///////////////////////////////////////////////////////
// Example for DLL-based Zorro strategies
///////////////////////////////////////////////////////
#include "stdafx.h"
#include <zorro.h>

#define WORKSHOP4
//#define WORKSHOP6
//#define WORKSHOP7
//#define RTEST
//#define PYTHONTEST
//#define OPTIONS
//#define DEEPLEARN
//#define DLLTEST	// user-defined extension DLL

#ifdef WORKSHOP4 //////////////////////////////////////
#include <profile.c>

DLLFUNC void run()
{
	if(Init) 
		printf("\nStrategy DLL test");
	LookBack = 300;
	asset("EUR/USD");

	vars Price = series(price(0));
	vars Trend = series(LowPass(Price,500));
	Stop = 4*ATR(100);
	
	vars MMI_Raw = series(MMI(Price,300));
	vars MMI_Smooth = series(LowPass(MMI_Raw,500));
	
	if(falling(MMI_Smooth)) {
		if(valley(Trend))
			enterLong();
		else if(peak(Trend))
			enterShort();
	}
	
	StartDate = 2010;
	EndDate = 2016; // fixed simulation period 
	
	set(LOGFILE); // log all trades
	//Verbose = 2;
	PlotWidth = 800;
	PlotHeight1 = 300;
	//set(PLOTNOW);
	//plot("MMI_Raw",MMI_Raw,NEW,GREY);
	//plot("MMI_Smooth",MMI_Smooth,0,BLACK);
	plotTradeProfile(-50); 
}
#endif

#ifdef WORKSHOP6 //////////////////////////////////////
void tradeCounterTrend()
{
	TimeFrame = 4;
	vars Price = series(price(0));
	vars Filtered = series(BandPass(Price,optimize(30,20,40,0,0),0.5));
	vars Signal = series(FisherN(Filtered,500));
	var Threshold = optimize(1,0.5,1.5,0.1,0);
	
	Stop = optimize(4,2,10,0,0) * ATR(100);
	Trail = 4*ATR(100);
	
	if(crossUnder(Signal,-Threshold)) 
		enterLong(); 
	else if(crossOver(Signal,Threshold)) 
		enterShort();
}

void tradeTrend()
{
	TimeFrame = 1;
	vars Price = series(price(0));
	vars Trend = series(LowPass(Price,optimize(500,300,700,0,0)));

	Stop = optimize(4,2,10,0,0) * ATR(100);
	Trail = 0;

	vars MMI_Raw = series(MMI(Price,300));
	vars MMI_Smooth = series(LowPass(MMI_Raw,500));
	
	if(falling(MMI_Smooth)) {
		if(valley(Trend))
			enterLong();
		else if(peak(Trend))
			enterShort();
	}
}

DLLFUNC void run()
{
	set(PARAMETERS+FACTORS);  // generate and use optimized parameters and factors
	//NumCores = -2;		// use multiple cores (Zorro S only)
	BarPeriod = 60;	// 1 hour bars
	LookBack = 2000;	// needed for Fisher()
	StartDate = 2005;
	EndDate = 2016; 	// fixed simulation period
	NumWFOCycles = 10; // activate WFO
	Capital = 10000;		// reinvestment mode
	
	if(ReTrain) {
		UpdateDays = -1;	// update price data from the server 
		SelectWFO = -1;	// select the last cycle for re-optimization
		reset(FACTORS);	// don't generate factors when re-training
	}
	
// portfolio loop
	while(asset(loop("EUR/USD","USD/JPY")))
	while(algo(loop("TRND","CNTR")))
	{
// don't reinvest
		//Margin = 0.5 * OptimalF * Capital;
// reinvest the square root of the component profit		
		Margin = 0.5 * OptimalF * Capital * sqrt(1 + ProfitClosed/Capital);

		if(strstr(Algo,"TRND")) 
			tradeTrend();
		else if(strstr(Algo,"CNTR")) 
			tradeCounterTrend();
	}
	
	set(TESTNOW+LOGFILE);
}
#endif

#ifdef WORKSHOP7 //////////////////////////////////////
DLLFUNC void run()
{
	StartDate = 2006;
	EndDate = 2017;
	BarPeriod = 1440; // 1 day
	BarZone = WET; // Western European midnight
	Weekend = 1;	// don't merge Friday and Sunday bars
	LookBack = 3;	// only 3 bars needed
	NumWFOCycles = 10;

	set(RULES); //+TESTNOW);

	if(Train) Hedge = 2;	// for training, allow long + short	
	LifeTime = 5;  				// one week
	MaxLong = MaxShort = 1;
	
	if(adviseLong(PATTERN+2,0,
		priceHigh(2),priceLow(2),priceClose(2),
		priceHigh(1),priceLow(1),priceClose(1),
		priceHigh(1),priceLow(1),priceClose(1),
		priceHigh(0),priceLow(0),priceClose(0)) > 40)
		enterLong();
	
	if(adviseShort() > 40)
		enterShort();
}
#endif

#ifdef RTEST //////////////////////////////////////////
#include <r.h>

