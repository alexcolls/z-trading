
#include <nexow.h>

void run(){

    BarPeriod = 1440;
    StartDate = 2010;

    set(PLOTNOW);
    assetList("OandaEuropeFX45");

    const int Len = 30;

    while(asset(loop(Assets))){
        double Vol = 0; int i;
        double Rets[30], TRs[30];
        for( i = 0; i < Len; i++ ){
            Vol += ( priceHigh(i)/priceLow(i)-1 )*100;
            Rets[i] = ( priceClose(i)/priceOpen(i)-1 )*100;
            TRs[i] = ( priceHigh(i)/priceLow(i)-1 )*100;
            //printf( "\nRet%d = %f, TR%d = %f", i, Rets[i], i, TRs[i] );
        }
        double StDev = StdDev(Rets,Len);
        double ATRd = SMA(TRs,Len);
        plot("StDev",StDev,BARS+NEW,BLUE);
        plot("ATRd",ATRd,0,RED);
        plot("Vol",Vol,BARS+NEW,RED);
    }

}