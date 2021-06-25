#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int ret=-1;
	int aux;
	char buffer[4][128];
	Employee* newEmployee=NULL;

	if(pFile!=NULL && pArrayListEmployee!=NULL)
	{
		fscanf(pFile, "%[^,], %[^,], %[^,], %[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
		do{
			aux=fscanf(pFile, "%[^,], %[^,], %[^,], %[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
			if(aux==4)
			{
				newEmployee=employee_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]);
				if(newEmployee!=NULL)
				{
					ll_add(pArrayListEmployee, (Employee*)newEmployee);
					ret=0;
				}
				else
				{
					ret=-1;
					employee_delete(newEmployee);
					break;
				}
			}
			else
			{
				ret=-1;
				employee_delete(newEmployee);
				break;
			}
		} while(!feof(pFile));
	}

    return ret;
}

int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int ret=-1;
	Employee* newEmployee;
	int cant;

	if(pFile!=NULL && pArrayListEmployee!=NULL)
	{
		do{
			newEmployee=employee_new();
			if(newEmployee!=NULL)
			{
				cant=fread(newEmployee,sizeof(Employee),1,pFile);
				if(cant==1)
				{
					if(ll_add(pArrayListEmployee, newEmployee)!=0)
					{
						ret=-1;
						break;
					}
					else
					{
						ret=0;
					}
				}
				else
				{
					employee_delete(newEmployee);
					break;
				}
			}
			else
			{
				printf("\nNo hay espacio suficiente para cargar los datos correspondientes.\n");
				ret=-1;
			}
		} while(!feof(pFile));
	}

	return ret;
}
