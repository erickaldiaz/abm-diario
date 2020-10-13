/*
 * arrayPublicaciones.h
 *
 *  Created on: Oct 12, 2020
 *      Author: ericka.diaz
 */

#ifndef ARRAYPUBLICACIONES_H_
#define ARRAYPUBLICACIONES_H_

#define ACTIVO 1
#define PAUSADO 0
#define PUBLITEXTO 64

typedef struct{
	int rubro;
	int estado;
	int idPublicacion;
	int isEmpty;
	int idCliente;
	char textoDePublicacion[PUBLITEXTO];
}Publicacion;

int publi_imprimirSimple(Publicacion* pElemento);
int publi_inicializar(Publicacion* pArray,int limite);
int publi_getEmptyIndex(Publicacion* pArray,int limite);
int publi_alta(Publicacion* pArray,int limite, int indice, int* idPublicacion, int idCliente);

int publi_imprimir(Publicacion* pArray,int limite);
int publi_buscarId(Publicacion* pArray, int limite, int valorBuscado);
int publi_pausar(Publicacion* pArray,int limite, int indice);




#endif /* ARRAYPUBLICACIONES_H_ */
