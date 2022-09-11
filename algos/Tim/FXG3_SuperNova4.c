


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
            LookBack = 1000;
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

                static int      r = 0;
                
                static double   WKmax[ASSETS], WKmin[ASSETS],  WKmid[ASSETS];
                static double   WKmaxs[ASSETS][WEEKS], WKmins[ASSETS][WEEKS];
                static double   WKop[ASSETS];
                
                static double   ZZhi[ASSETS],  ZZlo[ASSETS];
                static double   ZZmax[ASSETS], ZZmin[ASSETS], ZZmid[ASSETS];
                static int      ZZlen[ASSETS];
                static int      ZZdir[ASSETS];
                static int      timming[ASSETS];
                // Normalize
                static double*  quotes[ASSETS];
                static double   Avg[ASSETS];
                const  int      Avgi = 120;
                static double   StD[ASSETS];
                const  int      StDi = 120;
                static double   Z[ASSETS];
                static double   Zs[ASSETS][1000];
                const  int      Zi = 20;
                static double   Zz[ASSETS];
        
                static double   vwap[ASSETS];

                const double    MNdevs = 1;
                const double    qty = 500000;
               

            // account //

                double DD = FloatingDD();


        // Trading Session //


        // Strategy //

            // Delete Noise //
            
                int k = 0;
                while( asset( loop(Assets) ) )
                {
                    quotes[k] = series( priceClose(), Avgi+StDi );
                    Avg[k] = ZMA( quotes[k], Avgi );
                    StD[k] = StdDev( quotes[k], StDi );
                    Z[k] = ( ( priceClose()-Avg[k] ) /StD[k] );
                    fees();
                    
                    if( PLOTNOW )
                    {
                        char plt1[10]; plt1 = strcat( plt1,"Zscore_" );
                        strcat( plt1,Symbol );
                        plot( plt1,Z[k],NEW+LINE,RED );
                        char plt2[10]; plt2 = strcat( plt2,"Zzlag_" );
                        strcat( plt2,Symbol );                    
                        plot( plt2,Zz[k],LINE,BLUE );
                    }

                    int i; const int j = Zi; 
                    for( i = 1; i < j; i++ )
                    {
                        Zs[k][j - i] = Zs[k][j - i - 1];
                        Zs[k][j - i] = Zs[k][j - i - 1];
                    }
                    Zs[k][0] = Z[k];
                    if( r > Zi )
                    {
                        //Zz[k] = LowPass( Zs[k], Zi );
                        if( ( Zs[k][0] >  Zs[k][1] && Zs[k][1] > Zs[k][2] ) &&
                            ( Zs[k][2] <  Zs[k][3] && Zs[k][3] < Zs[k][4] ) )
                                enterShort(qty);
                        else if ( ( Zs[k][0] <  Zs[k][1] && Zs[k][1] < Zs[k][2] ) &&
                                ( Zs[k][2] >  Zs[k][3] && Zs[k][3] > Zs[k][4] ) ) 
                                    enterLong(qty);                        
                    }
                    
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
                                    
                    const int n = 3;
                    const int aTRx = 1;
                    double aTR = ATR(n)*aTRx;
                    
                    const int ZZminBars = 4;
                    if( ZZdir[k] == 1 )
                    {
                        ZZmax[k] = max( ZZmax[k],priceHigh(0) );
                        plot( "ZZmax",ZZmax[k],MAIN+LINE,BLUE+TRANSP );
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
                        plot("ZZmin",ZZmin[k],MAIN+LINE,BLUE+TRANSP);
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

            //
        
        //
        
        r++;

    ////

}
