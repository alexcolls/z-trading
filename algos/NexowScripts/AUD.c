
typedef struct SPOT
{
	DATE  time; // timestamp of the tick in UTC, OLE date/time format  
	float Val; // price data, positive for ask and negative for bid
	} SPOT;


function AUD()
{  
	SPOT* myspot  = malloc(sizeof(SPOT)); 
	var r;
	
	StartDate = 2007; BarPeriod = 1440; BarZone = ET;
	asset("AUD/CAD"); r += log(price(0))-log(price(1));
	asset("AUD/CHF"); r += log(price(0))-log(price(1));
	asset("AUD/HKD"); r += log(price(0))-log(price(1));
	asset("AUD/JPY"); r += log(price(0))-log(price(1));
	asset("AUD/NZD"); r += log(price(0))-log(price(1));
	asset("AUD/SGD"); r += log(price(0))-log(price(1));
	asset("AUD/USD"); r += log(price(0))-log(price(1));
	asset("EUR/AUD"); r -= log(price(0))-log(price(1));
	asset("GBP/AUD"); r -= log(price(0))-log(price(1));
	asset("XAG/AUD"); r -= log(price(0))-log(price(1));
	asset("XAU/AUD"); r -= log(price(0))-log(price(1));
 
	myspot->time=NOW;
	myspot->Val=r;
	
	return myspot;
}

void main()
{

	SPOT X = AUD();
	
	static int n = 1;
	printf("%.1f",X.Val);
	n++;
	/*
	dataSet(1,n,1,X.Val);
	
	dataSave(1,"AUD.t1");
*/
}

/*
void main()
{
  string Format = "+0,,,%t,f,f,s";
  int Records = dataParse(1,Format,"History\\BTCEUR.csv");
  printf("\n%d records read",Records);
// now convert it to t1 and change sign for sell quotes
  for(i=0; i<Records; i++) {
    T1* t1 = dataAppendRow(2,2);
    t1->time = dataVar(1,i,0);
    t1->fVal = dataVar(1,i,1);
    string sell = dataStr(1,i,3);
    if(sell[0] == 't') t1->fVal = -t1->fVal;
// display progress bar and check [Stop] button
    if(!progress(100*i/Records,0)) break;
  }
  if(Records) dataSave(2,"History\\BTCEUR.t1");
}
*/