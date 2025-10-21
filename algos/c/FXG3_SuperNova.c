


/*---------------------------------------------------------------*/
/*|||||||||||||||| Nexow - FX_G3_SUPERNOVA.v1.1. ||||||||||||||||*/
/*---------------------------------------------------------------*/


#include <nexow.h>
#define ASSETS 3
#define WEEKS 4
#define ALGOS 30


//// Predictive Model ////

void ParabolicReggression( double EURGBP, double EURUSD, double GBPUSD )
{
    double* in0 = series( EURGBP );
    double* in1 = series( EURUSD );
    double* in2 = series( GBPUSD );

    const int PRlen     = 360;
    const int PRorder   = 2;
    const int PRweigth  = 1;
    
    asset("EUR_GBP");
    double EURGBP_PR0 = polyfit( 0, in0, PRlen, PRorder, PRweigth );
    plot( "EURGBP_PR0",EURGBP_PR0,NEW,GREEN );
    double EURGBP_exp = polynom( 0,-1 ) + polynom( 0,-2 ) + polynom( 0,-3 ); 
    double EURGBP_exp = EURGBP + EURGBP_exp;
    plot( "EURGBP_exp",EURGBP_exp,MAIN,BLUE );

    asset("EUR_USD");
    double EURUSD_PR1 = polyfit( 0, in1, PRlen, PRorder, PRweigth );
    plot( "EURUSD_PR1",EURUSD_PR1,NEW,GREEN );
    double EURUSD_exp = polynom( 0,-1 ) + polynom( 0,-2 ) + polynom( 0,-3 );
    double EURUSD_exp = EURUSD + EURUSD_exp;
    plot( "EURUSD_exp",EURUSD_exp,MAIN,BLUE ); 

    asset("GBP_USD");
    double GBPUSD_PR2 = polyfit( 0, in2, PRlen, PRorder, PRweigth );
    plot( "GBPUSD_PR2",GBPUSD_PR2,NEW,GREEN );
    double GBPUSD_exp = polynom( 0,-1 ) + polynom( 0,-2 ) + polynom( 0,-3 ); 
    double GBPUSD_exp = GBPUSD + GBPUSD_exp;
    plot( "GBPUSD_exp",GBPUSD_exp,MAIN,BLUE ); 
    
	
}


void run() 
{	


    //// Engine ////


        // Params //


            BarPeriod = 60;
            LookBack = 240;
            Hedge = 1; // No NFA compliant. Hedging across algos.
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
                
                static int EURGBPpos, EURUSDpos, GBPUSDpos;

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

                EUR = GBP = USD = 0;

                asset("EUR_GBP");
                if( WKop[0] > MNmax[0] )
                {
                    EUR++;
                    GBP--;
                }
                else if( WKop[0] < MNmin[0] )
                {
                    EUR--;
                    GBP++;
                }
                
                asset("EUR_USD");
                if( WKop[1] > MNmax[1] ){
                    EUR++;
                    USD--;
                }
                else if( WKop[1] < MNmin[1] )
                {
                    EUR--;
                    USD++;
                }
                
                asset("GBP_USD");
                    if( WKop[2] > MNmax[2] )
                    {
                        GBP++;
                        USD--;
                    }
                    else if( WKop[2] < MNmin[2] )
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
                    }
                }   


            // Predictive Model //

                //ParabolicReggression( EURGBP, EURUSD, GBPUSD );




        // Trading Mechanics //

            asset("EUR_GBP");
            if( EURGBPpos == 0 ){
                if( EURGBP > 1 ){
                    enterLong();
                    EURGBPpos = 1;
                }
                else if( EURGBP < -1 ){
                    enterShort();
                    EURGBPpos = -1;
                }
            }
            asset("EUR_USD");
            if( EURUSDpos == 0 ){
                if( EURUSD > 1 ){
                    enterLong();
                    EURUSDpos = 1;
                }
                else if( EURUSD < -1 ){
                    enterShort();
                    EURUSDpos = -1;
                }
            }
            asset("GBP_USD");
            if( GBPUSDpos == 0 ){
                if( GBPUSD > 1 ){
                    enterLong();
                    GBPUSDpos = 1;
                }
                else if( GBPUSD < -1 ){
                    enterShort();
                    GBPUSDpos = -1;
                }
            }
            if( dow(0) == 5 && hour(0) == 12 )
            {
                while( asset( loop(Assets) ) )
                {
                    exitLong();
                    exitShort();
                }
            }

            if( 0 )
            {
                if( Wk > WEEKS )
                {
                    const int size = 100000;
                    double EURGBP_size, EURUSD_size, GBPUSD_size;
                    if( GO )
                    {
                        int k = 0;
                        while( asset( loop(Assets) ) )
                        {
                            fees();

                            int status = EURGBP+EURUSD+GBPUSD;
                            plot( "status",status,NEW+BARS,BLACK );
                            plot("zero",0,LINE,BLACK);

                            if( status == 0 )
                            {
                                double SL = WKmid[k];
                                if( strstr( "EUR_GBP",Symbol ) )
                                {
                                    if( priceHigh(0) == WKmax[k] )
                                    {
                                        algo( "EURGBP_X0_L" );
                                        enterShort( size,-priceClose(0),SL );
                                    }
                                    if( priceLow(0) == WKmin[k] )
                                    {
                                        algo( "EURGBP_X0_S" );
                                        enterLong( size,-priceClose(0),SL );
                                    }
                                    if( priceClose(0) > ZZmid[k] )
                                    {
                                        algo( "EURGBP_X0_L" );
                                        exitLong();
                                    }
                                    if( priceClose(0) < ZZmid[k] )
                                    {
                                        algo( "EURGBP_X0_S" );
                                        exitShort();
                                    }
                                }
                                else if( strstr( "EUR_USD",Symbol ) )
                                {
                                    if( priceHigh(0) == WKmax[k] )
                                    {
                                        algo( "EURUSD_X0_L" );
                                        enterShort( size,-priceClose(0),SL );
                                    }
                                    if( priceLow(0) == WKmin[k] )
                                    {
                                        algo( "EURUSD_X0_S" );
                                        enterLong( size,-priceClose(0),SL );
                                    }
                                    if( priceClose(0) > ZZmid[k] )
                                    {
                                        algo( "EURUSD_X0_L" );
                                        exitLong();
                                    }
                                    if( priceClose(0) < ZZmid[k] )
                                    {
                                        algo( "EURUSD_X0_S" );
                                        exitShort();
                                    }
                                }
                                else if( strstr( "GBP_USD",Symbol ) )
                                {
                                    if( priceHigh(0) == WKmax[k] )
                                    {
                                        algo( "GBPUSD_X0_L" );
                                        enterShort( size,-priceClose(0),SL );
                                    }
                                    if( priceLow(0) == WKmin[k] )
                                    {
                                        algo( "GBPUSD_X0_S" );
                                        enterLong( size,-priceClose(0),SL );
                                    }
                                    if( priceClose(0) > ZZmid[k] )
                                    {
                                        algo( "GBPUSD_X0_L" );
                                        exitLong();
                                    }
                                    if( priceClose(0) < ZZmid[k] )
                                    {
                                        algo( "GBPUSD_X0_S" );
                                        exitShort();
                                    }
                                }
                            }

                            k++;

                        }
                    }
                }
            }


            // runs //
            
                r++;
                Wk = r/120;

            //
        

        //


    ////


}
