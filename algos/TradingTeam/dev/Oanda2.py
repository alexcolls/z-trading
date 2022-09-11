from oauth2client.service_account import ServiceAccountCredentials as SAC
import oandapyV20
from oandapyV20 import API
import oandapyV20.endpoints.pricing as pricing
import oandapyV20.endpoints.forexlabs as labs
import pandas as pd
import numpy as np
import statistics as stat
import gspread as gs

OA = { 'Token': 'ea74153c2aba5b6e58714d57b3601602-7669b039c81edcc9b1ec2e4c8fadf2fa',
       'ID': '101-004-9922005-003' }

def GSapi(GSname,GSsheet):
    scope = ["https://spreadsheets.google.com/feeds",
            'https://www.googleapis.com/auth/spreadsheets',
            "https://www.googleapis.com/auth/drive.file",
            "https://www.googleapis.com/auth/drive"]
    credentials = SAC.from_json_keyfile_name('C:\ZorroBeta\Strategy\Python\GoogleSheet\GoogleSheet-b90941c49358.json',scope)
    ga = gs.authorize(credentials)
    return ga.open(GSname).worksheet(GSsheet)

def Oanda_Prices(accountID,params):
    r = pricing.PricingInfo(accountID=accountID, params=params)
    rv = api.request(r)
    df = pd.DataFrame(r.response['prices'])
    df = df.drop(df.columns[[0,1,2,3,6,7,8,9]], axis=1)
    df = df.rename(columns={'instrument':'Symbol','closeoutBid':'Bid','closeoutAsk':'Ask'})
    df = df.set_index('Symbol')
    return df

def Oanda_Spreads(params):
    r = labs.Spreads(params=params)
    rv = api.request(r)
    df = pd.DataFrame(r.response['avg'])
    df.columns = ["DateTime","Spread"]
    df['DateTime'] = pd.to_datetime(df['DateTime'], unit='s')
    df = df.set_index('DateTime')
    return df

api = API(access_token=OA['Token'])

params = {
    "instruments": "AU200_AUD,CN50_USD,EU50_EUR,FR40_EUR,DE30_EUR,HK33_HKD,IN50_USD,JP225_USD,NL25_EUR,SG30_SGD,TWIX_USD,UK100_GBP,NAS100_USD,US2000_USD,SPX500_USD,US30_USD,DE10YB_EUR,UK10YB_GBP,USB10Y_USD,USB02Y_USD,USB05Y_USD,USB30Y_USD,BCO_USD,WTICO_USD,NATGAS_USD,CORN_USD,SOYBN_USD,SUGAR_USD,WHEAT_USD,XCU_USD,XPT_USD,XPD_USD,XAU_USD,XAG_USD,XAU_AUD,XAU_CAD,XAU_CHF,XAU_EUR,XAU_GBP,XAU_HKD,XAU_JPY,XAU_NZD,XAU_SGD,XAU_XAG,XAG_AUD,XAG_CAD,XAG_CHF,XAG_EUR,XAG_GBP,XAG_HKD,XAG_JPY,XAG_NZD,XAG_SGD,AUD_USD,EUR_USD,GBP_USD,NZD_USD,USD_CAD,USD_CHF,USD_HKD,USD_JPY,USD_SGD,AUD_CAD,AUD_CHF,AUD_HKD,AUD_JPY,AUD_NZD,AUD_SGD,CAD_CHF,CAD_HKD,CAD_JPY,CAD_SGD,CHF_HKD,CHF_JPY,EUR_AUD,EUR_CAD,EUR_CHF,EUR_GBP,EUR_HKD,EUR_JPY,EUR_NZD,EUR_SGD,GBP_AUD,GBP_CAD,GBP_CHF,GBP_HKD,GBP_JPY,GBP_NZD,GBP_SGD,HKD_JPY,NZD_CAD,NZD_CHF,NZD_HKD,NZD_JPY,NZD_SGD,SGD_CHF,SGD_HKD,SGD_JPY,EUR_DKK,EUR_NOK,EUR_SEK,USD_DKK,USD_NOK,USD_SEK,CHF_ZAR,EUR_CZK,EUR_HUF,EUR_PLN,EUR_TRY,EUR_ZAR,GBP_PLN,GBP_ZAR,TRY_JPY,USD_CNH,USD_CZK,USD_HUF,USD_INR,USD_MXN,USD_PLN,USD_SAR,USD_THB,USD_TRY,USD_ZAR,ZAR_JPY"
}
Prices = Oanda_Prices(OA['ID'],params)

