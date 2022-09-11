

#include <NexowFunctions.h>

typedef struct{
char Sym[4];
char Code[7];
int Inv;
} symcode;

symcode COTcodes[8];

void SetCOTcodes(){
    strcpy(COTcodes[0].Sym,"AUD");
    strcpy(COTcodes[0].Code,"232741");
    COTcodes[0].Inv = 1;
    strcpy(COTcodes[1].Sym,"CAD");
    strcpy(COTcodes[1].Code,"090741");
    COTcodes[1].Inv = -1;
    strcpy(COTcodes[2].Sym,"CHF");
    strcpy(COTcodes[2].Code,"092741");
    COTcodes[2].Inv = -1;
    strcpy(COTcodes[3].Sym,"EUR");
    strcpy(COTcodes[3].Code,"099741");
    COTcodes[3].Inv = 1;
    strcpy(COTcodes[4].Sym,"GBP");
    strcpy(COTcodes[4].Code,"096742");
    COTcodes[4].Inv = 1;
    strcpy(COTcodes[5].Sym,"JPY");
    strcpy(COTcodes[5].Code,"097741");
    COTcodes[5].Inv = -1;
    strcpy(COTcodes[6].Sym,"NZD");
    strcpy(COTcodes[6].Code,"112741");
    COTcodes[6].Inv = 1;
    strcpy(COTcodes[7].Sym,"USDindex");
    strcpy(COTcodes[7].Code,"098662");
    COTcodes[7].Inv = 1;
}


void run(){
    
    set(PLOTNOW);
    assetList("FX28");
    StartDate = 2005;
    BarPeriod = 60;
    LookBack = 300;
    Spread = Commission = 0;

    if( is(INITRUN) ){
        SetCOTcodes();
    }

   double Cot;
    while(asset(loop(Assets))){
        bool OnlyFutures = TRUE;
        double X, Y;
        int i;
        for( i = 0; i < 8; i++){
            if( strstr(COTcodes[i].Sym,Base()) ){
                X = (COT_NonCom(i+1,COTcodes[i].Code,OnlyFutures)*COTcodes[i].Inv);
            }
            else if( strstr(COTcodes[i].Sym,Term()) ){
                Y = (COT_NonCom(i+1,COTcodes[i].Code,OnlyFutures)*COTcodes[i].Inv);
            }
        }
        double Osc = X-Y;

        if( strstr(Symbol,"CAD/CHF") ){
            Cot = Osc;
        }

    }

    static double Max, Min;

    asset("CAD/CHF");

    double MA = EMA(series(price()),200);
    double MA2 = EMA(series(price()),10);
    double* MAs = series(MA,3);

    if( peak(MAs) )
        Max = MAs[1];
    else if( valley(MAs) )
        Min = MAs[1];
    
    if( MA > Max )
        Max = MA;
    else if( MA < Min )
        Min = MA;

    double Vol = (Max-Min);///priceClose(0);
    double Vol2 = (MA2-MA);///priceClose(0);
    double Lev = EMA(series(Vol),200);

    double* Sig = series(Vol2);


    plot("MA",MA,0,BLACK);
    plot("MA2",MA2,0,BLUE);
    plot("Max",Max,0,RED);
    plot("Min",Min,0,GREEN);

    plot("Vol",Vol,1,BLUE);
    plot("Vol-",-Vol,0,BLUE);
    plot("Vol2",Vol2,0,RED);
    plot("Z1",0,0,BLACK);
    plot("T+",Lev,0,BLACK);
    plot("T-",-Lev,0,BLACK);

    plot("COT",Cot,1,BLUE);
    plot("Z",0,0,BLACK);








  
}