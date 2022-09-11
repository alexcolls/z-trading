//////////////////////////////////////////////////////
// Efficient Frontier ////////////////////////////////
//////////////////////////////////////////////////////
#include <profile.c>

#define NN		30	 // max number of assets

function run()
{
	BarPeriod = 1440;
	NumYears = 7;
	LookBack = 6*252;
	set(PRELOAD); // allow extremely long lookback period
	Verbose = 0;

	string Names[NN];
	vars	Returns[NN];
	var	Covariances[NN][NN];
	var	Means[NN];
	
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

		var BestV = markowitz(Covariances,Means,N,0);	
		var MinV = markowitzVariance(0,0);
		var MaxV = markowitzVariance(0,1);
			
		PlotScale = 8;
		PlotHeight1 = 300;
		int Steps = 50;
		for(i=0; i<Steps; i++) {
			var V = MinV + i*(MaxV-MinV)/Steps;
			var R = markowitzReturn(0,V);
			plotBar("Frontier",i,V,100*R,LINE|LBL2,BLACK);
		}
		plotGraph("Max Sharpe",(BestV-MinV)*Steps/(MaxV-MinV),
			100*markowitzReturn(0,BestV),SQUARE,GREEN);
	}
}