Symbols = ['AU200_AUD','CN50_USD','EU50_EUR','FR40_EUR','DE30_EUR','HK33_HKD','IN50_USD','JP225_USD','NL25_EUR','SG30_SGD','TWIX_USD','UK100_GBP','NAS100_USD','US2000_USD','SPX500_USD','US30_USD','DE10YB_EUR','UK10YB_GBP','USB10Y_USD','USB02Y_USD','USB05Y_USD','USB30Y_USD','BCO_USD','WTICO_USD','NATGAS_USD','CORN_USD','SOYBN_USD','SUGAR_USD','WHEAT_USD','XCU_USD','XPT_USD','XPD_USD','XAU_USD','XAG_USD','XAU_AUD','XAU_CAD','XAU_CHF','XAU_EUR','XAU_GBP','XAU_HKD','XAU_JPY','XAU_NZD','XAU_SGD','XAU_XAG','XAG_AUD','XAG_CAD','XAG_CHF','XAG_EUR','XAG_GBP','XAG_HKD','XAG_JPY','XAG_NZD','XAG_SGD','AUD_USD','EUR_USD','GBP_USD','NZD_USD','USD_CAD','USD_CHF','USD_HKD','USD_JPY','USD_SGD','AUD_CAD','AUD_CHF','AUD_HKD','AUD_JPY','AUD_NZD','AUD_SGD','CAD_CHF','CAD_HKD','CAD_JPY','CAD_SGD','CHF_HKD','CHF_JPY','EUR_AUD','EUR_CAD','EUR_CHF','EUR_GBP','EUR_HKD','EUR_JPY','EUR_NZD','EUR_SGD','GBP_AUD','GBP_CAD','GBP_CHF','GBP_HKD','GBP_JPY','GBP_NZD','GBP_SGD','HKD_JPY','NZD_CAD','NZD_CHF','NZD_HKD','NZD_JPY','NZD_SGD','SGD_CHF','SGD_HKD','SGD_JPY','EUR_DKK','EUR_NOK','EUR_SEK','USD_DKK','USD_NOK','USD_SEK','CHF_ZAR','EUR_CZK','EUR_HUF','EUR_PLN','EUR_TRY','EUR_ZAR','GBP_PLN','GBP_ZAR','TRY_JPY','USD_CNH','USD_CZK','USD_HUF','USD_INR','USD_MXN','USD_PLN','USD_SAR','USD_THB','USD_TRY','USD_ZAR','ZAR_JPY']

g1 = GSapi('OandaEurope','Main')
g2 = GSapi('OandaEurope','Spreads')

for i in range(115,117):
    params = {
        "instrument": Symbols[i],
        "period": 10000000000
    }
    df = Oanda_Spreads(params=params)
    hour = df.index.hour
    df = pd.concat([df, pd.DataFrame(hour, index=df.index)], axis = 1)
    df = df.rename(columns={'DateTime':'Hour'})
    df = df.set_index('Hour')
    cols = ['B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z']
    pip = float(g1.cell(i+2,7).value)*10
    h = 0
    for let in cols:
        cell = let + str(i+2)
        if let != 'Z':
            if sum(df.index == h) < 10:
                g2.update_acell(cell,'N/A')
            else:
                spread = (stat.mean(df['Spread'][h])*pip)/float(Prices['Ask'][Symbols[i]])
                g2.update_acell(cell,spread)
            h += 1
        else:
            g2.update_acell(cell,float(Prices['Ask'][Symbols[i]]))


"""hrs = pd.unique(df.index)
for h in range(24):
    if not h in hrs:
        appnd = pd.DataFrame(data='N/A',columns=['Spread'],index=[h])
        df = df.append(appnd)"""
#isinstance(df['Spread'][h], str) or 
