
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
    printf("\n");
    Ccy_Print();
    printf("\n");
    
    Ccy_AddVals(10);


    /*
    int i, j;
    for( i = 0; i < Ccy_n; i++ )
    {
        for( j = 0; j < 5; j++ )
        {
            printf("\ni= %d Sym= %s j= %d Val= %f",i,Ccy_Vals[i].Ccy,j,Ccy_Vals[i].Val[j]);
        }
        printf("\n");
    }
    printf("\n");
    */
    ccyccyval Pairs_Correl[133];

    int i, j, n;
    for ( i = 0; i < Ccy_n; i++ ){
        double Correl;
        for( j = 0; j < Ccy_n; j++ ){
            if( !strstr(Ccy_Vals[i].Ccy,Ccy_Vals[j].Ccy) ){
                strcpy(Pairs_Correl[n].Ccy1,Ccy_Vals[i].Ccy);
                strcpy(Pairs_Correl[n].Ccy2,Ccy_Vals[j].Ccy);
                Pairs_Correl[n].Val = Correlation(Ccy_Vals[i].Val,Ccy_Vals[j].Val,5);
                n++;
            }
        }
    }
    
    for( i = 0; i < 132; i++ ){
        printf("\ni= %d Ccy1= %s Ccy2= %s Val= %f",i,Pairs_Correl[i].Ccy1,Pairs_Correl[i].Ccy2,Pairs_Correl[i].Val);
    }
    
    Ccy_Reset();
    
}