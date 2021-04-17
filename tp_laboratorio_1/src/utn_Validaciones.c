#include <stdio.h>
#include <stdlib.h>

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int ret;
	int num;
	while(reintentos>0)
	{
		printf(mensaje);
		if(scanf("%d",&num)==1)
		{
			if(num<=maximo && num>=minimo)
				break;
		}
		fflush(stdin);
		reintentos--;
		printf(mensajeError);
	}
	if(reintentos==0)
	{
		ret=-1;
	}
	else
	{
		ret=0;
		*pResultado = num;
	}
	return ret;
}
