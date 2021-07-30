#ifndef Controller_H_INCLUDED
#define Controller_H_INCLUDED

/** \brief                              Carga los datos de las bicicletas desde el archivo data.csv (modo texto).
 *
 * \param pArrayListBicicleta LinkedList*    Puntero a Linkedlist.
 * \param proximoId int*                Puntero al próximo id a ser usado.
 * \return int                          Retorna 1 si funciona. Retorna 0 si no funciona.
 *
 */
int controller_loadFromText(LinkedList* pArrayListBicicleta,int* proximoId);


/** \brief                              Carga los datos de las bicicletas desde el archivo data.bin (modo binario).
 *
 * \param pArrayListBicicleta LinkedList*    Puntero a Linkedlist.
 * \param proximoId int*                Puntero al próximo id a ser usado.
 * \return int                          Retorna 1 si funciona. Retorna 0 si no funciona.
 *
 */
int controller_loadFromBinary(LinkedList* pArrayListBicicleta,int* proximoId);


/** \brief                              Agrega un nuevo bicicleta a la lista.
 *
 * \param pArrayListBicicleta LinkedList*    Puntero a Linkedlist.
 * \param pId int*                      Puntero al próximo id a ser usado.
 * \return int                          Retorna 1 si funciona. Retorna 0 si no funciona.
 *
 */
int controller_addBicicleta(LinkedList* pArrayListBicicleta,int* pId);


/** \brief                              Modifica la informacion relacionada a un bicicleta en la lista.
 *
 * \param pArrayListBicicleta LinkedList*    Puntero a Linkedlist.
 * \return int                          Retorna 1 si funciona. Retorna 0 si no funciona.
 *
 */
int controller_editBicicleta(LinkedList* pArrayListBicicleta);


/** \brief                              Elimina un país de la lista.
 *
 * \param pArrayListBicicleta LinkedList*    Puntero a Linkedlist.
 * \return int                          Retorna 1 si funciona. Retorna 0 si no funciona.
 *
 */
int controller_removeBicicleta(LinkedList* pArrayListBicicleta);


/** \brief                              Muestra por consola las bicicletas de la lista.
 *
 * \param pArrayListBicicleta LinkedList*    Puntero a Linkedlist.
 * \return int                          Retorna 1 si funciona. Retorna 0 si no funciona.
 *
 */
int controller_ListBicicleta(LinkedList* pArrayListBicicleta);


/** \brief                              Ordena las bicicletas según criterio del usuario.
 *
 * \param pArrayListBicicleta LinkedList*    Puntero a Linkedlist.
 * \return int                          Retorna 1 si funciona. Retorna 0 si no funciona.
 *
 */
int controller_sortBicicleta(LinkedList* pArrayListBicicleta);


/** \brief                              Guarda la lista de bicicletaes como un archivo de texto.
 *
 * \param pArrayListBicicleta LinkedList*    Puntero a Linkedlist.
 * \return int                          Retorna 1 si funciona. Retorna 0 si no funciona.
 *
 */
int controller_saveAsText(LinkedList* pArrayListBicicleta);


/** \brief                              Guarda la lista de bicicletaes como un archivo binario.
 *
 * \param pArrayListBicicleta LinkedList*    Puntero a Linkedlist.
 * \return int                          Retorna 1 si funciona. Retorna 0 si no funciona.
 *
 */
int controller_saveAsBinary(LinkedList* pArrayListBicicleta);


/** \brief                              Provee valores aleatorios a las bicicletas de la lista.
 *
 * \param bicicleta void*                    Puntero a void.
 * \return void*                        Retorna un puntero a void.
 *
 */
void* bicicleta_aleatoryBicicletas(void* bicicleta);

#endif
