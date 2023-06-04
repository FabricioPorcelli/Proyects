/* ordenar_lista_aristas.h*/

#ifndef ORDENAR_LISTA_ARISTAS_H
#define	ORDENAR_LISTA_ARISTAS_H

#include <stdio.h>
#include <stdlib.h>

#define ASCII 65
// Con la ayuda de esta macro podemos manipular los vertices como nombrados
// con mumeros pero que en consola se muestren como nombrados con ABCs

#include "ordenar_lista_aristas.c"

arista *crearArista(int , int , int , int );
struct arista *insertar(struct arista *, struct arista *);
void listado(struct arista *);
struct arista *devolverArista(struct arista* );

#endif