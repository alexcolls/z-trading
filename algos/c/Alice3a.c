// Alice3a: Portfolio trading ///////////////////

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
	vars Trend = series(LowPass(Price,optimize(500,300,800)));

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

	NumCores = -1;		// multicore training (Zorro S only)
	set(PARAMETERS+LOGFILE);  // generate and use optimized parameters
	BarPeriod = 60;	  // 1 hour bars
	LookBack = 2000;	// needed for Fisher()
	NumWFOCycles = 10; // activate WFO
	
	if(ReTrain) {
		UpdateDays = -1;	// update price data from the server 
		SelectWFO = -1;	// select the last cycle for re-optimization
	}
	
// portfolio loop
	while(asset(loop("EUR/USD","USD/JPY")))
	while(algo(loop("TRND","CNTR")))
	{
		if(Algo == "TRND") 
			tradeTrend();
		else if(Algo == "CNTR") 
			tradeCounterTrend();
	}
	
	PlotWidth = 800;
	PlotHeight1 = 400;
	//ColorWin = ColorLoss = 0;
	//ColorUp = ColorDn = 0;
	ColorDD = 0x010101;
	ColorEquity = GREY;
	set(TESTNOW);
}