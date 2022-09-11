

#include <NexowFunctions.h>

void run(){

    set(PLOTNOW);
    assetList("AssetsFix");
    StartDate = 2005;
    BarPeriod = 60;
    LookBack = 10000;

    double LP = LowPass(series(price()),6000);
    plot("LP",LP,0,RED);

    const char* Format = "%Y-%m-%d,f1";

    double EURggr = dataFromQuandl(1,Format,"SGE/EURGGR",1);
    double EURir = dataFromQuandl(2,Format,"SGE/EURIR",1);
    double EURcpic = dataFromQuandl(3,Format,"SGE/EURCPIC",1);
    double EURunr = dataFromQuandl(4,Format,"SGE/EURUNR",1);
    double EURgdg = dataFromQuandl(5,Format,"SGE/EURGDG",1);
    double EURbot = dataFromQuandl(6,Format,"SGE/EURBOT",1);
    double EURcagdp = dataFromQuandl(7,Format,"SGE/EURCA",1);

    double USDggr = dataFromQuandl(11,Format,"SGE/USAGGR",1);
    double USDir = dataFromQuandl(22,Format,"SGE/USAIR",1);
    double USDcpic = dataFromQuandl(33,Format,"SGE/USACPIC",1);
    double USDunr = dataFromQuandl(44,Format,"SGE/USAUNR",1);
    double USDgdg = dataFromQuandl(55,Format,"SGE/USAGDG",1);
    double USDbot = dataFromQuandl(66,Format,"SGE/USABOT",1);
    double USDcagdp = dataFromQuandl(77,Format,"SGE/USACA",1);

    int Dir = 0;

    double EURma = EMA(series(EURbot),6000);
    double USDma = EMA(series(USDbot),6000);

    static double EURbot2, USDbot2;
    static int EUR, USD;

    if( EURbot != EURbot2 || USDbot != USDbot2 ){
        if( EURbot > EURbot2 )
            EUR = -1;
        else if( EURbot < EURbot2 )
            EUR = 1;
        else EUR = 0;
        EURbot2 = EURbot;
        if( USDbot > USDbot2 )
            USD = -1;
        else if( USDbot < USDbot2 )
            USD = 1;
        else USD = 0;
        USDbot2 = USDbot;
        exitLong();
        exitShort();
    }

    Dir = USD-EUR;

    plot("Dir",Dir,1,RED);
    plot("Z",0,0,BLACK);

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
    
    plot("EUR",0,1,BLACK);
    plot("EURma",EURma,0,GREY);
    plot("EURbot",EURbot,0,BLUE);

    plot("USD",0,1,BLACK);
    plot("USDma",USDma,0,GREY);
    plot("USDbot",USDbot,0,RED);


  

    


    
  
}