// Filter test ///////////////////

function run()
{
	BarPeriod = 60;
	MaxBars = 500;
	ColorUp = ColorDn = 0; // don't plot a price curve
	LookBack = 150;
	set(PLOTNOW);
	asset(""); // dummy asset
	
	vars Impulse = series(1-genSquare(400,400));
	int Period = 50;
	plot("Impulse",Impulse,0,GREY);
	plot("SMA",SMA(Impulse,Period),0,BLACK);
	plot("EMA",EMA(Impulse,Period),0,0xA0A000);
	plot("ALMA",ALMA(Impulse,Period),0,0x008000);
	plot("Laguerre",Laguerre(Impulse,10.0/Period),0,0xA00000);
	plot("LinearReg",LinearReg(Impulse,Period),0,0x0000A0);
	plot("Hull MA",HMA(Impulse,Period),0,0x00FF00);
	plot("Zero-Lag MA",ZMA(Impulse,Period),0,0x00FFFF);
	plot("Decycle",Decycle(Impulse,Period),0,0xFF00FF);
	plot("LowPass",LowPass(Impulse,Period),0,0xFF0000);
	plot("Smooth",Smooth(Impulse,Period),0,0x0000FF);
}

