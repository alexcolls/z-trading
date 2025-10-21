

#include <NexowFunctions.h>

void run(){

    set(PLOTNOW);
    assetList("AssetsFix");
    StartDate = 2007;
    BarPeriod = 60;
    LookBack = 200;

    asset("EUR/USD");

    double DE_L = dataFromQuandl(1,"%Y-%m-%d,f1,f2,f3,f4,f5,f6,f7,f8,f9,f10,f11,f12,f13,f14,f15,f16,f17","CFTC/099741_FO_ALL",2);
    double DE_S = dataFromQuandl(1,"%Y-%m-%d,f1,f2,f3,f4,f5,f6,f7,f8,f9,f10,f11,f12,f13,f14,f15,f16,f17","CFTC/099741_FO_ALL",3);
    double AM_L = dataFromQuandl(1,"%Y-%m-%d,f1,f2,f3,f4,f5,f6,f7,f8,f9,f10,f11,f12,f13,f14,f15,f16,f17","CFTC/099741_FO_ALL",5);
    double AM_S = dataFromQuandl(1,"%Y-%m-%d,f1,f2,f3,f4,f5,f6,f7,f8,f9,f10,f11,f12,f13,f14,f15,f16,f17","CFTC/099741_FO_ALL",6);
    double LF_L = dataFromQuandl(1,"%Y-%m-%d,f1,f2,f3,f4,f5,f6,f7,f8,f9,f10,f11,f12,f13,f14,f15,f16,f17","CFTC/099741_FO_ALL",8);
    double LF_S = dataFromQuandl(1,"%Y-%m-%d,f1,f2,f3,f4,f5,f6,f7,f8,f9,f10,f11,f12,f13,f14,f15,f16,f17","CFTC/099741_FO_ALL",9);
    double OR_L = dataFromQuandl(1,"%Y-%m-%d,f1,f2,f3,f4,f5,f6,f7,f8,f9,f10,f11,f12,f13,f14,f15,f16,f17","CFTC/099741_FO_ALL",11);
    double OR_S = dataFromQuandl(1,"%Y-%m-%d,f1,f2,f3,f4,f5,f6,f7,f8,f9,f10,f11,f12,f13,f14,f15,f16,f17","CFTC/099741_FO_ALL",12);
    double TR_L = dataFromQuandl(1,"%Y-%m-%d,f1,f2,f3,f4,f5,f6,f7,f8,f9,f10,f11,f12,f13,f14,f15,f16,f17","CFTC/099741_FO_ALL",14);
    double TR_S = dataFromQuandl(1,"%Y-%m-%d,f1,f2,f3,f4,f5,f6,f7,f8,f9,f10,f11,f12,f13,f14,f15,f16,f17","CFTC/099741_FO_ALL",15);
    double NR_L = dataFromQuandl(1,"%Y-%m-%d,f1,f2,f3,f4,f5,f6,f7,f8,f9,f10,f11,f12,f13,f14,f15,f16,f17","CFTC/099741_FO_ALL",16);
    double NR_S = dataFromQuandl(1,"%Y-%m-%d,f1,f2,f3,f4,f5,f6,f7,f8,f9,f10,f11,f12,f13,f14,f15,f16,f17","CFTC/099741_FO_ALL",17);
    double DE = DE_L-DE_S;
    double AM = AM_L-AM_S;
    double LF = LF_L-LF_S;
    double OR = OR_L-OR_S;
    double TR = TR_L-TR_S;
    double NR = NR_L-NR_S;
    double RR = TR-NR;

    double CO = DE;
    double NC = LF_L-LF_S+AM_L-AM_S;

    //plot("DE",DE,1,RED);
    //plot("Z1",0,0,BLACK);
    //plot("AM",AM,1,RED);
    //plot("Z2",0,0,BLACK);
    //plot("LF",LF,1,RED);
    //plot("Z3",0,0,BLACK);
    //plot("OR",OR,1,RED);
    //plot("Z4",0,0,BLACK);
    //plot("TR",TR,1,RED);
    //plot("Z5",0,0,BLACK);
    //plot("NR",NR,1,RED);
    //plot("Z6",0,0,BLACK);
    plot("CO",CO,1,BLUE);
    plot("NC",NC,0,RED);
    plot("Z7",0,0,BLACK);
    plot("TO",NC-CO,1,RED);
    plot("Z8",0,0,BLACK);

    /*
    double Net = AM_L-AM_S+DE_S-DE_L+LF_L-LF_S;
    double* NET = series(Net);
    int Thres = 50000;
    static bool Impulse;
    if( NET[2]<0 && NET[3]>0 ){
        exitLong();
        if( Impulse ){
            enterShort();
        }
        Impulse = TRUE;
    }
    else if( NET[2]>0 && NET[3]<0 ){
        exitShort();
        if( Impulse ){
            enterLong();
        }
        Impulse = TRUE;
    }

    if( Impulse && abs(Net)>=Thres ){
        Impulse = FALSE;
    }

    double Level;
    static double Max, Min;
    if( Net>Max ){
        Max = Net;
        Min = 0;
    }
    else if( Net<Min ){
        Min = Net;
        Max = 0;
    }
    if( Net > 0 )
        Level = Max*0.764;
    else if( Net < 0 )
        Level = Min*0.764;
    */
    /*
    plot("DE_L",DE_L,1,BLUE);
    plot("DE_S",DE_S,0,RED);
    plot("AM_L",AM_L,1,BLUE);
    plot("AM_S",AM_S,0,RED);
    plot("LF_L",LF_L,1,BLUE);
    plot("LF_S",LF_S,0,RED);
    plot("OR_L",OR_L,1,BLUE);
    plot("OR_S",OR_S,0,RED);
    plot("TR_L",TR_L,1,BLUE);
    plot("TR_S",TR_S,0,RED);
    plot("NR_L",NR_L,1,BLUE);
    plot("NR_S",NR_S,0,RED);
    plot("Net",Net,1,RED);
    plot("Level",Level,0,BLUE);
    plot("Zero",0,0,BLACK);
    */
   

}