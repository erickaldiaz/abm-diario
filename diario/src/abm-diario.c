/*
 ============================================================================
 Name        : abm-diario.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "arrayClientes.h"
#include "arrayPublicaciones.h"
#include "utn.h"

#define QTY_CLIENTES 1000
#define QTY_PUBLICACIONES 1000

int main(void)
{
	setbuf (stdout,NULL);

	Client arrayClientes[QTY_CLIENTES];
//	Publicacion arrayPublicaciones[QTY_PUBLICACIONES];

	int option;
	int idClientes=0;
	int auxiliaryIndex;
	int auxiliaryId;




	if(initClient(arrayClientes,QTY_CLIENTES) == 0)
	{
		printf("Clientes inicializado correctamente\n");
	}
//	if(initPublicaciones(arrayPublicaciones,QTY_PUBLICACIONES) == 0)
//		{
//			printf("Publicaciones inicializado correctamente \n");
//		}

    do
    {

    	if(!utn_getNumber(	&option,
    								"\n\n1.ALTA de clientes"
    								"\n2.MODIFICAR clientes"
    								"\n3.BAJA de clientes"
    								"\n4.PUBLICAR"
    								"\n5.PAUSAR publicación"
    								"\n6.REANUDAD publicación"
    			                    "\n7.IMPRIMIR clientes"
    								"\n8.INFORMAR"
    								"\n9.SALIR\n\n","\nError option inválida",1,5,3) )
    	{
    		switch(option)
    		{
    			case 1:
    				auxiliaryIndex = client_getEmptyIndex(arrayClientes,QTY_CLIENTES);
    				if(auxiliaryIndex >= 0)
    				{
    					if(addClient(arrayClientes,QTY_CLIENTES,auxiliaryIndex,&idClientes) == 0)
    					{
    						printf("\ncarga con exito\n");
    					}
    					else
    					{
    						printf("\nNo se pueden cargar más clientes (Máximo: 1000 clientes)\n");
    					}
    				}
    				break;

    			case 2:

    					printClient(arrayClientes,QTY_CLIENTES);
    					if(utn_getNumber(&auxiliaryId,"\nIndique el ID del cliente a modificar:\n","\nID inválido\n",0,idClientes,2) == 0)
    					{
    						auxiliaryIndex = findClientById(arrayClientes,QTY_CLIENTES,auxiliaryId);
    						if(	auxiliaryIndex >= 0 && modClient(arrayClientes,QTY_CLIENTES,auxiliaryIndex) == 0)
    						{
    							printf("\nSe ha realizado la modifcación con éxito\n");
    						}
    					}
    				else
    				{
    					printf("Error! No es posible ingresar a esta opción antes de pasar por la 1\n\n");
    				}
    				break;

    			case 3:
    					printClient(arrayClientes,QTY_CLIENTES);
    					if(utn_getNumber(&auxiliaryId,"\nIndique el ID del cliente a dar de baja:\n","\nID inválido\n",0,idClientes,2) == 0)
    					{
    						auxiliaryIndex = findClientById(arrayClientes,QTY_CLIENTES,auxiliaryId);
    						if(	auxiliaryIndex >= 0 && removeClient(arrayClientes,QTY_CLIENTES,auxiliaryIndex) == 0)
    						{
    							printf("\nSe ha realizado la baja con exito\n");
    						}
    					}

    				else
    				{
    					printf("Error! No es posible ingresar a esta opción antes de pasar por la 1\n\n");
    				}
    				break;

//    			case 4:
//
//
//    			case 5:
//
//    			case 6:
//
//    			case 7:
//
//    			case 8:
//
//    			case 9:
//

    		}
    	}
    }while(option!=9);

	return EXIT_SUCCESS;
}
