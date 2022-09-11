

#include <NexowFunctions.h>

void run(){

    set(PLOTNOW);
    assetList("AssetsFix");
    StartDate = 2005;
    BarPeriod = 60;
    
    double Y10 = dataFromQuandl(1,"%Y-%m-%d,f1","FED/RIFLGFL_XII_N_B",1);
    double Y30 = dataFromQuandl(2,"%Y-%m-%d,f1","FED/RIFLGFCY30_N_B",1);

    double EU1 = dataFromQuandl(3,"%Y-%m-%d,f1","BUNDESBANK/BBK01_WT1010",1);
    double EU30 = dataFromQuandl(4,"%Y-%m-%d,f1","BUNDESBANK/BBK01_WT3030",1);


    asset("EUR/USD");

    plot("10Y",EU1,1,RED);
    plot("30Y",EU30,0,BLUE);


  
}