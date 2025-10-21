
#include <nexow.h>

#define AU200 "AU200_AUD_2019.t1"


void PlotT1( int Handle, char* T1file ){

    dataLoad(Handle,T1file,2);
    int TimeRow = 0, PriceRow = 0;

    while( Bar < MaxBars ){

        double Time = dataVar(1,TimeRow,0);
        double Price = dataVar(1,PriceRow,1);

        static double Ask, Bid;
        if( Price > 0 )
            Ask = Price;
        else if( Price < 0 )
            Bid = Price;

        printf("\n%s %f",Time,Price);

        priceQuote(Time,Price);

        plot("Ask",Ask,1,RED);
        plot("Bid",Bid,0,BLUE);

        TimeRow++;
        PriceRow++;

    }

}

void run(){
    
    set(PLOTNOW);
    assetList("OandaEuropeALL2");
    //History = ".t1";
    StartDate = 2019;
    BarPeriod = 1;

    asset("AU200_AUD");

    plot("Spread",marketVal(0),1,RED);
    plot("Freq",marketVol(0),1,RED);

    //PlotT1(1,"AU200_AUD_2019.t1");


    
}