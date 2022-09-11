// Perfect martingale system ///////////////////

function run()
{
	set(PLOTNOW);
	BarPeriod = 1440;
	Stop = TakeProfit = ATR(100);
	Lots = pow(2,LossStreakTotal); // the martingale formula...
	
// wait until last stop/profit target was hit
	if(NumOpenTotal == 0) {
		if(random() < 0)
			enterShort();
		else 
			enterLong();
	}	
}