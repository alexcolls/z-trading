// Workshop 5: Counter trend trading, optimized ////////////////

function run()
{
	set(PARAMETERS|LOGFILE);  // generate and use optimized parameters
	BarPeriod = 240;	// 4 hour bars
	LookBack = 500;
	StartDate = 2005;
	EndDate = 2017; 	// fixed simulation period
	NumWFOCycles = 10; // activate WFO
	NumCores = -2;	// multicore training
	
	asset("EUR/USD");
	
	if(ReTrain) {
		UpdateDays = -1;	// update price data from the server 
		SelectWFO = -1;	// select the last cycle for re-optimization
	}
		
// calculate the buy/sell signal
	vars Price = series(price());
	vars Filtered = series(BandPass(Price,optimize(30,20,40),0.5));
	vars Signal = series(FisherN(Filtered,500));
	var Threshold = optimize(1,0.5,1.5,0.1);

// buy and sell
	Stop = optimize(4,2,10) * ATR(100);
	Trail = 4*ATR(100);

	if(crossUnder(Signal,-Threshold))
		enterLong(); 
	else if(crossOver(Signal,Threshold))
		enterShort();

// plot signals and thresholds
	plot("Filtered",Filtered,NEW,BLUE);
	plot("Signal",Signal,NEW,RED);
	plot("Threshold1",1,0,BLACK);
	plot("Threshold2",-1,0,BLACK);
	PlotWidth = 600;
	PlotHeight1 = 300;
	set(PLOTNOW);
} 