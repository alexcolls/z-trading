// contractPD test //////////////////////////////////////////
	
void main() 
{
	if(version() < 1.98) {
		printf("\Need Zorro 1.99 or above!");
		return;
	}
	StartDate = 20170601;
	LookBack = 0;

	assetList("AssetsIB");
	History = ".t8"; // make sure no adjusted prices are used
	asset("SPY");

// load today's contract chain
	contractUpdate(0,0,CALL|PUT);
	printf("\n%i contracts",NumContracts);
	if(!NumContracts) return;
	
// get min and max strike
	contract(CALL,45,0);
	var StrikeMin = ContractStrike;
	contract(CALL,45,9999);
	var StrikeMax = ContractStrike;
	printf("\nStrike range %.2f...%.2f",StrikeMin,StrikeMax);

// get underlying price
	var Price,Current = priceClose(0);
	printf("\nCurrent price %.2f",Current);

// plot CPD histogram	
	contractCPD(45);	// 6 weeks
	int N = 0;
	for(Price = 0.75*Current; Price <= 1.25*Current; N++,Price += 0.01*Current) {
		if(N == 25)
			plotBar("Current",N,floor(Price),cpd(Price),BARS|LBL2,BLACK);
		else
			plotBar("CPD",N,floor(Price),cpd(Price),BARS|LBL2,RED);
	}
	printf("\nExpected price %.2f",cpdv(50));
	
// compare with future price
	set(PEEK);
	N = timeOffset(UTC,-45,0,0);
	printf("\nFuture price %.2f",priceClose(N));
}