#include <stdio.h>
#include <stdlib.h>

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

int dividir(int num1, int num2, float* pTotal)
{
	int ret=0;
	if(pTotal!=NULL)
	{
		if(num2!=0)
		{
			*pTotal=num1/(float)num2;
			ret=1;
		}
	}
	return ret;
}

int factorial(int n, long int* pTotal)
{
	long int aux;
	int i;
	int ret=0;

	aux=n;

	if(pTotal!=NULL)
	{
		if(n==1 || n==0)
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
