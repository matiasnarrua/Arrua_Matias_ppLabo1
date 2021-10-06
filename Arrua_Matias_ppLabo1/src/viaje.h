/*
 * viaje.h
 *
 *  Created on: 6 oct. 2021
 *      Author: Mati
 */

#ifndef VIAJE_H_
#define VIAJE_H_

typedef struct{
	int idViaje;
	char descripcion[25];
	float kms;
}eViaje;


#endif /* VIAJE_H_ */

void listarViaje(eViaje viajes [], int tamViaje );

int cargarDescripcionViaje(char descripcion[], int id, eViaje viajes[], int tamViaje );
int validarViaje(int viaje);
