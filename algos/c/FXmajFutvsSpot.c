
#include <NexowFunctions.h>

#define NUMCONTRACTS 20

double FUTo[NUMCONTRACTS];
double FUTc[NUMCONTRACTS];
double SPTo[NUMCONTRACTS];
double SPTc[NUMCONTRACTS];
int Days[NUMCONTRACTS];

void EODtrade( int Handle, int ExpoDays ) {
    Days[Handle-1] += 1;
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

void EODplot( int Handle ){
    plot("FUTo",FUTo[Handle-1],0,BLUE+TRANSP);
    plot("FUTc",FUTc[Handle-1],0,BLUE);
    plot("SPTo",SPTo[Handle-1],0,RED+TRANSP);
    plot("SPTc",SPTc[Handle-1],0,RED);
}

void ContFutvsSpotCandleAlgo( int Handle, char* AlgoID, char* SpotAsset, char* QuandlCode, double DivideBy, int ExpoDays, bool Plot ) {
    asset(SpotAsset);
    algo(AlgoID);
    const char* Format = "%Y-%m-%d,f1,f2,f3,f4,f5,f6,f7,f8";
    double FutOpen = dataFromQuandl(Handle,Format,QuandlCode,1);
    double FutClose = dataFromQuandl(Handle,Format,QuandlCode,6);
    if( FutOpen == 0 || FutClose == 0 ) {
        exitLong(); 
        exitShort();
        return; 
    }
    else {
        if( DivideBy != 0 ) {
            FutOpen = DivideBy/FutOpen;
            FutClose = DivideBy/FutClose; 
        }
        if( FutOpen != FUTo[Handle-1] || FutClose != FUTc[Handle-1] ) {
            FUTo[Handle-1] = FutOpen;
            SPTo[Handle-1] = SPTc[Handle-1];
            SPTc[Handle-1] = priceClose(0);
            EODtrade(Handle,ExpoDays); 
        }
    }
    if( Plot )
        EODplot(Handle); 
}

void run() {

    set(PLOTNOW);
    assetList("FX28");
    StartDate = 2005;
    //BarZone = -8;
    BarPeriod = 60;
    
    LookBack = 10;
    Hedge = 1;
    Capital = 100000;
    Margin = 1000;
    
    ContFutvsSpotCandleAlgo(1,"Algo1","EUR_USD","CHRIS/CME_EC1",0,1,TRUE);
    ContFutvsSpotCandleAlgo(2,"Algo1b","EUR_USD","CHRIS/CME_EC2",0,1,FALSE);

    ContFutvsSpotCandleAlgo(3,"Algo2","GBP_USD","CHRIS/CME_BP1",0,1,TRUE);
    ContFutvsSpotCandleAlgo(4,"Algo2b","GBP_USD","CHRIS/CME_BP2",0,1,FALSE);

    ContFutvsSpotCandleAlgo(5,"Algo3","USD_CHF","CHRIS/CME_SF1",1,1,TRUE);
    ContFutvsSpotCandleAlgo(6,"Algo3b","USD_CHF","CHRIS/CME_SF2",1,1,FALSE);

    ContFutvsSpotCandleAlgo(7,"Algo4","USD_CAD","CHRIS/CME_CD1",1,1,TRUE);
    ContFutvsSpotCandleAlgo(8,"Algo4b","USD_CAD","CHRIS/CME_CD2",1,1,FALSE);
    ContFutvsSpotCandleAlgo(9,"Algo4c","USD_CAD","CHRIS/CME_CD3",1,1,FALSE);

    ContFutvsSpotCandleAlgo(10,"Algo5","USD_JPY","CHRIS/CME_JY1",1000000,1,TRUE);
    ContFutvsSpotCandleAlgo(11,"Algo5b","USD_JPY","CHRIS/CME_JY2",1000000,1,FALSE);
    
    ContFutvsSpotCandleAlgo(12,"Algo6","AUD_USD","CHRIS/CME_AD1",0,1,TRUE);
    ContFutvsSpotCandleAlgo(13,"Algo6b","AUD_USD","CHRIS/CME_AD2",0,1,FALSE);

    ContFutvsSpotCandleAlgo(14,"Algo7","NZD_USD","CHRIS/CME_NE1",0,1,TRUE);
    ContFutvsSpotCandleAlgo(15,"Algo7b","NZD_USD","CHRIS/CME_NE2",0,1,FALSE);

    setFXaccounting(1,-1);
    setFees(0.02,0.0,0.1,5);
    setCurrencyLeverage();
    SetAccountPlots("SPX500_USD",1);

}


