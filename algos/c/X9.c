
function run()
{
  
  StartDate = 2005;
  EndDate = 2019;
  
  BarPeriod = 60;
  asset("GBP/USD");
  
  double 	Threshold = 0.002;
   
  vars 		Prices = series(price());
  
  double		LPF = LowPass(Prices, 120);
  double		SMF = Smooth(Prices,120);

  double 	Trend = LPF/SMF-1;
  vars		Trends = series(Trend);
  
  double 	HPF = HighPass(Prices,10);
  double		BPF = BandPass(Prices,10,0.1);
  double		ROF = Roof(Prices,10,50);
  
  Stop 	= 	4*ATR(10);
  Trail 	= 	ATR(10);
  
  if(Trends[1]>Threshold){
	  if(peak(Trends))
		  enterLong();
  }
  
  if(Trends[1]<-Threshold){
	  if(valley(Trends))
		  enterShort();
  }
   
  
  plot("Trend",Trend,1,BLUE);
  plot("Threshold-1",-Threshold,0,BLACK);
  plot("Threshold+1",Threshold,0,BLACK);
  plot("Zero",0,0,BLACK);
  
  
  set(PLOTNOW);
  
}