function run()
{
	StartDate = 20141230;
	EndDate = 20150225;
	PlotWidth = 800;
	PlotHeight1 = 300;
	PlotHeight2 = 150;
	set(PLOTNOW);
	asset("EUR/CHF");

	plot("Volatility",LowPass(series((HH(10) - LL(10))),400),NEW+BARS,BLACK);
}