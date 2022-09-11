


/*---------------------------------------------------------------*/
/*|||||||||||||||| Nexow - FX_G3_SUPERNOVA.v1.1. ||||||||||||||||*/
/*---------------------------------------------------------------*/


#include <nexow.h>

#define ASSETS 124
#define WEEKS 4

string Status = "Test";

void run() 
{	

    //// Engine ////


        // Params //

            assetList( "FX_G8_USD" );

            BarPeriod = 60;
            LookBack = 500;
            //Hedge = 1; // No NFA compliant. Hedging across algos.
            StartDate = 2010;
            StartWeek = 10000; // No Sundays.
            MonteCarlo = 0;

        // Charting //

            set(PLOTNOW); // |LOGFILE
            setf(PlotMode,PL_FINE+PL_DIFF);
            PlotHeight1 = 600;
            PlotHeight2 = 100;

            double hardstop = 20;
            Margin = 1000;
            
            if( strstr(Status,"Test") )
            {
                Capital = 100000;
                ColorUp = ColorDn = ColorWin = ColorLoss = ColorEquity = ColorDD = 0;
               
                static int Y = year(), M = month();
                static double iY, iM; if( is(FIRSTRUN) ) iY = iM = Equity;
                double BA  = ( Balance / Capital - 1 ) * 100;
                static double BAx; if( BA > BAx ) BAx = BA;
                static double iBA, BAy2, BAm2;
                double EQ  = ( Equity  / Capital - 1 ) * 100;
                static double EQx = EQ; if( EQ > EQx ) EQx = EQ;
                static double EQ2y = 0, EQ2m = 0, EQy2 = 0, EQm2 = 0; 
                double EQy = ( EQ - EQ2y ); double EQm = ( EQ - EQ2m );
                if( year()  != Y ) { EQy2 = ( EQ - iBA ); iY = EQ; EQ2y = EQ; EQy2 = EQy; EQy = 0; Y = year(); }
                if( month() != M ) { EQm2 = ( EQ - iBA ); iM = EQ; EQ2m = EQ; EQm2 = EQm; EQm = 0; M = month(); }
                double HS =  ( EQx - hardstop );
                double DD  = ( EQ - BAx ); if( DD > 0 ) DD = 0;
                double FG  = ( EQ - BA );  if( FG > 0 ) FG = 0;
                double LV = 0;
                for( open_trades )
                    LV += ( TradeLots * MarginCost * Leverage ) / Equity;
                                
                asset(AssetBox);
                plot( "Balance",BA,MAIN+LINE,GREY ); plot( "Equity",EQ,MAIN+LINE,0x741424 );
                plot( "HardStop",HS,MAIN+LINE,BLACK+TRANSP ); plot( "HS_",HS,MAIN+BARS,GREY+TRANSP );
                plot( "Drawdown",DD,MAIN+BARS,0x741424+TRANSP ); plot( "DD_",DD,LINE,0x741424+TRANSP );
                plot( "Zero",0,MAIN+LINE,GREY );
                plot( "Floating",FG,NEW+MAIN+BARS,0x741424 ); plot( "FG_",FG,LINE,0x741424+TRANSP );
                plot( "Yearly",0,NEW+LINE,GREY );
                if( is(FIRSTRUN) ) { plot( "EQyear+",EQy,BARS,DARKGREEN+TRANSP ); plot( "EQyear-",EQy,BARS,RED+TRANSP ); }
                if( EQy > 0 ) plot( "EQyear+",EQy,BARS,DARKGREEN+TRANSP ); else plot( "EQyear-",EQy,BARS,RED+TRANSP );
                plot( "Monthly",0,NEW+LINE,GREY );
                if( is(FIRSTRUN) ) { plot( "EQmonth+",EQm,BARS,DARKGREEN+TRANSP ); plot( "EQmonth-",EQm,BARS,RED+TRANSP ); }
                if( EQm > 0 ) plot( "EQmonth+",EQm,BARS,DARKGREEN+TRANSP ); else plot( "EQmonth-",EQm,BARS,RED+TRANSP );
                plot( "Leverage",LV,NEW+BARS,GREY );

            }
    

        //



    //// FX_G3_SUPERNOVA ////


        // Instruments //

            
            //assetList( "OandaEuropeFX28" );
            
            //assetList( "OandaEuropeFX45" );

        // Algos //

        //

            //RM();



        // Global Variables //

            // init //

                static int      r = 0;
                static double*  quotes[ASSETS];
                static double   Avg[ASSETS];
                const  int      Avgi = 120;
                static double   StD[ASSETS];
                const  int      StDi = 120;
                static double   Z[ASSETS];
                static double   Zs[ASSETS][1000];
                const  int      Zi = 20;
                static double   Zz[ASSETS];
                      

            // account //

                


        // Trading Session //


        // Strategy //

            // Delete Noise //
            
                int k = 0;
                while( asset( loop(Assets) ) )
                {
                    fees();
                    quotes[k] = series( priceClose(), Avgi+StDi );
                    Avg[k] = ZMA( quotes[k], Avgi );
                    StD[k] = StdDev( quotes[k], StDi );
                    Z[k] = ( ( priceClose()-Avg[k] ) /StD[k] );
                    
                    int i; const int j = Zi; 
                    for( i = 1; i < j; i++ )
                    {
                        Zs[k][j - i] = Zs[k][j - i - 1];
                        Zs[k][j - i] = Zs[k][j - i - 1];
                    }
                    Zs[k][0] = Z[k];
                    if( r > Zi )
                    {
                        if( ( Zs[k][0] >  Zs[k][1] && Zs[k][1] > Zs[k][2] ) &&
                            ( Zs[k][2] <  Zs[k][3] && Zs[k][3] < Zs[k][4] ) )
                                enterShort();
                        else 
                        if ( ( Zs[k][0] <  Zs[k][1] && Zs[k][1] < Zs[k][2] ) &&
                                ( Zs[k][2] >  Zs[k][3] && Zs[k][3] > Zs[k][4] ) ) 
                                    enterLong();                        
                    }
                    
                    k++;

                    //Spread = 0.00001;
                    //plot( "Spread",marketVal(0),NEW+BARS,BLUE );
                    //plot( "Realsp",Spread,LINE,RED );
                    
                    // if( PLOTNOW )
                    // {
                    //     char plt1[10]; plt1 = strcat( plt1,"Zscore_" );
                    //     strcat( plt1,Symbol );
                    //     plot( plt1,Z[k],NEW+LINE,RED );
                    //     char plt2[10]; plt2 = strcat( plt2,"Zzlag_" );
                    //     strcat( plt2,Symbol );                    
                    //     plot( plt2,Zz[k],LINE,BLACK );
                    // }

                    //plot( "DD",DD,NEW+BARS,RED );
                    //plot( "Zero",0,LINE,BLACK );


                }

            //
        
            r++;

        //

        //setAccountPlot("SPX500_USD",1);

    ////

}
