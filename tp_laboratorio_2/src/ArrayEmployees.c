#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn_Validaciones.h"
#include "ArrayEmployees.h"


int initEmployees(Employee list[], int len)
{
	int ret=-1;
	int i;

	if(list!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			list[i].isEmpty=1;
		}
		ret=0;
	}
	return ret;
}

int altaEmployee(Employee list[], int len, int* IncresCount)
{
	int ret=-1;
	int control[6];
	char name[15];
	char lastName[15];
	float salary;
	int sector;
	int auxPos;

	if(list!=NULL && len>0)
	{
		auxPos=searchFreeEmployee(list, len);
		if(auxPos!=-1)
		{
			control[0]=utn_getStringAlpha(name,"Ingrese el nombre del Empleado\n","Error: Vuelva a ingresar el nombre. Use caracteres alfabeticos.\n",15,3);
			control[1]=utn_getStringAlpha(lastName,"Ingrese el apellido del Empleado\n","Error: Vuelva a ingresar el apellido. Use caracteres alfabeticos.\n",15,3);
			control[2]=utn_getNumeroFlotante(&salary,"Ingrese el salario del Empleado.\n","Error: Ingrese una cifra mayor a 0.\n",1,100000,3);
			control[3]=utn_getNumero(&sector,"Ingrese una de las siguientes opciones de sector:\n1. RRHH\n2. Cobranzas\n3. Marketing\n4. Desarrollo\n","Error: Ingrese alguna de las opciones dadas.\n",1,4,3);
			if(control[0]!=-1 && control[1]!=-1 && control[2]!=-1 && control[3]!=-1)
			{
				addEmployee(list,len,IncresCount,name,lastName,salary,sector, auxPos);
				list[auxPos].isEmpty=0;
				printf("\nEl id del empleado dado de alta es: %d\n\n", list[auxPos].id);
				ret=0;
			}
			else
			{
				printf("\nError al ingresar datos. Vuelva a intentarlo.\n");
			}
		}
		else
		{
			printf("\nNo se encontraron espacios disponibles para cargar a otro empleado.\n");
		}
	}
	return ret;
}

int addEmployee(Employee list[], int len, int* id, char name[], char lastName[], float salary, int sector, int posicion)
{
	int ret=-1;

	(*id)++;
	strcpy(list[posicion].name,name);
	strcpy(list[posicion].lastName,lastName);
	list[posicion].salary=salary;
	list[posicion].sector=sector;
	list[posicion].id=*id;
	ret=0;

	return ret;
}

int searchFreeEmployee(Employee list[], int len)
{
	int ret=-1;
	int i;

	if(list!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty==1)
			{
				ret=i;
				break;
			}
		}
	}
	return ret;
}

int findEmployeeById(Employee list[], int len,int id)
{
	int ret=-1;
	int i;

	if(list!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty==0 && list[i].id==id)
			{
				ret=i;
				break;
			}
		}
	}
	return ret;
}

int removeEmployee(Employee list[], int len)
{
	int ret=-1;
	int i;
	int id;

	if(list!=NULL && len>0)
	{
		printEmployees(list, len);
		printf("\nIngrese el id del empleado a dar de baja.\n\n");
		scanf("%d",&id);

		i=findEmployeeById(list, len, id);

		if(list[i].isEmpty==0)
		{
			list[i].isEmpty=1;
			ret=0;

			printEmployees(list, len);
		}
		else
		{
			printf("\nEl id no es valido o pertenece a un empleado ya dado de baja anteriormente.\n");
		}
	}
	return ret;
}

int printEmployees(Employee list[], int length)
{
	int ret=-1;
	int i;

	if(list!=NULL && length>0)
	{
		printf("-------------------------------------------------------------------------\n");
		printf("ID	Apellido		Nombre		Sueldo		Sector	\n");
		printf("-------------------------------------------------------------------------\n");
		for(i=0;i<length;i++)
		{
			if(list[i].isEmpty==0)
			{
				printEmployee(list, i);
			}
		}
		ret=0;
	}
	return ret;
}

void printEmployee(Employee list[], int i)
{
	char auxSector[15];

	findSectorById(auxSector, list,i);
	printf("%-3d  -  %-15s  -  %-15s  -  %.2f  -  %-15s\n", list[i].id, list[i].lastName,list[i].name, list[i].salary, auxSector);
}

void findSectorById(char* tipoR, Employee list[],int posicion)
{

	if(list!=NULL)
	{
		if(list[posicion].isEmpty==0)
		{
			switch(list[posicion].sector)
			{
				case 1:
					strcpy(tipoR, "RRHH");
					break;
				case 2:
					strcpy(tipoR, "Cobranzas");
					break;
				case 3:
					strcpy(tipoR, "Marketing");
					break;
				case 4:
					strcpy(tipoR, "Desarrollo");
					break;
				default:
					break;
			}
		}
	}
}

