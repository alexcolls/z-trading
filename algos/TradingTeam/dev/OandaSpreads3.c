
#include <nexow.h>

void run(){
    
    set(PLOTNOW);
    assetList("OandaEuropeALL");
    LookBack = 86400;
    StartDate = 2019;
    BarPeriod = 1;

    const int Len = 86400;
    const int Len2 = 4000;

    //double AvgSpread = (SMA(series(marketVal()),Len)/priceClose(0))*100;
    //double AvgTicks = SMA(series(marketVol()),Len)*60;

    double Spr = (marketVal(0)/priceClose(0))*100;
    double Tck = marketVol(0);

    // plot("Spread",Spr,1,RED);
    // plot("AvgSpread",AvgSpread,0,BLUE);
    // plot("Freq",Tck,1,RED);
    // plot("AvgTicks",AvgTicks,0,BLUE);

    double hs[24];
    double ht[24];
    int h[24];
    int i, j;
    for( j = 0; j < 23; j++ ){
        hs[j] = 0;
        ht[j] = 0;
        h[j] = 0;
    }
    for( i = 0; i < Len2; i++ ){   
        for( j = 0; j < 23; j++ ){
            if( hour(i) == j ){
                hs[j] += (marketVal(i)/priceClose(i))*100;
                ht[j] += marketVol(i);
                h[j]++;   
            }
        }
    }
    for( j = 0; j < 23; j++ ){
        hs[j] = hs[j]/(double)h[j];
        plot("Hour",hs[j],1,RED);
    }
    


}