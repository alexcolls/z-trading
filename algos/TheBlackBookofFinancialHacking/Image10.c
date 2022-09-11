function run()
{
//	StartDate = 20130615;
	StartDate = 20141215;
//	EndDate = 20150101;
	EndDate = 20150215;
	LookBack = 60*24;
	PlotWidth = 800;
	PlotHeight1 = 320;
	PlotHeight2 = 150;
	set(PLOTNOW);
	asset("EUR/CHF");

//	plot("Volatility",LowPass(series((HH(24) - LL(24))),3000),NEW+BARS,BLACK);
}