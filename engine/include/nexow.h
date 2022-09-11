
/////////////// Nexow Functions 2019 ///////////////


// Include Paths //

	#include <stdio.h>
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
	//#include <String.h>
	#include <trading.h>
	#include <variables.h>
	#include <windows.h>
	//#include <zorro.h>
	//#include <indicators.c>
	//#include <stdlib.h>
	//#include <iostream>


//////////////////////

// Perefined Structs //

	typedef struct{
    char* Sym;
    double Val;
	} symval;

	typedef struct{
    char* Sym;
    double Val1;
	double Val2;
	} symval2;

	typedef struct{
    char* Sym1;
    char* Sym2;
	double Val;
	} sym2val;

	typedef struct{
    char* Sym;
    double Vals[1000];
	} symvals;

	typedef struct{
    char Pair[8];
    double Val;
	} pairval;

	typedef struct{
    char Ccy1[4];
    char Ccy2[4];
	double Val;
	} ccyccyval;

	typedef struct{
    char Ccy[4];
    double Val;
	int n;
	} ccyval;

	typedef struct{
    char Ccy[4];
    double Val[1000];
	} ccyvals;

//////////////////////

// OKTest //

	void OK(){
		printf("\n%s","OK");
	}

//////////////////////

// No Fees //

	void fees(){
		Spread = Commission = RollLong = RollShort = Interest = 0;
	}

//////////////////////

// Recursive Function Factorial //

	var factorial( var x ){
		if (x <= 1)
			return 1;
		return x * factorial(x - 1);
	}

//////////////////////

// Recursive Function Factorial //

	var nAlgos( var assets, var assetsperalgo ){ 
		var num = factorial(assets);
		var den = factorial(assets-assetsperalgo) * factorial(assetsperalgo);
		return num/den;
	}

//////////////////////

// Implementation of itoa() //

	void reverse(string s){
		int i, j;
		char c;
		for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
		{
			c = s[i];
			s[i] = s[j];
			s[j] = c;
		}
	}

	void itoa(int n, string s){
		int i, sign;

		if ((sign = n) < 0) /* record sign */
			n = -n;			/* make n positive */
		i = 0;
		do
		{						   /* generate digits in reverse order */
			s[i++] = n % 10 + '0'; /* get next digit */
		} while ((n /= 10) > 0);   /* delete it */
		if (sign < 0)
			s[i++] = '-';
		s[i] = '\0';
		reverse(s);
	}

//////////////////////

// Sort symval array by .Val descending //

	void sortsymval(int n, symval* arr){
		int i, j;
		symval temp[1];
		for(i = 0; i < n-1; i++){  
			for(j = 0; j < n-i-1; j++){  
				if(arr[j].Val < arr[j+1].Val){
					temp[0].Sym = arr[j].Sym;
					temp[0].Val = arr[j].Val;
					arr[j].Sym = arr[j+1].Sym;
					arr[j].Val = arr[j+1].Val;
					arr[j+1].Sym = temp[0].Sym;
					arr[j+1].Val = temp[0].Val;
				}
			}
		}
	}

	void sortsymval2(int n, symval2* arr){
		int i, j;
		symval2 temp[1];
		for(i = 0; i < n-1; i++){  
			for(j = 0; j < n-i-1; j++){  
				if(arr[j].Val1 < arr[j+1].Val1){
					temp[0].Sym = arr[j].Sym;
					temp[0].Val1 = arr[j].Val1;
					temp[0].Val2 = arr[j].Val2;
					arr[j].Sym = arr[j+1].Sym;
					arr[j].Val1 = arr[j+1].Val1;
					arr[j].Val2 = arr[j+1].Val2;
					arr[j+1].Sym = temp[0].Sym;
					arr[j+1].Val1 = temp[0].Val1;
					arr[j+1].Val2 = temp[0].Val2;
				}
			}
		}
	}

	void sortpairval(int n, pairval* PairValtoSort){
		int i, j;
		pairval temp[1];
		for(i = 0; i < n-1; i++){  
			for(j = 0; j < n-i-1; j++){  
				if(PairValtoSort[j].Val < PairValtoSort[j+1].Val){
					strcpy(temp[0].Pair,PairValtoSort[j].Pair);
					temp[0].Val = PairValtoSort[j].Val;
					strcpy(PairValtoSort[j].Pair,PairValtoSort[j+1].Pair);
					PairValtoSort[j].Val = PairValtoSort[j+1].Val;
					strcpy(PairValtoSort[j+1].Pair,temp[0].Pair);
					PairValtoSort[j+1].Val = temp[0].Val;
				}
			}
		}
	}

//////////////////////

// Add element to a double list chronologically ordered //

	void addtoList( double *List, int Length, double ElementtoAdd ){
		int i;
		for (i = 0; i < Length; i++){
			List[Length - i] = List[Length - i - 1];
		}
		List[0] = ElementtoAdd;
	}

	void AddToDoublesList(double* List, int Length, double ElementtoAdd ){
		int i;
		for( i = 0; i < Length; i++ ){
			List[Length-i] = List[Length-i-1];
		}
		List[0] = ElementtoAdd;
    }

//////////////////////

// Reset String Array //

	void resstrarr( string *array ){
		int i = 0;
		while( TRUE ){
			if( array[i] == NULL )
				break;
			memset(array[i], 0, sizeof(array[i]));
			array[i] = '\0';
			i++;       
		}
	}

//////////////////////

