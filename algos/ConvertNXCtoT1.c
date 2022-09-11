
#define STARTDAY	20161004
#define ENDDAY 	20161014
#define BUFFER		10000

string InName = "History\\%8d.GS.nx2";  // name of a single day CSV file
string OutName = "SPY_201610.t1";
string Code = "eSPY";

int Row,Rows,Count;

typedef struct QUOTE {
	char	Name[24];
	var	Time,Price,Size;
} QUOTE;

int callback(QUOTE *Quote)
{
	Count++;
	if(!strstr(Quote->Name,Code)) return 1;
	if(abs(Quote->Price) < 150) return 1; // remove outliers 
	T1* t1 = dataStr(1,Row,0);	// store record in T1 format
	t1->time = Quote->Time;
	t1->fVal = Quote->Price;
	Row++; Rows++;
	if(Row >= BUFFER)	{ // dataset full?
		Row = 0;
		dataAppend(2,1);
		printf(".");
		if(!wait(0)) return 0;	// abort when [Stop] was hit
	}
	return 1;
}


function main()
{
	if(Broker != "NxCore") {
		printf("\nBroker plugin: %s",Broker); 
		quit("Please select NxCore plugin!");
		return;
	}

	dataNew(1,BUFFER,2);
	login(1);
	
	int N;
	for(N = STARTDAY; N <= ENDDAY; N++) {
		string FileName = strf(InName,N);
		if(!file_date(FileName)) continue;
		printf("\n%s..",FileName);
		Count = Row = Rows = 0;
		brokerCommand(SET_HISTORY,FileName);
		dataAppend(2,1,0,Row);
		printf("\n%d quotes, %d rows stored",Count,Rows);
		if(!wait(0)) return;
	}
	dataSave(2,OutName);		// store complete dataset
}
