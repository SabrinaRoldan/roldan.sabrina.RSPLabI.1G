#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bicicleta.h"
#include "roldan.h"

int menu(int* opcion)
{
    system("cls");
    printf("        ***  Menu de opciones  ***\n\n");
    printf("  1- Cargar archivo\n");
    printf("  2- Imprimir lista\n");
    printf("  3- Asignar tiempos\n");
    printf("  4- Filtrar por tipo\n");
    printf("  5- Mostrar posiciones\n");
    printf("  6- Guardar posiciones\n");
    printf("  7- Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d",opcion);

    return *opcion;

}

eBicicleta* bicicleta_new()
{
    eBicicleta* nuevoBicicleta=(eBicicleta*) malloc(sizeof(eBicicleta));

    if(nuevoBicicleta!=NULL)
    {
        nuevoBicicleta->id_bike=0;
        strcpy(nuevoBicicleta->nombre,"");
        strcpy(nuevoBicicleta->tipo,"");
        nuevoBicicleta->tiempo=0;
    }

    return nuevoBicicleta;

}

eBicicleta* bicicleta_newParametros(char* id_bikeStr,char* nombreStr,char* tipoStr,char* tiempoStr)
{
    eBicicleta* nuevoBicicleta=bicicleta_new();

    if(nuevoBicicleta!=NULL)
    {
        if(!(bicicleta_setId(nuevoBicicleta,atoi(id_bikeStr)) &&
           bicicleta_setNombre(nuevoBicicleta,nombreStr) &&
           bicicleta_setTipo(nuevoBicicleta,tipoStr) &&
           bicicleta_setTiempo(nuevoBicicleta,atoi(tiempoStr)))
           )
        {
            free(nuevoBicicleta);
            nuevoBicicleta=NULL;
        }
    }

    return nuevoBicicleta;
}

void bicicleta_delete(eBicicleta* bicicleta)
{
    if(bicicleta!=NULL)
    {
        free(bicicleta);
    }
}

int bicicleta_setId(eBicicleta* this,int id_bike)
{
    int retorno=0;

    if(this!=NULL && id_bike>0)
    {
        this->id_bike=id_bike;
        retorno=1;
    }

    return retorno;
}

int bicicleta_getId(eBicicleta* this,int* id_bike)
{
    int retorno=0;

    if(this!=NULL && id_bike!=NULL)
    {
        *id_bike=this->id_bike;
        retorno=1;
    }

    return retorno;
}

int bicicleta_setNombre(eBicicleta* this,char* nombre)
{
    int retorno=0;

    if(this!=NULL && nombre!=NULL && strlen(nombre)>=2 && strlen(nombre)<=128)
    {
        strcpy(this->nombre,nombre);
        retorno=1;
    }

    return retorno;
}

int bicicleta_getNombre(eBicicleta* this,char* nombre)
{
    int retorno=0;

    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=1;
    }

    return retorno;
}

int bicicleta_setTipo(eBicicleta* this,char* tipo)
{
    int retorno=0;

    if(this!=NULL && tipo!=NULL && strlen(tipo)>=2 && strlen(tipo)<=128)
    {
        strcpy(this->tipo,tipo);
        retorno=1;
    }

    return retorno;
}

int bicicleta_getTipo(eBicicleta* this,char* tipo)
{
    int retorno=0;

    if(this!=NULL && tipo!=NULL)
    {
        strcpy(tipo,this->tipo);
        retorno=1;
    }

    return retorno;
}

int bicicleta_setTiempo(eBicicleta* this,int tiempo)
{
    int retorno=0;

    if(this!=NULL && tiempo>=0)
    {
        this->tiempo=tiempo;
        retorno=1;
    }

    return retorno;
}

int bicicleta_getTiempo(eBicicleta* this,int* tiempo)
{
    int retorno=0;

    if(this!=NULL && tiempo!=NULL)
    {
        *tiempo=this->tiempo;
        retorno=1;
    }

    return retorno;
}

int mostrarBicicleta(eBicicleta* this)
{
    int retorno=0;

    if(this!=NULL)
    {
      printf("   %4d  %20s        %20s     %6d\n"
           ,this->id_bike
           ,this->nombre
           ,this->tipo
           ,this->tiempo);
        retorno=1;
    }

    return retorno;
}

int bicicleta_compareId(void* bicicleta1, void* bicicleta2)
{
    int retorno=0;

    eBicicleta* p1=NULL;
    eBicicleta* p2=NULL;

    if(bicicleta1!=NULL && bicicleta2!=NULL)
    {
        p1=(eBicicleta*) bicicleta1;
        p2=(eBicicleta*) bicicleta2;

        if((p1->id_bike)>(p2->id_bike))
        {
            retorno=-1;
        }
        else if((p1->id_bike)<(p2->id_bike))
        {
            retorno=1;
        }
    }
    return retorno;
}

int bicicleta_compareNombre(void* bicicleta1, void* bicicleta2)
{
    int retorno=0;

    eBicicleta* p1=NULL;
    eBicicleta* p2=NULL;

    if(bicicleta1!=NULL && bicicleta2!=NULL)
    {
        p1=(eBicicleta*) bicicleta1;
        p2=(eBicicleta*) bicicleta2;

        if(strcmp(p1->nombre,p2->nombre)>0)
        {
            retorno=-1;
        }
        else if(strcmp(p1->nombre,p2->nombre)<0)
        {
            retorno=1;
        }
    }
    return retorno;
}

int bicicleta_compareTipo(void* bicicleta1, void* bicicleta2)
{
    int retorno=0;

    eBicicleta* p1=NULL;
    eBicicleta* p2=NULL;

    if(bicicleta1!=NULL && bicicleta2!=NULL)
    {
        p1=(eBicicleta*) bicicleta1;
        p2=(eBicicleta*) bicicleta2;

        if(strcmp(p1->tipo,p2->tipo)>0 || (strcmp(p1->tipo,p2->tipo)==0 && (p1->tiempo)>(p2->tiempo)))
        {
            retorno=-1;
        }
        else if(strcmp(p1->tipo,p2->tipo)<0 || (strcmp(p1->tipo,p2->tipo)==0 && (p1->tiempo)<(p2->tiempo)))
        {
            retorno=1;
        }
    }
    return retorno;
}

int bicicleta_compareTiempo(void* bicicleta1, void* bicicleta2)
{
    int retorno=0;

    eBicicleta* p1=NULL;
    eBicicleta* p2=NULL;

    if(bicicleta1!=NULL && bicicleta2!=NULL)
    {
        p1=(eBicicleta*) bicicleta1;
        p2=(eBicicleta*) bicicleta2;

        if((p1->tiempo)>(p2->tiempo))
        {
            retorno=-1;
        }
        else if((p1->tiempo)<(p2->tiempo))
        {
            retorno=1;
        }
    }
    return retorno;
}

int bicicleta_filterTipo(void* bicicleta)
{
    int retorno=0;
    eBicicleta* bicicleta1=NULL;


    if(bicicleta!=NULL)
    {
        bicicleta1=(eBicicleta*) bicicleta;
        if(!strcmp(bicicleta1->tipo,"BMX"))
        retorno=1;
    }
    return retorno;
}
