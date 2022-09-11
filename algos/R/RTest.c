#include <r.h>

function main()
{
	Rstart();
	
	var vecIn[5],vecOut[5];
	int i;
	for(i=0; i<5; i++) 
		vecIn[i] = i;
	
	Rset("Rin",vecIn,5);
	Rx("Rout <- Rin * 10");
	Rv("Rout",vecOut,5);
	
	if(!Rrun()) 
		printf("Error - R session aborted!");
	else 
		for(i=0; i<5; i++) 
			printf("%.0f ",vecOut[i]);
}
