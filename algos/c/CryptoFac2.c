
#include <NexowFunctions.h>

void run(){

    set(PLOTNOW);
    assetList("CryptoFac.csv");
    StartDate = 2018;
    EndDate = 20190401;
    BarPeriod = 1440;
    //LookBack = 1;

    Weekend = 0; 

    History = ".t1";

    asset("XBTUSDpe");



    // double Bid = priceClose(0);
    // double VOLbid = marketVol(0);

    // asset("XBTUSDask");

    // double Ask = priceClose(0);
    // double VOLask = marketVol(0);

    // plot("Ask",Ask,0,BLUE);
    // plot("Bid",Bid,0,RED);

    // plot("VolAsk",VOLask,BARS+NEW,BLUE);
    // plot("VolBid",VOLbid,BARS,RED+TRANSP);





}