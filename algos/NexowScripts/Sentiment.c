// Get today's market sentiment //////////////////////////////////////

void main() 
{
	if(!Live || Broker != "IB") {
		printf("\nStart in Trade mode with IB TWS!");
		return;
	}
	StartDate = NOW;
	LookBack = 0;
	assetList("AssetsIB");
	asset("SPY");

// load today's contract chain
	contractUpdate(0,0,CALL|PUT);
	printf("\n%i contracts today",NumContracts);
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
	printf("\nWait time approx %i minutes",1+NumContracts/200);
	contractCPD(45);
	int N = 0;
	for(Price = 0.75*Current; Price <= 1.25*Current; N++,Price += 0.01*Current) {
		if(N == 25)
			plotBar("Current",N,floor(Price),cpd(Price),BARS|LBL2,BLACK);
		else
			plotBar("CPD",N,floor(Price),cpd(Price),BARS|LBL2,RED);
	}
	printf("\nExpected price %.2f",cpdv(50));
}