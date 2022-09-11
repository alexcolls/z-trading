// Trend Trading ///////////////////
#include <profile.c>

function run()
{
	vars Price = series(price());
	vars Trend = series(LowPass(Price,500));
	
	Stop = 4*ATR(100);
	
	vars MMI_Raw = series(MMI(Price,300));
	vars MMI_Smooth = series(LowPass(MMI_Raw,500));
	
	if(falling(MMI_Smooth)) {
		if(valley(Trend))
			enterLong();
		else if(peak(Trend))
			enterShort();
	}
	
	StartDate = 2005;
	EndDate = 2020; // fixed simulation period 2009-2014
	
	set(LOGFILE); // log all trades
	PlotWidth = 800;
	PlotHeight1 = 300;
	ColorUp = ColorDn = ColorWin = ColorLoss = 0;
	ColorDD = BLACK;
	ColorEquity = GREY;
	//plot("MMI_Raw",MMI_Raw,NEW,GREY);
	//plot("MMI_Smooth",MMI_Smooth,0,BLACK);
	//plotTradeProfile(-50); 
}