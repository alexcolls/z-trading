// Price Pattern Experiment ////////////////////////////

var Limit = 70;

function run()
{
	NumCores = -2;
	BarPeriod = 60;
	set(RULES+TESTNOW+ALLCYCLES);
	NumYears = 10;
	NumWFOCycles = 10;
	NumSampleCycles = 4;

	asset("EUR/USD");
	if(Train) {
		Hedge = 2;	
		Detrend = TRADES;	
	} else {
		Hedge = 1;	
		Detrend = 0;	
	}
	
	ExitTime = 4; 
	if(between(lhour(CET),9,13)) 
	{
		if(adviseLong(
			PATTERN+FAST+2,0,
			priceHigh(2),priceLow(2),priceClose(2),
			priceHigh(1),priceLow(1),priceClose(1),
			priceHigh(1),priceLow(1),priceClose(1),
			priceHigh(0),priceLow(0),priceClose(0)) > Limit)
			reverseLong(1);	
			
		if(adviseShort() > Limit)
			reverseShort(1);
	}
	
	PlotWidth = 800;
	PlotHeight1 = 320;
	ColorDD = 0;
}
