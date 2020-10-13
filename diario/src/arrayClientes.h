/*
 * cliente.h
 *
 *  Created on: Oct 12, 2020
 *      Author: ericka.diaz
 */

#ifndef ARRAYCLIENTES_H_
#define ARRAYCLIENTES_H_



#define NAME_LEN 51
#define LAST_NAME_LEN 51
#define CUIT_LEN 11

typedef struct {
	int id;
	char name[NAME_LEN];
	char lastName[LAST_NAME_LEN];
	char cuit;
	int isEmpty; //le pongo un uno o cero para "hacer" que los elimina

}Client;

int initClient(Client* list, int len);
int client_getEmptyIndex(Client* list,int len);
int addClient(Client* list, int len, int indice, int* id);
int findClientById(Client* list, int len,int id);
int modClient(Client* list, int len, int indice);
int removeClient(Client* list, int len, int id);
int client_imprimir(Client* list);
int printClient(Client* list, int length);


#endif /* CLIENTE_H_ */
