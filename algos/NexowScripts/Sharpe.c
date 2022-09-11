
#include <NexowFunctions.h>

#define BARS 5
#define BARS2 10

void run(){

    set(PLOTNOW);

    BarPeriod = 1440;
    StartDate = 2005;

    double Returns[BARS];
    double Returns2[BARS2];
    int i;
    
    //while(asset(loop(Assets))){
        // Returns

            for(i = 0; i < BARS; i++){
                Returns[i] = (price(i)/price(i+1)-1)*100;
                //Returns[i] = (log(price(i))-log(price(i+1)))*100;
                //printf("\nSymbol: %s, Return: %f", Symbol, Returns[i]);
            }
            for(i = 0; i < BARS2; i++){
                Returns2[i] = (price(i)/price(i+1)-1)*100;
                //Returns[i] = (log(price(i))-log(price(i+1)))*100;
                //printf("\nSymbol: %s, Return: %f", Symbol, Returns[i]);
            }

        //

        double* Mean = series(SMA(Returns,BARS),2);
        double* Mean2 = series(SMA(Returns2,BARS2),2);
        double* StDv = series(StdDev(Returns,BARS),2);
        double* StDv2 = series(StdDev(Returns2,BARS2),2);
        double Sharpe[2], Sharpe2[2];
        if( StDv[0] == 0 )
            Sharpe[0] = 1;
        if( StDv[1] == 0 )
            Sharpe[1] = 1;
        else{
            Sharpe[0] = ( Mean[0] / StDv[0] );
            Sharpe[1] = ( Mean[1] / StDv[1] );
        }
        if( StDv2[0] == 0 )
            Sharpe2[0] = 1;
        if( StDv2[1] == 0 )
            Sharpe2[1] = 1;
        else{
            Sharpe2[0] = ( Mean2[0] / StDv2[0] );
            Sharpe2[1] = ( Mean2[1] / StDv2[1] );
        }
        double Atr = ATR(BARS);
        double UpB = priceHigh(1)+Atr;
        double DnB = priceLow(1)-Atr;
        /*
        plot("UpB",UpB,0,BLUE);
        plot("DnB",DnB,0,BLUE);

        plot("Sharpe",Sharpe[0],1,RED);
        //plot("Sharpe2",Sharpe2[0],0,BLUE);
        plot("Z1",1,0,BLACK);
        plot("Z0",0,0,BLACK);
        plot("Z-1",-1,0,BLACK);
        plot("StDv1",StDv[0],1,RED);
        plot("StDv2",-StDv[0],0,RED);
        plot("Mean",Mean[0],0,BLUE);
        plot("Z",0,0,BLACK);
        */
        // Strategy

            /*
            exitShort();

            double Thres = 1;

            if( Sharpe[0]>Thres && Mean[0]<Mean[1] )
                enterShort();
            */

            Spread = Commission = RollLong = RollShort = 0;
            /*
            if( Mean[0]>StDv[0] && Mean[1]<StDv[1] )
                enterShort();
            if( Mean[0]<StDv[0] && Mean[1]>StDv[1] )
                exitShort();
            if( Mean[0]<-StDv[0] && Mean[1]>-StDv[1] )
                enterLong();
            if( Mean[0]>-StDv[0] && Mean[1]<-StDv[1] )
                exitLong();
            */

            if( priceClose(0)>priceOpen(0) && Sharpe[0]<Sharpe[1] )
                enterShort();
            
            
            if( priceClose(0)<priceOpen(0) && Sharpe[0]>Sharpe[1] )
                enterLong();
          
            

        //
    //}

}