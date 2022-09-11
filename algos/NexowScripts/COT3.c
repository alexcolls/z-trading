

#include <NexowFunctions.h>

void run(){

    set(PLOTNOW);
    assetList("AssetsFix");
    StartDate = 2007;
    BarPeriod = 1440;
    LookBack = 200;

    asset("AUD/CAD");


    double OI_AUD = COT(1,"232741",1);
    plot("OI_AUD",OI_AUD,1,BLUE);
    double OI_CAD = COT(2,"090741",1);
    plot("OI_CAD",OI_CAD,0,RED);

    double* OI = series(OI_AUD+OI_CAD);
    double MA = SMA(OI,20);

    plot("OI",OI,1,RED);
    plot("MA",MA,0,BLACK);

   
   

}