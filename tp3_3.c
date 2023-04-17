#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int cant;
    char **vector;
    char *Buff;
    
    printf("Ingrese la cantidad de nombres: ");
    scanf("%d",&cant);

    vector = (char **) malloc(sizeof(char) * cant);
    
    
    for (int i = 0; i < cant; i++)
    {
        Buff = (char *) malloc(sizeof(char)*100);
        printf("Ingrese un nombre: ");
        fflush(stdin);
        gets(Buff);

        vector[i] = (char *) malloc(sizeof(char) * (strlen(Buff)+1));
        strcpy(vector[i],Buff);

        free(Buff);
    }

    //mostrar
    for (int i = 0; i < cant; i++)
    {
        puts(vector[i]);

    }
    
    //tengo problemas con el ultimo nombre
    //preguntar porque es necesario utilizar el auxiliar
    //falta liberar memoria de vector[i]



    return 0;
}

