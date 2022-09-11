

#include <NexowFunctions.h>

void run(){

    set(PLOTNOW);
    assetList("AssetsFix");
    StartDate = 2005;
    BarPeriod = 60;
    LookBack = 900;

    const char* Format = "%Y-%m-%d,f1";

    double EURggr = dataFromQuandl(1,Format,"SGE/EURUNR",1);
    double USDggr = dataFromQuandl(11,Format,"SGE/USAUNR",1);

    static double EUR, USD, EURc, USDc;
    int Dir = 0;

    if( EURggr != EUR && USDggr != USD ){
        EURc = (EURggr/EUR-1)*100;
        EUR = EURggr;
        USDc = (USDggr/USD-1)*100;
        USD = USDggr;
        if( EURc > 0 && USDc < 0 )
            Dir = -1;
        else if( EURc < 0 && USDc > 0 )
            Dir = 1;
    }  

    if( TradeIsLong && Dir < 0 )
        exitLong();
    else if( TradeIsShort && Dir > 0 )
        exitShort();

    if( !TradeIsOpen ){
        if( Dir > 0 )
            enterLong();
        else if( Dir < 0 )
            enterShort();
    }

    plot("00",0,1,BLACK);
    plot("EURc",EURc,0,BLUE);
    plot("USDc",USDc,0,RED);

    plot("0",0,1,BLACK);
    plot("EURggr",EURggr,0,BLUE);
    plot("USDggr",USDggr,0,RED);


  

    


    
  
}