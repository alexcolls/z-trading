// Random Price Curve ///////////////////

function run()
{
	NumYears = 2;
	BarPeriod = 1440;
	PlotWidth = 800;
	PlotHeight1 = 300;
	ColorUp = ColorDn = 0; // don't plot a real price curve
	set(PLOTNOW);
	
	asset("EUR/USD");
	plot("Price",price(),0,RED);	
	
	vars Random = series(0);
	if(Bar == 1)
		Random[0] = price();
	else
		Random[0] = Random[1] + 0.01*random();
	plot("Random",Random[0],0,BLUE);	
}