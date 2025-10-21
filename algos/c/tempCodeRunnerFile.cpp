int* sumMatrix(int a[][], int b[][], int filas, int columnas){

    int* suma = new int[filas][columnas]

    for(int i = 0; i < filas; i++)
    {
        for(int j = 0; j < columnas; j++)
        {
            suma[i][j] = a[i][j] + b[i][j];
        }
                
    }

    return suma;
    
}