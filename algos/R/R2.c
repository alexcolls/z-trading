//Example for computing trade signals in R
#include <NexowFucntions.h>

int Size = 200; // number of candles needed by the R algorithm  
/*
int RCheck()
{
   if(!Rrun()) {
     quit("R session aborted!");
     return 0;     
   }
   return 1;
}
*/
void run()
{
  BarPeriod = 60;
  LookBack = Size;
  asset("EUR/USD");  
  
  if(is(INITRUN)) {
    Rstart("MySignals.r",1);
// load all required R objects from a file in the Zorro Data folder 
    Rx(strf("load('%sData/MyObjects.bin')",slash(ZorroFolder)));
// make sure everything loaded ok
    //if(!RCheck()) return;
  }

// generate reverse price series (latest price comes last)
  vars O = rev(series(priceOpen())),
    H = rev(series(priceHigh())),
    L = rev(series(priceLow())),
    C = rev(series(priceClose()));
    
  if(!is(LOOKBACK)) {
// send the last 200 candles to R
    Rset("Open",O,Size);
    Rset("High",H,Size);
    Rset("Low",L,Size);
    Rset("Close",C,Size);

// let R compute the signal
    var Signal = Rd("Compute(Open,High,Low,Close)");
    if(!RCheck()) return;
    
    if(Signal > 0 && !NumOpenLong)
      enterLong();
    if(Signal < 0 && !NumOpenShort)
      enterShort();
  }
}
