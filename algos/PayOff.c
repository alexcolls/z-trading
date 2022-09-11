// Options combination, payoff diagram //////////////////////////
#include <contract.c>

//#define ASSET		"SPY"
#define UNDERL		280	// if no asset
#define HISTVOL	0.15	// if no asset
#define DIVIDEND	0.01
#define RISKFREE	0.01
#define EXPIRY		6*7	// in days
#define RANGE		0.12	// plot price range, percentage
#define POINTS		100
#define PLOT_DELTA	// plot average delta as green line

/////////////////////////////////////////////////
void contractAdd(int Num,int Type,var StrikeDist);

void Call() {
	contractAdd(1,CALL,0);
}

void Put() {
	contractAdd(1,PUT,0);
}

void Butterfly() {
	contractAdd(1,PUT,-5);
	contractAdd(-2,PUT,0);
	contractAdd(1,PUT,5);
}

void ButterflyC() {
	contractAdd(1,CALL,-5);
	contractAdd(-2,CALL,0);
	contractAdd(1,CALL,5);
}

void CallSpread() {
	contractAdd(1,CALL,-5);
	contractAdd(-1,CALL,5);
}

void PutSpread() {
	contractAdd(1,PUT,5);
	contractAdd(-1,PUT,-5);
}

void Strangle() {
	contractAdd(1,CALL,5);
	contractAdd(1,PUT,-5);
}

void Condor() {
	contractAdd(1,PUT,-15);
	contractAdd(-1,PUT,-5);
	contractAdd(-1,CALL,5);
	contractAdd(1,CALL,15);
}

void doCombo() {
	Condor(); // <= put here the combo to test
	//Butterfly();
}

//////////////////////////////////////////////////
var UnderL,HistVol;

void optionPlot(int Num,CONTRACT* C,var RangeMin,var RangeMax) 
{
	static var OptionGains[POINTS],OptionVals50[POINTS],OptionDeltas[POINTS];
	PlotScale = 10;
	var Step = (RangeMax-RangeMin)/POINTS;
	Step = round(Step+0.5);
	RangeMin = round(RangeMin);
	if(C) C->Expiry = 0.5*C->Expiry;	// for the value at 50% expiration

	int i;
	for(i=0; i<POINTS; i++)
	{
		if(!Num) {
			OptionGains[i] = OptionVals50[i] = OptionDeltas[i] = 0;
		} else {
			var Price = RangeMin + i*Step;
			if(Price > RangeMax) break;
			var Delta = 0;
			OptionGains[i] += Multiplier*Num*contractProfit(C,Price,-C->fAsk);
			OptionVals50[i] += Multiplier*Num*(contractVal(C,Price,HistVol,DIVIDEND,RISKFREE,&Delta)-C->fAsk);
			plotBar("Zero",i,0,0,LINE,BLACK);
#ifdef PLOT_DELTA
			OptionDeltas[i] += contractDelta(C->Type,2*C->Expiry,Price,HistVol,RISKFREE,C->fStrike);
			//plotBar("DeltaAt50%",i,Price,Delta,LINE|LBL2|AXIS2,GREEN);
			plotBar("Delta",i,Price,OptionDeltas[i],LINE|LBL2|AXIS2,GREEN);
#endif
			plotBar("ValueAt50%",i,Price,OptionVals50[i],LINE|LBL2,RED);
			plotBar("ValueAtExpiry",i,Price,OptionGains[i],LINE|LBL2,BLUE);
		}
	}
}

void contractAdd(int Num,int Type,var StrikeDist)
{
	static CONTRACT C;
	C.Type = Type;
	C.Expiry = EXPIRY;
	C.fStrike = round(ifelse(0.5*UnderL < StrikeDist,StrikeDist,UnderL+StrikeDist),0.5);
	C.fUnl = UnderL;
	C.fBid = C.fAsk = contractVal(&C,C.fUnl,HistVol,DIVIDEND,RISKFREE);
	printf("\n%s %d %s %.1f Premium %.2f",
		ifelse(Num>0,"Buy","Sell"),abs(Num),ifelse(C.Type&CALL,"Call","Put"),(var)C.fStrike,(var)C.fAsk);
	comboAdd(&C,Num);
	optionPlot(Num,&C,(1-RANGE)*UnderL,(1+RANGE)*UnderL);
}

#ifdef ASSET
void run() 
{
	set(PRELOAD,LOGFILE);
	BarPeriod = 1440;
	StartDate = NOW;
	if(is(INITRUN)) {
		assetAdd(ASSET);
		assetHistory(ASSET,FROM_AV);
		asset(ASSET);
	}
	vars Closes = series(priceClose());
	HistVol = Volatility(Closes,20);
	UnderL = Closes[0];
#else
void main() 
{
	HistVol = HISTVOL;
	UnderL = UNDERL;
#endif
	optionPlot(0,0,0,0); 	// reset arrays
	comboAdd(0,0);
	Multiplier = 100;

	if(!is(LOOKBACK)) {
		if(!initRQL()) {
			quit("R and RQuantLib required!");
			return;
		}
		doCombo();
		printf("\nUnderlying: %.2f Volatility: %.2f",UnderL,HistVol);
		printf("\nRisk Short %.2f Long %.2f Premium %.2f",
			Multiplier*comboRisk(-1),Multiplier*comboRisk(1),Multiplier*comboPremium(1));
		quit("Ok!");
	}
}	