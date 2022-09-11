// Options combination //////////////////////////

#include <contract.c>
void optionAdd(int Num,int Type,var StrikeOffs);

#define ASSET		"AAPL"
#define DIVIDEND	0
#define RISKFREE	0
#define EXPIRY		120	// 4 months

#define BUY		(1<<10)
#define SELL	(1<<11)
#define POINTS	100

// Butterfly
/*void combo()
{
	optionAdd(1,BUY|CALL,-5);
	optionAdd(2,SELL|CALL,0);
	optionAdd(1,BUY|CALL,5);
}*/

// Call spread
/*void combo()
{
	optionAdd(1,BUY|CALL,-5);
	optionAdd(1,SELL|CALL,5);
}*/

// Put spread
/*void combo()
{
	optionAdd(1,BUY|PUT,5);
	optionAdd(1,SELL|PUT,-5);
}*/

// Strangle
/*void combo()
{
	optionAdd(1,BUY|CALL,5);
	optionAdd(1,BUY|PUT,-5);
}*/

// Condor
void combo()
{
	optionAdd(1,BUY|CALL,-10);
	optionAdd(1,SELL|CALL,-5);
	optionAdd(1,SELL|CALL,5);
	optionAdd(1,BUY|CALL,10);
}

//////////////////////////////////////////////////

var OptionGains[POINTS],OptionVals50[POINTS];
var UnderL,HistVol;

string buySell(int Type) { if(Type&BUY) return "Buy"; else return "Sell"; }
string callPut(int Type) { if(Type&CALL) return "Call"; else return "Put"; }

void optionPlot(int Num,CONTRACT* C,var Premium,var RangeMin,var RangeMax) 
{
	PlotScale = 10;
	var Step = (RangeMax-RangeMin)/POINTS;
	Step = round(Step+0.5,1);
	RangeMin = round(RangeMin,1);

	int Type = C->Type;
	var Strike = C->fStrike;
	C->Expiry = C->Expiry*0.5;	// value at 50% expiration

	int i;
	for(i=0; i<POINTS; i++)
	{
		if(Num == 0) {
			OptionGains[i] = OptionVals50[i] = 0;
		} else {
			var Price = RangeMin + i*Step;
			if(Price > RangeMax) break;
			var Gain = 0;
			var Val50 = contractVal(C,Price,HistVol,DIVIDEND,RISKFREE);
			switch(Type&(BUY|SELL|CALL|PUT)) {
				case BUY|CALL: 
					if(Price > Strike) Gain = Price - Strike;
					Gain -= Premium;
					Val50 -= Premium;
					break;
				case BUY|PUT: 
					if(Price < Strike) Gain = Strike - Price;
					Gain -= Premium;
					Val50 -= Premium;
					break;
				case SELL|CALL: 
					if(Price > Strike) Gain = Strike - Price;
					Gain += Premium;
					Val50 = Premium - Val50;
					break;
				case SELL|PUT: 
					if(Price < Strike) Gain = Price - Strike;
					Gain += Premium;
					Val50 = Premium - Val50;
					break;
			}
			OptionGains[i] += Multiplier*Num*Gain;
			OptionVals50[i] += Multiplier*Num*Val50;
			plotBar("Zero",i,0,0,LINE,BLACK);
			plotBar("ValueAt50%",i,Price,OptionVals50[i],LINE|LBL2,GREEN);
			plotBar("ValueAtExpiry",i,Price,OptionGains[i],LINE|LBL2,BLUE);
		}
	}
}

void optionAdd(int Num,int Type,var StrikeOffs)
{
	CONTRACT C;
	C.Type = Type;
	C.Expiry = EXPIRY;
	C.fStrike = round(UnderL+StrikeOffs,1);
	
	var Premium = contractVal(&C,UnderL,HistVol,DIVIDEND,RISKFREE);
	if(Num) 
		printf("\n%s %d %s Strk %.1f Val %.2f",
			buySell(Type),Num,callPut(Type),(var)C.fStrike,Multiplier*Premium);
	optionPlot(Num,&C,Premium,0.8*UnderL,1.2*UnderL);
}

void run() 
{
	BarPeriod = 1440;
	StartDate = NOW;
	set(PRELOAD|LOGFILE);
	if(is(INITRUN)) {
		initRQL();
		assetAdd(ASSET);
		assetHistory(ASSET,FROM_GOOGLE);
		asset(ASSET);
	}
	vars Close = series(priceClose());
	HistVol = Volatility(Close,20);
	UnderL = Close[0];
	//printf("\n%s: Date %.0f Price %.2f Volatility: %.2f",strdate("%y-%m-%d",0),wdate(0),UnderL,HistVol);
	Multiplier = 100;

	if(!is(LOOKBACK)) 
	{
		printf("\n%s: Price %.2f Volatility: %.2f",Asset,UnderL,HistVol);
		optionAdd(0,0,0);
		combo();
		quit("Ok!");
	}
}	