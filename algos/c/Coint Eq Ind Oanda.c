
//////////////////////////////////////// \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
///                                                                           \\\
///  ### Long-Short Cointegration Strategy -> OandaEurope Equity Indices ###  \\\
///                                                                           \\\
/// 		Copyright © 2019 Nexow Systems, S.L. All rights reserved.         \\\
//////////////////////////////////////// \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

#include <nexow.h>

/* Select Universe */

	#define ASSETLIST "OandaEuropeIndex"
	#define ASSETS 16
	#define ASSETSPERALGO 2
	#define ALGOS 120  // ALGOS = (ASSETS*(ASSETS-1))/ASSETPERALGO except: if ( ASSETS == ASSETSPERALGO ) then ALGOS = 1;


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
	assetinfo assetinfos[ASSETS];

	typedef struct{
		string algo;
		char asset[10][ASSETSPERALGO];
		int startyear;
		int starthour;
		int endhour;
	} algoinfo;
	algoinfo algoinfos[ALGOS];

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
	algostat algostats[ALGOS];

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
	algostrategy algos[ALGOS];


/* Init Fuctions */

	int ass = 0;
	void initAssetInfos(){	
		while(loop(asset(Assets))){
			assetinfos[ass].asset = Asset;
		}
		/* AU200_AUD */
		assetinfos[ass].asset = strf("%c%c%c%c%c%c%c%c%c");
		strcpy(assetinfos[ass].asset,"AU200_AUD");
		//assetinfos[ass].asset = "AU200_AUD";
		assetinfos[ass].startyear = 2006;
		assetinfos[ass].starthour = 0;
		assetinfos[ass].endhour = 16;
		/* CN50_USD */ ass = 1;
		assetinfos[ass].asset = strf("%c%c%c%c%c%c%c%c%c");
		strcpy(assetinfos[ass].asset,"CN50_USD");
		//assetinfos[ass].asset = "CN50_USD";
		assetinfos[ass].startyear = 2012;
		assetinfos[ass].starthour = 1;
		assetinfos[ass].endhour = 17;
		/* EU50_EUR */ ass = 2;
		assetinfos[ass].asset = strf("%c%c%c%c%c%c%c%c%c");
		strcpy(assetinfos[ass].asset,"EU50_EUR");
		//assetinfos[ass].asset = "EU50_EUR";
		assetinfos[ass].startyear = 2006;
		assetinfos[ass].starthour = 6;
		assetinfos[ass].endhour = 20;
		/* FR40_EUR */ ass = 3;
		assetinfos[ass].asset = strf("%c%c%c%c%c%c%c%c%c");
		strcpy(assetinfos[ass].asset,"FR40_EUR");
		//assetinfos[ass].asset = "FR40_EUR";
		assetinfos[ass].startyear = 2006;
		assetinfos[ass].starthour = 7;
		assetinfos[ass].endhour = 20;
		/* DE30_EUR */ ass = 4;
		assetinfos[ass].asset = strf("%c%c%c%c%c%c%c%c%c");
		strcpy(assetinfos[ass].asset,"DE30_EUR");
		//assetinfos[ass].asset = "DE30_EUR";
		assetinfos[ass].startyear = 2006;
		assetinfos[ass].starthour = 6;
		assetinfos[ass].endhour = 20;
		/* HK33_HKD */ ass = 5;
		assetinfos[ass].asset = strf("%c%c%c%c%c%c%c%c%c");
		strcpy(assetinfos[ass].asset,"HK33_HKD");
		//assetinfos[ass].asset = "HK33_HKD";
		assetinfos[ass].startyear = 2006;
		assetinfos[ass].starthour = 1;
		assetinfos[ass].endhour = 17;
		/* IN50_USD */ ass = 6;
		assetinfos[ass].asset = strf("%c%c%c%c%c%c%c%c%c");
		strcpy(assetinfos[ass].asset,"IN50_USD");
		//assetinfos[ass].asset = "IN50_USD";
		assetinfos[ass].startyear = 2012;
		assetinfos[ass].starthour = 2;
		assetinfos[ass].endhour = 20;
		/* JP225_USD */ ass = 7;
		assetinfos[ass].asset = "JP225_USD";
		assetinfos[ass].startyear = 2006;
		assetinfos[ass].starthour = 0;
		assetinfos[ass].endhour = 20;
		/* NL25_EUR */ ass = 8;
		assetinfos[ass].asset = "NL25_EUR";
		assetinfos[ass].startyear = 2008;
		assetinfos[ass].starthour = 7;
		assetinfos[ass].endhour = 19;
		/* SG30_SGD */ ass = 9;
		assetinfos[ass].asset = "SG30_SGD";
		assetinfos[ass].startyear = 2006;
		assetinfos[ass].starthour = 0;
		assetinfos[ass].endhour = 20;
		/* TWIX_USD */ ass = 10;
		assetinfos[ass].asset = "TWIX_USD";
		assetinfos[ass].startyear = 2012;
		assetinfos[ass].starthour = 0;
		assetinfos[ass].endhour = 20;
		/* UK100_GBP */ ass = 11;
		assetinfos[ass].asset = "UK100_GBP";
		assetinfos[ass].startyear = 2006;
		assetinfos[ass].starthour = 0;
		assetinfos[ass].endhour = 20;
		/* NAS100_USD */ ass = 12;
		assetinfos[ass].asset = "NAS100_USD";
		assetinfos[ass].startyear = 2006;
		assetinfos[ass].starthour = 0;
		assetinfos[ass].endhour = 20;
		/* US2000_USD */ ass = 13;
		assetinfos[ass].asset = "US2000_USD";
		assetinfos[ass].startyear = 2006;
		assetinfos[ass].starthour = 0;
		assetinfos[ass].endhour = 20;
		/* SPX500_USD */ ass = 14;
		assetinfos[ass].asset = "SPX500_USD";
		assetinfos[ass].startyear = 2006;
		assetinfos[ass].starthour = 0;
		assetinfos[ass].endhour = 20;
		/* US30_USD */ ass = 15;
		assetinfos[ass].asset = "US30_USD";
		assetinfos[ass].startyear = 2006;
		assetinfos[ass].starthour = 0;
		assetinfos[ass].endhour = 20;
	}

	int alg = 0;
	int apa = 0;

	int k;
	void Recursive(int i, int j, string* arr){
		int ii;
		for ( ii = i; ii < ASSETS-(ASSETSPERALGO-j); ii++)
		{
			//printf("\n %d ,%d, %s , %s ",ii,j,arr[0],arr[1]);
			if(j == ASSETSPERALGO){
				int jj;
				for( jj = 0; jj < ASSETSPERALGO-1; jj++)
				{
					algoinfos[k].asset[jj] = strf("%c%c%c%c%c%c%c%c%c%c");
					strcpy(algoinfos[k].asset[jj],arr[jj]);
				}
				algoinfos[k].asset[jj] = strf("%c%c%c%c%c%c%c%c%c%c");
				strcpy(algoinfos[k].asset[jj],assetinfos[ii].asset);
				//printf("\n %d ,%d, %s , %s ",ii,j,arr[0],arr[1]);
				k++;
			}
			else{
				string auxarr[ASSETSPERALGO];
				int kk;
				for(kk = 0;kk<j-1;kk++){
					//auxarr[kk] = strf("%c%c%c%c%c%c%c%c%c%c");
					strcpy(auxarr[kk],arr[kk]);  
				}
				auxarr[j-1] = strf("%c%c%c%c%c%c%c%c%c%c");
				strcpy(auxarr[j-1],assetinfos[ii].asset);  
				Recursive(ii+1,j+1,auxarr);
			} 
		}
	
	}

	void init( int ass, int apa ){
		
		


	}



