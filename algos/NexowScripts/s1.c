
function run(){
	
	set(PLOTNOW);
	StartDate = 2007;
	BarPeriod = 1440;
	BarZone = UTC;
	
	double Xr,Yr;
	double Threshold = 0.005;
	
	asset("XAU/USD");
		//exitLong(); exitShort();
		Xr = ( priceClose(0)/priceClose(1)-1 );
		
	asset("XAG/USD"); 
		//exitLong(); exitShort();
		Yr = ( priceClose(0)/priceClose(1)-1 );
		
		
	var Diff = ( Xr-Yr );	
	
	if(Diff>Threshold)
	{
		asset("XAU/USD");
			Lots = ( 1000/priceClose(0) );
			//enterShort();
		asset("XAG/USD");
			Lots = ( 1000/priceClose(0) );
			//enterLong();
	}
	
	if(Diff<-Threshold)
	{
		asset("XAU/USD");
			Lots = ( 1000/priceClose(0) );
			//enterShort();
		asset("XAG/USD");
			//Lots ( 1000/priceClose(0) );
			//enterShort();
	}

	plot("Diff",Diff,1,RED);
	plot("T+",Threshold,0,BLACK);
	plot("T-",-Threshold,0,BLACK);	
	
}