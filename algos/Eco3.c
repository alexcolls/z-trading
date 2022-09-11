

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

    static double EURgdg2, USDgdg2, EUR, USD;

    if( EURgdg != EURgdg2 ){
        EUR = (EURgdg/EURgdg2-1)*100;
        EURgdg2 = EURgdg;
    }
    if( USDgdg != USDgdg2 ){
        USD = (USDgdg/USDgdg2-1)*100;
        USDgdg2 = USDgdg;
    }

    plot("Z",0,1,BLACK);
    plot("EUR",EUR,0,BLUE);
    plot("USD",USD,0,RED);
    

    plot("Z1",0,1,BLACK);
    plot("EURgdg",EURgdg,0,BLUE);

    plot("Z2",0,1,BLACK);
    plot("USDgdg",USDgdg,0,RED);



  

    


    
  
}