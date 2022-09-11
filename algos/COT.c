

#include <NexowFunctions.h>

void run(){

    set(PLOTNOW);

    assetList("AssetsFix");
    //setFees(0.0,0.0,0.0,5);

    StartDate = 2007;
    BarPeriod = 1440;
    LookBack = 600;

    asset("XAU/USD");

    double* Prices = series(priceClose());

    if(is(INITRUN)) {
        assetAdd("GOLD");
        int Handle = assetHistory("CHRIS/CME_GC1",FROM_QUANDL|VOLATILE); // load gold futures history
        if(Handle) dataSave(Handle,"GOLD.t6");
    }

    asset("GOLD");
    plot("XAUUSD",Prices,0,RED);
    double* Prices2 = series(priceClose());
    plot("XAUUSD2",Prices2,0,BLUE);
    string COT_Code = "CFTC/088691_F_ALL";
    var Ind = COT_CommercialIndex(1,COT_Code,6*20); // gold COT report
    plot("Fast Index",Ind,NEW,RED);
    var Ind2 = COT_CommercialIndex(1,COT_Code,12*20);
    plot("Slow Index",Ind2,0,BLUE);
   


    

}