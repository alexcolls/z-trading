
void run()
{
    set(PLOTNOW);
    
    StartDate = 2007;
    BarPeriod = 1440;
    
    ccyReset();	// reset strengths at begin of any bar
    string Name;
    while(Name = (loop(Assets)))
    {
        //if(assetType(Name) != FOREX) 
        //continue;
        asset(Name);
        double* Prices = series(price());
        double  Roc = StochEhlers(Prices,10,5,5);
        ccySet(Roc); // store price change as strength
        //plot("Roc",Roc,1,BLUE);
    }
    auto
    // get currency pairs with highest and lowest strength difference
    string Best = ccyMax(), Worst = ccyMin();
    double Threshold = 0;

    plot("Threshold",Threshold,1,BLACK);
    //plot("Best",ccyStrength(Best),0,BLUE);
    //plot("Worst",ccyStrength(Worst),0,RED);


    static char OldBest[8], OldWorst[8];	// static for keeping contents between runs
    if(*OldBest && !strstr(Best,OldBest)) { // new strongest asset?
        asset(OldBest);
        exitLong();
        printf("\nExitBest: %s",Symbol);
        if(ccyStrength(Best) > Threshold) {
        asset(Best);
        enterLong();
        printf("\nEnterBest: %s",Symbol);
        }
    } 
    if(*OldWorst && !strstr(Worst,OldWorst)) { // new weakest asset?
        asset(OldWorst);
        exitShort();
        printf("\nExitWorse: %s",Symbol);
        if(ccyStrength(Worst) < -Threshold) {
        asset(Worst);
        enterShort();
        printf("\nEnterWorse: %s",Symbol);
        }
    }

    // store previous strongest and weakest asset names  
    strcpy(OldBest,Best);
    strcpy(OldWorst,Worst);
    
}
