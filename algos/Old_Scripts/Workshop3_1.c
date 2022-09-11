function main()
{
	var profit = slider(3,50,0,200,"Profit",0);
	
	if(profit > 100)
		printf("Enough!");
	else
		printf("Not enough!");
}