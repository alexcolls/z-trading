// Options Test //////////////////////////

#include <contract.c>

void run() 
{
	BarPeriod = 1440;
	BarZone = ET;
	BarOffset = 15*60;
	StartDate = 20140101;
	EndDate = 20160601;
	set(PRELOAD|LOGFILE);
	PlotWidth = 1000;
	PlotHeight1 = 400;
	
	assetList("AssetsIB");
	assetHistory("SPY",FROM_YAHOO|UNADJUSTED);
	asset("SPY");
	if(is(INITRUN))
		dataLoad(1,"SPY_Options.t8",9);

	contractUpdate(Asset,1,CALL|PUT);
	Multiplier = 100;
	int Type = ifelse(random() > 0,CALL,PUT);
	contract(Type,30,priceClose());
	static int LastExpiry = 0;
	if(ContractType && LastExpiry != ContractExpiry) {
		enterShort();
		LastExpiry = ContractExpiry;
	}
}

/* trade the underlying instead
void run() 
{
	BarPeriod = 1440;
	BarZone = ET;
	BarOffset = 15*60;
	StartDate = 20140101;
	EndDate = 20160601;
	assetList("AssetsIB");
	assetHistory("SPY",FROM_YAHOO|UNADJUSTED);
	asset("SPY");

	if(day()%10 == 0) { // trade every 10th day
		if(random() > 0) enterShort();
		else enterLong();
	}
}*/