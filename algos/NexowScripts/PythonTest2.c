
#include <nexow.h>

#define ASSETS 10
#define ASSETSPERALGO 3

typedef struct{
    string syms[10];
} info;
info algos[200];

void main()
{

	pyStart("",1);

	pySet("ass",ASSETS);
    pySet("apa",ASSETSPERALGO);
    pyX("from itertools import combinations\n");
	pyX("def rSubset(arr, r):\n
            return list(combinations(arr, r))\n");
    pyX("PyVec = rSubset(range(ass),apa)\n");
    pyX("for i in range(len(PyVec)):\n
            PyVec[i] = list(PyVec[i])\n");
    pyX("print(PyVec)\n");

    int alg = nAlgos(ASSETS,ASSETSPERALGO);

    int i, j; var Vec[ASSETSPERALGO];
    for( i = 0; i < alg; i++ ){
        pySet("i",i);
        pyX("ret = PyVec[i]\n");
        pyVec("ret",Vec,ASSETSPERALGO);       
        printf("\nalg: %d, syms: ", i);
        for(j=0; j<ASSETSPERALGO; j++) printf("%.0f ",Vec[j]);  
    }

}
