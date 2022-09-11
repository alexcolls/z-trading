
#define ES_HISTORY	"ES_201610.t1"
#define SPY_HISTORY	"SPY_201610.t1"
#define TIMEFORMAT	"%Y%m%d %H:%M:%S"
#define FACTOR			10
#define OFFSET			3.575

function main()
{
	var StartTime = wdatef(TIMEFORMAT,"20161005 10:01:25"),
		EndTime = wdatef(TIMEFORMAT,"20161005 10:01:35");
	MaxBars = 20000;
	BarPeriod = 0.001/60.;	// 1 ms bars 
	Outlier = 1.002;

	set(PLOTNOW);
	PlotHeight1 = 400;

	assetList("HFT.csv");
	dataLoad(1,ES_HISTORY,2);
	dataLoad(2,SPY_HISTORY,2);
	int RowES=0, RowSPY=0;
	
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
			priceQuote(TimeSPY,PriceSPY);
		}
		
		asset("ES");
		if(AssetBar) plot("ES",AskPrice+OFFSET,LINE,RED);
		asset("SPY");
		if(AssetBar) plot("SPY",FACTOR*AskPrice,LINE,BLACK);
	}
}
