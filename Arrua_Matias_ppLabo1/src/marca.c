/*
 * marca.c
 *
 *  Created on: 6 oct. 2021
 *      Author: Mati
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "marca.h"


void listarMarcas(eMarca marca [], int tamTip )
{

    printf("*****Listado de marca*****\n\n");
    printf("Id    Descripcion\n");

    for(int i=0; i<tamTip; i++)
    {
        printf("%d   %10s\n",marca[i].id, marca[i].descripcion);
    }
    printf("\n\n");
}


int cargarDescripcionMarca(char descripcion[], int id, eMarca marca[], int tamTip )
{

    int todoOk = 0;
    for(int i=0; i <tamTip; i++)
    {
        if(marca[i].id == id)
        {
            strcpy(descripcion, marca[i].descripcion);
            todoOk = 1;

        }

    }
    return todoOk;
}


int validarMarca(int marca)
{

    do
    {

        if(marca <1000 || marca>1003)
        {

            printf("\nError selecciones un id de marca valido: ");
            scanf("%d", &marca);
        }
    }
    while(marca <1000 || marca>1003);

    return marca;
}
