

#include <NexowFunctions.h>

void run(){

    set(PLOTNOW);
    assetList("AssetsFix");
    StartDate = 2005;
    BarPeriod = 1440;
    LookBack = 300;

    double LP = LowPass(series(price()),200);
    plot("LP",LP,0,RED);

    const char* Format = "%Y-%m-%d,f1";

    double EUR10Y = dataFromQuandl(1,Format,"SGE/EURMKT",1);
    double USD10Y = dataFromQuandl(11,Format,"SGE/USAMKT",1);

    double EURma = EMA(series(EUR10Y),200);
    double USDma = EMA(series(USD10Y),200);

    double Osc = (EUR10Y-EURma)-(USD10Y-USDma);

    plot("Zero",0,1,BLACK);
    plot("Osc",Osc,0,RED);


    // if( TradeIsLong && Dir < 0 )
    //     exitLong();
    // else if( TradeIsShort && Dir > 0 )
    //     exitShort();

    // if( !TradeIsOpen ){
    //     if( Dir > 0 )
    //         enterLong();
    //     else if( Dir < 0 )
    //         enterShort();
    // }

    plot("1",0,1,BLACK);
    plot("EUR10Y",EUR10Y,0,BLUE);
    plot("EURma",EURma,0,BLUE+TRANSP);

    plot("2",0,1,BLACK);
    plot("USD10Y",USD10Y,0,RED);
    plot("USDma",USDma,0,RED+TRANSP);





    


    
  
}