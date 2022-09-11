// Machine learning ////////////////////////////
#include <profile.c>

function run()
{
	StartDate = 2005; // use > 10 years data
	EndDate = 2015;
	BarPeriod = 1440; // 1 day
	BarZone = WET;		// European session
	Weekend = 1;	// don't merge Friday and Sunday bars
	LookBack = 3;	// only 3 bars needed
	NumWFOCycles = 10;

	if(Test) {
		Detrend = SHUFFLE;
		NumTotalCycles = 1000;
	}

	asset("EUR/USD");
	set(RULES);

	if(Train) Hedge = 2;	// for training, allow long + short	
	LifeTime = 5;  		// one week
	Stop = 1000*PIP;		// just a large stop distance
	
	if(adviseLong(PATTERN+FAST+2,0,
		priceHigh(2),priceLow(2),priceClose(2),
		priceHigh(1),priceLow(1),priceClose(1),
		priceHigh(1),priceLow(1),priceClose(1),
		priceHigh(0),priceLow(0),priceClose(0)) > 40)
		reverseLong(1);
	
	if(adviseShort() > 40)
		reverseShort(1);
}


function evaluate()
{
	var TestProfit = 450;
	static int Count = 0;
	if(Balance > TestProfit)
		Count++;
	
	var Bucket = floor(Balance/25);
	plotBar("Profit",Bucket,25*Bucket,1,SUM+BARS+LBL2,RED);	

	if(TotalCycle == NumTotalCycles) {
		var Probability = (100.*Count)/NumTotalCycles;
		printf("\n-------------------------------------------");
		printf("\nReality Check: %.1f%% Random Probability",Probability);
		if(Probability <= 1)
			printf("\nSystem result is significant");
		else if(Probability <= 5)
			printf("\nSystem result is possibly significant");
		else 
			printf("\nSystem result is not statistically significant");
		printf("\n-------------------------------------------");
	} 
}