
// G12 Top Long-Short //

#include <NexowFunctions.h>

#define ASSETS 66
#define MA1_p 10
#define MA2_p 20
#define TOP 10

void swap(symval *xp, symval *yp)
{
    symval *temp = xp;
    xp = yp; 
    yp = temp; 
} 

void run(){

    set(PLOTNOW);

    BarPeriod = 1440;
    StartDate = 2015;

    symval Dists[ASSETS];
    int k;

    while(asset(loop(Assets))){

        double* Prices = series(priceClose());    
        double MA1 = EMA(Prices,MA1_p);
        plot("MA1",MA1,0,RED);
        double MA2 = EMA(Prices,MA2_p);
        plot("MA2",MA2,0,BLUE);
        double Dist = ( (priceClose(0)-MA1)/MA1 + (priceClose(0)-MA2)/MA2 )*10000;
        plot("Dist",Dist,1,RED);     

        Dists[k].Sym = Symbol;
        Dists[k].Val = Dist;
        k++;
    }

    int i;
    for( i = 0; i < ASSETS; i++)
    {
        printf("\ni= %d, Symbol= %s, Value= %f", i, Dists[i].Sym, Dists[i].Val);
    }

    sortsymval(ASSETS,Dists);

    for( i = 0; i < ASSETS; i++)
    {
        printf("\nKK= %d, Sym= %s, Val= %f", i, Dists[i].Sym, Dists[i].Val);
    }

    printf("\n");


    symval Best[TOP], Worst[TOP];

    for( i = 0; i < TOP; i++)
    {
        Best[i].Sym = Dists[i].Sym;
        Best[i].Val = Dists[i].Val;
    }

    for( i = 0; i < TOP; i++)
    {
        printf("\nBest= %d, Sym= %s, Val= %f", i, Best[i].Sym, Best[i].Val);
    }

    int j;
    for( i = ASSETS-1; i > ASSETS-TOP-1; i--)
    {
        Worst[j].Sym = Dists[i].Sym;
        Worst[j].Val = Dists[i].Val;
        j++;
    }

    for( i = 0; i < TOP; i++)
    {
        printf("\nWorst= %d, Sym= %s, Val= %f", i, Worst[i].Sym, Worst[i].Val);
    }

    printf("\n");

    int AUD,CAD,CHF,EUR,GBP,HKD,JPY,NZD,SGD,USD,XAG,XAU;
    for( i = 0; i < TOP; i++)
    {
        asset(Best[i].Sym);
        if(strcmp(Base(),"AUD") == 0){AUD++;} else if(strcmp(Term(),"AUD") == 0){AUD--;}
        if(strcmp(Base(),"CAD") == 0){CAD++;} else if(strcmp(Term(),"CAD") == 0){CAD--;}
        if(strcmp(Base(),"CHF") == 0){CHF++;} else if(strcmp(Term(),"CHF") == 0){CHF--;}
        if(strcmp(Base(),"EUR") == 0){EUR++;} else if(strcmp(Term(),"EUR") == 0){EUR--;}
        if(strcmp(Base(),"GBP") == 0){GBP++;} else if(strcmp(Term(),"GBP") == 0){GBP--;}
        if(strcmp(Base(),"HKD") == 0){HKD++;} else if(strcmp(Term(),"HKD") == 0){HKD--;}
        if(strcmp(Base(),"JPY") == 0){JPY++;} else if(strcmp(Term(),"JPY") == 0){JPY--;}
        if(strcmp(Base(),"NZD") == 0){NZD++;} else if(strcmp(Term(),"NZD") == 0){NZD--;}
        if(strcmp(Base(),"SGD") == 0){SGD++;} else if(strcmp(Term(),"SGD") == 0){SGD--;}
        if(strcmp(Base(),"USD") == 0){USD++;} else if(strcmp(Term(),"USD") == 0){USD--;}
        if(strcmp(Base(),"XAG") == 0){XAG++;} else if(strcmp(Term(),"XAG") == 0){XAG--;}
        if(strcmp(Base(),"XAU") == 0){XAU++;} else if(strcmp(Term(),"XAU") == 0){XAU--;}
        asset(Worst[i].Sym);
        if(strcmp(Base(),"AUD") == 0){AUD--;} else if(strcmp(Term(),"AUD") == 0){AUD++;}
        if(strcmp(Base(),"CAD") == 0){CAD--;} else if(strcmp(Term(),"CAD") == 0){CAD++;}
        if(strcmp(Base(),"CHF") == 0){CHF--;} else if(strcmp(Term(),"CHF") == 0){CHF++;}
        if(strcmp(Base(),"EUR") == 0){EUR--;} else if(strcmp(Term(),"EUR") == 0){EUR++;}
        if(strcmp(Base(),"GBP") == 0){GBP--;} else if(strcmp(Term(),"GBP") == 0){GBP++;}
        if(strcmp(Base(),"HKD") == 0){HKD--;} else if(strcmp(Term(),"HKD") == 0){HKD++;}
        if(strcmp(Base(),"JPY") == 0){JPY--;} else if(strcmp(Term(),"JPY") == 0){JPY++;}
        if(strcmp(Base(),"NZD") == 0){NZD--;} else if(strcmp(Term(),"NZD") == 0){NZD++;}
        if(strcmp(Base(),"SGD") == 0){SGD--;} else if(strcmp(Term(),"SGD") == 0){SGD++;}
        if(strcmp(Base(),"USD") == 0){USD--;} else if(strcmp(Term(),"USD") == 0){USD++;}
        if(strcmp(Base(),"XAG") == 0){XAG--;} else if(strcmp(Term(),"XAG") == 0){XAG++;}
        if(strcmp(Base(),"XAU") == 0){XAU--;} else if(strcmp(Term(),"XAU") == 0){XAU++;}
    }

    printf("\nAUD= %d\nCAD= %d\nCHF= %d\nEUR= %d\nGBP= %d\nHKD= %d\nJPY= %d\nNZD= %d\nSGD= %d\nUSD= %d\nXAG= %d\nXAU= %d",AUD,CAD,CHF,EUR,GBP,HKD,JPY,NZD,SGD,USD,XAG,XAU);

    printf("\n");
/*
    symval Index[10];
    for( i = 0; i < TOP; i++)
    {
        asset(Best[i].Sym);
        char*   Base = Base();
        char*   Term = Term();
        printf("\n%s %s",Base,Term);
        for( j = 0; j < 10; j++){
            if(strcmp(Base,Index[j].Sym) == 0)
                Index[j].Val++;
            if(strcmp(Term,Index[j].Sym) == 0)
                Index[j].Val--;
        }

    }
*/

}