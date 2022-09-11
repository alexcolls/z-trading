
function run()
{
	// Generale Parameters //
		
		set(PLOTNOW);
		BarPeriod = 1440; 
		BarZone = WET;
		StartDate = 2005;
		LookBack = 2000;
		Spread = RollLong = RollShort = Commission = Slippage = 0;
	
	//
	
	// Machine Learning Paramaters //
		
		set(RULES|PEEK|TESTNOW|OPENEND); // generate rules, test after training
		NumWFOCycles = 5;   // mandatory for machine learning functions
		//if(Train) Hedge = 2; // allow long + short
		//LifeTime = 5;        // = one week
		//MaxLong = MaxShort = 1; // only 1 open trade
  
	//
	
	// Normalized Variables //
		
		var Periods = 120; //optimize(120,10,600,10);
		
		var Return = log(priceClose())-log(priceOpen());
  
		var Center = center(Return,Periods);
		var Scale = scale(Return,Periods);
		var Compress = compress(Return,Periods);
		var Normal = normalize(Return,Periods);
		var ZScore = zscore(Return,Periods);  
  
	//
	
	plot("Center",Center,1,BLUE);
	plot("Scale",Scale,1,BLUE);
	plot("Compress",Compress,1,BLUE);
	plot("Normalize",Normal,1,BLUE);
	plot("Z-Score",ZScore,1,BLUE);
	
	
	var Signals[5];
	
	Signals[0] = Center;
	Signals[1] = Scale;
	Signals[2] = Compress;
	Signals[3] = Normal;
	Signals[4] = ZScore;

	//Stop = 4*ATR(100); 
	//TakeProfit = 4*ATR(100);
	if(adviseLong(DTREE,0,Signals,2) > 0)
		enterLong();
	if(adviseShort(DTREE,0,Signals,2) > 0)
		enterShort();

}