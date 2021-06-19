#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn_Validaciones.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int main()
{
	setbuf(stdout, NULL);

    int option = 0;
    int flagFileLoaded=0;
    int flagFileSaved=0;

    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
    	printf("\n******************************************************************************************\n");
    	printf("Ingrese la opcion Deseada: \n");
    	printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    	printf("2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
    	printf("3. Alta de empleado.\n");
    	printf("4. Modificar datos de empleado.\n");
    	printf("5. Baja de empleado.\n");
    	printf("6. Listar empleados.\n");
    	printf("7. Ordenar empleados.\n");
    	printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    	printf("9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n\n");
    	printf("10. Salir.\n");
    	printf("******************************************************************************************\n\n");
    	scanf("%d", &option);

        switch(option)
        {
            case 1:
            	if(flagFileLoaded==0)
            	{
					if(controller_loadFromText("data.csv",listaEmpleados)==0)
					{
						flagFileLoaded++;
					}
            	}
            	else
            	{
            		printf("\nError: Ya se cargaron archivos anteriomente.\n");
            	}
            	break;
            case 2:
            	if(flagFileLoaded==0)
				{
					if(controller_loadFromBinary("dataBi.bin", listaEmpleados)==0)
					{
						flagFileLoaded++;
					}
				}
				else
				{
					printf("\nError: Ya se cargaron archivos anteriomente.\n");
				}
                break;
            case 3:
            	controller_addEmployee(listaEmpleados);
                break;
            case 4:
            	controller_editEmployee(listaEmpleados);
                break;
            case 5:
            	controller_removeEmployee(listaEmpleados);
                break;
            case 6:
            	controller_ListEmployee(listaEmpleados);
                break;
            case 7:
            	controller_sortEmployee(listaEmpleados);
                break;
            case 8:
            	if(controller_saveAsText("data.csv", listaEmpleados)==0)
            	{
            		flagFileSaved=1;
            	}
                break;
            case 9:
            	if(controller_saveAsBinary("dataBi.bin", listaEmpleados)==0)
				{
					flagFileSaved=1;
				}
                break;
            case 10:
            	if(flagFileSaved!=0)
            	{
					printf("\nSalió del programa. Hasta luego.\n");
					ll_deleteLinkedList(listaEmpleados);
            	}
            	else
            	{
            		printf("\nDesea salir sin guardar?.\n");
            		if(utn_getCaracterSN()==0)
            		{
            			printf("\nSalió del programa. Hasta luego.\n");
						ll_deleteLinkedList(listaEmpleados);
            		}
            		else
            		{
            			option=8;
            		}
            	}
                break;
            default:
            	printf("\nIngrese alguna de las opciones dadas, por favor.\n\n");
                break;
        }
    }while(option != 10);
    return 0;
}

