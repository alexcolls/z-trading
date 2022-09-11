
#include <nexow.h>

void run(){


    double K[5];

    K[0] = 0;
    K[1] = 1;
    K[2] = 2;
    K[3] = 3;
    K[4] = 4;

    AddToDoublesList(K,5,.9);
    int i;
    for ( i = 0; i < 5; i++)
    {
        printf("\n%d %f",i,K[i]);
    }
    

}