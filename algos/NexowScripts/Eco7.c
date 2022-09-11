

#include <NexowFunctions.h>

ccyval CPIC[10];
ccyccyval CPICx[45];

void setNames(){
    strcpy(CPIC[0].Ccy,"AUD");
    strcpy(CPIC[1].Ccy,"CAD");
    strcpy(CPIC[2].Ccy,"CHF");
    strcpy(CPIC[3].Ccy,"EUR");
    strcpy(CPIC[4].Ccy,"GBP");
    strcpy(CPIC[5].Ccy,"HKD");
    strcpy(CPIC[6].Ccy,"JPY");
    strcpy(CPIC[7].Ccy,"NZD");
    strcpy(CPIC[8].Ccy,"SGD");
    strcpy(CPIC[9].Ccy,"USD");
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

    const double Healthy = 0.25, Sick = 1;
    const char* Format = "%Y-%m-%d,f1";
    double AUD = dataFromQuandl(1,Format,"SGE/AUSCPIC",1);
    double CAD = dataFromQuandl(2,Format,"SGE/CANCPIC",1);
    double CHF = dataFromQuandl(3,Format,"SGE/CHECPIC",1);
    double EUR = dataFromQuandl(4,Format,"SGE/EURCPIC",1);
    double GBP = dataFromQuandl(5,Format,"SGE/GBRCPIC",1);
    double HKD = dataFromQuandl(6,Format,"SGE/HKGCPIC",1);
    double JPY = dataFromQuandl(7,Format,"SGE/JPNCPIC",1);
    double NZD = dataFromQuandl(8,Format,"SGE/NZLCPIC",1);
    double SGD = dataFromQuandl(9,Format,"SGE/SGPCPIC",1);
    double USD = dataFromQuandl(10,Format,"SGE/USACPIC",1);

    static int count = 0;
    if( AUD != CPIC[0].Val ){
        CPIC[0].Val = AUD;
        count++; }
    if( CAD != CPIC[1].Val ){
        CPIC[1].Val = CAD;
        count++; }
    if( CHF != CPIC[2].Val ){
        CPIC[2].Val = CHF;
        count++; }
    if( EUR != CPIC[3].Val ){
        CPIC[3].Val = EUR;
        count++; }
    if( GBP != CPIC[4].Val ){
        CPIC[4].Val = GBP;
        count++; }
    if( HKD != CPIC[5].Val ){
        CPIC[5].Val = HKD;
        count++; }
    if( JPY != CPIC[6].Val ){
        CPIC[6].Val = JPY;
        count++; }
    if( NZD != CPIC[7].Val ){
        CPIC[7].Val = NZD;
        count++; }
    if( SGD != CPIC[8].Val ){
        CPIC[8].Val = SGD;
        count++; }
    if( USD != CPIC[9].Val ){
        CPIC[9].Val = USD;
        count++; }
    
    if( count >= 10 ){
        CloseAll();
        count = 0;
        int i, j, k;
        for( i = 0; i < 10; i++ ){
            for( j = 0; j < 10; j++ ){
                if( !strstr(CPIC[i].Ccy,CPIC[j].Ccy) ){
                    strcpy(CPICx[k].Ccy1,CPIC[i].Ccy);
                    strcpy(CPICx[k].Ccy2,CPIC[j].Ccy);
                    double Ccy1 = CPIC[i].Val;
                    if( Ccy1 > 2-Healthy && Ccy1 < 2+Healthy )
                        Ccy1 = 1;
                    else if( Ccy1 < 2-Sick && Ccy1 < 2+Sick )
                        Ccy1 = -1;
                    else Ccy1 = 0;
                    double Ccy2 = CPIC[j].Val;
                    if( Ccy2 > 2-Healthy && Ccy2 < 2+Healthy )
                        Ccy2 = 1;
                    else if( Ccy2 < 2-Sick && Ccy2 < 2+Sick )
                        Ccy2 = -1;
                    else Ccy2 = 0;
                    CPICx[k].Val = Ccy1-Ccy2;
                    k++;
                }
            }
        }
        while(asset(loop(Assets))){
            string X = Base();
            string Y = Term();
            int i;
            for( i = 0; i < 45; i++ ){
                if( strstr(X,CPICx[i].Ccy1) && strstr(Y,CPICx[i].Ccy2) ){
                    if( CPICx[i].Val == -2 )
                        enterShort();
                    else if( CPICx[i].Val == 2 )
                        enterLong();
                    break;
                }
                if( strstr(Y,CPICx[i].Ccy1) && strstr(X,CPICx[i].Ccy2) ){
                    if( CPICx[i].Val == 2 )
                        enterShort();
                    else if( CPICx[i].Val == -2 )
                        enterLong();
                    break;
                }
            }
        }
    }

    while(asset(loop(Assets))){
        plot("Zero",0,1,BLACK);
        plot("AUD",CPIC[0].Val,0,LIGHTBLUE);
        plot("CAD",CPIC[1].Val,0,GREEN);
        plot("CHF",CPIC[2].Val,0,BLUE);            
        plot("EUR",CPIC[3].Val,0,ORANGE);            
        plot("GBP",CPIC[4].Val,0,DARKBLUE);
        plot("HKD",CPIC[5].Val,0,OLIVE);
        plot("JPY",CPIC[6].Val,0,PURPLE);
        plot("NZD",CPIC[7].Val,0,MAGENTA);
        plot("SGD",CPIC[8].Val,0,CYAN);
        plot("USD",CPIC[9].Val,0,DARKGREEN);
    }
 
}