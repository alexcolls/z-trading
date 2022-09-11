
#include <nexow.h> 

typedef struct{
    string syms[10];
} info;
info algos[200];

#define ASSETS 8
#define ASSETSPERALGO 3

int alg = 0;
string* setSymsPerAlgos( string* assetlist, string* recarr, int i, int ass, int apa ){
	if( apa > ass ){
        printf("\nError -> More APA than ASS");
		return;
    }
	if( apa == 0 ){
        printf("\nalg %d",alg);
        printstrarr(recarr,0,10);    
        alg++;
		return;
	}
    int j;
	for( j = i; j < ass; j++ ){
        string aux[10];
        resstrarr(aux);
        appstrarr(aux, recarr);
        appstr(aux, assetlist[j]);
        setSymsPerAlgos(assetlist, aux, j + 1, ass, apa - 1);
	}
}

void main(){

	string assetlist[10];
    
    assetlist[0] = "A";
    assetlist[1] = "B";
    assetlist[2] = "C";
    assetlist[3] = "D";
    assetlist[4] = "E";
    assetlist[5] = "F";
    assetlist[6] = "G";
    assetlist[7] = "H";

	setSymsPerAlgos(assetlist, "", 0, ASSETS, ASSETSPERALGO);

    // int i, j;
    // for( i = 0; i < alg; i++ ){
    //     for( j = 0; j < ASSETSPERALGO; j++ ){
    //         printf("\nalgo %d syms %d = %s", i, j, algos[i].syms[j]);
    //     }
    // }

    // printstrarr(algos[0].syms,0,10);    

   

}


