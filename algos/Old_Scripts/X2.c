
function run()
{
  
  StartDate = 2007;
  EndDate = 2019;
  
  BarPeriod = 1440;
  asset("EUR/USD");
   
  vars 		Prices = series(price());
  
  double		SMF = Smooth(Prices,10);
  double		LPF = LowPass(Prices, 10);
  
  double 	HPF = HighPass(Prices,10);
  double		BPF = BandPass(Prices,10,0.1);
  double		ROF = Roof(Prices,10,50);
  
  
  vars 		HPFs = series(HPF);
  vars		LPFs = series(LPF);
  

  if(falling(HPFs)) {
	  if(falling(LPFs))
	  enterShort();
  }
  
  if(rising(HPFs)) {
	  if(rising(LPFs))
	  enterLong();
  }
  
  
  plot("LPF",LPF,0,RED);
  plot("SMF",SMF,0,BLUE);
  
  plot("ROF",ROF,1,BLUE);
  plot("Threshold-1",-0.01,0,BLACK);
  plot("Threshold+1",0.01,0,BLACK);
  
  plot("HPF",HPF,1,BLUE);
  plot("Threshold-2",-0.01,0,BLACK);
  plot("Threshold+2",0.01,0,BLACK);
  
  plot("BPF",BPF,1,BLACK);
  plot("Threshold-3",-0.01,0,BLACK);
  plot("Threshold+13",0.01,0,BLACK);
  
  
  set(PLOTNOW+PRELOAD);
  
}