// Panel Test ///////////////////

void click(int row,int col)
{
	sound("click.wav");
	string Text = panelGet(row,col);
	if(Text == "Close") 
		panelSet(row,col,"Open",GREEN,0,0);
	else if(Text == "Open") 
		panelSet(row,col,"Close",ColorPanel[3],0,0);
	else if(Text == "Start") 
		panelSet(row,col,"Stop",0,2,0);
	else if(Text == "Stop") 
		panelSet(row,col,"Start",0,1,0);
	else if(Text == "Select") 
		panelSet(row,col,"Unselect",0,3,0);
	printf("\nClicked on %i,%i",row,col);
}

void main()
{
	if(!is(SPONSORED)) {
		printf("Need Zorro S for panel!");
		return;
	}
	panel("Strategy\\TestPanel2.csv",BLACK,60);
	while(wait(100)) {
		int i,j;
		for(j=14; j<14+11; j++)
		for(i=2; i<2+7; i++)
			if(panelGet(9,5) != "Stop") 
				panelSet(j,i,strf("%.2f",random(10000)),0,0,0);
		panelSet(0,3,strf("%i",atoi(panelGet(0,3))+1),0,0,0);
	}
}