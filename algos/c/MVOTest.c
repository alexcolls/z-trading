//////////////////////////////////////////////////////
// MVO Experiments            ////////////////////////
//////////////////////////////////////////////////////
#include <profile.c>

//#define HEATMAP

#define DAYS	252 // 1 year
#define NN		30	 // max number of assets

//////////////////////////////////////////////////////

function run()
{
	BarPeriod = 1440;
	LookBack = DAYS;
	NumYears = 7;
	Verbose = 0;
	set(PRELOAD); // allow extremely long lookback period

	string Names[NN];
	vars	Returns[NN];
	var	Means[NN];
	var	Covariances[NN][NN];
	var	Weights[NN];
	
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

	int i,j;
	static var BestVariance = 0;
	static int Month = 0;
	if(tdm() == 1 && !is(LOOKBACK)) {
		for(i=0; i<N; i++) {
			Means[i] = Moment(Returns[i],LookBack,1);
			for(j=0; j<N; j++)
				Covariances[N*i+j] = Covariance(Returns[i],Returns[j],LookBack);	
		}
		BestVariance = markowitz(Covariances,Means,N,0.5);
		Month++;
	}
	
	static var Return, ReturnN, ReturnMax, ReturnBest, ReturnMin;
	if(is(LOOKBACK)) {
		Month = 0;
		ReturnN = ReturnMax = ReturnBest = ReturnMin = 0;
	}

	if(BestVariance > 0) {
		for(Return=0,i=0; i<N; i++) Return += (Returns[i])[0]/N; // 1/N 
		ReturnN = (ReturnN+1)*(Return+1)-1;
		
		markowitzReturn(Weights,0);	// min variance
		for(Return=0,i=0; i<N; i++) Return += Weights[i]*(Returns[i])[0];
		ReturnMin = (ReturnMin+1)*(Return+1)-1;
		
		markowitzReturn(Weights,1);	// max return
		for(Return=0,i=0; i<N; i++) Return += Weights[i]*(Returns[i])[0];
		ReturnMax = (ReturnMax+1)*(Return+1)-1;

		markowitzReturn(Weights,BestVariance); // max Sharpe
		for(Return=0,i=0; i<N; i++) Return += Weights[i]*(Returns[i])[0];
		ReturnBest = (ReturnBest+1)*(Return+1)-1;

		set(PLOTNOW);
		PlotHeight1 = 300;
#ifndef HEATMAP
		PlotWidth = 1000;
		ColorUp = ColorDn = ColorWin = ColorLoss = ColorEquity = ColorDD = 0;
		plot("1/N",100*ReturnN,AXIS2,BLACK);
		plot("Max Sharpe",100*ReturnBest,AXIS2,GREEN);
		plot("Max Return",100*ReturnMax,AXIS2,RED);
		plot("Min Variance",100*ReturnMin,AXIS2,BLUE);
#endif
	}
#ifdef HEATMAP
	static var *WeightMap = 0;
	if(!WeightMap && NumBars) 
		WeightMap = (var*)malloc(NumBars*N*sizeof(var));
	for(i=0; i<N; i++)
		WeightMap[Month*N+i] = Weights[i];
	PlotWidth = 1500;
	plotHeatmap("Weights",WeightMap,N,Month,0.5);
	if(is(EXITRUN))
		free(WeightMap);
#endif
}