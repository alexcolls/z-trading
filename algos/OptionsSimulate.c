// Simulation von Options/FOP-Daten aus dem Underlying. 

#include <contract.c>

string Name = "SPY"; 
string FileName = "History\\SPYa.t8";
var StrikeMax[3] = { 20,40,80 }; // 3 strike ranges with different steps
var StrikeStep[3] = { 0.5,1,5 };  // stepwidths for the 3 ranges
var MinStrike = 10;
int DaysMax = 150;		// max expiration
var BidAskSpread = 0.8, BidAskSpreadMin = 0.02; // Bid/Ask spread percent and offset
var Dividend = 0.02;
int Type = 0; // or EUROPEAN, or FUTURE
int ExpireDay = FRIDAY;

/////////////////////////////////////////////////////////

CONTRACT* c;
int N = 0;

void run() 
{
	BarPeriod = 1440;
	StartDate = 2011;
	EndDate = 2018;
	LookBack = 21; // for volatility
	BarOffset = 16*60+30; // needed for same-day values
	
	assetList("AssetsIB");
	assetHistory(Name,FROM_STOOQ|UNADJUSTED);
	asset(Name);

	static int TotalContracts;
	if(is(FIRSTINITRUN)) {
		N = 0;
		initRQL();
		int MaxContractsPerDay = 2*(1+2*(StrikeMax[0]/StrikeStep[0] + StrikeMax[1]/StrikeStep[1] + StrikeMax[2]/StrikeStep[2])) * (1+DaysMax/7);
		TotalContracts = (1+EndDate-StartDate)*252*MaxContractsPerDay;
		printf("\nAllocating %d Contracts",TotalContracts);
		c = (CONTRACT*)dataNew(1,TotalContracts,9);
		if(!c) { printf(" - failed"); quit(); }
	}

	var HistVolOV = VolatilityOV(20);
	var Unl = priceClose();
	var Interest = 0.01*yield();

	if(!is(LOOKBACK)) {
		if(N >= TotalContracts || year() > EndDate) quit();
		var Strike;
		int Days = 1;
		while((dow()+Days)%7 != ExpireDay) Days++;
		for(; Days <= DaysMax; Days += 7)
		for(Strike = max(MinStrike,round(Unl-StrikeMax[2],StrikeStep[2])); Strike <= Unl+StrikeMax[2]; Strike)
		for(i = 0; i < 2; i++)
		{
			c->time = wdate();
			c->fUnl = Unl;
			c->fStrike = Strike;
			c->Type = Type + ifelse(i,PUT,CALL);
			c->Expiry = ymd(c->time+Days);
			c->fBid = contractVal(c,Unl,HistVolOV,Dividend,Interest);
			if(c->fBid < 0.01) continue; // contract is not traded
			c->fAsk = (1.+BidAskSpread/100)*c->fBid + BidAskSpreadMin;

			if(abs(Unl-Strike) < StrikeMax[0]) 
				Strike = round(Strike + StrikeStep[0],StrikeStep[0]);
			else if(abs(Unl-Strike) < StrikeMax[1]) 
				Strike = round(Strike + StrikeStep[1],StrikeStep[1]);
			else Strike = round(Strike + StrikeStep[2],StrikeStep[2]);
			N++; c++;
		}
	}
	
	if(is(EXITRUN)) {
		printf("\nSaving %d records to %s",N,FileName);
		dataSort(1);	// reverse the entry order
		dataSave(1,FileName,0,N);
		printf("\nOk!");
	}
}
