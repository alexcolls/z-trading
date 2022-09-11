// Spectral Analysis ///////////////////

//#define FILTER // for Fig. 7

function run()
{
	BarPeriod = 60;
	StartDate = 20130128;
	EndDate = 20130201;
	LookBack = 300; // 2 x highest Cycle
	asset("SPX500");
	set(LOGFILE);
	
	vars Price = series(price());
#ifdef FILTER
	plot("Filtered",BandPass(Price,24,0.1),NEW,BLACK);
	set(PLOTNOW);
#else	
	int Cycle;
	for(Cycle = 5; Cycle < 150; Cycle += 1) {
		var Strength = Spectrum(Price,Cycle);
		plotBar("Spectrum",Cycle,Cycle,Strength,BARS+AVG+LBL2,BLACK);
	}
#endif		
}
