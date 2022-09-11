// X_Y //

string Name = "AUD/USD";

asset(Name);
var Timeframe	= 1440;
var Timezone 	= "ET";

var X()
{
	static var AUD;
	BarPeriod = Timeframe; BarZone = Timezone;
	asset("AUD/CAD"); AUD += log(price(0))-log(price(1));
	asset("AUD/CHF"); AUD += log(price(0))-log(price(1));
	asset("AUD/HKD"); AUD += log(price(0))-log(price(1));
	asset("AUD/JPY"); AUD += log(price(0))-log(price(1));
	asset("AUD/NZD"); AUD += log(price(0))-log(price(1));
	asset("AUD/SGD"); AUD += log(price(0))-log(price(1));
	asset("AUD/USD"); AUD += log(price(0))-log(price(1));
	asset("EUR/AUD"); AUD -= log(price(0))-log(price(1));
	asset("GBP/AUD"); AUD -= log(price(0))-log(price(1));
	asset("XAG/AUD"); AUD -= log(price(0))-log(price(1));
	asset("XAU/AUD"); AUD -= log(price(0))-log(price(1));
	return AUD;
}

var Y()
{
	static var USD;
	BarPeriod = Timeframe; BarZone = Timezone;
	asset("AUD/USD"); USD -= log(price(0))-log(price(1));
	asset("EUR/USD"); USD -= log(price(0))-log(price(1));
	asset("GBP/USD"); USD -= log(price(0))-log(price(1));
	asset("NZD/USD"); USD -= log(price(0))-log(price(1));
	asset("USD/CAD"); USD += log(price(0))-log(price(1));
	asset("USD/CHF"); USD += log(price(0))-log(price(1));
	asset("USD/HKD"); USD += log(price(0))-log(price(1));
	asset("USD/JPY"); USD += log(price(0))-log(price(1));
	asset("USD/SGD"); USD += log(price(0))-log(price(1));
	asset("XAG/USD"); USD -= log(price(0))-log(price(1));
	asset("XAU/USD"); USD -= log(price(0))-log(price(1));
	return USD;
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