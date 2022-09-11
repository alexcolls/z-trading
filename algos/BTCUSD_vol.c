
#include <nexow.h>

void run()
{
    BarPeriod = 60;
    //LookBack = 1;
	
    set(PLOTNOW);
    assetList("BTCUSD_vol.c");

    asset("BTCUSD");

    static double WKop, WKcl, WKvol;

    if( dow() == 5 && hour() == 16 ){
        WKcl = priceClose(0);
        WKvol = abs((WKcl/WKop-1)*100);
        WKop = WKcl;
        //if( WKvol > 10 )
            //t++;
    }

    plot("WKvol",WKvol,NEW+BARS,BLACK);
    plot("Min",10,LINE,RED);

    //plot("t",t,BARS+NEW,BLACK);
 
}