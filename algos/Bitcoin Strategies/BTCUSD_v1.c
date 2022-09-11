
#include <nexow.h>

void run()
{
   
	
    set(PLOTNOW);
    asset("BTCUSD");
    BarPeriod = 60;

    static double WKop, WKcl, WKvol;
    static int t = 0;

    if( dow(0) == 5 && hour(0) == 16 )
    {
        WKcl = priceClose(0);
        if( WKop > 0 )
            WKvol = ( WKcl / WKop - 1 )*100;
        WKop = WKcl;
        if( abs(WKvol) > 10 )
            t++;
    }

    plot("WKvol",WKvol,NEW+BARS,RED);
    plot("t",t,BARS+NEW,BLACK);
 
}  
