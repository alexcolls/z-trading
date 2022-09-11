

#include <NexowFunctions.h>

void run(){

    set(PLOTNOW);
    assetList("AssetsFix");
    StartDate = 2005;
    BarPeriod = 60;
    LookBack = 300;
    Spread = Commission = 0;

    char* Code = "099741";//"096742";
    
    //double OI = COT_OpIn(1,Code,FALSE);
    double NC1 = COT_NonCom(2,Code,TRUE);
    //double CO = -COT_Comm(3,Code,FALSE);
    //double RE = COT_Retail(4,Code,FALSE);

    char* Code2 = "096742";
    
    //double OI = COT_OpIn(1,Code,FALSE);
    double NC2 = COT_NonCom(6,Code2,TRUE);
    //double CO2 = -COT_Comm(3,Code,FALSE);
    //double RE = COT_Retail(4,Code,FALSE);

    double NC = NC1-NC2;

    asset("EUR/GBP");

    int Len = 200;
    double* P = series(price());
    double* LP = series(EMA(P,Len));

    static int Dir = 1;
    static double L1, L2, L3, L4, LastNC, LastPrice, NCL1, NCL2, LastDir;

    /*
    if( ( NC < 0 && LastNC > 0 ) || ( NC > 0 && LastNC < 0 ) ){
        NCL1 = 0;
    }
    */


    if( NC < LastNC && LastDir == 1 ){
        NCL1 = LastNC;
    }
    if( NC > LastNC && LastDir == -1 ){
        NCL2 = LastNC;
    }

    if( NC > NCL1 )
        NCL1 = NC;
    if( NC < NCL2 )
        NCL2 = NC;


    if( NC > LastNC ){
        LastDir = 1;
    }
    else if( NC < LastNC ){
        LastDir = -1;
    }

    if( NC != LastNC ){
        LastNC = NC;
        LastPrice = priceClose(1);
    }

    static int Sig, Sig2;
    if( Dir == -1 && NC > 0 ){
        if( L1 < priceClose(1) )
            Sig = 1;
        else
            Sig = 0;
        L1 = priceClose(1);
        Dir = 1;
    }
    else if( Dir == 1 && NC < 0 ){
        if( L1 > priceClose(1) )
            Sig = -1;
        else
            Sig = 0;
        L1 = priceClose(1);
        Dir = -1;
    }


    if( NC > 0 && NC2 < 0 )
        Sig2 = 1;
    else if( NC < 0 && NC2 > 0 )
        Sig2 = -1;
    else
        Sig2 = 0;

    /*
    double Prop = 0.5;
    if( Dir == 1 && priceHigh(0) > L4 ){
        L2 = priceClose(0);
        L4 = priceHigh(0);
        L3 = L1+(priceHigh(0)-L1)*Prop;
    }
    else if( Dir == -1 && priceLow(0) < L4 ){
        L2 = priceClose(0);
        L4 = priceLow(0);
        L3 = L1-(L1-priceLow(0))*Prop;
    }
    */



    plot("L1",L1,0,RED);
    //plot("LastPrice",LastPrice,0,BLUE);
    plot("LP",LP,0,RED);
    //plot("L2",L2,0,GREEN);
    //plot("L4",L4,0,BLUE);
    //plot("L3",L3,0,BLACK);

    plot("NC",NC,1,BLUE);
    plot("Zero",0,0,BLACK);

    //plot("OI",OI,1,BLACK);
    plot("NC1",NC1,1,RED);
    plot("NC2",NC2,0,BLUE);
    //plot("CO",CO,0,BLUE);
    //plot("RE",RE,0,GREEN);
    plot("Z",0,0,BLACK);
    //plot("NCL1",NCL1,0,RED);
    //plot("NCL2",NCL2,0,GREEN);





  
}