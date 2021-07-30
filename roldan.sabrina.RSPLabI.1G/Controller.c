#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "bicicleta.h"
#include "parser.h"
#include "roldan.h"
#include <time.h>

int controller_loadFromText(LinkedList* pArrayListBicicleta,int* proximoId)
{
    int retorno=0;
    char path[128];

    if(utn_getEmail("Ingrese el nombre del archivo a cargar: ","Error.\n",3,128,4,path))
    {
        if(path!=NULL && pArrayListBicicleta!=NULL)
        {
            FILE* f=fopen(path,"r");
            if(parser_BicicletaFromText(f,pArrayListBicicleta,proximoId))
            {
                retorno=1;
                fclose(f);
            }
        }
    }

    return retorno;
}

int controller_loadFromBinary(LinkedList* pArrayListBicicleta,int* proximoId)
{
    int retorno=0;
    char path[128];

    if(utn_getEmail("Ingrese el nombre del archivo a cargar: ","Error.\n",3,128,4,path))
    {
        if(path!=NULL && pArrayListBicicleta!=NULL)
        {
            FILE* f=fopen(path,"rb");
            if(parser_BicicletaFromBinary(f,pArrayListBicicleta,proximoId))
            {
                retorno=1;
                fclose(f);
            }
        }
    }

    return retorno;
}

int controller_addBicicleta(LinkedList* pArrayListBicicleta, int* pId)
{
    int retorno=0;
    char nombre[128];
    char tipo[20];
	int tiempo;
    int id_bike;

    eBicicleta* auxBicicleta=bicicleta_new();

    if(pArrayListBicicleta!=NULL && ll_len(pArrayListBicicleta)>=0)
    {
        system("cls");
        printf("        Alta Bicicleta\n\n");

        if(*pId==0)
        {
            *pId=1;
        }

        id_bike=*pId;
        auxBicicleta->id_bike=id_bike;
        printf("ID: %4d\n\n",auxBicicleta->id_bike);

        if(!utn_getName("Ingrese el nombre del bicicleta: ","Error. ",2,129,4,nombre)&&
           !bicicleta_getNombre(auxBicicleta,nombre))
        {
            printf("Error al cargar el nombre.\n");
            return -1;
        }
        strcpy(auxBicicleta->nombre,nombre);

        if(!utn_getName("Ingrese el tipo de bicicleta: ","Error. ",2,20,4,tipo)&&
           !bicicleta_getTipo(auxBicicleta,tipo))
        {
            printf("Error al cargar el tipo.\n");
            return -1;
        }
        strcpy(auxBicicleta->tipo,tipo);


        if(!utn_getUnsignedInt("Ingrese cantidad de tiempo: ","Error.",1,7,0,1000000,4,&tiempo)&&
           !bicicleta_getTiempo(auxBicicleta,&tiempo))
        {
            printf("Error al cargar los tiempo.\n");
            return -1;
        }
        auxBicicleta->tiempo=tiempo;

        printf("\n\n");

        (*pId)++;

        retorno=1;

        ll_add(pArrayListBicicleta,auxBicicleta);

    }

    return retorno;
}

int controller_editBicicleta(LinkedList* pArrayListBicicleta)
{
    int retorno=0;
    int opcion;
    int id;
    char confirma;
    char nombre[128];
    char tipo[20];
	int tiempo;

    system("cls");
    printf("        Modificar Bicicleta\n\n");
    printf("Ingrese id: ");
    scanf("%d",&id);

    if(!(ll_get(pArrayListBicicleta,id-1)))
    {
        printf("\nNo existe una bicicleta con el id: %d\n", id);
    }
    else
    {
        id=id-1;
        printf("\n  ID                Nombre   Tipo   Tiempo  \n");
        mostrarBicicleta(ll_get(pArrayListBicicleta,id));
        printf("Confirma modificacion?: ");
        fflush(stdin);
        scanf("%c",&confirma);

        if(confirma=='s')
        {

            printf("        Opciones a modificar:\n\n");
            printf("1- Nombre\n");
            printf("2- Tipo\n");
            printf("3- Tiempo\n\n");
            printf("Ingrese opcion: ");
            fflush(stdin);
            scanf("%d",&opcion);

            switch(opcion){
                case 1:
                    if(!utn_getName("Ingrese el nombre del bicicleta: ","Error. ",2,129,4,nombre))
                    {
                        printf("Error al cargar el nombre.\n");
                        return -1;
                    }
                    bicicleta_setNombre(ll_get(pArrayListBicicleta,id),nombre);
                    break;

                case 2:
                    if(!utn_getName("Ingrese el nombre del bicicleta: ","Error. ",2,20,4,tipo))
                    {
                        printf("Error al cargar el tipo.\n");
                        return -1;
                    }
                    bicicleta_setTipo(ll_get(pArrayListBicicleta,id),tipo);
                    break;

                case 3:
                    if(!utn_getUnsignedInt("Ingrese tiempo: ","Error.",1,7,0,1000000,4,&tiempo))
                    {
                        printf("Error al cargar la cantidad de tiempo.\n");
                        return -1;
                    }
                    bicicleta_setTiempo(ll_get(pArrayListBicicleta,id),tiempo);
                    break;

                default:
                    printf("Opcion no valida\n");
                    break;
            }


            retorno=1;
        }
        else
        {
            printf("Modificacion cancelada por el usuario\n");
        }
    }

    return retorno;
}