// Reset String Array //

	void resintarr( int *array ){
		int i = 0;
		while( TRUE ){
			if( array[i] == NULL )
				break;
			array[i] = -1;
			i++;       
		}
	}

//////////////////////

// Append String to an Array //

	void appstr( string *array, string str ){
		int i = 0;
		while( TRUE ){
			if( array[i] == NULL )
				break;
			i++;       
		}
		array[i] = strf("%c%c%c%c%c%c%c%c%c%c");
		strcpy(array[i], str);
	}

//////////////////////


// Append Int to an Array //

	void appint( int *array, int n ){
		int i = 0;
		while( TRUE ){
			if( array[i] == -1 )
				break;
			i++;       
		}
		array[i] = n;
	}

//////////////////////

// Append 2 String Arrays //

	void appstrarr( string *destarray, string *arraytoappend ){
		int i = 0;
		while( TRUE ){
			if( destarray[i] == -1 )
				break;
			i++;       
		}
		int ii = 0;
		while( TRUE ){
			if( arraytoappend[ii] == -1 )
				break;
			ii++;       
		}
		int j = 0, jj = 0;
		for( j = i; j < ii; j++){
			destarray[j] = strf("%c%c%c%c%c%c%c%c%c%c");
			strcpy(destarray[j],arraytoappend[jj]);
			jj++;
		} 
	}

//////////////////////

// Append 2 Int Arrays //

	void appintarr( int *destarray, int *arraytoappend ){
		int i = 0;
		while( TRUE ){
			if( destarray[i] == NULL )
				break;
			i++;       
		}
		int ii = 0;
		while( TRUE ){
			if( arraytoappend[ii] == NULL )
				break;
			ii++;       
		}
		int j = 0, jj = 0;
		for( j = i; j < ii; j++){
			destarray[j] = arraytoappend[jj];
			jj++;
		}
	}

//////////////////////

// Print String Array //

	void printstrarr( string *array, int startidx, int endidx ){
		printf("\n");
		int i = startidx;
		for( i = 0; i < endidx; i++ ){
			if( array[i] == NULL )
				break;
			printf("\n%s",array[i]);
		}
		printf("\n");
	}

//////////////////////

// Print Int Array //

	void printintarr( int *array, int startidx, int endidx ){
		printf("\n");
		int i = startidx;
		for( i = 0; i < endidx; i++ ){
			if( array[i] == NULL )
				break;
			printf("\n%d",array[i]);
		}
		printf("\n");
	}

//////////////////////

// CET Schedule //

	int gmtCET(){
		if( week() > 12 && week() < 44 ){
			return 2;
		}
		else if( week() <= 12 || week() >= 44 ){
			return 1;
		}
	}

//////////////////////

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

//////////////////////

// Check if the current asset is FX //

	bool IsFX()
	{
		char* Base = Base();
		if( strstr(Base,"AUD") || strstr(Base,"CAD") || strstr(Base,"CHF") || strstr(Base,"EUR") || strstr(Base,"GBP") || strstr(Base,"HKD") || 
			strstr(Base,"JPY") || strstr(Base,"NZD") || strstr(Base,"SGD") || strstr(Base,"USD") || strstr(Base,"XAG") || strstr(Base,"XAU") ){
			return TRUE;
		}
		else return FALSE;
	}

//////////////////////

// Portfolio Symbols List //

	string SymbolsList[100];
	bool SymbolsListActivated;
	int NumberOfSymbols;
	void SetSymbolsList(){
		if( !SymbolsListActivated ){
			char* CurrSym = Symbol;
			int i;
			while(asset(loop(Assets))){
				SymbolsList[i] = Symbol;
				NumberOfSymbols++;
				i++;
			}
			asset(CurrSym);
			SymbolsListActivated = TRUE;
		}
	}

//////////////////////

// Is the Symbol Name Correct? //

	bool IsSymbolCorrect( string SymbolName ){
		SetSymbolsList();
		int i;
		for(i = 0; i < NumberOfSymbols; i++){
			if( strstr(SymbolsList[i],SymbolName) ){
				return TRUE;
			}
		}
		return FALSE;
	}

//////////////////////

