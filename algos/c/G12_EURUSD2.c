// X1_v2 //

var startDate 	= 2007;
var endDate 	= 2019;
var Period		= 1440;
var rEUR 		= 0;	
var rUSD 		= 0;	

var EURr()
{  
  BarPeriod = Period;
  //BarZone = ET;
  //asset("EUR/USD"); rEUR += log(price(0))-log(price(1));
  asset("EUR/AUD"); rEUR += log(price(0))-log(price(1));
  asset("EUR/GBP"); rEUR += log(price(0))-log(price(1));
  asset("EUR/NZD"); rEUR += log(price(0))-log(price(1));
  asset("XAU/EUR"); rEUR += log(1/price(0))-log(1/price(1));
  asset("XAG/EUR"); rEUR += log(1/price(0))-log(1/price(1));
  asset("EUR/CAD"); rEUR += log(price(0))-log(price(1));
  asset("EUR/CHF"); rEUR += log(price(0))-log(price(1));
  asset("EUR/HKD"); rEUR += log(price(0))-log(price(1));
  asset("EUR/JPY"); rEUR += log(price(0))-log(price(1));
  asset("EUR/SGD"); rEUR += log(price(0))-log(price(1));
  return rEUR;
}

var USDr()
{  
  
  BarPeriod = Period;
  //BarZone = ET;
  //asset("EUR/USD"); rUSD += log(1/price(0))-log(1/price(1));
  asset("AUD/USD"); rUSD += log(1/price(0))-log(1/price(1));
  asset("GBP/USD"); rUSD += log(1/price(0))-log(1/price(1));
  asset("NZD/USD"); rUSD += log(1/price(0))-log(1/price(1));
  asset("XAG/USD"); rUSD += log(1/price(0))-log(1/price(1));
  asset("XAU/USD"); rUSD += log(1/price(0))-log(1/price(1));
  asset("USD/CAD"); rUSD += log(price(0))-log(price(1));
  asset("USD/CHF"); rUSD += log(price(0))-log(price(1));
  asset("USD/HKD"); rUSD += log(price(0))-log(price(1));
  asset("USD/JPY"); rUSD += log(price(0))-log(price(1));
  asset("USD/SGD"); rUSD += log(price(0))-log(price(1));
  return rUSD;
}

function run() 
{

	StartDate = startDate;
	EndDate = endDate;
	LookBack = 300;
	set(PLOTNOW);  
	
	//Capital = 100000;
	Spread = RollLong = RollShort = Commission = 0;
	
	vars EURm = series(EURr());
	vars USDm = series(USDr());
	
	plot("EUR",EURr(),1,RED);
	plot("USD",USDr(),1,BLUE);

	int Signal;
	if( rising(EURm) && falling(USDm) )
	{
		Signal = -1;
	}
	if( rising(USDm) && falling(EURm) )
	{
		Signal = 1;
	}
	
	plot("Signal",Signal,1,DARKGREEN);
	plot("0",0,0,BLACK);
	
	TakeProfit = ATR(200)*2;
	Stop = ATR(200)*2;
	//Trail = ATR(200)*1;
	Lots = 100000;
	asset("EUR/USD");

	if( Signal == 1 )
		enterLong();
	else if( Signal == -1 )
		enterShort();

	
	if( TradeIsOpen && Signal == 0 )
	{
		exitLong();
		exitShort();
	}


}


  
