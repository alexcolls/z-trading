// contractPD test //////////////////////////////////////////
#include <contract.c>

#define Sentiment AssetVar[0]

void run() 
{
	if(version() < 1.99) {
		printf("\Need Zorro 1.99 or above!");
		return;
	}
	StartDate = 20120102;
	EndDate = 20171231;
	BarPeriod = 1440;

	assetList("AssetsIB");
	asset("SPY");
	MaxLong = MaxShort = 1;

// load today's contract chain
	contractUpdate(0,0,CALL|PUT);
	int N = contractCPD(45);

// change market sentiment when there are enough contracts	
	if(N) 
	{
		var Expectation = cpdv(50) - priceClose();
		if(Expectation < 0)
			Sentiment = min(Expectation,Sentiment+Expectation);
		else
			Sentiment = max(Expectation,Sentiment+Expectation);
	}
	if(Sentiment > 5)
		enterLong();
	if(Sentiment < -5)
		enterShort();
	
	plot("Sentiment",Sentiment,NEW,RED);
}