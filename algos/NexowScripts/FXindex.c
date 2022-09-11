
#include <nexow.h>

double AUD;
double CAD;
double CHF;
double EUR;
double GBP;
double JPY;
double HKD;
double SGD;
double NZD;
double USD;

vars AUDs;
vars CADs;
vars CHFs;
vars EURs;
vars GBPs;
vars JPYs;
vars HKDs;
vars SGDs;
vars NZDs;
vars USDs;

FILE *aud;
FILE *cad;
FILE *chf;
FILE *eur;
FILE *gbp;
FILE *jpy;
FILE *hkd;
FILE *sgd;
FILE *nzd;
FILE *usd;

void run(){

    set(PLOTNOW);
	assetList("OandaEuropeFX45.csv");
    StartDate = 2006;
    BarPeriod = 1440;
/*
    if( is(INITRUN) ){
        aud = fopen("P:\\TeamWork\\MARCT\\AUD.csv", "a+");
        cad = fopen("P:\\TeamWork\\MARCT\\CAD.csv", "a+");
        chf = fopen("P:\\TeamWork\\MARCT\\CHF.csv", "a+");
        eur = fopen("P:\\TeamWork\\MARCT\\EUR.csv", "a+");
        gbp = fopen("P:\\TeamWork\\MARCT\\GBP.csv", "a+");
        jpy = fopen("P:\\TeamWork\\MARCT\\JPY.csv", "a+");
        hkd = fopen("P:\\TeamWork\\MARCT\\HKD.csv", "a+");
        sgd = fopen("P:\\TeamWork\\MARCT\\SGD.csv", "a+");
        nzd = fopen("P:\\TeamWork\\MARCT\\NZD.csv", "a+");
        usd = fopen("P:\\TeamWork\\MARCT\\USD.csv", "a+");
    }
*/
    while(asset(loop(Assets))){
        
        double Price;

        if( Term() == "JPY")
            Price = price(0)/100;
        else if( Term() == "HKD" )
            Price = price(0)/8;
        else if( Base() == "HKD" )
            Price = price(0)*8;
        else
            Price = price(0);
        
        if( Base() == "AUD" )
            AUD += 1/Price;
        else if( Term() == "AUD" )
            AUD += Price;

        if( Base() == "CAD" )
            CAD += 1/Price;
        else if( Term() == "CAD" )
            CAD += Price;

        if( Base() == "CHF" )
            CHF += 1/Price;
        else if( Term() == "CHF" )
            CHF += Price;

        if( Base() == "EUR" )
            EUR += 1/Price;
        else if( Term() == "EUR" )
            EUR += Price;

        if( Base() == "GBP" )
            GBP += 1/Price;
        else if( Term() == "GBP" )
            GBP += Price;

        if( Base() == "JPY" )
            JPY += 1/Price;
        else if( Term() == "JPY" )
            JPY += Price;

        if( Base() == "HKD" )
            HKD += 1/Price;
        else if( Term() == "HKD" )
            HKD += Price;

        if( Base() == "SGD" )
            SGD += 1/Price;
        else if( Term() == "SGD" )
            SGD += Price;

        if( Base() == "NZD" )
            NZD += 1/Price;
        else if( Term() == "NZD" )
            NZD += Price;

        if( Base() == "USD" )
            USD += 1/Price;
        else if( Term() == "USD" )
            USD += Price;

    }

    AUD = 1/((AUD+1)/10);
    CAD = 1/((CAD+1)/10);
    CHF = 1/((CHF+1)/10);
    EUR = 1/((EUR+1)/10);
    GBP = 1/((GBP+1)/10);
    JPY = 1/((JPY+1)/10);
    HKD = 1/((HKD+1)/10);
    SGD = 1/((SGD+1)/10);
    NZD = 1/((NZD+1)/10);
    USD = 1/((USD+1)/10);

    AUDs = series(AUD);
    CADs = series(CAD);
    CHFs = series(CHF);
    EURs = series(EUR);
    GBPs = series(GBP);
    JPYs = series(JPY);
    HKDs = series(HKD);
    SGDs = series(SGD);
    NZDs = series(NZD);
    USDs = series(USD);

    PlotHeight1 = 600; PlotHeight2 = 100;
	ColorUp = ColorDn = ColorWin = ColorLoss = ColorEquity = ColorDD = 0;
	
    plot("AUD",AUDs,0,RED);
    plot("CAD",CADs,0,BLUE);
    plot("CHF",CHFs,0,DARKGREEN);
    plot("EUR",EURs,0,DARKBLUE);
    plot("GBP",GBPs,0,GREEN);
    plot("JPY",JPYs,0,ORANGE);
    plot("HKD",HKDs,0,PURPLE);
    plot("SGD",SGDs,0,YELLOW);
    plot("NZD",NZDs,0,CYAN);
    plot("USD",USDs,0,MAGENTA);

    // if( TRUE ){
    //     fputs(strf("%d,%f\n", utm(wdate()), AUD), aud);
    //     fputs(strf("%d,%f\n", utm(wdate()), CAD), cad);
    //     fputs(strf("%d,%f\n", utm(wdate()), CHF), chf);
    //     fputs(strf("%d,%f\n", utm(wdate()), EUR), eur);
    //     fputs(strf("%d,%f\n", utm(wdate()), GBP), gbp);
    //     fputs(strf("%d,%f\n", utm(wdate()), JPY), jpy);
    //     fputs(strf("%d,%f\n", utm(wdate()), HKD), hkd);
    //     fputs(strf("%d,%f\n", utm(wdate()), SGD), sgd);
    //     fputs(strf("%d,%f\n", utm(wdate()), NZD), nzd);
    //     fputs(strf("%d,%f\n", utm(wdate()), USD), usd);
    // }

    // if( is(EXITRUN) ){
    //     fclose(aud);
    //     fclose(cad);
    //     fclose(chf);
    //     fclose(eur);
    //     fclose(gbp);
    //     fclose(jpy);
    //     fclose(hkd);
    //     fclose(sgd);
    //     fclose(nzd);
    //     fclose(usd);
    // }

}