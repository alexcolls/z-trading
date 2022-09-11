#include <iostream>

#define MAX_COLUMNAS 100


using namespace std;

int main(){





    return 0;
}

int** sumMatrix(int a[][MAX_COLUMNAS], int b[][MAX_COLUMNAS], int filas, int columnas){

    int** suma = new int*[filas];
    *suma = new int[columnas];

    for(int i = 0; i < filas; i++)
    {
        for(int j = 0; j < columnas; j++)
        {
            suma[i][j] = a[i][j] + b[i][j];
        }     
    }

    return suma;
    
}