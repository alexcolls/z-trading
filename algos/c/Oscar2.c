#include <NexowFunctions.h>

void run() {

    assetList("FX28");
    StartDate = 2010;
    BarPeriod = 1440;
    LookBack = 0;

    asset("EUR/USD");

    if (is(INITRUN))
    {
        //exec("pythonw", "Strategy\\Oscar1.py", 0);
    }
    

    FILE *csv = fopen("History\\book.csv", "a+");

    fputs(strf("%d,%f\n", utm(wdate()), price()), csv);

    fclose(csv);    
}