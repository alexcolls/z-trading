
#include <NexowFunctions.h>

void run(){

    set(PLOTNOW);
    assetList("FX28");
    StartDate = 2005;
    BarPeriod = 60;
    //LookBack = 6000;
    Spread = Commission = RollLong = RollShort = 0;
    //Hedge = 1;

    int H = hour();

    const int AsiaStart = 1 , AsiaEnd = 7 ;
    const int EuroStart = 8 , EuroEnd = 14;
    const int AmerStart = 15, AmerEnd = 21;

    static double Asia, Euro, Amer;

    int Len = 1000;

    if( H >= AsiaStart && H <= AsiaEnd ){
        Asia += (priceClose(0)/priceOpen(0)-1)*100;
        
    }
    if( H >= EuroStart && H <= EuroEnd ){
        Euro += (priceClose(0)/priceOpen(0)-1)*100;
    }
    if( H >= AmerStart && H <= AmerEnd ){
        Amer += (priceClose(0)/priceOpen(0)-1)*100;
    }
    double* as = series(Asia);
    double* eu = series(Euro);
    double* am = series(Amer);

    double AS = (LinearRegSlope(as,Len));
    double EU = (LinearRegSlope(eu,Len));
    double AM = (LinearRegSlope(am,Len));

    if( H == AsiaStart-1 ){
        //algo("AS");
        exitLong();exitShort();
        if( AS > 0 )
            enterLong();
        else if( AS < 0 )
            enterShort();
    }
    if( H == EuroStart-1 ){
        //algo("EU");
        exitLong();exitShort();
        if( EU > 0 )
            enterLong();
        else if( EU < 0 )
            enterShort();
    }
    if( H == AmerStart-1 ){
        //algo("AM");
        exitLong();exitShort();
        if( AM > 0 )
            enterLong();
        else if( AM < 0 )
            enterShort();
    }



    plot("Asia",Asia,1,RED);
    plot("AS",AS,1,RED);
    //plot("ASm",AS[Len],0,BLACK);
    plot("Euro",Euro,1,BLUE);
    plot("EU",EU,1,BLUE);
    //plot("EUm",EU[Len],0,BLACK);
    plot("Amer",Amer,1,GREEN);
    plot("AM",AM,1,GREEN);
    //plot("AMm",AM[Len],0,BLACK);



}