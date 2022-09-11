

#include <NexowFunctions.h>

void run(){

    set(PLOTNOW);
    assetList("AssetsFix");
    StartDate = 2005;
    BarPeriod = 1440;
    LookBack = 200;

    double MA1 = ZMA(series(priceClose()),40);
    double MA2 = ZMA(series(priceClose()),80);
    plot("MA1",MA1,0,RED);
    plot("MA2",MA2,0,BLUE);

    double* MA1s = series(MA1);
    double* MA2s = series(MA2);

    static int Dir;
    static double Max, Min;
    static int MaxN, MinN;
    static double AccUp, AccDn;

    if( Dir == 1 ){
        if( priceClose(0) > Max ){
            Max = priceClose(0);
            MaxN = 0;
        }
        else MaxN++;
    }
    else if( Dir == -1 ){
        if( priceClose(0) < Min ){
            Min = priceClose(0);
            MinN = 0;
        }
        else MinN++;
    }
    
    if( crossUnder(MA1s,MA2s) ){
        Min = priceClose(0);
        MinN = 0;
        AccDn = ((priceClose(0)/priceClose(MaxN)-1)*100)/(MaxN+1);
        AccUp = 0;
    }
    else if( crossOver(MA1s,MA2s) ){
        Max = priceClose(0);
        MaxN = 0;
        AccUp = ((priceClose(0)/priceClose(MinN)-1)*100)/(MinN+1);
        AccDn = 0;
    }

    if( MA1 > MA2 ){
        Dir = 1;
    }
    else if( MA1 < MA2 ){
        Dir = -1;
    }

    double Thres = 0.25;

    plot("Max",Max,0,RED);
    plot("Min",Min,0,BLUE);

    plot("Z",0,1,BLACK);
    plot("AccDn",AccDn,BARS,RED);
    plot("AccUp",AccUp,BARS,BLUE);
    plot("T+",Thres,0,BLACK);
    plot("T-",-Thres,0,BLACK);

    plot("MaxN",MaxN,BARS+NEW,RED);
    plot("MinN",MinN,BARS,BLUE+TRANSP);

    /*
    char* Code = "096742";
    
    double OI = (COT_OpIn(1,Code,TRUE));
    double NC = (COT_NonCom(2,Code,TRUE));

    plot("OI",OI,1,BLACK);

    plot("NC",NC,1,BLUE);
    plot("Z1",0,0,BLACK);
    
    */
  
}