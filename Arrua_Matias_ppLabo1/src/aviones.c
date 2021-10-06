/*
 * aviones.c
 *
 *  Created on: 6 oct. 2021
 *      Author: Mati
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "aviones.h"

int menu() {
	int opcion;

	system("cls");
	printf("***** Gestion de la Aerolinea *****\n\n");
	printf(
			"1. Alta Avion\n2. Modificar Avion\n3. Baja Avion\n4. Listar Aviones\n5. Listar Viajes\n"
					"6. Listar Marcas\n7. Salir\n\n");
	fflush(stdin);
	printf("Ingrese opcion: ");
	scanf("%d", &opcion);

	return opcion;

}

void inicializarAviones(eAviones vec[], int tam) {
	for (int i = 0; i < tam; i++) {
		vec[i].isEmpty = 1;

	}
}

int buscarLibre(eAviones avion[], int tam) {
	int aux = -1;

	for (int i = 0; i < tam; i++) {
		if (avion[i].isEmpty == 1) {
			aux = i;
			break;
		}
	}
	return aux;
}

int altaAvion(eAviones avion[], int tam, int id, eViaje viajes[],int tamViaje, eMarca marcas[], int tamMarca) {
	int ok = 0;
	eAviones auxAvion;
	int pos = buscarLibre(avion, tam);
	if (pos == -1) {
		printf("Sistema Completo\n\n");
	} else {
		auxAvion.idAvion = id;

		printf("ingrese la matricula: ");
		scanf("%d", &auxAvion.matricula);



		        system("cls");
		        listarViaje(viajes, tamViaje);
		        printf("\nSeleccione el id del viaje_ ");
	        	scanf("%d", &auxAvion.idViaje);

	        	validarViaje(auxAvion.idViaje);

	        	system("cls");
	        	listarMarcas(marcas, tamMarca);
		printf("\nSeleccione el id de la marca: ");
		scanf("%d", &auxAvion.idMarca);
		validarMarca(auxAvion.idMarca);

		printf("ingrese el Modelo: ");
		scanf("%d", &auxAvion.modelo);
		while (auxAvion.modelo < 1950 || auxAvion.modelo > 2021) {
					printf("error ingrese modelo valido (1950-2021)");
					scanf("%d", &auxAvion.modelo);
				}

		printf("ingrese la cantidad de asientos: ");
		scanf("%d", &auxAvion.cantAsientos);
		while (auxAvion.cantAsientos < 1 || auxAvion.cantAsientos > 3000) {
			printf("error ingrese una cantidad valida (0-3000)");
			scanf("%d", &auxAvion.cantAsientos);
		}

		printf("ingrese la fecha ( DIA ): ");
		scanf("%d", &auxAvion.fecha.dia);
		while (auxAvion.fecha.dia < 0 || auxAvion.fecha.dia > 31) {
			printf("error ingrese un dia valido");
			scanf("%d", &auxAvion.fecha.dia);
		}
		printf("ingrese la fecha ( MES ): ");
		scanf("%d", &auxAvion.fecha.mes);
		while (auxAvion.fecha.mes < 0 || auxAvion.fecha.mes > 12) {
			printf("error ingrese un mes valido");
			scanf("%d", &auxAvion.fecha.mes);
		}

		printf("ingrese la fecha ( ANIO ): ");
		scanf("%d", &auxAvion.fecha.anio);
		while (auxAvion.fecha.anio < 2000 || auxAvion.fecha.anio > 2021) {
			printf("error ingrese un anio valido (2000-2021)");
			scanf("%d", &auxAvion.fecha.anio);
		}

		auxAvion.isEmpty = 0;
avion[pos] = auxAvion;
		ok = 1;
	}

	return ok;
}

void mostrarAvion(eAviones aviones, eMarca marca[], int tamMar,eViaje viajes[], int tamViaj) {
	char descMarc[20];
	char descViaje[20];

	cargarDescripcionMarca(descMarc, aviones.idMarca, marca, tamMar);
	cargarDescripcionViaje(descViaje, aviones.idViaje, viajes, tamViaj);
	printf("%8d   %8d     %15s  %15s    %8d  %10d\n", aviones.idAvion,aviones.modelo, descViaje, descMarc, aviones.matricula,aviones.cantAsientos);

}

void listarAviones(eAviones aviones[], int tamA, eMarca marcas[], int tamMarc,eViaje viajes[], int tamViaje)
{

    int flag = 0;

    system("cls");
    printf("*****Listado de aviones*****\n\n");

    printf("       Id     Modelo              Viaje            Marca     Matricula     Cant/Asientos    \n");

    for(int i=0; i<tamA; i++)
    {
        if(aviones[i].isEmpty == 0 )
        {
            mostrarAvion (aviones [i], marcas, tamMarc,viajes, tamViaje);
            flag = 1;
        }
    }
    if(flag ==0)
    {
        printf("****No hay aviones que mostrar****\n\n");
    }

}




int buscarAvion (int id,eAviones aviones[],int tamA )
{
    int indice = -1;
    for(int i=0; i<tamA; i++)
    {
        if(aviones[i].matricula == id && aviones[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void modificarAvion (eAviones aviones[], int tamA, eMarca marcas[], int tamMar,eViaje viajes[], int tamVia)
{
    int id ;
    int indice;
    char confirma;
    int opcion;
    int nuevoCantAs;
    int nuevoModelo;



    system("cls");
    printf("***** Modificar Avion *****\n\n");

    listarAviones(aviones,tamA,marcas,tamMar,viajes,tamVia);

    printf("Ingrese la matricula: ");
    scanf("%d", &id);
    indice = buscarAvion(id, aviones, tamA);

    if(indice == -1)
    {
        printf("No hay registro de la bicicleta con el Id: %d\n",id);
    }
    else
    {
        mostrarAvion(aviones[indice],marcas, tamMar,viajes,tamVia);

        printf("Modificar este Avion[S/N] ?");
        fflush(stdin);
        scanf("%c", &confirma);

        if(confirma == 's')
        {
            printf("Seleccione que desea modificar:\n1_Modelo\n2_Cantidad de asientos\n\n");
            scanf("%d",&opcion);

            switch(opcion)
            {
            case 1:
                system("cls");

                printf("****Modificar Modelo de avion****\n\n");

                printf("ingrese el modelo a modificar: ");
                scanf("%d",&nuevoModelo);

                aviones[indice].modelo = nuevoModelo;
                printf("Se ha actualizado el modelo del avion \n\n");

                break;
            case 2:
                system("cls");
                printf("****Modificar Cantidad de asientos****\n\n");
                printf("ingrese la cantidad de asientos a modificar: : ");
                scanf("%d",&nuevoCantAs);
                while (nuevoCantAs < 0 || nuevoCantAs > 3000) {
                			printf("error ingrese una cantidad valida (0-3000)");
                			scanf("%d", &nuevoCantAs);
                		}

                aviones[indice].cantAsientos = nuevoCantAs;
                printf("Se ha actualizado el rodado con exito \n\n");
                break;
            }

        }
        else
        {
            printf("Se ha cancelado la operacion\n\n");
        }
    }
}


void bajaAvion (eAviones aviones[], int tamA, eMarca marcas[], int tamMar,eViaje viajes[], int tamVia )
{
    int matricula ;
    int indice;
    char confirma;
    system("cls");
    printf("*****Baja Avion *****\n\n");

    listarAviones(aviones,tamA,marcas,tamMar,viajes,tamVia);
    printf("\nIngrese matricula: ");
    scanf("%d", &matricula);
    indice = buscarAvion(matricula, aviones, tamA);

    if(indice == -1)
    {

        printf("No hay registro del avion con la matricula: %d\n",matricula);
    }
    else
    {
        mostrarAvion (aviones[indice],marcas, tamMar,viajes,tamVia);
        printf("Confirma baja[S/N] ?");
        fflush(stdin);
        scanf("%c", &confirma);

        if(confirma == 's')
        {
            aviones[indice].isEmpty = 1;
            printf("Se ha realizado la baja con exito \n\n");
        }
        else
        {
            printf("Se ha cancelado la operacion\n\n");
        }
    }
}


void ordenarAviones(eAviones aviones[], int tamA)
{
    eAviones auxAvion;
    for(int i=0; i<tamA-1; i++)
    {
        for(int j= i+1; j<tamA; j++)
        {

            if( aviones[i].idMarca > aviones[j].idMarca)
            {

                auxAvion = aviones[i];
                aviones[i]=aviones[j];
                aviones[j] = auxAvion;
            }
            else if (aviones[i].idMarca == aviones[j].idMarca && aviones[i].matricula > aviones[j].matricula)
            {
                auxAvion=aviones[i];
                aviones[i]=aviones[j];
                aviones[j] = auxAvion;
            }

        }
    }
}


