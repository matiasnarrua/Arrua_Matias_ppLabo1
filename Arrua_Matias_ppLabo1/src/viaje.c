/*
 * viaje.c
 *
 *  Created on: 6 oct. 2021
 *      Author: Mati
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "viaje.h"


void listarViaje(eViaje viajes [], int tamViaje )
{

    printf("*****Listado de tipos*****\n\n");
    printf("Id    Descripcion      Kms\n");

    for(int i=0; i<tamViaje; i++)
    {
        printf("%d   %10s    %2.2f\n",viajes[i].idViaje, viajes[i].descripcion, viajes[i].kms);
    }
    printf("\n\n");
}


int cargarDescripcionViaje(char descripcion[], int id, eViaje viajes[], int tamViaje )
{

    int todoOk = 0;
    for(int i=0; i <tamViaje; i++)
    {
        if(viajes[i].idViaje == id)
        {
            strcpy(descripcion, viajes[i].descripcion);
            todoOk = 1;

        }

    }
    return todoOk;
}


int validarViaje(int viaje)
{

    do
    {

        if(viaje <100 || viaje>104)
        {

            printf("\nError selecciones un id de viaje valido: ");
            scanf("%d", &viaje);
        }
    }
    while(viaje <100 || viaje>104);

    return viaje;
}
