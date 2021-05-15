#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn_Validaciones.h"
#include "struct.Alumnos.h"
#include "utn_all-functions.h"

int inicializarStruct(alumnos array[], int tam)
{
	int ret=-1;
	int i;

	if (array != NULL && tam > 0)
	{
		for (i = 0; i < tam; i++)
		{
			array[i].isEmpty = 1;
		}
		ret = 0;
	}
	return ret;
}

int mostrarListados(alumnos array[], eCarrera arrayCarrera[], int tamAlumnos, int tamCarrera)
{
	int i;
	int ret=-1;

	if(array!=NULL && arrayCarrera!=NULL && tamAlumnos>0)
	{
		printf("id	Legajo	Sexo	Edad	Nota1	Nota2	Promedio	Apellido	Carrera\n");
		for(i=0;i<tamAlumnos;i++)
		{
			if(array[i].isEmpty==0)
			{
				mostrarAlumno(array, arrayCarrera,tamCarrera, i);
			}
		}
		ret=0;
	}
	return ret;
}

void mostrarAlumno(alumnos arrayAlumno[], eCarrera arrayCarrera[],int tamCarrera, int posicionAlumno)
{
	char aux[20];

	buscarDescCarreraPorAlumno(arrayCarrera, tamCarrera, arrayAlumno,posicionAlumno, &aux);

	printf("%-3d	%-5d	%-5c	%-5d	%-5d	%-5d	%.2f		%-15s	%-15s\n",posicionAlumno,arrayAlumno[posicionAlumno].legajo,arrayAlumno[posicionAlumno].sexo,arrayAlumno[posicionAlumno].edad,arrayAlumno[posicionAlumno].nota1,arrayAlumno[posicionAlumno].nota2,arrayAlumno[posicionAlumno].promedio,arrayAlumno[posicionAlumno].apellido, aux);
}

int buscarDescCarreraPorAlumno(eCarrera arrayCarrera[],int tamCarrera, alumnos arrayAlumno[], int posicionAlumno, char* aux)
{
	int ret=-1;
	int i;

	for(i=0;i<tamCarrera;i++)
	{
		if(arrayCarrera[i].idCarrera == arrayAlumno[posicionAlumno].idCarrera)
		{
			*aux=arrayCarrera[i].descripcionCarrera;
			ret=0;
		}
	}

	return ret;
}

int buscarLibre(alumnos array[], int tam, int* posicion)
{
	int ret=-1;
	int i;

	if(array!=NULL && tam>0)
	{
		for(i=0;i<tam;i++)
		{
			if(array[i].isEmpty==1)
			{
				*posicion=i;
				ret=0;
				break;
			}
		}
	}
	return ret;
}

int IngresarDatos(alumnos array[], int tam, eCarrera arrayCarrera[], int tamCarrera, int* contadorID)
{
	int ret=-1;
	int control[5];
	int posicion;
	int i;

	if(array!=NULL && tam>0 && contadorID!=NULL)
	{
		if(buscarLibre(array,tam,&posicion)==1)
		{
			(*contadorID)++;
			//control[0]=utn_getNumero(&datos[pos].legajo, "Ingrese el legajo del alumno.\n", "Error: Ingrese un entero entre 1000 y 9999 inclusive", 1000, 9999, 3);
			array[posicion].legajo=*contadorID;
			printf("Ingrese el sexo del alumno.\n");
			fflush(stdin);
			scanf("%c", &array[posicion].sexo);
			control[1]= utn_getNumero(&array[posicion].edad, "Ingrese la edad del alumno.\n", "Error: Ingrese un entero entre 5 y 100 inclusive", 5, 100, 3);
			control[2]=	utn_getNumero(&array[posicion].nota1, "Ingrese la nota1 del alumno.\n", "Error: Ingrese un entero entre 1 y 10 inclusive", 1, 10, 3);
			control[3]= utn_getNumero(&array[posicion].nota2, "Ingrese la nota2 del alumno.\n", "Error: Ingrese un entero entre 1 y 10 inclusive", 1, 10, 3);
			array[posicion].promedio=(array[posicion].nota1+(float)array[posicion].nota2)/2;
			printf("El promedio de las notas es: %.2f.\n", array[posicion].promedio);
			printf("\nEstos son los ID de las carreras\n");
			for(i=0;i<tamCarrera;i++)
			{
			printf("%d - %s\n", arrayCarrera[i].idCarrera, arrayCarrera[i].descripcionCarrera);
			}
			control[4]= utn_getNumero(&array[posicion].idCarrera, "\nIngrese el id de la carrera del alumno.\n", "Error: Ingrese una de las opciones entre 0 y 2 inclusive", 0, 2, 3);
			printf("Ingrese el apellido del alumno.\n");
			fflush(stdin);
			gets(array[posicion].apellido);
			if(control[0]!=-1 && control[1]!=-1 && control[2]!=-1 && control[3]!=-1 && control[4]!=-1)
			{
				array[posicion].isEmpty=0;
				ret=0;
			}
			else
			{
				printf("Error al ingresar datos.\n\n");
			}
		}
		else
		{
			printf("\nNo hay mas espacios donde cargar datos.");
		}
	}
	return ret;
}

