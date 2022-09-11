
///----------------------------------\\\ 
///  FX G10 TOP LONG-SHORT STRATEGY  \\\ 
///----------------------------------\\\ 
///        NEXOW SYSTEMS S.L.        \\\ 
///        Author: Alex Colls        \\\ 
///         Date: May 2019           \\\ 
///          Version: 1.1            \\\ 
///----------------------------------\\\ 

#include <NexowFunctions.h>

    /// 1. STRATEGY PARAMETERS \\\ 

        #define ASSETLIST "OandaEuropeFX45"
        #define NUM_OF_ASSETS 45
        #define TIMEFRAME 1440
        #define TIMEZONE UTC
        #define BENCHMARK "SPX500"

        #define PRICE priceClose
        #define MA_TYPE EMA
        #define MA_PERIODS 120
        #define N_DEVS 2
        #define WARMUP 300
        #define TOP 5
        #define THRESHOLD 0

        #define MARGIN_PERCENT 0.1
        #define LOTLIMIT 1000000
        #define LIFETIME 100
        #define MAXORDERS 100
        #define SECSL 20
        #define SECTP 20
        #define MAXFLOATDD 10
        #define MINFLOATDD -80
        #define MAXLEVERAGE 50
        #define MAXLEVPERCURR 50

        #define SET_PLOT TRUE
        #define PLOT_INDICATORS FALSE
        #define PLOT_ACCOUNT TRUE
        #define SET_LOGFILE TRUE   
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
            double MA = MA_TYPE(Prices,MA_PERIODS);
            double StDev = StdDev(Prices,MA_PERIODS);
            double UpBand = MA + StDev * N_DEVS;
            double LoBand = MA - StDev * N_DEVS;
            double Vol = UpBand - LoBand;
            double Dist = ( Prices[0]-LoBand ) / ( Vol );
            Dists[k].Sym = Symbol;
            Dists[k].Val = Dist;
            k++;
            if( PLOT_INDICATORS ){
                plot("MA",MA,0,RED);
                plot("UpBand",UpBand,0,BLUE);
                plot("LoBand",LoBand,0,BLUE);
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

        LotLimit = LOTLIMIT;
        LifeTime = LIFETIME;
        MaxLong = MaxShort = MAXORDERS;

        double ATRxSL = SECSL;
        double ATRxTP = SECTP;
        double MaxFloatingDD = MAXFLOATDD;
        double MinFloatingDD = MINFLOATDD;
        double MaxLeverage = MAXLEVERAGE;
        double MaxLevPerCurrency = MAXLEVPERCURR;

        double FloatingDD = (Equity/Balance-1)*100;

        double AUD,CAD,CHF,EUR,GBP,HKD,JPY,NZD,SGD,USD,XAG,XAU;
        AUD=0;CAD=0;CHF=0;EUR=0;GBP=0;HKD=0;JPY=0;NZD=0;SGD=0;USD=0;XAG=0;XAU=0;
        double CurrLev, PositionLeverage;
        for(open_trades){
            char* Base = Base();
            char* Term = Term();
            CurrLev = TradeLots*MarginCost*Leverage/Equity;
            PositionLeverage += CurrLev;
            if( TradeIsShort ){ CurrLev = CurrLev*(-1); }
            if(strstr(Base,"AUD")){ AUD += CurrLev; } else if( strstr(Term,"AUD")){ AUD -= CurrLev; }
            if(strstr(Base,"CAD")){ CAD += CurrLev; } else if( strstr(Term,"CAD")){ CAD -= CurrLev; }
            if(strstr(Base,"CHF")){ CHF += CurrLev; } else if( strstr(Term,"CHF")){ CHF -= CurrLev; }
            if(strstr(Base,"EUR")){ EUR += CurrLev; } else if( strstr(Term,"EUR")){ EUR -= CurrLev; }
            if(strstr(Base,"GBP")){ GBP += CurrLev; } else if( strstr(Term,"GBP")){ GBP -= CurrLev; }
            if(strstr(Base,"HKD")){ HKD += CurrLev; } else if( strstr(Term,"HKD")){ HKD -= CurrLev; }
            if(strstr(Base,"JPY")){ JPY += CurrLev; } else if( strstr(Term,"JPY")){ JPY -= CurrLev; }
            if(strstr(Base,"NZD")){ NZD += CurrLev; } else if( strstr(Term,"NZD")){ NZD -= CurrLev; }
            if(strstr(Base,"SGD")){ SGD += CurrLev; } else if( strstr(Term,"SGD")){ SGD -= CurrLev; }
            if(strstr(Base,"USD")){ USD += CurrLev; } else if( strstr(Term,"USD")){ USD -= CurrLev; }
            if(strstr(Base,"XAG")){ XAG += CurrLev; } else if( strstr(Term,"XAG")){ XAG -= CurrLev; }
            if(strstr(Base,"XAU")){ XAU += CurrLev; } else if( strstr(Term,"XAU")){ XAU -= CurrLev; }
        }
        
        if( FloatingDD < -abs(MinFloatingDD) || FloatingDD > abs(MaxFloatingDD)|| PositionLeverage > MaxLeverage ){
            for(open_trades){
                exitLong();
                exitShort();
            }
        }        

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
                TakeProfit = priceClose(0)*((double)SECTP/100);
                Stop = priceClose(0)*((double)SECSL/100);
                enterShort();
                
                asset(Worst[i].Sym);
                TakeProfit = priceClose(0)*((double)SECTP/100);
                Stop = priceClose(0)*((double)SECSL/100);
                enterLong();
            }
        }

    ///

    /// 6. ACCOUNT PLOTS \\\ 

        if( PLOT_ACCOUNT ){

            PlotHeight1 = 600;
            PlotHeight2 = 150;

            ColorUp = ColorDn = ColorWin = ColorLoss = ColorEquity = ColorDD = 0;

            asset(BENCHMARK);

            static int r; r++;
            static double InitialBench, InitialBalance, Benchmark;
            if( is(FIRSTRUN) ){
                InitialBench = priceOpen(0);
                InitialBalance = Benchmark = Balance;
            }
            if( r > WARMUP ){
                Benchmark = (priceClose(0)/InitialBench) * InitialBalance;
            }

            static double StartYear, StartMonth;
            static int Year = year();
            static int Month = month();
            if( is(FIRSTRUN) ){
                StartYear = StartMonth = Equity;
            }
            if( year() > Year ){
                StartYear = Equity;
                Year = year();
            }
            if( month() != Month ){
                Month = month();
                StartMonth = Equity;
            }

            static double MaxBalance = Balance;
            static double MaxBalanceB = Benchmark;
            if( Balance > MaxBalance )
                MaxBalance = Balance;
            if( Benchmark > MaxBalanceB )
                MaxBalanceB = Benchmark;
            double UnderWater = (Equity/MaxBalance-1)*100;
            double UnderWaterB = (Benchmark/MaxBalanceB-1)*100;
            double Drawdown = Equity-MaxBalance;
            double DrawdownB = Benchmark-MaxBalanceB;
    
            double Bret = RET(1) * 100;
            static double LastEQ;
            double Pret = ( (Balance-LastEQ)/LastEQ ) * 100;
            LastEQ = Balance;
            static double Br[261], Pr[261], TE[261];
            for (i = 260; i > 0; i--)
            {
                Br[i] = Br[i-1];
                Pr[i] = Pr[i-1];
                TE[i] = TE[i-1];
            }
            Br[0] = Bret; Pr[0] = Pret; TE[0] = Pret-Bret;
            
            double R, Sy, Sx, Ay, Ax, Beta, Alpha, Sharpe, TrackingError;
            if( r > WARMUP+260 ){
                R = Correlation(Br,Pr,260);
                Sy = StdDev(Br,260);
                Sx = StdDev(Pr,260);
                Ay = SMA(Br,260);
                Ax = SMA(Pr,260);
                Beta = Covariance(Pr,Br,260)/Variance(Br,260);
                Alpha = ( Ax - ( Beta * Ay ) ) ;
                Sharpe = Ax / Sx;
                TrackingError = StdDev(TE,260);
            }            

            asset(AssetBox);

            plot("Balance",Balance,BARS,GREY);
            plot("Equity",Equity,BARS,0x1E86E2+TRANSP);
            plot("StartYear",StartYear,0,BLACK+TRANSP);
            plot("StartMonth",StartMonth,0,BLACK+TRANSP);
            plot("MarginUsed",MarginVal,BARS,BLACK);
            plot("Benchmark",Benchmark,0,RED);
            
            plot("DDBenchmark",DrawdownB,BARS,RED+TRANSP);
            plot("DrawDown",Drawdown,BARS,GREY+TRANSP);
            plot("P1",0,0,BLACK);

            plot("P2",0,1,BLACK);
            plot("UWBenchmark",UnderWaterB,BARS,RED+TRANSP);
            plot("UnderWater",UnderWater,BARS,0x1E86E2+TRANSP);
            
            plot("MaxFloatingDD",abs(MaxFloatingDD),1,BLACK);
            plot("FloatingDD",FloatingDD,BARS,0x1E86E2+TRANSP);
            plot("MinFloatingDD",-abs(MinFloatingDD),0,BLACK);
            plot("P3",0,0,BLACK);           

            plot("Leverage",PositionLeverage,1,0x1E86E2);
            plot("MaxLeverage",MaxLeverage,0,BLACK);
            plot("1",1,0,BLACK);
            plot("P4",0,0,BLACK);
            
            plot("AUD",AUD,1,OLIVE);
            plot("CAD",CAD,0,GREEN);
            plot("CHF",CHF,0,BLUE);            
            plot("EUR",EUR,0,ORANGE);            
            plot("GBP",GBP,0,DARKBLUE);
            plot("HKD",HKD,0,LIGHTBLUE);
            plot("JPY",JPY,0,PURPLE);
            plot("NZD",NZD,0,MAGENTA);
            plot("SGD",SGD,0,DARKGREEN);
            plot("USD",USD,0,CYAN);
            plot("XAG",XAG,0,SILVER);
            plot("XAU",XAU,0,YELLOW);
            plot("MaxLev",MaxLevPerCurrency,0,BLACK);
            plot("-MaxLev",-MaxLevPerCurrency,0,BLACK);
            plot("P5",0,0,BLACK);

            
            plot("Alpha",Alpha,1,RED);
            plot("P6",0,0,BLACK);
            
            plot("Beta",Beta,1,BLUE);
            plot("P7",0,0,BLACK);

            plot("Sharpe",Sharpe,1,BLUE);
               
            

        }

    ///

}