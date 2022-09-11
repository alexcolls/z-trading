


/*---------------------------------------------------------------*/
/*|||||||||||||||| Nexow - FX_G3_SUPERNOVA.v1.1. ||||||||||||||||*/
/*---------------------------------------------------------------*/


#include <nexow.h>
#define ASSETS 3
#define WEEKS 12
#define ALGOS 30


void run() 
{	


    //// Engine ////


        // Params //


            BarPeriod = 60;
            LookBack = 500;
            //Hedge = 1; // No NFA compliant. Hedging across algos.
            StartDate = 2005;
            StartWeek = 10000; // No Sundays.
            MonteCarlo = 0;
            Capital = 100000; // Test Capital.


        // Charting //


            setf(PlotMode,PL_FINE+PL_DIFF);
            PlotHeight1 = 600;
            PlotHeight2 = 80;
            set(PLOTNOW); // |LOGFILE

        //



    //// FX_G3_SUPERNOVA ////


        // Instruments //

            assetList( "FXG3_SuperNova" );
            /*EUR_GBP, EUR_USD, GBP_USD*/


        // Algos //

            static string Algos[ALGOS];
            if( is(INITRUN) )
            {
                Algos[0] =  "EURGBP_X0_L";
                Algos[0] =  "EURGBP_X0_S";
                Algos[0] =  "EURUSD_X0_L";
                Algos[0] =  "EURUSD_X0_S";
                Algos[0] =  "GBPUSD_X0_L";
                Algos[0] =  "GBPUSD_X0_S";
            }


        // Global Variables //

            // init //

                static bool     GO = false;
                static short    r = 0, Wk = 0;
                static double   WKop[ASSETS];
                static double   WKmax[ASSETS], WKmin[ASSETS],  WKmid[ASSETS];
                static double   WKmaxs[ASSETS][WEEKS], WKmins[ASSETS][WEEKS];
                static double   MNmax[ASSETS], MNmin[ASSETS];
                static double   ZZhi[ASSETS],  ZZlo[ASSETS];
                static double   ZZmax[ASSETS], ZZmin[ASSETS];
                static int      ZZdir[ASSETS], ZZlen[ASSETS];
                static double   ZZmid[ASSETS];
                static int      EURGBP, EURUSD, GBPUSD;
                static int      EUR, GBP, USD;
                
                static int      EURGBPpos, EURUSDpos, GBPUSDpos;

                static double* EURGBPr;
                static double* EURUSDr; 
                static double* GBPUSDr;
                

            // account //

                double DD = FloatingDD();


        // Trading Session //

            if( ( dow(0) == 2 && hour(0) >= 7  ) ||
                ( dow(0) == 5 && hour(0) <= 12 ) ||
                ( dow(0) >  2 && dow(0) < 5  ) )
            {
                GO = true;
            }
            else
            {
                GO = false;
            }
                 
            // if( !GO )
            // {
            //     while( asset( loop(Assets) ) )
            //     {
            //         while( algo( loop(Algos) ) )
            //         {
            //             exitLong();
            //             exitShort();
            //         }
            //     }
            // }


        // Strategy //

            // Delete Noise //
            
                int k = 0;
                while( asset( loop(Assets) ) )
                {
                    if( dow(0) == 1 && hour(0) == 0 && minute(0) == 0 )
                    {
                        EURGBPpos = EURUSDpos = GBPUSDpos = 0;
                        int i; const int j = WEEKS; 
                        for( i = 1; i < j; i++ )
                        {
                            WKmaxs[k][j - i] = WKmaxs[k][j - i - 1];
                            WKmins[k][j - i] = WKmins[k][j - i - 1];
                        }
                        WKmaxs[k][0] = WKmax[k];
                        WKmins[k][0] = WKmin[k];
                        
                        double maxs[WEEKS];
                        double mins[WEEKS];
                        for( i = 0; i < j; i++ )
                        {
                            maxs[i] = WKmaxs[k][i];
                            mins[i] = WKmins[k][i];
                        }
                        MNmax[k] = Sum( maxs,j )/(float)j;
                        MNmin[k] = Sum( mins,j )/(float)j;
                        
                        WKmax[k] = ZZhi[k] = ZZmax[k] = priceHigh(0);
                        WKmin[k] = ZZlo[k] = ZZmin[k] = priceLow(0);

                        WKop[k] = priceOpen(0);
                        
                        ZZlen[k] = 0;
                        if( priceClose(0) > priceOpen(0) )
                            ZZdir[k] = 1;
                        else
                            ZZdir[k] = -1;  
                    }
                    plot( "WKop",WKop[k],MAIN+LINE,BLACK );
                    
                    WKmax[k] = max( WKmax[k],priceHigh(0) );
                    plot( "WKmax",WKmax[k],MAIN,RED );
                    WKmin[k] = min( WKmin[k],priceLow(0) );
                    plot( "WKmin",WKmin[k],MAIN,RED );
                    WKmid[k] = ( WKmax[k]+WKmin[k] )/2;
                    plot( "WKmid",WKmid[k],MAIN,RED+TRANSP );
                    
                    if( Wk > WEEKS )
                    {
                        plot( "MNmax",MNmax[k],MAIN+DOT,RED );
                        plot( "MNmin",MNmin[k],MAIN+DOT,RED );
                    }
                    
                    const int n = 3;
                    const int aTRx = 1;
                    double aTR = ATR(n)*aTRx;
                    
                    const int ZZminBars = 4;
                    if( ZZdir[k] == 1 )
                    {
                        ZZmax[k] = max( ZZmax[k],priceHigh(0) );
                        plot( "ZZmax",ZZmax[k],MAIN+LINE,GREEN+TRANSP );
                        ZZlen[k]++;
                        if( ZZlen[k] >= ZZminBars && priceClose(0) < ( ZZmax[k]-aTR ) )
                        {
                            ZZhi[k] = ZZmax[k];
                            ZZmax[k] = priceClose(0);
                            plot( "ZZhi",ZZhi[k],MAIN+DOT,BLUE );
                            ZZdir[k] = -1;
                            ZZlen[k] = 0;
                        }
                    }
                    else if( ZZdir[k] == -1 )
                    {
                        ZZmin[k] = min( ZZmin[k],priceLow(0) );
                        plot("ZZmin",ZZmin[k],MAIN+LINE,GREEN+TRANSP);
                        ZZlen[k]++;
                        if( ZZlen[k] >= ZZminBars && priceClose(0) > ( ZZmin[k]+aTR ) )
                        {
                            ZZlo[k] = ZZmin[k];
                            ZZmin[k] = priceClose(0);
                            plot( "ZZlo",ZZlo[k],MAIN+DOT,BLUE );
                            ZZdir[k] = 1;
                            ZZlen[k] = 0;
                        }
                    }
                    double Max = max( ZZhi[k],ZZmax[k] );
                    double Min = min( ZZlo[k],ZZmin[k] );
                    ZZmid[k] = ( Max+Min )/2;
                    plot( "ZZmid",ZZmid[k],MAIN+LINE,BLUE+TRANSP );
                    
                    k++;

                }

            // CCYs direction //

                EUR = GBP = USD = 0;

                asset("EUR_GBP");
                if( ZZmid[0] > MNmax[0] )
                {
                    EUR++;
                    GBP--;
                }
                else if( ZZmid[0] < MNmin[0] )
                {
                    EUR--;
                    GBP++;
                }
                
                asset("EUR_USD");
                if( ZZmid[1] > MNmax[1] ){
                    EUR++;
                    USD--;
                }
                else if( ZZmid[1] < MNmin[1] )
                {
                    EUR--;
                    USD++;
                }
                
                asset("GBP_USD");
                    if( ZZmid[2] > MNmax[2] )
                    {
                        GBP++;
                        USD--;
                    }
                    else if( ZZmid[2] < MNmin[2] )
                    {
                        GBP--;
                        USD++;
                    }

            // FXpairs direction // simplify


                while( asset( loop(Assets) ) )
                {
                    plot( "0",0,NEW+LINE,BLACK  );
                    plot( "EUR",EUR,LINE,ORANGE );
                    plot( "GBP",GBP,LINE,PURPLE );
                    plot( "USD",USD,LINE,YELLOW );
                    if( strstr( "EUR_GBP",Symbol ) )
                    {
                        EURGBP = ( EUR-GBP );
                        plot( Symbol,EURGBP,NEW+BARS,ORANGE+PURPLE );
                        plot( "EURGBP_+4",4,LINE,BLACK );
                        plot( "EURGBP_+2",2,LINE,BLACK );
                        plot( "EURGBP_0 ",0,LINE,BLACK );
                        plot( "EURGBP_-2",-2,LINE,BLACK );
                        plot( "EURGBP_-4",-4,LINE,BLACK );
                        EURGBPr = series(RET(1));
                        plot("EURGBPr",EURGBPr,NEW+LINE,BLUE);
                    }
                    if( strstr( "EUR_USD",Symbol ) )
                    {
                        EURUSD = ( EUR-USD );
                        plot( Symbol,EURUSD,NEW+BARS,ORANGE+YELLOW );
                        plot( "EURUSD_+4",4,LINE,BLACK );
                        plot( "EURUSD_+2",2,LINE,BLACK );
                        plot( "EURUSD_0 ",0,LINE,BLACK );
                        plot( "EURUSD_-2",-2,LINE,BLACK );
                        plot( "EURUSD_-4",-4,LINE,BLACK );
                        EURUSDr = series(RET(1));
                        plot("EURUSDr",EURUSDr,NEW+LINE,BLUE);
                    }
                    else if( strstr( "GBP_USD",Symbol ) )
                    {
                        GBPUSD = ( GBP-USD );
                        plot( Symbol,GBPUSD,NEW+BARS,PURPLE+YELLOW );
                        plot( "GBPUSD_+4",4,LINE,BLACK );
                        plot( "GBPUSD_+2",2,LINE,BLACK );
                        plot( "GBPUSD_0 ",0,LINE,BLACK );
                        plot( "GBPUSD_-2",-4,LINE,BLACK );
                        plot( "GBPUSD_-4",-4,LINE,BLACK );
                        GBPUSDr = series(RET(1));
                        plot("GBPUSDr",GBPUSDr,NEW+LINE,BLUE);
                    }
                } 



                asset("EUR_GBP");
                double EURGBPc = Correlation(EURUSDr,GBPUSDr,480);
                plot("EURGBPc",EURGBPc,NEW+LINE,RED);
                asset("EUR_USD");
                double EURUSDc = Correlation(EURGBPr,GBPUSDr,480);
                plot("EURUSDc",EURUSDc,NEW+LINE,RED);
                asset("GBP_USD");
                double GBPUSDc = Correlation(EURGBPr,EURUSDr,480);
                plot("GBPUSDc",GBPUSDc,NEW+LINE,RED);


            // Predictive Model //

                //ParabolicReggression( EURGBP, EURUSD, GBPUSD );




        // Trading Mechanics //

            // Logic

                const double qty = 10;
                double size;

                asset("EUR_GBP");
                fees();
                if( EURGBP < 0 ){
                    size = qty*EURGBP;
                    enterLong(size);
                }
                else if( EURGBP > 0 ){
                    size = qty*EURGBP;
                    //enterShort(size);
                }
                else if( EURGBP == 0 ){
                    exitLong();
                    exitShort();
                }
                asset("EUR_USD");
                fees();
                if( EURUSD < 0 ){
                    size = qty*EURUSD;
                    enterLong(size);
                }
                else if( EURUSD > 0 ){
                    size = qty*EURUSD;
                    //enterShort(size);
                }
                else if( EURUSD == 0 ){
                    exitLong();
                    exitShort();
                }
                asset("GBP_USD");
                fees();
                if( GBPUSD < 0 ){
                    size = qty*GBPUSD;
                    enterLong(size);
                }
                else if( GBPUSD > 0 ){
                    size = qty*GBPUSD;
                    //enterShort(size);
                }
                else if( GBPUSD == 0 ){
                    exitLong();
                    exitShort();
                }




            
        // runs //
        
            r++;
            Wk = r/120;

        //

    ////


}
