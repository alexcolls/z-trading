

#include <NexowFunctions.h>

void run(){

    set(PLOTNOW);
    assetList("AssetsFix");
    StartDate = 2005;
    BarPeriod = 60;
    LookBack = 200;  

    const int Len = 120;
    const double Open = 0.5, Close = 0.8;

    static double LastCOT, COTp, PP;

    char* Code = "096742";
    double NC = COT_NonCom(2,Code,TRUE);
    double CO = COT_Comm(3,Code,TRUE);
    double NN = CO+NC;

    double Dir = 0, DirNC = 0;

    static int count;

    if( NN != LastCOT ){
        if( LastCOT > 0 && NN < 0 ){
            enterLong();
            count = 0;
            PP = priceClose(0);
        }
        else if( LastCOT < 0 && NN > 0 ){
            enterShort();
            count = 0;
            PP = priceClose(0);
        }
        else{
            if( NN < LastCOT )
                count--;
            else if( NN > LastCOT )
                count++;
        }
        COTp = priceClose(0);
    }

    LastCOT = NN;

    plot("COTp",COTp,0,RED);
    plot("PP",PP,0,BLUE);

    plot("NN",NN,1,BLACK);
    plot("Z",0,0,BLACK);

    plot("NC",NC,1,BLACK);
    plot("CO",CO,0,BLUE);
    plot("Z1",0,0,BLACK);

    plot("F",count,BARS+NEW,RED);
    plot("Z2",0,0,BLACK);




    
  
}