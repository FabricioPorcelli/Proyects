//----------LIBRERIAS----------
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
//-----------------------------

// Incluimos el header del archivo .cpp
#include "funcion_cartas.h"

// Prototipo funciones en el mismo archivo.
int mazoCartas();
void inicioCartas();
void barajar();
void reinicio_cartas();

// Matriz del Mazo de cartas
int mazo[ 4 ][ 10 ]; // aca es donde mezclamos las cartas

// Carta actual
int carta = 1; 

//********************************************************************************************
// Funcion principal. Me da una carta desde la 1ra a la numero 40 sin repetir.
int mazoCartas()
{
    int aux;
    
    for (int fila = 0; fila <= 3; fila++){
        for (int columna = 0; columna <= 9; columna++){
            // si la posición contiene la carta actual, la muestra
            if (mazo[fila][columna] == carta)
            {
                aux = (fila*100) + columna; // (2*100) + 7 = 207
            }
        }
    }
    carta++;
    return aux;   // devuelve aux
}
//********************************************************************************************

// Funcion auxiliar. Me resetea el numero de carta que estoy mostrando
void reinicio_cartas(){
    carta = 1;
}

//********************************************************************************************

// Funcion principal. La llamo al principio del programa para inicializar el arreglo de mazo.
void inicioCartas()
{
    // itera a través de las filas del mazo
    for (int fila = 0; fila <= 3; fila++){
        // itera a través de las columnas del mazo para la fila actual
        for (int columna = 0; columna <= 9; columna++){
            mazo[fila][columna] = 0; // inicializa la posición del mazo en 0
        }
    }
}

//********************************************************************************************

// Funcion principal. Elije las cartas del 1 al 40 en orden y  
// les asigna una fila y columna aleatoria a cada carta
void barajar()
{
    int fila;    // representa el palo de la carta
    int columna; // representa el valor de la carta

    time_t tiempo; // incluida en time.h , time_t un entero (generalmente de 32 o 64 bits), 
                   // que representa el número de segundos desde el inicio del tiempo Unix.

    srand(time(&tiempo)); // siembra el generador de números aleatorios usando de semilla
                          // el valor devuelto por time_t

    // para cada una de las 52 cartas, selecciona una posición del mazo al azar
    for (int carta = 1; carta <= 40; carta++){
        do // selecciona una nueva posición aleatoria hasta encontrar una desocupada
        {
            fila = rand() % 4;              // selecciona al azar la fila (0 a 3)
            columna = rand() % 10;          // selecciona al azar la columna (0 a 9)
        } while (mazo[fila][columna] != 0);

        // coloca el número de la carta en la posición elegida del mazo
        mazo[fila][columna] = carta; // con carta del 1 al 40
    }
}

//********************************************************************************************