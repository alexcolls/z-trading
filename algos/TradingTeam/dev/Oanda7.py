from oauth2client.service_account import ServiceAccountCredentials as SAC
import gspread as gs
from oandapyV20 import API
import oandapyV20.endpoints.instruments as instruments
import pandas as pd
import statistics as stat
from datetime import datetime as dt
import time

OA = { 'Token': 'ea74153c2aba5b6e58714d57b3601602-7669b039c81edcc9b1ec2e4c8fadf2fa',
       'ID': '101-004-9922005-003' }

def GSapi(GSname,GSsheet):
    scope = ["https://spreadsheets.google.com/feeds",
            "https://www.googleapis.com/auth/spreadsheets",
            "https://www.googleapis.com/auth/drive.file",
            "https://www.googleapis.com/auth/drive"]
    credentials = SAC.from_json_keyfile_name('C:\ZorroBeta\Strategy\Python\GoogleSheet\GS_main.json',scope)
    ga = gs.authorize(credentials)
    return ga.open(GSname).worksheet(GSsheet)

def Oanda_Candles(Symbol,params):
    r = instruments.InstrumentsCandles(instrument=Symbol,params=params)
    rv = api.request(r)
    df = pd.DataFrame(r.response['candles'])
    Len = len(df); t, o, h, l, c, r, v, b = [], [], [], [], [], [], [], []
    for i in range(Len):
        if df['complete'][i]:
            t.append(dt.strptime(df['time'][i][:19],'%Y-%m-%dT%H:%M:%S'))
            o.append(float(df['mid'][i]['o']))
            h.append(float(df['mid'][i]['h']))
            l.append(float(df['mid'][i]['l']))
            c.append(float(df['mid'][i]['c']))
            r.append(float(df['mid'][i]['c'])/float(df['mid'][i]['o'])-1)
            v.append(float(df['mid'][i]['h'])/float(df['mid'][i]['l'])-1)
            b.append(int(df['volume'][i]))
    df = pd.DataFrame({'DateTime':t,'Open':o,'High':h,'Low':l,'Close':c,'Return':r,'Volatility':v,'Volume':b})
    df = df.set_index('DateTime')
    return df

api = API(access_token=OA['Token'])
g = GSapi('OandaEurope','Correlation2')

Symbols = ['AU200_AUD','CN50_USD','EU50_EUR','FR40_EUR','DE30_EUR','HK33_HKD','IN50_USD','JP225_USD','NL25_EUR','SG30_SGD','TWIX_USD','UK100_GBP','NAS100_USD','US2000_USD','SPX500_USD','US30_USD','DE10YB_EUR','UK10YB_GBP','USB10Y_USD','USB02Y_USD','USB05Y_USD','USB30Y_USD','BCO_USD','WTICO_USD','NATGAS_USD','CORN_USD','SOYBN_USD','SUGAR_USD','WHEAT_USD','XCU_USD','XPT_USD','XPD_USD','XAU_USD','XAG_USD','XAU_AUD','XAU_CAD','XAU_CHF','XAU_EUR','XAU_GBP','XAU_HKD','XAU_JPY','XAU_NZD','XAU_SGD','XAU_XAG','XAG_AUD','XAG_CAD','XAG_CHF','XAG_EUR','XAG_GBP','XAG_HKD','XAG_JPY','XAG_NZD','XAG_SGD','AUD_USD','EUR_USD','GBP_USD','NZD_USD','USD_CAD','USD_CHF','USD_HKD','USD_JPY','USD_SGD','AUD_CAD','AUD_CHF','AUD_HKD','AUD_JPY','AUD_NZD','AUD_SGD','CAD_CHF','CAD_HKD','CAD_JPY','CAD_SGD','CHF_HKD','CHF_JPY','EUR_AUD','EUR_CAD','EUR_CHF','EUR_GBP','EUR_HKD','EUR_JPY','EUR_NZD','EUR_SGD','GBP_AUD','GBP_CAD','GBP_CHF','GBP_HKD','GBP_JPY','GBP_NZD','GBP_SGD','HKD_JPY','NZD_CAD','NZD_CHF','NZD_HKD','NZD_JPY','NZD_SGD','SGD_CHF','SGD_HKD','SGD_JPY','EUR_DKK','EUR_NOK','EUR_SEK','USD_DKK','USD_NOK','USD_SEK','CHF_ZAR','EUR_CZK','EUR_HUF','EUR_PLN','EUR_TRY','EUR_ZAR','GBP_PLN','GBP_ZAR','TRY_JPY','USD_CNH','USD_CZK','USD_HUF','USD_INR','USD_MXN','USD_PLN','USD_SAR','USD_THB','USD_TRY','USD_ZAR','ZAR_JPY']
GScols = ['B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','AA','AB','AC','AD','AE','AF','AG','AH','AI','AJ','AK','AL','AM','AN','AO','AP','AQ','AR','AS','AT','AU','AV','AW','AX','AY','AZ','BA','BB','BC','BD','BE','BF','BG','BH','BI','BJ','BK','BL','BM','BN','BO','BP','BQ','BR','BS','BT','BU','BV','BW','BX','BY','BZ','CA','CB','CC','CD','CE','CF','CG','CH','CI','CJ','CK','CL','CM','CN','CO','CP','CQ','CR','CS','CT','CU','CV','CW','CX','CY','CZ','DA','DB','DC','DD','DE','DF','DG','DH','DI','DJ','DK','DL','DM','DN','DO','DP','DQ','DR','DS','DT','DU']

params = {
    'count': '260',
    'granularity': 'D'
}

def main():
    for i in range(124):
        for j in range(124):
            cell = GScols[j] + str(i+2)
            if Symbols[i] == Symbols[j]:
                continue
            else:
                df1 = Oanda_Candles(Symbols[i],params)
                df1 = df1.drop(df1.columns[[0,1,2,3,5,6]], axis=1)
                df1 = df1.rename(columns={'Volatility':1})
                df2 = Oanda_Candles(Symbols[j],params)
                df2 = df2.drop(df2.columns[[0,1,2,3,5,6]], axis=1)
                df2 = df2.rename(columns={'Volatility':2})
                df = pd.merge(df1,df2,how='inner',left_index=True,right_index=True)
                cor = pd.np.corrcoef(df[1],df[2])[1][0]
                g.update_acell(cell,cor)


if __name__ == "__main__":
    main()
