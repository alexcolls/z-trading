



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

{
	static var CAD;
	BarPeriod = Timeframe; BarZone = Timezone;
	asset("AUD/CAD"); CAD -= log(price(0))-log(price(1));
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

{
	static var CHF;
	BarPeriod = Timeframe; BarZone = Timezone;
	asset("AUD/CHF"); CHF -= log(price(0))-log(price(1));
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

{
	static var EUR;
	BarPeriod = Timeframe; BarZone = Timezone;
	asset("EUR/AUD"); EUR += log(price(0))-log(price(1));
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







