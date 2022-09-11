import OandaLib as lib

g = lib.GSapi('OandaEurope','Intraday Autocorrelation')

params = {
    'count': '1440',
    'granularity': 'H1'
}

for i in range(lib.nSyms):
    df = lib.Oanda_Candles(lib.SymList[i],params)
    Len = len(df); Dir = []
    for j in range(Len):
        r = 0
        if j != 0:
            if ( df.iloc[j]['Return'] > 0 and df.iloc[j-1]['Return'] > 0 ) or ( df.iloc[j]['Return'] < 0 and df.iloc[j-1]['Return'] < 0 ):
                r = 1
            elif ( df.iloc[j]['Return'] > 0 and df.iloc[j-1]['Return'] < 0 ) or ( df.iloc[j]['Return'] < 0 and df.iloc[j-1]['Return'] > 0 ):
                r = -1
        Dir.append(r)
    df['Dir'] = Dir
    df['Hour'] = df.index.hour
    df = df.set_index('Hour')
    h = 0
    for col in lib.IntradayCols:
        cell = col + str(i+4)
        if sum(df.index == h) < 10:
            g.update_acell(cell,'N/A')
        else:
            g.update_acell(cell,lib.stat.mean(df['Dir'][h]))
        h += 1
