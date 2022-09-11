// DTree example. In sample test, for illustration only. //////////

function run()
{
	set(RULES|PLOTNOW);
	StartDate = 2016;
	EndDate = 2017;
	BarPeriod = 240;
	LookBack = 250;
	
	while(asset(loop("EUR/USD","AUD/USD","GBP/USD")))
	{
// data series
		vars Closes = series(priceClose());
		vars Highs = series(priceHigh());
		vars Lows = series(priceLow());
		vars Trends= series(LowPass(Closes, 100));
		
// signals
		var Sigs[3];
		Sigs[0] = scale(Highs[0]-Lows[0], 250);
		Sigs[1] = scale(Closes[0]-Trends[0], 250);
		Sigs[2] = scale(ATR(20), 250);
		
		if(Train) Hedge = 2; //needed for training trade results
		LifeTime = 6; 	// 1 day prediction horizon
		MaxLong = MaxShort = 1;
		
// generate model in train mode, predict next trade in test/live mode
		var LongPrediction = adviseLong(DTREE+RETURNS,0,Sigs,3);
		var ShortPrediction = adviseShort(DTREE+RETURNS,0,Sigs,3);
		if(Train || (LongPrediction > 0 && ShortPrediction < 0))
			enterLong();
		if(Train || (ShortPrediction > 0 && LongPrediction < 0))
			enterShort();
		
// chart
		PlotWidth = 800;
		plot("LongPrediction", LongPrediction, NEW|BARS, GREEN+TRANSP);
		plot("ShortPrediction", ShortPrediction, 0|BARS, RED+TRANSP);
	}
}