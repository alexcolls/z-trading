
//////////////////////////////////////// \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
///                                                                           \\\
///  ### Long-Short Cointegration Strategy -> OandaEurope Equity Indices ###  \\\
///                                                                           \\\
/// 		Copyright © 2019 Nexow Systems, S.L. All rights reserved.         \\\
//////////////////////////////////////// \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

#include <nexow.h>

/* Global Parameters */

#define ASSETLIST "OandaEuropeIndex"
#define ACC_CURR "USD"
#define ASSETS 16
#define PAIRS 120
#define QUOTE_CCYs 6
#define BARS 60
#define PERIODS 500
#define MARGIN 100000
#define NOPPS 1
#define SELECTALGO 1
#define PRINT FALSE

/* Data structs */

typedef struct{
    char sym[10];
	int year;
	int start;
	int end;
} info;
info infos[ASSETS];
void printInfos(){
	int i; printf("\n### INFOS ###");
	for( i = 0; i < ASSETS; i++ ){
		printf("\ni= %d, .sym= %s, .year= %d, .start= %d, .end= %d", i, infos[i].sym, infos[i].year, infos[i].start, infos[i].end);
	}
	printf("\n");
}

typedef struct{
    string sym1;
	string sym2;
	char algo[5];
	double val;
	int dir;
	int year;
	int start;
	int end;
} pair;
pair pairs[PAIRS];
void printPairs(){
	int i; printf("\n### PAIRS ###");
	for( i = 0; i < PAIRS; i++ ){
		printf("\ni= %d, .sym1= %s, .sym2= %s, .algo= %s, .val= %f, .dir= %d, .year= %d, .start= %d, .end= %d", i, pairs[i].sym1, pairs[i].sym2, pairs[i].algo, pairs[i].val, pairs[i].dir, pairs[i].year, pairs[i].start, pairs[i].end);
	}
	printf("\n");
}

typedef struct{
	char algo[5];
    string syms[2];
	double ba;
	vars eq;
	vars f1;
	double f2;
	int ls;
	int ws;
	int Ls;
	int Ws;
} algos;
algos algostats[PAIRS];
/*
void printAlgos(){
	int i; printf("\n### ALGOS ###");
	for( i = 0; i < PAIRS; i++ ){
		printf("\ni= %d, .algo= %s, .sym1= %s, .sym2= %s, .eq= %f, .f1= %f, .f2= %f", i, algostats[i].algo, algostats[i].syms[0], algostats[i].syms[1], algostats[i].eq, algostats[i].f1, algostats[i].f2);
	}
	printf("\n");
}
*/
typedef struct{
    char ccy[4];
	char cross[8];
	int inver;
    double rate;
} fxr;
fxr FX[QUOTE_CCYs];
int nCCY = 1;
void printFx(){
	int i; printf("\n### FX ###");
	for( i = 0; i < QUOTE_CCYs; i++ ){
		printf("\ni= %d, .ccy= %s, .cross= %s, .inver= %d, .rate= %f", i, FX[i].ccy, FX[i].cross, FX[i].inver, FX[i].rate);
	}
	printf("\n");
}

typedef struct{
	string sym;
	char ccy[4];
	double prs[PERIODS];
} symprs;
symprs Vec[ASSETS];
void printVec( int prsRows ){
	int i, j; printf("\n### VEC ###");
	for( i = 0; i < ASSETS; i++ ){
		printf("\ni= %d, .sym= %s, .ccy= %s", i, Vec[i].sym, Vec[i].ccy);
		for (j = 0; j < prsRows; j++){
			printf("\n.       %d.prs= %f", j, Vec[i].prs[j]);
		}
	}
	printf("\n");
}

/* Functions */

