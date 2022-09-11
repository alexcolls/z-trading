function run(){
	
	set(PLOTNOW);
	
	StartDate = 2005;
	BarPeriod = 1440;
	
	int Period = 10;
	
	var FirstPrice = priceClose(Period-1);
	
	var Slope = ( priceClose(0)-FirstPrice ) / ( Period - 1 );

	int i;
	var Mean = SMA(series(priceClose()),Period);
	var LRDev = 0;
	var StDev = 0;
	
	for(i = 0; i<Period; i++)
	{
		var Line = FirstPrice+(Slope*i);
		LRDev += abs(priceClose(Period - 1 - i) - Line)/Period;
		StDev += abs(priceClose(Period - 1 - i) - Mean)/Period;
	}
	
	var StDev2 = LowPass(series(StdDev(series(StDev),Period)),3);
	
	var sLRDev = SMA(series(LRDev),Period);
	
	var Threshold = LRDev;//sLRDev+StDev2;
	
	var Mid = ZMA(series(priceClose()),Period);
	var High = Mid + sLRDev;
	var Low = Mid - sLRDev;
	
	var Hi = Mid + StDev;
	var Lo = Mid - StDev;
	
	plot("M",Mid,0,BLACK);
	plot("M",Mid,0,BLACK);
	plot("H",High,0,BLUE);
	plot("L",Low,0,BLUE);	
	
	plot("Hi",Hi,0,RED);
	plot("Lo",Lo,0,RED);	
	
	plot("sLRDev",sLRDev,1,BLUE);
	plot("StDev",StDev,0,RED);
	plot("Threshold",Threshold,0,BLACK);
	
	
	
	
	
	/*
	
	// Trend System //
	
	vars Vol = series(StDev);
	vars Mids = series(Mid);
	

	if( !TradeIsOpen )
	{
		if( rising(Vol) && ( StDev > Threshold ) )
		{
			if( falling(Mids) )
			{
				enterShort();
				
			}
			else if( rising(Mids) )
			{
				enterLong();
				
			}
		}
	}
	
	if( TradeIsOpen && ( StDev < Threshold ) ) 
	{
		exitLong();
		exitShort();
	}
	
	*/
	
	
	
}