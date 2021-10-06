/*
 * marca.h
 *
 *  Created on: 6 oct. 2021
 *      Author: Mati
 */

#ifndef MARCA_H_
#define MARCA_H_

typedef struct{
	int id;
	char descripcion[20];
}eMarca;

#endif /* MARCA_H_ */

void listarMarcas(eMarca marca [], int tamTip );

int cargarDescripcionMarca(char descripcion[], int id, eMarca marca[], int tamTip );
int validarMarca(int marca);
