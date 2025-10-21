

#include <NexowFunctions.h>

ccyval GGR[10];
ccyccyval GGRx[45];

void setNames(){
    strcpy(GGR[0].Ccy,"AUD");
    strcpy(GGR[1].Ccy,"CAD");
    strcpy(GGR[2].Ccy,"CHF");
    strcpy(GGR[3].Ccy,"EUR");
    strcpy(GGR[4].Ccy,"GBP");
    strcpy(GGR[5].Ccy,"HKD");
    strcpy(GGR[6].Ccy,"JPY");
    strcpy(GGR[7].Ccy,"NZD");
    strcpy(GGR[8].Ccy,"SGD");
    strcpy(GGR[9].Ccy,"USD");
}

void run(){

    set(PLOTNOW);
    assetList("AssetsFix45");
    StartDate = 2005;
    BarPeriod = 1440;
    LookBack = 300;
    
    if( is(INITRUN) ){
        setNames();
    }

    const double Thres = 0;

    const char* Format = "%Y-%m-%d,f1";
    double AUD = dataFromQuandl(1,Format,"SGE/AUSGGR",1);
    double CAD = dataFromQuandl(2,Format,"SGE/CANGGR",1);
    double CHF = dataFromQuandl(3,Format,"SGE/CHEGGR",1);
    double EUR = dataFromQuandl(4,Format,"SGE/EURGGR",1);
    double GBP = dataFromQuandl(5,Format,"SGE/GBRGGR",1);
    double HKD = dataFromQuandl(6,Format,"SGE/HKGGGR",1);
    double JPY = dataFromQuandl(7,Format,"SGE/JPNGGR",1);
    double NZD = dataFromQuandl(8,Format,"SGE/NZLGGR",1);
    double SGD = dataFromQuandl(9,Format,"SGE/SGPGGR",1);
    double USD = dataFromQuandl(10,Format,"SGE/USAGGR",1);

    static int count = 0;
    if( AUD != GGR[0].Val ){
        GGR[0].Val = AUD;
        count++; }
    if( CAD != GGR[1].Val ){
        GGR[1].Val = CAD;
        count++; }
    if( CHF != GGR[2].Val ){
        GGR[2].Val = CHF;
        count++; }
    if( EUR != GGR[3].Val ){
        GGR[3].Val = EUR;
        count++; }
    if( GBP != GGR[4].Val ){
        GGR[4].Val = GBP;
        count++; }
    if( HKD != GGR[5].Val ){
        GGR[5].Val = HKD;
        count++; }
    if( JPY != GGR[6].Val ){
        GGR[6].Val = JPY;
        count++; }
    if( NZD != GGR[7].Val ){
        GGR[7].Val = NZD;
        count++; }
    if( SGD != GGR[8].Val ){
        GGR[8].Val = SGD;
        count++; }
    if( USD != GGR[9].Val ){
        GGR[9].Val = USD;
        count++; }
    
    if( count >= 10 ){
        CloseAll();
        count = 0;
        int i, j, k;
        for( i = 0; i < 10; i++ ){
            for( j = 0; j < 10; j++ ){
                if( !strstr(GGR[i].Ccy,GGR[j].Ccy) ){
                    strcpy(GGRx[k].Ccy1,GGR[i].Ccy);
                    strcpy(GGRx[k].Ccy2,GGR[j].Ccy);
                    GGRx[k].Val = GGR[i].Val-GGR[j].Val;
                    k++;
                }
            }
        }
        while(asset(loop(Assets))){
            string X = Base();
            string Y = Term();
            int i;
            for( i = 0; i < 45; i++ ){
                if( strstr(X,GGRx[i].Ccy1) && strstr(Y,GGRx[i].Ccy2) ){
                    if( GGRx[i].Val < -Thres )
                        enterShort();
                    else if( GGRx[i].Val > Thres )
                        enterLong();
                    break;
                }
                if( strstr(Y,GGRx[i].Ccy1) && strstr(X,GGRx[i].Ccy2) ){
                    if( GGRx[i].Val > Thres )
                        enterShort();
                    else if( GGRx[i].Val < -Thres )
                        enterLong();
                    break;
                }
            }
        }
    }

    while(asset(loop(Assets))){
        plot("Zero",0,1,BLACK);
        plot("AUD",GGR[0].Val,0,LIGHTBLUE);
        plot("CAD",GGR[1].Val,0,GREEN);
        plot("CHF",GGR[2].Val,0,BLUE);            
        plot("EUR",GGR[3].Val,0,ORANGE);            
        plot("GBP",GGR[4].Val,0,DARKBLUE);
        plot("HKD",GGR[5].Val,0,OLIVE);
        plot("JPY",GGR[6].Val,0,PURPLE);
        plot("NZD",GGR[7].Val,0,MAGENTA);
        plot("SGD",GGR[8].Val,0,CYAN);
        plot("USD",GGR[9].Val,0,DARKGREEN);
    }
 
}