#include "contribuyente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn_Validaciones.h"

void iniContribuyente(eContribuyente arrayC[], int tamContrib)
{
	int i;

	if(arrayC!=NULL && tamContrib>0)
	{
		for(i=0;i<tamContrib;i++)
		{
			arrayC[i].isEmpty=1;
		}
	}
}

int buscarLibreContribuyente(eContribuyente arrayC[], int tamContrib)
{
	int ret=-1;
	int i;

	if(arrayC!=NULL && tamContrib>0)
	{
		for(i=0;i<tamContrib;i++)
		{
			if(arrayC[i].isEmpty==1)
			{
				ret=i;
				break;
			}
		}
	}
	return ret;
}

void mostrarContribuyente(eContribuyente arrayC[], int posicion)
{

	printf("%-3d  -  %-10s  -  %-10s  -  %-15s\n",arrayC[posicion].idContribuyente,arrayC[posicion].nombre, arrayC[posicion].apellido, arrayC[posicion].cuil);
}

int listarContribuyentes(eContribuyente arrayC[], int tamContrib)
{
	int ret=-1;
	int i;

	if(arrayC!=NULL && tamContrib>0)
	{
		printf("--------------------------------------------------\n");
		printf("ID	Nombre		Apellido	 Cuil	\n");
		printf("--------------------------------------------------\n");
		for(i=0;i<tamContrib;i++)
		{
			if(arrayC[i].isEmpty==0)
			{
				mostrarContribuyente(arrayC, i);
			}
		}
		ret=0;
	}
	return ret;
}

int altaContribuyente(eContribuyente arrayC[], int tamContrib , int* contadorIDincremental)
{
	int ret=-1;
	int posicion;
	int control[5];

	if(arrayC!=NULL && tamContrib>0)
	{
		posicion=buscarLibreContribuyente(arrayC, tamContrib);
		if(posicion!=-1)
		{
			control[0]=utn_getStringAlpha(arrayC[posicion].nombre, "Ingrese el nombre del Contribuyente. \n","Error: Vuelva a ingresar el nombre",10,3);
			control[1]=utn_getStringAlpha(arrayC[posicion].apellido, "Ingrese el apellido del Contribuyente. \n","Error: Vuelva a ingresar el apellido.",10,3);
			control[2]=utn_getCuit(arrayC[posicion].cuil,"Ingrese el cuil del Contribuyente. Use guiones donde corresponda. \n","Error:  Vuelva a ingresar el CUIL. Respete los guiones.\n",3);
		}
		if(control[0]!=-1 && control[1]!=-1 && control[2]!=-1)
		{
			arrayC[posicion].isEmpty=0;
			(*contadorIDincremental)++;
			arrayC[posicion].idContribuyente=*contadorIDincremental;
			printf("\nEl ID del contribuyente dado de alta es: %d\n",arrayC[posicion].idContribuyente);
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

void bajaContrbuyente(eContribuyente arrayC[], int tamContrib)
{
	int id;
	int i;
	char respuesta;
	int auxControl;

	if(arrayC!=NULL && tamContrib>0)
	{
		listarContribuyentes(arrayC, tamContrib);
		printf("Ingrese el id del contribuyente al que desea modificar.\n");
		scanf("%d",&id);
		if(id>999 && id<1050)
		{
			for(i=0;i<tamContrib;i++)
			{
				if(id==arrayC[i].idContribuyente && arrayC[i].isEmpty==0)
				{
					auxControl=utn_getChar(&respuesta,"\nConfirma la eliminacion del contribuyente?(S o N)\n","Error: Ingrese S (para si) o N (para no).\n",'n','s',3);
					if(auxControl!=-1)
					{
						if(respuesta=='S' || respuesta=='N')
						{
						arrayC[i].isEmpty=1;
						listarContribuyentes(arrayC, tamContrib);
						break;
						}
						else
						{
							printf("\nError: al modificar datos. Vuelva a intentarlo.\n");
						}
					}
				}
			}
		}
	}
}

int modificarDato(eContribuyente arrayC[],int tamContrib)
{
	int ret=-1;
	int id;
	int opModificar;
	int i;

	if(arrayC!=NULL && tamContrib>0)
	{
		listarContribuyentes(arrayC, tamContrib);
		printf("\nIngrese el id del contribuyente al que desea modificar.\n");
		scanf("%d",&id);
		if(id>999 && id<1050)
		{
			for(i=0;i<tamContrib;i++)
			{
				if(id==arrayC[i].idContribuyente)
				{
					printf("\nQue desea modificar?\n");
					printf("1. Nombre\n");
					printf("2. Apellido\n");
					printf("3. Cuil\n\n");
					printf("4. Salir.\n\n");
					scanf("%d",&opModificar);

					switch(opModificar)
					{
						case 1: //Legajo

							utn_getStringAlpha(arrayC[i].nombre, "Ingrese el nombre del Contribuyente. \n","Error: Vuelva a ingresar el nombre",10,3);
						break;
						case 2: //Sexo
							utn_getStringAlpha(arrayC[i].apellido, "Ingrese el apellido del Contribuyente. \n","Error: Vuelva a ingresar el apellido.",10,3);
							break;
						case 3: //Edad
							utn_getCuit(arrayC[i].cuil,"Ingrese el cuil del Contribuyente. Use guiones donde corresponda. \n","Error:  Vuelva a ingresar el CUIL. Respete los guiones.\n",3);
							break;
						case 4: //Nota1
							printf("\nVolviendo al menu principal.\n");
							break;
						default:
							printf("\nIngrese alguna de las opciones dadas.\n");
							break;
					}
					ret=0;
					break;
				}
			}
		}
		listarContribuyentes(arrayC, tamContrib);
	}
	return ret;
}

void hardcodearContribuyente(eContribuyente arrayC[], int tamContrib)
{
	int i;
	char nombre[][20]={"Lucas","Aldana","Ornela","Pedro","Agustin","Matias","Gabriel","Maria","Raul","Yanina"};
	char apellido[][20]={"Lucas","Aldana","Ornela","Pedro","Agustin","Matias","Gabriel","Maria","Raul","Yanina"};
	char cuil[][20]={"20-12345678-9","33-30513028-9","33-30511212-9","33-30213028-9","20-30513028-9","40-20134848-8","53-32165498-9","20-40673980-6","15-30513028-6","33-30525875-1"};
	int idContrib[]={1000,1001,1002,1003,1004,1005,1006,1007,1008,1009};

	for(i=0;i<tamContrib;i++)
	{
		strcpy(arrayC[i].nombre, nombre[i]);
		strcpy(arrayC[i].apellido, apellido[i]);
		strcpy(arrayC[i].cuil, cuil[i]);
		arrayC[i].idContribuyente=idContrib[i];
		arrayC[i].isEmpty=0;
	}

}