// G8 FX Currency Index Prices //

	double EURIdx8(){
		char* CurrSym = Symbol;
		double Ret;
		asset("EUR/AUD");
		Ret += 1/price(0);
		asset("EUR/CAD");
		Ret += 1/price(0);
		asset("EUR/CHF");
		Ret += 1/price(0);
		asset("EUR/GBP");
		Ret += 1/price(0);
		asset("EUR/JPY");
		Ret += 1/price(0);
		asset("EUR/NZD");
		Ret += 1/price(0);
		asset("EUR/USD");
		Ret += 1/price(0);
		asset(CurrSym);
		return 1/((Ret+1)/8);
	}

	double USDIdx8(){
		char* CurrSym = Symbol;
		double Ret;
		asset("AUD/USD");
		Ret += price(0);
		asset("USD/CAD");
		Ret += 1/price(0);
		asset("USD/CHF");
		Ret += 1/price(0);
		asset("EUR/USD");
		Ret += price(0);
		asset("GBP/USD");
		Ret += price(0);
		asset("USD/JPY");
		Ret += 1/price(0);
		asset("NZD/USD");
		Ret += price(0);
		asset(CurrSym);
		return 1/((Ret+1)/8);
	}

	double EURIdx8r(){
		char* CurrSym = Symbol;
		double Ret;
		asset("EUR/AUD");
		Ret += (priceClose(0)/priceOpen(0)-1)*100;
		asset("EUR/CAD");
		Ret += (priceClose(0)/priceOpen(0)-1)*100;
		asset("EUR/CHF");
		Ret += (priceClose(0)/priceOpen(0)-1)*100;
		asset("EUR/GBP");
		Ret += (priceClose(0)/priceOpen(0)-1)*100;
		asset("EUR/JPY");
		Ret += (priceClose(0)/priceOpen(0)-1)*100;
		asset("EUR/NZD");
		Ret += (priceClose(0)/priceOpen(0)-1)*100;
		asset("EUR/USD");
		Ret += (priceClose(0)/priceOpen(0)-1)*100;
		asset(CurrSym);
		return Ret/8;
	}

	double USDIdx8r(){
		char* CurrSym = Symbol;
		double Ret;
		asset("AUD/USD");
		Ret -= (priceClose(0)/priceOpen(0)-1)*100;
		asset("USD/CAD");
		Ret += (priceClose(0)/priceOpen(0)-1)*100;
		asset("USD/CHF");
		Ret += (priceClose(0)/priceOpen(0)-1)*100;
		asset("EUR/USD");
		Ret -= (priceClose(0)/priceOpen(0)-1)*100;
		asset("GBP/USD");
		Ret -= (priceClose(0)/priceOpen(0)-1)*100;
		asset("USD/JPY");
		Ret += (priceClose(0)/priceOpen(0)-1)*100;
		asset("NZD/USD");
		Ret -= (priceClose(0)/priceOpen(0)-1)*100;
		asset(CurrSym);
		return Ret/8;
	}

	


//////////////////////

