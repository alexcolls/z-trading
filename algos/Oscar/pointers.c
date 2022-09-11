#include <stdio.h>

typedef struct{
    int x;
    int y;
    Point* pint;
} Point;

int main(){

    int a = 5;
    int* pa = &a; // pa = a NO

    int b = 10;
    int* pb = &b;

    printf("Valor de a: %d =  valor del puntero: %d", a, pa);

    *pa = 20; //a

    printf("\nValor de a: %d", a);
    printf("\nValor de b: %d", b);

    pa = pb; //pa = &b

    *pa = 20; //b

    printf("\nValor de b: %d", b);

    //---------------------------------//

    Point punto1 = { 1, 3, &a };

    printf("\nValor de x: %d ,  valor de y: %d, valor de pint: %d", punto1.x, punto1.y, *(punto1.pint));

    Point* ppunto = &punto1;

    printf("\nValor de x: %d ,  valor de y: %d, valor de pint: %d", ppunto->x, ppunto->y, *(ppunto->pint));


    void* pvoid = (void*) ppunto;

    return 0;
}