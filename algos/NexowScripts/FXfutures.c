
#include <NexowFunctions.h>

void run(){

    set(PLOTNOW);
    assetList("FX28");
    StartDate = 2005;
    BarPeriod = 60;
    BarZone = UTC;
    LookBack = 600;

    asset("GBP/USD");

    const char* Format = "%Y-%m-%d,f1,f2,f3,f4,f5,f6,f7,f8";
    const char* Code = "CHRIS/CME_BP2";
    
    double Open = dataFromQuandl(1,Format,Code,1);
    double High = dataFromQuandl(2,Format,Code,2);
    double Low = dataFromQuandl(3,Format,Code,3);
    double Close = dataFromQuandl(4,Format,Code,6);
    //double Volume = dataFromQuandl(5,Format,Code,7);
    //double OI = dataFromQuandl(6,Format,Code,8);

    static double O, H, L, C;
    static double Os, Cs;
    static int P;
    if( Open != O || Close != C ){
        Os = Cs;
        Cs = priceClose(0);
        exitLong(); exitShort();
        P = 0;
    }
    if( Open != 0 )
        O = Open;
    if( High != 0 )
        H = High;
    if( Low != 0 )
        L = Low;
    if( Close != 0 )
        C = Close;

    double Diff = C-Cs;
    double Trend = EMA(series(Diff),200);
    
    plot("Open",O,0,BLUE+TRANSP);
    //plot("High",H,0,GREEN);
    //plot("Low",L,0,RED);
    plot("Close",C,0,BLUE);
    plot("OpenSpot",Os,0,RED+TRANSP);
    plot("CloseSpot",Cs,0,RED);
    //plot("Volume",Volume,1,BLUE);
    //plot("OI",OI,1,BLUE);
    plot("Trend",Trend,1,BLUE);
    plot("Zero",0,0,BLACK);

    if( C < O && Cs > Os && P >= 0 ){
        enterShort();
        P = -1;
    }
    else if( C > O && Cs < Os && P <= 0){
        enterLong();
        P = 1;
    }

    //plot()

    

}


