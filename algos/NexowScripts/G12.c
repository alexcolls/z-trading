
#define R log(price(0))-log(price(1))

function Signal(double X, double Xf, double Y, double Yf, double Z)
{
	int Sig;
	if( X>Xf+Z && Y<Yf-Z )
	{
		Sig =  1;
	}
	if( X<Xf-Z && Y>Yf+Z )
	{
		Sig = -1;
	}
	
	return Sig;
}

function run(){
	
	// Currency Returns // 
	
		StartDate = 2007;	BarPeriod = 1440; BarZone = ET;
		double r; static double AUD,CAD,CHF,EUR,GBP,HKD,JPY,NZD,SGD,USD,XAG,XAU;
		asset("AUD/CAD"); r = R; AUD += r; CAD -= r;
		asset("AUD/CHF"); r = R; AUD += r; CHF -= r;
		asset("AUD/HKD"); r = R; AUD += r; HKD -= r;
		asset("AUD/JPY"); r = R; AUD += r; JPY -= r;
		asset("AUD/NZD"); r = R; AUD += r; NZD -= r;
		asset("AUD/SGD"); r = R; AUD += r; SGD -= r;
		asset("AUD/USD"); r = R; AUD += r; USD -= r;
		asset("CAD/CHF"); r = R; CAD += r; CHF -= r;
		asset("CAD/HKD"); r = R; CAD += r; HKD -= r;
		asset("CAD/JPY"); r = R; AUD += r; JPY -= r;
		asset("CAD/SGD"); r = R; CAD += r; SGD -= r;
		asset("CHF/HKD"); r = R; CHF += r; HKD -= r;
		asset("CHF/JPY"); r = R; CHF += r; JPY -= r;
		asset("EUR/AUD"); r = R; EUR += r; AUD -= r;
		asset("EUR/CAD"); r = R; EUR += r; CAD -= r;
		asset("EUR/CHF"); r = R; EUR += r; CHF -= r;
		asset("EUR/GBP"); r = R; EUR += r; GBP -= r;
		asset("EUR/HKD"); r = R; EUR += r; HKD -= r;
		asset("EUR/JPY"); r = R; EUR += r; JPY -= r;
		asset("EUR/NZD"); r = R; EUR += r; NZD -= r;
		asset("EUR/SGD"); r = R; EUR += r; SGD -= r;
		asset("EUR/USD"); r = R; EUR += r; USD -= r;
		asset("GBP/AUD"); r = R; GBP += r; AUD -= r;
		asset("GBP/CAD"); r = R; GBP += r; CAD -= r;
		asset("GBP/CHF"); r = R; GBP += r; CHF -= r;
		asset("GBP/HKD"); r = R; GBP += r; HKD -= r;
		asset("GBP/JPY"); r = R; GBP += r; JPY -= r;
		asset("GBP/NZD"); r = R; GBP += r; NZD -= r;
		asset("GBP/SGD"); r = R; GBP += r; SGD -= r;
		asset("GBP/USD"); r = R; GBP += r; USD -= r;
		asset("HKD/JPY"); r = R; HKD += r; JPY -= r;
		asset("NZD/CAD"); r = R; NZD += r; CAD -= r;
		asset("NZD/CHF"); r = R; NZD += r; CHF -= r;
		asset("NZD/HKD"); r = R; NZD += r; HKD -= r;
		asset("NZD/JPY"); r = R; NZD += r; JPY -= r;
		asset("NZD/SGD"); r = R; NZD += r; SGD -= r;
		asset("NZD/USD"); r = R; NZD += r; USD -= r;
		asset("SGD/CHF"); r = R; SGD += r; CHF -= r;
		asset("SGD/HKD"); r = R; SGD += r; HKD -= r;
		asset("SGD/JPY"); r = R; SGD += r; JPY -= r;
		asset("USD/CAD"); r = R; USD += r; CAD -= r;
		asset("USD/CHF"); r = R; USD += r; CHF -= r;
		asset("USD/HKD"); r = R; USD += r; HKD -= r;
		asset("USD/JPY"); r = R; USD += r; JPY -= r;
		asset("USD/SGD"); r = R; USD += r; SGD -= r;
		asset("XAG/AUD"); r = R; XAG += r; AUD -= r;
		asset("XAG/CAD"); r = R; XAG += r; CAD -= r;
		asset("XAG/CHF"); r = R; XAG += r; CHF -= r;
		asset("XAG/EUR"); r = R; XAG += r; EUR -= r;
		asset("XAG/GBP"); r = R; XAG += r; GBP -= r;
		asset("XAG/HKD"); r = R; XAG += r; HKD -= r;
		asset("XAG/JPY"); r = R; XAG += r; JPY -= r;
		asset("XAG/NZD"); r = R; XAG += r; NZD -= r;
		asset("XAG/SGD"); r = R; XAG += r; SGD -= r;
		asset("XAG/USD"); r = R; XAG += r; USD -= r;
		asset("XAU/AUD"); r = R; XAU += r; AUD -= r;
		asset("XAU/CAD"); r = R; XAU += r; CAD -= r;
		asset("XAU/CHF"); r = R; XAU += r; CHF -= r;
		asset("XAU/EUR"); r = R; XAU += r; EUR -= r;
		asset("XAU/GBP"); r = R; XAU += r; GBP -= r;
		asset("XAU/HKD"); r = R; XAU += r; HKD -= r;
		asset("XAU/JPY"); r = R; XAU += r; JPY -= r;
		asset("XAU/NZD"); r = R; XAU += r; NZD -= r;
		asset("XAU/SGD"); r = R; XAU += r; SGD -= r;
		asset("XAU/USD"); r = R; XAU += r; USD -= r;
		asset("XAU/XAG"); r = R; XAU += r; XAG -= r;
	
	//
	
	
	// Currency Filter //
	
		int FiltPer = 200;
		
		double AUDf = LowPass(series(AUD),FiltPer);
		double CADf = LowPass(series(CAD),FiltPer);
		double CHFf = LowPass(series(CHF),FiltPer);
		double EURf = LowPass(series(EUR),FiltPer);
		double GBPf = LowPass(series(GBP),FiltPer);
		double HKDf = LowPass(series(HKD),FiltPer);
		double JPYf = LowPass(series(JPY),FiltPer);
		double NZDf = LowPass(series(NZD),FiltPer);
		double SGDf = LowPass(series(SGD),FiltPer);
		double USDf = LowPass(series(USD),FiltPer);
		double XAGf = LowPass(series(XAG),FiltPer);
		double XAUf = LowPass(series(XAU),FiltPer);
		
		int MeanPer = 10;
		
		double EURm = SMA(series(EUR),MeanPer);
		double USDm = SMA(series(USD),MeanPer);
		

	//

	// Trading Conditions //
	
		
		

	// AUDCAD 
		
	asset("AUD/CAD");
	
/*
	if(TradeIsShort)
	{
		if( AUD > AUDf && CAD < CADf )
			enterLong();
	}
	if(TradeIsLong)
	{
		if( AUD < AUDf && CAD > CADf )
			enterShort();
	}
		*/

	// EUR/USD 
	
		asset("EUR/USD");
		
		int Sig = Signal(EUR,EURf,USD,USDf,0.1);
		
		double EURUSDf = LowPass(series(price()),200);
		plot("EURUSDf",EURUSDf,0,RED);
		
		int Dir;
		for(last_trades)
		{
			if(TradeIsOpen)
			{
				if(TradeIsShort)
				{
					Dir = -1;
				}
				else
				{
					Dir = 1;
				}
			}
		}
		if( Dir != 0 && Sig == 0 )
		{
			exitLong();
			exitShort();
		}
		if( Dir == 0 )
		{
			if( Sig == 1 )
				enterLong();
			if( Sig == -1 )
				enterShort();
		}
	
	//
	
	set(PLOTNOW);
		
		plot("EURg",EURf,1,RED);
		plot("EURm",EURm,0,RED);
		plot("EUR",EUR,0,RED);
		plot("USDf",USDf,1,BLUE);
		plot("USDm",USDm,0,BLUE);
		plot("USD",USD,0,BLUE);
	
}