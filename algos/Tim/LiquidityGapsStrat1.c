

#include <nexow.h>

double Max, Min, Max2, Min2, Max3, Min3;//, RevMax, RevMin;
int Trading = 0;
int Dir = 0;
int Go = 0;

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
	PlotHeight2 = 100;
	
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
	else if( hour(0) >= 7 && hour(0) < 14 )
		Session = 2;
	else if( hour(0) >= 14 && hour(0) < 16 )	
		Session = 3;
	plot("Session",Session,NEW+BARS,RED);
	//plot("WeekDay",dow(0),NEW+BARS,BLACK);

	static double MaxWK, MinWK;
	if( dow(0) == 1 && hour(0) == 0 ){
		MaxWK = priceHigh(0);
		MinWK = priceLow(0);
	}
	if( dow(0) == 1 || dow(0) == 2 ){
		MaxWK = max(MaxWK,priceHigh(0));
		MinWK = min(MinWK,priceLow(0));
	}

	//plot("MaxWK",MaxWK,MAIN,RED);
	//plot("MinWK",MinWK,MAIN,RED);

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
		plot("Max",Max,MAIN+DOT,BLUE);
		plot("Min",Min,MAIN+DOT,BLUE);
		plot("Max*2",Max2,MAIN+DOT,BLUE);
		plot("Min*2",Min2,MAIN+DOT,BLUE);
		plot("Max*3",Max3,MAIN+DOT,BLUE);
		plot("Min*3",Min3,MAIN+DOT,BLUE);
		//plot("Max*6",RevMax,MAIN+DOT,RED);
		//plot("Min*6",RevMin,MAIN+DOT,RED);
		Trading = 1;
		Go = 0;
	}

	//plot("Beta",Dist,NEW+BARS,DARKGREEN);



	if( Trading && hour(0) >= 6 && hour(0) <= 13 ){

		if( priceClose(0) > Max ){
			Dir = -1;
		}
		else if( priceClose(0) < Min ){
			Dir = 1;
		}

		// if( priceClose(0) > RevMax ){
		// 	Dir = 2;
		// }
		// else if( priceClose(0) < RevMin ){
		// 	Dir = -2;
		// }

		if( Dir == -1 && priceClose(0) > MA ){
			enterShort(Sizes,-Max);
			enterShort(Sizes,-Max2);
			enterShort(Sizes,-Max3);
		}
		else if( Dir == 1 && priceClose(0) < MA ){
			enterLong(Sizes,-Min);	
			enterLong(Sizes,-Min2);
			enterLong(Sizes,-Min3);
		}

		// if( Dir == -2 && priceClose(0) > MA ){
		// 	enterShort(Sizes);
		// }
		// else if( Dir == 2 && priceClose(0) < MA ){
		// 	enterLong(Sizes);
		// }

	}

	if( priceClose(0) > Max3 || priceClose(0) < Min3 ){
		Go = 1;
	}
	
	if( Go && DD > 0 ){
		exitLong();
		exitShort();
		Go = 0;
	}


	if( Trading && hour(0) == 14 || FloatingDD() <= -2.5 || FloatingDD() >= 3 ){
		exitLong();
		exitShort();
		Trading = 0;
		Dir = 0;
		Go = 0;
	}

	plot("DD",FloatingDD(),NEW+BARS,RED);

}







	// if( hour(0) == 8 ){
	// 	int n = 9, i;
	// 	for( i = 0; i < n; i++ ) {
	// 		Max = max(priceHigh(i),Max);
	// 		Min = min(priceLow(i),Min);
	// 	}
	// 	// for( i = 0; i < n; i++ ) {
	// 	// 	plotGraph("Max2",i,Max,DOT,RED);
	// 	// 	plotGraph("Min2",i,Min,DOT,RED);
	// 	// }
	// }


	// const int MT = 24*40;
	// for( i = 0; i < MT; i++ ){
	// 	if( priceHigh(i) > MThi )
	// 		MThi = priceHigh(i);
	// 	if( priceLow(i) < MTlo )
	// 		MTlo = priceLow(i);
	// }
	// const int ST = 24*20;
	// for( i = 0; i < ST; i++ ){
	// 	if( priceHigh(i) > SThi )
	// 		SThi = priceHigh(i);
	// 	if( priceLow(i) < STlo )
	// 		STlo = priceLow(i);
	// }
	// // 
	// // plot("MThi",MThi,MAIN,BLUE);
	// // plot("MTlo",MTlo,MAIN,BLUE);
	// // plot("SThi",SThi,MAIN,DARKGREEN);
	// // plot("STlo",STlo,MAIN,DARKGREEN);

/*
	double Vol = 0; 
	int i, Len = 200;
	for( i = 0; i < Len; i++)
	{
		Vol += log(priceHigh(i))-log(priceLow(i));
	}
	Vol = (Vol/Len)*3;
	plot("Vol",Vol,1,RED);
	
	double cVol = abs(log(priceOpen(1))-log(priceClose(1)));
	plot("cVol",cVol,0,BLUE);

	double Line = priceClose(0);
	if( cVol > Vol ){
		if( priceClose(1) > priceOpen(1) )
			Line = (priceLow(0)+priceHigh(2))/2;
		else if( priceClose(1) < priceOpen(1) )
			Line = (priceHigh(0)+priceLow(2))/2;
	}
	plot("Line",Line,MAIN,RED);
*/