void bajaAlumno(alumnos array[])
{
	int control;
	int id;
	control= utn_getNumero(&id, "Ingrese el id del alumno a eliminar.\n", "Error: Ingrese un id valido.", 0, 4, 3);
	if(control!=-1)
	{
	array[id].isEmpty=1;
	}
}

void modificarDato(alumnos array[], int opcion, int id)
{
	switch(opcion)
	{
		case 1: //Legajo
			utn_getNumero(&array[id].legajo, "Ingrese el nuevo legajo del alumno.\n", "Error: Ingrese un entero entre 1000 y 9999 inclusive", 1000, 9999, 3);
			break;
		case 2: //Sexo
			printf("Ingrese el nuevo sexo del alumno.\n");
			fflush(stdin);
			scanf("%c", &array[id].sexo);
			break;
		case 3: //Edad
			utn_getNumero(&array[id].edad, "Ingrese el nueva edad del alumno.\n", "Error: Ingrese un entero entre 5 y 100 inclusive", 5, 100, 3);
			break;
		case 4: //Nota1
			utn_getNumero(&array[id].nota1, "Ingrese la nueva nota1 del alumno.\n", "Error: Ingrese un entero entre 1 y 10 inclusive", 1, 10, 3);
			break;
		case 5: //Nota2
			utn_getNumero(&array[id].nota2, "Ingrese la nueva nota2 del alumno.\n", "Error: Ingrese un entero entre 1 y 10 inclusive", 1, 10, 3);
			break;
		case 6: //Apellido
			printf("Ingrese el apellido del alumno.\n");
			fflush(stdin);
			gets(array[id].apellido);
			break;
		case 7: //Salir
			printf("\nVolviendo al menu anterior.\n");
			break;
		default:
			printf("\nIngrese alguna de las opciones dadas.\n");
			break;
	}
}

int ordenLegajo (alumnos array[], int tam)
{
	int ret=-1;
	int i;
	int j;
	if(array!= NULL && tam>0)
	{
		for(i=0;i<tam-1;i++)
		{
			if(array[i].isEmpty==0)
			{
				for(j=i+1;j<tam;j++)
				{
					if(array[j].isEmpty==0)
					{
						if(array[i].apellido<array[j].apellido)
						{
							swapEnterosAsc(array[i].legajo, array[j].legajo, &array[i].legajo, &array[j].legajo);
							swapChar(array[i].sexo, array[j].sexo, &array[i].sexo, &array[j].sexo);
							swapEnterosAsc(array[i].edad, array[j].edad, &array[i].edad, &array[j].edad);
							swapEnterosAsc(array[i].nota1, array[j].nota1, &array[i].nota1, &array[j].nota1);
							swapEnterosAsc(array[i].nota2, array[j].nota2, &array[i].nota2, &array[j].nota2);
							swapFloatAsc(array[i].promedio, array[j].promedio, &array[i].promedio, &array[j].promedio);
							swapStrings(array[i].apellido, array[j].apellido);
							ret=0;
						}
					}
				}
			}
		}
	}
	return ret;
}

