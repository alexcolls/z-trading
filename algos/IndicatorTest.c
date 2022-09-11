// Indicatortest ///////////////////

function run()
{
	set(LOGFILE|PLOTNOW);
	NumYears = 1;
	MaxBars = 210;
	PlotScale = 8;
	PlotWidth = 800;
	PlotHeight1 = 350;
	PlotHeight2 = 80;
	vars Prices = series(price());
	vars Closes = series(priceClose());
	
// plot Bollinger bands
	BBands(Prices,30,2,2,MAType_SMA);
	plot("Bollinger1",rRealUpperBand,BAND1,0x00CC00);
	plot("Bollinger2",rRealLowerBand,BAND2,0xCC00FF00);
	plot("SAR",SAR(0.02,0.02,0.2),DOT,RED);
	ZigZag(Prices,20*PIP,5,BLUE);
	
// plot some other indicators	
	plot("ATR (PIP)",ATR(20)/PIP,NEW,RED);
	plot("Doji",CDLDoji(),NEW+BARS,BLUE);
	plot("FractalDim",FractalDimension(Prices,30),NEW,RED);
	plot("ConnorsRSI",ConnorsRSI(Closes,3,2,100),NEW,RED);
}
