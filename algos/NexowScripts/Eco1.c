

#include <NexowFunctions.h>

void run(){

    set(PLOTNOW);
    assetList("AssetsFix");
    StartDate = 2005;
    BarPeriod = 60;
    LookBack = 900;

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

    
    if( EURcpic > 1.5 && EURcpic < 2.5 )
        Dir += 2;
    else if( EURcpic > 1 && EURcpic < 3 )
        Dir += 1;
    else if( EURcpic > 0 && EURcpic < 1 )
        Dir -= 1;
    else if( EURcpic < -2 )
        Dir -= 3;
    else if( EURcpic < 0 )
        Dir -= 2;
    else if( EURcpic > 3 )
        Dir -= 1;
    else if( EURcpic > 4 )
        Dir -= 2;
    else
        Dir -= 1;

    if( USDcpic > 1.5 && USDcpic < 2.5 )
        Dir -= 2;
    else if( USDcpic > 1 && USDcpic < 3 )
        Dir -= 1;
    else if( USDcpic > 0 && USDcpic < 1 )
        Dir += 1;
    else if( USDcpic < -2 )
        Dir += 3;
    else if( USDcpic < 0 )
        Dir += 2;
    else if( USDcpic > 4 )
        Dir += 2;
    else if( USDcpic > 3 )
        Dir += 1;
    else
        Dir += 1;
    
    
    
    // if( EURggr > USDggr )
    //     Dir++;
    // else Dir--;

    
    // if( EURir > USDir )
    //     Dir++;
    // else Dir--;

    
    // if( abs(EURcpic-2) < abs(USDcpic-2) )
    //     Dir++;
    // else Dir--;
    
    double EURsl = LinearRegSlope(series(EURunr),800);
    double USDsl = LinearRegSlope(series(USDunr),800);
    //plot("EURsl",EURsl,1,BLUE);
    //plot("USDsl",USDsl,0,RED);
    /*
    if( EURsl < 0 )
        Dir++;
    else Dir--;

    if( USDsl < 0 )
        Dir--;
    else Dir++;
    */
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
    


    plot("EURir",EURir,1,BLUE);
    plot("EURcpic",EURcpic,0,BLACK);
    plot("EUR3",3,0,DARKGREEN);
    plot("EUR1",1,0,DARKGREEN);
    plot("EUR0",0,0,DARKGREEN);

    plot("USDir",USDir,1,RED);
    plot("USDcpic",USDcpic,0,BLACK);
    plot("USD3",3,0,DARKGREEN);
    plot("USD1",1,0,DARKGREEN);
    plot("USD0",0,0,DARKGREEN);
    
    // plot("1",0,1,BLACK);
    // plot("EURggr",EURggr,0,BLUE);
    // plot("USDggr",USDggr,0,RED);
    // //plot("GGR",EURggr-USDggr,0,BLACK);
    
    
    // plot("2",0,1,BLACK);
    // plot("EURir",EURir,0,BLUE);
    // plot("USDir",USDir,0,RED);
    // //plot("IR",EURir-USDir,0,BLACK);

    // plot("3",0,1,BLACK);
    // plot("EURcpic",EURcpic,0,BLUE);
    // plot("USDcpic",USDcpic,0,RED);
    // //plot("CPIC",EURcpic-USDcpic,0,BLACK);

    // plot("23",0,1,BLACK);
    // plot("EURint",EURir-EURcpic,0,BLUE);
    // plot("USDint",USDir-USDcpic,0,RED);
    // //plot("CPIC",EURcpic-USDcpic,0,BLACK);



    // plot("4",0,1,BLACK);
    // plot("EURunr",EURunr,0,BLUE);
    // plot("USDunr",USDunr,0,RED);
    // //plot("UNR",EURunr-USDunr,0,BLACK);

    // plot("5",0,1,BLACK);
    // //plot("EURgdg",EURgdg,0,BLUE);
    // //plot("USDgdg",USDgdg,0,RED);
    // plot("GDG",EURgdg-USDgdg,0,BLACK);

    // plot("6",0,1,BLACK);
    // plot("EURbot",EURbot,0,BLUE);
    // plot("USDbot",USDbot,0,RED);
    // //plot("BOT",EURbot-USDbot,0,BLACK);

    // plot("7",0,1,BLACK);
    // plot("EURcagdp",EURcagdp,0,BLUE);
    // //plot("USDcagdp",USDcagdp,0,RED);
    // //plot("CAGDP",EURcagdp-USDcagdp,0,BLACK);
    

    


    
  
}