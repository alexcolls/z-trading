
#include <NexowFunctions.h>

void run(){

    set(PLOTNOW);
    StartDate = 2005;
    BarPeriod = 1440;
    LookBack = 300;



    double MA = EMA(series(price()),60);
    plot("MA",MA,0,RED);

    if( priceClose(0) > MA && priceClose(1) < MA )
        enterLong();
    else if( priceClose(0) < MA && priceClose(1) > MA )
        enterShort();

    plot("EUR",EURIdx8(),1,RED);
    plot("USD",USDIdx8(),0,BLUE);


}