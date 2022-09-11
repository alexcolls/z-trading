

#include <NexowFunctions.h>

void run(){

    set(PLOTNOW);
    assetList("AssetsFix");
    StartDate = 2005;
    BarPeriod = 60;
    LookBack = 200;

    const char* Format = "%Y-%m-%d,f1";

    double GBPgr = dataFromQuandl(1,Format,"SGE/GBRGGR",1);
    double USDgr = dataFromQuandl(2,Format,"SGE/USAGGR",1);
    double EURgr = dataFromQuandl(3,Format,"SGE/EURGGR",1);

    static double LastGBP, LastUSD, LastEUR;
    static int GBP, USD, EUR;

    if( GBPgr > LastGBP )
        GBP = 1;
    else if( GBPgr < LastGBP )
        GBP = -1;

    LastGBP = GBPgr;

    if( USDgr > LastUSD )
        USD = 1;
    else if( USDgr < LastUSD )
        USD = -1;

    LastUSD = USDgr;

    if( EURgr > LastEUR )
        EUR = 1;
    else if( EURgr < LastEUR )
        EUR = -1;

    LastEUR = EURgr;
    

    plot("GBPgr",GBPgr,1,BLUE);
    plot("USDgr",USDgr,0,RED);
    plot("EURgr",EURgr,0,DARKGREEN);
    plot("0",0,0,BLACK);

    plot("GBP",GBP,1,BLUE);
    plot("USD",USD,0,RED);
    plot("EUR",EUR,0,DARKGREEN);
    plot("00",0,0,BLACK);

    asset("GBP/USD");
    static int GBPUSD;
    if( GBP == 1 && USD == -1 ){
        if( GBPUSD != 1 ){
            enterLong();
            GBPUSD = 1;
        }
    }
    else if( GBP == -1 && USD == 1 ){
        if( GBPUSD != -1 ){
            enterShort();
            GBPUSD = -1;
        }
    }
    else{
        exitLong();
        exitShort();
        GBPUSD = 0;
    }

    asset("EUR/GBP");
    static int EURGBP;
    if( EUR == 1 && GBP == -1 ){
        if( EURGBP != 1 ){
            enterLong();
            EURGBP = 1;
        }
    }
    else if( EUR == -1 && GBP == 1 ){
        if( EURGBP != -1 ){
            enterShort();
            EURGBP = -1;
        }
    }
    else{
        exitLong();
        exitShort();
        EURGBP = 0;
    }

    asset("EUR/USD");
    static int EURUSD;
    if( EUR == 1 && USD == -1 ){
        if( EURUSD != 1 ){
            enterLong();
            EURUSD = 1;
        }
    }
    else if( EUR == -1 && USD == 1 ){
        if( EURUSD != -1 ){
            enterShort();
            EURUSD = -1;
        }
    }
    else{
        exitLong();
        exitShort();
        EURUSD = 0;
    }
    




    
  
}