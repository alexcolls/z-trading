
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
    strcpy(COT[7].Sym,"USD"); // US Dollar Index
    strcpy(COT[7].Code,"098662");
}

    /// 1. STRATEGY PARAMETERS \\\ 

        #define ASSETLIST "FX28"
        #define NUM_OF_ASSETS 28
        #define TIMEFRAME 60
        #define TIMEZONE UTC

        #define PRICE priceClose
        #define MA_TYPE ZMA
        #define MA1_PERIODS 10
        #define MA2_PERIODS 60
        #define WARMUP 200
        #define TOP 8
        #define THRESHOLD 0

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
        
        double USD_COT = 0;
        double USD_OI = 0;
        int i; bool OnlyFutures = TRUE;
        for( i = 0; i < 7; i++){
            COT[i].NC = COT_NonCom(COT[i].Code,OnlyFutures);
            USD_COT -= COT[i].NC;
            COT[i].OI = COT_OpIn(COT[i].Code,OnlyFutures);
            USD_OI += COT[i].OI;
            //printf("\ni= %d, handle= %d, Sym= %s, Code= %s, NC= %f",i,handle,COT[i].Sym,COT[i].Code,COT[i].NC);
        }
        COT[7].NC = USD_COT/7;
        COT[7].OI = USD_OI/7;
        handle = 1;

        symval2 Dists[NUM_OF_ASSETS];
        int k, i;
        while(asset(loop(Assets))){
            double* Prices = series(PRICE());    
            double MA1 = MA_TYPE(Prices,MA1_PERIODS);
            double MA2 = MA_TYPE(Prices,MA2_PERIODS);
            double Dist = ( (priceClose(0)-MA1)/MA1 + (priceClose(0)-MA2)/MA2 )*100;
            Dists[k].Sym = Symbol;
            Dists[k].Val1 = Dist;
            double Xnc, Xoi, Ync, Yoi;
            Xnc = Xoi = Ync = Yoi = 0;
            for( i = 0; i < 8; i++){
                if( strstr(COT[i].Sym,Base()) ){
                    Xnc = COT[i].NC;
                    Xoi = COT[i].OI;
                    break;
                }
            }
            for( i = 0; i < 8; i++){
                if( strstr(COT[i].Sym,Term()) ){
                    Ync = -COT[i].NC;
                    Yoi = COT[i].OI;
                    break;
                }
            }
            double Rx = (double)Yoi/(double)Xoi;
            double Ry = (double)Xoi/(double)Yoi;
            //Xnc = Xnc * Rx;
            //Ync = Ync * Ry;
            double COTnc = Xnc+Ync;
            double Dir;
            if( Xnc > 0 && Ync < 0 && COTnc > 0 && priceClose(0) > MA2 )
                Dir = 1;
            else if( Xnc < 0 && Ync > 0 && COTnc < 0 && priceClose(0) < MA2 )
                Dir = -1;
            else Dir = 0;
            Dists[k].Val2 = Dir;
            k++;

            plot("MA1",MA1,0,RED);
            plot("MA2",MA2,0,BLUE);
            plot("Dir",Dir,1,BLUE);
            plot("Z2",0,0,BLACK);
            plot("COT",COTnc,1,BLACK);
            plot("Xnc",Xnc,0,GREEN+TRANSP);
            plot("Ync",Ync,0,RED+TRANSP);
            plot("Z",0,0,BLACK);
            plot("Dist",Dist,1,RED);

        }
        /*
        /// 3.2. CALCULATE THE ABSOLUTE AVERGAE OF THE CURRENT DISTANCE

        double AvgDists, AvgNC;
        int i;
        for( i = 0; i < NUM_OF_ASSETS; i++){
            AvgDists += abs(Dists[i].Val1);
            AvgNC += abs(Dists[i].Val2);
        }
        AvgDists = (AvgDists/NUM_OF_ASSETS)*(double)THRESHOLD;
        AvgNC = (AvgNC/NUM_OF_ASSETS)*(double)THRESHOLD;

        while(asset(loop(Assets))){
            //plot("AvgNC",AvgNC,0,BLACK);
            //plot("-AvgNC",-AvgNC,0,BLACK);
            plot("AvgDists",AvgDists,0,BLACK);
            plot("-AvgDists",-AvgDists,0,BLACK);
            plot("Z1",0,0,BLACK);
        }
        
        /// 3.3. SORT THE DISTANCES ARRAY

        sortsymval2(NUM_OF_ASSETS,Dists);

        if( PRINT_LOGS ){
            printf("\n");
            int i;
            for( i = 0; i < NUM_OF_ASSETS; i++){
                printf("\ni= %d, Sym= %s, Val1= %f, Val2= %f", i, Dists[i].Sym, Dists[i].Val1, Dists[i].Val2);
            }
        }

        /// 3.4. TOP BEST & WORST

        symval2 Best[TOP];
        int i;
        for( i = 0; i < TOP; i++)
        {
            Best[i].Sym = Dists[i].Sym;
            Best[i].Val1 = Dists[i].Val1;
            Best[i].Val2 = Dists[i].Val2;
        }
        symval2 Worst[TOP];
        int i, j;
        for( i = NUM_OF_ASSETS-1; i > NUM_OF_ASSETS-TOP-1; i--)
        {
            Worst[j].Sym = Dists[i].Sym;
            Worst[j].Val1 = Dists[i].Val1;
            Worst[j].Val2 = Dists[i].Val2;
            j++;
        }

        symval2 Middle[TOP];
        double MidPoint = (double)NUM_OF_ASSETS/2;
        double MidTop = (double)TOP/2;
        int StartIndex = (int)MidPoint-(int)MidTop;
        int i;
        for( i = 0; i < TOP; i++)
        {
            Middle[i].Sym = Dists[StartIndex+i].Sym;
            Middle[i].Val1 = Dists[StartIndex+i].Val1;
            Middle[i].Val2 = Dists[StartIndex+i].Val2;
        }


        if( PRINT_LOGS ){
            printf("\n");
            int i;
            for( i = 0; i < TOP; i++){
                printf("\nBest= %d, Sym= %s, Val1= %f, Val2= %f", i, Best[i].Sym, Best[i].Val1, Best[i].Val2);
            }
            int i;
            for( i = 0; i < TOP; i++){
                printf("\nWorst= %d, Sym= %s, Val1= %f, Val2= %f", i, Worst[i].Sym, Worst[i].Val1, Worst[i].Val2);
            }
            int i;
            for( i = 0; i < TOP; i++){
                printf("\nMiddle= %d, Sym= %s, Val1= %f, Val2= %f", i, Middle[i].Sym, Middle[i].Val1, Middle[i].Val2);
            }
        }

    ///

    */
    /// 4.1. MONEY MANAGEMENT

        //double Quantity = (MARGIN_PERCENT/100) * Balance;      

    ///
    /*
    /// 5. TRADING RULES \\\ 

        /// 5.1. EXIT RULES
        
        while(asset(loop(Assets))){
            int Top = 0;
            int i;
            for( i = 0; i < TOP; i++){
                if( strcmp(Symbol,Best[i].Sym) == 0 ){
                    exitLong();
                    Top = 1;
                    break;
                }
                else if( strcmp(Symbol,Worst[i].Sym) == 0 ){
                    exitShort();
                    Top = -1;
                    break;
                }
            }
            if( Top == 0 ){
                exitLong();
                exitShort();
            }
        }
        
        
        /// 5.1. ENTRY RULES
        
        int i;
        for( i = 0; i < TOP; i++)
        {
            if( Best[i].Val1 > AvgDists && Best[i].Val2 == 0 )
            {
                asset(Best[i].Sym);
                double Ratio = (((double)TOP-(double)i)/(double)TOP);
                Margin = Quantity;// * Ratio;
                enterShort();
            }
            if( Worst[i].Val1 < -AvgDists && Worst[i].Val2 == 0 )
            {
                asset(Worst[i].Sym);
                double Ratio = (((double)TOP-(double)i)/(double)TOP);
                Margin = Quantity;// * Ratio;
                enterLong();
            }
            /*
            if( abs(Middle[i].Val1) < AvgDists )
            {
                asset(Middle[i].Sym);
                double Ratio = (((double)TOP-(double)i)/(double)TOP);
                Margin = Quantity;// * Ratio;
                if( Middle[i].Val2 > 0 )
                    enterLong();
                else if( Middle[i].Val2 < 0 )
                    enterShort();
            }
            
        }
    */
    ///
        
}