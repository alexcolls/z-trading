

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
	asset("AUD_USD");

	Capital = 100000;
	double Lev = 0.01;
	int Sizes = Balance*Lev;
	double DD = FloatingDD();
	//plot("Spread",marketVal(),NEW+BARS,BLUE);


    // Indicators //

    double Run = 0;
    if( ( dow(0) > 1 && dow(0) < 5 ) || ( dow(0) == 5 && hour(0) < 12 ) )
        Run = 0.5;
    if( Run > 0 && hour(0) >= 7 && hour(0) < 13 )
        Run = 1;
    plot("Run",Run,NEW+BARS,DARKGREEN);

    static double WKopen;
	static double MaxWK, MinWK, Max, Min;
    static double ZZhi, ZZlo, ZZmax, ZZmin;
    static int ZZdir = 1, ZZlen = 0;
    
	if( dow(0) == 1 && hour(0) == 0 && minute(0) == 0 ){
        WKopen = priceOpen(0);
		MaxWK = Max = ZZhi = ZZmax = priceHigh(0);
		MinWK = Min = ZZlo = ZZmin = priceLow(0);
        if( priceClose(0) > priceOpen(0) )
            ZZdir = 1;
        else
            ZZdir = -1;
        ZZlen = 0;
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
    plot("TR",tr,LINE,BLUE);

    const double atrN = 3;
    if( ZZdir == 1 ){
        ZZmax = max(ZZmax,priceHigh(0));
        plot("ZZmax",ZZmax,MAIN+LINE,GREEN+TRANSP);
        ZZlen++;
        if( ZZlen >= 60 && priceClose(0) < (ZZmax-atr*atrN) ){
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
            ZZlo = ZZmin;
            ZZmin = priceClose(0);
            plot("ZZlo",ZZlo,MAIN+DOT,BLUE);
            ZZdir = 1;
            ZZlen = 0;
        }
    }
    plot("ZZdir",ZZdir,NEW+BARS,RED);
    plot("ZZ+",1,LINE,BLACK);
    plot("ZZ-",-1,LINE,BLACK);
    plot("ZZ0",0,LINE,BLACK);
    Max = max(ZZhi,ZZmax);
    Min = min(ZZlo,ZZmin);
    double ZZmid = (Max+Min)/2;
    plot("ZZmid",ZZmid,MAIN+LINE,BLUE+TRANSP);

    double WKtrend = 0;
    if( dow(0) > 2 || ( dow(0) == 2 && hour(0) >= 7 ) )
        WKtrend = (Max-Min)/(MaxWK-MinWK);
    //plot("WKtrend",WKtrend,NEW+BARS,ORANGE);
    //plot("MaxTrend",1,LINE,BLACK);
    //plot("MidTrend",0.5,LINE,BLACK);

    int Dir = 0;
    if(  MidWK > WKopen && ZZmid > MidWK )
        Dir = 1;
    else if(  MidWK < WKopen && ZZmid < MidWK )
        Dir = -1;
    plot("Dir",Dir,NEW+BARS,BLACK);
    plot("Zero",0,LINE,BLACK);



    // Strategy // 

    static double longs = 0;
    static double shorts = 0;


    if( Run > 0 ){
        if( priceClose(0) > WKopen && priceClose(0) > MidWK && priceClose(0) < ZZmid ){
            enterLong(Sizes,priceClose(0),MinWK);
            longs++;
        }
        else if( priceClose(0) < WKopen && priceClose(0) < MidWK && priceClose(0) > ZZmid ){
            enterShort(Sizes,priceClose(0),MaxWK);
            shorts++;
        }
    }
    if( longs > 0 && priceHigh(0) == MaxWK ){
        
    }
    if( tr > atr ){
        exitLong();
        exitShort();
    }


    // if( ZZdir < 0 ){
    //     if( longprice != 0 ){
    //         exitLong();
    //         longprice = 0;
    //     }
    //     if( Run == 1 && shortprice == 0 ){
    //         enterShort(Sizes);
    //         shortprice = priceClose(0);
    //     }
    //     else if( Run == 1 && shortprice != 0 && priceHigh(0) > shortprice ){
    //         enterShort(Sizes,-priceHigh(0));
    //         shortprice = priceHigh(0);
    //     }
    //     shortprice = priceHigh(0);
    // }
    // else if( ZZdir > 0 ){
    //     if( shortprice != 0 ){
    //         exitShort();
    //         shortprice = 0;
    //     }
    //     if( Run == 1 && longprice == 0 ){
    //         enterLong(Sizes);
    //         longprice = priceClose(0);
    //     }
    //     else if( Run == 1 && longprice != 0 && priceLow(0) < longprice ){
    //         enterLong(Sizes,-priceLow(0));
    //         longprice = priceLow(0);
    //     }
    //     longprice = priceLow(0);
    // }

    // if( Trading ){
    //     double Dir = 0;
    //     if( priceHigh(0) == MaxWK )
    //         exitLong();
    //     else if( priceLow(0) == MinWK )
    //         exitShort();
    //     if( Run == 1 ){
    //         if( Dir == 0 ){
    //             enterShort(Sizes,-priceHigh(0));
    //             enterLong(Sizes,-priceLow(0));
    //         }
    //         else if( Dir > 0 )
    //             enterLong(Sizes,-(priceOpen(0)-marketVal()));
    //         else if( Dir < 0 )
    //             enterShort(Sizes,-(priceOpen(0)+marketVal()));
    //     }
    // }
    
    // Accounting //

    double Pos = NumOpenLong - NumOpenShort;
    //plot("Pos",Pos,NEW+BARS,ORANGE);

    //plot("DD",FloatingDD(),NEW+BARS,RED);

    double Longs = (WinValLong-LossValLong)/Balance;
    double Shorts = (WinValShort-LossValShort)/Balance;
    //plot("Longs",Longs,NEW+BARS,DARKGREEN+TRANSP);
    //plot("Shorts",Shorts,BARS,RED+TRANSP);

}
