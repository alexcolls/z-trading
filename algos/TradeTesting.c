
#include <NexowFunctions.h>

void run(){

    BarPeriod = 1;

    while(asset(loop(Assets))){
        LotsAlloc(0.50);

        enterLong();

        printf("\nBalance= %f", Balance);
        printf("\nEquity= %f", Equity);
        printf("\nSymbol= %s", Symbol);
        printf("\nPipValue= %f", PipValue_USD());
        printf("\nLots= %f", Lots);
    }

}