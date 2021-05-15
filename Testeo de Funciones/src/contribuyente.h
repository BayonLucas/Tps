/*
 * contribuyente.h
 *
 *  Created on: 13 may. 2021
 *      Author: lucas
 */

#ifndef CONTRIBUYENTE_H_
#define CONTRIBUYENTE_H_

typedef struct{
	char nombre[10];
	char apellido[10];
	char cuil[14];
	int idContribuyente;
	int isEmpty;
} eContribuyente;

/*brief Inicializa el array de tipo eContribuyente
 *param1 recibe el array en cuestio.
 *param2 recibe el tamaño del array
 *la funcion no retorna nada.
 */
void iniContribuyente(eContribuyente arrayC[], int tamContrib);

/* la funcion busca un espacio libre en el array de tipo eContribuyente
 *param1 recibe el array en cuestio.
 *param2 recibe el tamaño del array
 *la funcion retorna -1 en caso de no encontrar un esoacio libre. Caso contrario retorna la posicion libre.
 */
int buscarLibreContribuyente(eContribuyente arrayC[], int tamContrib);

/*
 *
 */
void mostrarContribuyente(eContribuyente arrayC[], int posicion);

/*
 *
 */
int listarContribuyentes(eContribuyente arrayC[], int tamContrib);

/*
 *
 */
int altaContribuyente(eContribuyente arrayC[], int tamContrib , int* contadorIDincremental);

/*
 *
 */
void bajaContrbuyente(eContribuyente arrayC[], int tamContrib);

/*
 *
 */
int modificarDato(eContribuyente arrayC[],int tamContrib);



/*
 *
 */
void hardcodearContribuyente(eContribuyente arrayC[], int tamContrib);

#endif /* CONTRIBUYENTE_H_ */
