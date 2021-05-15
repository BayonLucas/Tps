/*
 ============================================================================
 Name        : 6.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	setbuf(stdout, NULL);
//------------------------------------------------------------------------------------------------------------------------------------------------------------

	//Caracteres y Cadenas de Caracteres

	char texto[5]={"Juan"};
    char texto[]="Nona mama";
    char conjuntoCaracteres[]={'N','o','n','a'};
    char caracteres[]={'N','o','n','a',' ','m','a','\0'};

    //Cuenta un caracter de mas
    printf("Texto:%s Tamanio: %d \n", texto, sizeof(texto));
    printf("Longitud de la cadena= %d \n", strlen(texto));

    //Imprime cualquier cosa, printf no sabe donde termina porque no encuentra el \0
    printf("\nConjuntoCaracteres:%s Tamanio: %d \n", conjuntoCaracteres, sizeof(conjuntoCaracteres));
    printf("Longitud de la cadena= %d \n", strlen(conjuntoCaracteres));

    //Ok
    printf("\ncaracteres:%s Tamanio: %d \n", caracteres, sizeof(caracteres));
    printf("Longitud de la cadena= %d \n", strlen(caracteres));

    char texto1[20], texto2[20], texto3[30];

    printf("ingrese texto 1: \n"); //Ingresar Mamma Mia
    fflush(stdin);
    scanf("%s", texto1); //Scanf donde encuentra un espacio, termina!
    printf("ingresaste: %s \n", texto1);

    printf("\ningrese texto 2: \n"); //Ingresar Mamma Mia
    fflush(stdin);
    gets(texto2); //Hace lo mismo q el "scanf" pero no necesita el ingreso de formato porq sabe q es una cadena de caracteres (Espera un puntero de tipo caracter).
    printf("ingresaste: %s \n", texto2);

    printf("\ningrese texto 3: \n"); //Ingresar Mamma Mia
    fgets (texto3, 30, stdin); //Esta funcion en realidad es para archivos. Toma la variablea la cual se le asigna el valor, el tamaño de array de caracteres, y de donde los toma(aca se pone stdin para q lo tome del teclado)
    printf("ingresaste: %s \n \n", texto3);

    //fgets guarda un caracter menos del que declare(porque guarda el \0).
    //Si ingreso un valor mayor a 5 en nombre, desborda la memoria, y sigue escribiendo en la variable edad

    char nombre[5];
	int edad= 34;

	printf("Ingrese nombre:");
	fflush(stdin);
	gets(nombre);
	printf("%s  %d\n", nombre, edad);

	/*Validacion de cantidad de caracteres para sar gets*/
	char nombre[6];
	char auxCad[10];

	printf("Ingrese un nombre: ");
	fflush(stdin);
	gets(auxCad);

	while(strlen(auxCad) >=6)
	{
		printf("Nombre demasiado largo. Reingrese nombre: ");
		fflush(stdin);
		gets(auxCad);
	}

	strcpy(nombre, auxCad);
	printf("\nSu nombre es: %s", nombre);

//--------------------------------------------------------------------------------------------------------------------------------------

    //FUNCIONES CON CARACTERES - #include <stdlib.h>
    // atoi()/atol()//atof

//--------------------------------------------------------------------------------------------------------------------------------------

	//atoi() - Convierte un string a un número. La conversión se detiene en cuanto se encuentra un carácter no aceptable. Si no se puede convertir la cadena, devuelve 0.

	char letras[] = "123";//"12.3" // "AAA"
    int numeroentero;

    numeroentero = atoi(letras);
    printf("Texto convertido en numeroentero %d \n", numeroentero);

    long numerolong;
    numerolong = atol(letras);
    printf("Texto convertido en numerolong %ld \n", numerolong);

    float numerodecimal;
    numerodecimal = atof(letras);
    printf("Texto convertido en numerodecimal %.2f \n", numerodecimal);

//--------------------------------------------------------------------------------------------------------------------------------------

    // itoa() - Convierte un número a una cadena de texto. La cadena contendrá tantos carácteres como dígitos tenga el resultado.
    //El parámetro base especifica la base utilizada para convertir el valor, esta deberá ser entre 2 y 36, inclusive.

    int numero=1234;
    char cadena[20];

    itoa(numero, cadena, 10);

    printf("Numero convertido en texto %s \n", cadena);

//--------------------------------------------------------------------------------------------------------------------------------------
#include <ctype.h>

    //islower() - Comprueba sin un carácter es de tipo minúscula. Verifica si pertenece al rango de caracteres de letras minúsculas, que por defecto son los que están en el rango 'a' a 'z'.
    //El valor de retorno será NO nulo si es un carácter en minúscula.

    char letra;
    letra='t';

    printf("Letra %c islower(): %d", letra, islower(letra));
    letra='D';

    printf("\nLetra %c islower(): %d", letra, islower(letra));
    letra = 'F';

    if (islower(letra)==0){
        printf("\n NO es minuscula");
    }
    else
    {
        printf("\n ES minuscula");
    }

//--------------------------------------------------------------------------------------------------------------------------------------

    //isupper() - Comprueba sin un carácter es de tipo MAYUSCULAS.

    char letra1;
    letra1='t';

    printf("\nLetra1 %c isupper(): %d", letra1, isupper(letra1));
    letra1='D';

    printf("\nLetra1 %c isupper(): %d", letra1, isupper(letra1));
    letra1 = 'F';

    if (isupper(letra1)==0){
        printf("\n NO es mayuscula");
    }
    else
    {
        printf("\n ES mayuscula");
    }

