/*
 * recaudacion.h
 *
 *  Created on: 13 may. 2021
 *      Author: lucas
 */

#ifndef RECAUDACION_H_
#define RECAUDACION_H_

#include "contribuyente.h"


typedef struct{
	int idContribuyente;
	char mes[15];
	int tipo;
	int idRecaudacion;
	int situacion;
	float importe;
	int isEmpty;
} eRecaudacion;

/*brief Inicializa el array de tipo eRecaudacion
 *param1 recibe el array en cuestio.
 *param2 recibe el tamaño del array
 *la funcion no retorna nada.
 */
void iniRecaudacion(eRecaudacion arrayR[], int tamRecaudacion);

/* la funcion busca un espacio libre en el array de tipo eRecaudacion
 *param1 recibe el array en cuestio.
 *param2 recibe el tamaño del array
 *la funcion retorna -1 en caso de no encontrar un esoacio libre. Caso contrario retorna la posicion libre.
 */
int buscarLibreRecaudacion(eRecaudacion arrayR[], int tamRecaudacion);

/*
 *
 */
int tipoRecaudacion(char* tipoR, eRecaudacion arrayR[],int posicion);

/*
 *
 */
void mostrarRecaudacion(eRecaudacion arrayR[], int posicion);

/*
 *
 */
int listarRecaudacion(eRecaudacion arrayR[], int tamRecaudacion);

/*
 *
 */
int altaRecaudacion(eRecaudacion arrayR[], int tamRecaudacion,eContribuyente arrayC[], int tamContrib ,int* contadorIDincremental);
#endif /* RECAUDACION_H_ */
