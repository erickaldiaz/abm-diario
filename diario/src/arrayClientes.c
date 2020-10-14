/*
 * cliente.c
 *
 *  Created on: Oct 12, 2020
 *      Author: ericka.diaz
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayClientes.h"
#include "utn.h"

/**
 * \brief Inicializa el array poniendo en todas las posiciones a isEmpty en 1
 * \param list Array de empleados a ser actualizado
 * \param len limite del array de empleados
 * \return Retorna 0  exito y -1 error
 *
 */
int initClient(Client* list, int len) {
	int reply=-1;
	int i;

	if(list != NULL && len > 0)
	{
		reply=0;
		for(i=0;i<len;i++)
		{
			list[i].isEmpty = 1;
		}
	}

return reply;
}


/**
 * \brief Buscar primera posicion vacia
 * \param list Array de empleados
 * \param len Limite del array de empleados
 * \return Retorna el indice de la posicion vacia y -1 error
 *
 */
int client_getEmptyIndex(Client* list,int len)
{
	int reply = -1;
	int i;
	if(list != NULL && len > 0)
	{
		for(i = 0; i < len ; i++)
		{
			if(list[i].isEmpty == 1)
			{
				reply = i;
				break;
			}
		}
	}
	return reply;
}

/**
 * \brief Da de alta un empleado en una posicion del array
 * \param list Array de empleados a ser actualizado
 * \param len limite del array de empleados
 * \param indice posicion a ser actualizada
 * \param id identificador a ser asignado al empleado
 * \return Retorna 0  exito y -1 error
 *
 */
int addClient(Client* list, int len, int indice, int* id)
{
	int reply = -1;
	Client bufferCliente;

	if(list != NULL && len > 0 && indice < len && indice >= 0 && id != NULL)
	{
		if(	utn_getName(bufferCliente.name,NAME_LEN,"\nNombre del cliente?\n","\nERROR\n",2) == 0 &&
			utn_getName(bufferCliente.lastName,LAST_NAME_LEN,"\nApellido del cliente?\n","\nERROR\n",2) == 0 &&
			utn_getCuit(bufferCliente.cuit,CUIT_LEN,"\nCuit del cliente?\n","\nERROR2\n",2) == 0)
		{
			reply = 0;
			bufferCliente.id = *id;
			bufferCliente.isEmpty = 0;
			list[indice] = bufferCliente;
			(*id)++;
		}
	}
	return reply;
}

/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param list Array de empleados
* \param len Limite del array de empleados
* \param id Puntero a la posicion del array donde se encuentra el valor buscado
*/
int findClientById(Client* list, int len,int id)
{
	int reply = -1;
	int i;

	if(list != NULL && len > 0 && id >= 0)
	{
		for(i = 0;i < len; i++)
		{
			if(list[i].id == id)
			{
				reply = i;
				break;
			}
		}
	}
	return reply;
}


/**
 * \brief Actualiza los datos de un empleado en una posicion del array
 * \param list Array de empleados a ser actualizado
 * \param len Limite del array de empleados
 * \param indice Posicion a ser actualizada
 * \return Retorna 0  exito y -1 error
 *
 */
int modClient(Client* list, int len, int indice)
{
	int reply=-1;
	int opcion;
	Client arrayAuxiliary;

	if(list != NULL && len > 0 && indice < len && indice >= 0 && list[indice].isEmpty == 0)
	{
		if(utn_getNumber(&opcion,"\n\nIngrese el numero de lo que desea modificar: \n1-Nombre \n2-Apellido"
					"\n3-Cuit\n\n","\nError opción inválida",1,3,2)==0)
		{
			switch(opcion)
			{
				case 1:
					if(utn_getName(arrayAuxiliary.name,NAME_LEN,"\nIngrese el nuevo nombre:\n","\nNombre inválido\n",2) ==0)
					{
						strncpy(list[indice].name,arrayAuxiliary.name,NAME_LEN);
					}
					break;

			    case 2:
					if(utn_getName(arrayAuxiliary.lastName,LAST_NAME_LEN,"\nIngrese el nuevo apellido:\n","\nApellido inválido\n",2) == 0)
					{
						strncpy(list[indice].lastName,arrayAuxiliary.lastName,LAST_NAME_LEN);
					}
			    	break;

			    case 3:
			    	if(utn_getCuit(arrayAuxiliary.cuit,CUIT_LEN,"\nIngrese el nuevo CUIT:\n","\nCUIT inválido\n",2) == 0)
			    	{
			    		strncpy(list[indice].cuit,arrayAuxiliary.cuit,CUIT_LEN);
			    	}
			    	break;

			 }
			reply = 0;
		}
	}
	return reply;
}

/**
 * \brief Elimina lo cargado en una posicion del array
 * \param list Array de empleados a ser actualizado
 * \param len Limite del array de empleados
 * \param id Posicion a ser actualizada
 * \return retorna 0  exito y -1 error
 *
 */
int removeClient(Client* list, int len, int id)
{
	int reply = -1;
	if(list != NULL && len > 0 && id < len && id >= 0 && list[id].isEmpty == 0)
	{
		list[id].isEmpty = 1;
		reply = 0;
	}
	return reply;
}

/**
 * \brief Imprime los datos de un empleado
 * \param list Puntero al empleado que se busca imprimir
 * \return Retorna 0  exito y -1 error
 *
 */
int client_imprimir(Client* list)
{
	int reply=-1;
	if(list != NULL && list->isEmpty == 0)
	{
		reply=0;
		printf("\nID del Empleado: %d \nNombre: %s \nApellido: %s\n",list->id,list->name,list->lastName);
	}
	return reply;
}

/**
 * \brief Imprime la lista de empleados
 * \param list Array de empleados a imprimir
 * \return Retorna 0  exito y -1 error
 *
 */
int printClient(Client* list, int length)
{
	int reply = -1;
	int i;
	if(list != NULL && length > 0)
	{
		reply = 0;
		for(i = 0;i < length; i++)
		{
			client_imprimir(&list[i]);
		}
	}
	return reply;
}
