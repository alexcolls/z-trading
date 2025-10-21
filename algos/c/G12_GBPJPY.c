// X_Y //

string Name = "GBP/JPY";

asset(Name);
var Timeframe	= 1440;
var Timezone 	= "ET";

var X()
{
	static var GBP;
	BarPeriod = Timeframe; BarZone = Timezone;
	asset("EUR/GBP"); GBP -= log(price(0))-log(price(1));
	asset("GBP/AUD"); GBP += log(price(0))-log(price(1));
	asset("GBP/CAD"); GBP += log(price(0))-log(price(1));
	asset("GBP/CHF"); GBP += log(price(0))-log(price(1));
	asset("GBP/HKD"); GBP += log(price(0))-log(price(1));
	asset("GBP/JPY"); GBP += log(price(0))-log(price(1));
	asset("GBP/NZD"); GBP += log(price(0))-log(price(1));
	asset("GBP/SGD"); GBP += log(price(0))-log(price(1));
	asset("GBP/USD"); GBP += log(price(0))-log(price(1));
	asset("XAG/GBP"); GBP -= log(price(0))-log(price(1));
	asset("XAU/GBP"); GBP -= log(price(0))-log(price(1));
	return GBP;
	}

var Y()
{
	static var JPY;
	BarPeriod = Timeframe; BarZone = Timezone;
	asset("AUD/JPY"); JPY -= log(price(0))-log(price(1));
	asset("CAD/JPY"); JPY -= log(price(0))-log(price(1));
	asset("CHF/JPY"); JPY -= log(price(0))-log(price(1));
	asset("EUR/JPY"); JPY -= log(price(0))-log(price(1));
	asset("GBP/JPY"); JPY -= log(price(0))-log(price(1));
	asset("HKD/JPY"); JPY -= log(price(0))-log(price(1));
	asset("NZD/JPY"); JPY -= log(price(0))-log(price(1));
	asset("SGD/JPY"); JPY -= log(price(0))-log(price(1));
	asset("USD/JPY"); JPY -= log(price(0))-log(price(1));
	asset("XAG/JPY"); JPY -= log(price(0))-log(price(1));
	asset("XAU/JPY"); JPY -= log(price(0))-log(price(1));
	return JPY;
}

function run()
{

	StartDate = 2007;
	LookBack = 200;
	set(PLOTNOW|LOGFILE);

	int Period = 200;
	var Xm = LowPass(series(X()),Period);
	var Ym = LowPass(series(Y()),Period);

	int Signal;
	if( X()>Xm && Y()<Ym )
	{
		Signal = 1;
	}
	if( X()<Xm && Y()>Ym )
	{
		Signal = -1;
	}

	asset(Name);
	if( !TradeIsOpen )
	{
		if( Signal == 1 )
			enterLong();
		else if( Signal == -1 )
			enterShort();
	}
	if( TradeIsOpen && Signal == 0 )
	{
		exitLong();
		exitShort();
	}
	
	plot("X",X(),1,RED);
	plot("Xm",Xm,0,RED);
	plot("Y",Y(),1,BLUE);
	plot("Ym",Ym,0,BLUE);

}