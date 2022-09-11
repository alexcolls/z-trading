


/*---------------------------------------------------------------*/
/*||||||||||||||||       Nexow - GRAVITY v1      ||||||||||||||||*/
/*---------------------------------------------------------------*/


#include <nexow.h>

#define ASSETS 45
#define WEEKS 4

#define LEVERAGE 2
#define HARDSTOP 5

typedef struct
{
    string Sym;
    double Val;
} 
s1;

s1 Zss[ASSETS];


// INIT //

void init()
{
    if( is(INITRUN) )
    {
        assetList( "GRAVITY" );
        BarPeriod = 60;
        LookBack = 1000;
        Hedge = 4; // NFA compliant.
        StartDate = 2005;  
        StartWeek = 10000; // No Sundays.
        MonteCarlo = 0;
        OK();
    }
}

// HARDSTOP //

void closeAll()
{
    while( asset( loop(Assets) ) )
    {
        exitLong();
        exitShort();
    }
}

// STATUS //

static bool go = false;
static bool death = false;

// RISK MANAGEMENT //

static int y, q;
static double iy, iq;
static double iBA, BA = 0, BAx = 0;
static double EQ = 0, EQx = 0;
static double EQ2y = 0, EQy2 = 0, EQyx = 0;
static double EQ2q = 0, EQq2 = 0, EQqx = 0;
static double EQy = 0, EQq = 0, DD = 0, FG = 0, LV = 0;
static double HS = 0, HSy = 0, HSq = 0;

void RiskManagement()
{

    static double lev = LEVERAGE;
    static double hsp = HARDSTOP;

    Capital = 100000;
    Margin = 100;        

    if( !death )
    {
        if( ( month() >  1  && month() < 12 ) ||
            ( month() == 1  && day()   > 7  ) ||
            ( month() == 12 && day()   < 20 )  )
        {
            go = true;
        }
        else
        {
            closeAll();
            go = false;
        }
    }
    else
    {
        closeAll();
        go = false;
    }        
        
    if( is(FIRSTRUN) ) iy = iq = Equity;
    BA  = ( Balance / Capital - 1 ) * 100;
    if( BA > BAx ) BAx = BA;
    EQ  = ( Equity  / Capital - 1 ) * 100;
    if( EQ > EQx ) EQx = EQ;
    if( year() == StartDate ) EQ2y = 0;
    EQy = ( EQ - EQ2y ); if( EQy > EQyx ) EQyx = EQy;
    EQq = ( EQ - EQ2q ); if( EQq > EQqx ) EQqx = EQq;
    if( year()  != y ) { y = year(); EQy2 = ( EQ - iBA ); iy = EQ; EQ2y = EQ; EQy2 = EQy; EQy = 0; EQyx = 0; EQx = EQ; death = false; }
    if( month() != q ) { q = month(); EQq2 = ( EQ - iBA ); iq = EQ; EQ2q = EQ; EQq2 = EQq; EQq = 0; }
    HS  = ( EQx - hsp );
    HSy = ( EQyx - hsp );
    HSq = ( EQqx - hsp/2 );
    DD  = ( EQ - BAx ); if( DD > 0 ) DD = 0;
    FG  = ( EQ - BA );  if( FG > 0 ) FG = 0;
    LV  = 0;
    for( open_trades )
        LV += ( TradeLots * MarginCost * Leverage ) / Equity;
    double phEQ = ( ( EquityLong + EquityShort ) / Capital -1 ) * 100;
        
    if( EQy <= HSy )
    {
        death = true;
    }

}

// MONEY MANAGEMENT // 

void MoneyManagement()
{

}

// PLOTTING //

bool PLT = FALSE;

void setplt()
{
    if( is(INITRUN) )
    {
        set(PLOTNOW); // |LOGFILE
        setf(PlotMode,PL_FINE+PL_DIFF);
        PlotHeight1 = 600;  
        PlotHeight2 = 50;
        if( PLT )
        {
            ColorUp = GREY; 
            ColorDn = BLACK; 
            ColorWin = GREEN; 
            ColorLoss = RED; 
            ColorEquity = GREY+TRANSP; // 0x741424; 
            ColorDD = GREY; // 0x741424+TRANSP;
        }
        else { ColorUp = ColorDn = ColorWin = ColorLoss = ColorEquity = ColorDD = 0; }        
    }
}

