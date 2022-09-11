import OandaLib as lib

g = lib.GSapi('OandaEurope','Intraday Volume')

params = {
    'count': '288',
    'granularity': 'H1'
}

for i in range(lib.nSyms):
    df = lib.Oanda_Candles(lib.SymList[i],params)
    df['Hour'] = df.index.hour
    df = df.set_index('Hour')
    h = 0
    for col in lib.IntradayCols:
        cell = col + str(i+4)
        if sum(df.index == h) < 10:
            g.update_acell(cell,'N/A')
        else:
            g.update_acell(cell,lib.stat.mean(df['Volume'][h]))
        h += 1