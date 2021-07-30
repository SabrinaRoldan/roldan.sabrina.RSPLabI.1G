#include "LinkedList.h"

#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED



#endif // PARSER_H_INCLUDED

/** \brief                              Parsea los datos los datos de los paises desde el archivo data.csv (modo texto).
 *
 * \param path char*                    Toma la ruta donde se encuentra el archivo.
 * \param pArrayListPais LinkedList*    Puntero a LinkedList.
 * \return int                          Retorna 1 si funciona, 0 si no funciona.
 *
 */
int parser_BicicletaFromText(FILE* pFile , LinkedList* pArrayListBicicleta,int* proximoId);

/** \brief                              Parsea los datos los datos de los paises desde el archivo data.bin (modo binario).
 *
 * \param path char*                    Toma la ruta donde se encuentra el archivo.
 * \param pArrayListPais LinkedList*    Puntero a LinkedList.
 * \return int                          Retorna 1 si funciona, 0 si no funciona.
 *
 */
int parser_BicicletaFromBinary(FILE* pFile , LinkedList* pArrayListBicicleta,int* proximoId);
