
///----------------------------------\\\ 
///  FX G10 TOP LONG-SHORT STRATEGY  \\\ 
///----------------------------------\\\ 
///        NEXOW SYSTEMS S.L.        \\\ 
///        Author: Alex Colls        \\\ 
///         Date: April 2019         \\\ 
///          Version: 1.0.           \\\ 
///----------------------------------\\\ 

#include <NexowFunctions.h>

    /// 1. STRATEGY PARAMETERS \\\ 

        #define ASSETLIST "FX28"
        #define NUM_OF_ASSETS 28
        #define TIMEFRAME 1440
        #define TIMEZONE UTC
        #define BENCHMARK "SPX500"

        #define PRICE priceClose
        #define MA_TYPE ZMA
        #define MA1_PERIODS 40
        #define MA2_PERIODS 80
        #define WARMUP 80
        #define TOP 
        #define THRESHOLD 1

        #define MARGIN_PERCENT 0.05

        #define SET_PLOT TRUE
        #define PLOT_INDICATORS FALSE
        #define PLOT_ACCOUNT TRUE
        #define SET_LOGFILE FALSE   
        #define PRINT_LOGS FALSE

        #define DETREND FALSE
        #define DT_TYPE RECIPROCAL

    ///

void run(){

    /// 2. ZORRO PARAMETERS \\\ 
        
        BarZone = TIMEZONE;
        BarPeriod = TIMEFRAME;
        LookBack = WARMUP;

        if( SET_PLOT ){
            set(PLOTNOW);
            setf(PlotMode,PL_LONG+PL_FINE+PL_DIFF);
        }
        if( SET_LOGFILE ){
            set(LOGFILE);
        }     
        if( TESTMODE ){
            Capital = 100000;
            StartDate = 2007;
            if( DETREND ){
                Detrend = DT_TYPE;
            }
        }

        /// 2.1. ASSET & ACCOUNT PARAMETERS

        assetList(ASSETLIST);
        setFXaccounting(1,-1);
        //setFees(0.01,0.003,0.2,5);
        setFees(0.0,0.0,0.0,5);    

    ///

    /// 3. INDICATORS & PORTFOLIO \\\ 

        /// 3.1. CALCULATE THE DISTANCES OF EACH INSTRUMENT 

        int i, j, k;
        double AvgDists;
        symval Dists[NUM_OF_ASSETS];
        while(asset(loop(Assets))){
            double* Prices = series(PRICE());    
            double MA1 = MA_TYPE(Prices,MA1_PERIODS);
            double MA2 = MA_TYPE(Prices,MA2_PERIODS);
            double Dist = ( (priceClose(0)-MA1)/MA1 + (priceClose(0)-MA2)/MA2 )*100;
            Dists[k].Sym = Symbol;
            Dists[k].Val = Dist;
            k++;
            if( PLOT_INDICATORS ){
                plot("MA1",MA1,0,RED);
                plot("MA2",MA2,0,BLUE);
                plot("Dist",Dist,1,RED);
            }
        }
    
        /// 3.2. CALCULATE THE ABSOLUTE AVERGAE OF THE CURRENT DISTANCE

        for( i = 0; i < NUM_OF_ASSETS; i++){
            AvgDists += abs(Dists[i].Val)/NUM_OF_ASSETS; 
        }

        if( PLOT_INDICATORS ){
            asset(AssetBox);
            plot("AvgDists",AvgDists,0,BLACK);
            plot("-AvgDists",-AvgDists,0,BLACK);
        }
        
        /// 3.3. SORT THE DISTANCES ARRAY

        sortsymval(NUM_OF_ASSETS,Dists);

        if( PRINT_LOGS ){
            printf("\n");
            for( i = 0; i < NUM_OF_ASSETS; i++){
                printf("\ni= %d, Sym= %s, Val= %f", i, Dists[i].Sym, Dists[i].Val);
            }
        }

        /// 3.4. TOP BEST & WORST

        symval Best[TOP];
        for( i = 0; i < TOP; i++)
        {
            Best[i].Sym = Dists[i].Sym;
            Best[i].Val = Dists[i].Val;
        }
        symval Worst[TOP];
        for( i = NUM_OF_ASSETS-1; i > NUM_OF_ASSETS-TOP-1; i--)
        {
            Worst[j].Sym = Dists[i].Sym;
            Worst[j].Val = Dists[i].Val;
            j++;
        }

        if( PRINT_LOGS ){
            printf("\n");
            for( i = 0; i < TOP; i++){
                printf("\nBest= %d, Sym= %s, Val= %f", i, Best[i].Sym, Best[i].Val);
            }
            for( i = 0; i < TOP; i++){
                printf("\nWorst= %d, Sym= %s, Val= %f", i, Worst[i].Sym, Worst[i].Val);
            }
        }

    ///

    /// 4. RISK MANAGEMENT \\\ 



        /// 4.1. MONEY MANAGEMENT

        double Quantity = (MARGIN_PERCENT/100) * Balance;      

    ///

    /// 5. TRADING RULES \\\ 

        /// 5.1. EXIT RULES

        while(asset(loop(Assets))){
            int Top = 0;
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
            if( PLOT_INDICATORS ){
                plot("Top",Top,1,BLUE);
            }
        }
        
        /// 5.1. ENTRY RULES
        
        double Thres = THRESHOLD;
        for( i = 0; i < TOP; i++)
        {
            if( Best[i].Val > AvgDists*Thres && Worst[i].Val < -AvgDists*Thres )
            {
                double Ratio = (((double)TOP-(double)i)/(double)TOP);
                Margin = Quantity * Ratio;
                
                asset(Best[i].Sym);
                enterShort();
                
                asset(Worst[i].Sym);
                enterLong();
            }
        }

    ///

    /// 6. ACCOUNT PLOTS \\\ 

        setCurrencyLeverage();
        SetAccountPlots( "SPX500_USD", 1 );

    ///

}