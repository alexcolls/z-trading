
///----------------------------------\\\ 
///      FX G12 CURRENCY INDEX       \\\ 
///----------------------------------\\\ 
///        NEXOW SYSTEMS S.L.        \\\ 
///        Author: Alex Colls        \\\ 
///         Date: May 2019           \\\ 
///          Version: 1.0            \\\ 
///----------------------------------\\\ 

#include <NexowFunctions.h>

    /// 1. STRATEGY PARAMETERS \\\ 

        #define ASSETLIST "AssetsFix"
        #define TIMEFRAME 60
        #define TIMEZONE UTC

        #define SET_PLOT TRUE

    ///

void run(){

    /// 2. ZORRO PARAMETERS \\\ 
        
        BarZone = TIMEZONE;
        BarPeriod = TIMEFRAME;
        StartDate = 2007;
        LookBack = 200;
        /*
        if( SET_PLOT ){
            set(PLOTNOW);
            setf(PlotMode,PL_LONG+PL_FINE+PL_DIFF);
        }
        */
       set(PLOTNOW);

        /// 2.1. ASSET & ACCOUNT PARAMETERS

        assetList(ASSETLIST);
        setFXaccounting(1,-1);
        setFees(0.0,0.0,0.0,5);    

    ///

    /// 3. INDICATORS & PORTFOLIO \\\ 
    
    while(asset(loop(Assets))){
        double* Prices = series(priceClose());    
        double MA1 = EMA(Prices,8);
        double MA2 = EMA(Prices,24);
        double MA3 = EMA(Prices,120);
        double Dist = ( (priceClose(0)-MA1)/MA1 + (priceClose(0)-MA2)/MA2 + (priceClose(0)-MA3)/MA3 )*100;
        Ccy_Set(Dist);
    }

    asset(AssetBox);
    int i; double X, Y;
    for( i = 0; i < 12; i++){
        if( strstr(Ccy[i].Ccy,Base()) ){
            X = Ccy[i].Val;
        }
        if( strstr(Ccy[i].Ccy,Term()) ){
            Y = Ccy[i].Val;
        }
    }

    double* Prices = series(priceClose());   
    double MA1 = EMA(Prices,8);
    double MA2 = EMA(Prices,24);
    double MA3 = EMA(Prices,120);
    double Dist = ( (priceClose(0)-MA1)/MA1 + (priceClose(0)-MA2)/MA2 + (priceClose(0)-MA3)/MA3 )*100;

    plot("MA1",MA1,0,RED);
    plot("MA2",MA2,0,RED);
    plot("MA3",MA3,0,RED);

    plot("Base",X,1,RED);
    plot("Term",Y,0,BLUE);
    plot("XY",X-Y,0,GREEN);
    plot("Pair",Dist,0,BLACK);
    plot("0",0,0,BLACK);
    
    Ccy_Reset();

    if( !TradeIsOpen ){
        if( X > 0 && Y < 0 )
            enterLong();
        else if( X < 0 && Y > 0 )
            enterShort();
    }
    else if( ( X > 0 && Y > 0 ) || ( X < 0 && Y < 0 ) ){
        exitLong();exitShort();
    }
    


}