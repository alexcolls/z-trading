
#include <NexowFunctions.h>

void run(){

    set(PLOTNOW);
    assetList("FX28");
    StartDate = 2005;
    BarPeriod = 60;
    LookBack = 210;
    //Capital = 100;
    //Margin = 10;
    Spread = Commission = RollLong = RollShort = Slippage = 0;
    //ColorUp = ColorDn = ColorWin = ColorLoss = ColorEquity = ColorDD = 0;

    double* p = series(price());


    double DP = DominantPeriod(p,60);
    double Len = DP;
    

    

    double* Max = series(MaxVal(p,Len));
    double* Min = series(MinVal(p,Len));
    double* Mid = series((Max[0]+Min[0])/2);

    plot("Max",Max,0,RED);
    plot("Min",Min,0,BLUE);
    plot("Mid",Mid,0,GREEN);

    double* EUR = series(EURIdx8());
    double* EURmax = series(MaxVal(EUR,Len));
    double* EURmin = series(MinVal(EUR,Len));

    plot("EUR",EUR,1,BLACK);
    plot("EURmax",EURmax,0,RED);
    plot("EURmin",EURmin,0,BLUE);

    double* USD = series(USDIdx8());
    double* USDmax = series(MaxVal(USD,Len));
    double* USDmin = series(MinVal(USD,Len));

    plot("USD",USD,1,BLACK);
    plot("USDmax",USDmax,0,RED);
    plot("USDmin",USDmin,0,BLUE);

    static int MaxCount = 1, MinCount = 1, LastMax, LastMin;

    if( Max[0] == LastMax ){
        if( MaxCount > 0 )
            MaxCount++;
        else if( MaxCount < 0 )
            MaxCount--;
    }
    else if( Max[0] > LastMax ){
        if( MaxCount > 0 )
            MaxCount++;
        else if( MaxCount < 0 )
            MaxCount = 1;
    }
    else if( Max[0] < LastMax ){
        if( MaxCount < 0 )
            MaxCount--;
        else if( MaxCount > 0 )
            MaxCount = -1;
    }
    if( Min[0] == LastMin ){
        if( MinCount > 0 )
            MinCount++;
        else if( MaxCount < 0 )
            MinCount--;
    }
    else if( Min[0] > LastMin ){
        if( MinCount > 0 )
            MinCount++;
        else if( MinCount < 0 )
            MinCount = 1;
    }
    else if( Min[0] < LastMin ){
        if( MinCount < 0 )
            MinCount--;
        else if( MinCount > 0 )
            MinCount = -1;
    }

    LastMax = Max[0];
    LastMin = Min[0];

    plot("MaxCount",MinIndex(p,Len)-MaxIndex(p,Len),BARS+NEW,RED);

    plot("DP",DP,BARS+NEW,BLUE);



    //plot("Correl",Correlation(EUR,USD,Len/2),1,BLACK);




}