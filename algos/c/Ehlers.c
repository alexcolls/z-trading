// Strategy from "Predictive Indicators for Effective Trading Strategies"
// from the great John Ehlers 

#define USE_PREDICT

function run() 
{
	BarPeriod = 1440;
	MaxLong = MaxShort = 1;
	asset("SPX500");
	
	vars Osc = series(StochEhlers(series(price()),10,20,10));

#ifndef USE_PREDICT	
	if(crossOver(Osc,0.8)) 
		enterShort();
	if(crossUnder(Osc,0.2))
		enterLong();
#else		
	if(predict(CROSSOVER,series(Osc[0]-0.8),10,0.01) > -5) 
		enterShort();
	if(predict(CROSSOVER,series(0.2-Osc[0]),10,0.01) > -5) 
		enterLong();
#endif

	PlotWidth = 800;
	plot("StochEhlers",Osc,NEW,RED);
	plot("Threshold1",.2,0,BLACK);
	plot("Threshold2",.8,0,BLACK);
	set(PLOTNOW);
}
