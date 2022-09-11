
function r()
{
	double r = log(price(0))-log(price(1));
	return r;
}

function run(){
	
	set(PLOTNOW);
	BarPeriod = 1440;
	
	static var AUD, CAD;

	asset("AUD/USD"); var r = log(price(0))-log(price(1)); AUD += r; CAD -= r;

	
	plot("AUD",AUD,1,BLUE);
	plot("CAD",CAD,0,RED);
	
}