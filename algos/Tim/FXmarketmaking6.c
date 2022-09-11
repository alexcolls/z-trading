

#include <nexow.h>

bool Trading = false;

void run() 
{
	set(PLOTNOW);
	StartWeek = 10000;
	BarPeriod = 1;
	StartDate = 2015;
	LookBack = 50000;
	setf(PlotMode,PL_FINE+PL_DIFF);
	Spread = Commission = RollLong = RollShort = Interest = 0;
	Hedge = 2;
    MonteCarlo = 0;

	PlotHeight1 = 600;
	PlotHeight2 = 80;
	
	assetList("FXG3_SuperNova");
	asset("EUR_GBP");

	Capital = 100000;
	
	//plot("Spread",marketVal(),NEW+BARS,BLUE);


    // Indicators //

        // Trading Session //

        double Run = 0;
        static int WKstop = 0;
        if( !WKstop ){
            if( ( dow(0) == 1 && hour(0) >= 7 ) || ( dow(0) > 1 && dow(0) < 4 ) )
                Run = 1;
            else if( dow(0) == 4 || ( dow(0) == 5 && hour(0) < 12 ) )
                Run = 0.5;
        }
        plot("Run",Run,NEW+BARS,DARKGREEN);

        // Global Variables //

        static double WKopen;
        static double WKmax, WKmin, Max, Min;
        static double ZZhi, ZZlo, ZZmax, ZZmin;
        static int WeeklyDir = 0;
        static int ZZdir = 1, ZZlen = 0;
        static int DailyDir = 0;
        static double WKmaxs[4], WKmins[4];
        static double WKupb, WKlob, WKmib, WKvol;

        // Start Week //

        if( dow(0) == 1 && hour(0) == 0 && minute(0) == 0 ){
            int i = 0, j = 3; 
            for( i = 0; i < j; i++ ){
                WKmaxs[j - i] = WKmaxs[j - i - 1];
                WKmins[j - i] = WKmins[j - i - 1];
            }
            WKmaxs[0] = WKmax;
            WKmins[0] = WKmin;
            WKupb = SMA(WKmaxs,j);
            WKlob = SMA(WKmins,j);
            WKmib = (WKupb+WKlob)/2;
            WKvol = ( WKupb - WKlob );
            WKopen = priceOpen(0);
            WKmax = Max = ZZhi = ZZmax = priceHigh(0);
            WKmin = Min = ZZlo = ZZmin = priceLow(0);
            if( priceClose(0) > priceOpen(0) )
                ZZdir = 1;
            else
                ZZdir = -1;
            ZZlen = 0;
            WKstop = false;
            DailyDir = 0;
        }
        WKmax = max(WKmax,priceHigh(0));
        WKmin = min(WKmin,priceLow(0));
        double WKmid = (WKmax+WKmin)/2;

        plot("Wkopen",WKopen,MAIN+DOT,BLACK);
        plot("WKmax",WKmax,MAIN,RED);
        plot("WKmin",WKmin,MAIN,RED);
        plot("WKmid",WKmid,MAIN,RED+TRANSP);
        plot("WKupb",WKupb,MAIN,PURPLE);
        plot("WKlob",WKlob,MAIN,PURPLE);
        plot("WKmib",WKmib,MAIN,PURPLE+TRANSP);
        plot("WKvol",WKvol,NEW+LINE,BLACK);
        plot("WKcurr",WKmax-WKmin,LINE,RED);

        // Daily Direction //
        
        if( dow(0) > 1 && hour(0) == 0 && minute(0) == 0 ){
            if( priceOpen(1440) < priceClose(0) )
                DailyDir += 1;
            else if( priceOpen(1440) > priceClose(0) )
                DailyDir -= 1;
        }
        plot("DailyDir",DailyDir,NEW+BARS,BLACK);
        plot("DailyDir2",2,LINE,BLACK);
        plot("DailyDir-2",-2,LINE,BLACK);

        // Weekly Direction //

        if( priceClose(0) > WKmib )
            WeeklyDir = 1;
        else if
            ( priceClose(0) < WKmib )
            WeeklyDir = -1;
      
        // ATR Volatility //
    
        const int n = 7200;
        double atr = ATR(n)*3;
        double tr = ATR(3);
        //plot("ATR",atr,NEW+LINE,BLACK);
        //plot("TR",tr,LINE,RED);

        // Zig Zag //

        const double atrN = 3;
        static double ZZhi2, ZZlo2;
        if( ZZdir == 1 ){
            ZZmax = max(ZZmax,priceHigh(0));
            plot("ZZmax",ZZmax,MAIN+LINE,GREEN+TRANSP);
            ZZlen++;
            if( ZZlen >= 60 && priceClose(0) < (ZZmax-atr*atrN) ){
                ZZhi2 = ZZhi;
                ZZhi = ZZmax;
                ZZmax = priceClose(0);
                plot("ZZhi",ZZhi,MAIN+DOT,BLUE);
                ZZdir = -1;
                ZZlen = 0;
            }
        }
        else if( ZZdir == -1 ){
            ZZmin = min(ZZmin,priceLow(0));
            plot("ZZmin",ZZmin,MAIN+LINE,GREEN+TRANSP);
            ZZlen++;
            if( ZZlen >= 60 && priceClose(0) > (ZZmin+atr*atrN) ){
                ZZlo2 = ZZlo;
                ZZlo = ZZmin;
                ZZmin = priceClose(0);
                plot("ZZlo",ZZlo,MAIN+DOT,BLUE);
                ZZdir = 1;
                ZZlen = 0;
            }
        }
        Max = max(ZZhi,ZZmax);
        Min = min(ZZlo,ZZmin);
        double ZZmid = (Max+Min)/2;
        plot("ZZmid",ZZmid,MAIN+LINE,BLUE+TRANSP);

        // ZigZag Diretion //

        int ZZlong = 0, ZZshort = 0;
        if( ZZlo > ZZlo2 && priceClose(0) > ZZlo )
            ZZlong = 1;
        if( ZZhi < ZZhi2 && priceClose(0) < ZZhi )
            ZZshort = -1;
        //plot("ZZlong",ZZlong,NEW+BARS,GREEN+TRANSP);
        //plot("ZZshort",ZZshort,BARS,RED+TRANSP);

        // Weekly Oscilator //

        const double maxOsc = 0.5;
        const double minOsc = -0.5;

        double Osc = ( ( ZZmid - WKmax ) + ( ZZmid - WKmin ) ) / ( WKmax - WKmin );
        plot("Osc",Osc,NEW+LINE,BLUE);
        plot("Osc0",0,LINE,BLACK);
        plot("Osc+",maxOsc,LINE,BLACK);
        plot("Osc-",minOsc,LINE,BLACK);
    
    // Strategy //

    const int TrendSize = 10000;
    const int ReversionSize = 0;
    const int RangeSize = 0;

    algo("Trend");
    algo("Reversion");
    algo("Range");

    static int TrendDir = 0;
    static int exitTrend = 0;

    if( Run == 1 && TrendSize > 0 ){
        
        algo("Trend");
        
        // Entry //

        if( WeeklyDir == 1 && priceClose(0) < ZZmid && priceLow(0) > ZZmin ){
            enterLong(TrendSize,-priceLow(0),ZZlo,ZZhi);
            TrendDir = 1;
        }
        else if( WeeklyDir == -1 && priceClose(0) > ZZmid && priceHigh(0) < ZZmax ){
            enterShort(TrendSize,-priceHigh(0),ZZhi,ZZlo);
            TrendDir = -1;
        }
        
        // Exit //

        if( TrendDir == 1 && priceHigh(0) == WKmax )
            exitTrend = 1;
        else if( TrendDir == -1 && priceLow(0) == WKmin )
            exitTrend = -1;
        
        if( exitTrend == 1 && priceLow(0) < ZZmid ){
            exitLong();
            TrendDir = 0;
            exitTrend = 0;
        }
        else if( exitTrend == -1 && priceHigh(0) > ZZmid ){
            exitShort();
            TrendDir = 0;
            exitTrend = 0;
        }
    
    }

    if( Run != 1 && TrendDir != 0 ){

        algo("Trend");

        if( TrendDir == 1 && priceHigh(0) == WKmax )
            exitLong();
        else if( TrendDir == -1 && priceLow(0) == WKmin )
            exitShort();

    }

    if( Run == 0 ){
        algo("Trend");
        exitLong();
        exitShort();
    }

}

