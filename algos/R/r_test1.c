
#include <NexowFunctions.h>

void run()
{
    Rstart("R_Dash2.r",2);

    //Rstart("r_test3.r",0);
    set(PLOTNOW);
    StartDate = 2005;
    BarPeriod = 1440;
    LookBack = 200;

    assetList("AssetsFix45");
    asset("AUD/USD");

    double MA = USDIdx8();

    plot("MA",MA,1,RED);


    Rx("MyFunc");

    fopen("C:\\ZorroBeta\\Strategy\\R_Dash2.r","r");

    system(r_command.c_str());



    
    
    //Rstart("r_test3.r",2); // enable output 
    

}

