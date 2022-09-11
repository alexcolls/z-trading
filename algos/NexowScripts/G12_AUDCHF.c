// X1_v2 //

var Timeframe	= 1440;
var Timezone 	= "ET";

var X()
{
	static var AUD;
	BarPeriod = Timeframe; BarZone = Timezone;
	asset("AUD/CAD"); AUD += log(price(0))-log(price(1));
	//asset("AUD/CHF"); AUD += log(price(0))-log(price(1));
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
	static var CHF;
	BarPeriod = Timeframe; BarZone = Timezone;
	//asset("AUD/CHF"); CHF -= log(price(0))-log(price(1));
	asset("CAD/CHF"); CHF -= log(price(0))-log(price(1));
	asset("CHF/HKD"); CHF += log(price(0))-log(price(1));
	asset("CHF/JPY"); CHF += log(price(0))-log(price(1));
	asset("EUR/CHF"); CHF -= log(price(0))-log(price(1));
	asset("GBP/CHF"); CHF -= log(price(0))-log(price(1));
	asset("NZD/CHF"); CHF -= log(price(0))-log(price(1));
	asset("SGD/CHF"); CHF -= log(price(0))-log(price(1));
	asset("USD/CHF"); CHF -= log(price(0))-log(price(1));
	asset("XAG/CHF"); CHF -= log(price(0))-log(price(1));
	asset("XAU/CHF"); CHF -= log(price(0))-log(price(1));
	return CHF;
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

	asset("AUD/CHF");
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



