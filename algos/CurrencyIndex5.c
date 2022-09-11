
///----------------------------------\\\ 
///      FX G12 CURRENCY INDEX       \\\ 
///----------------------------------\\\ 
///        NEXOW SYSTEMS S.L.        \\\ 
///        Author: Alex Colls        \\\ 
///         Date: May 2019           \\\ 
///          Version: 1.0            \\\ 
///----------------------------------\\\ 

#include <NexowFunctions.h>

    /// 1. STRATEGY PARAMETERS \\\ 

        #define ASSETLIST "AssetsFix"
        #define TIMEFRAME 1440
        #define TIMEZONE UTC

        #define SET_PLOT TRUE

    ///

void run(){

    /// 2. ZORRO PARAMETERS \\\ 
        
        BarZone = TIMEZONE;
        BarPeriod = TIMEFRAME;
        StartDate = 2007;
        LookBack = 200;
        /*
        if( SET_PLOT ){
            set(PLOTNOW);
            setf(PlotMode,PL_LONG+PL_FINE+PL_DIFF);
        }
        */
       set(PLOTNOW);

        /// 2.1. ASSET & ACCOUNT PARAMETERS

        assetList(ASSETLIST);
        setFXaccounting(1,-1);
        setFees(0.0,0.0,0.0,5);    

    ///

    /// 3. INDICATORS & PORTFOLIO \\\ 
    
    while(asset(loop(Assets))){
        double* Prices = series(priceClose());    
        double MA1 = EMA(Prices,10);
        double MA2 = EMA(Prices,30);
        double MA3 = EMA(Prices,60);
        double Dist = ( (priceClose(0)-MA1)/MA1 + (priceClose(0)-MA2)/MA2 + (priceClose(0)-MA3)/MA3 )*100;
        Ccy_Set(Dist);
    }

    int Periods = 20;
    
    Ccy_AddVals(Periods);

    pairval Pairs_Correl[67], Pairs_Correl2[67];

    int i, j, n;
    for ( i = 0; i < Ccy_n; i++ ){
        double Correl;
        for( j = 0; j < Ccy_n; j++ ){
            if( !strstr(Ccy_Vals[i].Ccy,Ccy_Vals[j].Ccy) ){
                char Pair[8];
                strcpy(Pair,Ccy_Vals[i].Ccy);
                strcat(Pair,"/");
                strcat(Pair,Ccy_Vals[j].Ccy);
                if( IsSymbolCorrect(Pair) ){
                    strcpy(Pairs_Correl[n].Pair,Pair);
                    double AvgRet_i = SMA(Ccy_Vals[i].Val,Periods);
                    double StDev_i = StdDev(Ccy_Vals[i].Val,Periods);
                    double AvgRet_j = SMA(Ccy_Vals[j].Val,Periods);
                    double StDev_j = StdDev(Ccy_Vals[j].Val,Periods);
                    double i_up = AvgRet_i + StDev_i;
                    double i_dn = AvgRet_i - StDev_i;
                    double j_up = AvgRet_j + StDev_j;
                    double j_dn = AvgRet_j - StDev_j;
                    /*
                    int p, v, r_i, r_j;
                    for( p = 0; p < Periods; p++ ){
                        if( Ccy_Vals[i].Val[p] > Ccy_Vals[j].Val[p] )
                            v++;
                        else if( Ccy_Vals[i].Val[p] < Ccy_Vals[j].Val[p] )
                            v--;
                        */


                        /*
                        if( ( Ccy_Vals[i].Val[p] > 0 && Ccy_Vals[j].Val[p] > 0 ) || ( Ccy_Vals[i].Val[p] < 0 && Ccy_Vals[j].Val[p] < 0 ) )
                            v++;
                        else if( ( Ccy_Vals[i].Val[p] > 0 && Ccy_Vals[j].Val[p] < 0 ) || ( Ccy_Vals[i].Val[p] < 0 && Ccy_Vals[j].Val[p] > 0 ) )
                            v--;
                        */
                        /*
                        if( Ccy_Vals[i].Val[p] > 0 )//>= StDev_i )
                            r_i++;
                        else if( Ccy_Vals[i].Val[p] < 0 )//<= -StDev_i )
                            r_i--;
                        if( Ccy_Vals[j].Val[p] > 0 )//>= StDev_j )
                            r_j++;
                        else if( Ccy_Vals[j].Val[p] < 0 )//<= -StDev_j )
                            r_j--;
                        */
                        /*                     
                        if( Ccy_Vals[i].Val[p] >= i_up && Ccy_Vals[j].Val[p] >= j_up )
                            v++;
                        else if( Ccy_Vals[i].Val[p] <= i_dn && Ccy_Vals[j].Val[p] <= j_dn )
                            v++;
                        else if( Ccy_Vals[i].Val[p] < i_up && Ccy_Vals[i].Val[p] > i_dn && Ccy_Vals[j].Val[p] < j_up && Ccy_Vals[j].Val[p] > j_dn )
                            v++;
                        else
                            v--;
                        */
                    //}
                    Pairs_Correl[n].Val = AvgRet_i-AvgRet_j;
                    //Pairs_Correl[n].Val = ((double)r_i-(double)r_j);//(double)Periods;
                    //Pairs_Correl[n].Val = (double)v/(((double)Periods*((double)Periods-1))/2);
                    //Pairs_Correl[n].Val = Correlation(Ccy_Vals[i].Val,Ccy_Vals[j].Val,30);
                    //Pairs_Correl2[n].Val = Correlation(Ccy_Vals[i].Val,Ccy_Vals[j].Val,10);
                    n++;
                }
            }
        }
    }

    //sortpairval(66,Pairs_Correl);
    //sortpairval(66,Pairs_Correl2);

    double Correl, Correl2;
    for( i = 0; i < 66; i++ ){
        //printf("\ni= %d Sym= %s Val= %f",i,Pairs_Correl[i].Pair,Pairs_Correl[i].Val);
        if( strstr(Pairs_Correl[i].Pair,AssetBox) ){
            Correl = Pairs_Correl[i].Val;
            //Correl2 = Pairs_Correl2[i].Val;
        }
    }
    //printf("\n");

    asset(AssetBox);
    double* Prices = series(priceClose());    
    double MA1 = EMA(Prices,10);
    double MA2 = EMA(Prices,30);
    double MA3 = EMA(Prices,60);
    double Dist2 = ( (priceClose(0)-MA1)/MA1 + (priceClose(0)-MA2)/MA2 + (priceClose(0)-MA3)/MA3 )*100;
    double* Dist2s = series(Dist2);
    double D2 = SMA(Dist2s,Periods);
    double* CorrelS = series(Correl,100);
    double MA = LowPass(CorrelS,Periods);
    double EMA = LowPass(series(price()),Periods);
    double T = Correl-D2;
    double* TT = series(T);
    double Thres = 0.5;

    static int Dir;
    static double Max, Max1, Min, Min1;
    if( T>0 && T>Max )
        Max = T;
    else if( T<0 && T<Min )
        Min = T;
    
    if( TT[0]>0 && TT[1]<0 ){
        if( abs(Min)>Thres && Max1>abs(Min) )
            Dir = 1;
        else Dir = 0;
        Min1 = Min;
        Min = 0;
    }
    else if( TT[0]<0 && TT[1]>0 ){
        if( Max>Thres && abs(Min1)>Max )
            Dir = -1;
        else Dir = 0;
        Max1 = Max;
        Max = 0;
    }

    plot("Z1",0,1,BLACK);
    plot("Dir",Dir,BARS,RED);

    //plot("EMA",EMA,0,RED);
    //plot("Correl",Correl,1,BLUE);
    //plot("CorrelMA",D2,0,RED);
    //plot("UP",0.9,0,BLACK);
    plot("T",T,1,RED);
    plot("Max",Max,0,BLUE);
    plot("Min",Min,0,BLUE);
    plot("Tmax",Thres,0,BLACK);
    plot("Tmin",-Thres,0,BLACK);
    plot("Z",0,0,BLACK);
    //plot("DN",-0.9,0,BLACK);

    Ccy_Reset();
    
}