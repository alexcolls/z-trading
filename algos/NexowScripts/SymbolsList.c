
#include <NexowFunctions.h>

void run(){

    set(PLOTNOW);

    assetList("AssetsFix");

    double X;

    printf("\n%s",Symbol);

    if( is(INITRUN) ){
        SetSymbolsList();
        OK();
        printf("\n");
    }

    printf("\n%s",Symbol);

    int i;
    for (i = 0; i < NumberOfSymbols; i++)
    {
       printf("\n%s",SymbolsList[i]);
    }
    printf("\n\n%d",NumberOfSymbols);

    if( strstr(SymbolsList[0],"AUD/CAD") ){
        OK();
        OK();
        printf("\n");
    }

    asset(SymbolsList[0]);

    X = price(0);

    asset(SymbolsList[1]);

    plot("SMA",X,0,RED);



}