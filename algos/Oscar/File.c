
void run()
{

    BarPeriod = 1440;
    asset("EUR/USD");

    double* X = series(price());

    file_write("C:\\ZorroBeta\\History\\File.txt",X,0);
    
}