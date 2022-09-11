// Trend Trading ///////////////////
#include <profile.c>

function run()
{
	vars Price = series(price());
	vars Trend = series(LowPass(Price,500));
	
	Stop = 4*ATR(100);
	
	if(valley(Trend))
		enterLong();
	else if(peak(Trend))
		enterShort();
	
	StartDate = 2000;
	EndDate = 2019; // fixed simulation period 2010-2015
	asset("EUR/USD");

	set(LOGFILE); // log all trades
	PlotWidth = 1600;
	PlotHeight1 = 600;
	//plotTradeProfile(-50); 
	//ColorWin = ColorLoss = 0;
	//ColorUp = ColorDn = 0;
	//ColorDD = 0x010101;
	//ColorEquity = GREY;
}