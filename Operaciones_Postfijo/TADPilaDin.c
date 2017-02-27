/*Definicion de las funciones.*/

#include <stdlib.h>
#include <TADPila.h>

void Initialize(pila* s)
{
	s->tope = NULL;
	s->tamano = 0;
	return;
}
void Destroy(pila *s)
{
	nodo *aux;
	while(s->tope != NULL)
	{
		aux = s->tope->abajo;
		free(s->tope);
		s->tope = aux;
	}
	return;
}
void Push(elemento e, pila *s)
{
	nodo *auxiliar;
	auxiliar = malloc(sizeof(nodo));
	//se omite la validación
	auxiliar->abajo = s->tope;
	s->tope = aux;
	auxiliar->e = e;
	s->tamano++;
	return;
}
elemento Pop(pila *s)
{
	elemento r;
	nodo *auxiliar;
	r = s->tope->e;
	auxiiar = s->tope->abajo;
	free(s->tope);
	s->tope = auxiiar;
	s->tamano--;
	return r;
}
int Size(pila *s)
{
	return s->tamano;
}
/*Declaracion alternativa sin int tamano*/

/*int size(pila *s)
{
	nodo*aux;
	int tamanio = 0;
	aux = s->tope;
	
	while(aux != NULL)
	{
		aux = aux->abajo;
		tamanio++;
	}
	return tamanio;
}*/
boolean Empty(pila *s)
{
	if(s->tope == NULL)
		return TRUE;
	return FALSE;
}
elemento Top(pila *s)
{
	return s->tope->e;
}
