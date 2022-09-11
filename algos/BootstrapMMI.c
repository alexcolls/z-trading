// White's Reality Check //////////////////////////////

#define WRC
//#define SELECT	"XAG/USD"

#define CURVES	1260
#define SAMPLES	1000
#define BUCKET	0.05

string DayFile = "Log\\BalanceDaily.bin";

void _plotHistogram(string Name,var Value,var Step,int Color)
{
  var Bucket = floor(Value/Step);
  plotBar(Name,Bucket,Step*Bucket,1,SUM+BARS+LBL2,Color);
}

var _export(string name,var* Data,int Length)
{
	file_delete(name);
	int i;
	for(i=0; i<Length; i++)
		file_append(name,strf("%.2f\n",Data[i]));
}

typedef struct curve
{
	string Name;
	int Length;
	var *Values;
	var	Perf;
} curve;

curve Curve[CURVES];

void main()
{
	byte *Content = file_content(DayFile);
	if(!Content) return;
	set(LOGFILE);

	int i,j,N = 0;
	int MaxN = 0;
	var MaxPerf = 0.0;
	while(N<CURVES && *Content) 
	{ 
// extract the next curve from the file
		string Name = Content;
		Content += strlen(Name)+1;
		int Size = *((int*)Content);
		int Length = Size/sizeof(var); // number of values
		Content += 4;
		var *Values = Content;
		Content += Size;

#ifdef SELECT
		if(!strstr(Name,SELECT)) continue;
#endif

// store the curve		
		Curve[N].Name = Name;
		Curve[N].Length = Length;
		Curve[N].Values = Values;
		Curve[N].Perf = 1.0/ProfitFactor(Values,Length);
		if(MaxPerf < Curve[N].Perf) {
			MaxN = N;
			MaxPerf = Curve[N].Perf;
		}
		printf("\n%s: %.2f",Curve[N].Name,Curve[N].Perf);
#ifndef WRC
		_plotHistogram("Profit",Perf,2*BUCKET,BLACK);
#endif		
		N++;
	}
	
	PlotScale = 10;
	PlotHeight1 = 250;
	printf("\n\nBest of %i systems\n%s: %.2f",N,Curve[MaxN].Name,MaxPerf); 

#ifdef WRC
	plotBar("nBest",MaxPerf/BUCKET,MaxPerf,50,BARS+LBL2,BLACK);	
	printf("\nBootstrap - please wait..");
	int Better = 0;
	var Sample[3000];
	var SamplePerf[SAMPLES];
	for(i=0; i<SAMPLES; i++) {
		var MaxSamplePerf = 0;
		for(j=0; j<N; j++) {
			randomize(BOOTSTRAP|DETREND,Sample,Curve[j].Values,Curve[j].Length);
			var Perf = 1.0/ProfitFactor(Sample,Curve[j].Length);
			MaxSamplePerf = max(MaxSamplePerf,Perf);
		}
		SamplePerf[i] = MaxSamplePerf;
		if(MaxPerf > MaxSamplePerf) Better++;
		_plotHistogram("Random",MaxSamplePerf,BUCKET,RED); //GREY);
		progress(100*i/SAMPLES,0);
		if(!wait(0)) break;
	}
	var MedianSamplePerf = Median(SamplePerf,SAMPLES);
	printf("\nSample median: %.2f",MedianSamplePerf);
	printf("\nP-Value of best strategy: %.2f",((var)(SAMPLES-Better))/SAMPLES);
#endif
}