
### Dependencies Libraries ###

import oandapyV20
import oandapyV20.endpoints.accounts as account
import oandapyV20.endpoints.positions as positions
import oandapyV20.endpoints.pricing as pricing
import pandas as pd
import pygsheets
from sqlalchemy import create_engine
import time

### Program Inputs ###

Token = 'f4a7d6dfc8ceec10521b7a95cd1755b7-78bb661a63cd5ae812671dd8756afd60'
Trader = 'Trader6'

### Oanda API Connection ###

oanda_api = oandapyV20.API(access_token=Token)
syms = ['AU200_AUD','CN50_USD','EU50_EUR','FR40_EUR','DE30_EUR','HK33_HKD','IN50_USD','JP225_USD','NL25_EUR','SG30_SGD','TWIX_USD','UK100_GBP','NAS100_USD','US2000_USD','SPX500_USD','US30_USD','DE10YB_EUR','UK10YB_GBP','USB10Y_USD','USB02Y_USD','USB05Y_USD','USB30Y_USD','BCO_USD','WTICO_USD','NATGAS_USD','CORN_USD','SOYBN_USD','SUGAR_USD','WHEAT_USD','XCU_USD','XPT_USD','XPD_USD','XAU_USD','XAG_USD','XAU_AUD','XAU_CAD','XAU_CHF','XAU_EUR','XAU_GBP','XAU_HKD','XAU_JPY','XAU_NZD','XAU_SGD','XAU_XAG','XAG_AUD','XAG_CAD','XAG_CHF','XAG_EUR','XAG_GBP','XAG_HKD','XAG_JPY','XAG_NZD','XAG_SGD','AUD_USD','EUR_USD','GBP_USD','NZD_USD','USD_CAD','USD_CHF','USD_HKD','USD_JPY','USD_SGD','AUD_CAD','AUD_CHF','AUD_HKD','AUD_JPY','AUD_NZD','AUD_SGD','CAD_CHF','CAD_HKD','CAD_JPY','CAD_SGD','CHF_HKD','CHF_JPY','EUR_AUD','EUR_CAD','EUR_CHF','EUR_GBP','EUR_HKD','EUR_JPY','EUR_NZD','EUR_SGD','GBP_AUD','GBP_CAD','GBP_CHF','GBP_HKD','GBP_JPY','GBP_NZD','GBP_SGD','HKD_JPY','NZD_CAD','NZD_CHF','NZD_HKD','NZD_JPY','NZD_SGD','SGD_CHF','SGD_HKD','SGD_JPY','EUR_DKK','EUR_NOK','EUR_SEK','USD_DKK','USD_NOK','USD_SEK','CHF_ZAR','EUR_CZK','EUR_HUF','EUR_PLN','EUR_TRY','EUR_ZAR','GBP_PLN','GBP_ZAR','TRY_JPY','USD_CNH','USD_CZK','USD_HUF','USD_INR','USD_MXN','USD_PLN','USD_SAR','USD_THB','USD_TRY','USD_ZAR','ZAR_JPY']

### MySQL Databade Connection ###

def MySQLdb(Database):
    db = create_engine('mysql+pymysql://aco:Forex2015!@35.242.173.232/'+ Database)
    return db.connect()

### Google Sheets Connection ###

gs = pygsheets.authorize(service_file='C:\ZorroBeta\Strategy\TradingTeam\dev\GS_trader1.json')
sh = gs.open(Trader); gsAccDsh = sh[0]; gsMM = sh[1]

### Oanda API Functions ###

def TestOandaConnection(Print):
    try:
        test = oanda_api.request(account.AccountDetails(AccountID))
    except:
        message ='Wrong Account ID!'
        gsAccDsh.update_value('C3',message)
        print(message)
        return False
    else:
        if Print:
            message = 'Connected!'    
            gsAccDsh.update_value('C3', message)
            df = pd.DataFrame(oanda_api.request(account.AccountDetails(AccountID)))
            gsAccDsh.update_value('C5', df['account']['alias'])
            gsAccDsh.update_value('C6', df['account']['currency'])
            print(message)
        return True

def Oanda_AccountID():
    AccountID = gsAccDsh.cell('C2').value
    return AccountID

def Oanda_HardStop():
    HardStop = gsAccDsh.cell('F3').value
    HardStop = float(HardStop.split('%')[0])/100
    return HardStop

def Oanda_InitialBalance():
    InitialBalance = gsAccDsh.cell('H2').value
    InitialBalance = InitialBalance.replace(',', '')
    InitialBalance = float(InitialBalance.replace('€ ', ''))
    return InitialBalance

def Oanda_RiskCapital():
    RiskCapital = float(InitialBalance*HardStop)
    return RiskCapital

