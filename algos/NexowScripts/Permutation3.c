
#include <nexow.h> 

typedef struct{
    string syms[10];
} info;
info algos[200];

#define ASSETS 4
#define ASSETSPERALGO 3

int alg = 0;
void setSymsPerAlgos( int* assetlist, int* recarr, int i, int ass, int apa ){
	if( apa > ass ){
        printf("\nError -> More APA than ASS");
		return;
    }
	if( apa == 0 ){
        printf("\nalg %d   %d",alg);
        printintarr(recarr,0,10);    
        alg++;
		return;
	}
    int j;
	for( j = i; j < ass; j++ ){
        int aux[10];
        resintarr(aux);
        appintarr(aux, recarr);
        appint(aux, assetlist[j]);
        setSymsPerAlgos(assetlist, aux, j + 1, ass, apa - 1);
	}
}

void main(){

	int assetlist[10] = { 0,1,2,3,4,5,6,7,8,10 };
    

    int aux[10] = {-1};
	setSymsPerAlgos(assetlist, aux, 0, ASSETS, ASSETSPERALGO);

    // int i, j;
    // for( i = 0; i < alg; i++ ){
    //     for( j = 0; j < ASSETSPERALGO; j++ ){
    //         printf("\nalgo %d syms %d = %s", i, j, algos[i].syms[j]);
    //     }
    // }

    // printstrarr(algos[0].syms,0,10);    

   

}


