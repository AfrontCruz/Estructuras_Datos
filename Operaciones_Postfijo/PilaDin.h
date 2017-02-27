#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED
#define TRUE 1
#define FALSE 0

typedef char boolean;

typedef struct
{
    char conteo;
    int valor;
}element;

typedef struct
{
    element e;
    struct nodo *abajo;
}nodo;

typedef struct
{
    nodo *tope;
    int tamanio;
}pila;

//Encabezados de funciones

void Initialize(pila *s);
void Push(pila *s, element e);
element Pop(pila *s);
boolean Empty(pila *s);
int Size(pila *s);
void Destroy(pila *s);

#endif // PILA_H_INCLUDED
