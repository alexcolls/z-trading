function run(){

  set(PLOTNOW+PARAMETERS+FACTORS+LOGFILE);
  BarPeriod = 1440;
  LookBack = 1000;
  StartDate = 2007;
  NumWFOCycles = 10;  
  Capital = 100000;	

  assetList("OandaEuropeFX45");

    while(asset(loop(Assets))){
	      
      vars Price = series(price());
      var Phase = DominantPhase(Price,10);
      vars Signal = series(sin(Phase+PI/4));
      vars Dominant = series(BandPass(Price,rDominantPeriod,1));
      ExitTime = 10*rDominantPeriod;
      var Threshold = optimize(0.5,1,2)*PIP;
      
      if(ReTrain) {
        UpdateDays = -1;  
        SelectWFO = -1;	
        reset(FACTORS); 
      }
      
      
      Margin = 0.5 * OptimalF * Capital * sqrt(1 + ProfitClosed/Capital);
      if(Amplitude(Dominant,optimize(50,100,200)) > Threshold) {
        if(valley(Signal))
          reverseLong(1); 
        else if(peak(Signal))
          reverseShort(1);
      }
      
      plot("Phase",Phase,1,BLACK);
      plot("Signal",Signal,1,BLACK);
      plot("Dominant",Dominant,1,BLACK);

    }
  
}