
///----------------------------------\\\ 
///  FX G10 TOP LONG-SHORT STRATEGY  \\\ 
///----------------------------------\\\ 
///        NEXOW SYSTEMS S.L.        \\\ 
///        Author: Alex Colls        \\\ 
///         Date: April 2019         \\\ 
///          Version: 1.0.           \\\ 
///----------------------------------\\\ 

#include <nexow.h>

    /// 1. STRATEGY PARAMETERS \\\ 

        #define ASSETLIST "OandaEuropeFX45.csv"
        #define NUM_OF_ASSETS 45
        #define TIMEFRAME 1440
        #define TIMEZONE UTC
        #define BENCHMARK "SPX500_USD"

        #define PRICE price
        #define MA_TYPE ZMA
        #define MA1_PERIODS 250
        #define MA2_PERIODS 500
        #define WARMUP 120
        #define TOP 20
        #define THRESHOLD 2

        #define MARGIN_PERCENT 0.01

    ///

void run(){

    /// 2. ZORRO PARAMETERS \\\ 
        
        BarZone = TIMEZONE;
        BarPeriod = TIMEFRAME;
        LookBack = WARMUP;

        set(PLOTNOW);
        setf(PlotMode,PL_LONG+PL_FINE+PL_DIFF);
  
        if( TESTMODE ){
            Capital = 100000;
            StartDate = 2019;
        }

        /// 2.1. ASSET & ACCOUNT PARAMETERS

        assetList(ASSETLIST);
        //setFXaccounting(1,-1,"_");
        //setFees(0.01,0.003,0.2,5);
        setFees(0.0,0.0,-1,5);    

    ///

    /// 3. INDICATORS & PORTFOLIO \\\ 

        /// 3.1. CALCULATE THE DISTANCES OF EACH INSTRUMENT 

        int i, j, k;
        double AvgDists;
        symval Dists[NUM_OF_ASSETS];
        while(asset(loop(Assets))){
            if( !strstr(Symbol,BENCHMARK) ){
                double* Prices = series(PRICE());    
                double MA1 = MA_TYPE(Prices,MA1_PERIODS);
                double MA2 = MA_TYPE(Prices,MA2_PERIODS);
                double Dist = ( (priceClose(0)-MA1)/MA1 + (priceClose(0)-MA2)/MA2 )*100;
                Dists[k].Sym = Symbol;
                Dists[k].Val = Dist;
                k++;
            }
        }
        
        /// 3.2. CALCULATE THE ABSOLUTE AVERGAE OF THE CURRENT DISTANCE

        for( i = 0; i < NUM_OF_ASSETS; i++){
            AvgDists += abs(Dists[i].Val)/NUM_OF_ASSETS; 
        }

        /// 3.3. SORT THE DISTANCES ARRAY

        sortsymval(NUM_OF_ASSETS,Dists);

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

    ///

    /// 4. RISK MANAGEMENT \\\ 
 
        /// 4.1. MONEY MANAGEMENT

        double Quantity = (MARGIN_PERCENT/100) * Balance;      

    ///

    /// 5. TRADING RULES \\\ 

        /// 5.1. EXIT RULES

        while(asset(loop(Assets))){
            if( !strstr(Symbol,BENCHMARK) ){
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

        printf("\n%f",Balance);

    ///

    /// 6. ACCOUNT PLOTS \\\ 

        //setAccountPlot(BENCHMARK, 1);

    ///

}