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
	
	//Spread = RollLong = RollShort = Commission = 0;
	
	static var EURUSD;
	
	asset("EUR/USD"); 
	EURUSD += log(price(0))-log(price(1));
	
	
	
	var EURUSDr = (EURr()-USDr());

	var EUR = EMA(series(EURr()),3);
	var USD = EMA(series(USDr()),3);
	
	var EURdev = StdDev(series(EURr()),200);
	var USDdev = StdDev(series(USDr()),200);
	
	vars EURm = series(LowPass(series(EURr()),200));
	vars USDm = series(LowPass(series(USDr()),200));
	
	var EURup = EURm[0]+EURdev;
	var EURdn = EURm[0]-EURdev;
	var USDup = USDm[0]+USDdev;
	var USDdn = USDm[0]-USDdev;
	
	var EURosc = EURr()-EURm[0];
	var USDosc = USDr()-USDm[0];
	
	/*
	vars Osc = series(EURosc-USDosc);
	var OscHP = EMA(Osc,20);
	
	plot("Osc",Osc,1,DARKGREEN);
	plot("OscHP",OscHP,0,RED);
	plot("00",0,0,BLACK);
	*/
	
	
	plot("EUR",EURr(),1,RED);
	plot("EURup",EURup,0,RED);
	plot("EURdn",EURdn,0,RED);
	plot("USD",USDr(),1,BLUE);
	plot("USDup",USDup,0,BLUE);
	plot("USDdn",USDdn,0,BLUE);
	//plot("EURUSD",EURUSD,0,BLACK);
	//plot("EURUSDr",EURUSDr,0,DARKGREEN);
	
	int Signal;
	/*
	if( falling(EURm) && rising(USDm) )
		Signal = -1;
	else if( rising(EURm) && falling(USDm) )
		Signal = 1;
	else
		Signal = 0;
	*/
	if( EURr()>EURm[0] && USDr()<USDm[0] )
		Signal = 1;
	if( EURr()<EURm[0] && USDr()>USDm[0] )
		Signal = -1;
	
	plot("Signal",Signal,1,RED);
	plot("0",0,0,BLACK);
	
	//Stop = ATR(200)*5;
	//Trail = ATR(200)*5;
	//Capital = 100000;
	Lots = 1000;
	asset("EUR/USD");
	if( !TradeIsOpen )
	{
		if( Signal == 1 )
			enterLong();
		else if( Signal == -1 )
			enterShort();
	}
	
	if( TradeIsOpen && Signal == 0 )
	{
		exitLong();
		exitShort();
	}

	

}


  
