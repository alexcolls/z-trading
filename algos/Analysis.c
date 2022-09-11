// Price Curve Analysis ///////////////////

function run()
{
	set(PLOTNOW);
	NumYears = 1;

	var vReturn = (price(0)-price(1))/PIP;
	plot("Return",vReturn,0,0);

	if(is(EXITRUN)) {
		DATA *P = plotData("Return");
		int N = P->end-2;
		var* D = P->Data+2;
		printf("\nMean change per bar = %f pips",Moment(D,N,1));
		printf("\nStdDeviation = %f",sqrt(Moment(D,N,2)));
		printf("\nSkewness = %f",Moment(D,N,3));
		printf("\nKurtosis = %f",Moment(D,N,4));
	}	
}