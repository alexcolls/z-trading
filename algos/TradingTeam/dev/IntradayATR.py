import OandaLib as lib

g = lib.GSapi('OandaEurope','Intraday Volatility')

params = {
    'count': '288',
    'granularity': 'H1'
}

for i in range(lib.nSyms):
    df = lib.Oanda_Candles(lib.SymList[i],params)
    Len = len(df); TR = []
    for j in range(Len):
        hh = df.iloc[j]['High']-df.iloc[j]['Low']
        if j == 0:
            TR.append(hh/df.iloc[j]['Close'])
        else:
            hc = abs(df.iloc[j]['High']-df.iloc[j-1]['Close'])
            lc = abs(df.iloc[j]['Low']-df.iloc[j-1]['Close'])
            TR.append(max(hh,hc,lc)/df.iloc[j]['Close'])
    df['TR'] = TR
    df['Hour'] = df.index.hour
    df = df.set_index('Hour')
    h = 0
    for col in lib.IntradayCols:
        cell = col + str(i+4)
        if sum(df.index == h) < 10:
            g.update_acell(cell,'N/A')
        else:
            g.update_acell(cell,lib.stat.mean(df['TR'][h]))
        h += 1
