import OandaLib as lib

g1 = lib.GSapi('OandaEurope','Main')
g2 = lib.GSapi('OandaEurope','Intraday Spreads')

params = { 'instruments': lib.SymStr }
Prices = lib.Oanda_Prices(lib.Oanda_Credentials['ID'],params)

for i in range(lib.nSyms):
    params = {
        "instrument": lib.SymList[i],
        "period": 10000000000
    }
    df = lib.Oanda_Spreads(params=params)
    hour = df.index.hour
    df = lib.pd.concat([df,lib.pd.DataFrame(hour, index=df.index)],axis = 1)
    df = df.rename(columns={'DateTime':'Hour'})
    df = df.set_index('Hour')  
    pip = float(g1.cell(i+4,8).value)*10
    h = 0
    for col in lib.IntradayCols:
        cell = col + str(i+4)
        if sum(df.index == h) < 10:
            g2.update_acell(cell,'N/A')
        else:
            spread = (lib.stat.mean(df['Spread'][h])*pip)/Prices['Mid'][lib.SymList[i]]
            g2.update_acell(cell,spread)
        h += 1
        if col == 'Y':
            g1.update_acell('N'+str(i+4),Prices['Mid'][lib.SymList[i]])
            g1.update_acell('O'+str(i+4),Prices['Spr'][lib.SymList[i]])
