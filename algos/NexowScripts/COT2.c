

#include <NexowFunctions.h>

void run(){

    set(PLOTNOW);
    assetList("AssetsFix");
    StartDate = 2007;
    BarPeriod = 1440;
    LookBack = 200;

    asset("XAU/USD");


    double OpenInterest = COT(1,"088691",1);
    plot("Open Interest",OpenInterest,1,RED);
    double CommercialsLong = COT(2,"088691",2);
    double CommercialsShort = COT(3,"088691",3);
    plot("Commercials Long",CommercialsLong,1,RED);
    plot("Commercials Short",CommercialsShort,0,BLUE);
    double DealersLong = COT(4,"088691",4);
    double DealersShort = COT(5,"088691",5);
    plot("Dealers Long",DealersLong,1,RED);
    plot("Dealers Short",DealersShort,0,BLUE);
    double NonCommercialsLong = COT(6,"088691",6);
    double NonComercialsShort = COT(7,"088691",7);
    plot("NonComercials Long",NonCommercialsLong,1,RED);
    plot("NonComercials Short",NonComercialsShort,0,BLUE);
   

}