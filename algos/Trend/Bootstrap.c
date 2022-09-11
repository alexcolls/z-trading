// White's Reality Check //////////////////////////////

#define WRC

//#define SELECT	"XAG/USD"
#define CURVES		900
#define SAMPLES	1000
#define BUCKET		0.01

void _plotHistogram(string Name,var Value,var Step,int Color)
{
  var Bucket = floor(Value/Step);
  plotBar(Name,Bucket,Step*Bucket,1,SUM+BARS+LBL2,Color);
}

typedef struct curve
{
	string Name;
	int Length;
	var *Values;
} curve;

curve Curve[CURVES];
var Daily[3000];

void main()
{
	byte *Content = file_content("Log\\TrendDaily.bin");
	if(!Content) {
		printf("\nFirst produce equity curves!");
		return;
	}
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
#ifdef SELECT // plot only curves from one asset
		if(!strstr(Name,SELECT)) continue;
#endif
// store the curve		
		Curve[N].Name = Name;
		Curve[N].Length = Length;
		Curve[N].Values = Values;
		var Performance = 1.0/ProfitFactor(Values,Length);
		if(MaxPerf < Performance) {
			MaxN = N;
			MaxPerf = Performance;
		}
		printf("\n%s: %.2f",Curve[N].Name,Performance);
		//_plotHistogram("Profit",Performance,BUCKET,RED);
		N++;
	}
	
	PlotScale = 10;
	PlotHeight1 = 300;
	printf("\n\nBenchmark: %s, %.2f", Curve[MaxN].Name,MaxPerf); 

#ifdef WRC
	plotBar("MaxPerf",MaxPerf/BUCKET,MaxPerf,30,BARS+LBL2,BLACK);	
	printf("\nBootstrap - please wait");
	int Worse = 0, Better = 0;
	for(i=0; i<SAMPLES; i++) {
		var MaxBootstrapPerf = 0;
		for(j=0; j<N; j++) {
			randomize(BOOTSTRAP|DETREND,Daily,Curve[j].Values,Curve[j].Length);
			var Performance = 1.0/ProfitFactor(Daily,Curve[j].Length);
			MaxBootstrapPerf = max(MaxBootstrapPerf,Performance);
		}
		printf(".");
		if(MaxPerf > MaxBootstrapPerf)
			Better++;
		else
			Worse++;
		_plotHistogram("Profit",MaxBootstrapPerf,BUCKET,RED);
		progress(100*i/SAMPLES,0);
	}
	printf("\nBenchmark beats %.0f%% of samples!",
		(var)Better*100./(Better+Worse));
#endif
}