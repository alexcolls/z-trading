 function LPstrat(var LP, var Dev, var lastclose,bool boole)
{
	
	algo("LPT");
	TimeFrame = 1;
	
	
		
	var LPup = LP+0.5*Dev;
	var LPdn = LP-0.5*Dev;
	
	
	plot("LP",LP,0,RED);
	plot("LPu",LPup,0,RED);
	plot("LPd",LPdn,0,RED);
	
	
	if( boole )
	{
		if( lastclose>LPup )
		{
			exitShort();
			boole = false;
		}
		else if( lastclose<LPdn )
		{
			exitLong();
			boole = false;
		}
	}
	
	if( !boole )
	{
		if( lastclose>LPup )
			enterLong();
		else if( lastclose<LPdn )
			enterShort();
	}
	
}
 
function run()
{
	set(PLOTNOW);
	
	BarPeriod = 1440;
	StartDate = 2007;
	LookBack = 200;

	int Period = 200;
	
	asset("EUR/USD"); vars prices = series(priceClose());
	var LP = LowPass(prices,Period);
	var Dev = StdDev(prices,Period);
	LPstrat(LP,Dev,price(0),TradeIsOpen);
	
	/*
	asset("GBP/USD"); vars prices = series(priceClose());
	var LP = LowPass(prices,Period);
	var Dev = StdDev(prices,Period);
	LPstrat(LP,Dev,price(0),TradeIsOpen);
	*/
	
	/*	
	while(loop("EUR/USD","USD/CHF","GBP/USD")) // loop through 3 assets
	{

	}
	*/
}
