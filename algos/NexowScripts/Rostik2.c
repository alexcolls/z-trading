
#include <nexow.h>

void run(){

    set(PLOTNOW);
    assetList("OandaEuropeALL.csv");
    RollLong = RollShort = Slippage = Commission = 0;
    Spread = 0.00005;
    StartDate = 2005;
    BarPeriod = 10;
    TimeFrame = 6;
    Hedge = 2;
    //MaxLong = MaxShort = 1;
    Capital = 100000;
    const int HourEntry = optimize(;
    const int HourExit = 15;
    static double hi, lo;
    const double risk = 2;

    asset("EUR_USD");    
    int TradingTime = 0;  

    if( hour() == HourEntry ){
        hi = priceHigh(0);
        lo = priceLow(0);
        double range = (hi-lo)/PIP;
        double lose = Balance*(risk/100);
        double ratio = lose/range;
        Lots = 10000*ratio;
        enterLong(Lots,hi,lo);
        enterShort(Lots,lo,hi);
        EntryTime = 10;
    }

    if( hour() == HourExit ){
        exitLong();
        exitShort();
    }

    algo("eur_usdX");

    // asset("USD_JPY");    
    // int TradingTime = 0;  

    // if( hour() == HourEntry ){
    //     hi = priceHigh(0);
    //     lo = priceLow(0);
    //     double range = (hi-lo)/PIP;
    //     double lose = Balance*(risk/100);
    //     double ratio = lose/range;
    //     Lots = 10000*ratio;
    //     enterLong(Lots,hi,lo);
    //     enterShort(Lots,lo,hi);
    //     EntryTime = 10;
    // }

    // if( hour() == HourExit ){
    //     exitLong();
    //     exitShort();
    // }



    //plot("High",hi,0,RED);
    //plot("Low",lo,0,BLUE);

    //plot("Tr",TradingTime,BARS+NEW,RED);

    SetAccountPlots("SPX500_USD",1);

    //plot("Lots",Lots,BARS+NEW,RED);

}