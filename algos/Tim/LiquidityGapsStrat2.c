

#include <nexow.h>

double Max, Min, Max2, Min2, Max3, Min3;//, RevMax, RevMin;
int Trading = 0;
int Dir = 0;
int Go = 0;
int Up = 0;
int Dn = 0;

void run() 
{
	set(PLOTNOW);
	//BarZone = "UTC";
	StartWeek = 10000;
	BarPeriod = 1;
	StartDate = 2018;
	LookBack = 1500;
	setf(PlotMode,PL_LONG+PL_FINE+PL_DIFF);
	Spread = Commission = RollLong = RollShort = Interest = 0;
	Hedge = 1;

	PlotHeight1 = 600;
	PlotHeight2 = 80;
	
	assetList("OandaEuropeIndex");
	asset("EUR_USD");

	Capital = 100000;
	double Lev = 0.01;
	int Sizes = Balance*Lev;
	double DD = FloatingDD();
	plot("Spread",marketVal(),NEW+BARS,BLUE);

	int Session = 0;
	if( hour(0) >= 22 || hour(0) >= 0 && hour(0) < 6 )
		Session = 1;
	else if( hour(0) >= 7 && hour(0) < 16 )
		Session = 2;
	else if( hour(0) >= 16 && hour(0) < 17 )	
		Session = 3;
	plot("Session",Session,NEW+BARS,RED);
	plot("WeekDay",dow(0),NEW+BARS,BLACK);

	static double MaxWK, MinWK, MidWK;
	if( dow(0) == 1 && hour(0) == 0 ){
		MaxWK = priceHigh(0);
		MinWK = priceLow(0);
		Up = Dn = 0;
	}
	MaxWK = max(MaxWK,priceHigh(0));
	MinWK = min(MinWK,priceLow(0));
	MidWK = (MaxWK+MinWK)/2;

	plot("MaxWK",MaxWK,MAIN,RED);
	plot("MinWK",MinWK,MAIN,RED);
	plot("MidWK",MidWK,MAIN,BLUE);

	const int len = 9;	
	double* Prices = series(price(),len+1);
	double MA = LowPass(Prices,len);
	plot("MA",MA,MAIN,RED);


	if( hour(0) == 6 && minute(0) == 1 ){
		Max = 0; 
		Min = 100000;
		int n = 480, i;
		for( i = 0; i < n; i++ ) {
			Max = max(priceHigh(i),Max);
			Min = min(priceLow(i),Min);
		}
		double Dist = Max-Min;
		Max2 = Max+Dist;
		Max3 = Max+Dist*2;
		Min2 = Min-Dist;
		Min3 = Min-Dist*2;
		//RevMax = Max+Dist*4;
		//RevMin = Min-Dist*4;
		//plot("Max",Max,MAIN+DOT,BLUE);
		//plot("Min",Min,MAIN+DOT,BLUE);
		//plot("Max*2",Max2,MAIN+DOT,BLUE);
		//plot("Min*2",Min2,MAIN+DOT,BLUE);
		//plot("Max*3",Max3,MAIN+DOT,BLUE);
		//plot("Min*3",Min3,MAIN+DOT,BLUE);
		//plot("Max*6",RevMax,MAIN+DOT,RED);
		//plot("Min*6",RevMin,MAIN+DOT,RED);
		Trading = 1;
	}

	if( priceOpen(0) > MidWK )
		Up++;
	else if( priceOpen(0) < MidWK )
		Dn++;
	
	plot("Up",Up,NEW+BARS,DARKGREEN+TRANSP);
	plot("Dn",Dn,BARS,ORANGE+TRANSP);

	double Osc = Up-Dn;

	plot("Osc",Osc,NEW+LINE,DARKGREEN);
	plot("0",0,LINE,BLACK);


	// if( priceHigh(0) > MidWK )
	// 	exitLong();
	// else if( priceLow(0) < MidWK )
	// 	exitShort();


	if( Osc < 0 && priceClose(0) > MA )
		enterShort(Sizes,-priceHigh(0));		
	else if( Osc > 0 && priceClose(0) > MA )
		enterLong(Sizes,-priceLow(0));

		// if( priceClose(0) > RevMax ){
		// 	Dir = 2;
		// }
		// else if( priceClose(0) < RevMin ){
		// 	Dir = -2;
		// }


		// if( Dir == -2 && priceClose(0) > MA ){
		// 	enterShort(Sizes);
		// }
		// else if( Dir == 2 && priceClose(0) < MA ){
		// 	enterLong(Sizes);
		// }

	

	if( priceHigh(0) == MaxWK || priceLow(0) == MinWK ){
		Go = 1;
	}
	
	if( Go && DD > 0 ){
		exitLong();
		exitShort();
		Go = 0;
	}


	if( Trading && hour(0) == 14 || FloatingDD() <= -2.5 || FloatingDD() >= 3 ){
		//exitLong();
		//exitShort();
		Trading = 0;
		Dir = 0;
	}

	plot("DD",FloatingDD(),NEW+BARS,RED);

}
