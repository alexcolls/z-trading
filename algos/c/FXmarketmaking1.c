

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

    static int Go = 0;
    static int Up, Dn;
    static int op,hi,lo,cl;
    static double Hi, Lo, Mi;
	static double MaxWK, MinWK, MidWK;
    
	if( dow(0) == 1 && hour(0) == 0 ){
		MaxWK = Hi = priceHigh(0);
		MinWK = Lo = priceLow(0);
		Up = Dn = 0;
        op = hi = lo = cl = 0;
        Go = 0;
	}
	MaxWK = max(MaxWK,priceHigh(0));
	MinWK = min(MinWK,priceLow(0));
	MidWK = (MaxWK+MinWK)/2;
	    
    const int len = 1440;
    double* prices = series((priceOpen()+priceHigh()+priceLow()+priceClose())/4);
	double LP = LowPass(prices,len);
	plot("LP",LP,MAIN,RED);

    if( priceOpen(1) > LP && priceClose(0) < LP )
        Lo = priceLow(0);
    else if( priceOpen(1) < LP && priceClose(0) > LP )
        Hi = priceHigh(0);
    Hi = max(Hi,priceHigh(0));
	Lo = min(MinWK,priceLow(0));
    Mi = (Hi+Lo)/2;
    
    plot("Hi",Hi,MAIN,ORANGE);
    plot("Lo",Lo,MAIN,ORANGE);
    plot("Mi",Mi,MAIN,ORANGE+TRANSP);
    plot("MaxWK",MaxWK,MAIN,RED);
	plot("MinWK",MinWK,MAIN,RED);
	plot("MidWK",MidWK,MAIN,BLUE);


    if( priceHigh(0) == MaxWK || priceLow(0) == MinWK )
        Up = Dn = op = hi = lo = cl = 0;

    if( priceOpen(0) > MidWK )
		Up++;
	else if( priceOpen(0) < MidWK )
		Dn--;
    double Osc = Up+Dn;

	
    
    
    
    
    
    
    if( priceOpen(0) > LP )
        op++;
    else if( priceOpen(0) < LP )
        op--;
    if( priceHigh(0) > LP )
        hi++;
    else if( priceHigh(0) < LP )
        hi--;
    if( priceLow(0) > LP )
        lo++;
    else if( priceLow(0) < LP )
        lo--;
    if( priceClose(0) > LP )
        cl++;
    else if( priceClose(0) < LP )
        cl--;
    
    double side = (hi+lo+op+cl);

    

    //plot("side",side,NEW+LINE,RED); plot("01",0,LINE,BLACK);

    int Dir = 0;
    if( dow(0) > 1 ){
        if( Osc < 0 && side > 0 )
            Dir = -1;
        else if( Osc > 0 && side < 0 )
            Dir = 1;
    }
    plot("Dir0",0,NEW+LINE,BLACK); plot("Dir+",1,LINE,BLACK); plot("Dir-",-1,LINE,BLACK);
    plot("Dir",Dir,BARS,BLACK);

    double atr = ATR(300)*3;
    double tr = ATR(3);
    plot("ATR",atr,NEW+LINE,BLACK);
    plot("TR",tr,LINE,BLUE);
    

    // Strategy // 

    if( Trading ){

        if( ( side < 0 && priceLow(0) < MidWK ) || ( side > 0 && priceHigh(0) > MidWK ) )
            Go = 1;
        else
            Go = 0;

        if( ( Go == 1 && DD > 0 ) || Run == 0 ){
            exitLong();
            exitShort();
            Go = 0;
        }
        plot("Go",Go,NEW+BARS,RED);

        if( priceHigh(0) == MaxWK )
            exitLong();
        else if( priceLow(0) == MinWK )
            exitShort();

        if( Run == 1 ){
            if( Dir == 0 ){
                enterShort(Sizes,-priceHigh(0));
                enterLong(Sizes,-priceLow(0));
            }
            else if( Dir > 0 )
                enterLong(Sizes,-(priceOpen(0)-marketVal()));
            else if( Dir < 0 )
                enterShort(Sizes,-(priceOpen(0)+marketVal()));
        }
    }
    
    double Longs = (WinValLong-LossValLong)/Balance;
    double Shorts = (WinValShort-LossValShort)/Balance;
    plot("Longs",Longs,NEW+BARS,DARKGREEN+TRANSP);
    plot("Shorts",Shorts,BARS,RED+TRANSP);

    double Pos = NumOpenLong - NumOpenShort;
    plot("Pos",Pos,NEW+BARS,ORANGE);

	plot("DD",FloatingDD(),NEW+BARS,RED);

}
