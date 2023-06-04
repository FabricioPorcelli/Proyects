/* main.c*/

#include <stdio.h>
#include <stdlib.h>
#include "ordenar_lista_aristas.h"
#include "kruskal.h"

int main (void){
    int M_Costos[VERTICES][VERTICES]; // Matriz de adyacencia
    arista* arbol = NULL;       // grafo inicial
    arista *ARBOLFINAL = NULL;  // arbol recubridor minimo

    int cont = 0;

    // Ciclo que solicita el ingreso del costo de las distintas aristas del grafo. 

    printf("A continuacion se le solicitara ingrese el costo de las aristas integradas por determinados vertices. En caso que no haya arista entre dos vertices ingrese 0.\n");

    for (int i = 0; i <= VERTICES-1; i++)
        for (int j = i + 1; j <= VERTICES-1; j++)
        {
            printf("- Ingrese costo de lado entre vertices %c y %c: ", i+ASCII, j+ASCII);
            scanf(" %d", &M_Costos[i][j]);
        }

    // Se insertan los valores ingresados. En caso de que el valor ingresado sea 0, considera que no hay una arista entre esos dos vertices.
    for (int i = 0; i <= VERTICES-1; i++){
        for (int j = i + 1; j <= VERTICES-1 ; j++){
            if (M_Costos[i][j] != 0){ // donde hay un 0 no hay arista
                cont = cont + 1;
                arbol = insertar(arbol, crearArista(cont, i, j, M_Costos[i][j]));
            }
        }
    }

    printf("\n\n");
    printf("*************************************************\n\n");

    printf("Esta es la lista de todas las aristas ordenadas de mayor a menor segun su peso:\n");
    listado(arbol);

    // ************ HASTA ACA ORDENA LA LISTA ENLAZADA CON LOS PESOS Y TODO INGRESADO ************

    // Llamada al algoritmo de kruskal y alojamiento del arbol que devuelve
    ARBOLFINAL = kruskal(arbol, ARBOLFINAL);

    // Impresion del resultado en pantalla
    printf("*************************************************\n");
    printf("\nEl Arbol Recubridor Minimo encontrado por el algoritmo es:\n");
    listado(ARBOLFINAL);

    printf("\n\nTrabajo realizado por Fabricio Porcelli y Julieta Russo.\nTaller de programacion 2. Instituto Politecnico Rosario.\n");

    free(arbol);
    free(ARBOLFINAL);

    return 0;
}