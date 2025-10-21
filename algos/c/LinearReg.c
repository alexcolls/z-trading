void run(){
	
	set(PLOTNOW);

    assetList("OandaEuropeFX45");
	
	StartDate = 2005;
	BarPeriod = 1440;
	
	int Period = 10;

	
    double FirstPrice = priceClose(Period-1);
    
    double Slope = ( priceClose(0)-FirstPrice ) / ( Period - 1 );

    
    double Mean = SMA(series(priceClose()),Period);
    double LRDev = 0;
    double StDev = 0;
    
    int i;
    for(i = 0; i<Period; i++)
    {
        double Line = FirstPrice+(Slope*i);
        LRDev += abs(priceClose(Period - 1 - i) - Line)/Period;
        StDev += abs(priceClose(Period - 1 - i) - Mean)/Period;
    }
    
    double StDev2 = LowPass(series(StdDev(series(StDev),Period)),3);
    
    double sLRDev = SMA(series(LRDev),Period);
    
    double Threshold = LRDev;//sLRDev+StDev2;
    
    double* Mid = series(ZMA(series(priceClose()),Period));

    
    plot("M",Mid,0,BLACK);
    
    plot("sLRDev",sLRDev,1,BLUE);
    plot("StDev",StDev,0,RED);
    plot("Threshold",Threshold,0,BLACK);
    plot("STDEFV",StdDev(series(priceClose()),Period),0,GREEN);

    double* ST = series(StDev);

    if( rising(ST) ){
        if( falling(Mid) )
            enterShort();
        else if( rising(Mid) )
            enterLong();
    }
    else if( falling(ST) ){
        exitLong();
        exitShort();
    }



	
	
	
	
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