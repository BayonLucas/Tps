#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn_Validaciones.h"

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int ret;
	int num;
	while(reintentos>0)
	{
		printf(mensaje);
		if(getInt(&num)==1)
		{
			if(num<=maximo && num>=minimo)
				break;
		}
		fflush(stdin);
		reintentos--;
		printf(mensajeError);
	}
	if(reintentos==0)
	{
		ret=-1;
	}
	else
	{
		ret=0;
		*pResultado = num;
	}
	return ret;
}

int getInt(int* pResultado)
{
	int ret=-1;

	char buffer[64];
	fgets(buffer,sizeof(buffer),stdin);
	buffer[strlen(buffer)-1]='\0';
	if(esNumerica(buffer))
	{
		*pResultado = atoi(buffer);
		ret=1;
	}
	return ret;
}

int esNumerica(char* cadena)
{
	int ret=-1;
	int i=0;
	if(cadena!=NULL)
	{
		while(cadena[i]!='\0')
		{
			if(cadena[i]<'0' || cadena[i]>'9')
			{
				break;
			}
				i++;
		}
	if(cadena[i]=='\0')
	ret=1;
	}

	return ret;
}

int utn_getChar(char *input,char mensaje[],char eMensaje[],char lowLimit,char hiLimit,int intentos)
{
	int ret=-1;
	char aux;
	char buffer;
	int i;
	if(input != NULL &&  mensaje != NULL && eMensaje != NULL &&  lowLimit <= hiLimit && intentos > 0)
	{
		printf("\n %s",mensaje); //Se le pide el tipo de dato a ingresar al usuario
		fflush(stdin);
		scanf("\n %c",&buffer);

		for (i = 0; i < intentos; i++)
		{
			aux = isdigit(buffer);
			if(buffer >= lowLimit && buffer <= hiLimit && aux == 0)
			{
				if(isupper(buffer)==0)
				{
					buffer=toupper(buffer);
				}
				*input = buffer;
				ret = 0;
				break;
			}
			else //Error al ingrese el tipo de dato por fuera de los limites establecidos
			{
				printf("\n %s\n",eMensaje);
				fflush(stdin);
				scanf("\n %c \n",&buffer);
			}
		} //FIN FOR
	}
	return ret;
} //FIN utn_getChar()

int utn_getStringAlpha(char* input,char mensaje[],char eMensaje[],int cantAproxChar,int reintentos)
{
	int ret = -1;
	char buffer[100];
	int i;

	if(input != NULL &&  mensaje != NULL && eMensaje != NULL &&  cantAproxChar>0 && reintentos > 0)
	{
		printf("\n %s",mensaje); //Se le pide el tipo de dato a ingresar al usuario
		fflush(stdin);
		gets(buffer);
		for(i=0;i<reintentos-1;i++)
		{
			if(esPalabra(buffer)==0)
			{
				if(strlen(buffer) <= cantAproxChar)
				{
					strncpy(input, buffer, cantAproxChar);
					ret=0;
					break;
				}
				else
				{
					ret=1; // Ingreso mas de lo debido.
				}
			}
			else //Error al ingrese el tipo de dato por fuera de los limites establecidos
			{
				printf("\n %s\n",eMensaje);
				fflush(stdin);
				gets(buffer);
			}
		}
	}
	return ret;
}

int esPalabra(char* cadena)
{
	int ret=-1;
	int i=0;
	if(cadena!=NULL)
	{
		while(cadena[i]!='\0')
		{
			if (isalpha(cadena[i])==0)
			{
				break;
			}
				i++;
		}
	if(cadena[i]=='\0')
	ret=0;
	}
	return ret;
}


int esCuit(char* cadena)
{
	int ret;
	int i;
	int contadorDigito=0;
	int contadorGuion=0;

	if(cadena!=NULL)
	{
		for(i=0;cadena[i]!='\0';i++)
		{
			if(isdigit(cadena[i])!=0)
			{
				contadorDigito++;
			}
			else
			{
				if(cadena[i]=='-')
				{
					contadorGuion++;
				}
				else
				{
					ret=-1;
					break;
				}
			}
		}
		if(contadorDigito==11 && contadorGuion==2)
		{
			ret=0;
		}
	}
	return ret;
}

