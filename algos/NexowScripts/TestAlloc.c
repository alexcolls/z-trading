
#include <NexowFunctions.h>

void run(){

    BarPeriod = 1440;
    StartDate = 2015;

    setAllocation(66,10);

    while(asset(loop(Assets))){

        printf("\nSymbol= %s, Allocation= %f, PipValue= %f", Symbol, Allocation(Symbol,66), PipValue_USD());

    }

}