#include <stdlib.h>
#include "pila.h"

void Initialize(pila *s)
{
    s->tamanio = 0;
    s->tope = NULL;

    return;
}

void Push(pila *s, element e)
{
    nodo *nuevo_nodo = malloc(sizeof(nodo));

    nuevo_nodo->abajo = s->tope;
    s->tope = nuevo_nodo;
    s->tope->e = e;
    s->tamanio++;

    return;
}

element Pop(pila *s)
{
    element retorno;
    nodo *auxiliar;

    retorno = s->tope->e;
    auxiliar = s->tope->abajo;
    free(s->tope);
    s->tope = auxiliar;
    s->tamanio--;

    return retorno;
}

boolean Empty(pila *s)
{
    boolean empty;

    if(s->tamanio = 0)
        empty = TRUE;
    else
        empty = FALSE;

    return empty;
}

int Size(pila *s)
{
    return s->tamanio;
}

void Destroy(pila *s)
{
    nodo* auxiliar;

    while(s->tope != NULL)
    {
        auxiliar = s->tope->abajo;
        free(s->tope);
        s->tope = auxiliar;
    }

    s->tamanio = 0;

    return;
}
