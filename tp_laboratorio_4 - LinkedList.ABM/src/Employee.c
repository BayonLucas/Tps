#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Employee.h"

Employee* employee_new()
{
	Employee* newEmployee=NULL;
	newEmployee=malloc(sizeof(Employee));

	if(newEmployee!=NULL)
	{
		newEmployee->id=0;
		strcpy(newEmployee->nombre," ");
		newEmployee->horasTrabajadas=0;
		newEmployee->sueldo=0;
	}

	return newEmployee;
}

Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr)
{
	Employee* newEmployee=employee_new();
	int auxId;
	int auxHoras;
	int auxSueldo;

	if(newEmployee!=NULL)
	{
		auxId=atoi(idStr);
		auxHoras=atoi(horasTrabajadasStr);
		auxSueldo=atoi(sueldoStr);

		if((employee_setId(newEmployee, auxId)==-1) ||
			(employee_setNombre(newEmployee, nombreStr)==-1) ||
			(employee_setHorasTrabajadas(newEmployee, auxHoras)==-1) ||
			(employee_setSueldo(newEmployee, auxSueldo)==-1))
		{
			free(newEmployee);
			newEmployee=NULL;
		}
	}

	return newEmployee;
}

void employee_delete(Employee* this)
{
	free(this);
}

int employee_setId(Employee* this,int id)
{
    int ret=-1;
    if(this!=NULL && id>0)
    {
    	this->id = id;
        ret=0;
    }
    return ret;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int ret=-1;
    if(this != NULL && nombre != NULL )
    {
        strcpy(this->nombre, nombre);
        ret=0;
    }
    return ret;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int ret=-1;
    if(this != NULL)
    {
    	this->horasTrabajadas = horasTrabajadas;
        ret=0;
    }
    return ret;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	int ret=-1;
	if(this != NULL && sueldo > 0)
    {
		this->sueldo = sueldo;
        ret=0;
    }
    return ret;
}

int employee_getId(Employee* this,int* id)
{
	int ret=-1;

	if(this!=NULL && id!=NULL)
	{
		*id=this->id;
		ret=0;
	}
	return ret;
}

int employee_getNombre(Employee* this,char* nombre)
{
	int ret=-1;

	if(this!=NULL && nombre!=NULL)
	{
		strcpy(nombre, this->nombre);
		ret=0;
	}
	return ret;
}

int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas)
{
	int ret=-1;

	if(this!=NULL && horasTrabajadas!=NULL)
	{
		*horasTrabajadas=this->horasTrabajadas;
		ret=0;
	}
	return ret;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
	int ret=-1;

	if(this!=NULL && sueldo!=NULL)
	{
		*sueldo=this->sueldo;
		ret=0;
	}
	return ret;
}

void employee_show(Employee* this)
{
	int auxId;
	char auxNombre[25];
	int auxHoras;
	int auxSueldo;

	employee_getId(this, &auxId);
	employee_getNombre(this, auxNombre);
	employee_getHorasTrabajadas(this, &auxHoras);
	employee_getSueldo(this, &auxSueldo);

	printf("%-4d	-	%-20s	-	%4d	-	%8d\n", auxId, auxNombre, auxHoras, auxSueldo);

}

int employee_sortId(void* pElementA, void* pElementB)
{
	int ret=0;
	int auxIdA;
	int auxIdB;

	if(pElementA!=NULL && pElementB!=NULL)
	{
		employee_getId((Employee*)pElementA, &auxIdA);
		employee_getId((Employee*)pElementB, &auxIdB);
		if(auxIdA<auxIdB)
		{
			ret=-1;
		}
		else
		{
			if(auxIdA>auxIdB)
			{
				ret=1;
			}
		}
	}

	return ret;
}

int employee_sortName(void* pElementA, void* pElementB)
{
	int ret=0;
	char auxNameA[128];
	char auxNameB[128];

	if(pElementA!=NULL && pElementB!=NULL)
	{
		employee_getNombre((Employee*)pElementA, auxNameA);
		employee_getNombre((Employee*)pElementB, auxNameB);
		ret=strcmp(auxNameA, auxNameB);
	}

	return ret;
}

int employee_sortHoras(void* pElementA, void* pElementB)
{
	int ret=0;
	int auxHorasA;
	int auxHorasB;

	if(pElementA!=NULL && pElementB!=NULL)
	{
		employee_getHorasTrabajadas((Employee*)pElementA, &auxHorasA);
		employee_getHorasTrabajadas((Employee*)pElementB, &auxHorasB);
		if(auxHorasA<auxHorasB)
		{
			ret=-1;
		}
		else
		{
			ret=1;
		}
	}

	return ret;
}

int employee_sortSueldo(void* pElementA, void* pElementB)
{
	int ret=0;
	int auxSueldoA;
	int auxSueldoB;

	if(pElementA!=NULL && pElementB!=NULL)
	{
		employee_getSueldo((Employee*)pElementA, &auxSueldoA);
		employee_getSueldo((Employee*)pElementB, &auxSueldoB);
		if(auxSueldoA<auxSueldoB)
		{
			ret=-1;
		}
		else
		{
			if(auxSueldoA>auxSueldoB)
			{
				ret=1;
			}
		}
	}

	return ret;
}

void employee_IncresSalary(void* this)
{
	int auxSueldo;
	if(employee_getSueldo((Employee*)this, &auxSueldo)==0 && auxSueldo>20000)
	{
		auxSueldo=auxSueldo+(10*auxSueldo/100);
		employee_setSueldo(this, auxSueldo);
	}
}
