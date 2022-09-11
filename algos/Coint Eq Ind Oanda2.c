
//////////////////////////////////////// \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
///                                                                           \\\
///  ### Long-Short Cointegration Strategy -> OandaEurope Equity Indices ###  \\\
///                                                                           \\\
/// 		Copyright © 2019 Nexow Systems, S.L. All rights reserved.         \\\
//////////////////////////////////////// \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

#include <nexow.h>

/* Select Universe */

	#define ASSETLIST "Test"
	#define ASSETS 124
	#define ASSETSPERALGO 2
	const int ALGOS;

/* FX Settings */

	#define ACC_CURR "USD"
	#define QUOTE_CCYs 6


/* General Data Structs */

	/* Infos structs */

	typedef struct{
		string asset;
		double ccyprice;
		int startyear;
		int starthour;
		int endhour;
	} assetinfo;
	assetinfo assetsinfo[ASSETS];

	typedef struct{
		char algo[6];
		string asset[ASSETSPERALGO];
		int startyear;
		int starthour;
		int endhour;
	} algoinfo;
	algoinfo algosinfo[120000];

	/* Stats structs */

	typedef struct{
		string asset;
		double balance;
		double realized;
		double equity;
		double unrealized;
		double winval;
		double lossval;
		double strwinval;
		double strlossval;
		int win;
		int loss;
		int strkwin;
		int strloss;
	} assetstat;
	assetstat assetstats[ASSETS];

	typedef struct{
		string algo;
		string asset[ASSETS];
		double balance;
		double realized;
		double equity;
		double unrealized;
		double winval;
		double lossval;
		double strwinval;
		double strlossval;
		int win;
		int loss;
		int strkwin;
		int strloss;
	} algostat;
	algostat algostats[1200];

	/* FX structs */

	typedef struct{
    string ccy;
	string cross;
	int inver;
    double rate;
	} fxrate;
	fxrate FX[QUOTE_CCYs];
	int nCCY = 1;


/* Startegy Data Structs */

	typedef struct{
	string algo;
    string sym1;
	string sym2;
	int pos1;
	int pos2;
	double mar1;	
	double mar2;
	vars arr1;
	vars arr2;
	var indic;
	} algostrategy;
	algostrategy algos[1200];

enri@fustesgilabert.com

