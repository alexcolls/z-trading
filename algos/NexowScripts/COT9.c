

#include <NexowFunctions.h>

void run(){

    set(PLOTNOW);
    assetList("AssetsFix");
    StartDate = 2005;
    BarPeriod = 1440;
    LookBack = 200;

    int Len1 = 80;
    int Len2 = 160;

    double MA1 = HTTrendline(series(priceClose()));
    double MA2 = ZMA(series(priceClose()),Len2);
    plot("MA1",MA1,0,BLUE);
    //plot("MA2",MA2,0,RED);

    char* Code = "096742";
    
    double* NC = series(COT_NonCom(2,Code,TRUE));

    double* NCMA1 = series(EMA(NC,Len1));
    double NCMA2 = ZMA(NC,Len2);

    static int Dir;
    static double Max, Min;

    if( Dir == 1 && NC[0] < 0 ){
        Min = priceLow(0);
    }
    else if( Dir == -1 && NC[0] > 0 ){
        Max = priceHigh(0);
    }

    if( NC[0] < 0 )
        Dir = -1;
    else if( NC[0] > 0 )
        Dir = 1;

    if( Dir == -1 && priceLow(0) < Min )
        Min = priceLow(0);
    else if( Dir == 1 && priceHigh(0) > Max )
        Max = priceHigh(0);

    plot("Max",Max,0,RED);
    plot("Min",Min,0,BLUE);


    plot("NC",NC,1,BLACK);
    plot("NCMA1",NCMA1,0,BLUE);
    //plot("NCMA2",NCMA2,0,RED);
    plot("Z1",0,0,BLACK);

    int Trend;
    if( NC[0] > 0 && NC[0] > NCMA1[0] )
        Trend = 1;
    else if( NC[0] < 0 && NC[0] < NCMA1[0] )
        Trend = -1;
    else
        Trend = 0;

    plot("Trend",Trend,BARS+NEW,RED);
    plot("Z2",0,0,BLACK);

    if( Trend == -1 ){
        if( priceClose(0) > MA1 ){
            TakeProfit = MA1;
            enterShort();
        }
    }
    else if( Trend == 1 ){
        if( priceClose(0) < MA1 ){
            TakeProfit = MA1;
            enterLong();
        }
    }
    else
    {
        exitLong(); exitShort();
    }
    


    
  
}