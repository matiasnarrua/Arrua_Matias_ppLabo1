/*
 * hardcodear.h
 *
 *  Created on: 6 oct. 2021
 *      Author: Mati
 */

#ifndef HARDCODEAR_H_INCLUDED
#define HARDCODEAR_H_INCLUDED

int idsHard[]= {1,2,3,4,5,6,7,8,9,10};
int idsMarcaHard[] = {1003,1000,1001,1002,1003,1002,1001,1002,1003,1000};
int idsViajeHard [] = { 100, 101, 103,100,104,101, 102, 100, 102,103};
int cantAsientosHard []= {2000,2900,2000,2700,2600,2000,2900,2700,2000,2600};
int matriculaHard[ ]={500,380,484,584,945,1204,6587,54821,359,1478};
int modeloHard[ ]= {1952,2000,2003,2020,2019,2020,2008,2007,2010,2014};

#endif // HARDCODEAR_H_INCLUDED



void hardcodearAviones(eAviones vec[],int cant);

/** \brief Hardcodea el vector aviones
 *
 * \param vec[] eAviones vector a hardcodear
 * \param cant int cantidad de espacio que se quiera llenar del vector
 * \return void
 *
 */

void hardcodearAviones(eAviones vec[],int cant)
{
    for(int i =0; i< cant; i++)
    {

        vec[i].idAvion =idsHard[i];
         vec[i].idMarca= idsMarcaHard [i];
        vec[i].idViaje = idsViajeHard[i];
        vec[i].cantAsientos = cantAsientosHard[i];
        vec[i].matricula = matriculaHard[i];
        vec[i].modelo = modeloHard[i];
        vec[i].isEmpty = 0;
    }
}
