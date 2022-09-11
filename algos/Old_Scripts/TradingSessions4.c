
#include <NexowFunctions.h>

typedef struct{
    double Ret[1000];
} str;

str AS1[28]; int as1 = 0;
str EU1[28]; int eu1 = 0;
str AM1[28]; int am1 = 0;

str AS2[28]; int as2 = 0;
str EU2[28]; int eu2 = 0;
str AM2[28]; int am2 = 0;

void run(){

    set(PLOTNOW);
    assetList("FX28");
    StartDate = 2005;
    BarPeriod = 60;
    LookBack = 1000;
    
    //Hedge = 1;

    const int AsiaStart = 1 , AsiaEnd = 7 ;
    const int EuroStart = 8 , EuroEnd = 14;
    const int AmerStart = 15, AmerEnd = 21;
    const int Len1 = 600, Len2 = 200;

    int k = 0;
    while(asset(loop(Assets))){
        
        Spread = Commission = RollLong = RollShort = 0;
        double Ret = (priceClose(0)/priceOpen(0)-1);
        int H = hour();

        double AS_CumRet1, EU_CumRet1, AM_CumRet1;
        double AS_CumRet2, EU_CumRet2, AM_CumRet2;
        if( H >= AsiaStart && H <= AsiaEnd ){

            if( as1 >= Len1 )
                as1 = 0;
            AS1[k].Ret[as1] = Ret;
            as1++;
            AS_CumRet1 = Sum(AS1[k].Ret,Len1);

            if( as2 >= Len2 )
                as2 = 0;
            AS2[k].Ret[as2] = Ret;
            as2++;
            AS_CumRet2 = Sum(AS2[k].Ret,Len2);

        }
        if( H >= EuroStart && H <= EuroEnd ){

            if( eu1 >= Len1 )
                eu1 = 0;
            EU1[k].Ret[eu1] = Ret;
            eu1++;
            EU_CumRet1 = Sum(EU1[k].Ret,Len1);

            if( eu2 >= Len2 )
                eu2 = 0;
            EU2[k].Ret[eu2] = Ret;
            eu2++;
            EU_CumRet2 = Sum(EU2[k].Ret,Len2);

        }
        if( H >= AmerStart && H <= AmerEnd ){

            if( am1 >= Len1 )
                am1 = 0;
            AM1[k].Ret[am1] = Ret;
            am1++;
            AM_CumRet1 = Sum(AM1[k].Ret,Len1);

            if( am2 >= Len2 )
                am2 = 0;
            AM2[k].Ret[am2] = Ret;
            am2++;           
            AM_CumRet2 = Sum(AM2[k].Ret,Len2);
        
        }

        plot("AS_CumRet1",AS_CumRet1,BARS+NEW,RED);
        plot("AS_CumRet2",AS_CumRet2,BARS,BLUE+TRANSP);
        plot("AS0",0,0,BLACK);
        plot("EU_CumRet1",EU_CumRet1,BARS+NEW,RED);
        plot("EU_CumRet2",EU_CumRet2,BARS,BLUE+TRANSP);
        plot("EU0",0,0,BLACK);
        plot("AM_CumRet1",AM_CumRet1,BARS+NEW,RED);
        plot("AM_CumRet2",AM_CumRet2,BARS,BLUE+TRANSP);
        plot("AM0",0,0,BLACK);

        k++;

        if( H == AsiaStart ){
            if( AS_CumRet2 > AS_CumRet1 )
                enterLong();
            else
                enterShort();
        }
        else if( H == AsiaEnd ){
            exitLong();
            exitShort();
        }
        if( H == EuroStart ){
            if( EU_CumRet2 > EU_CumRet1 )
                enterLong();
            else
                enterShort();
        }
        else if( H == EuroEnd ){
            exitLong();
            exitShort();
        }
        if( H == AmerStart ){
            if( AM_CumRet2 > AM_CumRet1 )
                enterLong();
            else
                enterShort();
        }
        else if( H == AmerEnd ){
            exitLong();
            exitShort();
        }

    }


}