void initInfos(){
	int ass = 0;
	/* AU200_AUD */
	strcpy(infos[ass].sym,"AU200_AUD");
	infos[ass].year = 2006;
	infos[ass].start = 0;
	infos[ass].end = 16;
	/* CN50_USD */ ass = 1;
	strcpy(infos[ass].sym,"CN50_USD");
	infos[ass].year = 2012;
	infos[ass].start = 1;
	infos[ass].end = 17;
	/* EU50_EUR */ ass = 2;
	strcpy(infos[ass].sym,"EU50_EUR");
	infos[ass].year = 2006;
	infos[ass].start = 6;
	infos[ass].end = 20;
	/* FR40_EUR */ ass = 3;
	strcpy(infos[ass].sym,"FR40_EUR");
	infos[ass].year = 2006;
	infos[ass].start = 7;
	infos[ass].end = 20;
	/* DE30_EUR */ ass = 4;
	strcpy(infos[ass].sym,"DE30_EUR");
	infos[ass].year = 2006;
	infos[ass].start = 6;
	infos[ass].end = 20;
	/* HK33_HKD */ ass = 5;
	strcpy(infos[ass].sym,"HK33_HKD");
	infos[ass].year = 2006;
	infos[ass].start = 1;
	infos[ass].end = 17;
	/* IN50_USD */ ass = 6;
	strcpy(infos[ass].sym,"IN50_USD");
	infos[ass].year = 2012;
	infos[ass].start = 2;
	infos[ass].end = 20;
	/* JP225_USD */ ass = 7;
	strcpy(infos[ass].sym,"JP225_USD");
	infos[ass].year = 2006;
	infos[ass].start = 0;
	infos[ass].end = 20;
	/* NL25_EUR */ ass = 8;
	strcpy(infos[ass].sym,"NL25_EUR");
	infos[ass].year = 2008;
	infos[ass].start = 7;
	infos[ass].end = 19;
	/* SG30_SGD */ ass = 9;
	strcpy(infos[ass].sym,"SG30_SGD");
	infos[ass].year = 2006;
	infos[ass].start = 0;
	infos[ass].end = 20;
	/* TWIX_USD */ ass = 10;
	strcpy(infos[ass].sym,"TWIX_USD");
	infos[ass].year = 2012;
	infos[ass].start = 0;
	infos[ass].end = 20;
	/* UK100_GBP */ ass = 11;
	strcpy(infos[ass].sym,"UK100_GBP");
	infos[ass].year = 2006;
	infos[ass].start = 0;
	infos[ass].end = 20;
	/* NAS100_USD */ ass = 12;
	strcpy(infos[ass].sym,"NAS100_USD");
	infos[ass].year = 2006;
	infos[ass].start = 0;
	infos[ass].end = 20;
	/* US2000_USD */ ass = 13;
	strcpy(infos[ass].sym,"US2000_USD");
	infos[ass].year = 2006;
	infos[ass].start = 0;
	infos[ass].end = 20;
	/* SPX500_USD */ ass = 14;
	strcpy(infos[ass].sym,"SPX500_USD");
	infos[ass].year = 2006;
	infos[ass].start = 0;
	infos[ass].end = 20;
	/* US30_USD */ ass = 15;
	strcpy(infos[ass].sym,"US30_USD");
	infos[ass].year = 2006;
	infos[ass].start = 0;
	infos[ass].end = 20;
}

void initPairs(){
	if( is(INITRUN) ){
		int k = 0, i = 0, j = 1;
		while(asset(loop(Assets))){
			if( !IsFX() ){
				for( i = 0; i < ASSETS-j; i++ )
					pairs[k+i].sym1 = Symbol;
				k = k+i;
				j++;
			}
		}
		k = 0;
		for( i = 0; i < ASSETS; i++ ){
			j = 0;
			while(asset(loop(Assets))){
				if( !IsFX() ){
					if( j > i ){
						pairs[k].sym2 = Symbol;
						char id[4];
						itoa((k+1),id);
						char algo[5];
						strcpy(algo,"");
						strcat(algo,"X");
						strcat(algo,id);
						strcpy(pairs[k].algo,algo);
						k++;
					}
					j++;
				}
			}
		}
		for( k = 0; k < PAIRS; k++ ){
			int y1, s1, e1, y2, s2, e2;
			for( i = 0; i < ASSETS; i++ ){
				if( strstr(infos[i].sym,pairs[k].sym1) ){
					y1 = infos[i].year;
					s1 = infos[i].start;
					e1 = infos[i].end;
				}
				else if( strstr(infos[i].sym,pairs[k].sym2) ){
					y2 = infos[i].year;
					s2 = infos[i].start;
					e2 = infos[i].end;
				}
			}
			pairs[k].year = max(y1, y2);
			pairs[k].start = max(s1,s2);
			pairs[k].end = min(e1,e2);
		}
	}
}

void initAlgoStats(){
	int p;
	for( p = 0; p < PAIRS; p++ ){
		strcpy(algostats[p].algo ,pairs[p].algo);
		algostats[p].syms[0] = pairs[p].sym1;
		algostats[p].syms[1] = pairs[p].sym2;
	}
}

