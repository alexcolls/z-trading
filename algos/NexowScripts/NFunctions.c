
// Nexow Functions //

//#include <candle.c>
#include <com.h>
#include <contract.c>
//#include <d3d9.h>
#include <default.c>
#include <dynamic.h>
//#include <func_list.h>
#include <functions.h>
#include <litec.h>
#include <opengl.h>
#include <profile.c>
#include <r.h>
#include <stdio.h>
//#include <String.h>
#include <trading.h>
#include <variables.h>
#include <windows.h>
//#include <zorro.h>
//#include <indicators.c>


// Currency Base and Term //

	char* Base()
	{
		char* Base = "";
		memcpy(Base,Symbol,3);
		return Base;
	}

	char* Term()
	{
		char* Term = "";
		strcpy(Term,Symbol+4);
		return Term;
	}

//

// PipValue in USD of the current FX Pair //

	double PipValue_USD()
	{
		char* AccCcy = "USD";
		double PipValue = 0;
		if(strstr(Term(),AccCcy))
		{
			PipValue = PIP * LotAmount;
		}
		else if(strstr(Base(),AccCcy))
		{
			PipValue = PIP * LotAmount / priceClose(0);
		}
		else
		{
			char* Term = Term();            
			if( strstr(Term,"AUD") || strstr(Term,"EUR") || strstr(Term,"GBP") || strstr(Term,"NZD") || strstr(Term,"XAU") || strstr(Term,"XAG") )
			{
				char* CurrSym = Symbol;
				char Sym[8];
				strcpy(Sym,Term);
				strcat(Sym,"/");
				strcat(Sym,AccCcy);
				asset(Sym);
				double Price = priceClose(0);
                asset(CurrSym);
				PipValue = PIP * LotAmount * Price;
			}   
			else if( strstr(Term,"CAD") || strstr(Term,"CHF") || strstr(Term,"HKD") || strstr(Term,"JPY") || strstr(Term,"SGD") )
			{
				char* CurrSym = Symbol;
				char Sym[8];
				strcpy(Sym,AccCcy);
				strcat(Sym,"/");
				strcat(Sym,Term);
				asset(Sym);
				double Price = priceClose(0);
                asset(CurrSym);
				PipValue = PIP * LotAmount / Price;
			}
		}
		return PipValue;
	}

//

// PipValue in EUR of the current FX Pair //

	double PipValue_EUR()
	{
		char* AccCcy = "EUR";
		double PipValue = 0;
		if(strstr(Term(),AccCcy))
		{
			PipValue = PIP * LotAmount;
		}
		else if(strstr(Base(),AccCcy))
		{
			PipValue = PIP * LotAmount / priceClose(0);
		}
		else
		{
			char* Term = Term();            
            if( strstr(Term,"XAU") || strstr(Term,"XAG") )
            {
                char* CurrSym = Symbol;
                char Sym[8];
				strcpy(Sym,Term);
				strcat(Sym,"/");
				strcat(Sym,AccCcy);
				asset(Sym);
				double Price = priceClose(0);
                asset(CurrSym);
				PipValue = PIP * LotAmount * Price;
            }   
            else if( strstr(Term,"AUD") || strstr(Term,"CAD") || strstr(Term,"CHF") || strstr(Term,"GBP") || strstr(Term,"HKD") || 
					 strstr(Term,"JPY") || strstr(Term,"NZD") || strstr(Term,"SGD") || strstr(Term,"USD") )
            {
                char* CurrSym = Symbol;
                char Sym[8];
                strcpy(Sym,AccCcy);
                strcat(Sym,"/");
                strcat(Sym,Term);
                asset(Sym);
                double Price = priceClose(0);
                asset(CurrSym);
				PipValue = PIP * LotAmount / Price;
            }
		}
		return PipValue;
	}

//


// Allocation percentage of Symbol in the Portfolio of Assets //

	#define MAXASSETS 66
	#define MAXBARS 10

	typedef struct{
		char* Name;
		double Correl;
		double Sharpe;
	} cdd;

	typedef struct{
		char* Name;
		double Alloc;
	} cd;

	cd Allocs[MAXASSETS];

	void setAllocation(int nAssets, int nBars){

		int i, j, k;
		
		// Portfolio Returns

			double PortReturns[MAXBARS];
			for(i = 0; i < nBars; i++){
				j = 0;
				while(asset(loop(Assets))){
					j++;   
					PortReturns[i] += ( ( (log(price(i))-log(price(i+1)))*100 ) / j );
				}
			}

		// Portfolio Allocation per Symbol

			cdd Correls[MAXASSETS];
			double Returns[MAXBARS];
			double Sharpe;
			while(asset(loop(Assets))){
				for(i = 0; i < nBars; i++){
					Returns[i] = (log(price(i))-log(price(i+1)))*100;
				}
				double Mean = SMA(Returns,BARS);
				double StDv = StdDev(Returns,BARS);
				if( StDv == 0 )
					Sharpe = 1;
				else
					Sharpe = ( Mean / StDv );
				double Correl = 1-Correlation(Returns,PortReturns,BARS);
				Correls[k].Name = Symbol;
				Correls[k].Correl = Correl;
				Correls[k].Sharpe = Sharpe;
				k++;
			}

			double SumCorrels;
			for(k = 0; k < nAssets; k++){
				SumCorrels += abs(Correls[k].Correl);
			}
			
			k = 0;
			while(asset(loop(Assets))){
				double Percent;
				if(strcmp(Symbol,Correls[k].Name) == 0){
					Percent = (Correls[k].Correl/SumCorrels)*100;
				}
				Allocs[k].Name = Symbol;
				Allocs[k].Alloc = Percent * Correls[k].Sharpe;
				k++;
			}

		//    

	}

	// Query of Allocation per Symbol
		
		int k;
		double Allocation(char* Name, int nAssets){
			for(k = 0; k < nAssets; k++){
				if(strcmp(Name,Allocs[k].Name) == 0){
					return Allocs[k].Alloc;
				}
			}
		}

	//

//