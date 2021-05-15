/*
 ============================================================================
 Name        : tp_laboratorio_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"

#define maxEmployee 10

int main(void) {
	setbuf(stdout, NULL);

	int menuPrincipal;
	int flagPrimerIngresado=0;
	int contadorEmpleadoId=0;
	Employee dEmpleado[maxEmployee];


	initEmployees(dEmpleado, maxEmployee);
	hardcodearEmployee(dEmpleado, maxEmployee, &flagPrimerIngresado);
	do
	{
		printf("\n=====================================\n");
		printf("Ingrese alguna de las sig. opciones: \n");
		printf("1. Altas.\n");
		printf("2. Modificar.\n");
		printf("3. Baja.\n");
		printf("4. Informar.\n\n");
		printf("5. Salir.\n");
		printf("=====================================\n");
		scanf("%d", &menuPrincipal);


		switch(menuPrincipal)
		{
			case 1:
				altaEmployee(dEmpleado, maxEmployee, &contadorEmpleadoId);
				flagPrimerIngresado=1;
				break;
			case 2:
				if(flagPrimerIngresado==1)
				{
					modifyData(dEmpleado, maxEmployee);
				}
				else
				{
					printf("\nPrimero debe ingresar al menos un empleado para poder realizar esta acción\n\n");
				}
				break;
			case 3:
				if(flagPrimerIngresado==1)
				{
					removeEmployee(dEmpleado, maxEmployee);
				}
				else
				{
					printf("\nPrimero debe ingresar al menos un empleado para poder realizar esta acción\n\n");
				}
				break;
			case 4:
				if(flagPrimerIngresado==1)
				{
					sortEmployeeAlphabetic(dEmpleado, maxEmployee);
				}
				else
				{
					printf("\nPrimero debe ingresar al menos un empleado para poder realizar esta acción\n\n");
				}
				break;
			case 5:
				printf("\nSalió de programa. Que tenga buen día.\n\n");
				break;
			default:
				printf("\nPor favor, Ingrese alguna de las opciones dadas.\n\n");
				break;
		}
	} while(menuPrincipal!=5);

	return EXIT_SUCCESS;
}