void updateAlgoStats(){
	int p, k;
	for( p = 0; p < PAIRS; p++ ){
		if( !SELECTALGO || SELECTALGO == p+1 ){
			double AlgoEQ = 0, AlgoBA = 0;
			int AlgoLS = 0, AlgoWS = 0;
			double AlgoLLS = 0, AlgoWWS = 0;
			algo(algostats[p].algo);
			for( k = 0; k < 2; k++ ){
				asset(algostats[p].syms[k]);
				AlgoEQ += EquityLong+EquityShort;
				AlgoBA += BalanceLong+BalanceShort;
				AlgoWS += WinStreakLong+WinStreakShort;
				AlgoLS += LossStreakLong+LossStreakShort;
				AlgoWWS += WinStreakValLong+WinStreakValShort;
				AlgoLLS += LossStreakValLong+LossStreakValShort;
			}
			algostats[p].eq = series(AlgoEQ);
			algostats[p].ba = AlgoBA;
			algostats[p].f1 = series(EMA(algostats[p].eq,120));
			algostats[p].f2 = LowPass(algostats[p].f1,100000);
			algostats[p].ls = AlgoLS;
			algostats[p].ws = AlgoWS;
			algostats[p].Ls = AlgoLLS;
			algostats[p].Ws = AlgoWWS;
		}
	}
}

string getQuoteCCY(){
	string Quote = "";
	strcpy(Quote,Symbol+strlen(Symbol)-3);
	return Quote;
}

void updateFXrates(){
	if( is(INITRUN) ){
		strcpy(FX[0].ccy,ACC_CURR);
		FX[0].rate = 1.0;
		while(asset(loop(Assets))){
			if( !IsFX() ){
				string QuoteCCY = getQuoteCCY();
				int i; bool isListed = FALSE; 
				for( i = 0; i < nCCY; i++ ){
					if( strstr(FX[i].ccy,QuoteCCY) ){
						isListed = TRUE;
						break;
					}
				}
				if( !isListed ){
					strcpy(FX[nCCY].ccy,QuoteCCY);
					nCCY++;
				}
			}
		}
		int i;
		for( i = 1; i < nCCY; i++ ){
			char FXcross[10];
			strcpy(FXcross,"");
			strcat(FXcross,FX[i].ccy);
			strcat(FXcross,"_");
			strcat(FXcross,ACC_CURR);
			if( asset(FXcross) ){
				strcpy(FX[i].cross,FXcross);
				FX[i].inver = 0;
			}
			else{
				char FXinver[10];
				strcpy(FXinver,"");
				strcat(FXinver,ACC_CURR);
				strcat(FXinver,"_");
				strcat(FXinver,FX[i].ccy);
				if( asset(FXinver) ){
					strcpy(FX[i].cross,FXinver);
					FX[i].inver = 1;
				}
			}
		}
	}
	int i; string CurrSym = Symbol;
	for( i = 1; i < nCCY; i++ ){
		asset(FX[i].cross);
		if( FX[i].inver )
			FX[i].rate = 1/price(0);
		else FX[i].rate = price(0);
	}
	asset(CurrSym);
}

double getFXrate(){
	int i; string QuoteCCY = getQuoteCCY();
	for( i = 0; i < nCCY; i++ ){
		if( strstr(FX[i].ccy,QuoteCCY) )
			return FX[i].rate; }
	return 0;
}

void updateVec(){
	if( is(INITRUN) ){
		int k = 0;
		while(asset(loop(Assets))){
			if( !IsFX() ){
				Vec[k].sym = Symbol;
				string QuoteCCY = getQuoteCCY();
				strcpy(Vec[k].ccy,QuoteCCY);
				k++;
			}
		}
	}
	int k, i, j; string CurrSym = Symbol;
	for( k = 0; k < ASSETS; k++ ){
		asset(Vec[k].sym); 
		double FXrate = getFXrate();
		for( i = 0; i < PERIODS; i++ ){
			Vec[k].prs[i] = price(i)*FXrate;
		}
	}
	asset(CurrSym);
}

double X[PERIODS];
void update_vX( string symbol ){
	int k = 0;
	for( k = 0; k < ASSETS; k++ ){
		if( strstr(Vec[k].sym,symbol) )
			break;
	}
	int i;
	for( i = 0; i < PERIODS; i++ ){
		X[i] = Vec[k].prs[i];
	}
}

double Y[PERIODS];
void update_vY( string symbol ){
	int k = 0;
	for( k = 0; k < ASSETS; k++ ){
		if( strstr(Vec[k].sym,symbol) )
			break;
	}
	int i;
	for( i = 0; i < PERIODS; i++ ){
		Y[i] = Vec[k].prs[i];
	}
}

