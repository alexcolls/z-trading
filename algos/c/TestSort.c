
#include <NexowFunctions.h>

symval Dists[3];

void main(){
    
   Dists[0].Sym = "A";
   Dists[0].Val = 1;
   Dists[1].Sym = "B";
   Dists[1].Val= -3;
   Dists[2].Sym = "C";
   Dists[2].Val = 8;

    int i;
    for( i = 0; i < 3; i++)
    {
        printf("\ni= %d, Symbol= %s, Value= %f", i, Dists[i].Sym, Dists[i].Val);
    }

    /*
    //swap(&Dists[j], &Dists[j+1]);
    int n = 3;
    int j;
    symval Temp[1];
    for(i = 0; i < n-1; i++){  
        for(j = 0; j < n-i-1; j++)  
            if(Dists[j].Val < Dists[j+1].Val){
                Temp[0].Sym = Dists[j].Sym;
                Temp[0].Val = Dists[j].Val;
                Dists[j].Sym = Dists[j+1].Sym;
                Dists[j].Val = Dists[j+1].Val;
                Dists[j+1].Sym = Temp[0].Sym;
                Dists[j+1].Val = Temp[0].Val;
            }
    }
    */
    sortsymval(3,Dists);

    for( i = 0; i < 3; i++)
    {
        printf("\nKK= %d, Symbol= %s, Value= %f", i, Dists[i].Sym, Dists[i].Val);
    }


}