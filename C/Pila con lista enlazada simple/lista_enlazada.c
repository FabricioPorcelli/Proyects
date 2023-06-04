#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// ***********************************************************
typedef struct nodo{
    int dato;
    struct nodo *next;
} NODO;
// ***********************************************************
typedef struct lista{
    NODO *inicio;
} LISTA; // representa la lista enlazada
// ***********************************************************
NODO *crearNodo(int valor)
{
    NODO *nuevoNodo = (NODO *)malloc(sizeof(NODO));
    nuevoNodo->dato = valor;
    nuevoNodo->next = NULL;
    return nuevoNodo;
}
// ***********************************************************
LISTA *crearLista()
{
    LISTA *listaEN = (LISTA *)malloc(sizeof(LISTA));
    listaEN->inicio = NULL;
    return listaEN;
}
// ***********************************************************
void listar(LISTA *listaEN, int valor)
{
    NODO *nodo = crearNodo(valor);
    NODO *aux = NULL;
    if (listaEN->inicio == NULL) // lista vacia?
    {
        listaEN->inicio = nodo;
    }
    else
    {
        aux = listaEN->inicio; // direccion de memoria de aux = direccion de memoria del nodo inicial
        while(aux->next != NULL){ // va recorriendo los nodos en la lista
            aux = aux->next;
        }
        aux->next = nodo; // se queda con la direccion del ultimo nodo y almacena el nodo nuevo
    }
}
// ***********************************************************
void imprimir(LISTA listaEN){
    NODO* aux = NULL; // auxiliar
    aux = listaEN.inicio;
    while (aux != NULL)
    {
        printf("VALOR = %d \t",aux->dato);
        printf("NEXT = %X \n",aux->next);
        aux = aux->next;
    }
}
// ***********************************************************
void destruirLISTA(LISTA *listaABorrar)
{
    free(listaABorrar);
}
// ***********************************************************
void deslistar(LISTA *listaEN, int valor){
    NODO *aux = NULL;
    if (listaEN->inicio == NULL) // lista vacia?
    {
        printf("La lista esta vacia.\n");
    }
    else
    {
        aux = listaEN->inicio; // direccion de memoria de aux = direccion de memoria del nodo inicial
        while(aux->next != NULL){ // va recorriendo los nodos en la lista
            if (aux->next != NULL)
            {
                aux = aux->next;
                aux->dato = 0;
                aux->next = NULL;
            }
        }
    }
}
// ***********************************************************
int main()
{
    printf("sizeof(LISTA) = %d\n",sizeof(LISTA));
    printf("sizeof(NODO) = %d\n",sizeof(NODO));

    LISTA* lista = crearLista();
    listar(lista, 347);
    // int* A = (int*)malloc(sizeof(int));
    // printf("sizeof int %d\n",sizeof(int));
    listar(lista, 353);
    listar(lista, 358);
    printf("\t     dir lista %X \n",lista->inicio);
    imprimir(*lista);

    destruirLISTA(lista);
    // free(A);
    // NODO *listaDeNodos;
    // listaDeNodos = NULL;

    // int valor;

    // printf("Ingrese un valor para la lista: ");
    // scanf("%d", &valor);
    // listaDeNodos = crearNodo(valor);

    // printf("Valor en la lista: %d\n", listaDeNodos->dato);
    // printf("Direccion del siguiente valor: %d\n", listaDeNodos->next);

    // destruirNodo(listaDeNodos);
    return 0;
}