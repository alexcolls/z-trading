

#include <nexow.h>

bool Trading = false;

void run() 
{
	set(PLOTNOW);
	StartWeek = 10000;
	BarPeriod = 1;
	StartDate = 2018;
	LookBack = 20000;
	setf(PlotMode,PL_FINE+PL_DIFF);
	Spread = Commission = RollLong = RollShort = Interest = 0;
	Hedge = 2;
    MonteCarlo = 0;

	PlotHeight1 = 600;
	PlotHeight2 = 80;
	
	assetList("OandaEuropeIndex");
	asset("EUR_USD");

	Capital = 100000;
	
	//plot("Spread",marketVal(),NEW+BARS,BLUE);


    // Indicators //

    static int WKstop = 0;
    double Run = 0;
    if( !WKstop ){
        if( ( dow(0) < 5 ) || ( dow(0) == 5 && hour(0) < 12 ) )
            Run = 0.5;
        if( Run > 0 && hour(0) >= 7 && hour(0) < 13 )
            Run = 1;
    }
    plot("Run",Run,NEW+BARS,DARKGREEN);

    static double WKopen;
	static double MaxWK, MinWK, Max, Min;
    static double ZZhi, ZZlo, ZZmax, ZZmin;
    static int ZZdir = 1, ZZlen = 0;
    static int Pow = 0;
    
	if( dow(0) == 1 && hour(0) == 0 && minute(0) == 0 ){
        WKopen = priceOpen(0);
		MaxWK = Max = ZZhi = ZZmax = priceHigh(0);
		MinWK = Min = ZZlo = ZZmin = priceLow(0);
        if( priceClose(0) > priceOpen(0) )
            ZZdir = 1;
        else
            ZZdir = -1;
        ZZlen = 0;
        WKstop = false;
	}
    plot("Wkopen",WKopen,MAIN+DOT,BLACK);
    MaxWK = max(MaxWK,priceHigh(0));
	MinWK = min(MinWK,priceLow(0));
	double MidWK = (MaxWK+MinWK)/2;
    plot("MaxWK",MaxWK,MAIN,RED);
	plot("MinWK",MinWK,MAIN,RED);
	plot("MidWK",MidWK,MAIN,RED+TRANSP);
    
    const int n = 7200;
    double atr = ATR(n)*3;
    double tr = ATR(3);
    plot("ATR",atr,NEW+LINE,BLACK);
    plot("TR",tr,LINE,RED);

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
    //plot("ZZdir",ZZdir,NEW+BARS,RED);
    //plot("ZZ+",1,LINE,BLACK);
    //plot("ZZ-",-1,LINE,BLACK);
    //plot("ZZ0",0,LINE,BLACK);
    Max = max(ZZhi,ZZmax);
    Min = min(ZZlo,ZZmin);
    double ZZmid = (Max+Min)/2;
    plot("ZZmid",ZZmid,MAIN+LINE,BLUE+TRANSP);

    double Osc = ( ( priceClose(0) - MaxWK ) + ( priceClose(0) - MinWK ) ) / ( MaxWK - MinWK );
    plot("Osc",Osc,NEW+LINE,BLUE);
    plot("Osc0",0,LINE,BLACK);
    plot("Osc+",0.5,LINE,BLACK);
    plot("Osc-",-0.5,LINE,BLACK);

    int Dir = 0;
    if( ZZhi > ZZhi2 && MidWK > WKopen && ZZmid > MidWK )
        Dir = 1;
    else if( ZZlo < ZZlo2 && MidWK < WKopen && ZZmid < MidWK )
        Dir = -1;
    plot("Dir",Dir,NEW+BARS,BLACK);
    plot("Zero",0,LINE,BLACK);

    // Strategy //

    double DD = FloatingDD();

	const int TrendSize = 1000;
    const int RangeSize = 0;
	const double MaxLev = 5;

    algo("Trend");
    double TrendVwap;
    int i = 0;
    for( current_trades ){
        i++;
        TrendVwap += TradePriceOpen;
    }
    if( i > 0 )
        TrendVwap = TrendVwap/(double)i;
    else
        TrendVwap = WKopen;
    plot("TrendVwap",TrendVwap,MAIN+DOT,BLACK);
    double TrendLev = 0;
    if( i > 0 )
        TrendLev = ( TrendSize * (double)i ) / Balance;
    plot("TrendLev",TrendLev,NEW+LINE,BLACK);
    plot("Trend0",0,LINE,BLACK);
    plot("MaxLev",MaxLev,LINE,RED);

    if( TrendLev >= MaxLev && DD > 0 ){
        if( priceHigh(0) == MaxWK )
            exitLong();
        else if( priceLow(0) == MinWK )
            exitShort();
    }

    static double TrendPrice;
    static double TrendDir;

    if( Run > 0 ){
        if( Dir != 0 && TrendSize > 0 ){
            algo("Trend");
            if( Dir == 1 && priceClose(0) < ZZmid ){
                enterLong(TrendSize,-priceClose(0),ZZlo,ZZhi);
                TrendDir = 1;
            }
            else if( Dir == -1 && priceClose(0) > ZZmid  ){
                enterShort(TrendSize,-priceClose(0),ZZhi,ZZlo);
                TrendDir = -1;
            }
        }
        else if( Dir == 0 && RangeSize > 0 ){
            algo("Range");
            if( Osc > -0.5 && priceClose(0) > WKopen ){
                enterShort(RangeSize,-priceHigh(0),MaxWK);
            }
            else if( Osc < 0.5 && priceClose(0) < WKopen ){
                enterLong(RangeSize,-priceLow(0),MinWK);
            }
        }
    }

    static int ExitTrend = 0;
    if( TrendDir == 1 && priceHigh(0) == MaxWK )
        ExitTrend = 1;
    else if( TrendDir == -1 && priceLow(0) == MinWK )
        ExitTrend = -1;
    
    if( ExitTrend == 1 && priceClose(0) < ZZmid ){
        algo("Trend");
        exitLong();
        TrendDir = 0;
        ExitTrend = 0;
    }
    else if( ExitTrend == -1 && priceClose(0) > ZZmid ){
        algo("Trend");
        exitShort();
        TrendDir = 0;
        ExitTrend = 0;
    }
    if( TrendDir == 1 && ZZlo < ZZlo2 && priceHigh(0) > ZZmid ){
        algo("Trend");
        exitLong();
        TrendDir = 0;
        ExitTrend = 0;
    }
    else if( TrendDir == -1 && ZZhi > ZZhi2 && priceLow(0) < ZZmid ){
        algo("Trend");
        exitShort();
        TrendDir = 0;
        ExitTrend = 0;
    }


    //plot("TrendPrice",TrendPrice,MAIN+LINE,ORANGE);

    // if( ( TrendVwap < TrendPrice && priceClose(0) <= ZZmin ) || ( Osc > -0.5 && priceLow(0) == MinWK ) ){
    //     algo("Trend");
    //     exitShort();
    // }
    // else if( ( TrendVwap > TrendPrice && priceClose(0) >= ZZmax ) || ( Osc < 0.5 && priceHigh(0) == MaxWK ) ){
    //     algo("Trend");
    //     exitLong();
    // }

    
    // if( Dir != 0 ){
    //     algo("Range");
    //     exitLong();
    //     exitShort();
    //     algo("Trend");
    //     if( tr > atr){
    //         if( priceHigh(0) == MaxWK && priceClose(0) > ZZmid )
    //             exitLong();
    //         else if( priceLow(0) == MinWK && priceClose(0) < ZZmid )
    //             exitShort();
    //     }
    // }
    // else if( Dir == 0 ){
    //     algo("Range");
    //     if( priceClose(0) > ZZmid )
    //         exitLong();
    //     else if( priceClose(0) < ZZmid )
    //     exitShort();
    // }

    // if( Run == 0 ){
    //     algo("Trend");
    //     exitLong();
    //     exitShort();
    //     algo("Range");
    //     exitLong();
    //     exitShort();
    // }

    // Risk Management //

    const double HS = -50;
    

    // if( DD <= HS ){
    //     algo("Trend");
    //     exitLong();
    //     exitShort();
    //     algo("Range");
    //     exitLong();
    //     exitShort();
    //     WKstop = true;
    // }
   



    // Accounting //
   

    plot("DD",DD,NEW+BARS,BLUE);
    plot("DD0",0,LINE,BLACK);
    plot("HS",HS,LINE,BLACK);

    double Longs = (WinValLong-LossValLong)/Balance;
    double Shorts = (WinValShort-LossValShort)/Balance;
    //plot("Longs",Longs,NEW+BARS,DARKGREEN+TRANSP);
    //plot("Shorts",Shorts,BARS,RED+TRANSP);

}
