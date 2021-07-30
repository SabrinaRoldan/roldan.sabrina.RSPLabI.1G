#include "LinkedList.h"

#ifndef BICICLETA_H_INCLUDED
#define BICICLETA_H_INCLUDED
typedef struct
{
    int id_bike;
    char nombre[128];
    char tipo[20];
    int tiempo;
}eBicicleta;

int menu(int* opcion);

/** \brief                          Crea una nueva bicicleta.
 *
 * \return eBicicleta*                    Retorna una bicicleta.
 *
 */
eBicicleta* bicicleta_new();

/** \brief                          Crea nuevos parametros para la bicicleta casteados a string.
 *
 * \param id_bikeStr char*               Id de bicicleta.
 * \param nombreStr char*           Nombre de la bicicleta.
 * \param tipoStr char*  			tipo de la bicicleta.
 * \param tiempoStr char*        		tiempo de la bicicleta.
 * \return eBicicleta*                    Retorna un bicicleta.
 *
 */
eBicicleta* bicicleta_newParametros(char* id_bikeStr,char* nombreStr,char* tipoStr,char* tiempoStr);

/** \brief                          Elimina un bicicleta.
 *
 * \param bicicleta eBicicleta*                Estructura Empleado.
 * \return void                     No retorna valores.
 *
 */
void bicicleta_delete(eBicicleta* bicicleta);

/** \brief                          Setter de Id de bicicleta.
 *
 * \param this eBicicleta*                Estructura bicicleta.
 * \param id_bike int                    Id de bicicleta.
 * \return int                      Retorna 1 si está todo bien ó 0 si falla.
 *
 */
int bicicleta_setId(eBicicleta* this,int id_bike);

/** \brief                          Getter de Id de bicicleta.
 *
 * \param this eBicicleta*                Estructura bicicleta.
 * \param id_bike int                    Id de bicicleta.
 * \return int                      Retorna 1 si está todo bien ó 0 si falla.
 *
 */
int bicicleta_getId(eBicicleta* this,int* id_bike);

/** \brief                          Setter de nombre de bicicleta.
 *
 * \param this eBicicleta*                Estructura bicicleta.
 * \param nombre char*              Nombre de bicicleta.
 * \return int                      Retorna 1 si está todo bien ó 0 si falla.
 *
 */
int bicicleta_setNombre(eBicicleta* this,char* nombre);

/** \brief                          Getter de nombre de bicicleta.
 *
 * \param this eBicicleta*                Estructura bicicleta.
 * \param nombre char*              Nombre de bicicleta.
 * \return int                      Retorna 1 si está todo bien ó 0 si falla.
 *
 */
int bicicleta_getNombre(eBicicleta* this,char* nombre);

/** \brief                          Setter de las horas trabajadas de bicicleta.
 *
 * \param this eBicicleta*                Estructura bicicleta.
 * \param horasTrabajadas int       tipo de bicicleta.
 * \return int                      Retorna 1 si está todo bien ó 0 si falla.
 *
 */
int bicicleta_setTipo(eBicicleta* this,char* tipo);

/** \brief                          Getter de las horas trabajadas de bicicleta.
 *
 * \param this eBicicleta*                Estructura bicicleta.
 * \param horasTrabajadas int       tipo de bicicleta.
 * \return int                      Retorna 1 si está todo bien ó 0 si falla.
 */
int bicicleta_getTipo(eBicicleta* this,char* tipo);

/** \brief                          Setter de tipo de bicicleta.
 *
 * \param this eBicicleta*                Estructura bicicleta.
 * \param tipo int             Tipo de bicicleta.
 * \return int                      Retorna 1 si está todo bien ó 0 si falla.
 *
 */
int bicicleta_setTiempo(eBicicleta* this,int tiempo);

/** \brief                          Getter de tipo de bicicleta.
 *
 * \param this eBicicleta*                Estructura bicicleta.
 * \param tipo int             Tipo de bicicleta.
 * \return int                      Retorna 1 si está todo bien ó 0 si falla.
 *
 */
int bicicleta_getTiempo(eBicicleta* this,int* tiempo);

/** \brief                          Muestra la bicicleta con sus valores.
 *
 * \param this eBicicleta*                Estructura bicicleta.
 * \return int                      Retorna 1 si está todo bien ó 0 si falla.
 *
 */
int mostrarBicicleta(eBicicleta* this);

/** \brief                          Compara Ids de bicicletas.
 *
 * \param bicicleta1 void*               Primer bicicleta a comparar.
 * \param bicicleta2 void*               Segundo bicicleta a comparar.
 * \return int                      Retorna -1 si el 1er bicicleta es mayor al segundo.
 *
 */
int bicicleta_compareId(void* bicicleta1, void* bicicleta2);

/** \brief                          Compara Nombres de bicicletas.
 *
 * \param bicicleta1 void*               Primer bicicleta a comparar.
 * \param bicicleta2 void*               Segundo bicicleta a comparar.
 * \return int                      Retorna -1 si el 1er bicicleta es mayor al segundo.
 *
 */
int bicicleta_compareNombre(void* bicicleta1, void* bicicleta2);

/** \brief                          Compara Horas Trabajadas de bicicletas.
 *
 * \param bicicleta1 void*               Primer bicicleta a comparar.
 * \param bicicleta2 void*               Segundo bicicleta a comparar.
 * \return int                      Retorna -1 si el 1er bicicleta es mayor al segundo.
 *
 */
int bicicleta_compareTipo(void* bicicleta1, void* bicicleta2);

/** \brief                          Compara Tipos de bicicletas.
 *
 * \param bicicleta1 void*               Primer bicicleta a comparar.
 * \param bicicleta2 void*               Segundo bicicleta a comparar.
 * \return int                      Retorna -1 si el 1er bicicleta es mayor al segundo.
 *
 */
int bicicleta_compareTiempo(void* bicicleta1, void* bicicleta2);

/** \brief                          Retorna una lista con los bicicletaes más castigados.
 *
 * \param bicicleta1 LinkedList*         Puntero a Linkedlist.
 * \return int                      Retorna el mayor porcentaje de poblacion sin vacunar.
 *
 */
int bicicleta_masCastigado(LinkedList* bicicleta1);

/** \brief                          Filtra por bicicletaes con un 30% de vacunacion de la 2da dosis.
 *
 * \param bicicleta1 void*               Puntero a void.
 * \return int                      Retorna 1 si está todo bien ó 0 si falla.
 *
 */
int bicicleta_filterTipo(void* bicicleta);

/** \brief                          Filtra por bicicletaes donde el porcentaje sin vacunar es mayor al vacunado.
 *
 * \param bicicleta1 void*               Puntero a void.
 * \return int                      Retorna 1 si está todo bien ó 0 si falla.
 *
 */
int bicicleta_filterAlHorno(void* bicicleta1);


#endif // BICICLETA_H_INCLUDED
