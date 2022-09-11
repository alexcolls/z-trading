
#include <NexowFunctions.h>

void run(){

    set(PLOTNOW);
    PlotHeight1 = 600;
    PlotHeight2 = 200;
    //ColorUp = ColorDn = ColorWin = ColorLoss = ColorEquity = ColorDD = 0;

    assetList("AssetsFix45");
    StartDate = 2005;
    BarPeriod = 60;
    Spread = Commission = Slippage = RollLong = RollShort = 0;

    double* prices = series(price());
    double* highs = series(priceHigh());
    double* lows = series(priceLow());

    double* Vol = series(marketVol());
    double* LP = series(LowPass(prices,200));
    

    double* MktPow1 = series(((priceHigh(0)-priceOpen(0))-(priceOpen(0)-priceLow(0)))*marketVol());
    double* MktPow2 = series(((priceHigh(0)-priceClose(0))-(priceClose(0)-priceLow(0)))*marketVol());
    
    const int Per = 200;
    const double PowTH = 0.03;

    double Pow1 = SMA(MktPow1,Per);
    double Pow2 = SMA(MktPow2,Per);
    
    plot("LP",LP,0,DARKGREEN);
    plot("LP+1",LP[0]+Pow1,0,RED);
    plot("LP+2",LP[0]+Pow2,0,RED);
    plot("LP-1",LP[0]-Pow1,0,BLUE);
    plot("LP-2",LP[0]-Pow2,0,BLUE);

    if( Pow1 <= PowTH && Pow1 >= -PowTH && Pow2 <= PowTH && Pow2 >= -PowTH ){
        if( !TradeIsLong && price(0) > LP[0] )
            enterLong();
        else if( !TradeIsShort && price(0) < LP[0] )
            enterShort();
    }
    else{
        exitLong();
        exitShort();
    }

    plot("Pow1",Pow1,1,RED);
    plot("Pow2",Pow2,0,BLUE);
    plot("Z1",0,0,BLACK);
    plot("Z2",PowTH,0,BLACK);
    plot("Z3",-PowTH,0,BLACK);
    

    double StDev = StdDev(Vol,200)*3;
    double StDev1 = StdDev(Vol,200);


    static double axis, lastvol;
    static int nt = 2;
    static double slope;

    int PosLen, NegLen;

    const int LenParam = 20;
    
    PosLen = NegLen = LenParam;

    int i;
    for( i = 0; i < LenParam; i++ ){
        if( priceOpen(i) < priceClose(i) )
            PosLen--;
        else if( priceOpen(i) > priceClose(i) )
            NegLen--;
    }

    double PosMA = EMA(prices,PosLen);
    double NegMA = EMA(prices,NegLen);

    if( peak(LP) || valley(LP) ){
        axis = LP[1];
        nt = 2;
        lastvol = Vol[0];
    }
    else nt++;

    double AvgVol = EMA(Vol,nt);

    double* LPh = series(LowPass(highs,nt));
    double* LPl = series(LowPass(lows,nt));

    double Slope = LinearRegSlope(LP,nt);

    const double Thres = 0.0005;
    const int Nmin = 250;

    //plot("axis",axis,0,BLUE);

    
    //plot("LPh",PosMA,0,DARKGREEN);
    //plot("LPl",NegMA,0,RED);
    
    plot("Vol",Vol,BARS+NEW,BLUE);
    plot("StDev",StDev,0,RED);
    plot("StDev1",StDev1,0,RED);

    //plot("EMA",AvgVol,1,RED);
    //plot("LV",lastvol,0,BLUE);

    //plot("nt",nt,BARS+NEW,BLACK);

    plot("Slope",Slope,1,RED);
    plot("Zero",0,0,BLACK);
    plot("Th+",Thres,0,BLACK);
    plot("Th-",-Thres,0,BLACK);
    
    // if( Vol[0] >= StDev && nt <= Nmin ){
    //     if( priceClose(0) > LP[0] && Slope >= Thres ){
    //         Stop = MinVal(lows,10);
    //         enterLong();
    //     }
    //     else if( priceClose(0) < LP[0] && Slope <= -Thres ){
    //         Stop = MaxVal(highs,10);
    //         enterShort();
    //     }
    // }
    
    // if( TradeIsLong ){
    //     if( priceClose(0) < LP[0] || Vol[0] <= StDev1 )
    //         exitLong();
    // }
    // else if( TradeIsShort ){
    //     if( priceClose(0) > LP[0] || Vol[0] <= StDev1 )
    //         exitShort();
    // }

    const int Len = 20;
    double Osc = (priceClose(0)-MaxVal(highs,nt))+(priceClose(0)-MinVal(lows,nt));

    
    
    plot("Osc",Osc,1,RED);
    plot("Z1",0,0,BLACK);


}