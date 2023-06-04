/* pilaLista .c */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
// #include "pilaLista.h"

// int desapila(pila **);

// void vaciaPila(pila **);

// int tamanio(pila *);

// int estaVacia(pila **);

// int cima(pila *);

// node* apila(node *cima, int valor) // recibe la cima y el valor a apilar
// {


// }

typedef struct nodo
{
    int dato;
    struct nodo* next;
} NODE;

NODE* crearNodo(NODE *cima, int valor){
    NODE* nuevoNodo;
    nuevoNodo = (NODE *)malloc(sizeof(NODE));
    nuevoNodo->next = NULL;
    nuevoNodo->dato = valor;
    if (cima == NULL)
    {
        cima = nuevoNodo;
    }
    return nuevoNodo;
}

int main()
{
    NODE* cima;
    cima = NULL;
    printf("%d \n",cima->dato);
    cima = crearNodo(cima,347);
    printf("%d \n",cima->dato);

    free(cima);
    return 0;
}