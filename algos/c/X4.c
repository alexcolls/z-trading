// X1_v2 //

var startDate 	= 2007;
var endDate 	= 2019;
var Period		= 60;
var Length		= 10;
var CutOffLow	= 10;
var CutOffHigh	= 20;

var EURr()
{  
  var r = 0;
  BarPeriod = Period;
  asset("EUR/USD"); r += StochEhlers(series(price()),Length,CutOffLow,CutOffHigh);
  asset("EUR/AUD"); r += StochEhlers(series(price()),Length,CutOffLow,CutOffHigh);
  asset("EUR/GBP"); r += StochEhlers(series(price()),Length,CutOffLow,CutOffHigh);
  asset("EUR/NZD"); r += StochEhlers(series(price()),Length,CutOffLow,CutOffHigh);
  asset("XAU/EUR"); r += StochEhlers(series(1/price()),Length,CutOffLow,CutOffHigh);
  asset("XAG/EUR"); r += StochEhlers(series(1/price()),Length,CutOffLow,CutOffHigh);
  asset("EUR/CAD"); r += StochEhlers(series(price()),Length,CutOffLow,CutOffHigh);
  asset("EUR/CHF"); r += StochEhlers(series(price()),Length,CutOffLow,CutOffHigh);
  asset("EUR/HKD"); r += StochEhlers(series(price()),Length,CutOffLow,CutOffHigh);
  asset("EUR/JPY"); r += StochEhlers(series(price()),Length,CutOffLow,CutOffHigh);
  asset("EUR/SGD"); r += StochEhlers(series(price()),Length,CutOffLow,CutOffHigh);
  return r/11;
}

var USDr()
{  
  var r = 0;
  BarPeriod = Period;
  asset("EUR/USD"); r += StochEhlers(series(1/price()),Length,CutOffLow,CutOffHigh);
  asset("AUD/USD"); r += StochEhlers(series(1/price()),Length,CutOffLow,CutOffHigh);
  asset("GBP/USD"); r += StochEhlers(series(1/price()),Length,CutOffLow,CutOffHigh);
  asset("NZD/USD"); r += StochEhlers(series(1/price()),Length,CutOffLow,CutOffHigh);
  asset("XAG/USD"); r += StochEhlers(series(1/price()),Length,CutOffLow,CutOffHigh);
  asset("XAU/USD"); r += StochEhlers(series(1/price()),Length,CutOffLow,CutOffHigh);
  asset("USD/CAD"); r += StochEhlers(series(price()),Length,CutOffLow,CutOffHigh);
  asset("USD/CHF"); r += StochEhlers(series(price()),Length,CutOffLow,CutOffHigh);
  asset("USD/HKD"); r += StochEhlers(series(price()),Length,CutOffLow,CutOffHigh);
  asset("USD/JPY"); r += StochEhlers(series(price()),Length,CutOffLow,CutOffHigh);
  asset("USD/SGD"); r += StochEhlers(series(price()),Length,CutOffLow,CutOffHigh);
  return r/11;
}

function run() 
{

	StartDate = startDate;
	EndDate = endDate;
	LookBack = 30;
	set(PLOTNOW);  
	
	vars EURs = series(EURr());
	vars USDs = series(USDr());
	
	asset("EUR/USD");
	BarPeriod = Period;
	
	Stop = 50*PIP;
	TakeProfit = 100*PIP;
	if(peak(EURs) and EURs[1]>0.7 and valley(USDs) and USDs[1]<0.3)
		enterShort();
	else if(valley(EURs)and EURs[1]<0.3 and peak(USDs) and USDs[1]>0.7)
		enterLong();
	
	plot("EUR",EURr(),1,RED);
	plot("USD",USDr(),0,BLUE);
	plot("Down",0.1,0,BLACK);
	plot("Up",0.9,0,BLACK);
	

}


  
