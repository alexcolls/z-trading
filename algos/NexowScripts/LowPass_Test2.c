function run() 
{
	
	set(LEAN|PLOTNOW);
	StartDate = 2005;
	BarPeriod = 1440;
	LookBack = 200;
	
	asset("EUR/USD");
	
	int Period = 200;
	
	vars Price = series(price(0));
	var LP = LowPass(Price,Period);
	var Dev = StdDev(Price,Period);
	vars LPup = series(LP+Dev);
	vars LPdn = series(LP-Dev);
	vars LPupm = series(LowPass(LPup,Period));
	vars LPdnm = series(LowPass(LPdn,Period));
	
	plot("LP",LP,0,RED);
	plot("LPu",LPup,0,RED);
	plot("LPd",LPdn,0,RED);
	plot("LPup",LPupm,0,BLUE);
	plot("LPdn",LPdnm,0,BLUE);
	
	if( price(0)>LPup[0] && ( crossOver(LPdn,LPdnm) or crossOver(LPup,LPupm) ) )
		enterLong();
	else if ( price(0)<LPdn[0] && ( crossUnder(LPdn,LPdnm)or crossUnder(LPup,LPupm) ) )
		enterShort();

	/*
	if( price(0)<LP )
		exitLong();
	else if( price(0)>LP )
		exitShort();
	*/
/*
	if(TradeIsOpen)
	{
		if(TradeIsLong && price(0)<LPdn)
			exitLong();
		if(TradeIsShort && price(0)>LPup)
			exitShort();
	}
	else
	{
		if( price(0)>LPup )
			enterLong();
		if( price(0)<LPdn )
			enterShort();
	}
*/
	
}

	