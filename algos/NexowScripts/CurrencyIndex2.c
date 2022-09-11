
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
        #define TIMEFRAME 1440
        #define TIMEZONE UTC

        #define SET_PLOT TRUE

    ///

void run(){

    /// 2. ZORRO PARAMETERS \\\ 
        
        BarZone = TIMEZONE;
        BarPeriod = TIMEFRAME;
        StartDate = 2010;
        //LookBack = WARMUP;
        /*
        if( SET_PLOT ){
            set(PLOTNOW);
            setf(PlotMode,PL_LONG+PL_FINE+PL_DIFF);
        }
        */

        /// 2.1. ASSET & ACCOUNT PARAMETERS

        assetList(ASSETLIST);
        setFXaccounting(1,-1);
        setFees(0.0,0.0,0.0,5);    

    ///

    /// 3. INDICATORS & PORTFOLIO \\\ 
    
    while(asset(loop(Assets))){

        double* Prices = series(priceClose());    
        double MA1 = ZMA(Prices,40);
        double MA2 = ZMA(Prices,80);
        double Dist = ( (priceClose(0)-MA1)/MA1 + (priceClose(0)-MA2)/MA2 )*100;
       
        Ccy_Set(Dist);

    }

    Ccy_Sort(0);

    printf("\n%d",Ccy_n);
    Ccy_Print();
    
    printf("\n%s",Ccy_Best(1));
    printf("\n%s",Ccy_Worst(1));
    printf("\n%s",Ccy_TopPair(1,1));
    printf("\n%d",Ccy_TopPair_Dir);

    printf("\n%f",Ccy_StdDev(0));
    printf("\n%f",Ccy_Avg(1));

    printf("\n%f",Ccy_Val("XAU"));
    printf("\n%d",Ccy_nPairs("XAU"));

    printf("\nNumSym= %d",NumberOfSymbols);

    

    Ccy_Reset();


    
}