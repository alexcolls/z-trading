import oandapyV20
import oandapyV20.endpoints.accounts as account
import pandas as pd
import pygsheets

gs = pygsheets.authorize(service_file='C:\ZorroBeta\Strategy\TradingTeam\dev\GS_trader1.json')

def Oanda_Account(accountID):
    client = oandapyV20.API(access_token='ea74153c2aba5b6e58714d57b3601602-7669b039c81edcc9b1ec2e4c8fadf2fa')
    r = account.AccountDetails(accountID)
    df = lib.pd.DataFrame(r.response['positions'])
    Len = len(df); Size, Fin = [], []
    pos = lib.pd.DataFrame()
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
    #pos['Fin'] = Fin
    #pos = pos.set_index('Symbol')
    return pos

LastLen = 0

client = oandapyV20.API(access_token='ea74153c2aba5b6e58714d57b3601602-7669b039c81edcc9b1ec2e4c8fadf2fa')
r = account.AccountDetails('101-004-9922005-009')
df = pd.DataFrame(client.request(r))

df


while True:

    df = Oanda_Postions(lib.Oanda_Credentials['ID'])
    print(df,'\n')
    sh = gs.open('Trader1'); wks = sh[0]
    Len = len(df)
    if Len < LastLen:
        wks.clear(start='J'+str(4+Len),end='M'+str(4+LastLen))
    LastLen = Len
    wks.set_dataframe(df,(3,10))

    lib.time.sleep(1)

from sqlalchemy import create_engine

MySQL = create_engine('mysql+pymysql://aco:Forex2015!@35.242.173.232/OandaEurope_Correlations')
dbConnection = MySQL.connect()

query = "SELECT * FROM Returns"

df = pd.read_sql(query,dbConnection)
p = df.set_index('index')
df

