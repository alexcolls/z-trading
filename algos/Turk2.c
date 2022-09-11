// market sentiment strategy //////////////////////////////////////////
#include <contract.c>

#define HORIZON	4	// prediction horizon in weeks

void run() 
{
	set(PLOTNOW);
	setf(PlotMode,PL_DIFF+PL_BENCHMARK);
	StartDate = 20120102;
	EndDate = 20190301;
	BarPeriod = 1440;
	LookBack = 0;

	History = ".t8";
	assetList("AssetsIB");
	asset("SPY");

// load today's contract chain
	contractUpdate(0,0,CALL|PUT);
	
// follow market sentiment when there are enough contracts	
	if(contractCPD(HORIZON*7) > 20) 
	{
		LifeTime = HORIZON*5;
		MaxLong = MaxShort = 1;
		var Expectation = cpdv(50) - priceClose();
		if(Expectation > 0)
			enterLong();
		else
			enterShort();
		plot("Expectation",Expectation,NEW,BLUE);
	}
	
}