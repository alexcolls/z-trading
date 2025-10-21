// Market Regime test ///////////////////

function run()
{
	BarPeriod = 60;
	MaxBars = 800;
	LookBack = 200;
	asset(""); // dummy asset
	ColorUp = ColorDn = 0; // don't plot a price curve
	PlotHeight1 = 300;
	PlotHeight2 = 200;
	set(PLOTNOW);
	
	if(Init) seed(1234);
	vars Signals = series(ifelse(Bar-LookBack < (MaxBars-LookBack)/2,0.2+0.5*genNoise(),0.2*genNoise()+0.8*(2.*Bar-MaxBars)/MaxBars));
	int Color = BLACK;
	plot("Signals",Signals,0,Color);
	plot("FractDim",FractalDimension(Signals,100),NEW,Color);
	plot("MMI",MMI(Signals,200),NEW,Color);
}

