#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn_Validaciones.h"
#include "Controller.h"

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int ret=-1;
	FILE* arch=NULL;
	FILE* AuxArch=NULL;
	int i;
	Employee* pEmployee=NULL;
	int auxId;
	char auxNombre[128];
	int auxHoras;
	int auxSueldo;

	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		if((arch=fopen(path,"r"))==NULL)
		{
			printf("\nEl archivo no se abrió Correctamente\n");
		}
		else
		{
			if(ll_isEmpty(pArrayListEmployee)==1)
			{
				if(parser_EmployeeFromText(arch , pArrayListEmployee)==0)
				{
					ret=0;
				}
				else
				{
					printf("\nEl archivo no se pudo leer correctamente\n");
				}
			}
			else
			{
				printf("Cargar el archivo provocará la perdida de los datos cargados anteriormente. Desea resguardarlos en otro archivo?.\n");
				if(utn_getCaracterSN()==0)
				{
					if((AuxArch=fopen("extraData.csv","w"))==NULL)
					{
						printf("\nEl archivo auxiliar no se abrió Correctamente\n");
					}
					else
					{
						fprintf(AuxArch,"ID,NOMBRE,HORAS TRABAJADAS,SUELDO\n");
						for(i=0;i<ll_len(pArrayListEmployee);i++)
						{
							pEmployee=(Employee*)ll_get(pArrayListEmployee, i);
							if(pEmployee!=NULL)
							{
								if( (employee_getId(pEmployee, &auxId)==0) &&
									(employee_getNombre(pEmployee, auxNombre)==0) &&
									(employee_getHorasTrabajadas(pEmployee, &auxHoras)==0) &&
									(employee_getSueldo(pEmployee, &auxSueldo)==0) )
								{
									fprintf(AuxArch,"%d,%s,%d,%d\n", auxId, auxNombre, auxHoras, auxSueldo);
								}
								else
								{
									free(pEmployee);
									ret=-1;
									printf("Error en el resguardo de la información.\n");
									break;
								}
							}
							else
							{
								printf("No hay espacio disponible para realizar el resguardo.\n");
							}
						}
						if(ll_clear(pArrayListEmployee)==0)
						{
							if(parser_EmployeeFromText(arch , pArrayListEmployee)==0)
							{
								ret=0;
							}
							else
							{
								printf("\nEl archivo no se pudo leer correctamente\n");
							}
						}
					}
				}
				else
				{
					if(ll_clear(pArrayListEmployee)==0)
					{
						if(parser_EmployeeFromText(arch , pArrayListEmployee)==0)
						{
							ret=0;
						}
						else
						{
							printf("\nEl archivo no se pudo leer correctamente\n");
						}
					}
				}
			}
		}
		if(ret==0)
		{
			printf("\n*La carga fue exitosa!*\n\n");
		}
		fclose(arch);
		fclose(AuxArch);
	}

    return ret;
}

