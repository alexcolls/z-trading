function run() 
{
	
	set(LEAN|PLOTNOW);
	StartDate = 2005;
	BarPeriod = 1440;
	LookBack = 200;
	
	int Period = 200;
	
	
	while(asset(loop(
	"AUD/CAD","AUD/CHF","AUD/HKD","AUD/JPY","AUD/NZD","AUD/SGD","AUD/USD","CAD/CHF","CAD/HKD","CAD/JPY",
	"CAD/SGD","CHF/HKD","CHF/JPY","EUR/AUD","EUR/CAD","EUR/CHF","EUR/GBP","EUR/HKD","EUR/JPY","EUR/NZD",
	"EUR/SGD","EUR/USD","GBP/AUD","GBP/CAD","GBP/CHF","GBP/HKD","GBP/JPY","GBP/NZD","GBP/SGD","GBP/USD",
	"HKD/JPY","NZD/CAD","NZD/CHF","NZD/HKD","NZD/JPY","NZD/SGD","NZD/USD","SGD/CHF","SGD/HKD","SGD/JPY",
	"USD/CAD","USD/CHF","USD/HKD","USD/JPY","USD/SGD","XAG/AUD","XAG/CAD","XAG/CHF","XAG/EUR","XAG/GBP",
	"XAG/HKD","XAG/JPY","XAG/NZD","XAG/SGD","XAG/USD","XAU/AUD","XAU/CAD","XAU/CHF","XAU/EUR","XAU/GBP",
	"XAU/HKD","XAU/JPY","XAU/NZD","XAU/SGD","XAU/USD","XAU/XAG")))
	{
		vars Price = series(price(0));
		var LP = LowPass(Price,Period);
		var Dev = StdDev(Price,Period);
		vars LPup = series(LP+Dev);
		vars LPdn = series(LP-Dev);
		vars LPupm = series(LowPass(LPup,Period));
		vars LPdnm = series(LowPass(LPdn,Period));
	
		if( price(0)>LPup[0] && ( crossOver(LPdn,LPdnm) or crossOver(LPup,LPupm) ) )
			enterLong();
		else if ( price(0)<LPdn[0] && ( crossUnder(LPdn,LPdnm)or crossUnder(LPup,LPupm) ) )
			enterShort();
		
		plot("LP",LP,0,RED);
		plot("LPu",LPup,0,RED);
		plot("LPd",LPdn,0,RED);
		plot("LPup",LPupm,0,BLUE);
		plot("LPdn",LPdnm,0,BLUE);
		
	}

	
	

	
	
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

	