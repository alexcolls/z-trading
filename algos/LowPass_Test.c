
function LPstrat(){
	
	vars Price = series(price(0));
	
	int Period = 200;
	
	var LP = LowPass(Price,Period);
	var Dev = StdDev(Price,Period);
	var LPup = LP+Dev;
	var LPdn = LP-Dev;
	
	plot("LP",LP,0,RED);
	plot("LPu",LPup,0,RED);
	plot("LPd",LPdn,0,RED);
	
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
	
	if( Dir == 1 && price(0)>LPup )
	{
		exitLong();
		Dir = 0;
	}
	if( Dir == -1 && price(0)<LPdn )
	{
		exitShort();
		Dir = 0;
	}
	
	if( Dir == 0 )
	{
		if( price(0)>LPup )
		{
			enterShort();
		}
		if( price(0)<LPdn )
		{
			enterLong();
		}
	}
	
}

function run() 
{
	set(LEAN|PLOTNOW);
	StartDate = 2005;
	BarPeriod = 1440;
	LookBack = 200;
	
	
	
	/*
	if(is(TRAINMODE)) Detrend = CURVE;
	
	NumWFOCycles = 50;
	if(ReTrain) {
		UpdateDays = -1;
		SelectWFO = -1;
		reset(FACTORS);
		plot("Retrained",1,1,BLUE);
	}
	*/
		
	while(asset(loop(
	"AUD/CAD","AUD/CHF","AUD/HKD","AUD/JPY","AUD/NZD","AUD/SGD","AUD/USD","CAD/CHF","CAD/HKD","CAD/JPY",
	"CAD/SGD","CHF/HKD","CHF/JPY","EUR/AUD","EUR/CAD","EUR/CHF","EUR/GBP","EUR/HKD","EUR/JPY","EUR/NZD",
	"EUR/SGD","EUR/USD","GBP/AUD","GBP/CAD","GBP/CHF","GBP/HKD","GBP/JPY","GBP/NZD","GBP/SGD","GBP/USD",
	"HKD/JPY","NZD/CAD","NZD/CHF","NZD/HKD","NZD/JPY","NZD/SGD","NZD/USD","SGD/CHF","SGD/HKD","SGD/JPY",
	"USD/CAD","USD/CHF","USD/HKD","USD/JPY","USD/SGD","XAG/AUD","XAG/CAD","XAG/CHF","XAG/EUR","XAG/GBP",
	"XAG/HKD","XAG/JPY","XAG/NZD","XAG/SGD","XAG/USD","XAU/AUD","XAU/CAD","XAU/CHF","XAU/EUR","XAU/GBP",
	"XAU/HKD","XAU/JPY","XAU/NZD","XAU/SGD","XAU/USD","XAU/XAG")))
	{
		
		LPstrat();
	}
	
}
	