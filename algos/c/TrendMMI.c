// Trend Trading Experiment ///////////////////
#include <default.c>

#define NO_COSTS
//#define DO_STATISTIC

string StatFile = "Log\\TrendStats.txt";
string DayFile = "Log\\BalanceDaily.bin";

var statistics(string Which)
{
	lock();
	var Wins = getvar(StatFile,strf("%s_Won",Which));
	var Losses = getvar(StatFile,strf("%s_Lost",Which));
	if(WinTotal > LossTotal)
		putvar(StatFile,strf("%s_Won",Which),Wins+1);
	else
		putvar(StatFile,strf("%s_Lost",Which),Losses+1);
	putvar(StatFile,strf("%s_Percent",Which),100*Wins/max(1,Wins+Losses));
	unlock();
}

int checkLookBack(int Period) 
{
	if(Period >= LookBack/TimeFrame) {
		StepNext = 0;	// abort optimization
		return LookBack/TimeFrame;
	} else
		return Period;
}

var objective() 
{ 
	if(NumWinTotal < 30 || NumLossTotal < 30) { // not enough trades
		StepNext = 0;	// abort optimization
		return 0; 
	}
	
#ifdef DO_STATISTIC	
	statistics(Script);
	statistics(Asset);
	statistics(Algo);
#endif	
	
	return WinTotal/max(1,LossTotal); // Profit factor
}

var filter(var* Data,int Period);

void run()
{
	set(PARAMETERS|LOGFILE|PLOTNOW|BALANCE);
	PlotHeight1 = 250;
	PlotScale = 8;
	ColorBars[1] = BLACK; // winning trades
	ColorBars[2] = GREY; // losing trades
	Detrend = TRADES;
	Curves = DayFile;

	StartDate = 2010;
	BarPeriod = 15;
	LookBack = 80*4*24; // ~ 4 months

	while(asset(loop("EUR/USD","SPX500","XAG/USD")))
	while(algo(loop("M15","H1","H4")))
	{
		TimeFrame = 1;
		if(strstr(Algo,"H1"))
			TimeFrame = 1*4;
		else if(strstr(Algo,"H4"))
			TimeFrame = 4*4;	

#ifdef NO_COSTS
		Spread = Commission = RollLong = RollShort = Slippage = 0;
#endif
		int Periods[10] = { 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000 };
		int Period = Periods[round(optimize(1,1,10,1),1)-1];
		
		var *Price = series(price());
		var *Smoothed = series(filter(Price,Period));

		int DoTrade = 1;
		int MMIPeriod = optimize(0,200,500,100);
		if(MMIPeriod > 0) {
			MMIPeriod = checkLookBack(MMIPeriod);
			vars MMI_Raw = series(MMI(Price,MMIPeriod));
			vars MMI_Smooth = series(LowPass(MMI_Raw,MMIPeriod));
			DoTrade = ifelse(falling(MMI_Smooth),1,0);
		}

		if(DoTrade) {
			if(valley(Smoothed))
				enterLong();
			else if(peak(Smoothed))
				enterShort();
		}
	}
}