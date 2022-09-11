

#include <NexowFunctions.h>


double COT_DEv;
double COT_DE( char* Code, bool OnlyFutures ){
    static double COT;
    const char* COT_Format = "%Y-%m-%d,f1,f2,f3,f4,f5,f6,f7,f8,f9,f10,f11,f12,f13,f14,f15,f16,f17";
    const char* COT_Code;
    if( OnlyFutures )
	    COT_Code = strf("CFTC/%s_F_ALL",Code);
    else
        COT_Code = strf("CFTC/%s_FO_ALL",Code);
    double Longs = dataFromQuandl(1000,COT_Format,COT_Code,2);
    double Shorts = dataFromQuandl(1000,COT_Format,COT_Code,3);
    if( dow() == 5 )
        COT_DEv = Longs-Shorts;
    return COT_DEv;
}

void run(){

    set(PLOTNOW);
    assetList("AssetsFix");
    StartDate = 2007;
    BarPeriod = 60;
    LookBack = 200;

    asset("EUR/USD");

    double DE_L = dataFromQuandl(1,"%Y-%m-%d,f1,f2,f3,f4,f5,f6,f7,f8,f9,f10,f11,f12,f13,f14,f15,f16,f17","CFTC/099741_F_ALL",2);
    double DE_S = dataFromQuandl(1,"%Y-%m-%d,f1,f2,f3,f4,f5,f6,f7,f8,f9,f10,f11,f12,f13,f14,f15,f16,f17","CFTC/099741_F_ALL",3);
    double AM_L = dataFromQuandl(1,"%Y-%m-%d,f1,f2,f3,f4,f5,f6,f7,f8,f9,f10,f11,f12,f13,f14,f15,f16,f17","CFTC/099741_F_ALL",5);
    double AM_S = dataFromQuandl(1,"%Y-%m-%d,f1,f2,f3,f4,f5,f6,f7,f8,f9,f10,f11,f12,f13,f14,f15,f16,f17","CFTC/099741_F_ALL",6);
    double LF_L = dataFromQuandl(1,"%Y-%m-%d,f1,f2,f3,f4,f5,f6,f7,f8,f9,f10,f11,f12,f13,f14,f15,f16,f17","CFTC/099741_F_ALL",8);
    double LF_S = dataFromQuandl(1,"%Y-%m-%d,f1,f2,f3,f4,f5,f6,f7,f8,f9,f10,f11,f12,f13,f14,f15,f16,f17","CFTC/099741_F_ALL",9);

    double DEf = COT_DE("099741",TRUE);

    plot("DE",DE_L-DE_S,1,BLUE);
    plot("DEf",DEf,0,GREEN);
    plot("Z",0,0,BLACK);
  

}