// CcyIdx - Currency Index //

	#define MAXCCY 32

	ccyval Ccy[MAXCCY];
	ccyvals Ccy_Vals[MAXCCY];
	int Ccy_n;
	void Ccy_Set( double Value ){
		if( IsFX() ){
            char* Base = Base();
			char* Term = Term();
			int i;
			for(i = 0; i < Ccy_n+1; i++){
                if( Ccy[i].Ccy[0] == '\0' ){
                    strcpy(Ccy[i].Ccy,Base);
					Ccy[i].Val = Value;
					Ccy[i].n = 1;
                    Ccy_n++;
                    break;
                }
                else if( strstr(Ccy[i].Ccy,Base) ){
					double SumVal = Ccy[i].Val*(double)Ccy[i].n+Value;
					Ccy[i].n++;
                    Ccy[i].Val = SumVal/Ccy[i].n;
                    break;
                }
            }
            for(i = 0; i < Ccy_n+1; i++){
                if( Ccy[i].Ccy[0] == '\0' ){
                    strcpy(Ccy[i].Ccy,Term);
					Ccy[i].Val = -Value;
					Ccy[i].n = 1;
                    Ccy_n++;
                    break;
                }
                else if( strstr(Ccy[i].Ccy,Term) ){
					double SumVal = Ccy[i].Val*(double)Ccy[i].n-Value;
                    Ccy[i].n++;
                    Ccy[i].Val = SumVal/Ccy[i].n;
                    break;
                }
            }
		}
	}

	void Ccy_AddVals( int Periods ){
		if( is(FIRSTRUN) ){
			int i;
			for( i = 0; i < Ccy_n; i++ ){
				strcpy(Ccy_Vals[i].Ccy,Ccy[i].Ccy);
			}
		}
		int i, j;
		for( i = 0; i < Ccy_n; i++ ){
			for( j = 0; j < Periods; j++ ){
				Ccy_Vals[i].Val[Periods-j] = Ccy_Vals[i].Val[Periods-j-1];
			}
			Ccy_Vals[i].Val[0] = Ccy[i].Val;
		}
    }

	void Ccy_Reset(){
		int i;
		for(i = 0; i < Ccy_n; i++){
			memset(Ccy[i].Ccy,0,4);
			Ccy[i].Val = 0;
			Ccy[i].n = 0;
		}
		Ccy_n = 0;
	}

	void Ccy_Print(){
		int i;
		for(i = 0; i < Ccy_n; i++){
			printf("\ni= %d, Ccy= %s, Val= %f, n= %d", i, Ccy[i].Ccy, Ccy[i].Val, Ccy[i].n);
		}
		printf("\n");
	}

	void Ccy_Divide(){
		int i;
		for(i = 0; i < Ccy_n; i++){
			Ccy[i].Val = Ccy[i].Val/(double)Ccy[i].n;
		}
	}

	void Ccy_Multiple(){
		int i;
		for(i = 0; i < Ccy_n; i++){
			Ccy[i].Val = Ccy[i].Val*(double)Ccy[i].n;
		}
	}

	void Ccy_Sort( int Descending_0_Ascending_1 ){
		ccyval temp[1];
		int i, ii;
		if( Descending_0_Ascending_1 == 0 ){
			for(i = 0; i < Ccy_n-1; i++){
				for(ii = 0; ii < Ccy_n-i-1; ii++){  
					if(Ccy[ii].Val < Ccy[ii+1].Val){
						strcpy(temp[0].Ccy,Ccy[ii].Ccy);
						temp[0].Val = Ccy[ii].Val;
						temp[0].n = Ccy[ii].n;
						strcpy(Ccy[ii].Ccy,Ccy[ii+1].Ccy);
						Ccy[ii].Val = Ccy[ii+1].Val;
						Ccy[ii].n = Ccy[ii+1].n;
						strcpy(Ccy[ii+1].Ccy,temp[0].Ccy);
						Ccy[ii+1].Val = temp[0].Val;
						Ccy[ii+1].n = temp[0].n;
					}
				}
			}
		}
		else if( Descending_0_Ascending_1 == 1 ){
			for(i = 0; i < Ccy_n-1; i++){
				for(ii = 0; ii < Ccy_n-i-1; ii++){  
					if(Ccy[ii].Val > Ccy[ii+1].Val){
						strcpy(temp[0].Ccy,Ccy[ii].Ccy);
						temp[0].Val = Ccy[ii].Val;
						temp[0].n = Ccy[ii].n;
						strcpy(Ccy[ii].Ccy,Ccy[ii+1].Ccy);
						Ccy[ii].Val = Ccy[ii+1].Val;
						Ccy[ii].n = Ccy[ii+1].n;
						strcpy(Ccy[ii+1].Ccy,temp[0].Ccy);
						Ccy[ii+1].Val = temp[0].Val;
						Ccy[ii+1].n = temp[0].n;
					}
				}
			}
		}
	}

	char* Ccy_Best( int Top ){
		Ccy_Sort(0);
		return Ccy[Top-1].Ccy;
	}

	char* Ccy_Worst( int Top ){
		Ccy_Sort(1);
		return Ccy[Top-1].Ccy;
	}

	int Ccy_TopPair_Dir;
	char* Ccy_TopPair( int TopBest, int TopWorst ){
		char Base[4], Term[4];
		strcat(Base,Ccy_Best(TopBest));
		strcat(Term,Ccy_Worst(TopWorst));
		if( strstr(Base,Term) ){
			return 0;
		}
		char TopPair[8];
		strcpy(TopPair,Base);
		strcat(TopPair,"/");
		strcat(TopPair,Term);
		if( IsSymbolCorrect(TopPair) ){
			Ccy_TopPair_Dir = 1;
			return TopPair;
		}
		char TopPairInverse[8];
		strcpy(TopPairInverse,Term);
		strcat(TopPairInverse,"/");
		strcat(TopPairInverse,Base);
		Ccy_TopPair_Dir = -1;
		return TopPairInverse;
	}

	double Ccy_Val( char* Currency_or_Pair ){
		if( strlen(Currency_or_Pair) == 3 ){
			int i;
			for(i = 0; i < Ccy_n; i++){
				if( strstr(Ccy[i].Ccy,Currency_or_Pair) ){
					return Ccy[i].Val;
				}
			}
			return 9999999999;
		}
		else if( strlen(Currency_or_Pair) == 6 ){
			char Base[4], Term[4];
			memcpy(Base,Currency_or_Pair,3);
			strcpy(Term,Currency_or_Pair+4);
			double BaseVal, TermVal;
			int i;
			for(i = 0; i < Ccy_n; i++){
				if( strstr(Ccy[i].Ccy,Base) ){
					BaseVal = Ccy[i].Val;
					break;
				}
			}
			for(i = 0; i < Ccy_n; i++){
				if( strstr(Ccy[i].Ccy,Term) ){
					TermVal = Ccy[i].Val;
					break;
				}
			}
			return BaseVal-TermVal;
		}
		else return 9999999999;
	}

	int Ccy_nPairs( char* Currency ){
		if( strlen(Currency) == 3 ){
			int i;
			for(i = 0; i < Ccy_n; i++){
				if( strstr(Ccy[i].Ccy,Currency) ){
					return Ccy[i].n;
				}
			}
			return 9999999999;
		}
		else return 9999999999;
	}
	
	double Ccy_StdDev( int Abs ){
		double Val[MAXCCY];
		int i;
		if( Abs == 0 ){
			for(i = 0; i < Ccy_n; i++){
				Val[i] = Ccy[i].Val;
			}
		}
		else if( Abs == 1 ){
			for(i = 0; i < Ccy_n; i++){
				Val[i] = abs(Ccy[i].Val);
			}
		}
		return StdDev(Val,Ccy_n);
	}

	double Ccy_Avg( int Abs ){
		double Val[MAXCCY];
		int i;
		if( Abs == 0 ){
			for(i = 0; i < Ccy_n; i++){
				Val[i] = Ccy[i].Val;
			}
		}
		else if( Abs == 1 ){
			for(i = 0; i < Ccy_n; i++){
				Val[i] = abs(Ccy[i].Val);
			}
		}
		return SMA(Val,Ccy_n);
	}

//////////////////////

// Commitment of Traders - COT Quandl //

	double COT_OpIn( int Handle, char* Code, bool OnlyFutures ){
		const char* COT_Format = "%Y-%m-%d,f1,f2,f3,f4,f5,f6,f7,f8,f9,f10";
		const char* COT_Code;
		if( OnlyFutures )
			COT_Code = strf("CFTC/%s_F_L_ALL",Code);
		else COT_Code = strf("CFTC/%s_FO_L_ALL",Code);
		double OpIn = dataFromQuandl(Handle,COT_Format,COT_Code,1);
		return OpIn;
	}

	double COT_NonCom( int Handle, char* Code, bool OnlyFutures ){
		const char* COT_Format = "%Y-%m-%d,f1,f2,f3,f4,f5,f6,f7,f8,f9,f10";
		const char* COT_Code;
		if( OnlyFutures )
			COT_Code = strf("CFTC/%s_F_L_ALL",Code);
		else COT_Code = strf("CFTC/%s_FO_L_ALL",Code);
		double Long = dataFromQuandl(Handle,COT_Format,COT_Code,2);
		double Short = dataFromQuandl(Handle,COT_Format,COT_Code,3);
		return Long-Short;
	}

	double COT_Comm( int Handle, char* Code, bool OnlyFutures ){
		const char* COT_Format = "%Y-%m-%d,f1,f2,f3,f4,f5,f6,f7,f8,f9,f10";
		const char* COT_Code;
		if( OnlyFutures )
			COT_Code = strf("CFTC/%s_F_L_ALL",Code);
		else COT_Code = strf("CFTC/%s_FO_L_ALL",Code);
		return dataFromQuandl(Handle,COT_Format,COT_Code,5)-dataFromQuandl(Handle,COT_Format,COT_Code,6);
	}

	double COT_Retail( int Handle, char* Code, bool OnlyFutures ){
		const char* COT_Format = "%Y-%m-%d,f1,f2,f3,f4,f5,f6,f7,f8,f9,f10,f11";
		const char* COT_Code;
		if( OnlyFutures )
			COT_Code = strf("CFTC/%s_F_L_ALL",Code);
		else COT_Code = strf("CFTC/%s_FO_L_ALL",Code);
		return dataFromQuandl(Handle,COT_Format,COT_Code,10)-dataFromQuandl(Handle,COT_Format,COT_Code,11);
	}

