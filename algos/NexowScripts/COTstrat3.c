
///------------------------------------\\\ 
///  FX G8 TOP LONG-SHORT STRATEGY COT \\\ 
///------------------------------------\\\ 
///         NEXOW SYSTEMS S.L.         \\\ 
///         Author: Alex Colls         \\\ 
///          Date: June 2019           \\\ 
///           Version: 1.0.            \\\ 
///------------------------------------\\\ 

#include <NexowFunctions.h>

typedef struct{
char Sym[4];
char Code[7];
double NC;
double OI;
} cotstruct;

cotstruct COT[8];

void SetCOTcodes(){
    strcpy(COT[0].Sym,"AUD");
    strcpy(COT[0].Code,"232741");
    strcpy(COT[1].Sym,"CAD");
    strcpy(COT[1].Code,"090741");
    strcpy(COT[2].Sym,"CHF");
    strcpy(COT[2].Code,"092741");
    strcpy(COT[3].Sym,"EUR");
    strcpy(COT[3].Code,"099741");
    strcpy(COT[4].Sym,"GBP");
    strcpy(COT[4].Code,"096742");
    strcpy(COT[5].Sym,"JPY");
    strcpy(COT[5].Code,"097741");
    strcpy(COT[6].Sym,"NZD");
    strcpy(COT[6].Code,"112741");
    strcpy(COT[7].Sym,"UDI"); // US Dollar Index
    strcpy(COT[7].Code,"098662");
}

    /// 1. STRATEGY PARAMETERS \\\ 

        #define ASSETLIST "FX28"
        #define NUM_OF_ASSETS 28
        #define TIMEFRAME 1440
        #define TIMEZONE UTC

        #define PRICE priceClose
        #define MA_TYPE ZMA
        #define MA1_PERIODS 200
        #define MA2_PERIODS 600
        #define WARMUP 200
        #define TOP 8
        #define THRESHOLD 1

        #define MARGIN_PERCENT 0.01
 
        #define SET_PLOT TRUE
        #define PRINT_LOGS FALSE


    ///

void run(){

    /// 2. ZORRO PARAMETERS \\\ 
        
        BarZone = TIMEZONE;
        BarPeriod = TIMEFRAME;
        LookBack = WARMUP;

        if( is(INITRUN) ){
            SetCOTcodes();
        }

        if( SET_PLOT ){
            set(PLOTNOW);
            setf(PlotMode,PL_LONG+PL_FINE+PL_DIFF);
        }
        if( TESTMODE ){
            Capital = 100000;
            StartDate = 2010;
        }

        /// 2.1. ASSET & ACCOUNT PARAMETERS

        assetList(ASSETLIST);
        setFXaccounting(1,-1);
        //setFees(0.01,0.003,0.2,5);
        setFees(0.0,0.0,0.0,5);    

    ///

    /// 3. INDICATORS & PORTFOLIO \\\ 

        /// 3.1. CALCULATE THE DISTANCES OF EACH INSTRUMENT 
        
        int i; bool OnlyFutures = TRUE;
        for( i = 0; i < 8; i++){
            COT[i].NC = COT_NonCom(COT[i].Code,OnlyFutures);
            COT[i].OI = COT_OpIn(COT[i].Code,OnlyFutures);
            //printf("\ni= %d, handle= %d, Sym= %s, Code= %s, NC= %f",i,handle,COT[i].Sym,COT[i].Code,COT[i].NC);
        }
        handle = 1;

        symval NonCom[NUM_OF_ASSETS];
        int k, i;
        while(asset(loop(Assets))){
            double Xnc, Xoi, Ync, Yoi;
            for( i = 0; i < 7; i++){
                if( strstr(COT[i].Sym,Base()) ){
                    Xnc = COT[i].NC;
                    Xoi = COT[i].OI;
                    break;
                }
            }
            for( i = 0; i < 7; i++){
                if( strstr(COT[i].Sym,Term()) ){
                    Ync = COT[i].NC;
                    Yoi = COT[i].OI;
                    break;
                }
            }
            double COTnc = (double)Xnc*((double)Yoi/(double)Xoi)-(double)Ync*((double)Xoi/(double)Yoi);
            //double COTnc = (double)Xnc-(double)Ync;
            NonCom[k].Sym = Symbol;
            NonCom[k].Val = COTnc;
            k++;
            plot("COT",COTnc,1,BLUE);
            plot("Xnc",Xnc,0,GREEN+TRANSP);
            plot("Ync",Ync,0,RED+TRANSP);
            plot("Z",0,0,BLACK);

        }
    
        /// 3.2. CALCULATE THE ABSOLUTE AVERGAE OF THE CURRENT DISTANCE

        double AvgNC;
        int i;
        for( i = 0; i < NUM_OF_ASSETS; i++){
            AvgNC += abs(NonCom[i].Val);
        }
        AvgNC = (AvgNC/NUM_OF_ASSETS)*(double)THRESHOLD;

        while(asset(loop(Assets))){
            int i;
            for( i = 0; i < NUM_OF_ASSETS; i++){         
                if( strstr(NonCom[i].Sym,Symbol) ){
                    if( NonCom[i].Val > AvgNC )
                        enterLong();
                    else if( NonCom[i].Val < -AvgNC )
                        enterShort();
                    else{ exitLong(); exitShort(); }
                    break;
                }
            }
            plot("AvgNC",AvgNC,0,BLACK);
            plot("-AvgNC",-AvgNC,0,BLACK);

        }
        
}