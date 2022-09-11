// Alice's Martingale Scam Robot /////////////////////

// Remarks: Stop distance increased to 500 pips
// for avoiding negative granularity bias

//#define HISTOGRAM
//#define CHECK_MARGINCALL

function run()
{
	BarPeriod = 1440;
	StartDate = 2015;
	NumYears = 1;
	LookBack = 0;

	asset("EUR/USD");
	TakeProfit = 25*PIP;
	Stop = 500*PIP;

	var ProfitGoal = 100*Bar;
	Lots = (ProfitGoal-ProfitClosed/PIPCost)/22; 
	Lots = clamp(Lots,1,200); 

#ifdef CHECK_MARGINCALL
	if(ProfitOpen+ProfitClosed < -250) {
		exitLong();
		exitShort();
	} else
#endif
	if(NumOpenTotal == 0) {
		if(random() > 0)
			enterLong();
		else 
			enterShort();
	}
	
#ifdef HISTOGRAM	
	NumTotalCycles = 3000; // run this simulation 3000 times
#else
	set(PLOTNOW|LOGFILE);
#endif
	ColorUp = ColorDn = ColorDD = 0;
	ColorWin = ColorLoss = 0;
	PlotWidth = 800;
	PlotHeight1 = 320;
}

// generate a profit distribution chart
#ifdef HISTOGRAM	
function evaluate()
{
	var Step = 1000;
	var Bucket = floor(ProfitClosed/PIPCost/Step);
	if(Bucket > -100)
		plotBar("Profit",Bucket,Step*Bucket,1,SUM+BARS+LBL2,RED);	
}
#endif