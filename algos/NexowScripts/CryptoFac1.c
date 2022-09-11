
#include <NexowFunctions.h>

void run(){

    set(PLOTNOW+TICKS);
    assetList("CryptoFac");
    StartDate = 2010;
    BarPeriod = 1;
    LookBack = 1;

    //History = ".t1";

    asset("BTCUSD");

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