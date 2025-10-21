// Workshop 6: Money Management ///////////////////

function tradeCounterTrend()
{
	TimeFrame = 4;
	vars Price = series(price());
	vars Filtered = series(BandPass(Price,optimize(30,20,40),0.5));
	vars Signal = series(FisherN(Filtered,500));
	var Threshold = optimize(1,0.5,1.5,0.1);
	
	Stop = optimize(10,2,30) * ATR(100);
	Trail = 4*ATR(100);
	
	if(crossUnder(Signal,-Threshold)) 
		enterLong(); 
	else if(crossOver(Signal,Threshold)) 
		enterShort();
}

function tradeTrend()
{
	TimeFrame = 1;
	vars Price = series(price());
	vars Trend = series(LowPass(Price,optimize(300,100,700)));

	Stop = optimize(10,2,30) * ATR(100);
	Trail = 0;

	vars MMI_Raw = series(MMI(Price,300));
	vars MMI_Smooth = series(LowPass(MMI_Raw,300));
	
	if(falling(MMI_Smooth)) {
		if(valley(Trend))
			enterLong();
		else if(peak(Trend))
			enterShort();
	}
}

function run()
{
	set(PARAMETERS+FACTORS+LOGFILE);  // generate and use optimized parameters and factors
	NumCores = -2;		// use multiple cores (Zorro S only)
	BarPeriod = 60;	// 1 hour bars
	LookBack = 2000;	// needed for Fisher()
	StartDate = 2005;
	EndDate = 2017; 	// fixed simulation period
	NumWFOCycles = 10; // activate WFO
	Capital = 10000;		// reinvestment mode
	
	if(ReTrain) {
		UpdateDays = -1;	// update price data from the server 
		SelectWFO = -1;	// select the last cycle for re-optimization
		reset(FACTORS);	// don't generate factors when re-training
	}
	
// portfolio loop
	while(asset(loop("EUR/USD","USD/JPY")))
	while(algo(loop("TRND","CNTR")))
	{
// don't reinvest
		Margin = 0.5 * OptimalF * Capital;

// reinvest the square root of the component profit		
		//Margin = 0.5 * OptimalF * Capital * sqrt(1 + ProfitClosed/Capital);

		if(Algo == "TRND") 
			tradeTrend();
		else if(Algo == "CNTR") 
			tradeCounterTrend();
	}
	
	PlotWidth = 600;
	PlotHeight1 = 300;
}