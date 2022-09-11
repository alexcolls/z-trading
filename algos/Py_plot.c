
#include <NexowFunctions.h>

void main()
{
  
    Rstart("",2); // enable output 
    
    double vecIn[5],vecOut[5];
    int i;
    for(i=0; i<5; i++) 
        vecIn[i] = i;
    
    Rset("rin",vecIn,5); // set up a vector
    Rx("rout <- rin * 10"); // perform some arithmetics
    Rx("plot(rout)",0); // print rout to the Zorro window 
    Rv("rout",vecOut,5); // read it back
    
    /*
    if(!Rrun()) 
        printf("Error - R session aborted!");
    else 
        for(i=0; i<5; i++) 
        printf("%.0f ",vecOut[i]);
        */
}






/*
// export historical price data to Rstring name = "Data\\Export.csv";
void run(){  
    
    BarPeriod = 60;  
    StartDate = 20140101;
    
    if(is(INITRUN)) // write the header
        file_write("AUDCAD","Date, Open, High, Low, Close",0);  
    else
        file_append("AUDCAD",strf(
            "\n%04i-%02i-%02i %02i:%02i, %.5f, %.5f, %.5f, %.5f",
            year(),month(),day(),hour(),minute(),
            priceOpen(),priceHigh(),priceLow(),priceClose()));
            
}

 in R:
> Data <- read.csv('C:/Projects/Zorro/Data/export.csv') # mind the forward slashes
> plot(Data$Close)> ...

*/