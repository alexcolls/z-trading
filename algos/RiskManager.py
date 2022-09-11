import oandapyV20
import oandapyV20.endpoints.accounts as account
import oandapyV20.endpoints.positions as positions
import oandapyV20.endpoints.pricing as pricing
import pandas as pd
import pygsheets
from sqlalchemy import create_engine


Token = 'ea74153c2aba5b6e58714d57b3601602-7669b039c81edcc9b1ec2e4c8fadf2fa'
gs = pygsheets.authorize(service_file='C:\ZorroBeta\Strategy\TradingTeam\dev\GS_trader1.json')
sh = gs.open('Trader'); gsAccDsh = sh[0]; gsMM = sh[1]
AccountID = gsAccDsh.cell('C2').value
AccRisk = gsAccDsh.cell('E2').value
AccRisk = float(AccRisk.split('%')[0])
InitBalance = 1000000
NomRisk = InitBalance*AccRisk/100

oanda_api = oandapyV20.API(access_token=Token)
syms = ['AU200_AUD','CN50_USD','EU50_EUR','FR40_EUR','DE30_EUR','HK33_HKD','IN50_USD','JP225_USD','NL25_EUR','SG30_SGD','TWIX_USD','UK100_GBP','NAS100_USD','US2000_USD','SPX500_USD','US30_USD','DE10YB_EUR','UK10YB_GBP','USB10Y_USD','USB02Y_USD','USB05Y_USD','USB30Y_USD','BCO_USD','WTICO_USD','NATGAS_USD','CORN_USD','SOYBN_USD','SUGAR_USD','WHEAT_USD','XCU_USD','XPT_USD','XPD_USD','XAU_USD','XAG_USD','XAU_AUD','XAU_CAD','XAU_CHF','XAU_EUR','XAU_GBP','XAU_HKD','XAU_JPY','XAU_NZD','XAU_SGD','XAU_XAG','XAG_AUD','XAG_CAD','XAG_CHF','XAG_EUR','XAG_GBP','XAG_HKD','XAG_JPY','XAG_NZD','XAG_SGD','AUD_USD','EUR_USD','GBP_USD','NZD_USD','USD_CAD','USD_CHF','USD_HKD','USD_JPY','USD_SGD','AUD_CAD','AUD_CHF','AUD_HKD','AUD_JPY','AUD_NZD','AUD_SGD','CAD_CHF','CAD_HKD','CAD_JPY','CAD_SGD','CHF_HKD','CHF_JPY','EUR_AUD','EUR_CAD','EUR_CHF','EUR_GBP','EUR_HKD','EUR_JPY','EUR_NZD','EUR_SGD','GBP_AUD','GBP_CAD','GBP_CHF','GBP_HKD','GBP_JPY','GBP_NZD','GBP_SGD','HKD_JPY','NZD_CAD','NZD_CHF','NZD_HKD','NZD_JPY','NZD_SGD','SGD_CHF','SGD_HKD','SGD_JPY','EUR_DKK','EUR_NOK','EUR_SEK','USD_DKK','USD_NOK','USD_SEK','CHF_ZAR','EUR_CZK','EUR_HUF','EUR_PLN','EUR_TRY','EUR_ZAR','GBP_PLN','GBP_ZAR','TRY_JPY','USD_CNH','USD_CZK','USD_HUF','USD_INR','USD_MXN','USD_PLN','USD_SAR','USD_THB','USD_TRY','USD_ZAR','ZAR_JPY']

def Oanda_Prices(AccountID):
    SymStr = ''
    for sym in syms:
        SymStr = SymStr+','+sym
    params = {'instruments': SymStr[1:]}
    request = pricing.PricingInfo(accountID=AccountID, params=params)
    api_request = oanda_api.request(request)
    df = pd.DataFrame(request.response['prices'])
    df = df.drop(df.columns[[0,1,2,3,6,7,8,9]], axis=1)
    df = df.rename(columns={'instrument':'Symbol','closeoutBid':'Bid','closeoutAsk':'Ask'})
    df = df.set_index('Symbol')
    df['Bid'] = df['Bid'].astype(float)
    df['Ask'] = df['Ask'].astype(float)
    df['Price'] = round((df['Bid']+df['Ask'])/2,5)
    df = df.drop(df.columns[[0, 1]], axis=1)
    return df

def Oanda_Account(AccountID):
    request = account.AccountDetails(AccountID)
    df = pd.DataFrame(oanda_api.request(request))
    AccKeys = ['AccName', 'Currency', 'NAV', 'Balance', 'PnL_Realized', 'PnL_Unrealized',
               'MarginAvailable', 'MarginUsed', 'PostionValue', 'nPositions', 'MarginCall',
               'MarginRate', 'Commissions', 'Financing']
    Acc = { 'AccName': df['account']['alias'], 'Currency': df['account']['currency'],
            'NAV': df['account']['NAV'], 'Balance': df['account']['balance'],
            'PnL_Realized': df['account']['pl'], 'PnL_Unrealized': df['account']['unrealizedPL'],
            'MarginAvailable': df['account']['marginAvailable'], 'MarginUsed': df['account']['marginUsed'],
            'PostionValue': df['account']['positionValue'], 'nPositions': df['account']['openPositionCount'],
            'MarginCall': df['account']['marginCallPercent'], 'MarginRate': df['account']['marginRate'],
            'Commissions': df['account']['commission'], 'Financing': df['account']['financing'] }
    return Acc, AccKeys

