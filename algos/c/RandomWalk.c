// Rise/Fall sequence distribution ///////////////////

function run()
{
	PlotHeight1 = 320;
	
	vars Price = series(price());
	int num = NumRiseFall(Price,20);
	int x = 3*num; 
	if(num < 0) x += 3; // eliminate the 0 gap
	plotBar("Price",x,num,1,SUM+BARS,RED);	
	
	vars Random = series(0);
	Random[0] = Random[1] + random();
	num = NumRiseFall(Random,20);
	x = 3*num+1;
	if(num < 0) x += 3;
	plotBar("Random",x,0,1,SUM+BARS,BLUE);	
}