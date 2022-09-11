//////////////////////////////////////////////////////
// Convert price history from Nanotick BBO .csv to .t1
//////////////////////////////////////////////////////

#define STARTDAY	20161004
#define ENDDAY 	20161014

string InName = "History\\CME.%08d-%08d.E.BBO-C.310.ES.csv";  // name of a single day CSV file
string OutName = "ES_201610.t1";
string Code = "ESZ";	// Symbol

string Format = "2,,%Y%m%d,%H:%M:%S,,,s,,,s,i,,";
// Nanotick line format: ReceivingDate,ReceivingTime,SendingDate,SendingTime,SeqNum,SecurityID,Symbol,Asset,SecurityGroup,EntryType,EntryPrice,EntrySize,DisplayFactor
//20161002,14:00:16.098500291,20161002,14:00:16.098445733,669,35903,ESH7,ES,ES,A,215800,5,0.01


void main()
{
	int N,Row,Record,Records;
	for(N = STARTDAY; N <= ENDDAY; N++)
	{
		string FileName = strf(InName,N,N+1);
		if(!file_date(FileName)) continue;
		Records = dataParse(1,Format,FileName);	// read BBO data
		printf("\n%d rows read",Records);
		dataNew(2,Records,2);					// create T1 dataset
		for(Record = 0,Row = 0; Record < Records; Record++)
		{
			if(!strstr(Code,dataStr(1,Record,1))) continue;	// select only records with correct symbol
			T1* t1 = dataStr(2,Row,0);			// store record in T1 format
			float Price = 0.01 * dataInt(1,Record,3);	// price in cents
			if(Price < 1000) continue;		// no valid price
			string AskBid = dataStr(1,Record,2);
			if(AskBid[0] == 'B')					// negative price for Bid
				Price = -Price;
			if(t1->fVal == Price) continue; // no price change
			t1->fVal = Price;
			t1->time = dataVar(1,Record,0) + 1./24.;		// add 1 hour Chicago-NY time difference
			Row++;
			//watch("!Price",t1->fVal,"Time",t1->time,"AskBid",AskBid);
		}
		printf(", %d stored",Row);
		dataAppend(3,2,0,Row);	// append dataset
		if(!wait(0)) return;
	}
	dataSave(2,"Test.t1");		// store complete dataset
	dataSave(3,OutName);		// store complete dataset
}