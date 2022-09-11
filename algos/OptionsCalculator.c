// Options calculator ///////////////////////////////////
#include <contract.c>

#define RANGE	2000	// underlying price range
#define RISKFREE	2	// riskfree rate in percent
#define VOLA	15		// annualized volatility in percent
//#define CALC_PRICE	// calculate price (need RQuantlib); comment out for delta only

void main()
{
	slider(1,RANGE/2,1,RANGE,"Underlng","Underlying price");
	slider(2,0,-0.15*RANGE,0.15*RANGE,"Strike+/-","Strike distance");
	//slider(3,10000,1000,30000,".Vola%",""); 
	slider(3,30,1,60,"Days","Days to expiration"); 
	printf("\nValue & Delta for put/call options");
	printf("\nRiskfree rate %.2f%%, annual volatility %.1f%%",
		(var)RISKFREE,(var)VOLA);
	int doPrice = 0;
#ifdef CALC_PRICE
	if(initRQL()) doPrice = 1;
#endif
	while(wait(100)) {
		CONTRACT Co;
		Co.fUnl = slider(1);
		Co.fStrike = Co.fUnl+slider(2);
		Co.Expiry = slider(3);
		var Vola = 0.01*VOLA; //0.001*slider(3);
		var RiskFree = 0.01*RISKFREE; 		
		var DeltaPut = 100*contractDelta(PUT,Co.Expiry,Co.fUnl,Vola,RiskFree,Co.fStrike);
		var DeltaCall = 100*contractDelta(CALL,Co.Expiry,Co.fUnl,Vola,RiskFree,Co.fStrike);
		if(doPrice) {
			Co.Type = PUT;
			var PricePut = contractVal(&Co,Co.fUnl,Vola,0,RiskFree);
			Co.Type = CALL;
			var PriceCall = contractVal(&Co,Co.fUnl,Vola,0,RiskFree);
			print(TO_INFO,"P %.2f %.0f%%  C %.2f %.0f%%",
				PricePut,DeltaPut,PriceCall,DeltaCall);
		} else
			print(TO_INFO,"Delta Put %.0f%%  Call %.0f%%",DeltaPut,DeltaCall);
#endif
	}
	printf("\n");
}