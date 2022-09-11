
#include <nexow.h>

typedef struct{
    char sym[10];
	var val;
} info;

info idx[10];

void run(){

    set(PLOTNOW);
	assetList("OandaEuropeALL.csv");
    StartDate = 2006;
    BarPeriod = 1440;

    asset("AU200_AUD");

    //printf("\n%s",AssetStr[0]);

    printf("\n%d",AssetVal);




}