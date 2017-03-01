#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED
#define TRUE 1
#define FALSE 0

typedef char boolean;

typedef struct
{
    char conteo;
    float valor;
}elemento;

typedef struct
{
    elemento e;
    struct nodo *abajo;
}nodo;

typedef struct
{
    nodo *tope;
    int tamanio;
}pila;

//Encabezados de funciones

void Initialize(pila *s);
void Push(pila *s, elemento e);
elemento Pop(pila *s);
boolean Empty(pila *s);
int Size(pila *s);
void Destroy(pila *s);
elemento Tope(pila *s);

#endif // PILA_H_INCLUDED
