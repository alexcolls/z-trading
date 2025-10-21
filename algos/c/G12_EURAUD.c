// X1_v2 //

asset("EUR/AUD");
var Timeframe	= 1440;
var Timezone 	= "ET";

var X()
{
	var EUR;
	BarPeriod = Timeframe; BarZone = Timezone;
	//asset("EUR/AUD"); EUR += log(price(0))-log(price(1));
	asset("EUR/CAD"); EUR += log(price(0))-log(price(1));
	asset("EUR/CHF"); EUR += log(price(0))-log(price(1));
	asset("EUR/GBP"); EUR += log(price(0))-log(price(1));
	asset("EUR/HKD"); EUR += log(price(0))-log(price(1));
	asset("EUR/JPY"); EUR += log(price(0))-log(price(1));
	asset("EUR/NZD"); EUR += log(price(0))-log(price(1));
	asset("EUR/SGD"); EUR += log(price(0))-log(price(1));
	asset("EUR/USD"); EUR += log(price(0))-log(price(1));
	asset("XAG/EUR"); EUR -= log(price(0))-log(price(1));
	asset("XAU/EUR"); EUR -= log(price(0))-log(price(1));
	return EUR;
}

var Y()
{
	var AUD;
	BarPeriod = Timeframe; BarZone = Timezone;
	asset("AUD/CAD"); AUD += log(price(0))-log(price(1));
	asset("AUD/CHF"); AUD += log(price(0))-log(price(1));
	asset("AUD/HKD"); AUD += log(price(0))-log(price(1));
	asset("AUD/JPY"); AUD += log(price(0))-log(price(1));
	asset("AUD/NZD"); AUD += log(price(0))-log(price(1));
	asset("AUD/SGD"); AUD += log(price(0))-log(price(1));
	asset("AUD/USD"); AUD += log(price(0))-log(price(1));
	//asset("EUR/AUD"); AUD -= log(price(0))-log(price(1));
	asset("GBP/AUD"); AUD -= log(price(0))-log(price(1));
	asset("XAG/AUD"); AUD -= log(price(0))-log(price(1));
	asset("XAU/AUD"); AUD -= log(price(0))-log(price(1));
	return AUD;
}

function run()
{

	StartDate = 2007;
	LookBack = 300;
	set(PLOTNOW|PARAMETERS);

	asset("EUR/AUD");
	
	var Per = 200; //optimize(20,20,300,20);
	var DP = DominantPeriod(series(price()),Per);
		
	//plot("DP",DP,1,BLACK);

	vars Xs = series(X());
	vars Ys = series(Y());
	var  Xm = Sum(Xs,DP);
	var  Ym = Sum(Ys,DP);
	
	asset("EUR/AUD");
	plot("Price",price(0),0,RED);
	
	var XY = (log(price(0))-log(price(1)))*1000;
	var XY2 = ((X()-Y())/10)*1000;
	
	plot("XY",XY,1,DARKGREEN);
	plot("XY2",XY2,0,BLACK);

	plot("X",X(),1,RED);
	plot("Y",Y(),0,BLUE);
	plot("Z",0,0,BLACK);
	
	plot("Xm",Xm,1,RED);
	plot("Ym",Ym,0,BLUE);
	plot("Zm",0,0,BLACK);

	/*
	int Signal;
	if( X>Xm && Y<Ym )
	{
		Signal = 1;
	}
	if( X<Xm && Y>Ym )
	{
		Signal = -1;
	}


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

	*/
}



