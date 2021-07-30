#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "LinkedList.h"
#include "bicicleta.h"

int parser_BicicletaFromText(FILE* pFile, LinkedList* pArrayListBicicleta,int* proximoId)
{
    int retorno=0;
    int cant;
    int nuevoId;
    char buffer[3][128];

    eBicicleta* bicicleta=bicicleta_new();
    if(pFile==NULL)
        {
            printf("No se pudo cargar el archivo\n");
        }

        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);

        do
        {
            cant=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);

            if(cant<4)
            {
                printf("Error al cargar el archivo.\n");
                break;
            }

            bicicleta=bicicleta_newParametros((itoa((atoi(buffer[0])+(*proximoId)),buffer[0],10)),buffer[1],buffer[2],buffer[3]);

            if(bicicleta==NULL)
            {
                printf("Error al cargar la bicicleta.\n");
            }
            else
            {
                ll_add(pArrayListBicicleta,bicicleta);
                retorno=1;
            }


        }while(!feof(pFile));

        nuevoId=atoi(buffer[0])+(*proximoId);
        *proximoId=nuevoId;
        (*proximoId)++;
        return retorno;
}

int parser_BicicletaFromBinary(FILE* pFile , LinkedList* pArrayListBicicleta,int* proximoId)
{
    int cant;
    int retorno=0;
    int nuevoId;

    if(pFile==NULL)
    {
        printf("No se pudo abrir  el archivo\n");
    }

    while(!feof(pFile))
    {
        eBicicleta* bicicleta=bicicleta_new();
        if(bicicleta!=NULL)
        {
            cant=fread(bicicleta,sizeof(eBicicleta),1,pFile);

            if(cant<1)
            {
                break;
            }
            ll_add(pArrayListBicicleta,bicicleta);
            bicicleta->id_bike=bicicleta->id_bike+(*proximoId);
            nuevoId=bicicleta->id_bike;
            bicicleta=NULL;
            retorno=1;
        }
    }

    *proximoId=nuevoId;
    (*proximoId)++;


    return retorno;
}
