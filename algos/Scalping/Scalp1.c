// Required win rate vs. trade Duration /////////////////////

function run()
{
	NumYears = 3;
	BarPeriod = 1;
	LookBack = 1440;
	PlotScale = 15;	
	Commission = 0.6;
	Spread = 0.5*PIP;

	int Duration = 1, i = 0;
	if(!is(LOOKBACK))
		while(Duration <= 1440)
	{ 	
		var Win = abs(priceClose(Duration)-priceClose(0))*PIPCost/PIP;
		var Cost = Commission*LotAmount/10000. + Spread*PIPCost/PIP;
	
		//printf("\nWin %.2f Cost %.2f",Win,Cost);
	
// Breakeven:
// Profit = Cost = Rate * Win - (1.-Rate) * Win; 
// => Cost = (Rate - 0.5) * 2 * Win; 
		
		var Rate = ifelse(Win>Cost, Cost/(2*Win) + 0.5, 1.);

		plotBar("Min Rate",i,Duration,100*Rate,AVG+BARS,RED);	
		
		if(Duration < 10) Duration += 1;
		else if(Duration < 60) Duration += 5;
		else if(Duration < 180) Duration += 30;
		else Duration += 60;
		i++;
	}

	Bar += 100;
}