def Update_AccountDetails():
    Acc, AccKeys = Oanda_Account(AccountID)
    df = pd.DataFrame(index=AccKeys, columns=['Result'])
    for Key in AccKeys:
        df['Result'][Key] = Acc[Key]
    gsAccDsh.set_dataframe(df, (6, 3))

def Oanda_Positions(AccountID):
    request = positions.OpenPositions(accountID=AccountID)
    api_request = oanda_api.request(request)
    df = pd.DataFrame(request.response['positions'])
    Len = len(df); Size, Fin = [], []
    pos = pd.DataFrame()
    pos['Symbol'] = df['instrument']
    for i in range(Len):
        Size.append(int(df['long'][i]['units'])+int(df['short'][i]['units']))
        if Size[i] > 0:
            Fin.append(float(df['long'][i]['financing']))
        elif Size[i] < 0:
            Fin.append(float(df['short'][i]['financing']))
    pos['Size'] = Size
    pos['Margin'] = df['marginUsed']
    pos['PnL'] = df['unrealizedPL']
    pos = pos.set_index('Symbol')
    return pos

Positions = Oanda_Positions(AccountID)


def InstrumentMaxSizes():

    Database = 'OandaEurope_Correlations'
    MySQL = create_engine('mysql+pymysql://aco:Forex2015!@35.242.173.232/' + Database)
    dbConnection = MySQL.connect()
    query = "SELECT * FROM D1"
    Corr_Matrix = pd.read_sql(query,dbConnection)
    Corr_Matrix = Corr_Matrix.set_index('Symbol')

    Database = 'OandaEurope_Statistics'
    MySQL = create_engine('mysql+pymysql://aco:Forex2015!@35.242.173.232/' + Database)
    dbConnection = MySQL.connect()
    query = "SELECT * FROM AvgVolatilities"
    volsql = pd.read_sql(query, dbConnection)
    volsql = volsql.set_index('Symbol')
    volsql = volsql.astype(float)
    volsql = volsql.T
    volsql = volsql.mean()
    Vols = volsql.to_dict()

    Prices = Oanda_Prices(AccountID)

    RRatios = {}
    for sym in syms:
        RRatios[sym] = round(AccRisk/Vols[sym],4)
    SymsNomRisks = {}
    for sym in syms:
        SymsNomRisks[sym] = round(NomRisk*RRatios[sym], 4)
    PriceRanges = {} 
    for sym in syms:
        PriceRanges[sym] = round(Prices['Price'][sym]*AccRisk/100, 4)
    MaxSizesbyVols = {}
    for sym in syms:
        MaxSizesbyVols[sym] = int(SymsNomRisks[sym]/PriceRanges[sym])
    Allocs = {}
    for sym in syms:
        try:
            Allocs[sym] = round(Positions['Size'][sym]/MaxSizesbyVols[sym], 4)
        except:
            Allocs[sym] = 0
    assets = list(Positions.index)
    LongMatrix = pd.DataFrame(index=assets, columns=syms)
    ShortMatrix = pd.DataFrame(index=assets, columns=syms)
    for sym in syms:
        for ass in assets:
            p = 1
            if sym != ass:
                p = float(Corr_Matrix[sym][ass])
            LongMatrix[sym][ass] = 1-Allocs[ass]-Allocs[sym]*p
            ShortMatrix[sym][ass] = 1-Allocs[ass]+Allocs[sym]*p
    LongRatios = LongMatrix.mean(); LongRatios = LongRatios.to_dict()
    ShortRatios = ShortMatrix.mean(); ShortRatios = ShortRatios.to_dict()
    MaxSizes = pd.DataFrame(index=syms, columns=['Long MaxSize','Short MaxSize','Expostion Level'])
    for sym in syms:
        MaxSizes['Long MaxSize'][sym] = int(MaxSizesbyVols[sym]*LongRatios[sym])
        MaxSizes['Short MaxSize'][sym] = int(MaxSizesbyVols[sym]*ShortRatios[sym])
        if Allocs[sym] == 0:
            MaxSizes['Expostion Level'][sym] = str()
        else:
            MaxSizes['Expostion Level'][sym] = str(round(Allocs[sym]*100,2))+'%'
        try:
            size = int(Positions['Size'][sym])
            if size > 0:
                MaxSizes['Short MaxSize'][sym] = MaxSizes['Short MaxSize'][sym] + size
            elif size < 0:
                MaxSizes['Long MaxSize'][sym] = MaxSizes['Long MaxSize'][sym] + abs(size)
        except:
            pass
    MaxSizes = MaxSizes.reset_index()
    MaxSizes = MaxSizes.rename(columns={'index': 'Symbols'})

    gsMM.set_dataframe(MaxSizes, (1,1))


InstrumentMaxSizes()
