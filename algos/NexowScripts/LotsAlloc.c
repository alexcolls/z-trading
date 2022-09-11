
#include <NexowFunctions.h>

void run(){

    BarPeriod = 1440;

    char* AccCcy = "USD";

    double Percentage = 5.50;

    double Collateral = ( Equity * Percentage/100 );

    if(strstr(Base(),AccCcy))
    {
        Lots = Collateral;
    }
    else if(strstr(Term(),AccCcy))
    {
        Lots = Collateral / priceClose(0);
    }
    else
    {
        char* Base = Base();            
        if( strstr(Base,"AUD") || strstr(Base,"EUR") || strstr(Base,"GBP") || strstr(Base,"NZD") || strstr(Base,"XAU") || strstr(Base,"XAG") )
        {
            char* CurrSym = Symbol;
            char Sym[8];
            strcpy(Sym,Base);
            strcat(Sym,"/");
            strcat(Sym,AccCcy);
            asset(Sym);
            double Price = priceClose(0);
            asset(CurrSym);
            Lots = Collateral / Price;
        }   
        else if( strstr(Base,"CAD") || strstr(Base,"CHF") || strstr(Base,"HKD") || strstr(Base,"JPY") || strstr(Base,"SGD") )
        {
            char* CurrSym = Symbol;
            char Sym[8];
            strcpy(Sym,AccCcy);
            strcat(Sym,"/");
            strcat(Sym,Base);
            asset(Sym);
            double Price = priceClose(0);
            asset(CurrSym);
            Lots = Collateral * Price;
        }
    }

    printf("\nLots= %f", Lots);
}



