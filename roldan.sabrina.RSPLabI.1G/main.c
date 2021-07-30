#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "bicicleta.h"
#include <time.h>



int main()
{
    int option=0;
    int proximoId=0;
    int flagDatos=0;
    int flagId=0;


    LinkedList* listaBicicletas = ll_newLinkedList();

    do{
        switch(menu(&option))
        {
            case 1:
                if(flagId)
                {
                    proximoId=proximoId-1;
                }

                if(!flagDatos)
                {
                    if(controller_loadFromText(listaBicicletas,&proximoId))
                    {
                        printf("\n\nSe ha cargado el archivo de texto con exito!!\n\n");
                        flagDatos=1;
                    }
                    else
                    {
                        printf("\n\nError al cargar el archivo de texto\n\n");
                    }
                }
                else
                {
                    printf("\n\nLos datos ya han sido cargados previamente desde este archivo.\n\n");
                }
                break;

            case 2:
                if(ll_len(listaBicicletas)==0)
                {
                    printf("\n\nNo hay bicicletas cargadas al sistema\n\n");
                }
                else
                {
                    controller_ListBicicleta(listaBicicletas);
                }
                break;

            case 3:
                if(!flagDatos)
                {
                    printf("\nNo hay datos cargados para asignar valores\n\n");
                }
                else
                {
                    ll_map(listaBicicletas,bicicleta_aleatoryBicicletas);
                    printf("\n\nValores asignados con exito!\n\n");
                }
                break;

            case 4:
                if(ll_filter(listaBicicletas,bicicleta_filterTipo))
                {
                    if(!controller_saveAsText(ll_filter(listaBicicletas,bicicleta_filterTipo)))
                    {
                        printf("Error al guardar el archivo de texto\n");
                    }
                    else
                    {
                        printf("El archivo de texto se ha guardado con exito!\n\n");
                    }
                }
                else
                {
                    printf("Error al filtrar los campos\n");
                }
                break;

            case 5:
                controller_sortBicicleta(listaBicicletas);
                if(ll_len(listaBicicletas)==0)
                {
                    printf("\n\nNo hay bicicletas cargadas al sistema\n\n");
                }
                else
                {
                    controller_ListBicicleta(listaBicicletas);
                }
                break;

            case 6:
                if(!controller_saveAsText(listaBicicletas))
                    {
                        printf("Error al guardar el archivo de texto\n");
                    }
                    else
                    {
                        printf("El archivo de texto se ha guardado con exito!\n\n");
                    }
                break;

            case 7:
                printf("Ha salido del programa.\nHasta la proxima!!!\n\n");
                break;

            default:
                printf("Opcion no valida\n");
                fflush(stdin);
                break;
        }
        system("pause");

    }while(option != 7);

    return 0;
}

