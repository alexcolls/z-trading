// X1 //

function run()
{
  
  StartDate = 2005;
  EndDate = 2019;
  BarPeriod = 1440;
  
  LookBack = 120;
  
  PlotScale = 6;	
  set(PLOTNOW);
  set(PLOTSTATS);
    
  while(asset(loop("AUD/USD","EUR/USD","GBP/USD","NZD/USD","USD/CAD","USD/CHF","USD/SGD","USD/HKD","USD/JPY","XAG/USD","XCU/USD","XPT/USD","XAU/USD")))
  {
	  
	double* 	Price = series(price());	
	double 	Return = SMA(series(Price[0]/Price[1]-1),120);
	double 	MA1 = SMA(series(Return),120);
	double 	MA2 = SMA(series(MA1),10);
	double 	FH = FractalHigh(Price,5);
	double 	FL = FractalLow(Price,5);
  
	if(MA1>MA2)
		enterLong();
	else if(MA1<MA2) 
		enterShort();	  

	plot("FH",FH,1,RED);
	plot("FL",FL,0,BLUE);
  
	plot("Return",Return,1,GREEN);
	plot("MA1",MA1,0,BLUE);
	plot("MA2",MA2,0,RED);
	
  }
   
  
}