//////////////////////

// Returs the PipValue in USD of the current FX Pair //

	double PipValue_USD()
	{
		char* AccCcy = "USD";
		double PipValue;
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
		return PipValue/10000;
	}

//////////////////////

// Returns the PipValue in EUR of the current FX Pair //

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
		return PipValue/10000;
	}

//////////////////////

// Base interest rate from Quandl

	void setCurrentSwap(double Broker_fee){

		// Base interest rate from Quandl

			double Base_ir;
			if( strstr(Base(),"AUD") )
				Base_ir = dataFromQuandl(901, "%Y-%m-%d,f", "BIS/PD_DAU", 1);
			else if( strstr(Base(),"CAD") )
				Base_ir = dataFromQuandl(902, "%Y-%m-%d,f", "BIS/PD_DCA", 1);
			else if( strstr(Base(),"CHF") )
				Base_ir = dataFromQuandl(903, "%Y-%m-%d,f", "BIS/PD_DCH", 1);
			else if( strstr(Base(),"EUR") )
				Base_ir = dataFromQuandl(904, "%Y-%m-%d,f", "BIS/PD_DXM", 1);
			else if( strstr(Base(),"GBP") )
				Base_ir = dataFromQuandl(905, "%Y-%m-%d,f", "BIS/PD_DGB", 1);
			else if( strstr(Base(),"HKD") )
				Base_ir = dataFromQuandl(906, "%Y-%m-%d,f", "BIS/PD_DHK", 1);
			else if( strstr(Base(),"JPY") )
				Base_ir = dataFromQuandl(907, "%Y-%m-%d,f", "BIS/PD_DJP", 1);
			else if( strstr(Base(),"NZD") )
				Base_ir = dataFromQuandl(908, "%Y-%m-%d,f", "BIS/PD_DNZ", 1);
			else if( strstr(Base(),"SGD") )
				Base_ir = dataFromQuandl(909, "%Y-%m-%d,f", "BIS/PD_DHK", 1); // Hong Kong interest rate
			else if( strstr(Base(),"USD") )
				Base_ir = dataFromQuandl(910,"%Y-%m-%d,f", "BIS/PD_DUS", 1);
			else if( strstr(Base(),"XAU") || strstr(Base(),"XAG") )
				Base_ir = 0.0;
		//

		// Term interest rate from Quandl
		
			double Term_ir;
			if( strstr(Term(),"AUD") )
				Term_ir = dataFromQuandl(901, "%Y-%m-%d,f", "BIS/PD_DAU", 1);
			else if( strstr(Term(),"CAD") )
				Term_ir = dataFromQuandl(902, "%Y-%m-%d,f", "BIS/PD_DCA", 1);
			else if( strstr(Term(),"CHF") )
				Term_ir = dataFromQuandl(903, "%Y-%m-%d,f", "BIS/PD_DCH", 1);
			else if( strstr(Term(),"EUR") )
				Term_ir = dataFromQuandl(904, "%Y-%m-%d,f", "BIS/PD_DXM", 1);
			else if( strstr(Term(),"GBP") )
				Term_ir = dataFromQuandl(905, "%Y-%m-%d,f", "BIS/PD_DGB", 1);
			else if( strstr(Term(),"HKD") )
				Term_ir = dataFromQuandl(906, "%Y-%m-%d,f", "BIS/PD_DHK", 1);
			else if( strstr(Term(),"JPY") )
				Term_ir = dataFromQuandl(907, "%Y-%m-%d,f", "BIS/PD_DJP", 1);
			else if( strstr(Term(),"NZD") )
				Term_ir = dataFromQuandl(908, "%Y-%m-%d,f", "BIS/PD_DNZ", 1);
			else if( strstr(Term(),"SGD") )
				Term_ir = dataFromQuandl(909, "%Y-%m-%d,f", "BIS/PD_DHK", 1); // Hong Kong interest rate
			else if( strstr(Term(),"USD") )
				Term_ir = dataFromQuandl(910,"%Y-%m-%d,f", "BIS/PD_DUS", 1);
			else if( strstr(Term(),"XAU") || strstr(Term(),"XAG") )
				Term_ir = 0.0;
		//

		// Calculate Swap rates
			double SwL = ((((Base_ir-Term_ir)/100)*10000)/365)-Broker_fee;
			double SwS = ((((Term_ir-Base_ir)/100)*10000)/365)-Broker_fee;
		//

		// Standarize to Swap rate to USD
			double SwapLong, SwapShort;
			if( strstr(Term(),"USD") ){
				SwapLong = SwL;
				SwapShort = SwS;
			}
			else if( strstr(Base(),"USD") ){
				SwapLong = SwL / priceClose(0);
				SwapShort = SwS / priceClose(0);
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
					strcat(Sym,"USD");
					asset(Sym);
					double Price = priceClose(0);
					asset(CurrSym);
					SwapLong = SwL * Price;
					SwapShort = SwS * Price;
				}   
				else if( strstr(Term,"CAD") || strstr(Term,"CHF") || strstr(Term,"HKD") || strstr(Term,"JPY") || strstr(Term,"SGD") )
				{
					char* CurrSym = Symbol;
					char Sym[8];
					strcpy(Sym,"USD");
					strcat(Sym,"/");
					strcat(Sym,Term);
					asset(Sym);
					double Price = priceClose(0);
					asset(CurrSym);
					SwapLong = SwL / Price;
					SwapShort = SwS / Price;
				}
			}
		//
		RollLong = SwapLong;
		RollShort = SwapShort;
	}

