// PORCELLI_lista_doblemente_enlazada.c

// Implemente en C una lista doblemente enlazada.
// El dato a guardar puede ser el que elija. Debe poseer todas las operaciones correspondientes.

#include <stdio.h>
#include <stdlib.h>
#define ASCII 65
//************************************************************************
typedef struct arista
{
    int numeroArista;
    int V1;
    int V2;
    int peso;
    struct arista *next;
    struct arista *previous;
} arista;
//************************************************************************
arista *crearArista(int numeroArista, int V1, int V2, int peso)
{
    arista *nuevaArista = (arista *)malloc(sizeof(arista));
    nuevaArista->V1 = V1;
    nuevaArista->V2 = V2;
    nuevaArista->numeroArista = numeroArista;
    nuevaArista->peso = peso;
    nuevaArista->previous = NULL;
    nuevaArista->next = NULL;
    return nuevaArista;
} // crearArista
//************************************************************************
struct arista *insertar(struct arista *top, struct arista *nuevo)
{
    struct arista *actual = top;    /* puntero para moverse por la lista */
    struct arista *anterior = NULL; /*puntero al elemento anterior al "actual" */
    /* Búsqueda del punto de inserción */
    while ((actual != NULL) && (actual->peso >= nuevo->peso))
    {
        anterior = actual;
        actual = actual->next;
    }
    /* Inserción */
    if (anterior != NULL)
    { /* inserción en medio o final */
        anterior->next = nuevo;
        nuevo->previous = anterior;
    }
    else
    { /* inserción al principio de la lista */
        top = nuevo;
        nuevo->previous = NULL;
    }
    nuevo->next = actual;
    if (actual != NULL)
        actual->previous = nuevo;

    return top; /* devuelve la cabecera de la lista */
} // insertar
//************************************************************************
void listadoASC(struct arista *top)
{
    int pesoTotal = 0;
    struct arista *aux = top; /* Puntero para recorrer la lista */
    printf("=== LISTA DE ARISTAS ASC ===\n\n");
    while (aux)
    { /* Bucle que recorre la lista */
        printf("DIR: %X \n",aux);
        printf(" Direccion PREVIOUS %X\n",aux->previous);
        printf(" Arista n%c%d (%c,%c) = %d\n", 167, aux->numeroArista, (aux->V1) + ASCII, (aux->V2) + ASCII, aux->peso);
        printf(" Direccion NEXT %X\n\n",aux->next);
        pesoTotal = pesoTotal + (aux->peso);
        aux = aux->next;
    }
    printf("\nPeso total: %d\n\n", pesoTotal);
} // listado
//************************************************************************
void listadoDESC(struct arista *top)
{
    int pesoTotal = 0;
    struct arista *aux = top; /* Puntero para recorrer la lista */

    do{
        aux = aux->next;
    }while (aux->next != 0);

    printf("\n\n=== LISTA DE ARISTAS DESC ===\n\n");
    while (aux)
    { /* Bucle que recorre la lista */
        printf("DIR: %X \n",aux);
        printf(" Direccion PREVIOUS %X\n",aux->previous);
        printf(" Arista n%c%d (%c,%c) = %d\n", 167, aux->numeroArista, (aux->V1) + ASCII, (aux->V2) + ASCII, aux->peso);
        printf(" Direccion NEXT %X\n\n",aux->next);
        pesoTotal = pesoTotal + (aux->peso);
        aux = aux->previous;
    }
    printf("\nPeso total: %d\n\n", pesoTotal);
} // listado
//************************************************************************
struct arista *borrar(struct arista *top, int numeroArista)
{
    struct arista *p = top;
    while (p)
    {
        if (numeroArista == p->numeroArista) /* lo hemos encontrado */
        {
            if (p->previous == NULL) /* es el primero */
            {
                top = p->next;
                if (top)
                    top->previous = NULL;
                free(p);
                return top;
            }
            if (p->next == NULL)
            {
                p->previous->next = NULL;
                free(p);
                return top;
            }

            else /* el elemento a eliminar va en medio o al final */
            {
                p->previous->next = p->next; /* va en medio */
                p->next->previous = p->previous;
                free(p);
                return top;
            }
        }
        p = p->next;
    }           /* fin del while */
    return top; /* no encontrado o lista vacía */
} // borrar
//************************************************************************

int main (){

    arista* listaDeAristas;
    listaDeAristas = NULL;

    int numeroArista; int V1; int V2; int peso;

    // CARGA ARISTAS EN LA LISTA SIMPLEMENTE ENLAZADA ORDENADA
    numeroArista = 1; V1 = 4; V2 = 5; peso = 2;
    listaDeAristas = insertar(listaDeAristas, crearArista(numeroArista, V1, V2, peso));
    numeroArista = 2; V1 = 6; V2 = 2; peso = 1;
    listaDeAristas = insertar(listaDeAristas, crearArista(numeroArista, V1, V2, peso));
    numeroArista = 3; V1 = 3; V2 = 6; peso = 4;
    listaDeAristas = insertar(listaDeAristas, crearArista(numeroArista, V1, V2, peso));
    numeroArista = 4; V1 = 1; V2 = 2; peso = 8;
    listaDeAristas = insertar(listaDeAristas, crearArista(numeroArista, V1, V2, peso));
    numeroArista = 5; V1 = 4; V2 = 2; peso = 2;
    listaDeAristas = insertar(listaDeAristas, crearArista(numeroArista, V1, V2, peso));

    // IMPRIMIR EL LISTADO DE ARISTAS CARGADAS DE FORMA ASCENDENTE
    listadoASC(listaDeAristas);

    // IMPRIMIR EL LISTADO DE ARISTAS CARGADAS DE FORMA DESCENDENTE
    listadoDESC(listaDeAristas);

    return 0;
}