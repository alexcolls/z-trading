

function run(){
	
	set(PLOTNOW);
	
	StartDate = 2005;
	BarPeriod = 60;
	LookBack = 1000;
	
   static var 	Dir, BSt, ZZ, Len, Res, Sup, Lev, Le2, Amp, Osc, Brs;
	
	int 	_Period 	= 20;
	var 	_nDevs	= 2;
	
	var 	Md = EMA(series(priceClose()),_Period);
	var 	Sd = StdDev(series(priceClose()),_Period);
	var 	Hi = ( Md + Sd*_nDevs );
	var 	Lo = ( Md - Sd*_nDevs );
	
	int 	Ba;
	
	if(priceClose(0)>priceOpen(0))
	{
		Ba = 1;
	}
	if(priceClose(0)<priceOpen(0))
	{
		Ba = -1;
	}
	else
	{
		Ba = 0;
	}
	
	
//	plot("Hi",Hi,0,BLUE);
//	plot("Md",Md,0,GREY);
//	plot("Lo",Lo,0,BLUE);
	
//	var   Mid = ( (Res+Sup)/2 );
//	var 	Re3 = ( Res+(Mid-Sup) );
//	var 	Re2 = ( Res+(Res-Mid) );
//	var   Su2 = ( Sup-(Mid-Sup) );
//	var   Su3 = ( Sup-(Res-Mid) );
	
//	plot("Re3",Re3,0,GREEN);
//	plot("Re2",Re2,0,RED);
//	plot("Res",Res,0,BLUE);
//	plot("Mid",Mid,0,GREY);
//	plot("Sup",Sup,0,BLUE);
//	plot("Su2",Su2,0,RED);
//	plot("Su3",Su3,0,GREEN);

	if( Dir == 1 )
	{
		if( priceHigh(0) > ZZ )
		{
			ZZ = priceHigh(0);
			BSt = 0;
		}
		if( priceClose(0) < Lo )
		{
			//plotGraph("ZZ",BSt,ZZ,LINE,GREY);
			Res = ZZ;
			Amp = ( Res - Sup );
			Lev = ( Sup + Amp*0.618 );
			Le2 = ( Sup + Amp*(1-0.618) );
			ZZ = priceHigh(0);
			Dir = -1;
			Len = BSt;
			BSt = 0;
		}
		BSt += 1;
		Len += 1;
		Osc = ( priceClose(0) / Sup -1 ) * (Len-BSt) + ( priceClose(0) / ZZ -1 ) * BSt;
	}
	else
	{
		if( priceLow(0) < ZZ ) 
		{
			ZZ = priceLow(0);
			BSt = 0;
		}
		if( priceClose(0) > Hi )
		{ 
			//plotGraph("ZZ",BSt,ZZ,LINE,GREY);
			Sup = ZZ;
			Amp = ( Res - Sup );
			Lev = ( Res - Amp*0.618 );
			Le2 = ( Res - Amp*(1-0.618) );
			ZZ = priceLow(0);
			Dir = 1;
			Len = BSt;
			BSt = 0;
		}
		BSt += 1;
		Len += 1;
		
		Osc = ( priceClose(0) / Res -1 ) * (Len-BSt) + ( priceClose(0) / ZZ -1 ) * BSt;
	}		
	
	
	// LEN & AMP Arrays
	
		vars Dirs = series(Dir,2);
	
		// LEN array
	
			vars Len_ = series(Len,2);
	
			static var LEN[10];
	
			if( Dirs[0] != Dirs[1] )
			{
				LEN[9] = LEN[8];
				LEN[8] = LEN[7];
				LEN[7] = LEN[6];
				LEN[6] = LEN[5];
				LEN[5] = LEN[4];
				LEN[4] = LEN[3];
				LEN[3] = LEN[2];
				LEN[2] = LEN[1];
				LEN[1] = LEN[0];
				LEN[0] = Len_[1];	
			}

		var LenMA  = SMA(LEN,10);
		var LenMA2 = SMA(series(Len),200);	
	
		// AMP array
		
			vars Amp_ = series(Amp,2);
	
			static var AMP[5];
	
			if( Dirs[0] != Dirs[1] )
			{
				AMP[4] = AMP[3];
				AMP[3] = AMP[2];
				AMP[2] = AMP[1];
				AMP[1] = AMP[0];
				AMP[0] = Amp_[1];	
			}

		var AmpMA  = SMA(AMP,5);
		var AmpMA2 = SMA(series(Amp),200);
	
	//
	
	
	
	var LRm = LinearReg(series(priceClose()),120);
	var LRa = LinearRegAngle(series(priceClose()),Len+1);
	var LRi = LinearRegIntercept(series(priceClose()),120);
	var LRs = LinearRegSlope(series(priceClose()),Len+1);
	
	
	plot("Lev",Lev,0,RED);
	plot("Le2",Le2,0,BLUE);


	var LPF = SMA(series(Osc),24);
	var HPF = HighPass(series(Osc),Len);
	var BPF = BandPass(series(Osc),LenMA,AmpMA);
	
	
	
	if( Dir != 0 )
	{
	plot("Osc2",LRm,0,BLUE);	
	plot("Osc3",LRi,0,RED);

	plot("Dir",Dir,1,BLACK);
	plot("Zero",0,0,BLACK);
	
	plot("Len",Len,1,BLUE);
	plot("BSt",BSt,0,BLACK);
	plot("LenMA",LenMA,0,RED);
	
	plot("Amp",Amp,1,BLUE);
	plot("AmpMA",AmpMA,0,RED);
	
	plot("Osc",LRs,1,RED);
	plot("Zero2",0,0,BLACK);
	//plot("LPF",LPF,0,RED);
	//plot("HPF",HPF,0,BLUE);
	
	

	}
	
	
	

}
	

	
	
	
	
