
#include <NexowFunctions.h>

void run(){

    set(PLOTNOW);
    assetList("FX28");
    StartDate = 2005;
    BarPeriod = 60;
    BarZone = UTC;
    LookBack = 100;

    setFXaccounting(1,-1);
    setFees(0.02,0.003,0.2,5);

    Capital = 100000;
    Margin = 10000;

    const char* Format = "%Y-%m-%d,f1,f2,f3,f4,f5,f6,f7,f8";
    
    // EUR //

        asset("EUR/USD");
        double EURopen = dataFromQuandl(1,Format,"CHRIS/CME_EC1",1);
        double EURclose = dataFromQuandl(2,Format,"CHRIS/CME_EC1",6);
        static double EURo, EURc, EURos, EURcs;
        static int EURpos = 0;
        if( EURopen != EURo || EURclose != EURc ){
            EURos = EURcs;
            EURcs = priceClose(0);
            exitLong(); exitShort();
            EURpos = 0;
        }
        if( EURopen != 0 )
            EURo = EURopen;
        if( EURclose != 0 )
            EURc = EURclose;
        if( EURc < EURo && EURcs > EURos && EURpos >= 0 ){
            enterShort();
            EURpos = -1;
        }
        else if( EURc > EURo && EURcs < EURos && EURpos <= 0 ){
            enterLong();
            EURpos = 1;
        }
        plot("EURo",EURo,0,BLUE+TRANSP);
        plot("EURc",EURc,0,BLUE);
        plot("EURos",EURos,0,RED+TRANSP);
        plot("EURcs",EURcs,0,RED);
    
    //
    
    // GBP //

        asset("GBP/USD");
        double GBPopen = dataFromQuandl(3,Format,"CHRIS/CME_BP2",1);
        double GBPclose = dataFromQuandl(4,Format,"CHRIS/CME_BP2",6);
        static double GBPo, GBPc, GBPos, GBPcs;
        static int GBPpos = 0;
        if( GBPopen != GBPo || GBPclose != GBPc ){
            GBPos = GBPcs;
            GBPcs = priceClose(0);
            exitLong(); exitShort();
            GBPpos = 0;
        }
        if( GBPopen != 0 )
            GBPo = GBPopen;
        if( GBPclose != 0 )
            GBPc = GBPclose;
        if( GBPc < GBPo && GBPcs > GBPos && GBPpos >= 0 ){
            enterShort();
            GBPpos = -1;
        }
        else if( GBPc > GBPo && GBPcs < GBPos && GBPpos <= 0 ){
            enterLong();
            GBPpos = 1;
        }
        plot("GBPo",GBPo,0,BLUE+TRANSP);
        plot("GBPc",GBPc,0,BLUE);
        plot("GBPos",GBPos,0,RED+TRANSP);
        plot("GBPcs",GBPcs,0,RED);
    
    //

    // CHF //

        asset("USD/CHF");
        double CHFopen = 1/dataFromQuandl(5,Format,"CHRIS/CME_SF1",1);
        double CHFclose = 1/dataFromQuandl(6,Format,"CHRIS/CME_SF1",6);
        static double CHFo, CHFc, CHFos, CHFcs;
        static int CHFpos = 0;
        if( CHFopen != CHFo || CHFclose != CHFc ){
            CHFos = CHFcs;
            CHFcs = priceClose(0);
            exitLong(); exitShort();
            CHFpos = 0;
        }
        if( CHFopen != 0 )
            CHFo = CHFopen;
        if( CHFclose != 0 )
            CHFc = CHFclose;
        if( CHFc < CHFo && CHFcs > CHFos && CHFpos >= 0 ){
            enterShort();
            CHFpos = -1;
        }
        else if( CHFc > CHFo && CHFcs < CHFos && CHFpos <= 0 ){
            enterLong();
            CHFpos = 1;
        }
        plot("CHFo",CHFo,0,BLUE+TRANSP);
        plot("CHFc",CHFc,0,BLUE);
        plot("CHFos",CHFos,0,RED+TRANSP);
        plot("CHFcs",CHFcs,0,RED);
    
    //

    // CAD //

        asset("USD/CAD");
        double CADopen = 1/dataFromQuandl(7,Format,"CHRIS/CME_CD1",1);
        double CADclose = 1/dataFromQuandl(8,Format,"CHRIS/CME_CD1",6);
        static double CADo, CADc, CADos, CADcs;
        static int CADpos = 0;
        if( CADopen != CADo || CADclose != CADc ){
            CADos = CADcs;
            CADcs = priceClose(0);
            exitLong(); exitShort();
            CADpos = 0;
        }
        if( CADopen != 0 )
            CADo = CADopen;
        if( CADclose != 0 )
            CADc = CADclose;
        if( CADc < CADo && CADcs > CADos && CADpos >= 0 ){
            enterShort();
            CADpos = -1;
        }
        else if( CADc > CADo && CADcs < CADos && CADpos <= 0 ){
            enterLong();
            CADpos = 1;
        }
        plot("CADo",CADo,0,BLUE+TRANSP);
        plot("CADc",CADc,0,BLUE);
        plot("CADos",CADos,0,RED+TRANSP);
        plot("CADcs",CADcs,0,RED);
    
    //

    // JPY //

        asset("USD/JPY");
        double JPYopen = 1000000/dataFromQuandl(9,Format,"CHRIS/CME_JY1",1);
        double JPYclose = 1000000/dataFromQuandl(10,Format,"CHRIS/CME_JY1",6);
        static double JPYo, JPYc, JPYos, JPYcs;
        static int JPYpos = 0;
        if( JPYopen != JPYo || JPYclose != JPYc ){
            JPYos = JPYcs;
            JPYcs = priceClose(0);
            exitLong(); exitShort();
            JPYpos = 0;
        }
        if( JPYopen != 0 )
            JPYo = JPYopen;
        if( JPYclose != 0 )
            JPYc = JPYclose;
        if( JPYc < JPYo && JPYcs > JPYos && JPYpos >= 0 ){
            enterShort();
            JPYpos = -1;
        }
        else if( JPYc > JPYo && JPYcs < JPYos && JPYpos <= 0 ){
            enterLong();
            JPYpos = 1;
        }
        plot("JPYo",JPYo,0,BLUE+TRANSP);
        plot("JPYc",JPYc,0,BLUE);
        plot("JPYos",JPYos,0,RED+TRANSP);
        plot("JPYcs",JPYcs,0,RED);
    
    //  
    
}


