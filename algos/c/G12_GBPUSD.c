// X1_v2 //

var startDate 	= 2007;
var endDate 	= 2019;
var Period		= 1440;
var rGBP 		= 0;	
var rUSD 		= 0;	

var GBPr()
{  
  BarPeriod = Period;
  //BarZone = ET;
  //asset("GBP/USD"); rGBP += log(price(0))-log(price(1));
  asset("GBP/AUD"); rGBP += log(price(0))-log(price(1));
  asset("EUR/GBP"); rGBP += log(1/price(0))-log(1/price(1));
  asset("GBP/NZD"); rGBP += log(price(0))-log(price(1));
  asset("XAU/GBP"); rGBP += log(1/price(0))-log(1/price(1));
  asset("XAG/GBP"); rGBP += log(1/price(0))-log(1/price(1));
  asset("GBP/CAD"); rGBP += log(price(0))-log(price(1));
  asset("GBP/CHF"); rGBP += log(price(0))-log(price(1));
  asset("GBP/HKD"); rGBP += log(price(0))-log(price(1));
  asset("GBP/JPY"); rGBP += log(price(0))-log(price(1));
  asset("GBP/SGD"); rGBP += log(price(0))-log(price(1));
  return rGBP;
}

var USDr()
{  
  
  BarPeriod = Period;
  //BarZone = ET;
  //asset("GBP/USD"); rUSD += log(1/price(0))-log(1/price(1));
  asset("AUD/USD"); rUSD += log(1/price(0))-log(1/price(1));
  asset("EUR/USD"); rUSD += log(1/price(0))-log(1/price(1));
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
	//Spread = RollLong = RollShort = Commission = 0;
	
	int LPPeriod = 200;
	var GBPm = LowPass(series(GBPr()),LPPeriod);
	var USDm = LowPass(series(USDr()),LPPeriod);
	
	plot("GBP",GBPr(),1,RED);
	plot("GBPm",GBPm,0,RED);
	plot("USD",USDr(),1,BLUE);
	plot("USDm",USDm,0,BLUE);

	int Signal;
	if( GBPr()>GBPm && USDr()<USDm )
	{
		Signal = 1;
	}
	if( GBPr()<GBPm && USDr()>USDm )
	{
		Signal = -1;
	}
	
	plot("Signal",Signal,1,DARKGREEN);
	plot("0",0,0,BLACK);
	
	//Stop = ATR(200)*5;
	//Trail = ATR(200)*5;
	Lots = 100000;
	asset("GBP/USD");
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


  
