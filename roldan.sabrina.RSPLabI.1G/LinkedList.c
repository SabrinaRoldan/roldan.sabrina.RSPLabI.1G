#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

/** \brief                      Obtiene un nodo de la lista
 *
 * \param this LinkedList*      Puntero a la lista
 * \param nodeIndex int         Indice del nodo a obtener
 * \return Node*                Retorna (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0
                                o mayor al len de la lista). Retorna (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex);


/** \brief                      Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList*      Puntero a la lista
 * \param nodeIndex int         Ubicacion donde se agregara el nuevo nodo
 * \param pElement void*        Puntero al elemento a ser contenido por el nuevo nodo
 * \return int                  Retorna (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= (LinkedList*) malloc(sizeof(LinkedList*));

    if(this!=NULL)
    {
        this->pFirstNode=NULL;
        this->size=0;
    }

    return this;
}

int ll_len(LinkedList* this)
{
    int cantidad=-1;

    if(this!=NULL)
    {
      cantidad=this->size;
    }

    return cantidad;
}

static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* auxNode=NULL;

    if(this!=NULL && nodeIndex>=0 && nodeIndex<ll_len(this) && nodeIndex<ll_len(this))
    {
        auxNode=this->pFirstNode;
        for(int i=0;i<nodeIndex;i++)
        {
            auxNode=auxNode->pNextNode;
        }
        return auxNode;
    }
    return NULL;
}

Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}

static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* node=NULL;
    Node* aux=NULL;

    if(this!=NULL && nodeIndex>=0 && nodeIndex<=ll_len(this))
    {
        node=(Node*) malloc(sizeof(Node));
        if(node!=NULL)
        {
            node->pElement=pElement;
            node->pNextNode=getNode(this, nodeIndex);
            if(nodeIndex==0)
            {
                this->pFirstNode=node;
            }
            else
            {
                aux=getNode(this,nodeIndex-1);
                aux->pNextNode=node;
            }
            this->size++;
            returnAux=0;
        }
    }

    return returnAux;
}

int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}

int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this!=NULL)
    {
        if(!addNode(this,ll_len(this),pElement))
        {
            returnAux=0;
        }
    }

    return returnAux;
}

void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* auxNode=NULL;

    if(this!=NULL && index>=0 && index<=ll_len(this))
    {
        auxNode=getNode(this,index);
        if(auxNode!=NULL)
        {
            returnAux=auxNode->pElement;
        }
    }

    return returnAux;
}

int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* auxNode=NULL;

    if(this!=NULL && index>=0 && index<ll_len(this))
    {
        auxNode=getNode(this,index);
        auxNode->pElement=pElement;
        returnAux=0;
    }

    return returnAux;
}

int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* anterior=NULL;
    Node* aux=NULL;

    if(this!=NULL && index>=0 && index<ll_len(this))
    {
        if(index==0)
        {
            aux=this->pFirstNode;
            this->pFirstNode=aux->pNextNode;
        }
        else
        {
            anterior=getNode(this,index-1);
            if(anterior!=NULL)
            {
                aux=anterior->pNextNode;
                anterior->pNextNode=aux->pNextNode;
            }
        }
        free(aux);
        this->size--;
        returnAux=0;
    }


    return returnAux;
}

int ll_clear(LinkedList* this)
{
    int returnAux = -1;

    if(this!=NULL)
    {
        while(ll_len(this)!=0)
        {
            ll_remove(this,0);
            returnAux=0;
        }
    }

    return returnAux;
}

int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this!=NULL)
    {
        if(!ll_clear(this))
        {
            free(this);
            returnAux=0;
        }
    }

    return returnAux;
}

int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if(this!=NULL)
    {
        int tam=ll_len(this);
        for(int i=0;i<tam;i++)
        {
            if(ll_get(this,i)==pElement)
            {
                returnAux=i;
                break;
            }
        }
    }

    return returnAux;
}

int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this!=NULL)
    {
        returnAux=1;
        if(ll_len(this)>0)
        {
            returnAux=0;
        }
    }

    return returnAux;
}

int ll_push(LinkedList* this, int index, void* pElement)
{
    return addNode(this,index,pElement);
}

void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;

    if(this!=NULL && index>=0 && index<ll_len(this))
    {
        returnAux=ll_get(this,index);
        if(ll_remove(this,index))
        {
           returnAux=NULL;
        }
    }

    return returnAux;
}

int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this!=NULL)
    {
        returnAux=1;
        if(ll_indexOf(this,pElement)==-1)
        {
            returnAux=0;
        }
    }

    return returnAux;
}

int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int tam;

    if(this!=NULL && this2!=NULL)
    {
        tam=ll_len(this2);
        returnAux=1;
        for(int i=0;i<tam;i++)
        {
            if(!ll_contains(this,ll_get(this2,i)))
            {
                returnAux=0;
                break;
            }
        }
    }


    return returnAux;
}

LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;

    if(this!=NULL && from>=0 && to>=from && to<=ll_len(this))
    {
        cloneArray=ll_newLinkedList();
        if(cloneArray!=NULL)
        {
            for(int i=from;i<to;i++)
            {
                ll_add(cloneArray,ll_get(this,i));
            }
        }
    }

    return cloneArray;
}

LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = this;

    return cloneArray;
}

int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    int tam;
    void* auxI=NULL;
    void* auxJ=NULL;

    if(this!=NULL && pFunc!=NULL && order>=0 && order<=1)
    {
        tam=ll_len(this);
        for(int i=0;i<tam-1;i++)
        {
            for(int j=i+1;j<tam;j++)
            {
                auxI=ll_get(this,i);
                auxJ=ll_get(this,j);
                if((pFunc(auxI,auxJ)<0 && !order)||
                   (pFunc(auxI,auxJ)>0 && order))
                {
                    ll_set(this,i,auxJ);
                    ll_set(this,j,auxI);
                }
            }
        }
        returnAux=0;
    }

    return returnAux;

}

LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void*))
{
    int tam;
    LinkedList* lista=NULL;
    void* aux=NULL;

    if(this!=NULL && pFunc!=NULL)
    {
        lista=ll_newLinkedList();
        if(this!=NULL)
        {
            tam=ll_len(this);
            for(int i=0;i<tam;i++)
            {
                aux=ll_get(this,i);
                if(pFunc(aux))
                {
                    ll_add(lista,aux);
                }
            }
        }
    }
    return lista;
}

LinkedList* ll_map (LinkedList* this, void*(*pFunc) (void* element))
{
    LinkedList* lista=NULL;
    void* aux=NULL;

    if(this!=NULL && pFunc!=NULL)
    {
        lista=ll_newLinkedList();
        int tam=ll_len(this);
        for(int i=0;i<tam;i++)
        {
            aux=ll_get(this,i);
            if(pFunc(aux))
            {
                ll_add(lista,aux);
            }
        }
    }

    return lista;
}
