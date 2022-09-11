import gspread as gs
from oauth2client.service_account import ServiceAccountCredentials as SAC
import oandapyV20
from oandapyV20 import API
import oandapyV20.endpoints.pricing as pricing
import pandas as pd

scope = ["https://spreadsheets.google.com/feeds",
        'https://www.googleapis.com/auth/spreadsheets',
        "https://www.googleapis.com/auth/drive.file",
        "https://www.googleapis.com/auth/drive"]

credentials = SAC.from_json_keyfile_name('C:\ZorroBeta\Strategy\Python\GoogleSheet\GoogleSheet-b90941c49358.json',scope)
ga = gs.authorize(credentials)
g = ga.open('OandaEurope').sheet1
#g.update_acell('L3','Alex')


accountID = '101-004-9922005-003'
access_token = 'ea74153c2aba5b6e58714d57b3601602-7669b039c81edcc9b1ec2e4c8fadf2fa'
api = API(access_token=access_token)

params = {
    "instruments": "AU200_AUD,CN50_USD,EU50_EUR,FR40_EUR,DE30_EUR,HK33_HKD,IN50_USD,JP225_USD,NL25_EUR,SG30_SGD,TWIX_USD,UK100_GBP,NAS100_USD,US2000_USD,SPX500_USD,US30_USD,DE10YB_EUR,UK10YB_GBP,USB10Y_USD,USB02Y_USD,USB05Y_USD,USB30Y_USD,BCO_USD,WTICO_USD,NATGAS_USD,CORN_USD,SOYBN_USD,SUGAR_USD,WHEAT_USD,XCU_USD,XPT_USD,XPD_USD,XAU_USD,XAG_USD,XAU_AUD,XAU_CAD,XAU_CHF,XAU_EUR,XAU_GBP,XAU_HKD,XAU_JPY,XAU_NZD,XAU_SGD,XAU_XAG,XAG_AUD,XAG_CAD,XAG_CHF,XAG_EUR,XAG_GBP,XAG_HKD,XAG_JPY,XAG_NZD,XAG_SGD,AUD_USD,EUR_USD,GBP_USD,NZD_USD,USD_CAD,USD_CHF,USD_HKD,USD_JPY,USD_SGD,AUD_CAD,AUD_CHF,AUD_HKD,AUD_JPY,AUD_NZD,AUD_SGD,CAD_CHF,CAD_HKD,CAD_JPY,CAD_SGD,CHF_HKD,CHF_JPY,EUR_AUD,EUR_CAD,EUR_CHF,EUR_GBP,EUR_HKD,EUR_JPY,EUR_NZD,EUR_SGD,GBP_AUD,GBP_CAD,GBP_CHF,GBP_HKD,GBP_JPY,GBP_NZD,GBP_SGD,HKD_JPY,NZD_CAD,NZD_CHF,NZD_HKD,NZD_JPY,NZD_SGD,SGD_CHF,SGD_HKD,SGD_JPY,EUR_DKK,EUR_NOK,EUR_SEK,USD_DKK,USD_NOK,USD_SEK,CHF_ZAR,EUR_CZK,EUR_HUF,EUR_PLN,EUR_TRY,EUR_ZAR,GBP_PLN,GBP_ZAR,TRY_JPY,USD_CNH,USD_CZK,USD_HUF,USD_INR,USD_MXN,USD_PLN,USD_SAR,USD_THB,USD_TRY,USD_ZAR,ZAR_JPY"
}

r = pricing.PricingInfo(accountID=accountID, params=params)
rv = api.request(r)
p = pd.DataFrame(r.response['prices'])
inst = p.drop(p.columns[[0,1,2,3,6,7,8,9]], axis=1)

# wrtie Prices
for i in range(124):
    cell = "M"+str(i+2)
    price = (float(inst['closeoutBid'][i])+float(inst['closeoutAsk'][i]))/2
    g.update_acell(cell,price)
    cell = "N"+str(i+2)
    spread = float(inst['closeoutAsk'][i])/float(inst['closeoutBid'][i])-1
    g.update_acell(cell,spread)    

# read csv
AvgData = pd.read_csv("C:\\ZorroBeta\\Strategy\\TradingTeam\\OandaSpreads.csv",names=["Symbol","AvgSpread","AvgTicks","Timestamp"])

for i in range(124):
    cell = "AB"+str(i+2)
    AvgSpread = float(AvgData['AvgSpread'][i])
    g.update_acell(cell,AvgSpread)
    cell = "AC"+str(i+2)
    AvgTicks = float(AvgData['AvgTicks'][i])
    g.update_acell(cell,AvgTicks)
 
paramsfx = {
    "instruments": "AUD_USD,USD_CAD,USD_CHF,USD_CNH,USD_CZK,USD_DKK,EUR_USD,GBP_USD,USD_HKD,USD_HUF,USD_INR,USD_JPY,USD_MXN,USD_NOK,NZD_USD,USD_PLN,USD_SAR,USD_SEK,USD_SGD,USD_THB,USD_TRY,XAG_USD,USD_ZAR"
}
fx = api.request(pricing.PricingInfo(accountID=accountID, params=paramsfx))
fx = pd.DataFrame(fx['prices'])
fx = fx.drop(fx.columns[[0,1,2,3,6,7,8,9]],axis=1)

for i in range(23):
    term = fx['instrument'][i][-3:]
    price = (float(fx['closeoutBid'][i])+float(fx['closeoutAsk'][i]))/2
    if term != 'USD':
        price = 1/price
    if i >= 21:
        y = i+3
    else: 
        y = i+2
    cell = "AF"+str(y)
    g.update_acell(cell,price)
