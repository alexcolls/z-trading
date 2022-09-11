// Strategy template ///////////////////////

function run() 
{
	set(LOGFILE);
	BarPeriod = 60;
	asset("EUR/USD");
	vars Prices = series(price());
	//... 
}