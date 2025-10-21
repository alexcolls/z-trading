
#include <NexowFunctions.h>

void run(){

    StartDate = 2019;

    assetList("AssetsFix");

    char* CurrSym = Symbol;

    setFXaccounting(1,-1);

    asset(CurrSym);
     
    printf("\nSymbol= %s, Price= %f, LotAmount= %f, PIP= %f, PIPCost= %f, Leverage= %f, MarginCost= %f", Symbol, priceClose(0), LotAmount, PIP, PIPCost, Leverage, MarginCost);

}

/*
void run(){

    assetList("AssetsFix");

    Leverage = 20;

    LotAmount = 100;

    StartDate = 2019;

    char* AccCcy = "USD";
    double AssetPrice = priceClose(0);
    if(strstr(Term(),AccCcy))
    {
        PIPCost = PIP * LotAmount;
    }
    else if(strstr(Base(),AccCcy))
    {
        PIPCost = ( PIP * LotAmount ) / AssetPrice;
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
            double USDPrice = priceClose(0);
            asset(CurrSym);
            PIPCost = ( PIP * LotAmount ) * USDPrice;
        }   
        else if( strstr(Term,"CAD") || strstr(Term,"CHF") || strstr(Term,"HKD") || strstr(Term,"JPY") || strstr(Term,"SGD") )
        {
            char* CurrSym = Symbol;
            char Sym[8];
            strcpy(Sym,AccCcy);
            strcat(Sym,"/");
            strcat(Sym,Term);
            asset(Sym);
            double USDPrice = priceClose(0);
            asset(CurrSym);
            PIPCost = ( PIP * LotAmount ) / USDPrice;
        }
    }

    MarginCost = AssetPrice / Leverage * PIPCost / PIP;

    printf("\nSymbol= %s, Price= %f, LotAmount= %f, PIP= %f, PIPCost= %f, Leverage= %f, MarginCost= %f", Symbol, priceClose(0), LotAmount, PIP, PIPCost, Leverage, MarginCost);

}
*/