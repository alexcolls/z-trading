
// G12 Top Long-Short //

#include <NexowFunctions.h>

#define ASSETS 45
#define MA1_p 20
#define MA2_p 40
#define TOP 10
#define CROSS_p 3

int Cross(double* Vals1, double* Vals2, int nPeriods){
    int i;
    for ( i = 0; i < nPeriods; i++)
    {
        if( Vals1[i]>Vals2[i] && Vals1[i+1]<Vals2[i+1] )
            return 1;
        if( Vals1[i]<Vals2[i] && Vals1[i+1]>Vals2[i+1] )
            return -1;
    }
}

void run(){

    Capital = 100000;
    
    BarPeriod = 1440;
    StartDate = 2007;

    assetList("AssetsFix45");
    setFees(0,0,-1,5);
    setFXaccounting(1,-1);

    set(PLOTNOW);

    int i, j, k;
    double AvgDists;
    symval Dists[ASSETS];
    while(asset(loop(Assets))){
        
        Leverage = 100;
        double* Prices = series(priceClose());    
        double MA1 = ZMA(Prices,MA1_p);
        //plot("MA1",MA1,0,RED);
        double MA2 = ZMA(Prices,MA2_p);
        //plot("MA2",MA2,0,BLUE);
        //plot("Cross",Cross(series(MA1),series(MA2),CROSS_p),1,RED); 
        double Dist = ( (priceClose(0)-MA1)/MA1 + (priceClose(0)-MA2)/MA2 )*100;
        //plot("Dist",Dist,1,RED);

        Dists[k].Sym = Symbol;
        Dists[k].Val = Dist;
        k++;

    }  

    for( i = 0; i < ASSETS; i++)
    {
        AvgDists += abs(Dists[i].Val)/ASSETS; 
    }
    while(asset(loop(Assets))){
        //plot("AvgDists",AvgDists,0,BLACK);
        //plot("-AvgDists",-AvgDists,0,BLACK);        
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
            //plot("Top",Top,1,BLUE);
            plot("MarginTotal",MarginTotal,1,RED);
            plot("Account",100000,0,BLACK);
            plot("MArginVal",MarginVal,1,RED);
            plot("RiskTotal",RiskTotal,1,RED);
        }
        
        double Percentage = 0.1;
        Margin = Percentage/100 * Balance;
        double Thres = 1;
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