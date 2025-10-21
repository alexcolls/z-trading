
#include <NexowFunctions.h>

double VolOV( int Periods )
{
	double a = 1, alpha = 0.92, numer = 0, denom = 0;
    double Hi = priceClose(0);
    double Lo = priceClose(0);
    int i;
	for( i = 1; i <= Periods; i++) {
        if( priceClose(i) > Hi )
            Hi = priceClose(i);
        if( priceClose(i) < Lo )
            Lo = priceClose(i);
	}
    for( i = 1; i <= Periods; i++) {
        double SV = .627 * 19.11 * log(Hi/Lo); // 19.11 = sqrt(365.25)
		numer += a*SV;
		denom += a;
		a *= alpha;
    }
	return numer/denom;
}

double HiShadows( int Periods ){
    double Avg = 0;
    int i;
	for( i = 0; i < Periods; i++) {
        if( priceClose(i) > priceOpen(i) )
            Avg += priceHigh(i)-priceClose(i);
        else
            Avg += priceHigh(i)-priceOpen(i);
	}
    return Avg/Periods;
}
double LoShadows( int Periods ){
    double Avg = 0;
    int i;
	for( i = 0; i < Periods; i++) {
        if( priceClose(i) > priceOpen(i) )
            Avg += priceOpen(i)-priceLow(i);
        else
            Avg += priceClose(i)-priceLow(i);
	}
    return Avg/Periods;
}

double RangeInd( int Periods ){
    double Avg = 0;
    int i;
	for( i = 0; i < Periods; i++) {
        Avg += priceClose(i)-priceOpen(i);
	}
    return Avg/Periods;
}

typedef struct{
    int n;
    double Val;
} intval;

intval Vol[24];

