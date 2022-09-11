
#include <NexowFunctions.h>

// Timeframe in minutes:
#define TIMEFRAME 1
// Backtesting start date:
#define STRATDATE 2019
// Trading Hours:
#define STRATHOUR 8
#define ENDHOUR 10
// SuperTrend Paramaters:
#define PERIODS 10
#define MULTIPLY 3
// Trading session pips limit:
#define MAXPIPS 100
#define MINPIPS -100

int Trend = 1;
double LastVal;
double SuperTrend( int Periods, double Multiply ){
    double Price = (priceHigh(0)+priceLow(0))/2;
    if( Trend == -1 && priceClose(0) > LastVal ){
        Trend = 1; LastVal = Price - ATR(Periods)*Multiply;
        return LastVal; 
    }
    else if( Trend == 1 && priceClose(0) < LastVal ){
        Trend = -1; LastVal = Price + ATR(Periods)*Multiply;
        return LastVal; 
    }
    if( Trend == 1 ){
        double NewVal = Price - ATR(Periods)*Multiply;
        if( NewVal > LastVal ){
            LastVal = NewVal;
            return NewVal; }
        else return LastVal; 
    }
    else if( Trend == -1 ){
        double NewVal = Price + ATR(Periods)*Multiply;
        if( NewVal < LastVal ){
            LastVal = NewVal;
            return NewVal; }
        else return LastVal; 
    }
}

void run(){

    set(PLOTNOW);
    StartDate = STRATDATE;
    BarPeriod = TIMEFRAME;
    LookBack = 100;
    //Spread = RollLong = RollShort = Commission = Slippage = 0;

    assetList("OandaEuropeIndex");

    int GMT = gmtCET();
    int StartHour = STRATHOUR-GMT;
    int EndHour = ENDHOUR-GMT;

    int Trading = 0;
    double ST = SuperTrend(PERIODS,MULTIPLY);
    static double ST1;
    if( ( hour() == StartHour && minute(0) > 1 ) || ( hour() > StartHour) && hour() < EndHour ){
        Trading = 1;
        if( !TradeIsLong ){
            if( priceClose(0) > ST && priceClose(1) < ST1 )
                enterLong();
        }
        if( !TradeIsShort ){
            if( priceClose(0) < ST && priceClose(1) > ST1 )
                enterShort();
        }
    }
    ST1 = ST;
    if( TradeIsLong && Trend == -1 )
        exitLong();
    if( TradeIsShort && Trend == 1 )
        exitShort();
    
    plot("SuperTrend",ST,0,RED);
    plot("Volume",marketVol(),BARS+NEW,BLUE);    
    plot("TradingTime",Trading,BARS+NEW,RED);

}