void plt()
{
    
    //ColorUp = ColorDn = ColorWin = ColorLoss = ColorEquity = ColorDD = 0;
    string sym = AssetBox;

    // while( asset( loop(Assets) ) )
    // {
    //     if( !strstr(Symbol,sym) )
    //         plot( "Spread",marketVal(0),NEW+BARS,BLACK );
    // }

    asset(AssetBox);

    //plot( "Phansom Equity",phEQ,MAIN+LINE,0x741424+TRANSP );
    plot( "Balance",BA,MAIN+LINE,GREY ); plot( "Equity",EQ,MAIN+LINE,0x741424 );
    plot( "HardStop",HS,MAIN+LINE,BLACK+TRANSP ); //plot( "HS_",HS,MAIN+BARS,GREY+TRANSP );
    plot( "Drawdown",DD,MAIN+BARS,0x741424+TRANSP ); plot( "DD_",DD,LINE,0x741424+TRANSP );
    //plot( "Zero",0,MAIN+LINE,GREY );
    plot( "Yearly",0,NEW+LINE,GREY );
    plot( "HSyear",HSy,LINE,BLACK+TRANSP );
    if( is(FIRSTRUN) ) { plot( "EQyear+",EQy,BARS,DARKGREEN+TRANSP ); plot( "EQyear-",EQy,BARS,RED+TRANSP ); }
    if( EQy > 0 ) plot( "EQyear+",EQy,BARS,DARKGREEN+TRANSP ); else plot( "EQyear-",EQy,BARS,RED+TRANSP );
    plot( "Monthly",0,NEW+LINE,GREY );
    plot( "HSquarter",HSq,LINE,BLACK+TRANSP );
    if( is(FIRSTRUN) ) { plot( "EQmonth+",EQq,BARS,DARKGREEN+TRANSP ); plot( "EQmonth-",EQq,BARS,RED+TRANSP ); }
    if( EQq > 0 ) plot( "EQmonth+",EQq,BARS,DARKGREEN+TRANSP ); else plot( "EQmonth-",EQq,BARS,RED+TRANSP );
    plot( "Leverage",LV,NEW+BARS,GREY );
    plot( "Floating",FG,BARS,0x741424 ); plot( "FG_",FG,LINE,0x741424+TRANSP );
    
        
}


// ALGO //

void run() 
{	
    
    init(); setplt();
    RiskManagement(); plt();
           
    // Global Variables //

    static int      r = 0;            static double*  Cls[ASSETS];
    static double   Avg[ASSETS];      const  int      Avgi = 120;
    static double   StD[ASSETS];      const  int      StDi = 120;
    static double   Z[ASSETS];        static double   Zz[ASSETS];
    const  int      Zi = 20;          static double   Zs[ASSETS][1000];    

    // Strategy //

    int k = 0;
    while( asset( loop(Assets) ) )
    {
        
        fees();
        //double DP = DominantPeriod(vars Data, int Period)
        Cls[k] = series( priceClose(), Avgi+StDi );
        Avg[k] = ZMA( Cls[k], Avgi );
        StD[k] = StdDev( Cls[k], StDi );
        Z[k] = ( ( priceClose()-Avg[k] ) /StD[k] );
        
        char plt1[12]; //plt1 = strcat( plt1,"Z_" );
        strcat( plt1,Symbol );
        plot( plt1,Z[k],NEW+LINE,RED );                   
        
        int i; const int j = Zi; 
        for( i = 1; i < j; i++ )
        {
            Zs[k][j - i] = Zs[k][j - i - 1];
            Zs[k][j - i] = Zs[k][j - i - 1];
        }
        Zs[k][0] = Z[k];

        if( r > Zi )
        {
            if( death ) 
                setf(TradeMode,TR_PHANTOM); // drawdown -> phantom trades
            else 
                resf(TradeMode,TR_PHANTOM); // profitable -> normal trades

            if( ( Zs[k][0] >  Zs[k][1] && Zs[k][1] > Zs[k][2] ) &&
                ( Zs[k][2] <  Zs[k][3] && Zs[k][3] < Zs[k][4] ) )
            {
                exitLong();
                enterShort();
            }         
            else 
            if( ( Zs[k][0] <  Zs[k][1] && Zs[k][1] < Zs[k][2] ) &&
                ( Zs[k][2] >  Zs[k][3] && Zs[k][3] > Zs[k][4] ) )
            {
                exitShort();
                enterLong();
            }                                 
        }                  

        k++;

    }


    asset(AssetBox);

    plotQuarterProfit();

    // int i;
    // for( i = 0; i < ASSETS; i++ )
    // {
    //     char name[3];
    //     itoa(k,name); 
    //     plot( name, Z[k], LINE, RED );
    // }      

    r++;   

}
