
/* SHANNON MULTI-STEP AHEAD FORECAST
 
*/
 
function run()
{
	set(PLOTNOW|PEEK);
	StartDate = 2005;
	BarPeriod = 60;
	LookBack = 100;
 
	int patterns = 3;
	int period = LookBack;
	vars Closes = series((priceClose()));	
 
	var upup[501], dndn[501], updn[501], dnup[501];
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
	
	var entropyUpUp = ShannonEntropy(upup, period+2, patterns);
	var entropyDnDn = ShannonEntropy(dndn, period+2, patterns);
	var entropyUpDn = ShannonEntropy(updn, period+2, patterns);
	var entropyDnUp = ShannonEntropy(dnup, period+2, patterns);
	
	static int win, loss;
	static var winTot, lossTot;
	if(is(INITRUN)) win = loss = winTot = lossTot = 0;
		
	if(max(max(max(entropyUpUp, entropyDnDn), entropyUpDn), entropyDnUp) == entropyUpUp and priceClose(-2) > priceClose(0)) {win++; winTot+=priceClose(-2)-priceClose(0);}
	else if(max(max(max(entropyUpUp, entropyDnDn), entropyUpDn), entropyDnUp) == entropyDnDn and priceClose(-2) < priceClose(0)) {win++; winTot+=priceClose(0)-priceClose(-2);}
	else if(max(max(max(entropyUpUp, entropyDnDn), entropyUpDn), entropyDnUp) == entropyUpUp and priceClose(-2) < priceClose(0)) {loss++; lossTot+=priceClose(0)-priceClose(-2);}
	else if(max(max(max(entropyUpUp, entropyDnDn), entropyUpDn), entropyDnUp) == entropyDnDn and priceClose(-2) > priceClose(0)) {loss++; lossTot+=priceClose(-2)-priceClose(0);}
 
	if(is(EXITRUN)) printf("\n\n%W: %.2f%%\nWins: %d Losses: %d\nWinTot: %.0f LossTot: %.0f\nPips/Trade: %.1f", 100.*win/(win + loss), win, loss, winTot/PIP, lossTot/PIP, (winTot-lossTot)/PIP/(win+loss));
	
	ColorUp = ColorDn = 0;
	plot("pips", (winTot-lossTot)/PIP, MAIN|BARS, BLUE);
	PlotWidth = 1000;
	
}