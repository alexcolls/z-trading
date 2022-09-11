#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define N 8
#define BUIT ' '
#define CPU   '0'
#define PLAYER 'X'
//Sebastian Osuna Marin NIU:1316340
//no he hecho lo de los dos ficheros, si fuera necesario lo puedo hacer y llevartelo el dia de la entrevista o el dia que me pidas.


typedef struct node {
struct node **fills;
int n_fills;
int col;
char tauler[N][N];
double valor;
} Node;

double heuristica(char tauler[N][N]){
 int i,j;
 double cont=0;

//parte positiva

//victoria
  for(i=0;i<N;i++){
    for(j=0;j<N-3;j++){
	if(tauler[i][j]==CPU & tauler[i][j+1]==CPU & tauler[i][j+2]==CPU & tauler[i][j+3]==CPU){cont=cont+5000;}
    }
  }


  for(j=0;j<N;j++){
    for(i=0;i<N-3;i++){
	if(tauler[i][j]==CPU & tauler[i+1][j]==CPU & tauler[i+2][j]==CPU & tauler[i+3][j]==CPU ){cont=cont+5000;}
    }
  }

 for(i=0;i<N-3;i++){
    for(j=0;j<N-3;j++){
	if(tauler[i][j]==CPU & tauler[i+1][j+1]==CPU & tauler[i+2][j+2]==CPU & tauler[i+3][j+3]==CPU){cont=cont+5000;}
    }
  }

  for(i=0;i<N-3;i++){
    for(j=3;j<N;j++){
	if(tauler[i][j]==CPU & tauler[i+1][j-1]==CPU & tauler[i+2][j-2]==CPU & tauler[i+3][j-3]==CPU){cont=cont+5000;}
    }

  }


//poner 3 juntas

   for(i=0;i<N;i++){
    for(j=0;j<N-2;j++){
	if(tauler[i][j]==CPU & tauler[i][j+1]==CPU & tauler[i][j+2]==CPU){cont=cont+50;}
    }
  }


  for(j=0;j<N;j++){
    for(i=0;i<N-2;i++){
	if(tauler[i][j]==CPU & tauler[i+1][j]==CPU & tauler[i+2][j]==CPU){cont=cont+50;}
    }
  }

 for(i=0;i<N-2;i++){
    for(j=0;j<N-2;j++){
	if(tauler[i][j]==CPU & tauler[i+1][j+1]==CPU & tauler[i+2][j+2]==CPU){cont=cont+50;}
    }
  }

  for(i=0;i<N-2;i++){
    for(j=2;j<N;j++){
	if(tauler[i][j]==CPU & tauler[i+1][j-1]==CPU & tauler[i+2][j-2]==CPU){cont=cont+50;}
    }

  }
 //poner 2 juntas

   for(i=0;i<N;i++){
    for(j=0;j<N-1;j++){
	if(tauler[i][j]==CPU & tauler[i][j+1]==CPU){cont=cont+20;}
    }
  }


  for(j=0;j<N;j++){
    for(i=0;i<N-1;i++){
	if(tauler[i][j]==CPU & tauler[i+1][j]==CPU){cont=cont+20;}
    }
  }

 for(i=0;i<N-1;i++){
    for(j=0;j<N-1;j++){
	if(tauler[i][j]==CPU & tauler[i+1][j+1]==CPU){cont=cont+20;}
    }
  }

  for(i=0;i<N-1;i++){
    for(j=1;j<N;j++){
	if(tauler[i][j]==CPU & tauler[i+1][j-1]==CPU){cont=cont+20;}
    }
  }
//colocacion piezas mas centradas
int kont=0;
    for(i=0;i<N;i++){
            if(tauler[i][1]==CPU || tauler[i][6]==CPU){kont++;}
            if(tauler[i][2]==CPU || tauler[i][5]==CPU){kont=kont+2;}
            if(tauler[i][3]==CPU || tauler[i][4]==CPU){kont=kont+3;}
    }
  cont=cont+kont;
//parte negativa
//derrota
  for(i=0;i<N;i++){
    for(j=0;j<N-3;j++){
	if(tauler[i][j]==PLAYER & tauler[i][j+1]==PLAYER & tauler[i][j+2]==PLAYER & tauler[i][j+3]==PLAYER){cont=cont-950;}
    }
  }


  for(j=0;j<N;j++){
    for(i=0;i<N-3;i++){
	if(tauler[i][j]==PLAYER & tauler[i+1][j]==PLAYER & tauler[i+2][j]==PLAYER & tauler[i+3][j]==PLAYER ){cont=cont-950;}
    }
  }

 for(i=0;i<N-3;i++){
    for(j=0;j<N-3;j++){
	if(tauler[i][j]==PLAYER & tauler[i+1][j+1]==PLAYER & tauler[i+2][j+2]==PLAYER & tauler[i+3][j+3]==PLAYER){cont=cont-950;}
    }
  }

  for(i=0;i<N-3;i++){
    for(j=3;j<N;j++){
	if(tauler[i][j]==PLAYER & tauler[i+1][j-1]==PLAYER & tauler[i+2][j-2]==PLAYER & tauler[i+3][j-3]==PLAYER){cont=cont-950;}
    }

  }

//3 juntas


   for(i=0;i<N;i++){
    for(j=0;j<N-2;j++){
	if(tauler[i][j]==PLAYER & tauler[i][j+1]==PLAYER & tauler[i][j+2]==PLAYER){cont=cont-40;}
    }
  }


  for(j=0;j<N;j++){
    for(i=0;i<N-2;i++){
	if(tauler[i][j]==PLAYER & tauler[i+1][j]==PLAYER & tauler[i+2][j]==PLAYER){cont=cont-40;}
    }
  }

 for(i=0;i<N-2;i++){
    for(j=0;j<N-2;j++){
	if(tauler[i][j]==PLAYER & tauler[i+1][j+1]==PLAYER & tauler[i+2][j+2]==PLAYER){cont=cont-40;}
    }
  }

  for(i=0;i<N-2;i++){
    for(j=2;j<N;j++){
	if(tauler[i][j]==PLAYER & tauler[i+1][j-1]==PLAYER & tauler[i+2][j-2]==PLAYER){cont=cont-40;}
    }


  return cont;
}
}
int mirarsisepuede(char tauler[N][N],int i){ //esta funcion no la utilizo
if(tauler[0][i]==BUIT){return 1;}
return 0;
}
void imprimirtauler(char tauler[N][N]){
int i,j;
system("cls");
for(i=0;i<N;i++){
    printf("|%d",i);
}
printf("| \n");
    for(i=0;i<N;i++){

        for(j=0;j<N;j++){
            printf("|%c",tauler[i][j]);
        }

        printf("|\n");
    }
}
void inictauler(char tauler[N][N]){
    int i,j;

    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            tauler[i][j]=BUIT;
        }
    }
}
void aplicarTirada(char tauler[N][N],int col, char PC){
    int i=N-1;
    while(tauler[i][col]!=BUIT || i==-1){
        i--;
    }

    if(i>-1){tauler[i][col]=PC;}
    else{printf("error \n");}
}
int numFills(char tauler[N][N]){
  int i,cont=0;

  for(i=0;i<N;i++){
    if(tauler[0][i]==BUIT){cont++;}
  }
  return cont;
}
int compvic(char tauler[N][N], char PC){
  int i,j,cont=0;

  for(i=0;i<N;i++){
    for(j=0;j<N-3;j++){
	if(tauler[i][j]==PC & tauler[i][j+1]==PC & tauler[i][j+2]==PC & tauler[i][j+3]==PC){return 1;}
    }
  }


  for(j=0;j<N;j++){
    for(i=0;i<N-3;i++){
	if(tauler[i][j]==PC & tauler[i+1][j]==PC & tauler[i+2][j]==PC & tauler[i+3][j]==PC ){return 1;}
    }
  }

 for(i=0;i<N-3;i++){
    for(j=0;j<N-3;j++){
	if(tauler[i][j]==PC & tauler[i+1][j+1]==PC & tauler[i+2][j+2]==PC & tauler[i+3][j+3]==PC){return 1;}
    }
  }

  for(i=0;i<N-3;i++){
    for(j=3;j<N;j++){
	if(tauler[i][j]==PC & tauler[i+1][j-1]==PC & tauler[i+2][j-2]==PC & tauler[i+3][j-3]==PC){return 1;}
    }

  }

  return 0;
}
void copiaTauler(char tauler1[N][N],char tauler2[N][N]){
int i,j;

for(i=0;i<N;i++){
  for(j=0;j<N;j++){
  tauler1[i][j]=tauler2[i][j];
    }
  }
}
Node *creaNode(char tauler[N][N],int numFill,int nivell){
    //printf("el tauler es \n" );
    //imprimirtauler(tauler);
    //printf("la columna es: %d  \n y el nivel es %d \n \n",numFill,nivell);
    Node *p=malloc(sizeof(Node));
    p->col=numFill;
    copiaTauler(p->tauler,tauler);
    if(nivell==2){
        aplicarTirada(p->tauler,numFill,PLAYER);
        p->n_fills=0,p->fills=NULL;
        p->valor=heuristica(p->tauler);
        //printf("el valor es: %lf \n",p->valor);
        //imprimirtauler(p->tauler);
        }
    else{
        aplicarTirada(p->tauler,numFill,CPU);
        p->n_fills=numFills(p->tauler);
        p->fills=malloc((p->n_fills)*sizeof(Node*));
    }
return p;
}
void crea1Nivell(Node *pare, int nivell){
  int col,indfill;
  indfill=0;
  for(col=0;col<pare->n_fills;col++){
    //if(mirarsisepuede(pare->tauler,col)==1){
        pare->fills[indfill]=creaNode(pare->tauler,col,nivell);
        indfill++;
    //}
  }
}
void creaArbre(Node *arrel){
  int i;
  crea1Nivell(arrel,1);
  for(i=0;i<arrel->n_fills;i++){
    crea1Nivell(arrel->fills[i],2);
  }
}
void evaluarhojas(Node *arrel){            //esta funcion no la utilizo
int i;
if(arrel->n_fills>0){
    for(i=0;i<=arrel->n_fills;i++){
        evaluarhojas(arrel->fills[i]);
        }
    }
else{
    arrel->valor=heuristica(arrel->tauler);

    }
}
void subirmin(Node *arrel){
double a;
int i;
a=arrel->fills[0]->valor;
for(i=0;i<arrel->n_fills-1;i++){
        //printf("------------------------------------------- \n");
        //printf("el valor de i es: %lf y el de i+1 es:%lf \n",a,arrel->fills[i+1]->valor);
        //imprimirtauler(arrel->fills[i]->tauler);
        //printf("_____________________________ \n");
        //imprimirtauler(arrel->fills[i+1]->tauler);


    if(a < arrel->fills[i+1]->valor){
       //  printf("el valor cogido es %lf \n",a);
    }
    else{
        a=arrel->fills[i+1]->valor;
       // printf("el valor cogido es %lf \n",a);
    }
}
//printf("------------------------------------------- \n");
//printf("el minimo subido es: %lf \n",a);
arrel->valor=a;
}
void subirmax(Node *arrel){                 //esta funcion no la utilizo
double a;
int i;
for(i=0;i<arrel->n_fills;i++){
    if(arrel->fills[i]->valor > arrel->fills[i+1]->valor){
        a=arrel->fills[i]->valor;
    }
    else{
        a=arrel->fills[i+1]->valor;
    }
}
arrel->valor=a;
}
int subirultimomax(Node *arrel){
int i,j;
j=arrel->fills[0]->col;
for(i=0;i<arrel->n_fills;i++){
    if(arrel->fills[i]->valor > arrel->fills[j]->valor){j=arrel->fills[i]->col;}
}
return j;
}
void minimax(Node *arrel){
int i,c;
creaArbre(arrel);
for(i=0;i<N;i++){
        subirmin(arrel->fills[i]);
       // printf("\n \n ______________%lf \n \n",arrel->fills[i]->valor);
    }
c=subirultimomax(arrel);
aplicarTirada(arrel->tauler,c,CPU);
}
void turno(Node *a, char PC){

if(PC==PLAYER){
        int b;
    printf("a que columna quieres tirar?");
   scanf("%d",&b);
   aplicarTirada(a->tauler,b,PLAYER);
   imprimirtauler(a->tauler);
}
else{
    minimax(a);
    imprimirtauler(a->tauler);
}
}

int main(){
int i,j,b,tirada=0;
char PC;
Node a;
inictauler(a.tauler);
a.n_fills=N;
a.fills=malloc((a.n_fills)*sizeof(Node*));

printf("Elige quien quieres que empieze puta!: 1 TU // OTRO MAQUINA");
scanf("%d",&b);
if(b==1){PC=PLAYER;}
else{PC=CPU;}
while(compvic(a.tauler,PLAYER)==0 && compvic(a.tauler,CPU)==0 && tirada<64){
   turno(&a,PC);

   if(PC==CPU){PC=PLAYER;}
   else{PC=CPU;}
   printf("estamos en la tirada %d \n",tirada);
   tirada++;
}
if(compvic(a.tauler,PLAYER)==1){printf("has ganao!!! enhorabuena!");}
else if(compvic(a.tauler,CPU)==1){printf("has perdido, la proxima vez sera");}
else{printf("TABLAS tablero lleno!");}


return 0;
}