int utn_getCuit(char input[],char mensaje[],char eMensaje[],int reintentos)
{
	int ret;
	char buffer[14];
	int i;
	int aux;

		if(input!=NULL && mensaje!= NULL && eMensaje!= NULL && reintentos>0)
		{
			for(i=reintentos;i>0;i--)
			{
				printf("\n %s",mensaje); //Se le pide el tipo de dato a ingresar al usuario
				fflush(stdin);
				fgets(buffer,14,stdin);
				aux=esCuit(buffer);
				if(aux==0)
				{
					if(buffer[2]=='-' && buffer[11]=='-')
					{
						strcpy(input,buffer);
						ret=0;
						break;
					}
				}
				else
				{
					printf("\n %s\n",eMensaje);
				}
			}
		}
		if(reintentos==0)
		{
			ret=-1;
		}
	return ret;
}

int myGets(char* cadena, int longitud)
{
	int retorno=-1;
	char bufferString[5000];
	if(cadena!=NULL && longitud>0)
	{
		fflush(stdin);
		if(fgets(bufferString, sizeof(bufferString),stdin)!=NULL)
		{
			if(bufferString[strnlen(bufferString, sizeof(bufferString))-1] =='\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString, sizeof(bufferString))<=longitud)
			{
				strncpy(cadena, bufferString, longitud);
				retorno=0;
			}
		}
	}
	return retorno;
}

int esFlotante(char* cadena, int longitud)
{
	int retorno= 1;
	int i;
	int contadorPunto=0;
	if(cadena!=NULL && strlen(cadena)>0)
	{
		for(i=0; i<longitud && cadena[i]!='\0'; i++)
		{
			if(i==0 && (cadena[i]=='+' || cadena[i]=='-'))
			{
				continue;
			}
			if(cadena[i]<'0'||cadena[i]>'9')
			{
				if(cadena[i]=='.' && contadorPunto==0)
				{
					contadorPunto++;
				}
				else
				{
				retorno=0;
				break;
				}
			}
		}
	}
	return retorno;
}

int getFloat(float* pResultado)
{
	int retorno = -1;
	char buffer[64];
	if(pResultado!=NULL)
	{
		if(myGets(buffer, sizeof(buffer))==0 && esFlotante(buffer, sizeof(buffer))==1)
		{
			*pResultado=atof(buffer);
			retorno=0;
		}
	}
	return retorno;
}

int utn_getNumeroFlotante(float* pResultado,char* mensaje,char* eMensaje,float minimo,float maximo,int reintentos)
{
	int retorno = -1;
	float bufferInterno;
	if(pResultado != NULL && mensaje != NULL && eMensaje != NULL && minimo <= maximo && reintentos>0)
	{
		do
		{
			printf("%s", mensaje);
			if(getFloat(&bufferInterno)==0 && bufferInterno>=minimo && bufferInterno<=maximo)
			{
				*pResultado=bufferInterno;
				retorno=0;
				break;
			}
			else
			{
				printf("%s", eMensaje);
				reintentos--;
			}
		}while(reintentos>=0);
	}
	return retorno;
}

void swapStrings(char* palabra1, char* palabra2)
{
	char aux[25];
	strcpy(aux,palabra1);
	strcpy(palabra1, palabra2);
	strcpy(palabra2, aux);
}

void swapChar(char x, char y, char* pX, char* pY)
{
	char aux;
	if(pX!=NULL && pY!=NULL)
	{
		aux=x;
		x=y;
		y=aux;
		*pX=x;
		*pY=y;
	}
}

void swapEnterosAsc(int x, int y, int* pX, int* pY)
{
	int aux;
	if(pX!=NULL && pY!=NULL)
	{
		aux=x;
		x=y;
		y=aux;
		*pX=x;
		*pY=y;
	}
}

void swapFloatAsc(float x, float y, float* pX, float* pY)
{
	float aux;
	if(pX!=NULL && pY!=NULL)
	{
		aux=x;
		x=y;
		y=aux;
		*pX=x;
		*pY=y;
	}
}







