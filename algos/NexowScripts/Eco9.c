

#include <NexowFunctions.h>

ccyval CPI[10];
ccyccyval CPIx[45];

void setNames(){
    strcpy(CPI[0].Ccy,"AUD");
    strcpy(CPI[1].Ccy,"CAD");
    strcpy(CPI[2].Ccy,"CHF");
    strcpy(CPI[3].Ccy,"EUR");
    strcpy(CPI[4].Ccy,"GBP");
    strcpy(CPI[5].Ccy,"HKD");
    strcpy(CPI[6].Ccy,"JPY");
    strcpy(CPI[7].Ccy,"NZD");
    strcpy(CPI[8].Ccy,"SGD");
    strcpy(CPI[9].Ccy,"USD");
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
    static double AUD2, CAD2, CHF2, EUR2, GBP2, HKD2, JPY2, NZD2, SGD2, USD2;
    double AUD = dataFromQuandl(1,Format,"SGE/AUSCPI",1);
    double CAD = dataFromQuandl(2,Format,"SGE/CANCPI",1);
    double CHF = dataFromQuandl(3,Format,"SGE/CHECPI",1);
    double EUR = dataFromQuandl(4,Format,"SGE/EURCPI",1);
    double GBP = dataFromQuandl(5,Format,"SGE/GBRCPI",1);
    double HKD = dataFromQuandl(6,Format,"SGE/HKGCPI",1);
    double JPY = dataFromQuandl(7,Format,"SGE/JPNCPI",1);
    double NZD = dataFromQuandl(8,Format,"SGE/NZLCPI",1);
    double SGD = dataFromQuandl(9,Format,"SGE/SGPCPI",1);
    double USD = dataFromQuandl(10,Format,"SGE/USACPI",1);

    static int count = 0;
    if( AUD != AUD2 ){
        CPI[0].Val = (AUD/AUD2-1)*100;
        AUD2 = AUD;
        count++; }
    if( CAD != CAD2 ){
        CPI[1].Val = (CAD/CAD2-1)*100;
        CAD2 = CAD;
        count++; }
    if( CHF != CHF2 ){
        CPI[2].Val = (CHF/CHF2-1)*100;
        CHF2 = CHF;
        count++; }
    if( EUR != EUR2 ){
        CPI[3].Val = (EUR/EUR2-1)*100;
        EUR2 = EUR;
        count++; }
    if( GBP != GBP2 ){
        CPI[4].Val = (GBP/GBP2-1)*100;
        GBP2 = GBP;
        count++; }
    if( HKD != HKD2 ){
        CPI[5].Val = (HKD/HKD2-1)*100;
        HKD2 = HKD;
        count++; }
    if( JPY != JPY2 ){
        CPI[6].Val = (JPY/JPY2-1)*100;
        JPY2 = JPY;
        count++; }
    if( NZD != NZD2 ){
        CPI[7].Val = (NZD/NZD2-1)*100;
        NZD2 = NZD;
        count++; }
    if( SGD != SGD2 ){
        CPI[8].Val = (SGD/SGD2-1)*100;
        SGD2 = SGD;
        count++; }
    if( USD != USD2 ){
        CPI[9].Val = (USD/USD2-1)*100;
        USD2 = USD;
        count++; }
    const double Pos = 0, Neg = 0;
    if( count >= 5 ){
        CloseAll();
        count = 0;
        int i, j, k;
        for( i = 0; i < 10; i++ ){
            for( j = 0; j < 10; j++ ){
                if( !strstr(CPI[i].Ccy,CPI[j].Ccy) ){
                    strcpy(CPIx[k].Ccy1,CPI[i].Ccy);
                    strcpy(CPIx[k].Ccy2,CPI[j].Ccy);
                    if( CPI[i].Val > Pos && CPI[j].Val < Neg )
                        CPIx[k].Val = 1;
                    else if( CPI[i].Val < Neg && CPI[j].Val > Pos )
                        CPIx[k].Val = -1;
                    else CPIx[k].Val = 0;
                    k++;
                }
            }
        }
        while(asset(loop(Assets))){
            string X = Base();
            string Y = Term();
            int i;
            for( i = 0; i < 45; i++ ){
                if( strstr(X,CPIx[i].Ccy1) && strstr(Y,CPIx[i].Ccy2) ){
                    if( CPIx[i].Val < -Thres )
                        enterShort();
                    else if( CPIx[i].Val > Thres )
                        enterLong();
                    break;
                }
                if( strstr(Y,CPIx[i].Ccy1) && strstr(X,CPIx[i].Ccy2) ){
                    if( CPIx[i].Val > Thres )
                        enterShort();
                    else if( CPIx[i].Val < -Thres )
                        enterLong();
                    break;
                }
            }
        }
    }

    while(asset(loop(Assets))){
        plot("Zero",0,1,BLACK);
        plot("AUD",CPI[0].Val,0,LIGHTBLUE);
        plot("CAD",CPI[1].Val,0,GREEN);
        plot("CHF",CPI[2].Val,0,BLUE);            
        plot("EUR",CPI[3].Val,0,ORANGE);            
        plot("GBP",CPI[4].Val,0,DARKBLUE);
        plot("HKD",CPI[5].Val,0,OLIVE);
        plot("JPY",CPI[6].Val,0,PURPLE);
        plot("NZD",CPI[7].Val,0,MAGENTA);
        plot("SGD",CPI[8].Val,0,CYAN);
        plot("USD",CPI[9].Val,0,DARKGREEN);
    }
 
}