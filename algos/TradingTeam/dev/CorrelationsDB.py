from oandapyV20 import API
import oandapyV20.endpoints.instruments as instruments
import pandas as pd
from datetime import datetime as dt

OA = { 'Token': 'ea74153c2aba5b6e58714d57b3601602-7669b039c81edcc9b1ec2e4c8fadf2fa',
       'ID': '101-004-9922005-003' }

api = API(access_token=OA['Token'])

def Oanda_Returns(Symbol,params):
    r = instruments.InstrumentsCandles(instrument=Symbol,params=params)
    rv = api.request(r)
    df = pd.DataFrame(r.response['candles'])
    Len = len(df); t, r, v = [], [], []
    for i in range(Len):
        if df['complete'][i]:
            t.append(dt.strptime(df['time'][i][:19],'%Y-%m-%dT%H:%M:%S'))
            r.append((float(df['mid'][i]['c'])/float(df['mid'][i]['o'])-1)*100)
            v.append((float(df['mid'][i]['h'])/float(df['mid'][i]['l'])-1)*100)
    df = pd.DataFrame({'DateTime':t,'Return':r,'Volatility':v})
    df = df.set_index('DateTime')
    return df

syms = ['AU200_AUD','CN50_USD','EU50_EUR','FR40_EUR','DE30_EUR','HK33_HKD','IN50_USD','JP225_USD','NL25_EUR','SG30_SGD','TWIX_USD','UK100_GBP','NAS100_USD','US2000_USD','SPX500_USD','US30_USD','DE10YB_EUR','UK10YB_GBP','USB10Y_USD','USB02Y_USD','USB05Y_USD','USB30Y_USD','BCO_USD','WTICO_USD','NATGAS_USD','CORN_USD','SOYBN_USD','SUGAR_USD','WHEAT_USD','XCU_USD','XPT_USD','XPD_USD','XAU_USD','XAG_USD','XAU_AUD','XAU_CAD','XAU_CHF','XAU_EUR','XAU_GBP','XAU_HKD','XAU_JPY','XAU_NZD','XAU_SGD','XAU_XAG','XAG_AUD','XAG_CAD','XAG_CHF','XAG_EUR','XAG_GBP','XAG_HKD','XAG_JPY','XAG_NZD','XAG_SGD','AUD_USD','EUR_USD','GBP_USD','NZD_USD','USD_CAD','USD_CHF','USD_HKD','USD_JPY','USD_SGD','AUD_CAD','AUD_CHF','AUD_HKD','AUD_JPY','AUD_NZD','AUD_SGD','CAD_CHF','CAD_HKD','CAD_JPY','CAD_SGD','CHF_HKD','CHF_JPY','EUR_AUD','EUR_CAD','EUR_CHF','EUR_GBP','EUR_HKD','EUR_JPY','EUR_NZD','EUR_SGD','GBP_AUD','GBP_CAD','GBP_CHF','GBP_HKD','GBP_JPY','GBP_NZD','GBP_SGD','HKD_JPY','NZD_CAD','NZD_CHF','NZD_HKD','NZD_JPY','NZD_SGD','SGD_CHF','SGD_HKD','SGD_JPY','EUR_DKK','EUR_NOK','EUR_SEK','USD_DKK','USD_NOK','USD_SEK','CHF_ZAR','EUR_CZK','EUR_HUF','EUR_PLN','EUR_TRY','EUR_ZAR','GBP_PLN','GBP_ZAR','TRY_JPY','USD_CNH','USD_CZK','USD_HUF','USD_INR','USD_MXN','USD_PLN','USD_SAR','USD_THB','USD_TRY','USD_ZAR','ZAR_JPY']
params = {'granularity':'D','count':'260'}

rets = {}
for sym in syms:
    rets[sym] = Oanda_Returns(sym, params)

p_ret = pd.DataFrame(index=syms, columns=syms)
p_vol = pd.DataFrame(index=syms, columns=syms)

for sym1 in syms:
    for sym2 in syms:
        if sym1 == sym2:
            p_ret[sym1][sym2] = str()
            p_vol[sym1][sym2] = str()
        else:
            xy = pd.merge(rets[sym1],rets[sym2],how='inner',left_index=True,right_index=True)
            p_ret[sym1][sym2] = str(round(pd.np.corrcoef(xy['Return_x'], xy['Return_y'])[1][0],4))
            p_vol[sym1][sym2] = str(round(pd.np.corrcoef(xy['Volatility_x'], xy['Volatility_y'])[1][0],4))

p_ret = p_ret.reset_index()
p_vol = p_vol.reset_index()

from sqlalchemy import create_engine

MySQL = create_engine('mysql+pymysql://aco:Forex2015!@35.242.173.232/OandaEurope_Correlations', echo=True)
dbConnection = MySQL.connect()

Date = str(dt.now())[0:10]
Returns_backup = 'Returns_' + Date
Volatilities_backup = 'Volatilities_' + Date

p_ret.to_sql('Returns', dbConnection, if_exists='replace', index=False)
p_vol.to_sql('Volatilities', dbConnection, if_exists='replace', index=False)

p_ret.to_sql(Returns_backup, dbConnection, if_exists='replace', index=False)
p_vol.to_sql(Volatilities_backup, dbConnection, if_exists='replace', index=False)

dbConnection.close()
 
