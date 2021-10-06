/*
 * aviones.h
 *
 *  Created on: 6 oct. 2021
 *      Author: Mati
 */
#include "fecha.h"
#include "marca.h"
#include "viaje.h"

#ifndef AVIONES_H_
#define AVIONES_H_
typedef struct{
	int idAvion;
	int matricula;
	int idViaje;
	int idMarca;
	int modelo;
	int cantAsientos;
	eFecha fecha;
	int isEmpty;
}eAviones;


#endif /* AVIONES_H_ */

int menu();
void inicializarAviones(eAviones vec[], int tam );

int altaAvion(eAviones avion[], int tam, int id, eViaje viajes[],int tamViaje, eMarca marcas[], int tamMarca);

void mostrarAvion(eAviones aviones, eMarca marca[], int tamMar,eViaje viajes[], int tamViaj);

void listarAviones(eAviones aviones[], int tamA, eMarca marcas[], int tamMarc,eViaje viajes[], int tamViaje);

int buscarAvion (int id,eAviones aviones[],int tamA );

void modificarAvion (eAviones aviones[], int tamA, eMarca marcas[], int tamMar,eViaje viajes[], int tamVia);

void bajaAvion (eAviones aviones[], int tamA, eMarca marcas[], int tamMar,eViaje viajes[], int tamVia );

void ordenarAviones(eAviones aviones[], int tamA);


