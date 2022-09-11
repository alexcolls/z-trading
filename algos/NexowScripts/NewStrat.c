
#include <NexowFunctions.h>

void run(){

    set(PLOTNOW);
    assetList("FX28");
    StartDate = 2005;
    BarPeriod = 60;
    BarZone = UTC;

    double* Prices = series(priceClose());

    int Len = 10;

    double MP1 = EMA(series(MidPrice(25)),Len);
    double MP2 = EMA(series(MidPrice(50)),Len);
    double MP3 = EMA(series(MidPrice(100)),Len);

    plot("MP25",MP1,0,GREEN);
    plot("MP50",MP2,0,RED);
    plot("MP100",MP3,0,BLUE);

    double* M1 = series(MP1);
    double* M2 = series(MP2);
    double* M3 = series(MP3);

    double Thres = 0.01;

    int D1, D2, D3;

    if( (M1[0]/M1[1]-1)*100 > Thres )
        D1 = 1;
    else if( (M1[0]/M1[1]-1)*100 < -Thres )
        D1 = -1;
    else
        D1 = 0;

    if( (M2[0]/M2[1]-1)*100 > Thres )
        D2 = 1;
    else if( (M2[0]/M2[1]-1)*100 < -Thres  )
        D2 = -1;
    else
        D2 = 0;

    if( (M3[0]/M3[1]-1)*100 > Thres  )
        D3 = 1;
    else if( (M3[0]/M3[1]-1)*100 < -Thres )
        D3 = -1;
    else
        D3 = 0;

    plot("Z",0,1,BLACK);
    plot("D1",D1,0,GREEN);
    plot("D2",D2,0,RED);
    plot("D3",D3,0,BLUE);

    int Dir;
    if( D1 == 1 && D2 == 1 && D3 == 1 )
        Dir = 1;
    else if( D1 == -1 && D2 == -1 && D3 == -1 )
        Dir = -1;
    else 
        Dir = 0;
    
    plot("Z1",0,1,BLACK);
    plot("Dir",Dir,BARS,BLUE);

    

    

}