

typedef struct
{
	DATE  time; // timestamp of the tick in UTC, OLE date/time format  
	float Val; // price data, positive for ask and negative for bid
} T1;

void run()
{
	BarPeriod = 1440;
	asset("EUR/USD");
	
	T1.time = strdate(YMD,0);
	T1.Val = price(0);

	dataSet(1,T1)
	dataSave(1,"History\\AAA.t6");
	printf("current val : %f",myspot->fVal);
	plot("X",n,1,BLUE);
	
}
	
	