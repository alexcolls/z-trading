void main()
{
	string MyAsset;
	while(MyAsset = loop("SPY","TNT","XIV","GLD","AAPL","YHOO")) // ... enter your assets here 
	{
		string URL = strf("https://www.google.com/finance/historical?q=%s&startdate=01-Jan-2000&output=csv",MyAsset);
		string Content = http_transfer(URL,0);
		if(!Content) continue;
		file_write("History\\history.csv",Content,0);
		dataNew(1,0,7);
		if(!dataParse(1,"%d-%b-%y,f3,f1,f2,f4,f6","History\\history.csv"))
			continue;
		printf(" %s",MyAsset);
		dataSave(1,strf("History\\%s.t6",MyAsset));
  }
}