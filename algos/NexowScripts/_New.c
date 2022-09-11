// Strategy template ///////////////////////

#include <nexow.h>

#define NA 5
#define APA 3

string ASS[NA];
ASS[0] = "A";
ASS[1] = "B";
ASS[2] = "C";
ASS[3] = "D";
ASS[4] = "E";


var Fact(var n)
{
	if (n > 1)
		return n * Fact(n - 1);
	else
		return 1;
}
/*
int AlgosX(var i, var j)
{
	var num = Fact(i);
	var auxx = i - j;
	var denom = Fact(auxx) * Fact(j);
	var ret = num / denom;
	return (int)ret;
}
*/
/*
void Recursiva(int i, int j, int k){
	for(int ii = i; ii < NA - (AP - j); ii++){
		print("\n Algo %d letter %d",k,ii);
		k++;
	}
}*/






void main()
{

	int a = nAlgos(6,3);



	printf("%d",a);

}
