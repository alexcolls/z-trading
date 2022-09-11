
#include <NexowFunctions.h>

#define NUMCONTRACTS 20

double FUTo[NUMCONTRACTS];
double FUTc[NUMCONTRACTS];
double SPTo[NUMCONTRACTS];
double SPTc[NUMCONTRACTS];
int Days[NUMCONTRACTS];

void ContFutvsSpotCandleAlgo( int Handle, char* AlgoID, char* SpotAsset, char* QuandlCode, int OpenField, int CloseField, double DivideBy, int ExpoDays, bool Plot ){
    asset(SpotAsset);
    algo(AlgoID);
    bool EOD = FALSE;
    const char* Format = "%Y-%m-%d,f1,f2,f3,f4,f5,f6,f7,f8";
    double FutOpen, FutClose;
    if( DivideBy == 0 ) {
        FutOpen = dataFromQuandl(Handle,Format,QuandlCode,OpenField);
        FutClose = dataFromQuandl(Handle,Format,QuandlCode,CloseField); }
    else {
        FutOpen = DivideBy/dataFromQuandl(Handle,Format,QuandlCode,OpenField);
        FutClose = DivideBy/dataFromQuandl(Handle,Format,QuandlCode,CloseField); }
    //printf("\nOpen = %f %f, Close = %f %f, Date = %f", FutOpen, SPTo[Handle-1], FutClose, SPTc[Handle-1], wdate());
    if( FutOpen != FUTo[Handle-1] ) {
        //printf("\n");
        EOD = TRUE;
        if( FutOpen != 0 ) {
            FUTo[Handle-1] = FutOpen; }
        else {
            exitLong(); exitShort();
            return; }
    }
    if( FutClose != FUTc[Handle-1] ) {
        EOD = TRUE;
        if( FutClose != 0 ) {
            FUTc[Handle-1] = FutClose; }
        else {
            exitLong(); exitShort();
            return; }
    }
    if( EOD ) {
        Days[Handle-1] += 1;
        SPTo[Handle-1] = SPTc[Handle-1];
        SPTc[Handle-1] = priceClose(0);
        if( Days[Handle-1] >= ExpoDays ) {
            exitLong(); exitShort(); }
        if( FUTc[Handle-1] < FUTo[Handle-1] && SPTc[Handle-1] > SPTo[Handle-1] ) {
            enterShort();
            Days[Handle-1] = 0; }
        else if( FUTc[Handle-1] > FUTo[Handle-1] && SPTc[Handle-1] < SPTo[Handle-1] ) {
            enterLong();
            Days[Handle-1] = 0;
        }
    }
    if( Plot ) { 
        plot("FUTo",FUTo[Handle-1],0,BLUE+TRANSP);
        plot("FUTc",FUTc[Handle-1],0,BLUE);
        plot("SPTo",SPTo[Handle-1],0,RED+TRANSP);
        plot("SPTc",SPTc[Handle-1],0,RED);
    }
}


void run() {

    set(PLOTNOW);
    assetList("FX28");
    StartDate = 2005;
    //BarZone = 8;
    BarPeriod = 60;
    
    LookBack = 10;
    Hedge = 1;
    Capital = 100000;
    Margin = Balance*0.002;
    
    ContFutvsSpotCandleAlgo(1,"Algo1","EUR_USD","CHRIS/CME_EC1",1,6,0,1,TRUE);

    ContFutvsSpotCandleAlgo(2,"Algo1b","EUR_USD","CHRIS/CME_EC2",1,6,0,1,FALSE);

    ContFutvsSpotCandleAlgo(3,"Algo2","GBP_USD","CHRIS/CME_BP1",1,6,0,1,FALSE);
    ContFutvsSpotCandleAlgo(4,"Algo2b","GBP_USD","CHRIS/CME_BP2",1,6,0,1,FALSE);

    ContFutvsSpotCandleAlgo(5,"Algo3","USD_CHF","CHRIS/CME_SF1",1,6,1,1,TRUE);
    ContFutvsSpotCandleAlgo(6,"Algo3b","USD_CHF","CHRIS/CME_SF2",1,6,1,1,FALSE);

    ContFutvsSpotCandleAlgo(7,"Algo4","USD_CAD","CHRIS/CME_CD1",1,6,1,1,FALSE);
    ContFutvsSpotCandleAlgo(8,"Algo4b","USD_CAD","CHRIS/CME_CD2",1,6,1,1,FALSE);
    ContFutvsSpotCandleAlgo(9,"Algo4c","USD_CAD","CHRIS/CME_CD3",1,6,1,1,FALSE);

    ContFutvsSpotCandleAlgo(10,"Algo5","USD_JPY","CHRIS/CME_JY1",1,6,1000000,1,FALSE);
    ContFutvsSpotCandleAlgo(11,"Algo5b","USD_JPY","CHRIS/CME_JY2",1,6,1000000,1,FALSE);
    
    ContFutvsSpotCandleAlgo(12,"Algo6","AUD_USD","CHRIS/CME_AD1",1,6,0,1,FALSE);
    ContFutvsSpotCandleAlgo(13,"Algo6b","AUD_USD","CHRIS/CME_AD2",1,6,0,1,FALSE);

    ContFutvsSpotCandleAlgo(14,"Algo7","NZD_USD","CHRIS/CME_NE1",1,6,0,1,FALSE);
    ContFutvsSpotCandleAlgo(15,"Algo7b","NZD_USD","CHRIS/CME_NE2",1,6,0,1,FALSE);
    
    setFXaccounting(1,-1);
    setFees(0.02,0.0,0.1,5);
    setCurrencyLeverage();
    SetAccountPlots("SPX500_USD",1);

}


