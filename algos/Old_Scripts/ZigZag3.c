

function run(){
	
	set(PLOTNOW);
	
	StartDate = 2005;
 //BarPeriod = 1440;
	
	static var 	Dir, Length, ZZ, Res, Sup;
	
	int 	_Period 	= slider(1,20,5,200,"EMA");
	var 	_nDevs	= slider(2,1,0.1,10,"nDev");
	int   _minLen	= slider(3,20,1,200,"minLen");
	
	var 	Md = LowPass(series(priceClose()),_Period);
	var 	Sd = StdDev(series(priceClose()),_Period);
	var 	Hi = ( Md + Sd*_nDevs );
	var 	Lo = ( Md - Sd*_nDevs );
	
	plot("Hi",Hi,0,RED);
	plot("Md",Md,0,GREY);
	plot("Lo",Lo,0,BLUE);
	
	var 	FrHi = FractalHigh(series(priceHigh()),3);
	var 	FrLo = FractalLow(series(priceLow()),3);
	
	if( FrHi>0 )
	{
		plotGraph("FrHi",1,FrHi+0.005,DOT,RED);
	}
	if( FrLo>0 )
	{
		plotGraph("FrLo",1,FrLo-0.005,DOT,BLUE);
	}
	
	
	if( Dir == 1 )
	{
		if( priceHigh(0) > ZZ ) 
		{
			ZZ = priceHigh(0);
			Length = 0;
		}
		if( ( priceClose(0) < Lo ) and ( Length >= _minLen ) )
		{
			plotGraph("ZZ",Length,ZZ,LINE,BLUE);
			Res = ZZ;
			ZZ = priceHigh(0);
			Dir = -1;
			Length = 0;
		}
		Length += 1;
	}
	else
	{
		if( priceLow(0) < ZZ ) 
		{
			ZZ = priceLow(0);
			Length = 0;
		}
		if( ( priceClose(0) > Hi ) and ( Length >= _minLen ) )
		{ 
			plotGraph("ZZ",Length,ZZ,LINE,BLUE);
			Sup = ZZ;
			ZZ = priceLow(0);
			Dir = 1;
			Length = 0;
		}
		Length += 1;
	}	
	
	plot("Res",Res,0,GREEN);
	plot("Sup",Sup,0,RED);
	plot("Mid",(Res+Sup)/2,0,GREY);
	
 //plot("Length",Length,1,RED);
 //plot("Dir",Dir,1,BLUE);
	
}
	

	
	
	
	
