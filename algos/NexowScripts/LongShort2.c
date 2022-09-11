
// G12 Top Long-Short //

#include <NexowFunctions.h>

#define ASSETS 45
#define MA1_p 20
#define MA2_p 40
#define TOP 10

void run(){

    Spread = Commission = RollLong = RollShort = 0;

    assetList("AssetsFix45");

    set(PLOTNOW);

    BarPeriod = 1440;
    StartDate = 2007;

    int i, j, k;
    double AvgDists;
    symval Dists[ASSETS];
    while(asset(loop(Assets))){
        
        double* Prices = series(priceClose());    
        double MA1 = ZMA(Prices,MA1_p);
        plot("MA1",MA1,0,RED);
        double MA2 = ZMA(Prices,MA2_p);
        plot("MA2",MA2,0,BLUE);     
        double Dist = ( (priceClose(0)-MA1)/MA1 + (priceClose(0)-MA2)/MA2 )*100;
        plot("Dist",Dist,1,RED); 

        Dists[k].Sym = Symbol;
        Dists[k].Val = Dist;
        k++;

    }  

    for( i = 0; i < ASSETS; i++)
    {
        AvgDists += abs(Dists[i].Val)/ASSETS; 
    }
    while(asset(loop(Assets))){
        plot("AvgDists",AvgDists,0,BLACK);
        plot("-AvgDists",-AvgDists,0,BLACK);        
    }
    
    sortsymval(ASSETS,Dists);

    symval Best[TOP];
    for( i = 0; i < TOP; i++)
    {
        Best[i].Sym = Dists[i].Sym;
        Best[i].Val = Dists[i].Val;
    }
    symval Worst[TOP];
    for( i = ASSETS-1; i > ASSETS-TOP-1; i--)
    {
        Worst[j].Sym = Dists[i].Sym;
        Worst[j].Val = Dists[i].Val;
        j++;
    }

    // Trading Rules //

        while(asset(loop(Assets))){
            
            int Top = 0;
            for( i = 0; i < TOP; i++){
                if( strcmp(Symbol,Best[i].Sym) == 0 ){
                    exitLong();
                    Top = 1;
                    //printf("\n%s %s %d", Symbol, "Best", i);
                    break;
                }
                else if( strcmp(Symbol,Worst[i].Sym) == 0 ){
                    exitShort();
                    Top = -1;
                    //printf("\n%s %s %d", Symbol, "Worst", i);
                    break;
                }
            }
            if( Top == 0 ){
                exitLong();
                exitShort();
            }
            plot("Top",Top,1,BLUE);
        }
        
        Margin = 1000;
        double Thres = 1.3;
        for( i = 0; i < TOP; i++)
        {
            if( Best[i].Val > AvgDists*Thres && Worst[i].Val < -AvgDists*Thres )
            {
                asset(Best[i].Sym);
                enterShort();
                asset(Worst[i].Sym);
                enterLong();
            }
        }

    // 

}