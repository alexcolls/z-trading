

function run(){
	
	set(PLOTNOW);
	
	int 	_StDate  = slider(1,2015,2005,2019,"StDate");
	var 	_Depth 	= slider(2,200,1,1000,"Depth");
	int 	_Length	= slider(3,1,1,1000,"Length");
	
	StartDate = _StDate;
	
	static var 	Dir, Length, ZZ, Res, Sup;
	
	if( Dir == 1 )
	{
		if( priceHigh(0) > ZZ ) 
		{
			ZZ = priceHigh(0);
			Length = 0;
		}
		if( ( priceClose(0) <= ZZ*(1-_Depth/10000) ) and ( Length >= _Length ) )
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
		if( ( priceClose(0) >= ZZ*(1+_Depth/10000) ) and ( Length >= _Length ) )
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
	

	
	
	
	
