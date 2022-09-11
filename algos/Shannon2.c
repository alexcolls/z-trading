
/* SHANNON MULTI-STEP AHEAD FORECAST
 
*/
 
function run()
{
	set(PLOTNOW|PEEK);
	StartDate = 2005;
	BarPeriod = 1440;
	LookBack = 100;

    Spread = Commission = 0;
 
	int patterns = 3;
	int period = LookBack;
	double* Closes = series((priceClose()));	
 
	double upup[501], dndn[501], updn[501], dnup[501];
	int i;
	for(i=1;i<period+1;i++)
	{
		upup[i] = Closes[i];
		dndn[i] = Closes[i];
		updn[i] = Closes[i];
		dnup[i] = Closes[i];	
	}
	upup[1] = Closes[0] + 1;
	upup[0] = upup[1] + 1;
	dndn[1] = Closes[0] - 1;
	dndn[0] = dndn[1] - 1;
	updn[1] = Closes[0] + 1;
	updn[0] = updn[1] - 1;
	dnup[1] = Closes[0] - 1;
	dnup[0] = dnup[1] + 1;
	
	double entropyUpUp = ShannonEntropy(upup, period+2, patterns);
	double entropyDnDn = ShannonEntropy(dndn, period+2, patterns);
	double entropyUpDn = ShannonEntropy(updn, period+2, patterns);
	double entropyDnUp = ShannonEntropy(dnup, period+2, patterns);

    
    static int Days;
	if( !TradeIsOpen ){
        if(max(max(max(entropyUpUp, entropyDnDn), entropyUpDn), entropyDnUp) == entropyUpUp ) { enterLong(); }
        else if(max(max(max(entropyUpUp, entropyDnDn), entropyUpDn), entropyDnUp) == entropyDnDn ) { enterShort(); }
    }
    if( TradeIsOpen ){
        Days++;
        if( Days > 2 ){
            exitLong(); exitShort();
            Days = 0;
        }
    }

	
}