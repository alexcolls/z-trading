
### Dependencies Libraries ###

import oandapyV20
import oandapyV20.endpoints.accounts as account
import oandapyV20.endpoints.positions as positions
import oandapyV20.endpoints.pricing as pricing
import pandas as pd
import pygsheets
from sqlalchemy import create_engine
import time
import datetime as dt
import sys

### Program Inputs ###

configFile = sys.argv[1]
config = open(configFile,'r')
GSheet, Token, AccountID, *rest = config.read().splitlines()
config.close()
UpdateSeconds = 1

### Declare Global Variables ###

syms = ['AU200_AUD','CN50_USD','EU50_EUR','FR40_EUR','DE30_EUR','HK33_HKD','IN50_USD','JP225_USD','NL25_EUR','SG30_SGD','TWIX_USD','UK100_GBP','NAS100_USD','US2000_USD','SPX500_USD','US30_USD','DE10YB_EUR','UK10YB_GBP','USB10Y_USD','USB02Y_USD','USB05Y_USD','USB30Y_USD','BCO_USD','WTICO_USD','NATGAS_USD','CORN_USD','SOYBN_USD','SUGAR_USD','WHEAT_USD','XCU_USD','XPT_USD','XPD_USD','XAU_USD','XAG_USD','XAU_AUD','XAU_CAD','XAU_CHF','XAU_EUR','XAU_GBP','XAU_HKD','XAU_JPY','XAU_NZD','XAU_SGD','XAU_XAG','XAG_AUD','XAG_CAD','XAG_CHF','XAG_EUR','XAG_GBP','XAG_HKD','XAG_JPY','XAG_NZD','XAG_SGD','AUD_USD','EUR_USD','GBP_USD','NZD_USD','USD_CAD','USD_CHF','USD_HKD','USD_JPY','USD_SGD','AUD_CAD','AUD_CHF','AUD_HKD','AUD_JPY','AUD_NZD','AUD_SGD','CAD_CHF','CAD_HKD','CAD_JPY','CAD_SGD','CHF_HKD','CHF_JPY','EUR_AUD','EUR_CAD','EUR_CHF','EUR_GBP','EUR_HKD','EUR_JPY','EUR_NZD','EUR_SGD','GBP_AUD','GBP_CAD','GBP_CHF','GBP_HKD','GBP_JPY','GBP_NZD','GBP_SGD','HKD_JPY','NZD_CAD','NZD_CHF','NZD_HKD','NZD_JPY','NZD_SGD','SGD_CHF','SGD_HKD','SGD_JPY','EUR_DKK','EUR_NOK','EUR_SEK','USD_DKK','USD_NOK','USD_SEK','CHF_ZAR','EUR_CZK','EUR_HUF','EUR_PLN','EUR_TRY','EUR_ZAR','GBP_PLN','GBP_ZAR','TRY_JPY','USD_CNH','USD_CZK','USD_HUF','USD_INR','USD_MXN','USD_PLN','USD_SAR','USD_THB','USD_TRY','USD_ZAR','ZAR_JPY']
AccKeys = ['NAV', 'Balance', 'Realized PnL', 'Realized %', 'Unrealized PnL', 'Unrealized %', 'Available Margin', 'Margin Used', 'Position Value', 'nPostions', 'Margin Call', 'Commissions', 'Financing']

FirstRun = True
Account = {}
Currency = str()
HardStop = float()
InitBalance = float()
RiskCapital = float()
Prices = pd.DataFrame()
Positions = pd.DataFrame(columns=['Size', 'Margin', 'PnL'])
nPositions = 0
LastPositions = pd.DataFrame(columns=['Size','Margin','PnL'])
nLastPositions = 0
Trades = pd.DataFrame(columns=['Size'])
Volatilities = pd.DataFrame()
Correlations = pd.DataFrame()
MaxSizesbyVols = {}
MaxSizes = MaxSizes = pd.DataFrame(index=syms, columns=['Long Max Quantity','Short Max Quantity'])

### Google Sheets Connection ###

gs = pygsheets.authorize(service_file='GS_main.json')
sh = gs.open(GSheet); gsAccDsh = sh[0]; gsMM = sh[1]

### Oanda API Connection ###

oanda_api = oandapyV20.API(access_token=Token)
def TestOandaConnection():
    try:
        test = oanda_api.request(account.AccountDetails(AccountID))
    except:
        print('Wrong Account ID!')
    else:
        print('Connected!', '\n')
        r = pd.DataFrame(oanda_api.request(account.AccountDetails(AccountID)))
        gsAccDsh.update_value('C3', AccountID)
        gsAccDsh.update_value('C4', r['account']['alias'])
        global Currency
        Currency = r['account']['currency']
        gsAccDsh.update_value('C5', Currency)