/* Init Fuctions */

	int ass = 0;
	int apa = 0;
	int alg = 0;

	void init_assetsinfo(){	
		/* AU200_AUD */
		assetsinfo[ass].asset = strf("%c%c%c%c%c%c%c%c%c");
		strcpy(assetsinfo[ass].asset,"AU200_AUD");
		//assetsinfo[ass].asset = "AU200_AUD";
		assetsinfo[ass].startyear = 2006;
		assetsinfo[ass].starthour = 0;
		assetsinfo[ass].endhour = 16;
		/* CN50_USD */ ass = 1;
		assetsinfo[ass].asset = strf("%c%c%c%c%c%c%c%c%c");
		strcpy(assetsinfo[ass].asset,"CN50_USD");
		//assetsinfo[ass].asset = "CN50_USD";
		assetsinfo[ass].startyear = 2012;
		assetsinfo[ass].starthour = 1;
		assetsinfo[ass].endhour = 17;
		/* EU50_EUR */ ass = 2;
		assetsinfo[ass].asset = strf("%c%c%c%c%c%c%c%c%c");
		strcpy(assetsinfo[ass].asset,"EU50_EUR");
		//assetsinfo[ass].asset = "EU50_EUR";
		assetsinfo[ass].startyear = 2006;
		assetsinfo[ass].starthour = 6;
		assetsinfo[ass].endhour = 20;
		/* FR40_EUR */ ass = 3;
		assetsinfo[ass].asset = strf("%c%c%c%c%c%c%c%c%c");
		strcpy(assetsinfo[ass].asset,"FR40_EUR");
		//assetsinfo[ass].asset = "FR40_EUR";
		assetsinfo[ass].startyear = 2006;
		assetsinfo[ass].starthour = 7;
		assetsinfo[ass].endhour = 20;
		/* DE30_EUR */ ass = 4;
		assetsinfo[ass].asset = strf("%c%c%c%c%c%c%c%c%c");
		strcpy(assetsinfo[ass].asset,"DE30_EUR");
		//assetsinfo[ass].asset = "DE30_EUR";
		assetsinfo[ass].startyear = 2006;
		assetsinfo[ass].starthour = 6;
		assetsinfo[ass].endhour = 20;
		/* HK33_HKD */ ass = 5;
		assetsinfo[ass].asset = strf("%c%c%c%c%c%c%c%c%c");
		strcpy(assetsinfo[ass].asset,"HK33_HKD");
		//assetsinfo[ass].asset = "HK33_HKD";
		assetsinfo[ass].startyear = 2006;
		assetsinfo[ass].starthour = 1;
		assetsinfo[ass].endhour = 17;
		/* IN50_USD */ ass = 6;
		assetsinfo[ass].asset = strf("%c%c%c%c%c%c%c%c%c");
		strcpy(assetsinfo[ass].asset,"IN50_USD");
		//assetsinfo[ass].asset = "IN50_USD";
		assetsinfo[ass].startyear = 2012;
		assetsinfo[ass].starthour = 2;
		assetsinfo[ass].endhour = 20;
		/* JP225_USD */ ass = 7;
		assetsinfo[ass].asset = "JP225_USD";
		assetsinfo[ass].startyear = 2006;
		assetsinfo[ass].starthour = 0;
		assetsinfo[ass].endhour = 20;
		/* NL25_EUR */ ass = 8;
		assetsinfo[ass].asset = "NL25_EUR";
		assetsinfo[ass].startyear = 2008;
		assetsinfo[ass].starthour = 7;
		assetsinfo[ass].endhour = 19;
		/* SG30_SGD */ ass = 9;
		assetsinfo[ass].asset = "SG30_SGD";
		assetsinfo[ass].startyear = 2006;
		assetsinfo[ass].starthour = 0;
		assetsinfo[ass].endhour = 20;
		/* TWIX_USD */ ass = 10;
		assetsinfo[ass].asset = "TWIX_USD";
		assetsinfo[ass].startyear = 2012;
		assetsinfo[ass].starthour = 0;
		assetsinfo[ass].endhour = 20;
		/* UK100_GBP */ ass = 11;
		assetsinfo[ass].asset = "UK100_GBP";
		assetsinfo[ass].startyear = 2006;
		assetsinfo[ass].starthour = 0;
		assetsinfo[ass].endhour = 20;
		/* NAS100_USD */ ass = 12;
		assetsinfo[ass].asset = "NAS100_USD";
		assetsinfo[ass].startyear = 2006;
		assetsinfo[ass].starthour = 0;
		assetsinfo[ass].endhour = 20;
		/* US2000_USD */ ass = 13;
		assetsinfo[ass].asset = "US2000_USD";
		assetsinfo[ass].startyear = 2006;
		assetsinfo[ass].starthour = 0;
		assetsinfo[ass].endhour = 20;
		/* SPX500_USD */ ass = 14;
		assetsinfo[ass].asset = "SPX500_USD";
		assetsinfo[ass].startyear = 2006;
		assetsinfo[ass].starthour = 0;
		assetsinfo[ass].endhour = 20;
		/* US30_USD */ ass = 15;
		assetsinfo[ass].asset = "US30_USD";
		assetsinfo[ass].startyear = 2006;
		assetsinfo[ass].starthour = 0;
		assetsinfo[ass].endhour = 20;
	}

    void init_AssetsCombinations(){
		ALGOS = nAlgos(ASSETS,ASSETSPERALGO);
        pyStart("",1); 
		pySet("ass",ASSETS); 
		pySet("apa",ASSETSPERALGO);
        pyX("from itertools import combinations\n");
		pyX("def rSubset(arr, r):\n
				return list(combinations(arr, r))\n");
		pyX("PyIdx = rSubset(range(ass),apa)\n");
		pyX("for i in range(len(PyIdx)):\n
				PyIdx[i] = list(PyIdx[i])\n");
        int i, j; var Idx[ASSETSPERALGO];
        for( alg = 0; alg < ALGOS; alg++ ){
            pySet("i",alg);
            pyX("ret = PyIdx[i]\n");
            pyVec("ret",Idx,ASSETSPERALGO);       
            for( apa = 0; apa < ASSETSPERALGO; apa++ ){
                algosinfo[alg].asset[apa] = Assets[Idx[apa]];
            }
        }
    }

    void init_algosinfo(){
		init_AssetsCombinations();
        for( alg = 0; alg < ALGOS; alg++ ){
            char id[5];
            itoa((alg+1),id);
            char algoid[6];
            strcpy(algoid,"X");
            strcat(algoid,id);
            strcpy(algosinfo[alg].algo,algoid);
			int startyear = 0, starthour = 0, endhour = 24;
			for( apa = 0; apa < ASSETSPERALGO; apa++ ){			
				for( ass = 0; ass < ASSETS; ass++ ){
					if( strstr(assetsinfo[ass].asset,algosinfo[alg].asset[apa]) ){
						startyear = max(startyear,assetsinfo[ass].startyear);
						starthour = max(starthour,assetsinfo[ass].starthour);
						endhour = min(endhour,assetsinfo[ass].endhour);
					}
				}
			}
        }
    }

    void print_assetsinfo(){
		printf("\n### assetsinfo ###");
		printf("\n");
        for( ass = 0; ass < ASSETS; ass++ ){
            printf("\nass= %d, .asset= %s, .startyear= %d, .starthour= %d, .endhour= %d", ass, assetsinfo[ass].asset, assetsinfo[ass].startyear, assetsinfo[ass].starthour, assetsinfo[ass].endhour);
        }
        printf("\n");
    }

    void print_algosinfo(){
        printf("\n### algoinfos ###");
		printf("\n");
        for( alg = 0; alg < ALGOS; alg++ ){
            printf("\n.algo= %s, .asset[%d]= %s, .startyear= %d, .starthour= %d, .endhour= %d", algosinfo[alg].algo, 0, algosinfo[alg].asset[0],  algosinfo[alg].startyear, algosinfo[alg].starthour, algosinfo[alg].endhour);
			for( apa = 1; apa < ASSETSPERALGO; apa++ ){
				printf("\n                      .asset[%d]= %s", apa, algosinfo[alg].asset[apa]);
			}
			printf("\n");
        }
        printf("\n");
    }

void main(){

	assetList("OandaEuropeIndex");

	init_assetsinfo();

	print_assetsinfo();

    init_algosinfo();

	print_algosinfo();

	//printf("\n%s",algosinfo[0].asset[0]);


	//initalgosinfo();

	//printalgosinfo();

}