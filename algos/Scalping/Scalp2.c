// Scalping experiment /////////////////////

//#define SECONDS (tick plugin required)

var _log2(var X) { return log(X)/log(2.); }
 
var _ShannonEntropy(char *S,int Length)
{
	static var Hist[256];
	memset(Hist,0,256*sizeof(var));
	var Step = 1./Length;
	int i;
	for(i=0; i<Length; i++) 
		Hist[S[i]] += Step;
	var H = 0;
	for(i=0;i<256;i++){
		if(Hist[i] > 0.)
			H -= Hist[i]*_log2(Hist[i]);
	}
	return H;
}

var _ShannonEntropy(var *Data,int Length,int PatternSize)
{
	char S[1024];
	int i,j;
	int Size = Length-PatternSize-1;
	for(i=0; i<Size; i++) {
		int C = 0;
		for(j=0; j<PatternSize; j++) {
			if(Data[i+j] > Data[i+j+1])
				C += 1<<j;
		}
		S[i] = C;
	}
	return _ShannonEntropy(S,Size);
} 


function run()
{
#ifdef SECONDS	
	StartDate = 20150101;
	EndDate = 20150201;
	BarPeriod = 1./60;
	LookBack = 60*300;
	History = ".t1";
#else	
	NumYears = 3;
	BarPeriod = 1;
	LookBack = 1440*300;
#endif	
	PlotScale = 15;	
	StartWeek = 10000;
	
	int Duration = 1, i = 0;
	while(Duration <= 1440)
	{ 
#ifdef SECONDS
		if(i >= 7) break;
		int Durations[7] = { 2,5,10,15,30,45,60 };
		Duration = Durations[i];
		TimeFrame = Duration;
#else
		TimeFrame = frameSync(Duration);
#endif
		vars Prices = series(price(),300);

		if(!is(LOOKBACK) && 0 == (Bar%101)) {
			var H = _ShannonEntropy(Prices,300,3);
			plotBar("Randomness",i,Duration,H,AVG+BARS,BLUE);	
		}

#ifndef SECONDS
		if(Duration < 10) Duration += 1;
		else if(Duration < 60) Duration += 5;
		else if(Duration < 240) Duration += 60;
		else if(Duration < 720) Duration += 240;
		else Duration += 720;
#endif
		i++;
	}
}