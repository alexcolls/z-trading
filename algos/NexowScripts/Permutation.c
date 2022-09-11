
//#include <nexow.h> 

void recur(string *assets, string out, int i, int nassets, int assetsperalgo){
	if (assetsperalgo > nassets ){
        printf("Error -> More APA than ASS");
		return;
    }
	if (assetsperalgo == 0){
		printf("\n%s",out);
		return;
	}
    int j;
	for ( j = i; j < nassets; j++){
        char aux1[10];
        strcpy(aux1, out);
        char aux2[10];
        strcpy(aux2, assets[j]);
        char aux[10];
        memset(aux,0,sizeof(aux));
        strcat(aux, aux1);
        strcat(aux, aux2);
		recur(assets, aux, j + 1, nassets, assetsperalgo - 1);
	}
}

void main(){

	string assets[10];
    
    assets[0] = "A";
    assets[1] = "B";
    assets[2] = "C";
    assets[3] = "D";

    int ass = 4;
	int apa = 2;

	recur(assets,"", 0, ass, apa);

}


