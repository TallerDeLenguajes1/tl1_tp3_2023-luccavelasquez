#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int N = 5;

int main()
{

    char **vector;
    char *Buff;
    
    vector = (char **) malloc(sizeof(char) * N);
    Buff = (char *) malloc(sizeof(char)*100);

    for (int i = 0; i < N; i++)
    {
        printf("Ingrese un nombre: ");
        gets(Buff);

        vector[i] = (char *) malloc((strlen(Buff)+1) *sizeof(char));
        strcpy(vector[i],Buff);
        
        puts(vector[i]);
    }
    
    //tengo problemas con el ultimo nombre
    //preguntar porque es necesario utilizar el auxiliar
    //falta liberar memoria



    return 0;
}