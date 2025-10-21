
#include <NexowFunctions.h>

void run(){

    set(PLOTNOW);
    PlotHeight1 = 600;
    PlotHeight2 = 200;
    ColorUp = ColorDn = ColorWin = ColorLoss = ColorEquity = ColorDD = 0;

    assetList("AssetsFix45");
    StartDate = 2005;
    BarPeriod = 1440;
    
    double EURfx = EURIdx8();

    const char* Format = "%Y-%m-%d,f1";
    double EUR_GGR = dataFromQuandl(1,Format,"SGE/EURGGR",1);
    double EUR_GGRc = dataFromQuandl(1,Format,"SGE/EURGGR",1);
    double EUR_CPI = dataFromQuandl(2,Format,"SGE/EURCINF",1);
    double EUR_UNR = dataFromQuandl(3,Format,"SGE/EURUNR",1);
    double EUR_PPI = dataFromQuandl(4,Format,"SGE/EURPPIC",1);

    static double EUR_UNR2;

    EUR_UNR = (EUR_UNR/EUR_UNR2-1)*100;
    EUR_UNR2 = dataFromQuandl(3,Format,"SGE/EURUNR",1);

    plot("EURfx",EURfx,0,BLACK);
    plot("EUR_GGR",EUR_GGR,1,BLUE);
    plot("Z1",0,0,BLACK);
    plot("EUR_CPI",EUR_CPI,1,RED);
    plot("Z2",0,0,BLACK);
    plot("EUR_UNR",EUR_UNR,1,RED);
    plot("Z3",0,0,BLACK);
    plot("EUR_PPI",EUR_PPI,1,RED);
    plot("Z4",0,0,BLACK);
 
}