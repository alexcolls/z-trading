
#include <nexow.h>

void run(){

    BarPeriod = 1;
    BarZone = UTC;
    LookBack = 28800;
    const int Len = LookBack;
    FILE *OandaSpreads = fopen("C:\\ZorroBeta\\Strategy\\TradingTeam\\OandaSpreads.csv", "w");
    assetList("OandaEuropeALL");
    while(asset(loop(Assets))){
        double AvgSpread = (SMA(series(marketVal()),Len)/priceClose(0));
        double AvgTicks = SMA(series(marketVol()),Len)*60;
        fputs(strf("%s,%f,%f,%d\n", Symbol, AvgSpread, AvgTicks, utm(wdate())), OandaSpreads);
    }
    fclose(OandaSpreads);
}