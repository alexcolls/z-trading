// Strategy template ///////////////////////

#include <nexow.h>

void run() 
{
	set(PLOTNOW);

	assetList("OandaEuropeALL");

    Spread = Commission = RollLong = RollShort = 0;
	
    BarPeriod = 1;
	StartDate = 2016;
	
	asset("EUR_USD");

	double* Prices = series(price());
	double MA = SMA(Prices,30);

	plot("MA",MA,0,RED);

    if( priceClose(0) > MA && priceClose(1) < MA )
        enterShort();
    else if( priceClose(0) < MA && priceClose(1) > MA )
        enterLong();

}