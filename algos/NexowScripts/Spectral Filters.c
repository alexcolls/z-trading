
function run()
{
	// Generale Parameters //
		
		set(PLOTNOW);
		BarPeriod = 1440; 
		BarZone = UTC;
		StartDate = 2005;
		LookBack = 240;
		//Spread = RollLong = RollShort = Commission = Slippage = 0;
	
	//
	
	var Period = DominantPeriod(10);
	vars Prices = series(priceClose());
	
	
	vars High = series(SMA(series(HH(Period,1)),Period));
	vars Low = series(SMA(series(LL(Period,1)),Period));

	
	plot("HH",High,0,RED);
	plot("LL",Low,0,BLUE);
	
	
	
	
	vars Prices = series(priceClose());
	

	vars X1 = series(HighPass(High,Period));
	
	vars X1m = series(LowPass(X1,Period));
	
	vars Y1 = series(HighPass(Low,Period));
	
	vars Y1m = series(LowPass(Y1,Period));

	
	plot("X1",X1,1,RED);
	//plot("X1m",X1m,0,RED);
	plot("Y1",Y1,0,BLUE);
	//plot("Y1m",Y1m,0,BLUE);
	plot("0",0,0,BLACK);
	
	plot("Peak",peak(X1)+peak(Y1),1,RED);
	plot("Valley",valley(X1)+valley(Y1),0,BLUE);
	
	int Signal;
	
	if( X1[0] < X1[2] && X1[1] > X1[2] && X1[0] > 0 && X1[0] > X1m[0] )
		Signal = -1;
	
	if( X1[0] > X1[2] && X1[1] < X1[2] && X1[0] < 0 && X1[0] < X1m[0] )
		Signal = 1;
	
	
	var R1 = Period;
	
	plot("R1",Period,1,BLUE);

	
}