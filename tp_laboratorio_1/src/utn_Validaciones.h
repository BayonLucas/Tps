/*
 * utn_Validaciones.h
 *
 *  Created on: 17 abr. 2021
 *      Author: lucas
 */

#ifndef UTN_VALIDACIONES_H_
#define UTN_VALIDACIONES_H_

/*brief Pide un dato mediante un printf, valida que sea un número entero, en caso de que no lo sea, informa el error y pide nuevamente el dato una especificada cantidad de veces.
 * param1 recibe una dirección de memoria donde se colocara el valor del número pedido.
 * param2 recibe el texto deseado a mostrar para solicitar el ingreso del dato.
 * param3 recibe el mensaje error en caso de que lo que ingresó sea distinto al tipo de dato solicitado.
 * param4 recibe el valor minimo del dato a ingresar.
 * param5 recibe el valor maximo del dato a ingresar.
 * param6 recibe la cantidad de reintento que se le permitiran al usuario en cuestión.
 * la función retorna -1 si no funcionó. Caso contrario, retornará 0.
 */
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

#endif /* UTN_VALIDACIONES_H_ */
