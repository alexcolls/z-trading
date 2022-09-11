
#include <NexowFunctions.h>

void run()
{

    Rstart("r_test3.r",2);
    set(PLOTNOW);
    StartDate = 2005;
    BarPeriod = 1440;
    LookBack = 200;

    assetList("AssetsFix45");
    asset("AUD/USD");



    double* Rk = FractalDimension(series(priceClose(0)),200);
    plot("MA",MA,1,RED);

    Rset("x",MA);

    Rx("plot(x)");
    
    
    //Rstart("r_test3.r",2); // enable output 
    

}

