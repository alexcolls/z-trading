

#include <NexowFunctions.h>

void run(){

    set(PLOTNOW);

    assetList("AssetsFix");
    setFees(0.0,0.0,0.0,5);

    StartDate = 2007;
    BarPeriod = 60;

    static int Long, Short;

    if( priceClose(0)>priceOpen(0) ){
        Long++;
        Short = 0;
        exitShort();
    }
    else if( priceClose(0)<priceOpen(0) ){
        Short--;
        Long = 0;
        exitLong();
    }

    double* L = series(Long);
    double* S = series(Short);

    double Delta = 3;
    double Alpha = 2;

    //exitShort();
    if( L[Alpha] >= Delta && Short == -Alpha ){
        enterShort();
        TakeProfit = ATR(20)*4;
        Stop = ATR(20)*4;
        Trail = ATR(20)*2;
    }
    if( S[Alpha] <= -Delta && Long == Alpha ){
        enterLong();
        TakeProfit = ATR(20)*4;
        Stop = ATR(20)*4;
        Trail = ATR(20)*2;
    }

    plot("Z",0,1,BLACK);
    plot("Long",Long,0,BLUE);
    plot("Short",Short,0,RED);

}