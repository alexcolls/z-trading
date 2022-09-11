// Rules and parameter training in 2 cycles ////////////////////////////

function run()
{
	StartDate = 2010;
	EndDate = 2018;
	BarPeriod = 1440; // 1 day
	BarZone = WET; // Western European midnight
	BarMode = BR_LEISURE;	// allows weekend bars, but don't trade on them
	NumWFOCycles = 5;
	asset("EUR/USD");
	
	set(TESTNOW);

	if(Train) Hedge = 2;	// for training, allow long + short	
	LifeTime = 3; 
	MaxLong = MaxShort = -1;
	
	Stop = optimize(5,1,10,1)*ATR(20);
	NumTrainCycles = 2;
	if(TrainCycle == 0) set(RULES|PARAMETERS); // Test or Trade mode
	else if(TrainCycle == 1) set(RULES);
	else if(TrainCycle == 2) set(PARAMETERS);
	
	if(adviseLong(PATTERN+FAST+2+RETURNS,0,
		priceHigh(2),priceLow(2),priceClose(2),
		priceHigh(1),priceLow(1),priceClose(1),
		priceHigh(1),priceLow(1),priceClose(1),
		priceHigh(0),priceLow(0),priceClose(0)) > 50)
		enterLong();
	
	if(adviseShort() > 50)
		enterShort();
}
