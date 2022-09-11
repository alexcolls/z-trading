// do some R calculations
#include <default.c>
#include <r.h>

function main()
{
  Rstart("",2); // enable output 
  
  var vecIn[5],vecOut[5];
  int i;
  for(i=0; i<5; i++) 
    vecIn[i] = i;
  
  Rset("rin",vecIn,5); // set up a vector
  Rx("rout <- rin * 10"); // perform some arithmetics
  Rx("print(rout)",3); // print rout to the Zorro window 
  Rv("rout",vecOut,5); // read it back
   
   if(!Rrun()) 
     printf("Error - R session aborted!");
   else 
    for(i=0; i<5; i++) 
      printf("%.0f ",vecOut[i]);
}

