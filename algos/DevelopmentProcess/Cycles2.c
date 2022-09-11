// Cycles Trading Test ///////////////////

function run()
{
	BarPeriod = 60;
	LookBack = 200;
	set(PARAMETERS+LOGFILE);
	NumWFOCycles = 5;
	
// entry parameters	
	vars Price = series(price());
	var Phase = DominantPhase(Price,10);
	vars Signal = series(sin(Phase+optimize(1,0.7,2)*PI/4));
	
// filter	
	vars Dominant = series(BandPass(Price,rDominantPeriod,1));
	var Threshold = optimize(1,0.7,2)*PIP;

// exit parameters	
	ExitTime = 10*rDominantPeriod;
	//Stop = ATR(100);
	//for(open_trades)
	//	TradeStopLimit -= TradeStopDiff/(10*rDominantPeriod);

	if(Amplitude(Dominant,100) > Threshold) {
		if(valley(Signal))
		  reverseLong(1); 
		else if(peak(Signal))
		  reverseShort(1);
	}
	
	asset("EUR/USD");
	PlotWidth = 800;
	PlotHeight1 = 320;
}