DLLFUNC void main()
{
	if(!Rstart()) {
		print(TO_WINDOW,"Error - R won't start!");
		return;
	}
	
	var vecIn[5],vecOut[5];
	int i;
	for(i=0; i<5; i++) 
		vecIn[i] = i;
	
	Rset("Rin",vecIn,5);
	Rx("Rout <- Rin * 10");
	Rv("Rout",vecOut,5);
		
	if(!Rrun()) {
		print(TO_WINDOW,"Error - R session aborted!");
		return;
	} 
	
	print(TO_WINDOW,"\nReturned: ");
		for(i=0; i<5; i++) 
			print(TO_WINDOW,"%.0f ",vecOut[i]);

// test a function
	Rx("RSum = function(MyVector) { return(sum(MyVector)) }");
	var RSum = Rd("RSum(Rout)"); 
	print(TO_WINDOW,"\nSum: %.0f",RSum);
}

#endif
#ifdef PYTHONTEST //////////////////////////////////////////
DLLFUNC int main()
{
	if(!pyStart("",1)) {
		printf("Error - Python won't start!");
		return 0;
	}
	
	var Vec[5] = { 0,1,2,3,4 };
	
	pySet("PyVec",Vec,5);
	pyX("for i in range(5): PyVec[i] *= 10\n");
	pyVec("PyVec",Vec,5);
	
	int i;
	printf("\nReturned: ");
	for(i=0; i<5; i++) printf("%.0f ",Vec[i]);

// test a function
	pyX("def PySum(V):\n Sum = 0\n for X in V: Sum += X\n return Sum\n\n");
	pyX("Result = PySum(PyVec)");
	printf("\nSum: %.0f",pyVar("Result"));
}
#endif

#ifdef OPTIONS ////////////////////////////////////////
#include <contract.c>

#define PREMIUM	2
#define WEEKS		6 // expiration

int i;
var Price;

CONTRACT* findCall(int Expiry, var Premium)
{
	for (i = 0; i < 50; i++) {
		if (!contract(CALL, Expiry, Price + 0.5*i)) return 0;
		if (between(ContractBid, 0.1, Premium))
			return ThisContract;
	}
	return 0;
}

CONTRACT* findPut(int Expiry, var Premium)
{
	for (i = 0; i < 50; i++) {
		if (!contract(PUT, Expiry, Price - 0.5*i)) return 0;
		if (between(ContractBid, 0.1, Premium)) return ThisContract;
	}
	return 0;
}

DLLFUNC void run()
{
	StartDate = 2012;
	EndDate = 2018;
	BarPeriod = 1440;
	if(is(TRADEMODE)) BarZone = ET; // EOD history is already ET
	BarOffset = 15 * 60 + 20; // trade at 15:20 ET
	LookBack = 1;
	PlotMode = 0;
	set(PLOTNOW);
	set(PRELOAD | LOGFILE);

	assetList("AssetsIB");
	asset("SPY");
	Multiplier = 100;

	// load today's contract chain
	Price = priceClose(0);
	int N = contractUpdate("SPYa", 0, CALL | PUT); // artificial options data

	// all expired? enter new options
	if (!NumOpenShort) {
		CONTRACT *Call = findCall(WEEKS * 7, PREMIUM);
		CONTRACT *Put = findPut(WEEKS * 7, PREMIUM);
		if (Call && Put) {
			MarginCost = 0.5*(0.15*Price - min(Call->fStrike - Price, Price - Put->fStrike));
			contract(Call); enterShort();
			contract(Put); enterShort();
		}
	}
}
#endif // OPTIONS

#ifdef DEEPLEARN //////////////////////////////////////
#include <r.h>

var change(int n)
{
	return scale((priceClose(0) - priceClose(n)) / priceClose(0), 100) / 100;
}

var range(int n)
{
	return scale((HH(n,0) - LL(n,0)) / priceClose(0), 100) / 100;
}

DLLFUNC void run()
{
	NumCores = -1;
	Script = "DeepLearn";
	StartDate = 20150101;
	BarPeriod = 60;	// 1 hour
	LookBack = 100;
	WFOPeriod = 252 * 24; // 1 year
	DataSplit = 90;
	set(RULES);
	set(LOGFILE | PLOTNOW);

	assetList("AssetsFix");
	asset("EUR/USD");
	Spread = RollLong = RollShort = Commission = Slippage = 0;
	LifeTime = 3;
	if(Train) Hedge = 2;
	var Threshold = 0.5;

	if(adviseLong(NEURAL|BALANCED, 0,
		change(1), change(2), change(3), change(4),
		range(1), range(2), range(3), range(4)) > Threshold)
		enterLong();
	if(adviseShort() > Threshold)
		enterShort();
}
#endif // DEEPLEARN

#ifdef DLLTEST //////////////////////////////////////
DLLFUNC var square(var Arg)
{
	return Arg * Arg;
}

/*Call from a lite-C script:
var square(var Arg);
API(square,Strategy\\MyStrategy)

void main()
{
	if(!square)
		printf("No square!");
	else
		printf("Square: %.3f",square(3));
}
*/
#endif
