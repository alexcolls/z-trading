

#include <NexowFunctions.h>

void run(){

    set(PLOTNOW);
    assetList("AssetsFix");
    StartDate = 2005;
    BarPeriod = 1440;
    LookBack = 200;

    double MA1 = ZMA(series(priceClose()),40);
    double MA2 = ZMA(series(priceClose()),80);
    plot("MA1",MA1,0,RED);
    plot("MA2",MA2,0,BLUE);

    static double Acc;

    double LastRet = priceClose(1)/priceOpen(1)-1;
    double CurrRet = priceClose(0)/priceOpen(0)-1;

    if( CurrRet > LastRet )
        Acc = 1;
    else if( CurrRet < LastRet )
        Acc = -1;

    plot("Acc",Acc,BARS+NEW,RED);



    
    /*
    char* Code = "096742";
    
    double OI = (COT_OpIn(1,Code,TRUE));
    double NC = (COT_NonCom(2,Code,TRUE));

    plot("OI",OI,1,BLACK);

    plot("NC",NC,1,BLUE);
    plot("Z1",0,0,BLACK);
    
    */
  
}