//////////////////////////////////////////////////////
// Mean Variance Optimization ////////////////////////
//////////////////////////////////////////////////////

#define LEVERAGE 4	// 1:4 leverage
#define DAYS	252 	// 1 year
#define NN		30	 	// max number of assets

//////////////////////////////////////////////////////

function run()
{
	BarPeriod = 1440;
	LookBack = DAYS;
	NumYears = 2;
	Verbose = 0;
	set(PRELOAD); // allow extremely long lookback period

	string Names[NN];
	vars	Returns[NN];
	var	Means[NN];
	var	Covariances[NN][NN];
	var	Weights[NN];

	var TotalCapital = slider(1,1000,0,10000,"Capital","Total capital to distribute");
	var VFactor = slider(2,0,0,100,"Risk","Variance factor");
	
	int N = 0;
	while(Names[N] = loop( 
		"TLT",
		"LQD",
		"SPY",
		"GLD",
		"VGLT",
		"AOK",
		0))
	{
		if(is(INITRUN))
			assetHistory(Names[N],FROM_YAHOO);
		asset(Names[N]);
		Returns[N] = series((priceClose(0)-priceClose(1))/priceClose(1));
		if(N++ >= NN) break;
	}

	if(is(EXITRUN)) {
		int i,j;
		for(i=0; i<N; i++) {
			Means[i] = Moment(Returns[i],LookBack,1);
			for(j=0; j<N; j++)
				Covariances[N*i+j] = Covariance(Returns[i],Returns[j],LookBack);	
		}
		var BestVariance = markowitz(Covariances,Means,N,0.5);
		var MinVariance = markowitzVariance(0,0);
		markowitzReturn(Weights,MinVariance+VFactor/100.*(BestVariance-MinVariance));

		for(i=0; i<N; i++) {
			asset(Names[i]);
			MarginCost = priceClose()/LEVERAGE;
			int Position = TotalCapital*Weights[i]/MarginCost;
			printf("\n%s:  %d Contracts at %.0f$",Names[i],Position,priceClose());
		}
	}
}