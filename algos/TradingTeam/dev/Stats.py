
import OandaLib as lib

g = lib.GSapi('OandaEurope','Stats')

params = [{'granularity':'M','count':'120'},
          {'granularity':'W','count':'156'},
          {'granularity':'D','count':'260'}]
periods = [[120,60,36,12],[156,52,26,13],[260,120,60,20]]

for k in range(lib.nSyms):
    col, cnt = 0, 0
    for i in range(3):
        His = lib.Oanda_Candles(lib.SymList[k],params[i])
        for j in range(4):
            Vol = lib.stat.mean(His['Volatility'].iloc[-periods[i][j]:])
            Ret = lib.stat.mean(His['Return'].iloc[-periods[i][j]:])
            Dev = lib.stat.stdev(His['Return'].iloc[-periods[i][j]:])
            cVol = lib.StatsCols[col]+str(k+4)
            cRet = lib.StatsCols[col+19]+str(k+4)
            cDev = lib.StatsCols[col+38]+str(k+4)
            g.update_acell(cVol,Vol)
            g.update_acell(cRet,Ret)
            g.update_acell(cDev,Dev)
            cnt += 1
            if cnt == 4:
                col +=2
                cnt = 0
            col += 1
        

            
            

