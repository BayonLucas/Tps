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

int sumar(int num1, int num2, int* rSuma);
int restar(int num1, int num2, int* pTotal);
int dividir(int num1, int num2, float* ptotal);
int multiplicar(int num1, int num2, int* pTotal);

int main(void) {
	setbuf(stdout, NULL);

	int menu;
	int A=0;
	int B=0;
	int FuncReturn[5];
	int rSuma;
	int rResta;
	float rDiv;
	int rMultiplic;
	//int rFact;

	do
	{
	printf("1. Ingresar 1er operando ---> A=%d \n",A);
	printf("2. Ingresar 2do operando ---> B=%d \n",B);
	printf("3. Calcular todas las operaciones. \n");
	printf("4. Informar resultados. \n");
	printf("5. Salir. \n");
	scanf("%d", &menu);

	switch(menu)
	{
		case 1:
			printf("Ingrese un número. \n");
			scanf("%d", &A);
			break;
		case 2:
			printf("Ingrese un número. \n");
			fflush(stdin);
			scanf("%d", &B);
			break;
		case 3:
			FuncReturn[0]=sumar(A, B, &rSuma);
			FuncReturn[1]=restar(A, B, &rResta);
			FuncReturn[2]=dividir(A, B, &rDiv);
			FuncReturn[3]=multiplicar(A, B, &rMultiplic);
			printf("Calculos realizados. \n");
			break;
		case 4:
			if(FuncReturn[0])
			{
				printf("El resultado de A+B es: %d \n", rSuma);
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
			if(FuncReturn[2])
			{
				printf("El resultado de A*B es: %d \n", rMultiplic);
			}
			break;
		case 5:
			printf("Cerró la calculadora. \n");
			break;
		default:
			printf("Ingrese una de las opciones dadas. \n");
			break;
	}

	} while(menu!=5); //Fin del Do while.
	return 0;
}// fin del main



int sumar(int num1, int num2, int* pTotal)
{
	int ret=0;
	if(pTotal!=NULL)
	{
		if(num1>0 || num2>0)
		{
			*pTotal=num1+num2;
			ret=1;
		}
	}
	return ret;
}
int restar(int num1, int num2, int* pTotal)
{
	int ret=0;
	if(pTotal!=NULL)
	{
		if(num1>0 || num2>0)
		{
			*pTotal=num1-num2;
			ret=1;
		}
	}
	return ret;
}
int dividir(int num1, int num2, float* pTotal)
{
	int ret=0;
	if(pTotal!=NULL)
	{
		if(num2!=0)
		{
			*pTotal=num1/num2;
			ret=1;
		}
	}
	return ret;
}
int multiplicar(int num1, int num2, int* pTotal)
{
	int ret=0;
	if(pTotal!=NULL)
	{
		if(num1>0 || num2>0)
		{
			*pTotal=num1*num2;
			ret=1;
		}
	}
	return ret;
}
