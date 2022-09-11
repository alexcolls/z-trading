
// G12 Top Long-Short //

#include <NexowFunctions.h>

#define MA1_p 20
#define MA2_p 40
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

    BarPeriod = 1440;
    StartDate = 2007;

    //assetList("AssetsFix45");
    Spread = Commission = RollLong = RollShort = 0;
    //setFees(0.0,0.0,-1);

    set(PLOTNOW);

    //while(asset(loop(Assets))){
        
        double* Prices = series(priceClose());
        double* PricesI = series(1/priceClose());     
        double MA1 = ZMA(Prices,MA1_p);
        plot("MA1",MA1,0,RED);
        double MA2 = ZMA(Prices,MA2_p);
        plot("MA2",MA2,0,BLUE);
        int CRS = Cross(series(MA1),series(MA2),CROSS_p);
        plot("CRS",CRS,1,RED); 
        double Dist = ( (priceClose(0)-MA1)/MA1 + (priceClose(0)-MA2)/MA2 )*100;
        plot("Dist",Dist,1,RED);
        plot("Zero",0,0,BLACK);
        double* Dists = series(Dist);
        double* MA1s = series(MA1);
        double* MA2s = series(MA2);
        double  AvgD = ZMA(Dists,MA2_p);
        double* AvgDs = series(AvgD);
        plot("AvgD",AvgD,0,BLUE);

        double PF = ProfitFactor(Prices,10);
        double PF2 = ProfitFactor(PricesI,10);
        plot("PF",PF,1,BLUE);
        plot("PF2",PF2,0,RED);
        
        double Thres = 0;
        Margin = 1000;
        /*
        if( Dist > AvgD )
            exitLong();
        else if( AvgD > Thres && Dist < 0 )
            enterLong();        
        if( Dist < AvgD )
            exitShort();
        else if( AvgD < -Thres && Dist > 0 )
            enterShort();
        */
        if( AvgD > Thres && crossUnder(Dists,AvgDs) ){
            Stop = priceHigh(0);
            TakeProfit = MA1;
            enterShort();
        }
        else if( AvgD < -Thres && crossOver(Dists,AvgDs) ){
            Stop = priceLow(0);
            TakeProfit = MA1;
            enterLong();
        }
        
    //}  

}