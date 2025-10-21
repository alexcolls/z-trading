
#include <NexowFunctions.h>

void run(){

    set(PLOTNOW);
    PlotHeight1 = 600;
    PlotHeight2 = 200;
    //ColorUp = ColorDn = ColorWin = ColorLoss = ColorEquity = ColorDD = 0;

    assetList("AssetsFix45");
    StartDate = 2005;
    BarPeriod = 1440;

    const char* Format = "%Y-%m-%d,f1";
    double AUD = dataFromQuandl(1,Format,"SGE/AUSBOT",1);
    double CAD = dataFromQuandl(2,Format,"SGE/CANBOT",1);
    
    asset("AUD/USD");
    double AUDn = AUD*priceClose(30);
    
    asset("USD/CAD");
    double CADn = CAD/priceClose(30);
    
    asset("AUD/CAD");
    
    plot("Z1",0,1,BLACK);
    plot("AUD",AUD,0,BLUE);
    plot("Z2",0,1,BLACK);
    plot("CAD",CAD,0,RED);
    plot("Z3",0,1,BLACK);
    plot("AUDn",AUDn,0,BLUE);
    plot("CADn",CADn,0,RED);
    plot("Z4",0,1,BLACK);
    plot("AUDn-CADn",AUDn-CADn,0,BLUE);

}