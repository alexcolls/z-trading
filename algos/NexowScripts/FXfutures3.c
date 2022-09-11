
#include <NexowFunctions.h>

void run(){

    set(PLOTNOW);
    assetList("AssetsFix");
    StartDate = 2005;
    BarPeriod = 60;
    BarZone = UTC;
    LookBack = 100;

    const char* Format = "%Y-%m-%d,f1,f2,f3,f4,f5,f6,f7,f8";
    const char* Code = "CHRIS/CME_EC1";

    asset("EUR/USD");
    double EURopen = dataFromQuandl(1,Format,Code,1);
    double EURclose = dataFromQuandl(2,Format,Code,6);
    static double EURo, EURc, EURos, EURcs;
    static int EURpos = 0;
    if( EURopen != EURo || EURclose != EURc ){
        EURos = EURcs;
        EURcs = priceClose(0);
        exitLong(); exitShort();
        EURpos = 0;
    }
    if( EURopen != 0 )
        EURo = EURopen;
    if( EURclose != 0 )
        EURc = EURclose;
    if( EURc < EURo && EURcs > EURos && EURpos >= 0 ){
        enterShort();
        EURpos = -1;
    }
    else if( EURc > EURo && EURcs < EURos && EURpos <= 0 ){
        enterLong();
        EURpos = 1;
    }
    plot("EURo",EURo,0,BLUE+TRANSP);
    plot("EURc",EURc,0,BLUE);
    plot("EURos",EURos,0,RED+TRANSP);
    plot("EURcs",EURcs,0,RED);
    
   
    
}


