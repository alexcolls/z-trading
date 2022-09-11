
void run()
{
    set(PLOTNOW);
    StartDate = 2015;

    // Parameters //

        BarPeriod = 15;
        int BBper = 162;
        double nDev = 2;
        int minBars = 5;
        int maxBars = 100;

    //

    // Indicators //

        double* Prices = series(priceClose());
        double  Sma = SMA(Prices,BBper);
        double  StDev = StdDev(Prices,BBper);
        double  BBup = Sma+StDev*nDev;
        double  BBdn = Sma-StDev*nDev;

        plot("Sma",Sma,0,BLACK);
        plot("BBup",BBup,0,RED);
        plot("BBdn",BBdn,0,BLUE);

        int i; double AvgBar;
        for( i = 0 ; i < BBper ; i++ )
        {
            double Avg = abs(priceClose(i)-priceClose(i+1));
            AvgBar += Avg;
        }
        double Vol = (AvgBar/BBper)*4;

    //

    // Strategy //

        static int n;
        if( ( priceClose(0) < BBup && priceClose(0) > BBdn ) || n >= maxBars ) 
            n = 0;
        else n++;

        static double BuyLevel, SellLevel;
        if( n == minBars )
        {
            if( priceClose(0) > BBup )
                BuyLevel = priceClose(0);
            else if( priceClose(0) < BBdn )
                SellLevel = priceClose(0);
        }

        if( BuyLevel != Sma && priceClose(0) < Sma )
            BuyLevel = Sma;
        else if( SellLevel != Sma && priceClose(0) > Sma )
            SellLevel = Sma;

        plot("BL",BuyLevel,0,BLUE);
        plot("SL",SellLevel,0,RED);

        plot("n",n,1,BLACK);
        plot("StDev",StDev,1,RED);
        plot("AvgBar",Vol,0,BLUE);
        


    //

}