double XYslope, XYinter;
void LinReg_XY( string symX, string symY ){
	update_vX(symX); update_vY(symY);
	double sumX = 0, sumX2 = 0; 
	double sumY = 0, sumXY = 0;
	int i; double n = PERIODS;
	for( i = 0 ; i < PERIODS; i++ ){
		sumX = sumX + X[i];
		sumX2 = sumX2 + (X[i]*X[i]);
		sumY = sumY + Y[i];
		sumXY = sumXY + (X[i]*Y[i]);
	}
	XYslope = (n*sumXY-sumX*sumY)/(n*sumX2-sumX*sumX);
	XYinter = (sumY - XYslope*sumX)/n;
}


/* Risk Management */
/*
void StopAlgo( double p ){
	vars EQ = algostats[p].eq;
	vars SL = algostats[p].f2;
	if( EQ[0] <= SL[0] ){
		setf(TradeMode, TR_PHANTOM);
		algo(algostats[p].algo);
		int k;
		for( k = 0; k < 2; k++ ){
			asset(algostats[p].syms[k]);
			exitLong(); exitShort();
		}
	}
}
*/
void setTakeProfit( double risk ){
	TakeProfit = price(0) * risk;
}

/* Money Management */

void setQuantity( double MarginUsed ){
	double PriceFX = price(0)*getFXrate();
	Lots = round(MarginUsed/PriceFX);
}

void GlobalMonMan(){
	Margin = Margin + (OptimalF * Capital * sqrt(1 + (WinTotal-LossTotal)/Capital));
}

void PortfMonMan( bool LongTrade ){
	double NumComponents = PAIRS;
	double AvailableCapital = Capital/sqrt(NumComponents);
	Margin = Margin + (ifelse(LongTrade,OptimalFLong,OptimalFShort)*AvailableCapital*sqrt(1+(WinLong-LossLong)/AvailableCapital));
}

/* Trading Strategy */

const double entershort = 0.99; // PARAMS TO OPTIMIZE
const double exitshort = 0.8; // PARAMS TO OPTIMIZE
double enterlong, exitlong;

void StrategyExecutor( int p, double prevval, double lastval ){	
	algo(pairs[p].algo);
	if(  year() > pairs[p].year && hour() >= pairs[p].start && hour() < pairs[p].end ){
		if(  pairs[p].dir > -NOPPS && prevval >= entershort && lastval < entershort && lastval > exitshort ){ // Enter Short
			asset(pairs[p].sym1);
			setQuantity(MARGIN);
			enterShort();
			asset(pairs[p].sym2);
			setQuantity(MARGIN);
			enterLong();
			pairs[p].dir--;
		}
		else if( pairs[p].dir < NOPPS && prevval <= enterlong && lastval > enterlong && lastval < exitlong ){ // Enter Long
			asset(pairs[p].sym1);
			setQuantity(MARGIN);
			enterLong();
			asset(pairs[p].sym2);
			setQuantity(MARGIN);
			enterShort();
			pairs[p].dir++;
		}
		else if( pairs[p].dir < 0 && lastval <= exitshort ){ // Exit Short
			asset(pairs[p].sym1);
			exitShort();
			asset(pairs[p].sym2);
			exitLong();
			pairs[p].dir = 0;
		}
		else if( pairs[p].dir > 0 && lastval >= exitlong ){ // Exit Long
			asset(pairs[p].sym1);
			exitLong();
			asset(pairs[p].sym2);
			exitShort();
			pairs[p].dir = 0;
		}
	}
}

/* TMF */

    // Code //

//

/* Plots */

void plotIndics( int p, double prevval, double lastval,
		   double entershort, double exitshort, 
		   double enterlong, double exitlong){
	if( SELECTALGO == p+1 ){
		string CurrSym = Symbol;
		asset(pairs[p].sym1);
		plot("MidPoint",0.5,NEW,BLACK);
		plot("PrevVal",prevval,0,DARKBLUE);
		plot("LastVal",lastval,0,BLUE);
		plot("EnterShort",entershort,0,RED);
		plot("ExitShort",exitshort,0,ORANGE);
		plot("EnterLong",enterlong,0,DARKGREEN);
		plot("ExitLong",exitlong,0,GREEN);
		asset(pairs[p].sym2);
		plot("MidPoint",0.5,NEW,BLACK);
		plot("PrevVal",1-prevval,0,DARKBLUE);
		plot("LastVal",1-lastval,0,BLUE);
		plot("EnterShort",1-entershort,0,RED);
		plot("ExitShort",1-exitshort,0,ORANGE);
		plot("EnterLong",1-enterlong,0,DARKGREEN);
		plot("ExitLong",1-exitlong,0,GREEN);
		asset(CurrSym);
	}
}