### MySQL Databade Connection ###

def MySQLdb(Database):
    db = create_engine('mysql+pymysql://aco:Forex2015!@35.242.173.232/'+ Database)
    return db.connect()

### Oanda API Functions ###

def gvHardStop():
    global HardStop
    HardStop = gsAccDsh.cell('F3').value
    HardStop = float(HardStop.split('%')[0])/100

def gvInitBalance():
    global InitBalance
    InitBalance = gsAccDsh.cell('H2').value
    InitBalance = InitBalance.replace(',', '')
    InitBalance = float(InitBalance.replace('€ ', ''))

def gvRiskCapital():
    global RiskCapital
    RiskCapital = float(InitBalance*HardStop)

def gvAccount():
    request = account.AccountDetails(AccountID)
    r = pd.DataFrame(oanda_api.request(request))
    global Account
    Account['NAV'] = float(r['account']['NAV'])
    Account['Balance'] = float(r['account']['balance'])
    Account['Realized PnL'] = float(r['account']['pl'])
    Account['Realized %'] = Account['Realized PnL']/Account['Balance']
    Account['Unrealized PnL'] = float(r['account']['unrealizedPL'])
    Account['Unrealized %'] = Account['Unrealized PnL']/Account['Balance']
    Account['Available Margin'] = float(r['account']['marginAvailable'])
    Account['Margin Used'] = float(r['account']['marginUsed'])
    Account['Position Value'] = float(r['account']['positionValue'])
    Account['nPostions'] = float(r['account']['openPositionCount'])
    Account['Margin Call'] = float(r['account']['marginCallPercent'])
    Account['Commissions'] = float(r['account']['commission'])
    Account['Financing'] = float(r['account']['financing'])

def gvPrices():
    global Prices
    symStr = ''
    for sym in syms:
        symStr = symStr+','+sym
    params = {'instruments': symStr[1:]}
    request = pricing.PricingInfo(accountID=AccountID, params=params)
    api_request = oanda_api.request(request)
    r = pd.DataFrame(request.response['prices'])
    Prices = pd.DataFrame()
    Prices['Symbol'] = r['instrument']
    Prices['Bid'] = r['closeoutBid'].astype(float)
    Prices['Ask'] = r['closeoutAsk'].astype(float)
    Prices['Mid'] = round((Prices['Bid']+Prices['Ask'])/2, 5)
    Prices = Prices.set_index('Symbol')

def gvPositions():
    global Positions
    global nPositions
    request = positions.OpenPositions(AccountID)
    api_request = oanda_api.request(request)
    r = pd.DataFrame(request.response['positions'])
    nPositions = len(r); Size = []
    Positions = pd.DataFrame(columns=['Size', 'Margin', 'PnL'])
    if nPositions > 0:
        Positions['Symbol'] = r['instrument']
        for i in range(nPositions):
            Size.append(int(r['long'][i]['units'])+int(r['short'][i]['units']))
        Positions['Size'] = Size
        Positions['Margin'] = r['marginUsed'].astype(float)
        Positions['PnL'] = r['unrealizedPL'].astype(float)
        Positions = Positions.set_index('Symbol')
    nPositions = len(Positions)

def gvLastPositions():
    global LastPositions
    LastPositions = Positions
    global nLastPositions
    nLastPositions = nPositions
   
def gvTrades():
    global Trades
    df1 = Positions.drop(columns=['Margin', 'PnL'])
    df2 = LastPositions.drop(columns=['Margin', 'PnL'])
    Trades = df1 - df2
    indx = list(df1.index) + list(df2.index)
    indx = set(indx)
    for idx in indx:
        if pd.isna(Trades['Size'][idx]):
            try:
                Trades['Size'][idx] = df1['Size'][idx]
            except:
                Trades['Size'][idx] = -df2['Size'][idx]
    Trades = Trades[Trades.Size != 0]

### MySQL Database Statistics ###

def gvVolatilities():
    global Volatilities
    dbConnection = MySQLdb('OandaEurope_Statistics')
    query = "SELECT * FROM AvgVolatilities"
    Volatilities = pd.read_sql(query, dbConnection)
    Volatilities = Volatilities.set_index('Symbol')
    Volatilities = Volatilities.astype(float)
    Volatilities = Volatilities.T
    Volatilities = Volatilities.mean()
    Volatilities = Volatilities.to_dict()

def gvCorrelations():
    global Correlations
    dbConnection = MySQLdb('OandaEurope_Correlations')
    query = "SELECT * FROM D1"
    Correlations = pd.read_sql(query, dbConnection)
    Correlations = Correlations.set_index('Symbol')

### Money Management ###