/*

		for( ass = 0; ass < ASSETS; ass++ ){
			for( apa = 0; apa < ASSETSPERALGO; apa++ ){
				algoinfos[alg].asset[apa] = strf("%c%c%c%c%c%c%c%c%c%c");
				strcpy(algoinfos[alg].asset[apa],assetinfos[ass].asset);
				printf("\n%d %d %s",alg, apa, algoinfos[alg].asset[apa]);
				alg++;
				if( alg > ALGOS )
					alg = 0;
					
			}
		}
	}

	
*/

/*	






		int i;
		while(asset(loop(Assets))){
			if( !IsFX() ){
				for( i = 0; i < ASSETS-ass; i++ )
					algoinfos[alg+i].asset[0] = Symbol;
				alg = alg+i;
				ass++;
			}
		}
		alg = 0;
		for( i = 0; i < ASSETS; i++ ){
			ass = 0;
			while(asset(loop(Assets))){
				if( !IsFX() ){
					if( j > i ){
						algoinfos[alg].sym2 = Symbol;
						char id[4];
						itoa((alg+1),id);
						char algoname[5];
						strcpy(algoname,"");
						strcat(algoname,"X");
						strcat(algoname,id);
						algoinfos[k].algo = algoname;
						alg++;
					}
					ass++;
				}
			}
		}
		for( alg = 0; alg < ALGOS; alg++ ){
			int y1, s1, e1, y2, s2, e2;
			for( ass = 0; ass < ASSETSPERALGO; ass++ ){
				if( algoinfos[])
				algoinfos[alg].startyear = max(assetinfos[ass].year,algoinfos[alg].year);
				algoinfos[alg].starthour = max(assetinfos[ass].starthour,algoinfos[alg].starthour);
				algoinfos[alg].endhour = min(assetinfos[ass].endthour,algoinfos[alg].endhour);
			}
			
		}


	}

*/

/**/

void printAssetInfos(){
	int i; printf("\n### Asset Infos ###");
	for( i = 0; i < ASSETS; i++ ){
		printf("\ni= %d, .asset= %s, .startyear= %d, .starthour= %d, .endhour= %d", i, assetinfos[i].asset, assetinfos[i].startyear, assetinfos[i].starthour, assetinfos[i].endhour);
	}
	printf("\n");
}
void printAlgoInfos(){
	int i; printf("\n### Algo Infos ###");
	for( i = 0; i < ALGOS; i++ ){
		printf("\ni= %d, .sym1= %s, .sym2= %s", i, algoinfos[i].asset[0], algoinfos[i].asset[1]);
	}
	printf("\n");
}

void main(){
	assetList("OandaEuropeIndex");

	initAssetInfos();

	printAssetInfos();

	string auxarray[ASSETSPERALGO];

	Recursive(0,1,auxarray);

	printAlgoInfos();

	//printf("\n%s",algoinfos[0].asset[0]);


	//initAlgoInfos();

	//printAlgoInfos();

}