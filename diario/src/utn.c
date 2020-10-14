#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"


static int getString(char* cadena, int longitud);
static int esNumerica(char* cadena, int limite);
static int esFlotante(char* cadena);
static int getFloat(float* pResult);
static int esNombre(char* cadena,int longitud);
static int getNombre(char* pResultado,int longitud);
static int getCuit(char* pResultado, int longitud);
static int esDescripcion(char* cadena,int longitud);
static int getDescripcion(char* pResultado, int longitud);

/**
 * \brief Solicita un numero al usuario, leuego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el minimo minimo a ser aceptado
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 */
int utn_getNumber(int* pResult, char* message, char* errorMessage, int minimum, int maximum, int retry){

	float bufferint;
	int returnAux = -1;


	if(pResult != NULL && message != NULL && errorMessage !=NULL && minimum <= maximum && retry >= 0)
	{
		do{
			printf("%s", message);
				scanf("%f", &bufferint);
				if(bufferint >= minimum && bufferint <= maximum){
					*pResult = bufferint;
					returnAux= 0;
					break;
				}else{
					printf("%s", errorMessage);
					retry--;
				}

		}while(retry > 0);
	}
	return returnAux;
}

/**
 * \brief Solicita un numero flotante y después de verificarlo devuelve el resultado
 * \param pResult Puntero donde se dejara el resultado de la función
 * \param message es el mensaje
 * \param errorMessage es el mensaje de Error
 * \param minimum es el num maximo que acepta
 * \param maximum es el minimo a que acepta
 * \return returnAux 0 exito y -1 error
 *
 */
int utn_getNumberFloat(float* pResult, char* message, char* errorMessage, float minimum, float maximum, int retry)
{
	float bufferFloat;
	int returnAux = -1;
	while(retry >= 0)
	{
		retry--;
		printf("%s",message);
		if(getFloat(&bufferFloat) == 0)
		{
			if(bufferFloat >= minimum && bufferFloat <= maximum)
			{
				*pResult = bufferFloat;
				returnAux = 0;
				break;
			}
		}
		printf("%s",errorMessage);
	}
	return returnAux;
}


/**
 * \brief Verifica si la cadena que fue ingresada es numerica
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si es numerica, 0 (falso) si no  es y -1  caso de error
 *
 */
static int esNumerica(char* cadena, int limite)
{
	int retorno = -1; // CASO ERROR

	if(cadena != NULL && limite > 0)
	{
		retorno = 1; // VERDADERO
		for(int i = 0;i < limite && cadena[i] != '\0';i++)
		{
			if(i == 0 && (cadena[i] == '+' || cadena[i] == '-'))
			{
				continue;
			}
			if(cadena[i] < '0'||cadena[i] > '9')
			{
				retorno = 0;
				break;
			}

		}

	}
	return retorno;
}


/**
 * \brief Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena
 * 			un máximo de 'longitud - 1' caracteres.
 * \param pResultado Puntero al espacio de memoria donde se copiara la cadena obtenida
 * \param longitud Define el tamaño de cadena
 * \return Retorna 0 exito y -1 error
 *
 */
static int getString(char* cadena, int longitud)
{
	int retorno=-1;
	char bufferString[4096];

	if(cadena != NULL && longitud > 0)
	{
		fflush(stdin);

		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString)) <= longitud)
			{
				strncpy(cadena,bufferString,longitud);
				retorno=0;
			}
		}
	}
	return retorno;
}


/**
 * \brief Verifica si la cadena ingresada es flotante
 * \param pResultado Puntero donde se dejara el resultado de la funcion
 * \return Retorna 0 exito y -1 error
 *
 */
