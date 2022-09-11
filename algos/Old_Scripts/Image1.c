// Bars & Candles /////////////////////

var Range = 0.0100;

// Renko Bars
/*int bar(vars Open,vars High,vars Low,vars Close)
{
	Open[0] = round(Close[1],Range);
	if(Close[0] - Open[0] >= Range) {
		Close[0] = Open[0]+Range;
		High[0] = Close[0];
		Low[0] = Open[0];
		return 1;
	}
	if(Open[0] - Close[0] >= Range) {
		Close[0] = Open[0]-Range;
		High[0] = Open[0];
		Low[0] = Close[0];
		return 1;
	}
	return 4;
}*/


function run()
{
	StartDate = 20090405;
	EndDate = 20090801;
	BarPeriod = 1440;
	PlotScale = 8;	
	asset("EUR/USD");
	plot("SMA",SMA(series(priceClose()),20),0,BLACK);
	set(PLOTNOW);
}