//////////////////////

// Set Lots with percentage of the account (Allocation) //

	void LotsAlloc(double Percentage)
	{
		char* AccCcy = "USD";
		double Collateral = ( Equity * Percentage/100 );

		if(strstr(Base(),AccCcy))
		{
			Lots = Collateral;
		}
		else if(strstr(Term(),AccCcy))
		{
			Lots = Collateral / priceClose(0);
		}
		else
		{
			char* Base = Base();            
			if( strstr(Base,"AUD") || strstr(Base,"EUR") || strstr(Base,"GBP") || strstr(Base,"NZD") || strstr(Base,"XAU") || strstr(Base,"XAG") )
			{
				char* CurrSym = Symbol;
				char Sym[8];
				strcpy(Sym,Base);
				strcat(Sym,"/");
				strcat(Sym,AccCcy);
				asset(Sym);
				double Price = priceClose(0);
				asset(CurrSym);
				Lots = Collateral / Price;
			}   
			else if( strstr(Base,"CAD") || strstr(Base,"CHF") || strstr(Base,"HKD") || strstr(Base,"JPY") || strstr(Base,"SGD") )
			{
				char* CurrSym = Symbol;
				char Sym[8];
				strcpy(Sym,AccCcy);
				strcat(Sym,"/");
				strcat(Sym,Base);
				asset(Sym);
				double Price = priceClose(0);
				asset(CurrSym);
				Lots = Collateral * Price;
			}
		}
	}

//////////////////////

// Set Fees for Backtest //

	void setFees(double SpreadInPercentage, double CommissionInPercentage, double SwapsBrokerFee, double SlippageInSeconds){
		char* CurrSym = Symbol;
		while(asset(loop(Assets))){
			Slippage = SlippageInSeconds;
			Spread = priceClose(0)*(SpreadInPercentage/100);
			Commission = 10000*(CommissionInPercentage/100);
			if( SwapsBrokerFee < 0 )
				RollLong = RollShort = 0;
			else{
				if( IsFX() )
					setCurrentSwap(SwapsBrokerFee);
				else
					RollLong = RollShort = 0;
			}
		}
		asset(CurrSym);
	}

//////////////////////

// Set FX Account parameters for each pair //

	void setFXaccounting(int LotUnits, int FixLeverage, char* Delimiter){
		while(asset(loop(Assets))){
			if( IsFX() ){
				if( FixLeverage > 0 ){
					Leverage = FixLeverage;
				}
				LotAmount = LotUnits;
				char* AccCcy = "USD";
				double AssetPrice = priceClose(0);
				if(strstr(Term(),AccCcy))
				{
					PIPCost = PIP * LotAmount;
				}
				else if(strstr(Base(),AccCcy))
				{
					PIPCost = ( PIP * LotAmount ) / AssetPrice;
				}
				else
				{
					char* Term = Term();            
					if( strstr(Term,"AUD") || strstr(Term,"EUR") || strstr(Term,"GBP") || strstr(Term,"NZD") || strstr(Term,"XAU") || strstr(Term,"XAG") )
					{
						char* CurrSym = Symbol;
						char Sym[8];
						strcpy(Sym,Term);
						strcat(Sym,Delimiter);
						strcat(Sym,AccCcy);
						asset(Sym);
						double USDPrice = priceClose(0);
						asset(CurrSym);
						PIPCost = ( PIP * LotAmount ) * USDPrice;
					}   
					else if( strstr(Term,"CAD") || strstr(Term,"CHF") || strstr(Term,"HKD") || strstr(Term,"JPY") || strstr(Term,"SGD") )
					{
						char* CurrSym = Symbol;
						char Sym[8];
						strcpy(Sym,AccCcy);
						strcat(Sym,Delimiter);
						strcat(Sym,Term);
						asset(Sym);
						double USDPrice = priceClose(0);
						asset(CurrSym);
						PIPCost = ( PIP * LotAmount ) / USDPrice;
					}
				}
				MarginCost = AssetPrice / Leverage * PIPCost / PIP;
			}
		}
	}

//////////////////////

// Return the percentage of Floating DrawDown of the account  //

	double FloatingDD(){
		return (Equity/Balance-1)*100;
	}

//////////////////////

