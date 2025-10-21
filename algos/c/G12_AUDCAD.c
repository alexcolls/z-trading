// X1_v2 //

var Timeframe	= 1440;
var Timezone 	= "ET";

var X()
{
	static var AUD;
	BarPeriod = Timeframe; BarZone = Timezone;
	//asset("AUD/CAD"); AUD += log(price(0))-log(price(1));
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
	static var CAD;
	BarPeriod = Timeframe; BarZone = Timezone;
	//asset("AUD/CAD"); CAD -= log(price(0))-log(price(1));
	asset("CAD/CHF"); CAD += log(price(0))-log(price(1));
	asset("CAD/HKD"); CAD += log(price(0))-log(price(1));
	asset("CAD/JPY"); CAD += log(price(0))-log(price(1));
	asset("CAD/SGD"); CAD += log(price(0))-log(price(1));
	asset("EUR/CAD"); CAD -= log(price(0))-log(price(1));
	asset("GBP/CAD"); CAD -= log(price(0))-log(price(1));
	asset("NZD/CAD"); CAD -= log(price(0))-log(price(1));
	asset("USD/CAD"); CAD -= log(price(0))-log(price(1));
	asset("XAG/CAD"); CAD -= log(price(0))-log(price(1));
	asset("XAU/CAD"); CAD -= log(price(0))-log(price(1));
	return CAD;
}

function run()
{

	StartDate = 2007;
	LookBack = 300;
	set(PLOTNOW);

	int Period = 200;
	var Xm = LowPass(series(X()),Period);
	var Ym = LowPass(series(Y()),Period);

	plot("X",X(),1,RED);
	plot("Xm",Xm,0,RED);
	plot("Y",Y(),1,BLUE);
	plot("Ym",Ym,0,BLUE);

	int Signal;
	if( X()>Xm && Y()<Ym )
	{
		Signal = 1;
	}
	if( X()<Xm && Y()>Ym )
	{
		Signal = -1;
	}

	asset("AUD/CAD");
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

}



