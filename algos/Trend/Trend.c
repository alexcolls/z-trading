// Trend Trading Experiment ///////////////////
#include <default.c>

#define WRC
#define DO_STATISTIC

int Period;
var Daily[3000];

var objective() 
{ 
	if(NumWinTotal < 30 || NumLossTotal < 30) { // not enough trades
		StepNext = 0;	// abort optimization
		return 0; 
	}
	
#ifdef DO_STATISTIC	
// store the result statistic	
	string FileName = "Log\\TrendStats.txt";
	string NameScript,NameAsset,NameAlgo;
	if(WinTotal > LossTotal) {
		NameScript = strf("%s_Won",Script);
		NameAsset = strf("%s_Won",Asset);
		NameAlgo = strf("%s_Won",Algo);
	} else {
		NameScript = strf("%s_Lost",Script);
		NameAsset = strf("%s_Lost",Asset);
		NameAlgo = strf("%s_Lost",Algo);
	}
	lock();
	var Score = getvar(FileName,NameScript);
	putvar(FileName,NameScript,Score+1);
	Score = getvar(FileName,NameAsset);
	putvar(FileName,NameAsset,Score+1);
	Score = getvar(FileName,NameAlgo);
	putvar(FileName,NameAlgo,Score+1);
	unlock();
#endif	

#ifdef WRC
// store the curves of daily returns
	string FileName = "Log\\TrendDaily.bin";
	string Name = strf("%s_%s_%s_%i",Script,Asset,Algo,Period);
	int Size = Day*sizeof(var);
	lock();
	file_append(FileName,Name,strlen(Name)+1);
	file_append(FileName,&Size,sizeof(int));
	file_append(FileName,Daily,Size);
	unlock();
#endif
	
	return WinTotal/max(1,LossTotal); // Profit factor
}

var filter(var* Data,int Period);

void run()
{
	set(PARAMETERS|LOGFILE);
	PlotHeight1 = 200;
	PlotScale = 8;
	ColorBars[1] = BLACK; // winning trades
	ColorBars[2] = GREY; // losing trades

#ifdef WRC
	Spread = Commission = RollLong = RollShort = Slippage = 0;
#endif

	StartDate = 2010;
	EndDate = 2016;
	BarPeriod = 15;
	LookBack = 80*4*24; // ~ 4 months
	
	while(asset(loop("EUR/USD","SPX500","XAG/USD")))
	while(algo(loop("M15","H1","H4")))
	{
		TimeFrame = 1;
		if(Algo == "H1")
			TimeFrame = 4;
		else if(Algo == "H4")
			TimeFrame = 4*4;	

		int Periods[10] = { 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000 };
		Period = Periods[optimize(0,0,9,1)];
		
		var *Price = series(price());
		var *Smoothed = series(filter(Price,Period));

		if(valley(Smoothed))
			enterLong();
		else if(peak(Smoothed))
			enterShort();
	} 
	
#ifdef WRC
// story daily result
	Daily[Day] = Balance;
#endif
}