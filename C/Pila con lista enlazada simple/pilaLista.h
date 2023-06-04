/* pilaLista .h */

typedef struct nodo
{
    int dato;
    struct nodo* next;
} node;

void apila(node **, int);

int desapila(node **);

void vaciaPila(node **);

int tamanio(node *);

int estaVacia(node **);

int cima(node *);