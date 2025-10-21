
#include <nexow.h>

void run(){

    set(PLOTNOW);
    BarPeriod = 60;
    assetList("OandaEuropeALL.csv");
    LookBack = 300;
    StartDate = 2018;

    double* pri = series(price(),100);
    double MA = SMA(pri,100);

    plot("EMA",MA,0,RED);
    

}