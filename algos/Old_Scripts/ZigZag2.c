

function run(){
	
	set(PLOTNOW);
	
	int 	_StDate  = slider(1,2015,2005,2019,"StDate");
	int 	_Period 	= slider(2,20,5,200,"EMA");
	var 	_nDevs	= slider(3,1,0.1,10,"nDev");
	
	StartDate = _StDate;
	
	static var 	Dir, Length, ZZ, Res, Sup;
	
	var 	Md = EMA(series(priceClose()),_Period);
	var 	Sd = StdDev(series(priceClose()),_Period);
	var 	Hi = ( Md + Sd*_nDevs );
	var 	Lo = ( Md - Sd*_nDevs );
	
	plot("Hi",Hi,0,RED);
	plot("Md",Md,0,GREY);
	plot("Lo",Lo,0,BLUE);
	
	if( Dir == 1 )
	{
		if( priceHigh(0) > ZZ ) 
		{
			ZZ = priceHigh(0);
			Length = 0;
		}
		if( priceClose(0) < Lo )
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
		if( priceClose(0) > Hi )
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
	
 //plot("Length",Length,1,RED);
 //plot("Dir",Dir,1,BLUE);
	
}
	

	
	
	
	
