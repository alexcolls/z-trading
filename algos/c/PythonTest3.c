
#include <nexow.h>

#define ASSETS 16
#define ASSETSPERALGO 2

typedef struct{
    string algo;
    string asset[ASSETSPERALGO];
    int startyear;
    int starthour;
    int endhour;
} algoinfo;
algoinfo algoinfos[1000];

int alg = 0;

void initAlgoInfos( int ass, int apa ){

    pyStart("",1);

	pySet("ass",ass);
    pySet("apa",apa);
    pyX("from itertools import combinations\n");
	pyX("def rSubset(arr, r):\n
            return list(combinations(arr, r))\n");
    pyX("PyIdx = rSubset(range(ass),apa)\n");
    pyX("for i in range(len(PyIdx)):\n
            PyIdx[i] = list(PyIdx[i])\n");
    pyX("print(PyIdx)\n");

    int i, j; var Idx[ASSETSPERALGO];
    for( i = 0; i < alg; i++ ){
        pySet("i",i);
        pyX("ret = PyIdx[i]\n");
        pyVec("ret",Idx,ASSETSPERALGO);       
        for(j=0; j<ASSETSPERALGO; j++){
            algoinfos[i].asset[j] = Assets[Idx[j]]; 
        }
    }

}

void main()
{
    assetList("OandaEuropeIndex");


    alg = nAlgos(ASSETS,ASSETSPERALGO);
    initAlgoInfos(ASSETS,ASSETSPERALGO);

    int i, j;
    for( i = 0; i < alg; i++ ){
        printf("\nalg: %d ", i);
        for(j=0; j<ASSETSPERALGO; j++){
            printf(" - %s - ",algoinfos[i].asset[j]);  
        }
    }

}
