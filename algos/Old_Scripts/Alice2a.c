// Workshop 5: Counter trend trading ///////////////////

function run()
{
	StartDate = 2000;
	EndDate = 2019; // fixed simulation period 2010-2015

	BarPeriod = 240;	// 4 hour bars
	
// calculate the buy/sell signal
	vars Price = series(price());
	vars Filtered = series(BandPass(Price,30,0.5));
	vars Signal = series(FisherN(Filtered,500));
	var Threshold = 1.0;

	Stop = 4*ATR(100);
	Trail = 4*ATR(100);

// buy and sell
	if(crossUnder(Signal,-Threshold))
		reverseLong(1); 
	else if(crossOver(Signal,Threshold))
		reverseShort(1);

// plot signals and thresholds
	plot("Filtered",Filtered,NEW,BLUE);
	plot("Signal",Signal,NEW,RED);
	plot("Threshold1",1,0,BLACK);
	plot("Threshold2",-1,0,BLACK);

	PlotWidth = 800;
	PlotHeight1 = 300;
	//PlotDate = 20110707;
	//PlotBars = 100;
	//PlotScale = 7;
	ColorWin = ColorLoss = 0;
	//ColorDD = ColorEquity = 0;
	ColorDD = 0x010101;
	ColorEquity = GREY;
} 