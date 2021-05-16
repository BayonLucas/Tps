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

/*brief Pide un texto al usuario, lo almacena como cadena, valida y convierte el texto a numero y lo devuelve como int.
 * param1 recibe una cadena de caracteres del usuario.
 * la funcion retorna -1 si no pudo pasar a la cadena de caracteres a int con exito mediante atoi(). Retorna 0 si cumplió con exito la transformacion.
 */
int getInt(int* pResultado);

/*brief Recibe una cadena de caracteres y devuelve 1 en el caso de que el texto este compuesto solo por números.
 * param1 recibe una cadena de caracteres.
 * la funcion retorna -1 si algun caracter de la cadena no es un número. Retorna 1 si todos los caracteres son numericos.
 */
int esNumerica(char* cadena);

/*brief Pide un dato mediante un printf, valida que sea un caracter, en caso de que no lo sea, informa el error y pide nuevamente el dato una especificada cantidad de veces.
 * param1 recibe una dirección de memoria donde se colocara el valor del caracter.
 * param2 recibe el texto deseado a mostrar para solicitar el ingreso del dato.
 * param3 recibe el mensaje error en caso de que lo que ingresó sea distinto al tipo de dato solicitado.
 * param4 recibe el valor minimo del dato a ingresar.
 * param5 recibe el valor maximo del dato a ingresar.
 * param6 recibe la cantidad de reintento que se le permitiran al usuario en cuestión.
 * la función retorna -1 si no funcionó. Caso contrario, retornará 0.
 */
int utn_getChar(char* input,char mensaje[],char eMensaje[],char lowLimit,char hiLimit,int intentos);

/*brief Pide un dato mediante un printf, valida que sea un string alfabetico. En caso de que no lo sea, informa el error y pide nuevamente el dato una especificada cantidad de veces.
 * param1 recibe una dirección de memoria donde se colocara el valor del string.
 * param2 recibe el texto deseado a mostrar para solicitar el ingreso del dato.
 * param3 recibe el mensaje error en caso de que lo que ingresó sea distinto al tipo de dato solicitado.
 * param4 recibe la cantidad aproximada de caracteres que va a tener el dato solicitado.
 * param5 recibe la cantidad de reintento que se le permitiran al usuario en cuestión.
 * la función retorna -1 si no funcionó. Caso contrario, retornará 0. Retorna 1 si el dato ingresado tiene mas caracteres de los que se informó e el param4.
 */
int utn_getStringAlpha(char* input,char mensaje[],char eMensaje[],int cantAproxChar,int reintentos);

/*brief Recibe un array de caracteres y lo analiza, caracter por caracter, hasta determinar si el string recibido es totalmente alfabetico.
 *Param1 recibe el array de caracteres a analizar
 *La funcion retorna -1 si el string contiene algo que no sean letras, y retorna 0 si salió todo bien.
 */
int esPalabra(char* cadena);

/*bierf Se pide un string y se corrobora que el dato recibido tenga el formato de un cuit o cuil
 * param1 recibe una dirección de memoria donde se colocara el valor del string.
 * param2 recibe el texto deseado a mostrar para solicitar el ingreso del dato.
 * param3 recibe el mensaje error en caso de que lo que ingresó sea distinto al tipo de dato solicitado.
 * param4 recibe la cantidad de reintento que se le permitiran al usuario en cuestión.
 * la función retorna -1 si no funcionó. Caso contrario, retornará 0. Retorna 1 si el dato ingresado tiene mas caracteres de los que se informó e el param4.
 */
int utn_getCuit(char input[],char mensaje[],char eMensaje[],int reintentos);

/*brief Corrobora si un string es un posible cuit/cuil
 *param1 recibe el string a analizar
 *la funcion retorna -1 en caso de que el string no sea un posible cuit/cuil. Retorna 0 si esta todo ok
 */
int esCuit(char* cadena);

/* Ajusta la memoria que ocupa un string
 *param1 recibe una cadena de caracteres a acortar
 *param2 recibe la longitud deseada
 *la funcion retorna -1 en caso de que registre NULL respecto del array. Retorna 0 si esta todo ok.
 */
int myGets(char* cadena, int longitud);

/*brief analiza si es flotante.
 *param1 recibe la cadena de caracteres.
 *param2 recibe la longitud ideal del array
 * la funcion retorna -1 en caso de recibir NULL respecto del array. Caso contrario, recibe 0.
 */
int esFlotante(char* cadena, int longitud);

/*brief transforma una cadena de caracteres a formato float is se dan las condiciones necesarias
 *param1 recibe la direccion de memoria para la asignacion del valor ya procesado
 * la funcion retorna -1 en caso de recibir NULL respecto del array. Caso contrario, recibe 0.
 */
int getFloat(float* pResultado);

/*brief Pide al usuario un numero decimal en formato char para su validacion y respectiva asignacion por referencia.
 * param1 recibe una dirección de memoria donde se colocara el valor del flotante.
 * param2 recibe el texto deseado a mostrar para solicitar el ingreso del dato.
 * param3 recibe el mensaje error en caso de que lo que ingresó sea distinto al tipo de dato solicitado.
 * param4 recibe el valor minimo del dato a ingresar.
 * param5 recibe el valor maximo del dato a ingresar.
 * param6 recibe la cantidad de reintento que se le permitiran al usuario en cuestión.
 * la función retorna -1 si no funcionó. Caso contrario, retornará 0.
 */
int utn_getNumeroFlotante(float* pResultado,char* mensaje,char* eMensaje,float minimo,float maximo,int reintentos);

/*brief Intercambia los valores de dos strings
 * param1 recibe la direccion de uno de los strings(array de caracteres).
 * param2 recibe la direccion del otro de los strings(array de caracteres).
 * No retorna nada.
 */
void swapStrings(char* palabra1, char* palabra2);

/*brief Intercambia el valor entre 2 variables mediante punteros
 * param1 recibe la variable entera a intercambiar.
 * param2 recibe la segunda variable int a intercambiar.
 * param3 recibe la direccion de la primer variable.
 * param4 recibe la direccion de la segunda variable.
 * No retorna nada.
 */
void swapEnterosAsc(int x, int y, int* pX, int* pY);

/*brief Invierte valores entre 2 variables de tipo float
 * param1 recibe un número float para intercambiarlo por el valor de param2.
 * param2 recibe otro número float para intercambiar.
 * param3 recibe la dirección de memoria del param1.
 * param4 recibe la direccion de memoria del param2.
 * la función no tiene retorno.
 */
void swapFloatAsc(float x, float y, float* pX, float* pY);

/*brief Intectambia los valores de 2 variables de tipo char entre si
 *param1 recibe el primer caracter
 *param2 recibe el segundo caracter
 *param3 recibe la direccion de memoria del primer caracter
 *param4 recibe la direccion de memoria del segundo caracter
 *La funcion no tiene retorno
 */
void swapChar(char x, char y, char* pX, char* pY);

#endif /* UTN_VALIDACIONES_H_ */
