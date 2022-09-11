
#include <NexowFunctions.h>

double calculate_roll_long(double base_ir, double term_ir, double broker_fee, double margin){
    double ird = (base_ir - term_ir)/100;
    return margin*ird/365 - broker_fee;
}
double calculate_roll_short(double base_ir, double term_ir, double broker_fee, double margin){
    double ird = (term_ir - base_ir)/100;
    return margin*ird/365 - broker_fee;
}

void run(){

    set(PLOTNOW);
    
    StartDate = 2005;
    
    // Base interest rate from Quandl
        double Base_ir;
        if( strstr(Base(),"AUD") )
            Base_ir = dataFromQuandl(1, "%Y-%m-%d,f", "BIS/PD_DAU", 1);
        else if( strstr(Base(),"CAD") )
            Base_ir = dataFromQuandl(2, "%Y-%m-%d,f", "BIS/PD_DCA", 1);
        else if( strstr(Base(),"CHF") )
            Base_ir = dataFromQuandl(3, "%Y-%m-%d,f", "BIS/PD_DCH", 1);
        else if( strstr(Base(),"EUR") )
            Base_ir = dataFromQuandl(4, "%Y-%m-%d,f", "BIS/PD_DXM", 1);
        else if( strstr(Base(),"GBP") )
            Base_ir = dataFromQuandl(5, "%Y-%m-%d,f", "BIS/PD_DGB", 1);
        else if( strstr(Base(),"HKD") )
            Base_ir = dataFromQuandl(6, "%Y-%m-%d,f", "BIS/PD_DHK", 1);
        else if( strstr(Base(),"JPY") )
            Base_ir = dataFromQuandl(7, "%Y-%m-%d,f", "BIS/PD_DJP", 1);
        else if( strstr(Base(),"NZD") )
            Base_ir = dataFromQuandl(8, "%Y-%m-%d,f", "BIS/PD_DNZ", 1);
        else if( strstr(Base(),"SGD") )
            Base_ir = dataFromQuandl(9, "%Y-%m-%d,f", "BIS/PD_DHK", 1); // Hong Kong interest rate
        else if( strstr(Base(),"USD") )
            Base_ir = dataFromQuandl(10,"%Y-%m-%d,f", "BIS/PD_DUS", 1);
        else if( strstr(Base(),"XAU") || strstr(Base(),"XAG") )
            Base_ir = 0.0;
    //

    // Term interest rate from Quandl
    
        double Term_ir;
        if( strstr(Term(),"AUD") )
            Term_ir = dataFromQuandl(1, "%Y-%m-%d,f", "BIS/PD_DAU", 1);
        else if( strstr(Term(),"CAD") )
            Term_ir = dataFromQuandl(2, "%Y-%m-%d,f", "BIS/PD_DCA", 1);
        else if( strstr(Term(),"CHF") )
            Term_ir = dataFromQuandl(3, "%Y-%m-%d,f", "BIS/PD_DCH", 1);
        else if( strstr(Term(),"EUR") )
            Term_ir = dataFromQuandl(4, "%Y-%m-%d,f", "BIS/PD_DXM", 1);
        else if( strstr(Term(),"GBP") )
            Term_ir = dataFromQuandl(5, "%Y-%m-%d,f", "BIS/PD_DGB", 1);
        else if( strstr(Term(),"HKD") )
            Term_ir = dataFromQuandl(6, "%Y-%m-%d,f", "BIS/PD_DHK", 1);
        else if( strstr(Term(),"JPY") )
            Term_ir = dataFromQuandl(7, "%Y-%m-%d,f", "BIS/PD_DJP", 1);
        else if( strstr(Term(),"NZD") )
            Term_ir = dataFromQuandl(8, "%Y-%m-%d,f", "BIS/PD_DNZ", 1);
        else if( strstr(Term(),"SGD") )
            Term_ir = dataFromQuandl(9, "%Y-%m-%d,f", "BIS/PD_DHK", 1); // Hong Kong interest rate
        else if( strstr(Term(),"USD") )
            Term_ir = dataFromQuandl(10,"%Y-%m-%d,f", "BIS/PD_DUS", 1);
        else if( strstr(Term(),"XAU") || strstr(Term(),"XAG") )
            Term_ir = 0.0;
    //

    // Broker Fee
        double Broker_fee = 0.0;
        double MarginAmount = 10000;
    //

    // Calculate Swap rates
        double SwL = calculate_roll_long(Base_ir,Term_ir,Broker_fee,MarginAmount);
        double SwS = calculate_roll_short(Base_ir,Term_ir,Broker_fee,MarginAmount);
    //

	// Standarize to Swap rate to USD
        double SwapLong, SwapShort;
        if( strstr(Term(),"USD") ){
            SwapLong = SwL;
            SwapShort = SwS;
        }
        else if( strstr(Base(),"USD") ){
            SwapLong = SwL / priceClose(0);
            SwapShort = SwS / priceClose(0);
        }
        else
        {   
            char* Term = Term();            
            if( strstr(Term,"AUD") || strstr(Term,"EUR") || strstr(Term,"GBP") || strstr(Term,"NZD") || strstr(Term,"XAU") || strstr(Term,"XAG") )
            {
                char* CurrSym = Symbol;
                char Sym[8];
                strcpy(Sym,Term);
                strcat(Sym,"/");
                strcat(Sym,"USD");
                asset(Sym);
                double Price = priceClose(0);
                asset(CurrSym);
                SwapLong = SwL * Price;
                SwapShort = SwS * Price;
            }   
            else if( strstr(Term,"CAD") || strstr(Term,"CHF") || strstr(Term,"HKD") || strstr(Term,"JPY") || strstr(Term,"SGD") )
            {
                char* CurrSym = Symbol;
                char Sym[8];
                strcpy(Sym,"USD");
                strcat(Sym,"/");
                strcat(Sym,Term);
                asset(Sym);
                double Price = priceClose(0);
                asset(CurrSym);
                SwapLong = SwL / Price;
                SwapShort = SwS / Price;
            }
        }
    //
    
    // Plot brute Swaps interest and USD standarized Swap interests
        PlotWidth = 800;
        PlotHeight1 = 400;
        PlotHeight2 = 250;
        plot("SwapLongUSD",SwapLong,1,BLUE);
        plot("SwapLong",SwL,0,BLUE+TRANSP);
        plot("SwapShortUSD",SwapShort,0,RED);
        plot("SwapShort",SwS,0,RED+TRANSP);
        plot("Zero",0,0,BLACK);
    //

}