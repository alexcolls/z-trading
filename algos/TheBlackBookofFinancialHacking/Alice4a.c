// Machine learning ////////////////////////////
#include <profile.c>

function run()
{
	StartDate = 2005; // use > 10 years data
	EndDate = 2015;
	BarPeriod = 1440; // 1 day
	BarZone = WET;		// West European session
	Weekend = 1;	// don't merge Friday and Sunday bars
	LookBack = 3;	// only 3 bars needed
	NumWFOCycles = 10;
	//Detrend = SHUFFLE;	// reality check

	asset("EUR/USD");
	set(RULES+TESTNOW+LOGFILE);// generate rules, test after training

	if(Train) Hedge = 2;	// for training, allow long + short	
	LifeTime = 5;  		// one week
	Stop = 1000*PIP;		// just a large stop distance
	
	if(adviseLong(PATTERN+2,0,
		priceHigh(2),priceLow(2),priceClose(2),
		priceHigh(1),priceLow(1),priceClose(1),
		priceHigh(1),priceLow(1),priceClose(1),
		priceHigh(0),priceLow(0),priceClose(0)) > 40)
		reverseLong(1);
	
	if(adviseShort() > 40)
		reverseShort(1);
	
	PlotWidth = 800;
	PlotHeight1 = 400;
	ColorDD = 0x010101;
	ColorEquity = GREY;
	//plotWFOCycle(Equity,0);
	//plotWFOProfit();
}
