///////////////////////////////////////////////////////////////////////
#include <r.h>

var change(int n)
{
	return scale((priceClose(0) - priceClose(n))/priceClose(0),100)/100;
}

var range(int n)
{
	return scale((HH(n) - LL(n))/priceClose(0),100)/100;
}

///////////////////////////////////////////////////////////////////////

function run()
{
	StartDate = 20140601;
	BarPeriod = 60;	// 1 hour
	LookBack = 100;

	WFOPeriod = 252*24; // 1 year
	DataSplit = 90;
	NumCores = -1;

	set(RULES|LOGFILE|TESTNOW|PLOTNOW);
	Spread = RollLong = RollShort = Commission = Slippage = 0;
	LifeTime = 3;
	if(Train) Hedge = 2;
	
///////////////////////////////////////////////////////////	
	if(adviseLong(NEURAL+BALANCED,0,
		change(1),change(2),change(3),change(4),
		range(1),range(2),range(3),range(4)) > 0.5) 
		enterLong();
	if(adviseShort() > 0.5) 
		enterShort();

	PlotWidth = 800;
	PlotHeight1 = 340;
	ColorUp = ColorDn = ColorWin = ColorLoss = 0;
}
