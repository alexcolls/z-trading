
#include <NexowFunctions.h>

void run(){

    set(PLOTNOW);
    assetList("FX28");
    StartDate = 2005;
    BarPeriod = 60;
    //LookBack = 9000;
    //Spread = Commission = RollLong = RollShort = 0;
    Hedge = 1;

    int H = hour();

    const int AsiaStart = 1 , AsiaEnd = 7 ;
    const int EuroStart = 8 , EuroEnd = 14;
    const int AmerStart = 15, AmerEnd = 21;

    static double X_As, X_Eu, X_Am;
    static double Y_As, Y_Eu, Y_Am;

    const string X = "USD", Y = "JPY";

    while(asset(loop(Assets))){
        string x = Base();
        string y = Term();
        if( strstr(X,x) ){
            if( H >= AsiaStart && H <= AsiaEnd ){
                X_As += (priceClose(0)/priceOpen(0)-1)*100;
            }
            if( H >= EuroStart && H <= EuroEnd ){
                X_Eu += (priceClose(0)/priceOpen(0)-1)*100;
            }
            if( H >= AmerStart && H <= AmerEnd ){
                X_Am += (priceClose(0)/priceOpen(0)-1)*100;
            }
        }
        else if( strstr(X,y) ){
            if( H >= AsiaStart && H <= AsiaEnd ){
                X_As -= (priceClose(0)/priceOpen(0)-1)*100;
            }
            if( H >= EuroStart && H <= EuroEnd ){
                X_Eu -= (priceClose(0)/priceOpen(0)-1)*100;
            }
            if( H >= AmerStart && H <= AmerEnd ){
                X_Am -= (priceClose(0)/priceOpen(0)-1)*100;
            }
        }
        if( strstr(Y,y) ){
            if( H >= AsiaStart && H <= AsiaEnd ){
                Y_As -= (priceClose(0)/priceOpen(0)-1)*100;
            }
            if( H >= EuroStart && H <= EuroEnd ){
                Y_Eu -= (priceClose(0)/priceOpen(0)-1)*100;
            }
            if( H >= AmerStart && H <= AmerEnd ){
                Y_Am -= (priceClose(0)/priceOpen(0)-1)*100;
            }
        }
        else if( strstr(Y,x) ){
            if( H >= AsiaStart && H <= AsiaEnd ){
                Y_As += (priceClose(0)/priceOpen(0)-1)*100;
            }
            if( H >= EuroStart && H <= EuroEnd ){
                Y_Eu += (priceClose(0)/priceOpen(0)-1)*100;
            }
            if( H >= AmerStart && H <= AmerEnd ){
                Y_Am += (priceClose(0)/priceOpen(0)-1)*100;
            }
        }
    }

    asset(AssetBox);

    plot("X_As",X_As,1,RED);
    plot("Y_As",Y_As,0,RED+TRANSP);
    plot("X_Eu",X_Eu,1,BLUE);
    plot("Y_Eu",Y_Eu,0,BLUE+TRANSP);
    plot("X_Am",X_Am,1,DARKGREEN);
    plot("Y_Am",Y_Am,0,GREEN);



}