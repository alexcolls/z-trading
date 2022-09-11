// Workshop 5: Counter trend trading, optimized ////////////////

function run()
{
	StartDate = 2010;
	EndDate = 2015;

	set(PARAMETERS+LOGFILE);  // generate and use optimized parameters
	BarPeriod = 240;	// 4 hour bars
	LookBack = 500;	// required for Fisher()
	if(Train) Detrend = TRADES;
	
// calculate the buy/sell signal
	vars Price = series(price());
	var BestCycle = optimize(30,25,35);
	vars Filtered = series(BandPass(Price,BestCycle,0.5));
	vars Signal = series(FisherN(Filtered,500));
	var Threshold = optimize(1,0.5,1.5,0.1);

// buy and sell
	Stop = optimize(4,2,10) * ATR(100);
	Trail = 4*ATR(100);

	var Cycle = DominantPeriod(Price,10);
	
	if(between(Cycle,BestCycle-10,BestCycle+10)) {
		if(crossUnder(Signal,-Threshold))
			reverseLong(1); 
		else if(crossOver(Signal,Threshold))
			reverseShort(1);
	}
	
	PlotWidth = 800;
	PlotHeight1 = 300;
//	if(Train) PlotHeight1 = 200;
//	g->dwColorBars[0] = 0x010101;
//	g->dwColorBars[1] = 0x808080;
//	g->dwColorBars[2] = 0xd0d0d0;
	set(TESTNOW);
} 