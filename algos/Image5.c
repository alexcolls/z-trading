// Random Walk Statistics ///////////////////

function run()
{
	PlotHeight1 = 320;
	
	vars Price = series(price());
	int num = NumRiseFall(Price,20);
	int pos = 3*num; 
	if(num < 0) pos += 3; // eliminate the 0 gap
	plotBar("Price",pos,num,1,SUM+BARS,GREY);	
	
	vars Random = series(0);
	Random[0] = Random[1] + random();
	num = NumRiseFall(Random,20);
	pos = 3*num+1;
	if(num < 0) pos += 3;
	plotBar("Random",pos,0,1,SUM+BARS,BLACK);	
}