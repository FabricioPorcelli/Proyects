// TRABAJO PRACTICO KRUSKAL EN C++
// PORCELLI FABRICIO COM1

#include <iostream>
#include <queue>
#include <map>

using namespace std;
//******************************************************************************************
// ARISTA
typedef pair<pair<char, char>, int> arista; /// v1 , v2 y costo entre ellos
//******************************************************************************************
// COMPARAR PESO DE ARISTAS
class MenorValor {
    public :
        bool operator()(arista e1, arista e2){
            return e1.second > e2.second;
        }
};
//******************************************************************************************
// ARBOL
typedef priority_queue<arista, vector<arista>, MenorValor> arbol;
//******************************************************************************************
// CONJUNTO COMBINA ENCUENTRA
typedef struct combina_encuentra {
    map<char, pair<char, char>> nombres;    /// vertice y vertice siguiente
    map<char, pair<int, char>> encabezados; /// cuenta y primer elemento
} conjunto_CE;
//******************************************************************************************
// GRAFO
class grafo {
private:
    vector<char> V;   /// Conjunto de vertices
    vector<arista> E; /// Conjunto de aristas con sus pesos

    conjunto_CE CE;              /// Estructura para el analisis de adyacencias
    arbol grafo_ordenado;        /// cola de prioridad con los pesos de las aristas
    vector<arista> arbol_minimo; /// A arbol de minimal

public:
    grafo() {}  /// constructor
    ~grafo() {} /// destructor

    void insertar_vertice(const char &); // LISTO
    void insertar_arista(const char &, const char &, const int &); // LISTO
    void insertar_arista(); // LISTO

