#include <stdio.h>
#include <stdlib.h>
#include <time.h>
const int filas = 5;
const int colum = 12;


void promediosGanancia(long **matriz);
void valorMaximo(long **matriz);
void valorMinimo(long **matriz);


int main()
{
    long promedio;

    //1ra forma
    long ** pMatriz = (long **) malloc (sizeof(long) * filas);

    //2da forma
    long * pMatriz2 = (long *) malloc (sizeof(long) * filas * colum);

    srand(time(NULL));

    for (int i = 0; i < filas; i++)
    {
        pMatriz[i] = (long *) malloc(sizeof(long) * colum);

        for (int j = 0; j < colum; j++)
        {
            
            pMatriz[i][j] = 10000 + rand() % 40000; 

            printf("%6ld", pMatriz[i][j]);
            
        }
        printf("\n");    
    }

    //mostrando los promedios por anio..
    promediosGanancia(pMatriz);

    //mostrando valor maximo..
    valorMaximo(pMatriz);
    printf("\n");
    //mostrando valor minimo..
    valorMinimo(pMatriz);
    /*for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < colum; j++)
        {
            //cargar matriz

            *(pMatriz2 + i * colum + j) = 10000 + rand() % 40000; 

            printf("%6ld", *(pMatriz2 + i * colum + j ));
        }  
        printf("\n");
    } */
    
    return 0;
}

void promediosGanancia(long **matriz)
{
    long promedio;

    for (int i = 0; i < filas; i++)
    {
        promedio = 0;

        for (int j = 0; j < colum; j++)
        {
            promedio += matriz[i][j];
            
        }
        printf("El promedio del anio %d es: %ld\n",i+1,promedio);
    }

}
void valorMaximo(long **matriz)
{
    long maximo = 0;
    int anio, mes;
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < colum; j++)
        {
            if (matriz[i][j] > maximo)
            {
                maximo = matriz[i][j];
                anio = i+1;
                mes = j+1;
            }
        
        }
        
    }
    printf("El valor maximo es %ld", maximo);
    printf("\nDel anio : %d y del mes %d: ", anio,mes);
}

void valorMinimo(long **matriz)
{
    long minimo = 60000;
    int anio, mes;

    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < colum; j++)
        {
            if (matriz[i][j] < minimo)
            {
                minimo = matriz[i][j];
                anio = i+1;
                mes = j+1;
            }
        
        }
        
    }
    printf("El valor minimo es %ld", minimo);
    printf("\nDel anio : %d y del mes %d: ", anio,mes);   
}


//preguntar si en las funciones hay que manejrase con forma punteros