
function TrendStrategy(){
	
	vars Prices = series(priceClose());
	var DP = DominantPeriod(Prices,optimize(500,50,1000,50));
	vars LP = series(LowPass(Prices,optimize(500,50,1000,50)));
	var Threshold = optimize(95,0,100,5);
	vars ArOsc = series(AroonOsc(optimize(50,50,1000,50)));

	Stop = ATR(DP)*optimize(5,2,10,2);
	Trail = ATR(DP)*optimize(5,2,10,2);
	
	if( !TradeIsOpen )
	{
		//Margin = 0.5 * OptimalF * Capital * sqrt(1 + ProfitClosed/Capital);
		if( ArOsc[0] > Threshold )
		{
			enterLong();
		}
		if( ArOsc[0] < -Threshold )
		{
			enterShort();
		}
	}
	
}

function run(){
	
	set(PARAMETERS+PLOTNOW);
	
	StartDate = 2005;
	BarPeriod = 60;
	LookBack = 1200;
	
	NumWFOCycles = 10; 
	DataSplit = 90;
	NumCores = 4;
	
	//Capital = 100000;
	
	if(ReTrain)
	{
		UpdateDays = -1;  
		SelectWFO = -1;
	}
	
	assetList("AssetsOandaEUR");
	while(asset(loop("EUR/USD")))
	{
		TrendStrategy();		
	}
	
}