int ordenApellido (alumnos array[], int tam)
{
	int ret=-1;
	int i;
	int j;
	if(array!= NULL)
	{
		for(i=0;i<tam-1;i++)
		{
			if(array[i].isEmpty==0)
			{
				for(j=i+1;j<tam;j++)
				{
					if(array[j].isEmpty==0)
					{
						if(array[i].apellido<array[j].apellido)
						{
							swapEnterosAsc(array[i].legajo, array[j].legajo, &array[i].legajo, &array[j].legajo);
							swapChar(array[i].sexo, array[j].sexo, &array[i].sexo, &array[j].sexo);
							swapEnterosAsc(array[i].edad, array[j].edad, &array[i].edad, &array[j].edad);
							swapEnterosAsc(array[i].nota1, array[j].nota1, &array[i].nota1, &array[j].nota1);
							swapEnterosAsc(array[i].nota2, array[j].nota2, &array[i].nota2, &array[j].nota2);
							swapFloatAsc(array[i].promedio, array[j].promedio, &array[i].promedio, &array[j].promedio);
							swapStrings(array[i].apellido, array[j].apellido);
							ret=0;
						}
					}
				}
			}
		}
	}
	return ret;
}

int ordenPromedioOLeg (alumnos array[], int tam)
{
	int ret=-1;
	int i;
	int j;
	if(array!= NULL)
	{
		for(i=0;i<tam-1;i++)
		{
			if(array[i].isEmpty==0)
			{
				for(j=i+1;j<tam;j++)
				{
					if(array[j].isEmpty==0)
					{
						if(array[i].promedio<array[j].promedio)
						{
							swapEnterosAsc(array[i].legajo, array[j].legajo, &array[i].legajo, &array[j].legajo);
							swapChar(array[i].sexo, array[j].sexo, &array[i].sexo, &array[j].sexo);
							swapEnterosAsc(array[i].edad, array[j].edad, &array[i].edad, &array[j].edad);
							swapEnterosAsc(array[i].nota1, array[j].nota1, &array[i].nota1, &array[j].nota1);
							swapEnterosAsc(array[i].nota2, array[j].nota2, &array[i].nota2, &array[j].nota2);
							swapFloatAsc(array[i].promedio, array[j].promedio, &array[i].promedio, &array[j].promedio);
							swapStrings(array[i].apellido, array[j].apellido);
							ret=0;
						}
						else
						{
							if(array[i].promedio==array[j].promedio && array[i].legajo<array[j].legajo)
							{
								swapEnterosAsc(array[i].legajo, array[j].legajo, &array[i].legajo, &array[j].legajo);
								swapChar(array[i].sexo, array[j].sexo, &array[i].sexo, &array[j].sexo);
								swapEnterosAsc(array[i].edad, array[j].edad, &array[i].edad, &array[j].edad);
								swapEnterosAsc(array[i].nota1, array[j].nota1, &array[i].nota1, &array[j].nota1);
								swapEnterosAsc(array[i].nota2, array[j].nota2, &array[i].nota2, &array[j].nota2);
								swapFloatAsc(array[i].promedio, array[j].promedio, &array[i].promedio, &array[j].promedio);
								swapStrings(array[i].apellido, array[j].apellido);
								ret=0;
							}
						}
					}
				}
			}
		}
	}
	return ret;
}

void buscarJoven(alumnos array[], int tam, int* idJoven)
{
	int elPrimero=0;
	int i;
	int aux;
	int idAux;

	for(i=0;i<tam;i++)
	{
		if(array[i].isEmpty==0)
		{
			if(elPrimero==0)
			{
				aux=array[i].edad;
				idAux=i;
				elPrimero++;
			}
			else
			{
				if(aux>array[i].edad)
				{
					aux=array[i].edad;
					idAux=i;

				}
			}
		}
	}
	*idJoven=idAux;
}

void informeCarrera(alumnos array[],int tam, eCarrera arrayCarrera[], int tamCarrera, int idCarrera)
{
	int i;

	printf("id	Legajo	Sexo	Edad	Nota1	Nota2	Promedio	Apellido	Carrera\n");
	for(i=0;i<tam;i++)
	{
		if(array[i].isEmpty==0)
		{
			if(array[i].idCarrera==idCarrera)
			{
				mostrarAlumno(array, arrayCarrera, tamCarrera , i);
			}
		}
	}
}
