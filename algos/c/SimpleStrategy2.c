
function run(){
	
	StartDate = 2005;
	BarPeriod = 1440;
	BarZone = ET;
	set(PLOTNOW);
	
	plot("Price",price(0),0,RED);
	
	asset("AUD/USD");
	var USD = priceClose(0);
	
	while(asset(loop("EUR/AUD","GBP/AUD","XAG/AUD","XAU/AUD")))
	{
		PIPCost = PIP*USD;
		Lots = 10000/USD;
		int Dir = 0;
		for(last_trades)
		{
			if(TradeIsOpen)
			{
				if(TradeIsShort)
				{
					Dir = -1;
				}
				else
				{
					Dir = 1;
				}
			}
		}
	
		if( Dir == 1 && priceClose(0)<price(0) )
		{
			exitLong();
			Dir = 0;
		}
		if( Dir == -1 && priceClose(0)>price(0) )
		{
			exitShort();
			Dir = 0;
		}
		
		if( Dir == 0 )
		{
			if( price(0)>price(1) && priceClose(0)>price(0) )
				enterLong();
			if( price(0)<price(1) && priceClose(0)<price(0) )
				enterShort();
		}
	}

}