//--------------------------------------------------------------------------------------------------------------------------------------

    //isdigit() - Indica si un carácter es numérico. Valor devuelto: Verdadero (!=0) o falso (0). Devuelve "verdadero" (un valor distinto de cero) si el carácter es numérico (0 a 9)

    char valor1;
    valor1='5';

    printf("\n\nLetra2 %c isdigit(): %d", valor1, isdigit(valor1));
    if (isdigit(valor1)==0){
        printf("\n NO es un numero");
    }
    else
    {
        printf("\n ES un numero ");
    }

//--------------------------------------------------------------------------------------------------------------------------------------

   //isalpha() - Comprueba sin un carácter es alfabético. Verifica si pertenece al rango de letras (A a Z o a a z).

    char letra2 = '9';

    printf("\n\nletra2 %c isalpha(): %d", letra2, isalpha(letra2));
    if (isalpha(letra2)==0){
        printf("\n NO es un caracter alfabetico \n\n");
    }
    else
    {
        printf("\n ES un caracter alfabetico \n\n");
    }

//--------------------------------------------------------------------------------------------------------------------------------------

    //tolower() - Convierte un caracter a minuscula

    char caracter= 'A';
    char convertido;

    printf("\nCaracter A = %c ", caracter);
    convertido = tolower(caracter);
    printf("\nCaracter Convertido  = %c ", convertido);

//--------------------------------------------------------------------------------------------------------------------------------------

    //toupper() - Convierte un caracter a mayuscula

    char caracter1= 'b';
    char convertido1;

    printf("\nCaracter b = %c ", caracter1);
    convertido1 = toupper(caracter1);
    printf("\nCaracter Convertido  = %c ", convertido1);

//--------------------------------------------------------------------------------------------------------------------------------------
    //FUNCIONES CON CADENAS DE CARACTERES #include<string.h>

    //strlen()-strcpy()-strncpy()-strcat()-strcmp()-stricmp()-strlwr()-strupr(cadena)

//--------------------------------------------------------------------------------------------------------------------------------------

    //strlen() = Devuelve la longitud del string pasado por argumento. No cuenta el último caracter que marca \0

    char palabra[15]="Programa en C";

    printf("\nCantidad de caracteres de palabra: %d ", strlen(palabra));

//--------------------------------------------------------------------------------------------------------------------------------------

    //strcpy(destino, origen) = Copia una cadena de caracteres a otra

    char cadOrigen[10]="Primero E";
    char cadDestino[10];

    printf("\n Cadena origen: %s ", cadOrigen);
    strcpy(cadDestino, cadOrigen);

    printf("\n Cadena destino: %s ", cadDestino);

//--------------------------------------------------------------------------------------------------------------------------------------

    //strncpy(destino, origen, n) = Copia una n cantidad de caracteres de 1 cadena a otra

    char cadOrigen[10]="Primero E";
    char cadDestino[10];

    printf("\n Cadena origen: %s ", cadOrigen);
    strncpy(cadDestino, cadOrigen, 2);

    printf("\n Cadena destino: %s ", cadDestino);

//--------------------------------------------------------------------------------------------------------------------------------------

    //strcat(destino, origen) = concatena 2 string

    char nombre[12]="Juan";
    char apellido[12]= "Perez";

    printf("\n\n Nombre: %s ", nombre);
    printf("\n Apellido: %s ", apellido);

    strcat(nombre," ");
    strcat(nombre, apellido);

    printf("\n\n Nombre: %s ", nombre);

//--------------------------------------------------------------------------------------------------------------------------------------

    //strcmp()= Compara 2 cadenas de caracter incluyendo mayusculas y minusculas

    	//strcmp(cadena1, cadena2)- Devuelve un numero entero
    	//devuelve 0 = Si las cadenas son iguales
    	//devuelve >0 = Si cadena1 > cadena2
    	//devuelve <0 = Si cadena1 < cadena2
    	//la mayuscula esta antes en el codigo ascii, es menor

    char cadena1[10]="boa";//"cao";//"caz";//"caA";//"boa";
    char cadena2[10]="cao";//"boa";//"caa";//"caa";//"CAO";
    int res;

    printf("\nCadena 1 %s ", cadena1);
    printf("\nCadena 2 %s ", cadena2);

    res = strcmp(cadena1,cadena2);

    printf("\n \n Resultado Comparacion %d ", res);
    if (res == 0)
    {
        printf("\nAmbas cadenas son iguales");
    }
        if (res > 0)
    {
        printf("\n Cadena1:%s es mayor a Cadena 2:%s ", cadena1, cadena2);
    }
        if (res < 0)
    {
        printf("\n Cadena2:%s es mayor a Cadena 1:%s \n\n", cadena2, cadena1);
    }

    //Sin variable res
    if ((strcmp(cadena1,cadena2))==0)
    {
        printf("\nAmbas cadenas son iguales");
    }
    else
    {
    	if((strcmp(cadena1,cadena2))>0)
        {
        printf("\n Cadena1:%s es mayor a Cadena 2:%s ", cadena1, cadena2);
        }
    	else
        {
    		printf("\n Cadena2:%s es mayor a Cadena 1:%s \n\n", cadena2, cadena1);
        }
    }

//--------------------------------------------------------------------------------------------------------------------------------------

    //strlwr(cadena); pasa una cadena a minuscula
    //strupr(cadena); pasa una cadena a mayuscula
}
