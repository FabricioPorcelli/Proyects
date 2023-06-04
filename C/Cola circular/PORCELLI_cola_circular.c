// PORCELLI_cola_circular.c

// Teniendo en cuenta lo descripto en el apunte de estructuras, implemente en C una cola circular

#include <stdio.h>
#include <stdlib.h>

#define longMAX 10

typedef struct _NODO{
    int dato;
    struct _NODO *previous;
    struct _NODO *next;
} Nodo;

typedef struct _COLA{
    Nodo *first;
    Nodo *last;
} Cola;

int estaVacia(Cola cola){
    //compruebo si el primer elemento de la cola es NULL
    if(cola.first == NULL)
        return 1; // la cola esta vacioa
    else
        return 0; // la cola tiene informacion
}

// variable que lleva la cuenta de los elementos en la cola
int cont = 0;

int crearNodo(Cola* cola, int valor){
    if(cont >= longMAX){
        printf("La cola esta LLENA, no se puede ingresar mas nada.\n");
        return -1;
    }
    else{
        Nodo* nuevoNodo = malloc(sizeof(Nodo));
        nuevoNodo->dato = valor;
        nuevoNodo->next = NULL;
        nuevoNodo->previous = NULL;
        if(estaVacia(*cola)){
            //Primer nodo
            cola->first = nuevoNodo;
            cola->last  = nuevoNodo;
            cont = 1;
        }
        else {
            Nodo* posicion_actual = cola->last;
            posicion_actual->next = nuevoNodo;
            nuevoNodo->previous = posicion_actual;
            cola->last = nuevoNodo;
            nuevoNodo->next = cola->first;
            cont++; // sumo el contador pues sume un elemento a la cola
        }
    }
}

int devolverPrimerElemento(Cola* cola){
    Nodo* posicion_actual = cola->first;
    cola->first = posicion_actual->next;
    posicion_actual->next->previous = cola->last;
    int auxsacar = posicion_actual->dato;
    cont--; // resto al contador porque quite un elemento
    free(posicion_actual); // tambien libero la memoria que ocupaba el elemento
    return auxsacar;
}


int main (void){

    Cola notas;
    notas.first = NULL;
    int nota;
    Nodo* posicion_actual;
    int auxsacado;

    printf("\n\nREGISTRO DE NOTAS TALLER II\n");
    int opcion;
    do
    {
        printf("\nOpciones a elegir:\n");
        printf("1- Ingresar notas\n");
        printf("2- Quitar ultimo elemento\n");
        printf("3- Listado de notas\n");
        printf("4- Salir\n");
        printf("> ");
        scanf(" %d",&opcion);
        switch (opcion)
        {
        case 1:
            printf("(Puede ingresar maximo de 10 notas, si desea salir ingrese -1)\n");
            do
            {
                printf("Ingrese nota: ");
                scanf("%d",&nota);
                if (nota != -1)
                    crearNodo(&notas, nota);
            } while (nota != -1);
            break;
        case 2:
            if (cont != 1)
                auxsacado = devolverPrimerElemento(&notas);
            else
                printf("Queda solo una nota. No se puede eliminar. :(\n");
            break;
        case 3:
            posicion_actual = notas.first;

            printf("\n***************************\n");
            printf("LISTA DE NOTAS: \n");
            for(int i=0; i<cont; i++){
                printf("%d\n", posicion_actual->dato);
                posicion_actual = posicion_actual->next;
            }
            printf("\n***************************\n");
            break;
        case 4:
            printf("Salida...\n");
            break;
        default:
            break;
        }
        printf("\n");
    } while (opcion != 4);

    return 0;
}