// Calulcate Leverage per Currency and total positions Leverage //

	double AUD_lev,CAD_lev,CHF_lev,EUR_lev,GBP_lev,HKD_lev,JPY_lev,NZD_lev,SGD_lev,USD_lev,XAG_lev,XAU_lev;
	double CurrencyLeverage;
	
	void setCurrencyLeverage(){
		char* CurrSym = Symbol;
        AUD_lev=CAD_lev=CHF_lev=EUR_lev=GBP_lev=HKD_lev=JPY_lev=NZD_lev=SGD_lev=USD_lev=XAG_lev=XAU_lev=0;
        double TradeLev, TotalLeverage;
		TradeLev = TotalLeverage = 0;
        for(open_trades){
			if( IsFX() ){
				char* Base = Base();
				char* Term = Term();
				TradeLev = TradeLots*MarginCost*Leverage/Equity;
				TotalLeverage += TradeLev;
				if( TradeIsShort ){ TradeLev = -TradeLev; }
				if(strstr(Base,"AUD")){ AUD_lev += TradeLev; } else if( strstr(Term,"AUD")){ AUD_lev -= TradeLev; }
				if(strstr(Base,"CAD")){ CAD_lev += TradeLev; } else if( strstr(Term,"CAD")){ CAD_lev -= TradeLev; }
				if(strstr(Base,"CHF")){ CHF_lev += TradeLev; } else if( strstr(Term,"CHF")){ CHF_lev -= TradeLev; }
				if(strstr(Base,"EUR")){ EUR_lev += TradeLev; } else if( strstr(Term,"EUR")){ EUR_lev -= TradeLev; }
				if(strstr(Base,"GBP")){ GBP_lev += TradeLev; } else if( strstr(Term,"GBP")){ GBP_lev -= TradeLev; }
				if(strstr(Base,"HKD")){ HKD_lev += TradeLev; } else if( strstr(Term,"HKD")){ HKD_lev -= TradeLev; }
				if(strstr(Base,"JPY")){ JPY_lev += TradeLev; } else if( strstr(Term,"JPY")){ JPY_lev -= TradeLev; }
				if(strstr(Base,"NZD")){ NZD_lev += TradeLev; } else if( strstr(Term,"NZD")){ NZD_lev -= TradeLev; }
				if(strstr(Base,"SGD")){ SGD_lev += TradeLev; } else if( strstr(Term,"SGD")){ SGD_lev -= TradeLev; }
				if(strstr(Base,"USD")){ USD_lev += TradeLev; } else if( strstr(Term,"USD")){ USD_lev -= TradeLev; }
				if(strstr(Base,"XAG")){ XAG_lev += TradeLev; } else if( strstr(Term,"XAG")){ XAG_lev -= TradeLev; }
				if(strstr(Base,"XAU")){ XAU_lev += TradeLev; } else if( strstr(Term,"XAU")){ XAU_lev -= TradeLev; }
			}
        }
		CurrencyLeverage = TotalLeverage;
		asset(CurrSym);
	}

//////////////////////

// Current Account Leverage //

	double getLeverage(){
        double TradeLeverage = 0, CurrentLeverage = 0;
        for(open_trades){
			TradeLeverage = (TradeLots*MarginCost*Leverage)/Equity;
			CurrentLeverage += TradeLeverage;
        }
		return CurrentLeverage;
	}

//////////////////////

// Close all open tardes //

	void CloseAll(){
		for(open_trades){
			exitLong();
			exitShort();
		}
	}   

//////////////////////

// Execute Hardstops //

	void HardStops( double MinFloatingDD, double MaxFloatingDD, double MaxLeverage ){
		if( MaxLeverage > 0 )
			setCurrencyLeverage();
		double FDD = FloatingDD();
		if( FDD <= -abs(MinFloatingDD) || FDD >= abs(MaxFloatingDD) || CurrencyLeverage >= abs(MaxLeverage) ){
            CloseAll();
        }
	}   

//////////////////////

