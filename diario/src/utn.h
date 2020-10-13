/*
 * utn.h
 *
 *  Created on: Oct 12, 2020
 *      Author: ericka.diaz
 */

#ifndef UTN_H_
#define UTN_H_

int utn_getNumber(int* pResult, char* message, char* errorMessage, int minimum, int maximum, int retry);
int utn_getNumberFloat(float* pResult, char* message, char* errorMessage, float minimum, float maximum, int retry);
int utn_getName(char* pResult, int leng,char* message, char* errorMessage, int retry);
int utn_getCuit(char* pResult, int leng,char* message, char* errorMessage, int retry);
int utn_getDescription(char* pResult, int leng,char* message, char* errorMessage, int retry);


#endif /* UTN_H_ */
