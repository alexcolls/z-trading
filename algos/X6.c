// helper function for finding trades at a grid line
bool findTrade(var Price,var Grid,bool IsShort) 
{
  for(open_trades)
    if((TradeIsShort == IsShort)
      and between(TradeEntryLimit,Price-Grid/2,Price+Grid/2))
        return true;
  return false;
}
  
function run() 
{
  BarPeriod = 1440;
  Hedge = 2; 
  EntryTime = ExitTime = 500;  
  var Price;
  var Grid = 100*PIP; // grid spacing
  var Current = priceClose();
// place pending trades at 5 grid lines  
// above and below the current price
  for(Price = 0; Price < Current+5*Grid; Price += Grid) {
    if(Price < Current-5*Grid)
      continue;
    if(Price < Current and !findTrade(Price,Grid,true))
      enterShort(0,Price,0,Grid);      
    else if(Price > Current and !findTrade(Price,Grid,false))
      enterLong(0,Price,0,Grid);
  }
}