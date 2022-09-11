
#include <NexowFunctions.h>

void run(){

    set(PLOTNOW);
    assetList("FXmajors");
    StartDate = 2005;
    BarPeriod = 60;
    //LookBack = 6000;
    //Hedge = 1;

    int H = hour();

    const int AsiaStart = 1 , AsiaEnd = 7 ;
    const int EuroStart = 8 , EuroEnd = 14;
    const int AmerStart = 15, AmerEnd = 21;

    static double Asia, Euro, Amer;

    while(asset(loop(Assets))){
        Spread = Commission = RollLong = RollShort = Slippage = 0;
        if( strstr("USD",Base()) ){
            if( H >= AsiaStart && H <= AsiaEnd ){
                Asia -= (priceClose(0)/priceOpen(0)-1)*100;
            }
            if( H >= EuroStart && H <= EuroEnd ){
                Euro -= (priceClose(0)/priceOpen(0)-1)*100;
            }
            if( H >= AmerStart && H <= AmerEnd ){
                Amer -= (priceClose(0)/priceOpen(0)-1)*100;
            }
            if( H == AsiaStart-1 ){
                exitLong();exitShort();
                if( Asia < 0 )
                    enterLong();
                else if( Asia > 0 )
                    enterShort();
            }
            if( H == EuroStart-1 ){
                exitLong();exitShort();
                if( Euro < 0 )
                    enterLong();
                else if( Euro > 0 )
                    enterShort();
            }
            if( H == AmerStart-1 ){
                exitLong();exitShort();
                if( Amer < 0 )
                    enterLong();
                else if( Amer > 0 )
                    enterShort();
            }
        }
        else{
            if( H >= AsiaStart && H <= AsiaEnd ){
                Asia += (priceClose(0)/priceOpen(0)-1)*100;
            }
            if( H >= EuroStart && H <= EuroEnd ){
                Euro += (priceClose(0)/priceOpen(0)-1)*100;
            }
            if( H >= AmerStart && H <= AmerEnd ){
                Amer += (priceClose(0)/priceOpen(0)-1)*100;
            }
            if( H == AsiaStart-1 ){
                exitLong();exitShort();
                if( Asia > 0 )
                    enterLong();
                else if( Asia < 0 )
                    enterShort();
            }
            if( H == EuroStart-1 ){
                exitLong();exitShort();
                if( Euro > 0 )
                    enterLong();
                else if( Euro < 0 )
                    enterShort();
            }
            if( H == AmerStart-1 ){
                exitLong();exitShort();
                if( Amer > 0 )
                    enterLong();
                else if( Amer < 0 )
                    enterShort();
            }

        }

    }

    asset(AssetBox);

    plot("Asia",Asia,1,RED);
    plot("Euro",Euro,1,BLUE);
    plot("Amer",Amer,1,GREEN);



}