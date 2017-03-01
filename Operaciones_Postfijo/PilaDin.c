#include <stdlib.h>
#include "PilaDin.h"

void
Initialize (pila *s)
{
  s->tamanio = 0;
  s->tope = NULL;

  return;
}

void
Push (pila *s, elemento e)
{
  nodo *nuevo_nodo = malloc (sizeof (nodo));

  nuevo_nodo->abajo = s->tope;
  s->tope = nuevo_nodo;
  s->tope->e = e;
  s->tamanio++;

  return;
}

elemento
Pop (pila *s)
{
  elemento retorno;
  nodo *auxiliar;

  retorno = s->tope->e;
  auxiliar = s->tope->abajo;
  free (s->tope);
  s->tope = auxiliar;
  s->tamanio--;

  return retorno;
}

boolean
Empty (pila *s)
{
  if(s->tope == NULL)
    return TRUE;
  
  return FALSE;
}

int
Size (pila *s)
{
  return s->tamanio;
}

void
Destroy (pila *s)
{
  nodo *auxiliar;

  while (s->tope != NULL)
    {
      auxiliar = s->tope->abajo;
      free (s->tope);
      s->tope = auxiliar;
    }

  s->tamanio = 0;

  return;
}

elemento
Top(pila *s)
{
  return s->tope->e;
}