void run(){

    set(PLOTNOW);
    assetList("FX28");
    StartDate = 2005;
    //BarZone = 8;
    BarPeriod = 60;

    Spread = Commission = RollLong = RollShort = 0;
    
    LookBack = 500;
    //Hedge = 2;

    int Len = 200;
    /*
    double Vol1 = RangeInd(Len);//HiShadows(120);
    double MA1 = EMA(series(priceClose()),Len);
    double Vol2 = (priceClose(0)-MA1)/Len;//LoShadows(120);
    //double MA2 = EMA(series(priceClose()),120);
    double Osc = Vol1-Vol2;
    double Osc2 = HiShadows(Len)-LoShadows(Len);

    static double LastVol;
    */
    /*
    double LP = LowPass(series(priceClose()),Len);
    double EM = EMA(series(priceClose()),Len);
    double DM = DEMA(series(priceClose()),Len);
    plot("LP",LP,0,BLUE);
    plot("EM",EM,0,RED);
    plot("DM",DM,0,DARKBLUE);
    
    double EUR = EURIdx8();
    double USD = 1/USDIdx8();
    double EURlp = ZMA(series(EUR),Len);
    double USDlp = ZMA(series(USD),Len);
    plot("EURlp",EURlp,1,RED+TRANSP);
    plot("EUR",EUR,0,RED);
    plot("USDlp",USDlp,1,BLUE+TRANSP);
    plot("USD",USD,0,BLUE);
    */
    static double UpLevel, DnLevel;

    static int Counter;
    double Distance = 0.005;
    //TakeProfit = Distance;
    //Stop = Distance*10;

    

    const double Multiply = 1/Distance;

    if( is(FIRSTRUN) ){
        double Level = round(Multiply*priceClose(0))/Multiply;
        if( Level > priceClose(0) ){
            UpLevel = Level;
            DnLevel = Level-Distance;
        }
        else{
            UpLevel = Level+Distance;
            DnLevel = Level;
        }
    }
    double nLevels;

    static double nLongs, LongsPrice, nShorts, ShortsPrice;
    if( priceClose(0) >= UpLevel ){
        nLevels = round((priceClose(0)-UpLevel)/Distance)+1;
        UpLevel = UpLevel+Distance*nLevels;
        DnLevel = UpLevel-Distance*2;
        if( Counter > 0 )
            Counter += nLevels;
        else
            Counter = nLevels;
        ShortsPrice = (ShortsPrice*nShorts+priceClose(0))/(nShorts+1);
        nShorts++;
        //enterShort();
    }
    else if( priceClose(0) <= DnLevel ){
        nLevels = round((DnLevel-priceClose(0))/Distance)+1;
        DnLevel = DnLevel-Distance*nLevels;
        UpLevel = DnLevel+Distance*2;
        if( Counter < 0 )
            Counter -= nLevels;
        else
            Counter = -nLevels;
        LongsPrice = (LongsPrice*nLongs+priceClose(0))/(nLongs+1);
        nLongs++;
        //enterLong();
    }

    static double LongsTarget, ShortsTarget;
    LongsTarget = LongsPrice + Distance;// + (priceClose(0)-ShortsTarget)/nLongs;
    ShortsTarget = ShortsPrice - Distance;// - (LongsTarget-priceClose(0))/nShorts;

    if( priceClose(0) >= LongsTarget ){
        nLongs = 0;
        //exitLong();
    }
    if( priceClose(0) <= ShortsTarget ){
        nShorts = 0;
        //exitShort();
    }

    double LongsTarget2 = ShortsTarget + Distance*nShorts;
    double ShortsTarget2 = LongsTarget - Distance*nLongs;

    double LP = (LongsTarget+ShortsTarget)/2;//LowPass(series(priceClose()),Len);
    double Osc = (priceClose(0)-LongsTarget)+(priceClose(0)-ShortsTarget);
    /*
    if( abs(Counter) >= 5 ){
        exitLong(); exitShort();
    }
    */


    int Hour = hour();
    double Ret = abs((priceClose(0)/priceOpen(0)-1)*100);

    Vol[Hour].n++;
    Vol[Hour].Val += Ret;

    double Volat = Vol[Hour].Val/(double)Vol[Hour].n;
    /*
    if( Hour == 15 ){
        if( priceClose(0)>priceOpen(0) )
            enterLong();
        else if( priceClose(0)<priceOpen(0) )
            enterShort();
    }
    else if( Hour == 22 ){
        exitLong(); exitShort();
    }
    */
    static double Asian, European, American;
    static double AsianOpen, EuropeanOpen, AmericanOpen;

    if( Hour == 1 ){
        AsianOpen = priceOpen(0);
        if( Asian == 1 )
            enterShort();
        else 
            enterLong();
    }
    else if( Hour == 7 ){
        Asian = (priceClose(0)/AsianOpen-1)*100;
        exitLong(); exitShort();
    }
    else if( Hour == 8 ){
        EuropeanOpen = priceOpen(0);
        if( European == 1 )
            enterShort();
        else 
            enterLong();
    }
    else if( Hour == 14 ){
        European = (priceClose(0)/EuropeanOpen-1)*100;
        exitLong(); exitShort();
    }
    else if( Hour == 15 ){
        AmericanOpen = priceOpen(0);
        if( American == 1 )
            enterShort();
        else 
            enterLong();
    }
    else if( Hour == 21 ){
        American = (priceClose(0)/AmericanOpen-1)*100;
        exitLong(); exitShort();
    }

    //printf("\nHour= %d, N= %d, Val= %f, Ret= %f",Hour,Vol[Hour].n,Vol[Hour].Val,Ret);
    if( Asian < 0 )
        Asian = -1;
    else
        Asian = 1;
    if( European < 0 )
        European = -1;
    else
        European = 1;
    if( American < 0 )
        American = -1;
    else
        American = 1;

    plot("LP",LP,0,BLUE);
    plot("UpLevel",UpLevel,0,RED+TRANSP);
    plot("DnLevel",DnLevel,0,RED+TRANSP);
    plot("LongsTarget",LongsTarget2,0,GREEN);
    plot("ShortsTarget",ShortsTarget2,0,RED);


    plot("Asian",Asian,1,RED);
    plot("European",European,1,BLUE);
    plot("American",American,1,GREEN);
    //plot("Counter",Volat,BARS+NEW,RED);
    //plot("Ret",Ret,BARS,BLUE+TRANSP);
    //plot("Zero",0,0,BLACK);


    

    

    //printf("\n%f %f %f",priceClose(0),UpLevel,DnLevel);

    







    /*
    double EURd = (EUR/EURlp-1)*100;
    double USDd = (USD/USDlp-1)*100;
    plot("EURd",EURd,1,RED);
    plot("USDd",USDd,0,BLUE);
    plot("z",0,0,BLACK);

    if( EURd > 0 && USDd > 0 ){
        if( !TradeIsOpen )
            enterLong();
    }
    else if( EURd < 0 && USDd < 0 ){
        if( !TradeIsOpen )
            enterShort();
    }
    else{
        exitLong(); exitShort();
    }
    */
    /*
    double* USD_ = series(USD,3);
    double* USDd_ = series(USDd,3);
    
    static double minUSD, minUSDd, maxUSD, maxUSDd;

    if( USD < USDlp ){
        exitShort();
        maxUSD = USD;
        maxUSDd = 0;
        if( USD < minUSD ){
            minUSD = USD;
        }
        if( USDd < minUSDd ){
            minUSDd = USDd;
        }
        if( valley(USD_) && valley(USDd_) && EUR > EURlp ){
            if( USD_[1] <= minUSD && USDd_[1] > minUSDd ){
                enterLong();
            }
        }
    }

    if( USD > USDlp ){
        exitLong();
        minUSD = USD;
        minUSDd = 0;
        if( USD > maxUSD ){
            maxUSD = USD;
        }
        if( USDd > maxUSDd ){
            maxUSDd = USDd;
        }
        if( peak(USD_) && peak(USDd_) && EUR < EURlp ){
            if( USD_[1] >= maxUSD && USDd_[1] < maxUSDd ){
                enterShort();
            }
        }
    }

    */


    /*
    double EURr = EURIdx8r();
    double USDr = USDIdx8r();

    double EURm = Sum(series(EURr),Len);
    double USDm = Sum(series(USDr),Len);

    double* rV = series(abs(priceClose(0)/priceOpen(0)-1)*100);
    double rVa = SMA(rV,Len);
    double rVd = StdDev(rV,Len)*2;

    plot("EURr",EURr,BARS+NEW,BLUE);
    plot("USDr",USDr,BARS,RED+TRANSP);
    plot("EURm",EURm,0,BLUE);
    plot("USDm",USDm,0,RED+TRANSP);

    //plot("rV",rV,BARS+NEW,BLUE);
    //plot("rVa",rVa,0,RED);
    plot("rVd+",rVd,0,GREEN);
    plot("rVd-",-rVd,0,GREEN);

    //plot("MA1",MA1,0,RED);
    //plot("MA2",MA2,0,BLUE);
    plot("Zero",0,1,BLACK);
    //plot("Vol1",Vol1,0,RED);
    //plot("Vol2",Vol2,0,BLUE);
    plot("Osc",Osc,0,BLUE);
    plot("Osc2",Osc2,0,RED);

    LastVol = Vol1;

    */

}