
#include <nexow.h>

void run(){
    
    set(PLOTNOW);
    assetList("OandaEuropeALL");
    LookBack = 5;
    StartDate = 20190901;
    BarPeriod = 1440;

    const int Len = LookBack;

    double AvgSpread = (SMA(series(marketVal()),Len)/priceClose(0))*100;
    double AvgTicks = SMA(series(marketVol()),Len)*60;

    double Spr = (marketVal(0)/priceClose(0))*100;
    double Tck = marketVol(0);

    plot("Spread",Spr,1,RED);
    plot("AvgSpread",AvgSpread,0,BLUE);
    plot("Freq",Tck,1,RED);
    plot("AvgTicks",AvgTicks,0,BLUE);


}