// PORCELLI_arbol_binario_strings.c

// Para la realización de este TP puede utilizar la implentación del apunte de árbol binario. Modifíquela para que los datos guardados sean una cadena de strings.
// El programa debe poder leer los datos desde un archivo 'entrada.txt'. También debe permitir almacenar cada una de las formas de recorer un árbol en sus respectivos archivos de salida.


// Un posible formato de entrada, 'entrada.txt':


// N1: "H" | N2: "E" | N3: "O" | N4: "A" | N5: "F" | N6: "G"
// N1:L=N2 | N1:R=N3 | N2:L=N4 | N2:R=N5 | N5:R=N6

// Las salidas serian:

// inorden.txt
// A E F G H O

// preorden.txt
// H E A F G O

// postorden:
// A G F E O H

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

typedef struct Nodo {
    char   palabra[30];
    struct Nodo *izquierda;
    struct Nodo *derecha;
} NODO;
//********************************************************
NODO *creaNodo(char* palabraIngresada) {
    NODO *nodo  = (NODO *) malloc(sizeof(NODO));
    strcpy(nodo->palabra, palabraIngresada);
    nodo->izquierda = nodo->derecha = NULL;
    return nodo;
}
//********************************************************
void inserta(NODO* nodo, char* palabra){
    if (strcmp(palabra,nodo->palabra)> 0) {
        if (nodo->derecha == NULL) {
            nodo->derecha = creaNodo(palabra);
        } else {
            inserta(nodo->derecha, palabra);
        }
    } else {
        if (nodo->izquierda == NULL) {
            nodo->izquierda = creaNodo(palabra);
        } else {
            inserta(nodo->izquierda, palabra);
        }
    }
}
//********************************************************
void preOrder(NODO* nodo) {
    if (nodo != NULL) {
        // declaro el puntero al archivo, y lo abro en modo
        // a+ = abre para actualizacion
        FILE *fPointerPre = fopen("preorder.txt","a+");
        // escribo la palabra
        fprintf(fPointerPre, nodo->palabra);
        printf("%s", nodo->palabra);
        // cierro el archivo
        fclose(fPointerPre);
        // llamo a la misma funcion (recursividad) pero enviandole
        // el nodo de la izquierda y cuando ya no hay mas
        // el de la derecha
        preOrder(nodo->izquierda);
        preOrder(nodo->derecha);

    }
}
//********************************************************
void inOrder(struct Nodo *nodo) {
    if (nodo != NULL) {
        // empiezo con los nodos de la izquierda
        inOrder(nodo->izquierda);
        // declaro el puntero al archivo, y lo abro en modo
        // a+ = abre para actualizacion
        FILE *fPointerPre = fopen("inorder.txt","a+");
        // escribo la palabra
        fprintf(fPointerPre, nodo->palabra);
        printf("%s", nodo->palabra);
        // cierro el archivo
        fclose(fPointerPre);
        // sigo con los nodos de la derecha
        inOrder(nodo->derecha);

    }
}
//********************************************************
void postOrder(struct Nodo *nodo) {
    if (nodo != NULL) {
        // empiezo con los nodos de la izquierda
        postOrder(nodo->izquierda);
        // despues lo de la derecha
        postOrder(nodo->derecha);
        // declaro el puntero al archivo, y lo abro en modo
        // a+ = abre para actualizacion
        FILE *fPointerPre = fopen("postorder.txt","a+");
        // escribo la palabra
        fprintf(fPointerPre, nodo->palabra);
        printf("%s", nodo->palabra);
        // cierro el archivo
        fclose(fPointerPre);
    }
}
//********************************************************

int main(void){

    NODO *raiz = creaNodo("H ");

    // declaro el puntero de FILE, en modo r = read
    FILE *fpointer = fopen("entrada.txt","r");

    // mientras no llegue al final del archivo
    while(!feof(fpointer)){
        char palabraLeida[30] = {0};
        fgets(palabraLeida, 30, fpointer);
        int largo = strlen(palabraLeida);
        palabraLeida[largo-1] = ' ';
        if(strcmp(palabraLeida, "") != 0){
            inserta(raiz, palabraLeida);
        }
    }
    // cuando termine de leer el archivo, lo cierra
    fclose(fpointer);

    int opcion;
    do
    {
        printf("\nOpciones a elegir:\n");
        printf("1- Preorder\n");
        printf("2- Inorder\n");
        printf("3- Postorder\n");
        printf("4- Salir\n");
        printf("> ");
        scanf(" %d",&opcion);
        switch (opcion)
        {
        case 1:
            printf("\n == PREORDER ==\n");
            preOrder(raiz);
            break;
        case 2:
            printf("\n == INORDER ==\n");
            inOrder(raiz);
            break;
        case 3:
            printf("\n == POSTORDER ==\n");
            postOrder(raiz);
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