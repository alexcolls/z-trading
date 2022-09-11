// Machine learning ////////////////////////////
#include <profile.c>

function run()
{
	StartDate = 2006;
	EndDate = 2017;
	BarPeriod = 1440; // 1 day
	BarZone = WET; // Western European midnight
	Weekend = 1;	// don't merge Friday and Sunday bars
	LookBack = 3;	// only 3 bars needed
	NumWFOCycles = 10;
	asset("EUR/USD");
	
	set(RULES+TESTNOW);

	if(Train) Hedge = 2;	// for training, allow long + short	
	LifeTime = 5;  		// one week
	MaxLong = MaxShort = 1;
	
	if(adviseLong(PATTERN+FAST+2,0,
		priceHigh(2),priceLow(2),priceClose(2),
		priceHigh(1),priceLow(1),priceClose(1),
		priceHigh(1),priceLow(1),priceClose(1),
		priceHigh(0),priceLow(0),priceClose(0)) > 40)
		enterLong();
	
	if(adviseShort() > 40)
		enterShort();

	PlotWidth = 600;
	PlotHeight1 = 300;
	//plotTradeProfile(40);
	//plotWFOCycle(Equity,0);
	//plotWFOProfit();
}
