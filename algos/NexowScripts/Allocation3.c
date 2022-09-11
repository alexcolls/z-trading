
// G12 Trading Strategy with Allocation //

#include <NexowFunctions.h>

#define ASSETS 66
#define BARS 5

typedef struct{
    char* Name;
    double Correl;
    double Sharpe;
} cdd;

typedef struct{
    char* Name;
    double Alloc;
} cd;

void run(){

    BarPeriod = 1440;
    StartDate = 2015;

    double PortReturns[BARS];
    double Returns[BARS];
    int i, j, k;
    
    // Portfolio Returns

        for(i = 0; i < BARS; i++){
            j = 0;
            while(asset(loop(Assets))){
                j++;   
                PortReturns[i] += ( ( (log(price(i))-log(price(i+1)))*100 ) / j );
            }
        }

    // Portfolio Allocation per Symbol

        cdd Correls[ASSETS];
        double Sharpe;
        while(asset(loop(Assets))){
            for(i = 0; i < BARS; i++){
                Returns[i] = (log(price(i))-log(price(i+1)))*100;
                //printf("\nSymbol: %s, Return: %f", Symbol, Returns[i]);
            }
            double Mean = SMA(Returns,BARS);
            double PortMean = SMA(PortReturns,BARS);
            double StDv = StdDev(Returns,BARS);
            if( StDv == 0 )
                Sharpe = 1;
            else
                Sharpe = ( Mean / StDv );
            double Correl = 1-Correlation(Returns,PortReturns,BARS);
            //printf("\nPortMean= %f, Mean= %f, StDv= %f, Sharpe= %f, Correl= %f", PortMean, Mean, StDv, Sharpe, Correl);
            Correls[k].Name = Symbol;
            Correls[k].Correl = Correl;
            Correls[k].Sharpe = Sharpe;
            plot("SH",Sharpe,1,RED);
            k++;
        }
        
        double SumCorrels;
        for(k = 0; k < ASSETS; k++){
            SumCorrels += abs(Correls[k].Correl);
        }
        
        k = 0;
        cd Allocs[ASSETS];
        while(asset(loop(Assets))){
            double Percent;
            if(strcmp(Symbol,Correls[k].Name) == 0){
                Percent = (Correls[k].Correl/SumCorrels)*100;
            }
            Allocs[k].Name = Symbol;
            Allocs[k].Alloc = Percent * Correls[k].Sharpe;
            //printf("\nK= %d, Symbol= %s, Correl= %f, Percent= %f, Sharpe= %f, Alloc= %f", k, Allocs[k].Name, Correls[k].Correl, Percent, Correls[k].Sharpe, Allocs[k].Alloc);
            k++;
        }

    //

    // Trading Strategy 

        set(PLOTNOW);

        double Collateral = 100000;
        double Allocation[2];

        double Threshold = 1.0;
                
        while(asset(loop(Assets))){
            for(k = 0; k < ASSETS; k++){
                if(strcmp(Symbol,Allocs[k].Name) == 0){
                    Allocation[1] = Allocation[0];
                    Allocation[0] = Allocs[k].Alloc;
                    //printf("\nSymbol= %s, Alloc= %f", Allocs[k].Name, Allocs[k].Alloc);
                }
            }
            double* MA = series(EMA(series(price()),BARS));
            plot("MA",MA,0,RED);
            plot("Price",price(0),0,BLUE);
            plot("Alloc",Allocation[0],1,BLUE);
            plot("Alloc1",Allocation[1],0,RED);
            plot("Zero",0,0,BLACK);
            
            RollLong = RollShort = 0;
            Commission = 0;
            //Spread = 0;
            Trail = ATR(10);
            //setCurrentSwap(0.1);
            //PIPCost = PipValue_USD();
            Margin = Collateral * abs(Allocation[0])/100;

            if( Allocation[0] < Allocation[1] )
                exitLong();
            else if( Allocation[0] > Allocation[1] )
                exitShort();   
                        
            if( Allocation[0] < Allocation[1] && Allocation[0] < -Threshold )
                enterShort();
            else if( Allocation[0] > Allocation[1] && Allocation[0] > Threshold )
                enterLong();          
        }  

    //

}