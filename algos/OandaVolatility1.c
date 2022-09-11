
#include <nexow.h>

#define ASSETS 45
#define LEN 30

symval StDevs[ASSETS];
symval MonTRs[ASSETS];
symval2 MonHL[ASSETS];

void run(){
    
    set(PLOTNOW);
    assetList("OandaEuropeFX45");
    StartDate = 2010;
    BarPeriod = 1440;

    if( is(INITRUN) ){
        int k = 0;
        while(asset(loop(Assets))){
            StDevs[k].Sym = MonTRs[k].Sym = MonHL[k].Sym = Symbol;
            k++;
        }
    }

    int k = 0;
    while(asset(loop(Assets))){
        int i; double Rets[LEN];
        for( i = 0; i < LEN; i++ )        
            Rets[i] = ( priceClose(i)/priceOpen(i)-1 )*100;
        StDevs[k].Val = StdDev(Rets,LEN)*3;
        if( day(0) == 1 ){
            MonTRs[k].Val = ( MonHL[k].Val1/MonHL[k].Val2-1 )*100;
            MonHL[k].Val1 = priceHigh(0); 
            MonHL[k].Val2 = priceLow(0);
        }
        else{
            if( priceHigh(0) > MonHL[k].Val1 )
                MonHL[k].Val1 = priceHigh(0);
            if( priceLow(0) < MonHL[k].Val2 )
                MonHL[k].Val2 = priceLow(0);
        }
        plot("StDev",StDevs[k].Val,BARS+NEW,RED);
        plot("MonTR",MonTRs[k].Val,LINE,BLUE);
        k++;
    }

    // int i;
    // for( i = 0; i < ASSETS; i++ )
    // {
    //     printf("\n%d Sym= %s %s, Val= %f", i, StDevs[i].Sym, MonTRs[i].Sym, StDevs[i].Val );
    // }
    
}