// Cold Blood Index //////////////////////////////

int TradeDays = 60; // Days since live start
int DrawDownDays = 30; // Days since you're in drawdown
var DrawDown = 100;   // Current drawdown depth in $

string BalanceFile = "Log\\BalanceDaily.dbl";

var logsum(int n)
{
	if(n <= 1) return 0;
	else return log(n)+logsum(n-1);
}

void main()
{
	int CurveLength = file_length(BalanceFile)/sizeof(var);
	var *Balances = file_content(BalanceFile);

	int M = CurveLength - DrawDownDays + 1;
	int T = TradeDays - DrawDownDays + 1;
	
	if(T < 1 || M <= T) {
		printf("Not enough samples!");
		return;
	}
	
	var GMin=0, N=0;
	int i = 0;
	for(; i < M; i++)
	{
		var G = Balances[i+DrawDownDays-1] - Balances[i];
		if(G <= -DrawDown) N += 1.;
		if(G < GMin) GMin = G;
	}  

	var P;
	if(TradeDays > DrawDownDays)
		P = 1. - exp(logsum(M-N)+logsum(M-T)-logsum(M)-logsum(M-N-T));
	else
		P = N/M;

	printf("\nTest period: %i days",CurveLength);
	printf("\nWorst test drawdown: %.f",-GMin);
	printf("\nM: %i  N: %i  T: %i",M,(int)N,T);
	printf("\nCold Blood Index: %.1f%%",100*P);
}