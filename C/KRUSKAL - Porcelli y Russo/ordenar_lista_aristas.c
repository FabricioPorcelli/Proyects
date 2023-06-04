/* ordenar_lista_aristas.c*/

#include <stdio.h>
#include <stdlib.h>
#include "ordenar_lista_aristas.h"

//************************************************************************
typedef struct arista
{
    int numeroArista;
    int V1;
    int V2;
    int peso;
    struct arista *next;
} arista;
//****CrearArista: Funcion que crea todas las aristas que se ingresan.
arista *crearArista(int numeroArista, int V1, int V2, int peso)
{
    arista *nuevaArista = (arista *)malloc(sizeof(arista));
    nuevaArista->V1 = V1;
    nuevaArista->V2 = V2;
    nuevaArista->numeroArista = numeroArista;
    nuevaArista->peso = peso;
    nuevaArista->next = NULL;
    return nuevaArista;
} // crearArista
//***Insertar: Inserta la arista en la cola de prioridad de acuerdo al peso
struct arista *insertar(struct arista *top, struct arista *nuevo)
{
    struct arista *actual = top;        // puntero para moverse por la lista
    struct arista *anterior = NULL;     //puntero al elemento anterior al "actual"
    
    /* Búsqueda del punto de inserción */
    while ((actual != NULL) && (actual->peso >= nuevo->peso))
    {
        anterior = actual;
        actual = actual->next;
    }
    
    /* Inserción */
    if (anterior != NULL)           // inserción en medio o final
        anterior->next = nuevo;
    else                            // inserción al principio de la lista
        top = nuevo;
    nuevo->next = actual;

    return top;                     // devuelve la cabecera de la lista
} // insertar
//***Listado: funcion que imprime la lista ingresada
void listado(struct arista *top)
{
    int pesoTotal = 0;
    struct arista *aux = top; /* Puntero para recorrer la lista */
    while (aux)
    { /* Bucle que recorre la lista */
        printf("Arista n%c%d (%c,%c) = %d\n", 167, aux->numeroArista, (aux->V1)+ASCII, (aux->V2)+ASCII, aux->peso);
        // printf("Direccion %X\n",aux);
        // printf("Direccion NEXT %X\n",aux->next);
        pesoTotal = pesoTotal + (aux->peso);
        aux = aux->next;
    }
    printf("\nPeso total: %d\n\n",pesoTotal);
} // listado
//***Funcion que devuelve la arista de menor peso
struct arista *devolverArista(struct arista* top){
    struct arista *p = top;     // Punteros para recorrer lista
    struct arista *ant = NULL;  // Punteros para recorrer lista
    struct arista *aux = NULL;
    while (p)
    {
        if (p->next == NULL)    // encuentro la ultima arista
        {
            aux = p;            // guardo mi arista en la variable auxiliar para devolverla
            ant->next = NULL;   // se convierte en el nuevo ultimo elemento
        }
        ant = p;                // avanza en la busqueda
        p = p->next;
    }
    return aux;                 // devuelvo mi ultimo elemento osea el de menor peso
} // devolverArista
//************************************************************************