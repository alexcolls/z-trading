
#include <nexow.h>

#define ASSETS 124
#define LEN 60

int months[ASSETS];
int days[ASSETS];

void run(){
    
    set(PLOTNOW);
    assetList("OandaEuropeALL");
    StartDate = 2007;
    BarPeriod = 1440;

    if( is(INITRUN) ){
        int k = 0;
        while(asset(loop(Assets))){
            StDevs[k].Sym = MnATR[k].Sym = MonHL[k].Sym = Symbol;
            k++;
        }
    }

    int k = 0;
    while(asset(loop(Assets))){
        int i; double Rets[LEN];
        for( i = 0; i < LEN; i++ )        
            Rets[i] = ( priceClose(i)/priceOpen(i)-1 )*100;
        StDevs[k].Val = StdDev(Rets,LEN)*5;
        if( day(0) == 1 || days[k] > day(0) ){
            months[k]++; days[k] = 1;
            double LastMonATR = ( MonHL[k].Val1/MonHL[k].Val2-1 )*100;
            AddToDoublesList(MnATR[k].Vals,36,LastMonATR);
            MonHL[k].Val1 = priceHigh(0); 
            MonHL[k].Val2 = priceLow(0);
        }
        else{
            days[k]++;
            if( priceHigh(0) > MonHL[k].Val1 )
                MonHL[k].Val1 = priceHigh(0);
            if( priceLow(0) < MonHL[k].Val2 )
                MonHL[k].Val2 = priceLow(0);
        }
        double MonATR = SMA(MnATR[k].Vals,36);
        plot("StDev",StDevs[k].Val,BARS+NEW,RED);
        plot("LastATR",MnATR[k].Vals[0],0,GREEN);
        if(  months[k] > 36 )
            plot("MonATR",MonATR,0,BLUE);
        k++;
    }

    // int i;
    // for( i = 0; i < ASSETS; i++ )
    // {
    //     printf("\n%d Sym= %s %s, Val= %f", i, StDevs[i].Sym, MonTRs[i].Sym, StDevs[i].Val );
    // }
    
}