int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int ret=-1;
	FILE* arch=NULL;
	FILE* AuxArch=NULL;
	int i;
	Employee* pEmployee=NULL;
	int auxId;
	char auxNombre[128];
	int auxHoras;
	int auxSueldo;

	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		if((arch=fopen(path,"rb"))==NULL)
		{
			printf("\nEl archivo no se abrió Correctamente\n");
		}
		else
		{
			if(ll_isEmpty(pArrayListEmployee)==1)
			{
				if(parser_EmployeeFromBinary(arch , pArrayListEmployee)==0)
				{
					ret=0;
				}
				else
				{
					printf("\nEl archivo no se pudo leer correctamente\n");
				}
			}
			else
			{
				printf("Cargar el archivo provocará la perdida de los datos cargados anteriormente. Desea resguardarlos en otro archivo?.\n");
				if(utn_getCaracterSN()==0)
				{
					if((AuxArch=fopen("extraDataBin.bin","wb"))==NULL)
					{
						printf("\nEl archivo auxiliar binario no se abrió Correctamente\n");
					}
					else
					{
						for(i=0;i<ll_len(pArrayListEmployee);i++)
						{
							pEmployee=(Employee*)ll_get(pArrayListEmployee, i);
							if(pEmployee!=NULL)
							{
								if( (employee_getId(pEmployee, &auxId)==0) &&
									(employee_getNombre(pEmployee, auxNombre)==0) &&
									(employee_getHorasTrabajadas(pEmployee, &auxHoras)==0) &&
									(employee_getSueldo(pEmployee, &auxSueldo)==0) )
								{
									fwrite(pEmployee, sizeof(Employee), 1, AuxArch);
								}
								else
								{
									free(pEmployee);
									ret=-1;
									printf("Error en el resguardo de la información.\n");
									break;
								}
							}
							else
							{
								printf("No hay espacio disponible para realizar el resguardo.\n");
							}
						}
						if(ll_clear(pArrayListEmployee)==0)
						{
							if(parser_EmployeeFromBinary(arch , pArrayListEmployee)==0)
							{
								ret=0;
							}
							else
							{
								printf("\nEl archivo no se pudo leer correctamente\n");
							}
						}
					}
				}
				else
				{
					if(ll_clear(pArrayListEmployee)==0)
					{
						if(parser_EmployeeFromBinary(arch , pArrayListEmployee)==0)
						{
							ret=0;
						}
						else
						{
							printf("\nEl archivo no se pudo leer correctamente\n");
						}
					}
				}
			}
		}
		fclose(arch);
		fclose(AuxArch);
	}

	return ret;
}

int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int ret=-1;
	int auxId;
	char auxNombre[128];
	int auxHorasTrabajadas;
	int auxSueldo;
	Employee* newEmployee=employee_new();

	if(pArrayListEmployee!=NULL && newEmployee!=NULL)
	{
		if(utn_getStringAlpha(auxNombre,"Ingrese el nombre del Empleado.\n", "Error: solo utilice caracteres albeticos.\n",128, 3)==0 &&
		   utn_getNumero(&auxHorasTrabajadas, "Ingrese la cantidad de horas trabajadas del empleado.\n", "Error: Ingrese un número entero.\n", 0, 99999, 3)==0 &&
		   utn_getNumero(&auxSueldo, "Ingrese el sueldo del empleado.\n", "Error: Ingrese un número entero.\n", 0, 999999, 3)==0)
		{
			employee_setNombre(newEmployee, auxNombre);
			employee_setHorasTrabajadas(newEmployee, auxHorasTrabajadas);
			employee_setSueldo(newEmployee, auxSueldo);
			if(ll_isEmpty(pArrayListEmployee)==1)
			{
				auxId=1;
				employee_setId(newEmployee, auxId);
				ret=0;
			}
			else
			{
				auxId=getLastId(pArrayListEmployee);
				if(auxId!=-1)
				{
					auxId++;
					employee_setId(newEmployee, auxId);
					ret=0;
				}
				else
				{
					printf("\nError en la busqueda del ultimo id.\n");
				}
			}
			if(ret==0)
			{
				if(ll_add(pArrayListEmployee, newEmployee)!=0)
				{
					ret=-1;
				}
				else
				{
					printf("El id del nuevo empleado es: %d\n\n",auxId);
				}
			}
		}
		else
		{
			printf("\nError al ingresar datos. Vuelva a intentar.\n");
		}
	}

    return ret;
}

