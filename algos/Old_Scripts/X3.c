// X1_v2 //

var startDate 	= 2007;
var endDate 	= 2019;
var Period		= 1440;
var Length		= 3;

var EURr()
{  
  var r = 0;
  BarPeriod = Period;
  //asset("EUR/USD"); r += LowPass(series(log(price(0))-log(price(1))),Length);
  asset("EUR/AUD"); r += LowPass(series(log(price(0))-log(price(1))),Length);
  asset("EUR/GBP"); r += LowPass(series(log(price(0))-log(price(1))),Length);
  asset("EUR/NZD"); r += LowPass(series(log(price(0))-log(price(1))),Length);
  asset("XAU/EUR"); r += LowPass(series(log(1/price(0))-log(1/price(1))),Length);
  asset("XAG/EUR"); r += LowPass(series(log(1/price(0))-log(1/price(1))),Length);
  asset("EUR/CAD"); r += LowPass(series(log(price(0))-log(price(1))),Length);
  asset("EUR/CHF"); r += LowPass(series(log(price(0))-log(price(1))),Length);
  asset("EUR/HKD"); r += LowPass(series(log(price(0))-log(price(1))),Length);
  asset("EUR/JPY"); r += LowPass(series(log(price(0))-log(price(1))),Length);
  asset("EUR/SGD"); r += LowPass(series(log(price(0))-log(price(1))),Length);
  return r/10;
}

var USDr()
{  
  var r = 0;
  BarPeriod = Period;
  //asset("EUR/USD"); r += LowPass(series(log(1/price(0))-log(1/price(1))),Length);
  asset("AUD/USD"); r += LowPass(series(log(1/price(0))-log(1/price(1))),Length);
  asset("GBP/USD"); r += LowPass(series(log(1/price(0))-log(1/price(1))),Length);
  asset("NZD/USD"); r += LowPass(series(log(1/price(0))-log(1/price(1))),Length);
  asset("XAG/USD"); r += LowPass(series(log(1/price(0))-log(1/price(1))),Length);
  asset("XAU/USD"); r += LowPass(series(log(1/price(0))-log(1/price(1))),Length);
  asset("USD/CAD"); r += LowPass(series(log(price(0))-log(price(1))),Length);
  asset("USD/CHF"); r += LowPass(series(log(price(0))-log(price(1))),Length);
  asset("USD/HKD"); r += LowPass(series(log(price(0))-log(price(1))),Length);
  asset("USD/JPY"); r += LowPass(series(log(price(0))-log(price(1))),Length);
  asset("USD/SGD"); r += LowPass(series(log(price(0))-log(price(1))),Length);
  return r/10;
}

function run() 
{

	StartDate = startDate;
	EndDate = endDate;
	LookBack = 100;
	set(PLOTNOW);  
		

	asset("EUR/USD");BarPeriod = Period;
	var EURUSD = ((1+(USDr()-EURr()))*price(1));
		
	plot("EURUSD",EURUSD,0,RED);

	
	plot("EUR",EURr(),1,RED);
	plot("USD",USDr(),0,BLUE);
	plot("Zero",0,0,BLACK);
	
	
		
}


  
