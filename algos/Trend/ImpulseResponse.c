// compare the impulse responses of some low-lag MAs
function run()
{
  set(PLOTNOW);
  BarPeriod = 60;
  MaxBars = 1000;
  LookBack = 150;
  asset("");   // don't load an asset
  ColorUp = ColorDn = 0;  // don't plot a price curve
  PlotWidth = 800;
  PlotHeight1 = 400;

  var *Impulse = series(ifelse(Bar>200 && Bar<400,1,0)); // square impulse 
  int Period = 50;
  plot("Impulse",Impulse[0],0,GREY);
  plot("SMA",SMA(Impulse,Period),0,BLACK);
  plot("EMA",EMA(Impulse,Period),0,0x808000);
  plot("ALMA",ALMA(Impulse,Period),0,0x008000);
  plot("Laguerre",Laguerre(Impulse,4.0/Period),0,0x800000);
  plot("LinearReg",LinearReg(Impulse,Period),0,0x0000A0);
  plot("Hull MA",HMA(Impulse,Period),0,0x00FF00);
  plot("Zero-Lag MA",ZMA(Impulse,Period),0,0x00FFFF); 
  plot("Decycle",Decycle(Impulse,Period),0,0xFF00FF);
  plot("LowPass",LowPass(Impulse,Period),0,0xFF0000);
  plot("Smooth",Smooth(Impulse,Period),0,0x0000FF);
}