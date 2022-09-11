// Alice's Scam Robot /////////////////////

// Remarks: Stop distance increased to 500 pips
// for avoiding negative granularity bias


#define HIGH_WIN_RATE
//#define HISTOGRAM

function run()
{
	BarPeriod = 1440;
	StartDate = 2015;
	NumYears = 1;
	LookBack = 0;

	asset("EUR/USD");
#ifdef HIGH_WIN_RATE
	TakeProfit = 25*PIP;
	Stop = 500*PIP;

	if(NumOpenTotal == 0) 
#endif
	{
		if(random() > 0)
			enterLong();
		else 
			enterShort();
	}
	
	set(PLOTNOW|LOGFILE);
	ColorUp = ColorDn = ColorDD = 0;
	ColorWin = ColorLoss = 0;
	PlotWidth = 800;
	PlotHeight1 = 320;

#ifdef HISTOGRAM	
	NumTotalCycles = 3000; // run this simulation 3000 times
#endif
}

// generate a profit distribution chart
#ifdef HISTOGRAM	
function evaluate()
{
#ifdef HIGH_WIN_RATE
	var Step = 100;
#else
	var Step = 250;
#endif	
	var Bucket = floor(ProfitClosed/PIPCost/Step);
	plotBar("Profit",Bucket,Step*Bucket,1,SUM+BARS+LBL2,RED);	
}
#endif