#include "recaudacion.h"
#include "contribuyente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn_Validaciones.h"

void iniRecaudacion(eRecaudacion arrayR[], int tamRecaudacion)
{
	int i;

	if(arrayR!=NULL && tamRecaudacion>0)
	{
		for(i=0;i<tamRecaudacion;i++)
		{
			arrayR[i].isEmpty=1;
		}
	}
}

int buscarLibreRecaudacion(eRecaudacion arrayR[], int tamRecaudacion)
{
	int ret=-1;
	int i;

	if(arrayR!=NULL && tamRecaudacion>0)
	{
		for(i=0;i<tamRecaudacion;i++)
		{
			if(arrayR[i].isEmpty==1)
			{
				ret=i;
				break;
			}
		}
	}
	return ret;
}

int tipoRecaudacion(char* tipoR, eRecaudacion arrayR[],int posicion)
{
	int ret;

	if(arrayR!=NULL)
	{
		if(arrayR[posicion].isEmpty==0)
		{
			ret=0;
			switch(arrayR[posicion].tipo)
			{
				case 1:
					strcpy(tipoR, "ARBA");
					break;
				case 2:
					strcpy(tipoR, "IIBB");
					break;
				case 3:
					strcpy(tipoR, "Ganancias");
					break;
				default:
					ret=-1;
					break;
			}
		}
	}
	return ret;
}

int sitRecaudacion(char* tipoR, eRecaudacion arrayR[],int posicion)
{
	int ret;

	if(arrayR!=NULL)
	{
		if(arrayR[posicion].isEmpty==0)
		{
			ret=0;
			switch(arrayR[posicion].situacion)
			{
				case 1:
					strcpy(tipoR, "Aduedado");
					break;
				case 2:
					strcpy(tipoR, "Refinanciado");
					break;
				case 3:
					strcpy(tipoR, "Saldado");
					break;
				default:
					ret=-1;
					break;
			}
		}
	}
	return ret;
}

void mostrarRecaudacion(eRecaudacion arrayR[], int posicion)
{
	char auxTipo[11];

	tipoRecaudacion(auxTipo,arrayR,posicion);

	printf("%-3d  -  %-15s  -  %-15s  -  %-3d\n",arrayR[posicion].idRecaudacion,auxTipo, arrayR[posicion].mes, arrayR[posicion].idContribuyente);
}

int listarRecaudacion(eRecaudacion arrayR[], int tamRecaudacion)
{
	int ret=-1;
	int i;

	if(arrayR!=NULL && tamRecaudacion>0)
	{
		printf("--------------------------------------------------\n");
		printf("ID Rec. -	Tipo -	Mes	- id Contrib.	\n");
		printf("--------------------------------------------------\n");
		for(i=0;i<tamRecaudacion;i++)
		{
			if(arrayR[i].isEmpty==0)
			{
				mostrarRecaudacion(arrayR, i);
			}
		}
		ret=0;
	}
	return ret;
}

int altaRecaudacion(eRecaudacion arrayR[], int tamRecaudacion, eContribuyente arrayC[],  int tamContrib, int* contadorIDincremental)
{
	int ret=-1;
	int posicion;
	int control[4];

	if(arrayR!=NULL && tamRecaudacion>0 && arrayC!=NULL && tamContrib>0)
	{
		posicion=buscarLibreRecaudacion(arrayR, tamRecaudacion);
		if(posicion!=-1)
		{
			listarContribuyentes(arrayC,tamContrib);
			control[1]=utn_getStringAlpha(arrayR[posicion].mes, "Escriba el nombre del mes de la recaudacion. \n","\nError: Vuelva a ingresar el mes.\n",15,3);
			control[0]=utn_getNumero(&arrayR[posicion].idContribuyente,"\nIngrese el id del contribuyente relacionado con la recaudacion.\n","\nError: Ingrese un id válido.\n",999,1100,3);
			control[2]=utn_getNumero(&arrayR[posicion].tipo,"\nIngrese el tipo:\n 1. ARBA\n 2. IIBB\n 3. Ganancias\n","\nError: Ingrese una de las opciones dadas.\n",1,3,3);
			control[3]=utn_getNumero(&arrayR[posicion].situacion,"\nIngrese el tipo:\n 1. Adeudado\n 2. Refinanciado\n 3. Saldado\n","\nError: Ingrese una de las opciones dadas.\n",1,3,3);
			control[4]=utn_getNumeroFlotante(&arrayR[posicion].importe,"Ingrese el importe de la recaudacion","Error: ingrese un numero valido",100,100000,3);
		}
		if(control[0]!=-1 && control[1]!=-1 && control[2]!=-1 && control[3]!=-1 && control[4]!=-1)
		{
			arrayR[posicion].isEmpty=0;
			(*contadorIDincremental)++;
			arrayR[posicion].idRecaudacion=*contadorIDincremental;
			printf("\nEl ID de la recaudacion dada de alta es: %d\n",arrayR[posicion].idRecaudacion);
			ret=0;
		}
		else
		{
			printf("Error al ingresar datos.\n\n");
		}
	}
	else
	{
		printf("\nNo hay mas espacios donde cargar datos.\n");
	}

	return ret;
}
