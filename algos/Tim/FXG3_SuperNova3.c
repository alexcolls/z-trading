


/*---------------------------------------------------------------*/
/*|||||||||||||||| Nexow - FX_G3_SUPERNOVA.v1.1. ||||||||||||||||*/
/*---------------------------------------------------------------*/


#include <nexow.h>
#define ASSETS 3
#define WEEKS 4


void run() 
{	


    //// Engine ////


        // Params //

            BarPeriod = 60;
            LookBack = 500;
            //Hedge = 1; // No NFA compliant. Hedging across algos.
            StartDate = 2008;
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

        //


        // Global Variables //

            // init //

                static bool     GO = false;
                static short    r = 0, Wk = 0;

                static double   MNhi[ASSETS], MNlo[ASSETS];
                static double   MNmax[ASSETS], MNmin[ASSETS];
                static double   MNv[ASSETS];
                
                static double   WKmax[ASSETS], WKmin[ASSETS],  WKmid[ASSETS];
                static double   WKmaxs[ASSETS][WEEKS], WKmins[ASSETS][WEEKS];
                static double   WKop[ASSETS];
                
                static double   ZZhi[ASSETS],  ZZlo[ASSETS];
                static double   ZZmax[ASSETS], ZZmin[ASSETS], ZZmid[ASSETS];
                static int      ZZlen[ASSETS];
                static int      ZZdir[ASSETS];
                static int      timming[ASSETS];
        
                static double   vwap[ASSETS];
                static double*  quotes[ASSETS];

                const double    MNdevs = 1;
                const double    qty = 1000;
               

            // account //

                double DD = FloatingDD();


        // Trading Session //


        // Strategy //

            // Delete Noise //
            
                int k = 0;
                while( asset( loop(Assets) ) )
                {
                    quotes[k] = series( priceClose() );
                    double Zlag = ZMA( quotes[k], 120 );
                    plot( "Zlag",Zlag,MAIN+LINE,GREEN);
                    if( dow(0) == 1 && hour(0) == 0 && minute(0) == 0 )
                    {
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
                        
                        MNv[k] = ( MNmax[k]-MNmin[k] )*2;
                        MNhi[k] = MNmax[k]+MNv[k];
                        MNlo[k] = MNmin[k]-MNv[k];

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
                        plot( "MNmax",MNmax[k],MAIN+LINE,RED );
                        plot( "MNmin",MNmin[k],MAIN+LINE,RED );
                        plot( "MNhi",MNhi[k],MAIN+LINE,BLUE );
                        plot( "MNlo",MNlo[k],MAIN+LINE,BLUE );
                        plot( "MNv",MNv[k],NEW+BARS,BLUE);
                    }
                    
                    const int n = 3;
                    const int aTRx = 3;
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

                int EUR, GBP, USD;
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
                if( ZZmid[1] > MNmax[1] ){
                    EUR++;
                    USD--;
                }
                else if( ZZmid[1] < MNmin[1] )
                {
                    EUR--;
                    USD++;
                }
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

                if( Wk > WEEKS )
                {
                    while( asset( loop(Assets) ) )
                    {
                        plot( "0",0,NEW+LINE,BLACK  );
                        plot( "EUR",EUR,LINE,ORANGE );
                        plot( "GBP",GBP,LINE,PURPLE );
                        plot( "USD",USD,LINE,YELLOW );
                    }

                    asset( "EUR_GBP" ); fees();
                    if( EUR > GBP && priceClose(0) > MNmax[0] )
                    {
                        if( ZZdir[0] == -1 && timming[0] != -1 )
                        {
                            enterLong( qty );
                        }
                    }
                    else if( EUR < GBP )
                    {
                        if( ZZdir[0] == 1 && timming[0] != 1 )
                        {
                            enterShort( qty );
                        }
                    }
                    
                    if( priceClose(0) >= MNhi[0] )
                    {
                        exitLong();
                    }
                    else if( priceClose(0) <= MNhi[0] )
                    {
                        exitShort();
                    }

                    //if( )
                    
                    asset( "EUR_USD" ); fees();
                    if( EUR > USD )
                    {
                        if( ZZdir[1] == -1 && timming[1] != -1 )
                        {
                            enterLong( qty );
                        }
                    }
                    else if( EUR < USD )
                    {
                        if( ZZdir[1] == 1 && timming[1] != 1 )
                        {
                            enterShort( qty );
                        }
                    }
                    
                    if( priceClose(0) >= MNhi[1] )
                    {
                        exitLong();
                    }
                    else if( priceClose(0) <= MNhi[1] )
                    {
                        exitShort();
                    }

                    asset( "GBP_USD" ); fees();
                    if( GBP > USD )
                    {
                        if( ZZdir[2] == -1 && timming[2] != -1 )
                        {
                            enterLong( qty );
                        }
                    }
                    else if( GBP < USD )
                    {
                        if( ZZdir[2] == 1 && timming[2] != 1 )
                        {
                            enterShort( qty );
                        }
                    }
                    
                    if( priceClose(0) >= MNhi[2] )
                    {
                        exitLong();
                    }
                    else if( priceClose(0) <= MNhi[2] )
                    {
                        exitShort();
                    }

                }

                int i;
                for( i = 0; i < 3; i++ )
                {
                    timming[i] = ZZdir[i];
                }
                


            //
            
        // runs //
        
            r++;
            Wk = r/120;

        //

    ////

}
