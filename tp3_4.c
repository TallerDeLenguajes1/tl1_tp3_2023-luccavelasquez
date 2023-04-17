#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct Producto {
    int ProductoID; //Numerado en ciclo iterativo
    int Cantidad; // entre 1 y 10
    char *TipoProducto; // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
} Producto;

typedef struct Cliente {
    int ClienteID; // Numerado en el ciclo iterativo
    char *NombreCliente; // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    Producto *Productos; //El tamaño de este arreglo depende de la variable
    // “CantidadProductosAPedir”
} Cliente;

float costoTotalProduct(Producto Productos);

int main()
{
    char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

    int cant, random;
    char *Buff = malloc(sizeof(char)*10);
    Cliente *clientes;
    
    srand(time(NULL));


    printf("Ingrese la cantidad de clientes: ");
    scanf("%d", &cant);
    
    clientes = malloc(sizeof(Cliente) * cant);

    //cargar
    for (int i = 0; i < cant; i++)
    {

        clientes[i].ClienteID = i+1; //para comenzar con el 1..
        printf("Ingrese el nombre: ");
        fflush(stdin);
        gets(Buff);
        clientes[i].NombreCliente = malloc(sizeof(char) * (strlen(Buff)+1));
        strcpy(clientes[i].NombreCliente,Buff);
        //
        clientes[i].CantidadProductosAPedir = 1 + rand() % 4; //1-5

        clientes[i].Productos = malloc(sizeof(Producto) * clientes[i].  CantidadProductosAPedir);

        for (int j = 0; j < clientes[i].CantidadProductosAPedir; j++)
        {
            clientes[i].Productos[j].ProductoID = j+1; //ver si va el +1
            clientes[i].Productos[j].Cantidad = 1 + rand() % 9;//1-10

            random = rand() % 5; //numero para sacar el aletotrio del   arreglo prod

            clientes[i].Productos[j].TipoProducto = malloc(sizeof(char) * (strlen(TiposProductos[random])+1));

            strcpy(clientes[i].Productos[j].TipoProducto,TiposProductos[random]);

            clientes[i].Productos[j].PrecioUnitario = 10 + rand() % 90; 
            
        }
    }

    //Mostrar
    for (int i = 0; i < cant; i++)
    {
        float total = 0;

        printf("\nCliente: %d\n",clientes[i].ClienteID);
        printf("Su nombre es: %s\n",clientes[i].NombreCliente);
        printf("Cantidad de productos a pedir: %d\n",clientes[i].CantidadProductosAPedir);

        for (int j = 0; j < clientes[i].CantidadProductosAPedir; j++)
        {
            printf("\nProducto: %d\n",clientes[i].Productos[j].ProductoID);
            printf("Cantidad : %d\n",clientes[i].Productos[j].Cantidad);
            printf("Tipo de Producto: %s\n",clientes[i].Productos[j].TipoProducto);
            printf("Precio Unitario: %f\n",clientes[i].Productos[j].PrecioUnitario);
            //calculamos el total de los productos de cada cliente
            total += costoTotalProduct(clientes[i].Productos[j]);
        }
        printf("\nTOTAL A PAGAR: %f\n",total);


        printf("---------------------");
    }

    return 0;
}


float costoTotalProduct(Producto producto)
{
    float result;
    result = producto.Cantidad * producto.PrecioUnitario;

    return result;
}

//preguntar en que momento se libera la memoria, si despues del mostrar o antes..