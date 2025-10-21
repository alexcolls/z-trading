// PERCEPTRON Test ////////////////////////////

function run()
{
	set(RULES,PEEK,TESTNOW,PLOTNOW,OPENEND);
	StartDate = 20150101;
	EndDate = 20181231;
	BarPeriod = 1440;
	LookBack = 100;
	BarZone = WET;
	BarOffset = 9*60+30; // market open
	asset("EUR/USD");
	
// set up walk-forward parameters
	int TestBars = 50; //number of bars in test period
	int TrainBars = 500; //number of bars in training period
	DataSplit = 100*TrainBars/(TestBars+TrainBars);
	WFOPeriod = TestBars+TrainBars;	
	
//signals
	vars Prices = series(priceClose());
	var Signals[4];
	Signals[0] = scale(ATR(10)-ATR(50),100);
	Signals[1] = ROC(Prices,1);
	Signals[2] = ROC(Prices,3);
	Signals[3] = ROC(Prices,10);
	
	var ObjLong = ifelse(priceClose(-5)-priceClose(0) > 200*PIP,1,-1);
	var ObjShort = ifelse(priceClose(-5)-priceClose(0) < -200*PIP,1,-1);
	
	if(Train) Hedge = 2; //needed for training trade results
	LifeTime = 3;
	MaxLong = MaxShort = 1;
	var GoLong = adviseLong(PERCEPTRON+BALANCED,ObjLong,Signals,4);
	var GoShort = adviseShort(PERCEPTRON+BALANCED,ObjShort,Signals,4);

	if(!Train) {	
		if(GoLong > 0 and GoShort < 0) 
			enterLong();
		else if(GoShort > 0 and GoLong < 0) 
			enterShort();
	}	
	PlotWidth = 800;
	plot("GoLong", GoLong, NEW, GREEN);
	plot("GoShort", GoShort, NEW, RED);	
}