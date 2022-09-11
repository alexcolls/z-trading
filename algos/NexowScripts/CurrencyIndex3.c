
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
       set(PLOTNOW);

        /// 2.1. ASSET & ACCOUNT PARAMETERS

        assetList(ASSETLIST);
        setFXaccounting(1,-1);
        setFees(0.0,0.0,0.0,5);    

    ///

    /// 3. INDICATORS & PORTFOLIO \\\ 
    
    while(asset(loop(Assets))){
        Ccy_Set(RET(1)*100);
    }

    static ccyvals Ccy_vars[20];
    int Per = 5;

    int i, j;
    if( is(FIRSTRUN) ){
        for( i = 0; i < Ccy_n; i++ )
        {
            strcpy(Ccy_vars[i].Sym,Ccy[i].Ccy);
        }
    }
    
    for( i = 0; i < Ccy_n; i++ )
    {
        for( j = 0; j < Per; j++ )
        {
            Ccy_vars[i].Val[Per-j] = Ccy_vars[i].Val[Per-j-1];
        }
        printf("\n%f",Ccy[i].Val);
        Ccy_vars[i].Val[0] = Ccy[i].Val;
    }
    
    for( i = 0; i < Ccy_n; i++ )
    {
        for( j = 0; j < Per; j++ )
        {
            printf("\ni= %d Sym= %s j= %d Val= %f",i,Ccy_vars[i].Sym,j,Ccy_vars[i].Val[j]);
        }
        printf("\n");
    }
    
    printf("\n");

    Ccy_Reset();
    
}