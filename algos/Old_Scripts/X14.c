

function run(){
	
	set(PLOTNOW);
	
	StartDate = 2010;
	BarPeriod = 60;
	LookBack = 3000;
	

	// Bollinger Bands //
	
		int 	_Period 	= 120;
		var 	_nDevs	= 2;

		var 	Md = EMA(series(priceClose()),_Period);
		var 	Sd = StdDev(series(priceClose()),_Period);
		var 	Hi = ( Md + Sd*_nDevs );
		var 	Lo = ( Md - Sd*_nDevs );
	
	//
	
	// Zig Zag //
	
		static var 	Dir, ZZ, ZZ1, ZZ2, ZZ3, ZZ4, Len, Len1, Len2, Len3, Len4, Amp, Amp1, Amp2, Amp3, Amp4, Pow, Pow1, Pow2, Pow3, Pow4, Lev, Res, Sup;
		
		var Proportion = 0.382;
		
		if( Dir == 1 )
		{
			if( priceClose(0) > ZZ )
			{
				ZZ = priceClose(0);
				Len1 = ( Len1 + Len + 1 );
				Len = 0;
				Amp1 = ( ZZ - ZZ1 );
				Amp = 0;
				Pow1 = ( Pow1 + Pow + 1 );
				Pow = 0;
				Sup = ( ZZ - ( Amp1 * Proportion ) );
			}
			if( priceClose(0) < ZZ )
			{
			Len += 1;
			if( Amp < ( ZZ - priceClose(0) ) )
				Amp = ( ZZ - priceClose(0) );
			if( priceClose(0) > priceOpen(0) ) 
				Pow += 1;
			if( priceClose(0) < priceOpen(0) )
				Pow -= 1;
			}
			if( ( priceClose(0) < Lo ) or ( priceClose(0) < Lev ) )
			{
				//plotGraph("ZZ",BSt,ZZ,LINE,GREY);
				ZZ4 = ZZ3;
				ZZ3 = ZZ2;
				ZZ2 = ZZ1;
				ZZ1 = ZZ;
				ZZ = priceClose(0);
				Len4 = Len3;
				Len3 = Len2;
				Len2 = Len1;
				Len1 = Len;
				Len = 0;
				Amp4 = Amp3;
				Amp3 = Amp2;
				Amp2 = Amp1;
				Amp1 = Amp;
				Amp = 0;
				Pow4 = Pow3;
				Pow3 = Pow2;
				Pow2 = Pow1;
				Pow1 = Pow;
				Pow = 0;
				Lev = ( ZZ1 - Amp1 * 0.5 );
				Dir = -1;
			}
		}
		else
		{
			if( priceClose(0) < ZZ ) 
			{
				ZZ = priceClose(0);
				Len1 = ( Len1 + Len + 1 );
				Len = 0;
				Amp1 = ( ZZ1 - ZZ );
				Amp = 0;
				Pow1 = ( Pow1 + Pow - 1 );
				Pow = 0;
				Res = ( ZZ + ( Amp1 * Proportion ) );
			}
			if( priceClose(0) > ZZ )
			{
				Len += 1;
				if( Amp < ( priceClose(0) - ZZ ) )
					Amp = ( priceClose(0) - ZZ );
				if( priceClose(0) > priceOpen(0) ) 
					Pow += 1;
				if( priceClose(0) < priceOpen(0) )
					Pow -= 1;
			}
			if( ( priceClose(0) > Hi ) or ( priceClose(0) > Lev ) )
			{ 
				//plotGraph("ZZ",BSt,ZZ,LINE,GREY);
				ZZ4 = ZZ3;
				ZZ3 = ZZ2;
				ZZ2 = ZZ1;
				ZZ1 = ZZ;
				ZZ = priceClose(0);
				Len4 = Len3;
				Len3 = Len2;
				Len2 = Len1;
				Len1 = Len;
				Len = 0;
				Amp4 = Amp3;
				Amp3 = Amp2;
				Amp2 = Amp1;
				Amp1 = Amp;
				Amp = 0;
				Pow4 = Pow3;
				Pow3 = Pow2;
				Pow2 = Pow1;
				Pow1 = Pow;
				Pow = 0;
				Lev = ( ZZ1 + Amp1 * 0.5 );
				Dir = 1;
			}
		}
		
		plot("Lev",Lev,0,GREY);
		plot("Sup",Sup,0,BLUE);
		plot("Res",Res,0,RED);
		
		plot("Pow",Pow,1,RED);
		plot("Pow1",Pow1,0,BLUE);
		plot("Pow2",Pow2,0,GREEN);
		plot("Pow3",Pow3,0,GREY);
		plot("Pow4",Pow4,0,PURPLE);
		plot("ZeroPow",0,0,BLACK);
		
		plot("Amp",Amp,1,RED);
		plot("Amp1",Amp1,0,BLUE);
		plot("Amp2",Amp2,0,GREEN);
		plot("Amp3",Amp3,0,GREY);
		plot("Amp4",Amp4,0,PURPLE);
		plot("ZeroAmp",0,0,BLACK);
		
		plot("Len",Len,1,RED);
		plot("Len1",Len1,0,BLUE);
		plot("Len2",Len2,0,GREEN);
		plot("Len3",Len3,0,GREY);
		plot("Len4",Len4,0,PURPLE);
		plot("ZeroLen",0,0,BLACK);
	//

	/*
	
	// Market Conditions //
	
			int LenC = Len1 - Len - Len2 + Len3 - Len4;
			int AmpC = Amp1/PIP - Amp/PIP - Amp2/PIP + Amp3/PIP - Amp4/PIP;
			int PowC = Pow1 - Pow - Pow2 + Pow3 - Pow4;
	
		if( Dir == -1 )
			PowC = -PowC;
			
		plot("PowC",PowC,1,BLUE);
		plot("PowZero",0,0,RED);
			
			
		plot("AmpC",AmpC,1,BLUE);
		plot("AmpZero",0,0,RED);
	
		plot("LenC",LenC,1,BLUE);
		plot("LenZero",0,0,RED);
	
	*/
	
	
	/*
	// Standard Deviation //
		
		var Return = log(priceClose(0))-log(priceOpen(0));
		
		vars Returns = series(Return);
	
		var Mean = SMA(Returns,Len);
		
		var SumDev;
		
		var i;
	
		for(i = 0; i<Len; i++)
		{
			SumDev += Returns[Len - i] - Mean;
		}	
		
		//var StDev = sqrt( pow(SumDev,2) / ( Len -1 ) );
		
		var StDev2 = StdDev(Returns,Len);
		
		//plot("StDev",StDev,1,RED);
		plot("StDev2",StDev2,1,BLUE);
		
	//
	*/
	
	/*
	
	// Linear Regression //
	
		static var i;
	
		var Slope = ( priceClose(0)-ZZ1 ) / ( Len - 1 );
		var LRDev, LROsc, LRInd;
	
		for(i = 0; i<Len; i++)
		{
			var Line = ZZ1+(Slope*i);
			LRDev += abs(priceClose(Len - 1 - i) - Line);
			LROsc += priceClose(Len - 1 - i) - Line;
			if( priceClose(Len - 1 - i) - Line > 0 )
				LRInd += 1;
			if( priceClose(Len - 1 - i) - Line < 0 ) 
				LRInd -= 1;
		}	
		
		LRDev = ( LRDev / Len );
		
	
	//
	*/
	
	if( Dir != 0 )
	{
		/*
		plot("LRInd1",LRInd1,1,RED);
		plot("i1",(Len-1)*Dir,0,BLUE);
		plot("Z1",0,0,BLACK);
		*/
		/*
		plot("Slope",Slope,1,RED);
		plot("LROsc",LROsc,1,BLUE);
		plot("LRInd",LRInd,0,RED);
		plot("i",(Len-1)*-Dir,0,BLUE);
		plot("Z",0,0,BLACK);
		*/
	}

	

		
		
	/*
	
	if( Dir == 1 )
	{
		if( TrueRange()>ATR(120)*3 and priceClose(0)>priceOpen(0) )
		{
			enterLong();
		}
		if( TrueRange()>ATR(120)*3 and priceClose(0)<priceOpen(0) )
		{
			exitLong();
		}
	}
	if( Dir == -1 )
	{
		if( TrueRange()>ATR(120)*3 and priceClose(0)<priceOpen(0) )
		{
			enterShort();
		}
		if( TrueRange()>ATR(120)*3 and priceClose(0)>priceOpen(0) )
		{
			exitShort();
		}
	}
	*/
	
}
	
	
	
	
