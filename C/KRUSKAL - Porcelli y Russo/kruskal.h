/* kruskal.h*/

#ifndef KRUSKAL_H
#define	KRUSKAL_H

#include <stdlib.h>
#include <string.h>
#include "kruskal.c"

void inicial(tipo_nombre, tipo_elemento, conjunto_CE *);
void combina(tipo_nombre, tipo_nombre, conjunto_CE *);
tipo_nombre encuentra(int, conjunto_CE *);
arista* kruskal(arista* , arista*);

#endif