def gvMaxSizesbyVols():
    global MaxSizesbyVols
    RRatios = {}
    for sym in syms:
        RRatios[sym] = round(HardStop/(Volatilities[sym]/100),4)
    SymsNomRisks = {}
    for sym in syms:
        SymsNomRisks[sym] = round(RiskCapital*RRatios[sym], 4)
    PriceRanges = {} 
    for sym in syms:
        PriceRanges[sym] = round(Prices['Mid'][sym]*HardStop, 4)
    MaxSizesbyVols = {}
    for sym in syms:
        MaxSizesbyVols[sym] = int(SymsNomRisks[sym]/PriceRanges[sym])

def gvMaxSizes():
    global MaxSizes
    if FirstRun or nPositions == 0:
        for sym in syms:
            MaxSizes['Long Max Quantity'][sym] = MaxSizesbyVols[sym]
            MaxSizes['Short Max Quantity'][sym] = MaxSizesbyVols[sym]
    elif len(Trades) > 0:
        for idx in Trades.index:
            for sym in syms:
                p = 1.
                if idx != sym:
                    p = float(Correlations[idx][sym])
                SizeRatio = Prices['Mid'][idx]/Prices['Mid'][sym]
                TradeSize = Trades['Size'][idx]*SizeRatio
                MaxSizes['Long Max Quantity'][sym] = int(MaxSizes['Long Max Quantity'][sym] - TradeSize*p)
                MaxSizes['Short Max Quantity'][sym] = int(MaxSizes['Short Max Quantity'][sym] + TradeSize*p)
        for sym in syms:
            if sym not in Positions.index:
                if MaxSizes['Long Max Quantity'][sym] < 0:
                    MaxSizes['Long Max Quantity'][sym] = 0
                if MaxSizes['Short Max Quantity'][sym] < 0:
                    MaxSizes['Short Max Quantity'][sym] = 0
            else:
                if Positions['Size'][sym] > 0 and MaxSizes['Short Max Quantity'][sym] < 0:
                    MaxSizes['Short Max Quantity'][sym] = 0
                elif Positions['Size'][sym] < 0 and MaxSizes['Long Max Quantity'][sym] < 0:
                    MaxSizes['Long Max Quantity'][sym] = 0
            
### Dashboard Updates Functions ###

def Update_AccountDetails():
    df = pd.DataFrame(index=AccKeys, columns=[Currency])
    for Key in AccKeys:
        df[Currency][Key] = Account[Key]
    df[Currency]['Margin Call'] = str(round(df[Currency]['Margin Call']*100,2)) + '%'
    df[Currency]['Realized %'] = str(round(df[Currency]['Realized %']*100,2)) + '%'
    df[Currency]['Unrealized %'] = str(round(df[Currency]['Unrealized %']*100,2)) + '%'
    gsAccDsh.set_dataframe(df, (5, 3))

def Update_Positions():
    df = Positions.reset_index()
    if FirstRun:
        gsMM.clear(start='N2', end='Q125')
    elif nPositions < nLastPositions:
        gsMM.clear(start='N'+str(1+nPositions), end='Q'+str(2+nLastPositions))
    if nPositions > 0:
        gsMM.set_dataframe(df, (1, 14))

def Update_MaxSizes():
    if FirstRun or len(Trades) > 0:
        maxSizes = MaxSizes.reset_index()
        maxSizes = maxSizes.rename(columns={'index': 'Symbol'})
        gsMM.set_dataframe(maxSizes, (1,1))

def Update_Dashboard():
    Update_AccountDetails()
    Update_Positions()
    Update_MaxSizes()

### Global Variables ###

def GlobalVariables():
    gvHardStop()
    gvInitBalance()
    gvRiskCapital()
    gvAccount()
    gvPrices()
    gvPositions()
    gvTrades()
    gvMaxSizes()

### Run script ###

def RunScript():
    now = dt.datetime.now()
    wkdy = now.weekday()
    hour = now.hour
    if wkdy == 5 and hour >= 10:
        return False
    else:
        return True

### Logs ###

def Logs():
    if len(Trades) > 0:
        print('---')
        print(time.strftime("%Y-%m-%d %H:%M:%S", time.gmtime()), '\n')
        print('New Trades:', '\n', Trades, '\n')
        print('Positions:', '\n', Positions, '\n')
      
### ___Init___ ###

TestOandaConnection()
gvHardStop()
gvInitBalance()
gvRiskCapital()
gvAccount()
gvPrices()
gvPositions()
gvTrades()
Update_AccountDetails()
Update_Positions()
gvVolatilities()
gvCorrelations()
gvMaxSizesbyVols()
gvMaxSizes()
Update_MaxSizes()
FirstRun = False

### ___Main___ ###

def main():
    GlobalVariables()
    Update_Dashboard()
    Logs()
    gvLastPositions()

if __name__ == "__main__":
    while RunScript():      
        main()
        time.sleep(UpdateSeconds)
