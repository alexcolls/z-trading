
import OandaLib as lib

g = lib.GSapi('OandaEurope','Intraweek Volume')

params = {
    'count': '780',
    'granularity': 'D'
}

for i in range(lib.nSyms):
    df = lib.Oanda_Candles(lib.SymList[i],params)
    df['Weekday'] = df.index.weekday
    df = df.set_index('Weekday')
    wd = [6,0,1,2,3,4]
    for j in range(6):
        cell = lib.IntradayCols[j] + str(i+4)
        if sum(df.index == wd[j]) < 10:
            g.update_acell(cell,'N/A')
        else:
            g.update_acell(cell,lib.stat.mean(df['Volume'][wd[j]]))