int modifyData(Employee list[],int len)
{
	int ret=-1;
	int id;
	int opModificar;
	int i;

	if(list!=NULL && len>0)
	{
		printEmployees(list, len);
		printf("\nIngrese el id del empleado a modificar.\n\n");
		scanf("%d",&id);

		i=findEmployeeById(list, len, id);

		if(list[i].isEmpty==0)
		{
			printf("\nQue desea modificar?\n");
			printf("1. Nombre\n");
			printf("2. Apellido\n");
			printf("3. Salario\n");
			printf("4. Sector.\n\n");
			printf("5. Salir.\n\n");
			scanf("%d",&opModificar);

			switch(opModificar)
			{
				case 1: //nombre
					utn_getStringAlpha(list[i].name, "Ingrese el nuevo nombre del Empleado. \n","Error: Vuelva a ingresar el nombre",15,3);
				break;
				case 2: //apellido
					utn_getStringAlpha(list[i].lastName, "Ingrese el nuevo apellido del Empleado. \n","Error: Vuelva a ingresar el apellido.",15,3);
					break;
				case 3: //salario
					utn_getNumeroFlotante(&list[i].salary,"Ingrese el nuevo salario del Empleado.\n","Error: Ingrese una cifra mayor a 0.\n",1,100000,3);
					break;
				case 4: //sector
					utn_getNumero(&list[i].sector,"Ingrese el nuevo sector al que pertenece el empleado:\n1. RRHH\n2. Cobranzas\n3. Marketing\n4. Desarrollo\n","Error: Ingrese alguna de las opciones dadas.\n",1,4,3);
					break;
				case 5: //Salir
					printf("\nVolviendo al menu principal.\n");
					break;
				default:
					printf("\nIngrese alguna de las opciones dadas.\n");
					break;
			}
			ret=0;
			printEmployees(list, len);
		}
		else
		{
			printf("\nEl id no es valido o pertenece a un empleado ya dado de baja anteriormente.\n");
		}
	}
	return ret;
}

int sortEmployeeAlphabetic(Employee list[],int len)
{
	int ret=-1;
	int order;
	//int auxCtrl;

	if(list!=NULL && len>0)
	{
		printf("\nIngrese el orden que desee para el informe:\n");
		printf("1. Ascendente\n");
		printf("2. Descendente\n");
		scanf("%d",&order);

		if(order==1 || order==2)
		{
			//printf("\n%d\n",order);
			sortEmployees(list, len, order);
			printEmployees(list, len);
			ret=0;
		}
		else
		{
			printf("\nError al ingresar el orden. Vuelva a intentarlo.\n");
		}
	}
 return ret;
}

int sortEmployees(Employee list[], int len, int order)
{
	int ret=-1;
	int i;
	int j;

	if(list!=NULL && len>0)
	{
		switch(order)
		{
		case 1:
			for(i=0;i<(len-1);i++)
			{
				if(list[i].isEmpty==0)
				{
					for(j=i+1;j<len;j++)
					{
						if(list[i].isEmpty==0)
						{
							if(strcmp(list[i].lastName,list[j].lastName)>0)
							{
								swapEnterosAsc(list[i].id, list[j].id, &list[i].id, &list[j].id);
								swapStrings(list[i].lastName, list[j].lastName);
								swapStrings(list[i].name, list[j].name);
								swapFloatAsc(list[i].salary, list[j].salary, &list[i].salary, &list[j].salary);
								swapEnterosAsc(list[i].sector, list[j].sector, &list[i].sector, &list[j].sector);
							}
							else
							{
								if(strcmp(list[i].lastName,list[j].lastName)==0 && list[i].sector>list[j].sector)
								{
									swapEnterosAsc(list[i].id, list[j].id, &list[i].id, &list[j].id);
									swapStrings(list[i].lastName, list[j].lastName);
									swapStrings(list[i].name, list[j].name);
									swapFloatAsc(list[i].salary, list[j].salary, &list[i].salary, &list[j].salary);
									swapEnterosAsc(list[i].sector, list[j].sector, &list[i].sector, &list[j].sector);
								}
							}
						}
					}
				}
			}
			break;
		case 2:
			for(i=0;i<(len-1);i++)
			{
				if(list[i].isEmpty==0)
				{
					for(j=i+1;j<len;j++)
					{
						if(list[i].isEmpty==0)
						{
							if(strcmp(list[i].lastName,list[j].lastName)<0)
							{
								swapEnterosAsc(list[i].id, list[j].id, &list[i].id, &list[j].id);
								swapStrings(list[i].lastName, list[j].lastName);
								swapStrings(list[i].name, list[j].name);
								swapFloatAsc(list[i].salary, list[j].salary, &list[i].salary, &list[j].salary);
								swapEnterosAsc(list[i].sector, list[j].sector, &list[i].sector, &list[j].sector);
								ret=0;
							}
							else
							{
								if(strcmp(list[i].lastName,list[j].lastName)==0 && list[i].sector<list[j].sector)
								{
									swapEnterosAsc(list[i].id, list[j].id, &list[i].id, &list[j].id);
									swapStrings(list[i].lastName, list[j].lastName);
									swapStrings(list[i].name, list[j].name);
									swapFloatAsc(list[i].salary, list[j].salary, &list[i].salary, &list[j].salary);
									swapEnterosAsc(list[i].sector, list[j].sector, &list[i].sector, &list[j].sector);
									ret=0;
								}
							}
						}
					}
				}
			}
			break;
		default:
			printf("El orden ingresado no es válido. Ingrese 1 ");
			break;
		}
	}

	return ret;
}

void hardcodearEmployee(Employee list[], int len, int* firstAdd)
{
	int i;
	char nombre[][20]={"Lucas","Aldana","Ornela","Pedro","Agustin","Matias","Gabriel","Maria","Raul","Yanina"};
	char apellido[][20]={"Bayon","Coronel","Perez","Rofuiguez","Suares","Messi","Bayon","Ordoñes","Felfort","Coronel"};
	float salary[]={12500.23, 25345.58, 31252.2, 20000, 31252.2, 18005.99, 28300.20, 16999.99, 27654.3, 30000};
	int sector[]={1, 4, 3, 1, 3, 3, 2, 2, 4, 3};
	int id[]={1,2,3,4,5,6,7,8,9,10};

	for(i=0;i<len;i++)
	{
		strcpy(list[i].name, nombre[i]);
		strcpy(list[i].lastName, apellido[i]);
		list[i].id=id[i];
		list[i].sector=sector[i];
		list[i].salary=salary[i];
		list[i].isEmpty=0;
	}
	*firstAdd=1;
}


