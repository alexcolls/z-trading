//////////////////////////////////////////////////////
// Heatmap Display ///////////////////////////////////
//////////////////////////////////////////////////////
#include <profile.c>

#define NN		30	 // max number of assets

var annual(var daily)
{
	return pow(daily+1.,252)-1.;
}

function run()
{
	BarPeriod = 1440;
	NumYears = 7;
	LookBack = 6*252;
	set(PRELOAD); // allow extremely long lookback period
	Verbose = 0;

	string Names[NN];
	vars	Returns[NN];
	var	Correlations[NN][NN];
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
		for(i=0; i<N; i++)
			for(j=0; j<N; j++)
				Correlations[N*i+j] = Correlation(Returns[i],Returns[j],LookBack);
		for(i=0; i<N; i++)
			printf("\n%i - %s: Mean %.2f%%  Variance %.2f%%",
				i+1,Names[i],100*annual(Moment(Returns[i],LookBack,1)),
				252*100*Moment(Returns[i],LookBack,2));
		plotHeatmap("Correlation",Correlations,N,N);
	}
}