int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int ret=-1;
	int idModif;
	Employee* modifEmployee;
	int opModif;
	char auxNombre[50];
	int auxHoras;
	int auxSueldo;

	if(pArrayListEmployee!=NULL && ll_isEmpty(pArrayListEmployee)==0)
	{
		if(utn_getNumero(&idModif, "Ingrese el id del Empleado a modificar\n", "Error: Ingrese un id activo\n", 0, getLastId(pArrayListEmployee), 3)==0)
		{
			modifEmployee=getEmployeeById(pArrayListEmployee, idModif);
			if(modifEmployee!=NULL)
			{
				printf("=========================================================================\n");
				printf("id	-	Nombre			-	Horas	-	Sueldo\n");
				printf("=========================================================================\n");
				employee_show(modifEmployee);
				if(utn_getNumero(&opModif, "Que desea modificar?: \n1.Nombre.\n2.Horas.\n3.Sueldo.\n\n", "Error: Ingre alguna de las opciones dadas\n", 1, 3, 10)==0)
				{
					switch(opModif)
					{
					case 1:
						if(utn_getStringAlpha(auxNombre, "Ingrese el nuevo nombre del empleado.\n", "Error: Ingrese caracteres válidos.\n\n", 50, 3)==0)
						{
							employee_setNombre(modifEmployee, auxNombre);
							ret=0;
						}
						break;
					case 2:
						if(utn_getNumero(&auxHoras, "Ingrese la nueva cantidad de horas trabajadas del empleado.\n",
								"Error: Ingrese un número entero válido.\n\n", 0, 9999, 3)==0)
						{
							employee_setHorasTrabajadas(modifEmployee, auxHoras);
							ret=0;
						}
						break;
					case 3:
						if(utn_getNumero(&auxSueldo, "Ingrese el nuevo sueldo del empleado.\n",
								"Error: Ingrese un número entero válido.\n\n", 0, 999999, 3)==0)
						{
							employee_setSueldo(modifEmployee, auxSueldo);
							ret=0;
						}
						break;
					}
					if(ret==0)
					{
						printf("\n*La modificación fue exitosa!*\n");
					}
				}
				else
				{
					printf("Error: Excedió el limite de intento al ingresar una opción.\n");
				}
			}
			else
			{
				printf("Error: El id ingresado le pertenece a un empleado ya dado de baja.\n");
			}
		}
		else
		{
			printf("Error: Al ingresar un id válido.\n");
		}
	}
	else
	{
		printf("\nDebe de haber al menos un empleado dado de alta para poder mostrar algo.\n");
	}
    return ret;
}

int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int ret=-1;
	int idDelete;
	Employee* deleteEmployee;
//	int indexEmployee;

	if(pArrayListEmployee!=NULL && ll_isEmpty(pArrayListEmployee)==0)
	{
		if(utn_getNumero(&idDelete, "Ingrese el id del Empleado a modificar\n", "Error: Ingrese un id activo\n", 0, getLastId(pArrayListEmployee), 3)==0)
		{
			deleteEmployee=getEmployeeById(pArrayListEmployee, idDelete);
			if(deleteEmployee!=NULL)
			{
				printf("=========================================================================\n");
				printf("id	-	Nombre			-	Horas	-	Sueldo\n");
				printf("=========================================================================\n");
				employee_show(deleteEmployee);
				printf("Desea eliminar este empleado?.\n");
				if(utn_getCaracterSN()==0)
				{
					//indexEmployee=ll_indexOf(pArrayListEmployee, deleteEmployee);
					if(ll_remove(pArrayListEmployee, ll_indexOf(pArrayListEmployee, deleteEmployee))==0)
					{
						printf("\n*El empleado fue dado de baja con exito!*\n");
						ret=0;
					}
				}
			}
			else
			{
				printf("Error: El id ingresado le pertenece a un empleado ya dado de baja.\n");
			}
		}
		else
		{
			printf("Error: Al ingresar un id válido.\n");
		}
	}
	else
	{
		printf("\nDebe de haber al menos un empleado dado de alta para poder mostrar algo.\n");
	}
	return ret;
}

int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int ret=-1;
	Employee* dirEmployee=NULL;
	int i;

	if(pArrayListEmployee!=NULL)
	{
		if(ll_isEmpty(pArrayListEmployee)==0)
		{
			printf("\n=========================================================================\n");
			printf("id	-	Nombre			-	Horas	-	Sueldo\n");
			printf("=========================================================================\n");
			for(i=0;i<ll_len(pArrayListEmployee);i++)
			{
				dirEmployee=ll_get(pArrayListEmployee, i);
				if(dirEmployee!=NULL)
				{
					employee_show(dirEmployee);
					ret=0;
				}
				else
				{
					ret=-1;
					printf("\nError en la carga de info.\n");
					break;
				}
			}
		}
		else
		{
			printf("\nDebe de haber al menos un empleado dado de alta para poder mostrar algo.\n");
		}
	}

    return ret;
}

