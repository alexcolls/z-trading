
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

    const int Len = 100;
    double Rk = FractalDimension(series(priceClose()),Len);

    int LenD = (int)((double)Len*Rk);

    double MA = SMA(series(priceClose()),LenD);
    plot("MA",MA,0,RED);




    plot("Rk",Rk,1,RED);

    Rset("Test",Rk);

    Rx("plot(Test)");
    
    
    //Rstart("r_test3.r",2); // enable output 
    

}

