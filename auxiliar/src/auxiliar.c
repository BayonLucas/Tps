/*
 ============================================================================
 Name        : auxiliar.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

long int factorial(int n, long int* pTotal);

int main(void) {
	setbuf(stdout, NULL);

	int n1=10;
	long int tFact;
	int retorno;

	printf("el num1: %d\n", n1);

	retorno=factorial(n1, &tFact);
	if(retorno)
		printf("\nEl total es: %ld",tFact);

	return EXIT_SUCCESS;
}

long int factorial(int n, long int* pTotal)
{
	long int aux;
	int i;
	int ret=0;

	aux=n;

	if(pTotal!=NULL)
	{
		if(n==1)
		{
			aux=1;
		}
		else
		{
			for(i=n;i>1;i--)
			{
				aux=aux*(i-1);
			}
			ret=1;
		}
	}
	*pTotal=aux;

	return ret;
}
