#include <r.h>

var change(int n)
{
	return scale((priceClose(0) - priceClose(n))/priceClose(0),100)/100;
}

var range(int n)
{
	return scale((HH(n) - LL(n))/priceClose(0),100)/100;
}

///////////////////////////////////////////////////////////////////////

function run()
{
	StartDate = 20140601; // start two years ago
	BarPeriod = 60; 
	LookBack = 100;

	set(RULES);
	LifeTime = 3; // prediction horizon
	Spread = RollLong = RollShort = Commission = Slippage = 0;
	
// generate the signals
	adviseLong(SIGNALS+BALANCED,0,
		change(1),change(2),change(3),change(4),
		range(1),range(2),range(3),range(4));
	enterLong(); 
}
