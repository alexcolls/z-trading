function run()
{
	vars Price = series(price());
	vars Trend = series(LowPass(Price,100));
	
	Stop = 4*ATR(100);
	if(valley(Trend))
		enterLong();
	else if(peak(Trend))
		enterShort();
}