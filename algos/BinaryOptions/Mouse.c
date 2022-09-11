void main()
{
	if(version() < 1.455) {
		quit("Need Zorro 1.46 or above!");
		return;
	}
	int BuyX,BuyY,SellX,SellY; // button coordinates

// open the browser	
	printf("\nOpening the broker's website...");
	exec("http://financial-hacker.com/shark.htm",0,1);

// get the position of the Buy button
	printf("\nRight click on [Buy]!");
	printf("\n");	
	while(wait(50)) {
		int button = mouse(&BuyX,&BuyY,window(""));
		printf("\r%04d %04d",BuyX,BuyY);
		if(button & 2) break;
	}
// wait until right key released	
	while(wait(50)) {
		int x,y,button = mouse(&x,&y,0);
		if(!(button & 2)) break;	
	}

// get the position of the Sell button	
	printf("\nRight click on [Sell]!");
	printf("\n");	
	while(wait(50)) {
		int button = mouse(&SellX,&SellY,window(""));
		printf("\r%04d %04d",SellX,SellY);
		if(button & 2) break;
	}
// wait until right key released	
	while(wait(50)) {
		int x,y,button = mouse(&x,&y,0);
		if(!(button & 2)) break;	
	}

// send mouse clicks to Buy and Sell	
	printf("\nI will now click on [Buy]!");
	Sleep(500);
	string k = strf("[click %d,%d]",BuyX,BuyY);
	keys(k);
	sound("Click");
	printf("\nI will now click on [Sell]!");
	Sleep(500);
	string k = strf("[click %d,%d]",SellX,SellY);
	keys(k);
	sound("Click");
	printf("\nDone!");
}
