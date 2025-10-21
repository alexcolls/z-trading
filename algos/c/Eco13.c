

#include <NexowFunctions.h>

void run(){

    set(PLOTNOW);
    assetList("AssetsFix");
    StartDate = 2000;
    BarPeriod = 60;
    LookBack = 900;

    const char* Format = "%Y-%m-%d,f1";

    double INF = dataFromQuandl(1,Format,"SGE/USACPIC",1);

    plot("0",0,NEW,BLACK);
    plot("INF",INF,0,RED);
    plot("Health",2,0,BLACK);

    double StrHyper = 5.0; // -2
    double Hyper = 4.0; // -1
    double HealtUp = 2.5; // 1
    double HealtDn = 1.5; // 2
    double Recession = 0.75; // 1
    double Deaf = 0.0; // 0
                    // -1
    int Trend;

    if( INF > StrHyper )
        Trend = -1;
    else if( INF > Hyper )
        Trend = 0;
    else if( INF > HealtUp )
        Trend = 1;
    else if( INF > HealtDn )
        Trend = 2;
    else if( INF > Recession )
        Trend = 1;
    else if( INF > Deaf )
        Trend = 0;
    else
        Trend = -1;
        
    plot("00",0,NEW,BLACK);
    plot("T",Trend,0,RED);

    if(!TradeIsOpen || TradeIsShort ){
        if( Trend > 0 ){
            Lots = 10*(double)Trend;
            enterLong();
        }
    }
    else{
        if( Trend == 0 ){
            exitLong(); 
            exitShort();
        }
    }

    if(TradeIsLong && Trend < 0){
        enterShort();
    }

  
}