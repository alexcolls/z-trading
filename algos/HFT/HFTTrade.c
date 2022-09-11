
#define ES_HISTORY	"ES_201610.t1"
#define SPY_HISTORY	"SPY_201610.t1"
#define TIMEFORMAT	"%Y%m%d %H:%M:%S"
#define FACTOR			10
#define LATENCY		0.5	// milliseconds
#define THRESHOLD		0.4

// This is the C coded HFT system
// 0 for closing the position
// 1 for ES long, SPY short
// 2 for ES short, SPY long
// -1 otherwise 
int tradeHFT(double AskSPY,double BidSPY,double AskES,double BidES)
{
	double SpreadSPY = AskSPY-BidSPY, SpreadES = AskES-BidES;
	double Arbitrage = (AskSPY+BidSPY-AskES-BidES)/2;
	static double ArbMean = Arbitrage;	
	ArbMean = 0.999*ArbMean + 0.001*Arbitrage;
	static double Deviation = 0;
	Deviation = 0.75*Deviation + 0.25*(Arbitrage - ArbMean);
	
	static int Position = 0;	
	if(Position == 0) {
		if(Deviation > SpreadSPY+THRESHOLD)
			return Position = 1;
		if(-Deviation > SpreadES+THRESHOLD)
			return Position = 2;
	} else {
		if(Position == 1 && -Deviation > SpreadES+THRESHOLD/2)
			return Position = 0;
		if(Position == 2 && Deviation > SpreadSPY+THRESHOLD/2)
			return Position = 0;
	}
	return -1;	
}

function main()
{
	var StartTime = wdatef(TIMEFORMAT,"20161005 09:30:00"),
		EndTime = wdatef(TIMEFORMAT,"20161005 15:30:00");
	MaxBars = 200000;
	BarPeriod = 0.1/60.;	// 100 ms bars 
	Outlier = 1.002;

	set(LOGFILE+PLOTNOW);
	PlotWidth = 1000;
	PlotHeight1 = 400;
	ColorWin = ColorLoss = 0;

	assetList("HFT.csv");
	dataLoad(1,ES_HISTORY,2);
	dataLoad(2,SPY_HISTORY,2);
	int RowES=0, RowSPY=0;
	
	EntryDelay = LATENCY/1000.;
	Hedge = 2;
	Fill = 8; // HFT fill mode;
	Slippage = 0;
	Lots = 100;
		
	while(Bar < MaxBars)
	{
		var TimeES = dataVar(1,RowES,0), 
			PriceES = dataVar(1,RowES,1),
			TimeSPY = dataVar(2,RowSPY,0),
			PriceSPY = dataVar(2,RowSPY,1);

		if(TimeES < TimeSPY) RowES++;
		else RowSPY++;

		if(min(TimeES,TimeSPY) < StartTime) continue;
		if(max(TimeES,TimeSPY) > EndTime) break;

		if(TimeES < TimeSPY) {
			asset("ES");
			priceQuote(TimeES,PriceES);
		} else {
			asset("SPY");
			priceQuote(TimeSPY,FACTOR*PriceSPY);
		}
		
		asset("ES");
		if(!AssetBar) continue;
		var AskES = AskPrice, BidES = AskPrice-Spread;
		asset("SPY");
		if(!AssetBar) continue;
		var AskSPY = AskPrice, BidSPY = AskPrice-Spread;

		plot("Arbitrage Profit",Equity,BARS+AXIS2,BLUE);

		//timer();
		int Action = tradeHFT(AskSPY,BidSPY,AskES,BidES);	
		//printf("#\nHFT time: %.3f us",timer()*1000);	
		switch(Action) {
			case 1: 
			asset("ES"); enterLong();
			asset("SPY"); enterShort();
			break;
		
			case 2: 
			asset("ES"); enterShort();
			asset("SPY"); enterLong();
			break;
		
			case 0:
			asset("ES"); exitLong(); exitShort();
			asset("SPY"); exitLong(); exitShort();
			break;
		}
	}
	asset("ES"); exitLong(); exitShort();	// exit last trade at the end
	asset("SPY"); exitLong(); exitShort();
	printf("\nEquity %.2f at NY Time %s",
		Equity,strdate(TIMEFORMAT,dataVar(1,RowES,0)));
}
