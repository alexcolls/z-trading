

typedef struct{
	string X;
	int Y;
} point;

function run(){

	set(PLOTNOW);
	asset("EUR/USD");
	plot("X",price(0),1,BLUE);
}