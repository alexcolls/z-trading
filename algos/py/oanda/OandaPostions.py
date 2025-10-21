
import OandaLib  as lib
import pygsheets

gs = pygsheets.authorize(service_file='C:\ZorroBeta\Strategy\TradingTeam\dev\GS_trader1.json')

def Oanda_Postions(accountID):
    r = lib.positions.OpenPositions(accountID=accountID)
    rv = lib.oanda.request(r)
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

while True:

    df = Oanda_Postions(lib.Oanda_Credentials['ID'])
    print(df,'\n')
    sh = gs.open('Trader'); wks = sh[0]
    Len = len(df)
    if Len < LastLen:
        wks.clear(start='I'+str(3+Len),end='L'+str(4+LastLen))
    LastLen = Len
    if Len > 0:
        wks.set_dataframe(df,(3,9))

    lib.time.sleep(1)