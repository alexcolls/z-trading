// Workshop 5: Counter trend trading, optimized, no WFO ////////////////
#include <profile.c>

function run()
{
	StartDate = 2010;
	EndDate = 2016; // fixed simulation period

	set(PARAMETERS+LOGFILE);  // generate and use optimized parameters
	BarPeriod = 240;	// 4 hour bars
	LookBack = 500;	// required for Fisher()
	
// calculate the buy/sell signal
	vars Price = series(price());
	vars Filtered = series(BandPass(Price,optimize(30,20,40),0.5));
	vars Signal = series(FisherN(Filtered,500));
	var Threshold = optimize(1,0.5,1.5,0.1);

// buy and sell
	Lots = 1;
	Stop = optimize(4,2,10) * ATR(100);
	Trail = 4*ATR(100);
	if(crossUnder(Signal,-Threshold))
		enterLong(); 
	else if(crossOver(Signal,Threshold))
		enterShort();

	PlotWidth = 600;
	PlotHeight1 = 300;
	//set(TESTNOW+PLOTNOW);
	//plotMAEGraph(-5); // plot the MAE graph
	//plotTradeProfile(30); 
} 