static int getFloat(float* pResult)
{
    int retorno=-1;
    char buffer[64];

    if(pResult != NULL)
    {
    	if(getString(buffer,sizeof(buffer))==0 && esFlotante(buffer))
    	{
			*pResult = atof(buffer);
			retorno = 0;
		}
    }
    return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es flotante
 * \param cadena Cadena de chars usada
 * \return Retorna 0 exito y -1 error
 *
 */
static int esFlotante(char* cadena)
{
	int i=0;
	int retorno = 1;
	int contadorPuntos=0;

	if(cadena != NULL && strlen(cadena) > 0)
	{
		for(i = 0 ; cadena[i] != '\0'; i++)
		{
			if(i == 0 && (cadena[i] == '-' || cadena[i] == '+'))
			{
				continue;
			}
			if(cadena[i] < '0' || cadena[i] > '9' )
			{
				if(cadena[i] == '.' && contadorPuntos == 0)
				{
					contadorPuntos++;
				}
				else
				{
					retorno = 0;
					break;
				}
			}
		}
	}
	return retorno;
}
/**
 * \brief Obtiene un string valido como nombre
 * \param pResultado Puntero donde se dejara el resultado de la funcion
 * \return Retorna 0 exito y -1 error
 *
 */
static int getNombre(char* pResultado, int longitud)
{
    int retorno=-1;
    char buffer[4096];

    if(pResultado != NULL)
    {
    	if(	getString(buffer,sizeof(buffer))==0 &&
    		esNombre(buffer,sizeof(buffer)) &&
			strnlen(buffer,sizeof(buffer))<longitud)
    	{
    		strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
    }
    return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es un nombre valido
 * \param cadena de chars
 * \return Retorna 0 exito y -1 error
 */
static int esNombre(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/**
 * \brief Solicita un nombre al usuario,valida y devuelve un resultado
 * \param pResult Puntero donde se dejara el resultado de la función
 * \param leng la longitud de resultado
 * \param message  es el mensaje
 * \param menssageError el mensaje de Error
 * \param retry Cant de reintentoS
 */

int utn_getName(char* pResult, int leng,char* message, char* errorMessage, int retry)
{
	char bufferString[4096];
	int returnAux = -1;
	while(retry>=0)
	{
		retry--;
		printf("%s",message);
		if(getNombre(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) < leng )
		{
			strncpy(pResult,bufferString,leng);
			returnAux = 0;
			break;
		}
		printf("%s",errorMessage);
	}
	return returnAux;
}

static int getCuit(char* pResultado, int longitud)
{
    int retorno=-1;
    char buffer[4096];

    if(pResultado != NULL)
    {
    	if(	getString(buffer,sizeof(buffer))==0 &&
    		esNumerica(buffer,sizeof(buffer)) &&
			strnlen(buffer,sizeof(buffer))<longitud)
    	{
    		strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
    }
    return retorno;
}

/**
 * \brief Solicita un CUIT al usuario, luego de verificarlo devuelve el resultado
 * \param pResult Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param leng Es la longitud del array resultado
 * \param message Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param reintentos Cantidad de reintentos
 * \return Retorna 0 si se obtuvo el numero flotante y -1 si no
 *
 */
int utn_getCuit(char* pResult, int leng,char* message, char* errorMessage, int retry)
{
	char bufferString[12];
	int retorno = -1;
	while(retry>=0)
	{
		retry--;
		printf("%s",message);
		if(getCuit(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) < leng )
		{
			strncpy(pResult,bufferString,leng);
			retorno = 0;
			break;
		}
		printf("%s",errorMessage);
	}
	return retorno;
}
/**
 * \brief Obtiene un string valido como descripcion
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
 *
 */
static int getDescripcion(char* pResultado, int longitud)
{
    int retorno=-1;
    char buffer[4096];

    if(pResultado != NULL)
    {
    	if(	getString(buffer,sizeof(buffer))==0 &&
    		esDescripcion(buffer,sizeof(buffer)) &&
			strnlen(buffer,sizeof(buffer))<longitud)
    	{
    		strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
    }
    return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es una descripcion valida
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es valida y 0 (falso) si no lo es
 *
 */
static int esDescripcion(char* cadena,int longitud)
{
	int i = 0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if(cadena[i] != '.' && cadena[i] != ' ' && (cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ) && (cadena[i] < '0' || cadena[i] > '9' ) )
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/**
 * \brief Solicita una descripcion al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param longitud Es la longitud del array resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param reintentos Cantidad de reintentos
 * \return Retorna 0 ok y -1  no
 *
 */
int utn_getDescription(char* pResult, int leng,char* message, char* errorMessage, int retry)
{
	char bufferString[4096];
	int retorno = -1;
	while(retry>=0)
	{
		retry--;
		printf("%s",message);
		if(getDescripcion(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) < leng )
		{
			strncpy(pResult,bufferString,leng);
			retorno = 0;
			break;
		}
		printf("%s",errorMessage);
	}
	return retorno;
}
