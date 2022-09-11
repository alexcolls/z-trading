// Counter trend trading function
function tradeCounterTrend()
{
  TimeFrame = optimize(4,2,12,2);	// 4 hour time frame
  vars Price = series(price(0));
  vars Filtered = series(BandPass(Price,optimize(10,10,50,10),0.5));
  vars Signal = series(FisherN(Filtered,500));
  var Threshold = optimize(0.5,0.5,2,0.25);

  Stop = optimize(2,2,10,2) * ATR(100);
  Trail = optimize(2,2,10,2) * ATR(100);

  if(crossUnder(Signal,-Threshold))
    enterLong();
  else if(crossOver(Signal,Threshold))
    enterShort();
}

// Trend trading function
function tradeTrend()
{
  TimeFrame = optimize(1,2,12,2); // 1 hour time frame
  vars Price = series(price(0));
  vars Trend = series(LowPass(Price,optimize(100,100,500,100)));
  
  Stop = optimize(2,2,10,2) * ATR(100);
  Trail = optimize(2,2,10,2) * ATR(100);

  vars MMI_Raw = series(MMI(Price,300));
  vars MMI_Smooth = series(LowPass(MMI_Raw,500));
  
  if(falling(MMI_Smooth)) {
    if(valley(Trend))
      enterLong();
    else if(peak(Trend))
      enterShort();
  }
}

function run()
{
  set(PARAMETERS+FACTORS+LOGFILE);
  BarPeriod = 60; 
  LookBack = 10000;
  StartDate = 2005;
  NumWFOCycles = 10;  
  Capital = 100000;	

  if(ReTrain) {
    UpdateDays = -1;  
    SelectWFO = -1;	
    reset(FACTORS); 
  }
  
 
// double portfolio loop

  assetList("AssetsOanda");
  while(asset(loop("EUR/USD","USD/JPY","AUD/USD","GBP/USD","NZD/USD","USD/CAD","USD/CHF","USD/HKD","USD/SGD","XAU/USD","XAG/USD")))
  while(algo(loop("TRND","CNTR")))
  {
    Margin = 0.5 * OptimalF * Capital * sqrt(1 + ProfitClosed/Capital);
    if(Algo == "TRND") 
      tradeTrend();
    else if(Algo == "CNTR") 
      tradeCounterTrend();
  }
}