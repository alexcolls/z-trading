
function run(){
	
	set(PLOTNOW);
	StartDate = 2019;
	BarPeriod = 5;
	BarZone = UTC;
	Commission = 0;
	Spread = 0;
	Slippage = 0;
	RollShort = 0;
	RollLong = 0;
	
	PlotHeight1 = 0;
	PlotHeight2 = 2000;
		
	var Threshold = 0.0;
	
	asset("XAU/USD");
		plot("XAU/USD",price(),NEW,BLUE);
		exitLong(); exitShort();
		var Xr = ( priceClose(0)/priceClose(1)-1 );
		
	asset("XAG/USD");
		plot("XAG/USD",price(),NEW,RED);
		exitLong(); exitShort();
		var Yr = ( priceClose(0)/priceClose(1)-1 );
		
		
	var Diff = ( Xr-Yr );	
	
	if(Diff > Threshold)
	{
		asset("XAU/USD");
			Lots = round( 10000/priceClose(1));
			enterShort();
		asset("XAG/USD");
			Lots = round( 10000/priceClose(1) );
			enterLong();
	}
		
	if(Diff<-Threshold)
	{
		asset("XAU/USD");
			Lots = round( 10000/priceClose(1) );
			enterLong();
		asset("XAG/USD");
			Lots = round( 10000/priceClose(1) );
			enterShort();
	}

	plot("Diff",Diff,NEW,RED);
	plot("T+",Threshold,0,BLACK);
	plot("T-",-Threshold,0,BLACK);	
	
}