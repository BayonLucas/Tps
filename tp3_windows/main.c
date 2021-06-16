#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

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

    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
    	printf("\n******************************************************************************************\n");
    	printf("Ingrese la opcion Deseada: \n");
    	printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    	printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
    	printf("3. Alta de empleado.\n");
    	printf("4. Modificar datos de empleado.\n");
    	printf("5. Baja de empleado.\n");
    	printf("6. Listar empleados.\n");
    	printf("7. Ordenar empleados.\n");
    	printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    	printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n\n");
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
            		printf("\nError: Ya se cargaron archivos anteriomente\n");
            	}
            	break;
            case 2:
            	if(flagFileLoaded==0)
				{
					if(controller_loadFromBinary( "dataBi.bin", listaEmpleados)==0)
					{
						flagFileLoaded++;
					}
				}
				else
				{
					printf("\nError: Ya se cargaron archivos anteriomente\n");
				}
                break;
            case 3:
            	controller_addEmployee(listaEmpleados);
                break;
            case 4:
            	controller_editEmployee(listaEmpleados);
                break;
            case 5:
            	if(ll_isEmpty(listaEmpleados)==0)
				{
            		controller_removeEmployee(listaEmpleados);
				}
				else
				{
					printf("\nDebe de haber al menos un empleado dado de alta para poder mostrar algo.\n");
				}
                break;
            case 6:
            	if(ll_isEmpty(listaEmpleados)==0)
            	{
            		controller_ListEmployee(listaEmpleados);
            	}
            	else
            	{
            		printf("\nDebe de haber al menos un empleado dado de alta para poder mostrar algo.\n");
            	}
                break;
            case 7:
            	controller_sortEmployee(listaEmpleados);
                break;
            case 8:

                break;
            case 9:

                break;
            case 10:
            	printf("\nSalió del programa. Hasta luego.\n");
                break;
            default:
                break;
        }
    }while(option != 10);
    return 0;
}

