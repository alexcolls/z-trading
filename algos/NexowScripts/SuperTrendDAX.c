
#include <NexowFunctions.h>
/*
double SuperTrend( int Periods, double Multiplier ){

    static double Up1, Dn1, Trend1;
    int Trend = 0, Flag = 0;

    double Atr = ATR(Periods);
    double Price = (priceHigh(0)+priceLow(0))/2;

    if( priceClose(0) > Up1 )
        Trend = 1;
    else if( priceClose(0) < Dn1 )
        Trend = -1;

    if( Trend == 1 && Trend1 == -1 )
        Flag = 1;
    else if( Trend == -1 && Trend1 == 1 )
        Flag = -1;

    if( Trend == 1 && Dn < Dn1 )
        Dn = Dn1;
    else if( Trend == -1 && Up > Up1 )
        Up = Up1;

    if( Flag == 1 )
        Up = Price+multiplier*moy;

    if( flagh == 1 )
        dn[0]=price-multiplier*moy;

    if( trend=1 )
        mysupertrend=dn[0];
    else
        mysupertrend=up[0];

}
*/
void run(){

    set(PLOTNOW);
    StartDate = 20190601;
    BarPeriod = 1;
    LookBack = 100;

    //Spread = RollLong = RollShort = Commission = 0;

    Slippage = 0;


    assetList("OandaEuropeIndex");
    

    double multiplier = 2;
    int period = 10;
    
    double moy = ATR(period);
    double price = (priceHigh(0)+priceLow(0))/2;
    double* up = series(price+multiplier*moy);
    double* dn = series(price-multiplier*moy);

    static int flag, flagh;
    double mysupertrend;

    static int lasttrend, trend = 1;

    if( priceClose(0)>up[1] )
        trend=1;
    else if( priceClose(0)<dn[1] )
        trend=-1;

    if( trend<0 && lasttrend>0 )
        flag=1;
    else
        flag=0;

    if( trend>0 && lasttrend<0 )
        flagh=1;
    else
        flagh=0;

    if( trend>0 && dn[0]<dn[1] )
        dn[0]=dn[1];

    if( trend<0 && up[0]>up[1] )
        up[0]=up[1];

    if( flag == 1 )
        up[0]=price+multiplier*moy;

    if( flagh == 1 )
        dn[0]=price-multiplier*moy;

    if( trend==1 )
        mysupertrend=dn[0];
    else
        mysupertrend=up[0];


    plot("Trend",mysupertrend,0,RED);
    //plot("SAR",SAR(0.02,0.02,0.2),0,BLUE);
    plot("Volume",marketVol(),BARS+NEW,BLUE);

    int GMT = gmtCET();

    int StartHour = 8-GMT;
    int EndHour = 10-GMT;
    
    int TradingHours = 0;

    static double lastspt;

    if( ( hour() == StartHour && minute(0) > 1 ) || ( hour() > StartHour) && hour() < EndHour ){
        TradingHours = 1;
        if( !TradeIsLong ){
            if( priceClose(0) > mysupertrend && priceClose(1) < lastspt )
                enterLong();
        }
        if( !TradeIsShort ){
            if( priceClose(0) < mysupertrend && priceClose(1) > lastspt )
                enterShort();
        }
    }
    plot("TH",TradingHours,BARS+NEW,RED);
    
    if( TradeIsLong && trend == -1 )
        exitLong();
    if( TradeIsShort && trend == 1 )
        exitShort();
    
    lasttrend = trend;
    lastspt = mysupertrend;
    

    /*
    if( !TradeIsLong ){
        if( priceClose(0) > mysupertrend )
            enterLong();
    }
    if( !TradeIsShort ){
        if( priceClose(0) < mysupertrend )
            enterShort();
    }
    */

}