    void inicial(const char &, const char &); //LISTO   /// inicializa a las estructuras de conjunto COMBINA - ENCUENTRA
    void combina(const char &, const char &); //LISTO   /// Combina las aristas que se encuentran formando el arbol
    char encuentra(const char &); //LISTO               /// Encuentra los vertices dentro del conjunto COMBINA - ENCUENTRA
    void kruskal();                                     /// Algoritmo generador del arbol recubridor minimal
    void inserta(); //LISTO                             /// Guarda al conjunto E dentro de la cola de prioridad teniendo en cuenta los costos.
    arista sacar_min(); // LISTO
    friend ostream & operator<<(ostream &os, arista A);
    friend ostream & operator<<(ostream &os, grafo G);
};
//******************************************************************************************
ostream & operator<<(ostream &os, grafo G){ /// Sobrercarga de la salida estandar para mostrar al grafo
    os << "El grafo es: \n";
    for(auto x: G.E)
        os << "\t" << x.first.first << " - " << x.first.second << ": costo = " << x.second << endl;
    return os;
}
ostream & operator<<(ostream &os, arista A){ /// Sobrercarga de la salida estandar para mostrar al grafo
    os << "\t" << A.first.first << " - " << A.first.second << ": costo = " << A.second;
    return os;
}
//******************************************************************************************
void grafo::insertar_vertice(const char &vert){ /// Guarda los vertices en el conjunto V
    V.push_back(vert);
}
void grafo::insertar_arista(const char &v1, const char &v2, const int &costo){ /// Guarda las aristas en el Conjunto E
    E.push_back(make_pair(make_pair(v1, v2), costo));
}
void grafo::insertar_arista(){ /// Guarda las aristas en el conjunto E pidiendolas ingresar por Teclado
    int peso = 0;
    char v1, v2;

    cout << "Ingrese por teclado la arista:" << endl;
    cout << "1er vertice: " ;
    cin >> v1;
    cout << "2do vertice: " ;
    cin >> v2;
    cout << "Peso: " ;
    cin >> peso;

    E.push_back(make_pair(make_pair(v1,v2), peso));
}
//******************************************************************************************
void grafo::inicial(const char &NOMBRE, const char &PRIMER_ELEMENTO){ /// inicializa a las estructuras de conjunto COMBINA - ENCUENTRA
    CE.encabezados.insert(make_pair(NOMBRE,make_pair(1,PRIMER_ELEMENTO)));
    CE.nombres.insert(make_pair(NOMBRE,make_pair(NOMBRE,0)));
}
void grafo::combina(const char &A, const char &B){ /// Combina las aristas que se encuentran formando el arbol
    char i;
    if (CE.encabezados[A].first > CE.encabezados[B].first){
        // A es el conjunto mas grande, combina B dentro de A
        // encuentra el final de B, cambiando los nombres de los
        // conjuntos por A conforme se avanza 1
        i = CE.encabezados[B].second;
        while (CE.nombres[i].second != 0)
        {
            CE.nombres[i].first = A;
            i = CE.nombres[i].second;
        }
        CE.nombres[i].first = A;
        CE.nombres[i].second = CE.encabezados[A].second;
        CE.encabezados[A].second = CE.encabezados[B].second;
        CE.encabezados[A].first = CE.encabezados[A].first + CE.encabezados[B].first;
    }
    else{
        i = CE.encabezados[A].second;
        while (CE.nombres[i].second != 0)
        {
            CE.nombres[i].first = B;
            i = CE.nombres[i].second;
        }
        CE.nombres[i].first = B;
        CE.nombres[i].second = CE.encabezados[B].second;
        CE.encabezados[B].second = CE.encabezados[A].second;
        CE.encabezados[B].first = CE.encabezados[B].first + CE.encabezados[A].first;
    }
}
char grafo::encuentra(const char &NOMBRE){ /// Encuentra los vertices dentro del conjunto COMBINA - ENCUENTRA
    return CE.nombres[NOMBRE].first;
}
//******************************************************************************************
void grafo::inserta(){ /// Guarda al conjunto E dentro de la cola de prioridad teniendo en cuenta los costos.
    for(auto x: E)
        grafo_ordenado.push(x);
}
arista grafo::sacar_min(){
    arista aux = grafo_ordenado.top();
    grafo_ordenado.pop();
    return aux;
}
//******************************************************************************************
void grafo::kruskal(){ /// Algoritmo generador del arbol recubridor minimal
    char comp_u, comp_v;
    int comp_n, costo = 0;
    char vertice;
    int cant_V = 1, op1, op2;
    arista a;

    cout << "\n\nELIJA UNA OPCION: " << endl;
    cout << "1 - Ingresar un grafo usted" << endl;
    cout << "2 - Utilizar algun grafo precargado" << endl;
    cout << " > ";
    cin >> op1;
    switch (op1){
    case 1:
        cout << "\nUsted eligio cargar un grafo.\n" << endl;
        cout << "**************************************" << endl;
        // INGRESAR VERTICES
        cout << "Cuantos vertices a ingresar? ";
        cin >> cant_V;
        cout << "Ingresar vertices " << endl;
        for (int i = 0; i < cant_V; i++){
            cout << "\t- Vertice: ";
            cin >> vertice;
            insertar_vertice(vertice);
        }
        // INGRESAR ARISTAS EN VECTOR DE ARISTAS
        cout << "**************************************" << endl;
        printf("A continuacion se le solicitara ingrese el costo de las aristas integradas por determinados vertices.\nEn caso que no haya arista entre dos vertices ingrese 0.\n");

        for(auto v1: V){
            for(auto v2: V){
                if (v2 > v1)
                {
                    costo = 0;
                    cout << "\t- Costo entre " << v1 << " - " << v2 << ": ";
                    cin >> costo;
                    if (costo != 0){
                        insertar_arista(v1,v2,costo);
                    }
                }
            }
        }
        break;
    case 2:
        cout << "\nUsted eligio utilizar un grafo precargado.\n" << endl;
        cout << "Elija uno: " << endl;
        cout << "1 - Grafo de 3 vertices " << endl;
        cout << "2 - Grafo de 4 vertices " << endl;
        cout << "3 - Grafo de 5 vertices " << endl;
        cout << "4 - Grafo de 8 vertices " << endl;
        cout << " > ";
        cin >> op2;
        switch (op2)
        {
        case 1:
            for (int i = 0; i < 3; i++){
                insertar_vertice(i+65);
            }
            insertar_arista('A','B',10);
            insertar_arista('A','C',5);
            insertar_arista('B','C',3);
            cout << "Grafo elegido: " << endl;
            for(auto g: E){
                cout << g << endl;
            }
            break;
        case 2:
            for (int i = 0; i < 4; i++){
                insertar_vertice(i+65);
            }
            insertar_arista('A','B',3);
            insertar_arista('A','C',2);
            insertar_arista('A','D',6);
            insertar_arista('B','E',9);
            insertar_arista('C','E',9);
            cout << "Grafo elegido: " << endl;
            for(auto g: E){
                cout << g << endl;
            }
            break;
        case 3:
            for (int i = 0; i < 5; i++){
                insertar_vertice(i+65);
            }
            insertar_arista('A','B',10);
            insertar_arista('A','C',12);
            insertar_arista('A','D',60);
            insertar_arista('A','E',7);
            insertar_arista('B','C',20);
            insertar_arista('C','D',32);
            cout << "Grafo elegido: " << endl;
            for(auto g: E){
                cout << g << endl;
            }
            break;
        case 4:
            for (int i = 0; i < 8; i++){
                insertar_vertice(i+65);
            }
            insertar_arista('A','B',10);
            insertar_arista('A','C',8);
            insertar_arista('B','C',8);
            insertar_arista('B','D',4);
            insertar_arista('C','E',5);
            insertar_arista('C','G',7);
            insertar_arista('D','E',5);
            insertar_arista('D','F',5);
            insertar_arista('E','F',7);
            insertar_arista('E','G',2);
            insertar_arista('F','G',12);
            insertar_arista('F','H',4);
            insertar_arista('G','H',5);
            cout << "Grafo elegido: " << endl;
            for(auto g: E){
                cout << g << endl;
            }
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }

    comp_n = V.size();

    // INICIO EL CONJUNTO CE
    for(auto x: E){
        inicial(x.first.first,x.first.first);
    }

    // ARMO LA PRIORITY_QUEUE
    inserta();
    if ((E.size() != 0)&&(E.size() >= V.size()))
    {
        while (comp_n > 1){
            a = sacar_min();
            comp_u = encuentra(a.first.first);
            comp_v = encuentra(a.first.second);
            if (comp_u != comp_v){
                // analiza si los dos vertices estan en una misma componente
                // conecta dos componentes diferentes
                combina(comp_u, comp_v);
                comp_n = comp_n - 1;
                arbol_minimo.push_back(a);
            }
        }
        if (arbol_minimo.size() == (V.size() - 1)){
            cout << "**************************************" << endl;
            cout << "EL GRAFO MINIMO ES: " << endl;
            for(auto am: arbol_minimo){
                cout << am << endl;
            }
            cout << "**************************************" << endl;
        }
    }
    else{
        cout << "**************************************" << endl;
        cout << "EL GRAFO ES INCONEXO." << endl;
        cout << "**************************************" << endl;
    }
}

int main()
{
    grafo G;
    G.kruskal();

    return 0;
}