
#include <nexow.h>

void AlgoLong(int Size){
    enterLong(Size,priceHigh(0),priceLow(0));
}

void AlgoShort(int Size){
    enterShort(Size,priceLow(0),priceHigh(0));
}

void run(){

    set(PLOTNOW);
    assetList("OandaEuropeALL.csv");
    Spread = RollLong = RollShort = Slippage = Commission = 0;
    StartDate = 2005;
    BarPeriod = 60;
    Hedge = 2;
    MaxLong = MaxShort = 1;

    asset("EUR_USD");
    
    const int HourEntry = 10;
    const int HourExit = 17;

    static double hi, lo;
    static int longs, shorts;

    int TradingTime = 0;

    if( hour() == HourEntry ){
        hi = priceHigh(0);
        lo = priceLow(0);
    }

    if( hour() >= HourEntry && hour() < HourExit ){
        TradingTime = 1;
        if( longs == 0 )
            enterLong(10000,hi,lo);
        if( longs == 1 && shorts == 0 ){
            exitShort();
            enterShort(10000,lo,hi);
        }
        if( shorts == 0 )
            enterShort(10000,lo,hi);
        if( shorts == 1 && longs == 0 ){
            exitLong();
            enterLong(10000,hi,lo);
        }
        for(open_trades){
            if( TradeIsOpen && TradeIsLong ){
                longs = 1;
                exitShort();
            }
            else if( TradeIsOpen && TradeIsShort ){
                shorts = 1;
                exitLong();
            }
        }
    }


    if( hour() == HourExit ){
        exitLong();
        exitShort();
        longs = 0;
        shorts = 0;
    }


    plot("High",hi,0,RED);
    plot("Low",lo,0,BLUE);

    plot("Tr",TradingTime,BARS+NEW,RED);
    plot("Longs",longs,BARS+NEW,RED);
    plot("Shorts",shorts,BARS+NEW,RED);



}