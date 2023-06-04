/* pilaArray .c */

#include <stdio.h>
#include <conio.h>
#include "pilaArray.h"

void apila(int elemento){
    if (tamanio() == CAPACIDAD)
        printf("ERROR: No caben mas elementos.");
    else{
        c = c + 1;
        elementos[c] = elemento;
    }
}
int desapila(){
    if (estaVacia())
        printf("ERROR: No hay elementos a borrar.");
    else c = c - 1;

    return elementos[c+1]; // devuelvo el valor que desapile
}
void vaciaPila(){
    c = -1;
}
int tamanio(){
    return c + 1;
}
int estaVacia(){
    return c == -1;
}

int cima(){
    if (estaVacia())
        printf("ERROR: La lista esta vacia.");
    else
        return elementos[c];
}

int main()
{
    system("cls");
    if (estaVacia())
        printf("La lista esta vacia \n");
    else
        printf("La lista tiene elementos \n");
    printf("\n");

    for (int i = 0; i < 100; i = i + 5)
    {
        printf("i = %d ", i);
        apila(i);
        printf("c = %d \n", c);
    }

    if (estaVacia())
        printf("La lista esta vacia \n");
    else
        printf("La lista tiene elementos \n");

    printf("*************************************************\n");
    for (int i = 0; i < tamanio(); i++) printf("%d ",elementos[i]);
    printf("\n");

    printf("Tamanio = %d \n",tamanio());
    printf("Cima = %d \n",cima());
    printf("*************************************************\n");
    printf("Desapilo el valor = %d\n",desapila());
    for (int i = 0; i < tamanio(); i++) printf("%d ",elementos[i]);
    printf("\n");

    printf("Tamanio ahora = %d \n",tamanio());
    printf("Cima = %d \n",cima());
    printf("*************************************************\n");
    printf("Desapilo el valor = %d\n",desapila());
    for (int i = 0; i < tamanio(); i++) printf("%d ",elementos[i]);
    printf("\n");

    printf("Tamanio ahora = %d \n",tamanio());
    printf("Cima = %d \n",cima());
    printf("*************************************************\n");
    printf("*************************************************\n");
    printf("Desapilo el valor = %d\n",desapila());
    printf("Desapilo el valor = %d\n",desapila());
    printf("Desapilo el valor = %d\n",desapila());
    for (int i = 0; i < tamanio(); i++) printf("%d ",elementos[i]);
    printf("\n");

    printf("Tamanio ahora = %d \n",tamanio());
    printf("Cima = %d \n",cima());
    printf("*************************************************\n");


    return 0;
}