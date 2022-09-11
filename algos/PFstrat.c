
// G12 Top Long-Short //

#include <NexowFunctions.h>


void run(){

    BarPeriod = 1440;
    StartDate = 2007;

    //assetList("AssetsFix");
    //Spread = Commission = RollLong = RollShort = 0;
    setFees(0.0,0.0,-1);

    set(PLOTNOW);

    int P1 = 15;
    int P2 = 10;
    while(asset(loop(Assets))){
        
        double* Prices = series(priceClose());
        double* PricesI = series(1/priceClose());     
        double PF1 = ProfitFactor(Prices,P1);
        double PF2 = ProfitFactor(Prices,P2);
        double PF1i = ProfitFactor(PricesI,P1);
        double PF2i = ProfitFactor(PricesI,P2);
        double* PF1_s = series(PF1);
        double* PF1i_s = series(PF1i);
        plot("PF1",PF1,1,BLUE);
        plot("PF2",PF2,0,BLUE+TRANSP);
        plot("PF1i",PF1i,0,RED);
        plot("PF2i",PF2i,0,RED+TRANSP);
        plot("One",1,0,BLACK);
        double Thres = 2;
        plot("Thres",Thres,0,BLACK);
        Margin = 1000;
        if( PF1 < Thres ){
            exitLong();
        }
        if( PF1i < Thres ){
            exitShort();
        }
        if( PF1_s[0] > Thres && PF1_s[1] < Thres ){
            enterLong();
        }
        if( PF1i_s[0] > Thres && PF1i_s[1] < Thres ){
            enterShort();
        }
        
        
    }  

}