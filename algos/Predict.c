function run()
{
	BarPeriod = 1440;
	NumYears = 2;
	
	vars Price = series(price());
	var LP30 = LowPass(Price,30);
	var LP100 = LowPass(Price,100);
	vars R = series(LP30);
	int Limit = -5; // predict 5 bars in advance

	ColorUp = ColorDn = 0; // suppress the price curve
	PlotScale = 8; // bigger symbols
	PlotWidth = 1000;
	PlotHeight1 = 300;
	set(PLOTNOW);
	plot("LP30",LP30,0,RED);
	plot("LP100",LP100,0,BLUE);
		
// Peaks / Valleys ////////////////////////////////////////	
	var Peak = predict(PEAK,R,10,0.5*PIP);
	var Valley = predict(VALLEY,R,10,0.5*PIP);
	static int Reversal = 0; // plot only 1 symbol per prediction
	if(Peak > Limit) {
		if(Reversal <= 0) 
			plot("Peak",LP30+ATR(30),TRIANGLE4,RED);
		Reversal = 1;
	}
	if(Valley > Limit) {
		if(Reversal >= 0) 
			plot("Valley",LP30-ATR(30),TRIANGLE,GREEN);
		Reversal = -1;
	}
	if(Peak < Limit && Valley < Limit)
		Reversal = 0;

// Crossovers /////////////////////////////////////////////
	var CO = predict(CROSSOVER,series(LP30-LP100),10,1*PIP);
	var CU = predict(CROSSOVER,series(LP100-LP30),10,1*PIP);
	static int Crossed = 0;
	if(CO > Limit) {
		if(Crossed <= 0) 
			plot("Cross",LP30,CROSS,BLACK);
		Crossed = 1;
	}
	if(CU > Limit) {
		if(Crossed >= 0) 
			plot("Cross",LP30,CROSS,BLACK);
		Crossed = -1;
	}
	if(CO < Limit && CU < Limit)
		Crossed = 0;		
}
