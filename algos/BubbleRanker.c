// Dual Momentum V1.0 trading, implementation by Hredot ///////////////////
// Disclaimer: Use at your own risk!                    ///////////////////
// You alone are responsible for your gains or losses.  ///////////////////

#include <nexow.h>

// Let's have space for up to 100 assets, just in case
#define NUMBEROFASSETS  1000

var assetWeight[NUMBEROFASSETS];// Will hold the index and performance stat of up to 1000 assets
int assetSorted[NUMBEROFASSETS];// Will hold the index of assetWeight sorted in decreasing order of performance
var myAssetType[NUMBEROFASSETS];// Stores information whether asset in assetWeight is stock =1 or bond =0
vars Price[NUMBEROFASSETS];     // Price history for each asset
int assetNum;             // Will contain the actual number of assets
int assetPlusNum;         // Will contain the actual number of assets with positive return

function bubbleSort(){    // sorts assetSorted to contain assetWeight indices in decreasing weight order
  int i,s,tmp;
  s=assetNum-1;
  while(s>0){
    for(i=0;i<s;i++){
      if(assetWeight[assetSorted[i]]*pow(100,myAssetType[assetSorted[i]]) <
         assetWeight[assetSorted[i+1]]*pow(100,myAssetType[assetSorted[i+1]])){
        // stocks weigh "100 times" more while sorting, since they grow better than bonds
        tmp=assetSorted[i];
        assetSorted[i]=assetSorted[i+1];
        assetSorted[i+1]=tmp;
      }
    }
    s--;
  }
}

function run()
{
	

    set(PLOTNOW+PRELOAD);
    BarPeriod = 1440; // 1 day bars
    LookBack = 24*20; // two years lookback period, just in case
    StartDate = 2010;
    Capital = slider(1, 5000, 0, 7000, "Capital", "How much money you start trading with.");
    int myLookBack = 12;   // 12 month lookback
    int myDaysUpdate = 15; // after how many days to update trades

    if(is(INITRUN)) {
      assetList("History\\AssetsSP250.csv"); // load asset list
      //  assetList("OandaEuropeFX45");
    }

      // Implement absolute momentum:
      // portfolio loop to determine performance of each asset
    assetNum=0;assetPlusNum=0;
    while(loop(Assets))
    {
      asset(Loop1);
      assetHistory(Loop1, FROM_GOOGLE);
      Price[assetNum]=series(price());
      myAssetType[assetNum] = 1-AssetVar[0];
      //Baltas and Kosowski (2012): linear regression is the best momentum indicator
      assetWeight[assetNum]=LinearRegSlope(Price[assetNum],myLookBack*20)/Moment(Price[assetNum],myLookBack*20,1);
      if(assetWeight[assetNum]>0){ assetPlusNum++; } // count up a wanted asset
      assetSorted[assetNum]=assetNum;
      assetNum++;
    }

      // Implement relative momentum:
      // sort AssetSorted to contain assetWeight indices in decreasing weight order
    bubbleSort();

    static int dayspast=0;dayspast++;    // increment days count until trade adjustment
    int i,enterNum=min((assetNum)/2,assetPlusNum); //Participate in at most 1/2 of winning assets
    if(dayspast>myDaysUpdate){            // update trades only once a time period myDaysUpdate
      for(i=enterNum;i<assetNum;i++){   // exit unwanted assets
        asset(Assets[assetSorted[i]]);
        exitLong();
      }
      var totalSlope=0;
      for(i=0;i<enterNum;i++){  // determine the overall weight of wanted assets
        totalSlope=totalSlope+assetWeight[assetSorted[i]];
      }
      for(i=0;i<enterNum;i++){  // enter wanted assets, each at the appropriate weight
        asset(Assets[assetSorted[i]]);
        Stop=3*ATR(24*20);
    // Note: The following is optimized for 2x leveraging!
        Lots=(Capital+WinTotal-LossTotal)*Leverage/(4*enterNum*price()*LotAmount);
    // drawdowns with this strategy are miniscule, therefore we reinvest all
    // use Capital*sqrt(1 + (WinTotal-LossTotal)/Capital) instead of (Capital+WinTotal-LossTotal) if you feel unsafe
        if(NumOpenLong < 3 && (Equity - MarginVal)/(Capital+WinTotal-LossTotal) >0.33 ) enterLong();
      }
      dayspast=0; // reset the day counter after the trades
    }asset(Assets[0]);

      //Plot results:
    PlotWidth = 600;
    PlotHeight1 = 300;  PlotHeight2 = 300;
    plot("$ Balance",Balance,NEW,BLUE);
    plot("Equity",Equity,0,GREEN);
    plot("BalanceInTrades",MarginVal,0,RED);

    }