/*Prototipos de funciones
Tipos de dato
Constantes
Struct elemento: Se queda abierto. se debe volver a crear el objeto*/

#define TRUE 1
#define FALSE 0

typedef char boolean;

typedef struct elemento
{
	int valor,resultado;
}elemento;

typedef struct nodo
{
	elemento e;
	struct nodo *abajo;
}nodo;

typedef struct pila
{
	nodo *tope;
	int tamano;
}pila;

//Inicializa la pila (recibe referencia de la pila)
void Initialize(pila* s);
void Destroy(pila *s);
void Push(elemento e, pila *s);
elemento Pop(pila *s);
int Size(pila *s);
boolean Empty(pila *s);
elemento Top(pila *s);