// Set Account Plots //

	void setAccountPlot(string BenchmarkSymbol, double BenchmarkLeverage){

		string CurrSym = Symbol;

		PlotHeight1 = 600; PlotHeight2 = 100;
		ColorUp = ColorDn = ColorWin = ColorLoss = ColorEquity = ColorDD = 0;

		asset(BenchmarkSymbol);
		static double InitBenchmark, InitBalance, Benchmark;
		static double StartYear, LastYearReturn, StartMonth, LastMonthReturn;
		static int Year = year(); static int Month = month();
		if( is(FIRSTRUN) ) {
			InitBenchmark = priceOpen(0);
			InitBalance = Benchmark = Balance;
			StartYear = StartMonth = Equity; }
		if( !is(LOOKBACK) ) {
			Benchmark = ( priceClose(0) / InitBenchmark ) * InitBalance; }
		if( year() > Year ) {
			LastYearReturn = ( ( Equity / StartYear) - 1 ) * 100;
			StartYear = Equity;
			Year = year(); }
		if( month() != Month ){
			LastMonthReturn = ( ( Equity / StartMonth) - 1 ) * 100;
			Month = month();
			StartMonth = Equity;
		}

		//asset(AssetBox);
		static double MaxBalance = Balance; static double MaxBalanceBenchmark = Benchmark;
		if( Balance > MaxBalance ) {
			MaxBalance = Balance; }
		if( Benchmark > MaxBalanceBenchmark ) {
			MaxBalanceBenchmark = Benchmark; }
		double UnderWater = ( Equity / MaxBalance - 1 ) * 100;
		if( UnderWater > 0 ) {
			UnderWater = 0; }
		double UnderWaterBenchmark = ( Benchmark / MaxBalanceBenchmark - 1 ) * 100;
		double Drawdown = Equity - MaxBalance;
		double DrawdownBenchmark = Benchmark - MaxBalanceBenchmark;

		plot("UW Benchmark", UnderWaterBenchmark, BARS, GREY + TRANSP);
		plot("UW Strategy", UnderWater, BARS, 0x1E86E2);
		plot("Benchmark", ((Benchmark / Capital - 1) * 100) * BenchmarkLeverage, 0, BLACK);
		plot("Strategy Balance", (Balance / Capital - 1) * 100, 0, 0x1E86E2 + TRANSP);
		plot("Strategy Equity", (Equity / Capital - 1) * 100, 0, 0x1E86E2);
		plot("UnrealizedPnL", FloatingDD(), BARS, RED + TRANSP);

		plot("LastYear", 0, 1, BLACK);
		plot("LastYearReturn", LastYearReturn, BARS, 0x1E86E2);
		plot("LastMonthReturn", LastMonthReturn, BARS, BLACK);

		plot("Leverage", 0, 1, BLACK);
		plot("Used Leverage", getLeverage(), BARS, RED); //0x1E86E2);

		asset(CurrSym);

	}

	int n_runs;
	void SetAccountPlots( char* Benchmark, double BnechmarkLeverage ){

		char* CurrSym = Symbol;

		set(PLOTNOW);
		PlotHeight1 = 600;
		PlotHeight2 = 100;
		ColorUp = ColorDn = ColorWin = ColorLoss = ColorEquity = ColorDD = 0;

		asset(Benchmark);
		n_runs++;
		static double InitialBench, InitialBalance, Bench;
		if( is(FIRSTRUN) ){
			InitialBench = priceOpen(0);
			InitialBalance = Bench = Balance;
		}
		if( n_runs > LookBack ){
			Bench = (priceClose(0)/InitialBench) * InitialBalance;
		}

		static double StartYear, LastYearReturn, StartMonth, LastMonthReturn;
		static int Year = year();
		static int Month = month();
		if( is(FIRSTRUN) ){
			StartYear = StartMonth = Equity;
		}
		if( year() > Year ){
			LastYearReturn = ((Equity/StartYear)-1)*100;
			StartYear = Equity;
			Year = year();
		}
		if( month() != Month ){
			LastMonthReturn = ((Equity/StartMonth)-1)*100;
			Month = month();
			StartMonth = Equity;
		}

		asset(AssetBox);
		
		//plot("StartYear",(StartYear/Capital-1)*100,0,GREY+TRANSP);
		//plot("StartMonth",(StartMonth/Capital-1)*100,0,BLACK+TRANSP);
		
		static double MaxBalance = Balance;
		static double MaxBalanceB = Bench;
		if( Balance > MaxBalance )
			MaxBalance = Balance;
		if( Bench > MaxBalanceB )
			MaxBalanceB = Bench;
		double UnderWater = (Equity/MaxBalance-1)*100;
		if( UnderWater > 0 )
			UnderWater = 0;
		double UnderWaterB = (Bench/MaxBalanceB-1)*100;
		double Drawdown = Equity-MaxBalance;
		double DrawdownB = Bench-MaxBalanceB;
		
		plot("UW Benchmark",UnderWaterB,BARS,GREY+TRANSP);
		plot("UW Strategy",UnderWater,BARS,0x1E86E2);

		plot("Benchmark",((Bench/Capital-1)*100)*BnechmarkLeverage,0,BLACK);
		plot("Strategy Balance",(Balance/Capital-1)*100,0,0x1E86E2+TRANSP);
		plot("Strategy Equity",(Equity/Capital-1)*100,0,0x1E86E2);
		plot("UnrealizedPnL",FloatingDD(),BARS,RED+TRANSP);	
		
		plot("LastYear",0,1,BLACK);
		plot("LastYearReturn",LastYearReturn,BARS,0x1E86E2);
		plot("LastMonthReturn",LastMonthReturn,BARS,BLACK);
		

		plot("Leverage",0,1,BLACK);
		plot("PositionsLeverage",CurrencyLeverage,BARS,RED);//0x1E86E2);
	
		plot("LeverageByCurrency",0,1,BLACK);
		if( AUD_lev != 0 )
			plot("AUD",AUD_lev,BARS,LIGHTBLUE);
		if( CAD_lev != 0 )
			plot("CAD",CAD_lev,BARS,GREEN);
		if( CHF_lev != 0 )
			plot("CHF",CHF_lev,BARS,BLUE);            
		if( EUR_lev != 0 )
			plot("EUR",EUR_lev,BARS,ORANGE);            
		if( GBP_lev != 0 )
			plot("GBP",GBP_lev,BARS,DARKBLUE);
		if( HKD_lev != 0 )
			plot("HKD",HKD_lev,BARS,OLIVE);
		if( JPY_lev != 0 )
			plot("JPY",JPY_lev,BARS,PURPLE);
		if( NZD_lev != 0 )
			plot("NZD",NZD_lev,BARS,MAGENTA);
		if( SGD_lev != 0 )
			plot("SGD",SGD_lev,BARS,CYAN);
		if( USD_lev != 0 )
			plot("USD",USD_lev,BARS,DARKGREEN);
		if( XAG_lev != 0 )
			plot("XAG",XAG_lev,BARS,SILVER);
		if( XAU_lev != 0 )
			plot("XAU",XAU_lev,BARS,YELLOW);
		
		asset(CurrSym);

	}

//////////////////////