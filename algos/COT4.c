
#include <nexow.h>

void run(){

    set(PLOTNOW);
    assetList("AssetsFix");
    StartDate = 2007;
    BarPeriod = 1440;
    LookBack = 200;

    asset("EUR_USD");


    double COT_EUR = COT_NonCom(1,"099741",TRUE);
    double COT_EUR2 = COT_Comm(2,"099741",TRUE);
    double* COT_EURs = series(COT_EUR);
    double MA = LowPass(COT_EURs,120);
    plot("Z",0,1,BLACK);
    plot("COT_EUR",COT_EUR,0,BLUE);
    plot("COT_EUR2",COT_EUR2,0,RED);
    plot("MA",MA,0,RED);

    // static int Long, Short;
    // if( COT_EURs[2]>COT_EURs[3] ){
    //     Long++;
    //     Short = 0;
    // }
    // else if( COT_EURs[2]<COT_EURs[3] ){
    //     Short--;
    //     Long = 0;
    // }

    // plot("Long",Long,1,BLUE);
    // plot("Short",Short,0,RED);
    // plot("Zero",0,0,BLACK);

    // if( COT_EURs[2]>MA && COT_EURs[3]<MA ){
    //     enterLong();
    // }
    // else if( COT_EURs[2]<MA && COT_EURs[3]>MA ){
    //     enterShort();
    // }
   

}