// Workshop 8: Simple Option system //////////////////////////////////////////
#include <contract.c>

#define PREMIUM	3.00
#define DAYS		6*7 


void run() 
{
	StartDate = 2012;
	EndDate = 2018;
	BarPeriod = 1440;
	LookBack = 1;
	set(PLOTNOW|LOGFILE);

	assetList("AssetsIB");
	asset("SPY");
	History = "a.t8"; // artificial options data
	Multiplier = 100;

// load today's contract chain
	int N = contractUpdate(Asset,0,CALL|PUT); 

// Enter new positions
	if(N && !NumOpenShort) { 
		if(combo(
			contractFind(CALL,DAYS,PREMIUM,2),1, 
			contractFind(PUT,DAYS,PREMIUM,2),1,
			0,0,0,0)) 
		{
			MarginCost = 0.15*priceClose()/2;
			enterShort(comboLeg(1));
			enterShort(comboLeg(2));
		}
	}
}