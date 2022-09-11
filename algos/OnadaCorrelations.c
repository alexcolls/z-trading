
#include <nexow.h>

#define ASSETS 124
#define XY 15376
#define LEN 780

symvals Ret[ASSETS];
sym2val Pxy[XY];

void run(){
    
    set(PLOTNOW);
    assetList("OandaEuropeALL");
    StartDate = 2015;
    BarPeriod = 1440;

    if( is(INITRUN) ){
        int k = 0;
        while(asset(loop(Assets))){
            Ret[k].Sym = Symbol;
            k++;
        }
        int i, j;
        for( i = 0; i < ASSETS; i++ ){
            for( j = 0; j < ASSETS; j++ ){
                Pxy[i+j].Sym2 = Ret[i].Sym;
                Pxy[i+j].Sym1 = Ret[j].Sym;
            }
        }
    }

    int i;
    for( i = 0; i < XY; i++ ){
        printf("\n%d, %s, %s", i, Pxy[i].Sym1, Pxy[i].Sym2);
    }
    printf("\n");
    
}