void plotAlgoStats( int Start, int End ){

	string CurrSym = Symbol;

	PlotHeight1 = 600; PlotHeight2 = 100;
	ColorUp = ColorDn = ColorWin = ColorLoss = ColorEquity = ColorDD = 0;
	
	int p; asset(AssetBox);
	for( p = 0; p < PAIRS; p++ ){
		if( SELECTALGO == p+1  ){
			if( p >= Start && p <= End ){
				double Rndm = abs(random());
				plot("Zero",0,0,BLACK);
				plot(algostats[p].algo,algostats[p].eq,0,#999999999*Rndm);
				plot("BA",algostats[p].ba,0,#999999999*Rndm);
				plot("F1",algostats[p].f1,0,RED);
				plot("F2",algostats[p].f2,0,BLUE);
				plot("WS",algostats[p].ws,1,BLUE);
				plot("LS",algostats[p].ls,0,RED);
				plot("WWS",algostats[p].Ws,1,BLUE);
				plot("LLS",algostats[p].Ls,0,RED);
			}
		}
	}
	plot("Equity",ProfitTotal,MAIN,GREEN);

	asset(CurrSym);

}

void filterSignal( int p ){
	vars EQ = algostats[p].eq;
	if( EQ[0] < algostats[p].f2 ){
		setf(TradeMode,TR_PHANTOM);
	}
	else {
		resf(TradeMode,TR_PHANTOM);
	}
}

void plotAsset( int Start, int End ){

	string CurrSym = Symbol;

	PlotHeight1 = 600; PlotHeight2 = 100;
	ColorUp = ColorDn = ColorWin = ColorLoss = ColorEquity = ColorDD = 0;
	
	int p, k;
	while(asset(loop(Assets))){
		if( !IsFX() ){
			if( k >= Start && k <= End ){
				string CurrSym2 = Symbol;
				double AssetEQ = 0;
				for( p = 0; p < PAIRS; p++ ){
					algo(pairs[p].algo);
					if( strstr(Symbol,pairs[p].sym1) || strstr(Symbol,pairs[p].sym2) ){
						AssetEQ += EquityLong+EquityShort;
					}
				}
				asset(AssetBox);
				k++;
				plot(CurrSym2,AssetEQ,0,#123456*k*(1000*abs(random())));
			}
		}
	}

	asset(CurrSym);

}


/* Main Run */

void run(){

	Spread = Commission = RollLong = RollShort = Slippage = Interest = 0;

	/* Init */
	
	if( is(INITRUN) ){
		set(PLOTNOW);
		assetList(ASSETLIST);
		BarPeriod = BARS;
		LookBack = PERIODS;
		Hedge = 5;	
		StartDate = 2016;
		Capital = 10000000;
		MonteCarlo = 0;
		initInfos();
		initPairs();
		initAlgoStats();
		enterlong = 1 - entershort; 
		exitlong = 1 - exitshort;
	}

	/* Print Data Structs */

	if( PRINT ){
		printInfos();
		printPairs();
		//printAlgos();
		printFx();
		printVec(5);
	}
	
	/* Update Values */

	updateAlgoStats();
	updateFXrates();
	updateVec();

	/* Strategy */
	
	if( !is(LOOKBACK) ){
		int p; static int runs; runs++;
		for( p = 0; p < PAIRS; p++ ){
			if( !SELECTALGO || SELECTALGO == p+1 ){

				/* Indicators Calculus */
				
				LinReg_XY(pairs[p].sym1,pairs[p].sym2);
				
				int i; double S[PERIODS]; double Max, Min; 
				for( i = 0; i < PERIODS; i++ ){
					S[i] = ( Y[i] - XYslope*X[i] - XYinter ) / abs(XYinter);
					if( i == 0 )
						Max = Min = S[i];
					Max = max(Max,S[i]);
					Min = min(Min,S[i]);
				}

				double prevval = pairs[p].val;
				double lastval = ( Max - S[0] ) / ( Max - Min );
				
				/* Plot Indicators */

				plotIndics(p,prevval,lastval,entershort,exitshort,enterlong,exitlong);

				/* Execute Strategy */

		
				//vars F2 = algostats[p].f2;
				//filterSignal(p);
				/*
				if( falling(algostats[p].f2) ){
					setf(TradeMode,TR_PHANTOM);
				}
				else {
					resf(TradeMode,TR_PHANTOM);
				}
				*/
				
				StrategyExecutor( p, prevval, lastval );
				
				pairs[p].val = lastval;

			}
		}
	}

	//plotAlgoStats(0,119);
	//plotAsset(0,10);
	//setAccountPlot("SPX500_USD", 1);



	/* END */

}