int controller_removeBicicleta(LinkedList* pArrayListBicicleta)
{
    int retorno=0;
    int idUsuario;
    char confirma;

    system("cls");
    printf("        Baja Bicicleta\n\n");

    printf("Ingrese id: ");
    scanf("%d",&idUsuario);

    if(!(ll_get(pArrayListBicicleta,idUsuario-1)))
    {
        printf("\nNo existe un bicicleta con el id: %d\n", idUsuario);
    }
    else
    {
        idUsuario=idUsuario-1;

        printf("\n  ID                Nombre   Tipo  Tiempo  SinVacunar\n");
        mostrarBicicleta(ll_get(pArrayListBicicleta,idUsuario));
        printf("Confirma baja?: ");
        fflush(stdin);
        scanf("%c",&confirma);

        if(confirma=='s')
        {
            ll_remove(pArrayListBicicleta,idUsuario);
            retorno=1;
        }
        else
        {
            printf("Baja cancelada por el usuario\n");
        }
    }

    return retorno;
}

int controller_ListBicicleta(LinkedList* pArrayListBicicleta)
{
    char buffer[4][128];
    FILE* f=fopen("bicicletas.csv","r");

    if(f==NULL)
    {
        printf("No se pudo cargar el archivo\n");
    }

    //agrega el encabezado de cada columna para leerlo por consola
    fscanf(f,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);
    printf("%4s  %20s        %20s %10s\n",buffer[0],buffer[1],buffer[2],buffer[3]);

    for(int i=0;i<ll_len(pArrayListBicicleta);i++)
    {
        mostrarBicicleta(ll_get(pArrayListBicicleta,i));
    }

    fclose(f);
    return 1;
}

int controller_sortBicicleta(LinkedList* pArrayListBicicleta)
{
    int order;

    system("cls");
    if(!utn_getUnsignedInt("\t***   Tipo   ***\n\n***Orden de la lista a mostrar***"
    "\n\n1- Descendente\n2- Ascendente\n\nIngrese la opcion deseada: ","Error. "
    ,1,2,-1,2,4,&order))
    {
        printf("Error al cargar su los datos\n");
    }
    else
    {
        if(order==2)
        {
            order=0;
        }
        printf("\nEsperando status...\n\n");
        ll_sort(pArrayListBicicleta,bicicleta_compareTipo,order);
        printf("Ordenamiento exitoso!\n\n");
    }

    return 0;
}

int controller_saveAsText(LinkedList* pArrayListBicicleta)
{
    int retorno=0;
    int id_bike;
    int cant;
    char tipo[20];
	int tiempo;
    char nombre[128];
    char path[128];

    if(utn_getEmail("Ingrese el nombre del archivo a guardar: ","Error.\n",3,128,4,path))
    {
        FILE* f=fopen(path,"w");
        if(f==NULL)
        {
            printf("No se pudo guardar el archivo\n");
        }

        fprintf(f,"ID,Nombre,Tipo,Tiempo\n");

        for(int i=0;i<ll_len(pArrayListBicicleta);i++)
        {
            if(pArrayListBicicleta!=NULL)
            {
                bicicleta_getId(ll_get(pArrayListBicicleta,i),&id_bike);
                bicicleta_getNombre(ll_get(pArrayListBicicleta,i),nombre);
                bicicleta_getTipo(ll_get(pArrayListBicicleta,i),tipo);
                bicicleta_getTiempo(ll_get(pArrayListBicicleta,i),&tiempo);

                cant=fprintf(f,"%d,%s,%s,%d\n",
                         id_bike
                        ,nombre
                        ,tipo
                        ,tiempo);
                if(cant<4)
                {
                    break;
                }
                retorno=1;
            }
        }
        fclose(f);
    }

    return retorno;
}

int controller_saveAsBinary(LinkedList* pArrayListBicicleta)
{
    int cant;
    int retorno=0;
    char path[128];

    if(utn_getEmail("Ingrese el nombre del archivo a cargar: ","Error.\n",3,128,4,path))
    {
        FILE* f=fopen(path,"wb");

        if(f==NULL)
        {
            printf("No se pudo guardar el archivo\n");
            exit(1);
        }

        for(int i=0;i<ll_len(pArrayListBicicleta);i++)
        {
            if(pArrayListBicicleta!=NULL)
            {
                cant=fwrite(ll_get(pArrayListBicicleta,i),sizeof(eBicicleta),1,f);
                if(cant<1)
                {
                    printf("Error\n");
                    break;
                }
                retorno=1;
            }
        }

        fclose(f);
    }

    return retorno;
}

void* bicicleta_aleatoryBicicletas(void* bicicleta)
{
    eBicicleta* auxBicicleta=(eBicicleta*) bicicleta;

    if(auxBicicleta!=NULL)
    {
        auxBicicleta->tiempo=rand() % (120 - 50 +1)+50;
    }

    return auxBicicleta;
}