int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int ret=-1;
	int opSort;
	int opOrden;
	int (*pFunc)(void*, void*);

	if(pArrayListEmployee!=NULL)
	{
		if(ll_isEmpty(pArrayListEmployee)==0)
		{
			if(utn_getNumero(&opSort, "Ingrese el criterio a ulitizar en el ordenamiento:\n1. id\n2. Nombre.\n3. Horas Trabajadas\n4. Sueldo.\n\n5. Volver.\n\n", "\nError: Ingrese alguna de las opciones dadas, por favor.\n", 1, 5, 3)==0)
			{
				switch(opSort)
				{
				case 1:
					pFunc=employee_sortId;
					break;
				case 2:
					pFunc=employee_sortName;
					break;
				case 3:
					pFunc=employee_sortHoras;
					break;
				case 4:
					pFunc=employee_sortSueldo;
					break;
				default:
					printf("\nError: Ingrese alguna de las opciones dadas.\n");
					break;
				}
				if(utn_getNumero(&opOrden, "Ingrese '1' para un orden Ascendente o '0' para un orden Descendente. \n", "\nError: Ingrese solo '1' o '0' por favor.\n", 0, 1, 3)==0)
				{
					if(ll_sort(pArrayListEmployee, pFunc, opOrden)==1)
					{
						printf("\nSe reordeno correctamente.\n");
						ret=0;
					}
				}
				else
				{
					printf("Error al ingresar el orden de la lista.\n");
				}
			}
		}
	}

    return ret;
}

int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

int getLastId(LinkedList* pArrayListEmployee)
{
	int retId=-2;
	LinkedList* linkedListCloned=ll_newLinkedList();
	int (*pSortId)(void*, void*);
	Employee* auxEmployee=NULL;

	pSortId=employee_sortId;

	if(pArrayListEmployee!=NULL)
	{
		linkedListCloned=ll_clone(pArrayListEmployee);
		if(linkedListCloned!=NULL)
		{
			ll_sort(linkedListCloned, pSortId, 1);
			auxEmployee=ll_get(linkedListCloned, (ll_len(linkedListCloned)-1));
			if(auxEmployee!=NULL)
			{
				employee_getId(auxEmployee, &retId);
				ll_clear(linkedListCloned);
				ll_deleteLinkedList(linkedListCloned);
			}
		}
	}
	return retId;
}

void* getEmployeeById(LinkedList* pArrayListEmployee, int id)
{
	void* returnEmployee=NULL;
	int i;
	int idCmp;
	Employee* auxEmp=NULL;

	if(pArrayListEmployee!=NULL && id>=0)
	{
		if(ll_isEmpty(pArrayListEmployee)==0)
		{
			for(i=0;i<ll_len(pArrayListEmployee);i++)
			{
				auxEmp=ll_get(pArrayListEmployee, i);
				if(auxEmp!=NULL)
				{
					employee_getId(auxEmp, &idCmp);
					if(idCmp==id)
					{
						returnEmployee=auxEmp;
						break;
					}
				}
			}
		}
	}
	return returnEmployee;
}





//	int i;
//	Employee* auxEmployee;
//	int cant;

//		{
//			if(ll_isEmpty(pArrayListEmployee)==1)
//			{
//				fclose(arch);
//				ret=0;
//			}
//			else
//			{
//				for(i=0;i<ll_len(pArrayListEmployee);i++)
//				{
//					auxEmployee=(Employee*)ll_get(pArrayListEmployee, i);
//					cant=fwrite(auxEmployee,sizeof(Employee), 1, arch);
//					ret=0;
//					if(cant!=1)
//					{
//						free(auxEmployee);
//						ret=-1;
//						break;
//					}
//				}
//				fclose(arch);
//			}
//		}

