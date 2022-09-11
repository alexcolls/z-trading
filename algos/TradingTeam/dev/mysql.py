
import pandas as pd
from oandapyV20 import API
import oandapyV20.endpoints.instruments as instruments
from datetime import datetime as dt

Account_ID = '101-004-9922005-003'
Token = 'ea74153c2aba5b6e58714d57b3601602-7669b039c81edcc9b1ec2e4c8fadf2fa'
Symbols = [ 'AU200_AUD','CN50_USD','EU50_EUR','FR40_EUR','DE30_EUR','HK33_HKD',
            'IN50_USD','JP225_USD','NL25_EUR','SG30_SGD','TWIX_USD','UK100_GBP',
            'NAS100_USD','US2000_USD','SPX500_USD','US30_USD','DE10YB_EUR',
            'UK10YB_GBP','USB10Y_USD','USB02Y_USD','USB05Y_USD','USB30Y_USD',
            'BCO_USD','WTICO_USD','NATGAS_USD','CORN_USD','SOYBN_USD','SUGAR_USD',
            'WHEAT_USD','XCU_USD','XPT_USD','XPD_USD','XAU_USD','XAG_USD','XAU_AUD',
            'XAU_CAD','XAU_CHF','XAU_EUR','XAU_GBP','XAU_HKD','XAU_JPY','XAU_NZD',
            'XAU_SGD','XAU_XAG','XAG_AUD','XAG_CAD','XAG_CHF','XAG_EUR','XAG_GBP',
            'XAG_HKD','XAG_JPY','XAG_NZD','XAG_SGD','AUD_USD','EUR_USD','GBP_USD',
            'NZD_USD','USD_CAD','USD_CHF','USD_HKD','USD_JPY','USD_SGD','AUD_CAD',
            'AUD_CHF','AUD_HKD','AUD_JPY','AUD_NZD','AUD_SGD','CAD_CHF','CAD_HKD',
            'CAD_JPY','CAD_SGD','CHF_HKD','CHF_JPY','EUR_AUD','EUR_CAD','EUR_CHF',
            'EUR_GBP','EUR_HKD','EUR_JPY','EUR_NZD','EUR_SGD','GBP_AUD','GBP_CAD',
            'GBP_CHF','GBP_HKD','GBP_JPY','GBP_NZD','GBP_SGD','HKD_JPY','NZD_CAD',
            'NZD_CHF','NZD_HKD','NZD_JPY','NZD_SGD','SGD_CHF','SGD_HKD','SGD_JPY',
            'EUR_DKK','EUR_NOK','EUR_SEK','USD_DKK','USD_NOK','USD_SEK','CHF_ZAR',
            'EUR_CZK','EUR_HUF','EUR_PLN','EUR_TRY','EUR_ZAR','GBP_PLN','GBP_ZAR',
            'TRY_JPY','USD_CNH','USD_CZK','USD_HUF','USD_INR','USD_MXN','USD_PLN',
            'USD_SAR','USD_THB','USD_TRY','USD_ZAR','ZAR_JPY']

def Oanda_Candles(Symbol, params):
    r = instruments.InstrumentsCandles(instrument=Symbol, params=params)
    rv = api.request(r)
    df = pd.DataFrame(r.response['candles'])
    Len = len(df)
    t, o, h, l, c, r, v, b = [], [], [], [], [], [], [], []
    for i in range(Len):
        if df['complete'][i]:
            t.append(dt.strptime(df['time'][i][:19], '%Y-%m-%dT%H:%M:%S'))
            o.append(float(df['mid'][i]['o']))
            h.append(float(df['mid'][i]['h']))
            l.append(float(df['mid'][i]['l']))
            c.append(float(df['mid'][i]['c']))
            r.append(round((float(df['mid'][i]['c'])/float(df['mid'][i]['o'])-1)*100,4))
            v.append(round((float(df['mid'][i]['h'])/float(df['mid'][i]['l'])-1)*100,4))
            b.append(float(df['volume'][i]))
    df = pd.DataFrame({ 'DateTime': t, 'Open': o, 'High': h, 'Low': l, 'Close': c, 
                        'Return': r, 'Volatility': v, 'Volume': b, 'Spread': 0.0, 
                        'RollLong': 0.0, 'RollShort': 0.0 })
    df = df.set_index('DateTime')
    return df

api = API(access_token=Token)

params = { 'granularity': 'D','count': '260' }
df = Oanda_Candles('AU200_AUD',params)
df

import mysql.connector

con = mysql.connector.connect(
    host="35.242.173.232",
    user="aco",
    passwd="Forex2015!",
    database="OandaEurope_EOD"
)

print(db)

query = con.cursor()

#query.execute("CREATE DATABASE OandaEurope_EOD")
#query.execute("DROP DATABASE x_db")
"""query.execute("SHOW DATABASES")
for x in query:
    print(x)"""

Schemas = {
    'Candle' : 'DateTime DATETIME, Open FLOAT, High FLOAT, Low FLOAT, Close FLOAT, Return FLOAT, Volatility FLOAT, Volume int, Spread FLOAT, RollLong FLOAT, RollShort FLOAT'
}
Schemas['Candle']
query.execute("CREATE TABLE AU200_AUD (DateTime DATETIME, Open FLOAT, High FLOAT, Low FLOAT, a FLOAT, b FLOAT, Volatility FLOAT, Volume INT, Spread FLOAT, RollLong FLOAT, RollShort FLOAT)")


#query.execute("ALTER TABLE AU200_AUD CHANGE Deviation Change FLOAT")
#query.execute("CREATE TABLE AU200_AUD( Schemas['Candle'] )")

sql = "INSERT INTO AU200_AUD (Open, High, Low, Close, Deviation, Volatility, Volume, Spread, RollLong, RollShort) VALUES (%f, %f, %f, %f, %f, %f, %d, %f, %f, %f)"

DateTime = list(df.index); Open = list(df['Open']); High = list(df['High']); Low = list(df['Low']); 
Close = list(df['Close']); Deviation = list(df['Deviation']); Volatility = list(df['Volatility']); 
Volume = list(df['Volume']); Spread = list(df['Spread']); RollLong = list(df['RollLong']); RollShort = list(df['RollShort'])

Vals = []

Len = len(DateTime)
for i in range(1):
    row = ( Open[i], High[i], Low[i], Close[i], Deviation[i], Volatility[i], Volume[i], Spread[i], RollLong[i], RollShort[i] )
    Vals.append(row)


Vals
sql
query.executemany(sql,Vals)




engine = create_engine('mysql://', echo=False)
df

import pymysql

db = 'OandaEurope_EOD'

conn = pymysql.connect(host = '35.242.173.232',
                       port = 3306,
                       user = 'aco',
                       passwd = 'Forex2015!',
                       db = db,
                       charset = 'utf8')



from sqlalchemy import create_engine
import pymysql

sqlEngine = create_engine(
    'mysql+pymysql://aco:Forex2015!@35.242.173.232/OandaEurope_EOD')

dbConnection = sqlEngine.connect()

try:Close
    df.to_sql('AU200_AUD', dbConnection, if_exists='replace')
except ValueError as vx:
    print(vx)
except Exception as ex:
    print(ex)
else:
    print("Table created successfully")
finally:
    dbConnection.close()



df
