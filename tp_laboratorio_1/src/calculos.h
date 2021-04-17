/*
 * calculos.h
 *
 *  Created on: 16 abr. 2021
 *      Author: lucas
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_

/*brief Calcula la suma de 2 enteros y pasa el resultado a través de un puntero.
 * param1 recibe un numero entero para sumar.
 * param2 recibe otro numero entero para sumar.
 * param2 recibe una dirección de memoria donde se depositará el resultado de la suma.
 * la función retorna 0 si no funcionó. Caso contrario, retornará 1.
 * */
int sumar(int num1, int num2, int* pTotal);

/*brief Calcula la resta de 2 enteros y pasa el resultado a través de un puntero.
 * param1 recibe un numero entero para restar.
 * param2 recibe otro numero entero para restar.
 * param2 recibe una dirección de memoria donde se depositará el resultado de la resta.
 * la función retorna 0 si no funcionó. Caso contrario, retornará 1.
 * */
int restar(int num1, int num2, int* pTotal);

/*brief Calcula el producto de 2 enteros y pasa el resultado a través de un puntero.
 * param1 recibe un numero entero para multiplicar.
 * param2 recibe otro numero entero para multiplicar.
 * param2 recibe una dirección de memoria donde se depositará el resultado de la multiplicación.
 * la función retorna 0 si no funcionó. Caso contrario, retornará 1.
 * */
int multiplicar(int num1, int num2, int* pTotal);

/*brief Calcula la división de 2 enteros y pasa el resultado a través de un puntero.
 * param1 recibe un numero entero para dividendo.
 * param2 recibe otro numero entero casteado a float para divisor.
 * param2 recibe una dirección de memoria donde se depositará el resultado de la división.
 * la función retorna 0 si no funcionó. Caso contrario, retornará 1.
 * */
int dividir(int num1, int num2, float* ptotal);

/*brief Calcula el factorial (n!) de un entero y pasa el resultado a través de un puntero.
 * param1 recibe un numero entero para factorear..
 * param2 recibe una dirección de memoria donde se depositará el resultado del factoreo.
 * la función retorna 0 si no funcionó. Caso contrario, retornará 1.
 * */
long int factorial(int n, long int* pTotal);

#endif /* CALCULOS_H_ */
