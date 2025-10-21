
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

    printf("\n\n");
    
    ccyval Ccy[30];
    int i, j;
    while(asset(loop(Assets))){
        if( IsFX() ){
            char* Base = Base();
            char* Term = Term();

            double Indic = 2.5;
        
            for(i = 0; i < j+1; i++)
            {
                if( Ccy[i].Ccy[0] == '\0' ){
                    strcpy(Ccy[i].Ccy,Base);
                    j++;
                    break;
                }
                else if( strstr(Ccy[i].Ccy,Base) ){
                    Ccy[i].Val += Indic;
                    Ccy[i].n++;
                    break;
                }
            }

            for(i = 0; i < j+1; i++)
            {
                if( Ccy[i].Ccy[0] == '\0' ){
                    strcpy(Ccy[i].Ccy,Term);
                    j++;
                    break;
                }
                else if( strstr(Ccy[i].Ccy,Term) ){
                    Ccy[i].Val -= Indic;
                    Ccy[i].n++;
                    break;
                }
            }

        }

    }

    int i;
    for(i = 0; i < j; i++)
    {
        printf("\ni= %d, Ccy= %s, Val= %f, n= %d", i, Ccy[i].Ccy, Ccy[i].Val, Ccy[i].n);
    }

    
}