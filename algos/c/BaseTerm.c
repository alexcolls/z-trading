
char* Base()
{
	char* Base = "";
	memcpy(Base,Symbol,3);
	return Base;
}

char* Term()
{
	char* Term = "";
	strcpy(Term,Symbol+4);
	return Term;
}

void run(){

	while(asset(loop("EUR/USD","CAD/JPY","EUR/GBP","AUD/USD")))
    {
		printf("\n\nSymbol: %s\nBase: %s\nTerm: %s",Symbol,Base(),Term());
	}

}


/*
void run()
{

    while(asset(loop(Assets)))
    {
		char Base[4];
		memcpy(Base,Symbol,3);

		char Term[4];
		strcpy(Term,Symbol+4);
	
    	printf("\n\nSymbol: %s\nBase: %s\nTerm: %s",Symbol,Base,Term);
	}

}
*/