def Oanda_Account():
    request = account.AccountDetails(AccountID)
    r = pd.DataFrame(oanda_api.request(request))
    Currency = r['account']['currency']; Account = {}
    AccKeys = [ 'NAV', 'Balance', 'Realized PnL', 'Realized %', 'Unrealized PnL', 'Unrealized %', 'Available Margin',
                'Margin Used', 'Position Value', 'nPostions', 'Margin Call', 'Commissions', 'Financing' ]
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
    return Account, AccKeys, Currency

def Oanda_Prices():
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
    return Prices

def Oanda_Positions():
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
    return Positions
    
def Oanda_Trades():
    df1 = Positions.drop(columns=['Margin', 'PnL'])
    df2 = Last_Positions.drop(columns=['Margin', 'PnL'])
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
    return Trades

### MySQL Database Statistics ###

def DBvolatilities():
    dbConnection = MySQLdb('OandaEurope_Statistics')
    query = "SELECT * FROM AvgVolatilities"
    Volatilities = pd.read_sql(query, dbConnection)
    Volatilities = Volatilities.set_index('Symbol')
    Volatilities = Volatilities.astype(float)
    Volatilities = Volatilities.T
    Volatilities = Volatilities.mean()
    Volatilities = Volatilities.to_dict()
    return Volatilities

def DBcorrelations():
    dbConnection = MySQLdb('OandaEurope_Correlations')
    query = "SELECT * FROM D1"
    Corr_Matrix = pd.read_sql(query, dbConnection)
    Corr_Matrix = Corr_Matrix.set_index('Symbol')
    return Corr_Matrix

### Money Management by Volatilities and Correlations ###

def SizesBySymbol(): 
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
    return MaxSizesbyVols

def MoneyManagement():
    global MaxSizes
    if len(Trades) > 0:
        for idx in Trades.index:
            for sym in syms:
                p = 1.
                if idx != sym:
                    p = float(Corr_Matrix[idx][sym])
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
    Account, AccKeys, Currency = Oanda_Account()
    df = pd.DataFrame(index=AccKeys, columns=[Currency])
    for Key in AccKeys:
        df[Currency][Key] = Account[Key]
    df[Currency]['Margin Call'] = str(round(df[Currency]['Margin Call']*100,2)) + '%'
    df[Currency]['Realized %'] = str(round(df[Currency]['Realized %']*100,2)) + '%'
    df[Currency]['Unrealized %'] = str(round(df[Currency]['Unrealized %']*100,2)) + '%'
    gsAccDsh.set_dataframe(df, (6, 3))

def Update_Positions():
    df = Positions.reset_index()
    if FirstRun:
        gsMM.clear(start='N2', end='Q125')
    elif nPositions < Last_nPositions:
        gsMM.clear(start='N'+str(1+nPositions), end='Q'+str(2+Last_nPositions))
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
    global AccountID
    AccountID = AccountID
    TestOandaConnection(False)
    global HardStop
    HardStop = Oanda_HardStop()
    global RiskCapital
    RiskCapital = Oanda_RiskCapital()
    global Prices
    Prices = Oanda_Prices()
    global Positions
    Positions = Oanda_Positions()
    global nPositions
    nPositions = len(Positions)
    global Trades
    Trades = Oanda_Trades()
    MoneyManagement()

def LastVariables():
    global Last_Positions
    Last_Positions = Positions
    global Last_nPositions
    Last_nPositions = len(Last_Positions)
    global FirstRun
    FirstRun = False

### Logs ###

def Logs():
    if len(Trades) > 0:
        print('New Trades:', '\n', Trades, '\n')
        print('Last Positions:', '\n', Positions, '\n')
      
### ___Init___ ###

FirstRun = True
AccountID = gsAccDsh.cell('C2').value
TestOandaConnection(True)
HardStop = Oanda_HardStop()
InitialBalance = Oanda_InitialBalance()
RiskCapital = Oanda_RiskCapital()
Prices = Oanda_Prices()
Positions = Oanda_Positions()
nPositions = len(Positions)
Last_Positions = pd.DataFrame(columns=['Size', 'Margin', 'PnL'])
Last_nPositions = 0
Trades = Oanda_Trades()
Volatilities = DBvolatilities()
Corr_Matrix = DBcorrelations()
MaxSizesbyVols = SizesBySymbol()
MaxSizes = pd.DataFrame(index=syms,columns=['Long Max Quantity','Short Max Quantity'])
for sym in syms:
    MaxSizes['Long Max Quantity'][sym] = MaxSizesbyVols[sym]
    MaxSizes['Short Max Quantity'][sym] = MaxSizesbyVols[sym]

### ___Main___ ###

def main():
    GlobalVariables()
    Update_Dashboard()
    Logs()
    LastVariables()

if __name__ == "__main__":
    while TestOandaConnection(False):      
        main()
        # Execute every x seconds:
        time.sleep(1)