//     double DD = FloatingDD();

	

// 	// const double MaxLev = 5;

//     // algo("Trend");
//     // double TrendVwap;
//     // int i = 0;
//     // for( current_trades ){
//     //     i++;
//     //     TrendVwap += TradePriceOpen;
//     // }
//     // if( i > 0 )
//     //     TrendVwap = TrendVwap/(double)i;
//     // else
//     //     TrendVwap = WKopen;
//     // plot("TrendVwap",TrendVwap,MAIN+DOT,BLACK);
//     // double TrendLev = 0;
//     // if( i > 0 )
//     //     TrendLev = ( TrendSize * (double)i ) / Balance;
//     // plot("TrendLev",TrendLev,NEW+LINE,BLACK);
//     // plot("Trend0",0,LINE,BLACK);
//     // plot("MaxLev",MaxLev,LINE,RED);

//     // // if( TrendLev >= MaxLev && DD > 0 ){
//     // //     if( priceHigh(0) == WKmax )
//     // //         exitLong();
//     // //     else if( priceLow(0) == WKmin )
//     // //         exitShort();
//     // // }

//     // static double TrendPrice;
//     // static double TrendDir;

//     // if( Run == 1 ){
//     //     if( WeeklyDir != 0 && TrendSize > 0 ){
//     //         algo("Trend");
//     //         if( WeeklyDir == 1 && priceClose(0) < ZZmid ){
                
                
//     //         }
//     //         else if( WeeklyDir == -1 && priceClose(0) > ZZmid  ){
//     //             enterShort(TrendSize,-priceClose(0),WKopen);
//     //             TrendDir = -1;
//     //         }
//     //     }
//     //     else if( WeeklyDir == 0 && RangeSize > 0 ){
//     //         algo("Range");
//     //         if( Osc > -0.5 && priceClose(0) > WKopen ){
//     //             enterShort(RangeSize,-priceHigh(0),WKmax);
//     //         }
//     //         else if( Osc < 0.5 && priceClose(0) < WKopen ){
//     //             enterLong(RangeSize,-priceLow(0),WKmin);
//     //         }
//     //     }
//     // }

    

//     if( Run == 0 ){
//         algo("Trend");
//         exitLong();
//         exitShort();
//     }

//     // Risk Management //

//     const double HS = -50;
    

//     // if( DD <= HS ){
//     //     algo("Trend");
//     //     exitLong();
//     //     exitShort();
//     //     algo("Range");
//     //     exitLong();
//     //     exitShort();
//     //     WKstop = true;
//     // }
   



//     // Accounting //
   

//     plot("DD",DD,NEW+BARS,BLUE);
//     plot("DD0",0,LINE,BLACK);
//     plot("HS",HS,LINE,BLACK);

//     double Longs = (WinValLong-LossValLong)/Balance;
//     double Shorts = (WinValShort-LossValShort)/Balance;
//     //plot("Longs",Longs,NEW+BARS,DARKGREEN+TRANSP);
//     //plot("Shorts",Shorts,BARS,RED+TRANSP);

// }
