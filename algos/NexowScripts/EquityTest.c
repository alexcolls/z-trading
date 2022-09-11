
#include <NexowFunctions.h>


void run() {

    set(PLOTNOW+COMMAND);

    asset("AAAA");
    //LookBack = 200;
    StartDate = 2017;
    EndDate = 2018;
    //BarPeriod = 1440;
    //Weekend = 1;

    double MA = SMA(series(priceClose()),20);

    plot("MA",MA,0,RED);

}