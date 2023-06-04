/* kruskal .c*/

#include "kruskal.h"
#include "ordenar_lista_aristas.h"
#include <stdio.h>
#include <stdlib.h>

#define VERTICES 6

// como estan definidos con typedef son punteros de tipo entero
typedef int tipo_nombre;
typedef int tipo_elemento;
typedef int vertice;

// Estructuras utilizadas 
typedef struct _ENCABEZADO
{
    int cuenta;
    int primer_elemento;
} encabezado;

typedef struct _NOMBRE
{
    tipo_nombre nombre_conjunto;
    int siguiente_elemento;
} nombre;

typedef struct _CONJUNTO_CE
{
    nombre nombres[VERTICES];
    encabezado encabezamientos_conjunto[VERTICES];
} conjunto_CE;
//**************************************

//***Funcion inicial: Inicializa las estructuras que se utilizaran en combina-encuentra
void inicial(tipo_nombre A, tipo_elemento x, conjunto_CE *C){
    C->nombres[x].nombre_conjunto = A;
    C->nombres[x].siguiente_elemento = 0;
    // puntero nulo al siguiente elemento
    C->encabezamientos_conjunto[A].cuenta = 1;
    C->encabezamientos_conjunto[A].primer_elemento = x;
} // inicial

//***Funcion Combina: Combinar los componentes A y B en C y llamar al resultado A o B arbitrariamente.

void combina(tipo_nombre A, tipo_nombre B, conjunto_CE *C){
    int i;
    if ((C->encabezamientos_conjunto[A].cuenta) > (C->encabezamientos_conjunto[B].cuenta)){
        // A es el conjunto mas grande, combina B dentro de A
        // encuentra el final de B, cambiando los nombres de los
        // conjuntos por A conforme se avanza 1
        i = C->encabezamientos_conjunto[B].primer_elemento;
        while (C->nombres[i].siguiente_elemento != 0)
        {
            C->nombres[i].nombre_conjunto = A;
            i = C->nombres[i].siguiente_elemento;
        }
        // agrega a la lista A al final de la B y llama A al resultado
        // ahora i es el indice del ultimo elemento de B

        C->nombres[i].nombre_conjunto = A;
        C->nombres[i].siguiente_elemento = C->encabezamientos_conjunto[A].primer_elemento;
        C->encabezamientos_conjunto[A].primer_elemento = C->encabezamientos_conjunto[B].primer_elemento;
        C->encabezamientos_conjunto[A].cuenta = C->encabezamientos_conjunto[A].cuenta + C->encabezamientos_conjunto[B].cuenta;
    }
    else{
        // B es al menos tan grande como A
        i = C->encabezamientos_conjunto[A].primer_elemento;

        while (C->nombres[i].siguiente_elemento != 0)
        {
            C->nombres[i].nombre_conjunto = B;
            i = C->nombres[i].siguiente_elemento;
        }

        C->nombres[i].nombre_conjunto = B;
        C->nombres[i].siguiente_elemento = C->encabezamientos_conjunto[B].primer_elemento;
        C->encabezamientos_conjunto[B].primer_elemento = C->encabezamientos_conjunto[A].primer_elemento;
        C->encabezamientos_conjunto[B].cuenta = C->encabezamientos_conjunto[B].cuenta + C->encabezamientos_conjunto[A].cuenta;
    }
} // combina
//************************************************************************
tipo_nombre encuentra(int x, conjunto_CE *C){
    // devuelve el nombre de aquel conjunto que tiene a x como miembro
    return (C->nombres[x].nombre_conjunto);
} // encuentra
//************************************************************************
arista* kruskal(arista* listaOrdenada, arista* MST){

    // Inicializo las variables a utilizar
    int comp_n;                 // cantidad actual de componentes
    arista* aristas;            // conjunto de aristas

    conjunto_CE componentes;   // el conjunto V agrupado en un conjunto de componentes COMBINA_ENCUENTRA
    vertice u, v;               // int
    arista* a;                  // auxiliar de arista
    tipo_nombre comp_siguiente; // nombre para el nuevo componente
    tipo_nombre comp_u, comp_v; // nombre de los componentes
    
    // inanula las aristas
    MST = NULL;
    aristas = NULL;
    comp_siguiente = 0;

    comp_n = VERTICES; // la cantidad de componentes inicial es = a la cantidad de VERTICES

    for (int i = 0; i < comp_n; i++) // Asigna valor inicial a un componente para que contenga un vertice de V
    {
        comp_siguiente = comp_siguiente + 1;
        inicial(comp_siguiente, i, &componentes);
    }

    while (comp_n > 1){
        a = devolverArista(listaOrdenada); // se va devolviendo las aristas con menor peso
        a->next = NULL;                     // aunque es lo mismo total no voy a recorrer nada solo necesito los valores
        comp_u = encuentra(a->V1, &componentes);
        comp_v = encuentra(a->V2, &componentes);
        if (comp_u != comp_v)
        {
            // conecta dos componentes diferentes
            combina(comp_u, comp_v, &componentes);
            comp_n = comp_n - 1;
            MST = insertar(MST, a);
        }
    }
    return MST;
} // kruskal
//************************************************************************
