
//#include "C:\\ZorroBeta\\Strategy\\NexowFunctions.c"
#include <NexowFunctions.h>

void run()
{
    char* AccCcy = "USD";
    while(asset(loop(Assets)))
    {
        double PipValue = 0;
        if(strstr(Term(),AccCcy))
        {
            PipValue = PIP * LotAmount;
        }
        else if(strstr(Base(),AccCcy))
        {
            PipValue = PIP * LotAmount / priceClose(0);
        }
        else
        {
            char* Term = Term();            
            if( strstr(Term,"AUD") || strstr(Term,"EUR") || strstr(Term,"GBP") || strstr(Term,"NZD") || strstr(Term,"XAU") || strstr(Term,"XAG") )
            {
                char* CurrSym = Symbol;
                char Sym[8];
				strcpy(Sym,Term);
				strcat(Sym,"/");
				strcat(Sym,AccCcy);
				asset(Sym);
				double Price = priceClose(0);
                asset(CurrSym);
				PipValue = PIP * LotAmount * Price;
            }   
            else if( strstr(Term,"CAD") || strstr(Term,"CHF") || strstr(Term,"HKD") || strstr(Term,"JPY") || strstr(Term,"SGD") )
            {
                char* CurrSym = Symbol;
                char Sym[8];
                strcpy(Sym,AccCcy);
                strcat(Sym,"/");
                strcat(Sym,Term);
                asset(Sym);
                double Price = priceClose(0);
                asset(CurrSym);
				PipValue = PIP * LotAmount / Price;
            }
        }
        printf("\n\nSymbol: %s\nBase: %s\nTerm: %s\nPipValue: %f",Symbol,Base(),Term(),PipValue);
    }
}