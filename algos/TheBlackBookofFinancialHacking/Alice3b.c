// Workshop 6_1: Portfolio trading ///////////////////

function tradeCounterTrend()
{
	TimeFrame = 4;
	vars Price = series(price());
	var BestCycle = optimize(30,25,35);
	vars Filtered = series(BandPass(Price,BestCycle,0.5));
	vars Signal = series(FisherN(Filtered,500));
	var Threshold = optimize(1,0.5,1.5,0.1);
	
	Stop = optimize(4,2,10) * ATR(100);
	Trail = 4*ATR(100);
	
	var Cycle = DominantPeriod(Price,10);
	
	if(between(Cycle,BestCycle-10,BestCycle+10)) {
		if(crossUnder(Signal,-Threshold))
			reverseLong(1); 
		else if(crossOver(Signal,Threshold))
			reverseShort(1);
	}
}

function tradeTrend()
{
	TimeFrame = 1;
	vars Price = series(price());
	vars Trend = series(LowPass(Price,optimize(500,300,700)));

	Stop = optimize(4,2,10) * ATR(100);
	Trail = 0;

	vars MMI_Raw = series(MMI(Price,300));
	vars MMI_Smooth = series(LowPass(MMI_Raw,500));
	
	if(falling(MMI_Smooth)) {
		if(valley(Trend))
			enterLong();
		else if(peak(Trend))
			enterShort();
	}
}

function run()
{
	StartDate = 2005;
	EndDate = 2015;

	set(PARAMETERS+FACTORS+LOGFILE);  // generate and use optimized parameters and factors
	BarPeriod = 60;	// 1 hour bars
	LookBack = 2000;	// needed for Fisher()
	NumWFOCycles = 10; // activate WFO
	NumCores = -1;		// use multiple cores (Zorro S only)
	Capital = 10000;	// reinvestment mode
	
	if(ReTrain) {
		UpdateDays = -1;	// update price data from the server 
		SelectWFO = -1;	// select the last cycle for re-optimization
		reset(FACTORS);	// don't generate factors when re-training
	}
	
// portfolio loop
	while(asset(loop("EUR/USD","USD/JPY")))
	while(algo(loop("TRND","CNTR")))
	{
// method 1: invest 1% of the balance	
		Margin = 0.01 * (Capital + ProfitClosed);	

// method 2: invest 50% of Optimal-F		
		Margin = 0.5 * OptimalF * (Capital + ProfitClosed);

// method 3: invest the square root of the component profit
		Margin = 0.5 * OptimalF * Capital * sqrt(1 + ProfitClosed/Capital);

		if(Algo == "TRND") 
			tradeTrend();
		else if(Algo == "CNTR") 
			tradeCounterTrend();
	}
	
	PlotWidth = 600;
	PlotHeight1 = 300;
	ColorUp = ColorDn = ColorWin = ColorLoss = 0; // don't plot candles and trades
	ColorDD = 0x010101;
	ColorEquity = GREY;
	set(TESTNOW+PLOTNOW); // plot the chart immediately after testing
}