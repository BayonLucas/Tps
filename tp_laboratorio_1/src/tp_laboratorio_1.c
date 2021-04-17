/*
 ============================================================================
 Name        : tp_laboratorio_1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*Bayón, Lucas
 *
 * Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:
	1. Ingresar 1er operando (A=x)
	2. Ingresar 2do operando (B=y)
	3. Calcular todas las operaciones
		a) Calcular la suma (A+B)
		b) Calcular la resta (A-B)
		c) Calcular la division (A/B)
		d) Calcular la multiplicacion (A*B)
		e) Calcular el factorial (A!)
	4. Informar resultados
		a) “El resultado de A+B es: r”
		b) “El resultado de A-B es: r”
		c) “El resultado de A/B es: r” o “No es posible dividir por cero”
		d) “El resultado de A*B es: r”
		e) “El factorial de A es: r1 y El factorial de B es: r2”
	5. Salir
		• Todas las funciones matemáticas del menú se deberán realizar en una biblioteca aparte,
	que contenga las funciones para realizar las cinco operaciones.
		• En el menú deberán aparecer los valores actuales cargados en los operandos A y B
	(donde dice “x” e “y” en el ejemplo, se debe mostrar el número cargado)
		• Deberán contemplarse los casos de error (división por cero, etc)
		• Documentar todas las funciones
*/

#include <stdio.h>
#include <stdlib.h>
#include "calculos.h"
#include "utn_Validaciones.h"

int main(void) {
	setbuf(stdout, NULL);

	int menu;
	int A=0;
	int B=0;
	int FuncReturn[6];
	int rSuma;
	int rResta;
	float rDiv;
	int rMultiplic;
	long int rFact[2];
	int controlIngresoA=0;
	int controlIngresoB=0;
	int controlCalculos=0;

	do
	{
		printf("\n1. Ingresar 1er operando ---> A = %d \n",A);
		printf("2. Ingresar 2do operando ---> B = %d \n",B);
		printf("3. Calcular todas las operaciones. \n");
		printf("4. Informar resultados. \n");
		printf("5. Salir. \n");
		scanf("%d", &menu);

		switch(menu)
		{
			case 1:
				utn_getNumero(&A, "\nIngrese el primer operando: \n", "\nEl dato ingresado no es un número entero. \n", -20000, 20000, 1000);
				controlIngresoA++;
				break;
			case 2:
				utn_getNumero(&B, "\nIngrese el segundo operando: \n", "\nEl dato ingresado no es un número entero. \n", -20000, 20000, 1000);
				controlIngresoB++;
				break;
			case 3:
				if(controlIngresoA!=0 && controlIngresoB!=0)
				{
					FuncReturn[0]=sumar(A, B, &rSuma);
					FuncReturn[1]=restar(A, B, &rResta);
					FuncReturn[2]=dividir(A, B, &rDiv);
					FuncReturn[3]=multiplicar(A, B, &rMultiplic);
					FuncReturn[4]=factorial(A, &rFact[0]);
					FuncReturn[5]=factorial(B, &rFact[1]);
					printf("\nCalculos realizados. \n\n");
					controlCalculos++;
				}
				else
				{
					printf("\nPor favor, termine de ingresar los dos operandos.\n");
				}
				break;
			case 4:
				if(controlIngresoA!=0 && controlIngresoB!=0)
				{
					if(controlCalculos!=0)
					{
						if(FuncReturn[0])
						{
							printf("\nEl resultado de A+B es: %d \n", rSuma);
						}
						if(FuncReturn[1])
						{
						printf("El resultado de A-B es: %d \n", rResta);
						}
						if(FuncReturn[2])
						{
							printf("El resultado de A/B es: %.4f \n", rDiv);
						}
						else
						{
							printf("No es posible dividir por cero \n");
						}
						if(FuncReturn[3])
						{
							printf("El resultado de A*B es: %d \n", rMultiplic);
						}
						if(FuncReturn[4] || FuncReturn[5])
						{
							printf("El factorial de A es: %ld y El factorial de B es: %ld\n\n", rFact[0], rFact[1]);
						}
						controlIngresoA=0;
						controlIngresoB=0;
						A=0;
						B=0;
						controlCalculos=0;
					}
					else
					{
						printf("\nPrimero debe seleccionar la opción 3. Calcular todas las operaciones. \n");
					}
				}
				else
				{
					printf("\nPor favor, termine de ingresar los dos operandos.\n");
				}
				break;
			case 5:
				printf("Cerró la calculadora. Que tenga buen día!. \n");
				break;
			default:
				printf("\nIngrese una de las opciones posibles. \n");
				break;
		} //Fin de Switch
	} while(menu!=5); //Fin del Do while.
	return 0;
}// fin del main
