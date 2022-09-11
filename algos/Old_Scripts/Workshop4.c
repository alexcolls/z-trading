// Trend Trading ///////////////////
#include <profile.c>

function run()
{
	EndDate = 2017; // fixed simulation period 
	Verbose = 2;
	set(LOGFILE|PLOTNOW); // log all trades

	vars Prices = series(priceClose());
	vars Trends = series(LowPass(Prices,300));
	
	Stop = 30*ATR(100);
	
	vars MMI_Raw = series(MMI(Prices,300));
	vars MMI_Smooth = series(LowPass(MMI_Raw,300));
	
	if(falling(MMI_Smooth)) 
	{
		if(valley(Trends))
			enterLong();
		else if(peak(Trends))
			enterShort();
	}
	
	PlotWidth = 800;
	PlotHeight1 = 300;
	//setf(PlotMode,PL_FILE);
	//setf(PlotMode,PL_FILE);
	//plot("MMI_Raw",MMI_Raw,NEW,GREY);
	//plot("MMI_Smooth",MMI_Smooth,0,BLACK);
	//plotTradeProfile(-50); 
}