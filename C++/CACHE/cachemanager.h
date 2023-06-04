
#include <iostream>
#include <fstream>
#include <map>
#include <utility>
#include <string>
#include <iomanip> // para setw y setprecision

using namespace std;
//******************************************************************************************
template <class T>
class CacheManager
{
    // members (private)
    int capacity;
    map<string, pair<T, int>> cache_data; // < Clave , < Obj , Indice de Uso > >
    int indice_de_uso = 0;
    bool write_file(string, T);

public:
    CacheManager(int); // recibe la capacidad en el int
    ~CacheManager();

    void iniciarCache();
    void show_cache();
    bool buscarArchivo(string key);
    bool buscarCache(string key);
    void modificarArchivo(string key, T obj);
    int maxMRU();
    string minLRU();
    T recuperarDato(string key);
    void insert(string key, T obj);
    T get(string key);
    // Agregar todas las funciones necesarias
};
//******************************************************************************************
// CONSTRUCTOR
    // inicializa el cache con el tamaño ingresado
template <class T>
CacheManager<T>::CacheManager(int cap){
    capacity = cap;
    fstream init("texto.txt", fstream::in | fstream::out | fstream::trunc);
    init.close();
}
// DESTRUCTOR
template <class T>
CacheManager<T>::~CacheManager() {}
//******************************************************************************************
template <class T>
void CacheManager<T>::iniciarCache(){
    //trunc
    fstream init("texto.txt", ios::trunc);
    init.close();
}
//******************************************************************************************
// FUNCIONA
template <class T>
void CacheManager<T>::show_cache(){
    cout << "********************************" << endl;
    cout << "Cache..." << endl;
    for(const auto& elem : cache_data){
        cout << " - " << elem.second.first << " " << elem.second.second << "\n";
    }
    cout << "********************************" << endl;
}
//******************************************************************************************
// FUNCIONA
template <class T>
bool CacheManager<T>::write_file(string key, T obj){
    ofstream output("texto.txt", ios::app);
    if (!output){ // ERROR
        cerr << "No se pudo abrir el archivo" << endl;
        return false;
    }
    output << key << " " << obj << " " << endl;

    return true;
}
//******************************************************************************************
// PROBLEMA
template <class T>
void CacheManager<T>::modificarArchivo(string key, T obj_nuevo){
    string clave;
    T obj_anterior;
    ifstream lec ("texto.txt", ios::in);
    ofstream aux ("auxiliar.txt", ios::app);
    if (lec.is_open()){
        // key
        lec>>clave;
        while (!lec.eof()){
            lec>>obj_anterior;
            if (clave.compare(key)){
                aux << clave << " " << obj_anterior << " " << endl;
            }
            else{
                aux << clave << " " << obj_nuevo << " " << endl;
            }
            lec>>clave;
        }
        lec.close();
        aux.close();
    }
    else{
        cout << "Error" << endl;
    }
    remove("texto.txt");
    rename("auxiliar.txt" , "texto.txt");
}
//******************************************************************************************
template <class T>
T CacheManager<T>::recuperarDato(string key){
    ifstream output("texto.txt", ios::in);
    T objeto;
    string keyAux;
    system("pause");
    while (!output.eof()){ // recorre el archivo hasta el final o hasta encontrarlo
        output >> keyAux;
        if (keyAux == key){
            // Se encontro en el archivo
            output >> objeto;
        }
    }
    output.close();
    return objeto;
}
//******************************************************************************************
// FUNCIONA
template <class T>
bool CacheManager<T>::buscarArchivo(string key){
    // Declaro el puntero y abro el archivo
    ifstream output("texto.txt", ios::in);
    bool encontrado = false;
    string keyAux;
    while (!output.eof() && !encontrado){ // recorre el archivo hasta el final o hasta encontrarlo
        output >> keyAux;
        if (keyAux == key){
            // Se encontro en el archivo
            encontrado = true;
        }
    }
    output.close();
    return encontrado;
}
//******************************************************************************************
// FUNCIONA
template <class T>
bool CacheManager<T>::buscarCache(string key){
    //cache_data.contains(key); C++ 20 NEEDED
    auto item = cache_data.find(key);
    if (item != cache_data.end()) {
        // cout << "Key exists!  -  {" <<
        //     item->first << ";" << item->second << "}\n";
        return true;
    } else {
        // cout << "Key does not exist!" << endl;
        return false;
    }
}
//******************************************************************************************
// FUNCIONA
template <class T>
int CacheManager<T>::maxMRU(){
    indice_de_uso++;
    return indice_de_uso;
}
//******************************************************************************************
template <class T>
string CacheManager<T>::minLRU(){
    int anterior = 1000000;
    string clave;
    for(const auto& elem : cache_data){
        if (anterior > elem.second.second){
            anterior = elem.second.second;
            clave = elem.first;
        }
    }
    return clave;
}
//******************************************************************************************
// INSERT
    // si el objeto existe, lo actualiza en el cache y en el archivo
    // sino existe, lo escribira en el sistema de archivos y el cache lo situara
    // con el mayor MRU
template <class T>
void CacheManager<T>::insert(string key, T obj){

    //map<string, pair<T, int>> cache_data; // < Clave , < Obj , Indice de Uso > >
    // YA EXISTE ?

    if (cache_data.empty()){
        write_file(key,obj);
        cache_data.insert(make_pair(key,make_pair(obj,maxMRU())));
    }
    else {
        if (buscarCache(key)){
            for(auto elem : cache_data){
                if ((elem.first == key)&&(elem.second.first != obj)){
                    // SI ESTA EN LA CACHE
                    // ACTUALIZA EL VALOR EN EL ARCHIVO
                    modificarArchivo(key,obj);
                }
            }
            // MRU MAYOR
            cache_data[key].second = maxMRU();
        }
        else{
            // NO
            // BUSCA EN EL ARCHIVO
            if (buscarArchivo(key)){
                // SI ESTA EN EL ARCHIVO
                // ACTUALIZA EL VALOR EN EL ARCHIVO
                modificarArchivo(key,obj);
                // LO COPIO EN LA CACHE
                // MRU MAYOR
                cache_data.insert(make_pair(key,make_pair(obj,maxMRU())));
                cache_data[key].second = maxMRU();
            }
            else{
                // EL DATO NO ESTA EN LA CACHE NI EN EL ARCHIVO
                // ESCRIBO EL VALOR EN EL ARCHIVO
                write_file(key,obj);
                // LO COPIO EN LA CACHE
                cache_data.insert(make_pair(key,make_pair(obj,maxMRU())));
                // MRU MAYOR
            }
        }
    }
    if (cache_data.size() > capacity){
        string eliminar = minLRU();
        cache_data.erase(eliminar);
    }
}
//******************************************************************************************
// GET
    // si el objeto existe, lo retorna y actualiza su MRU
    // sino existe, el programa debe informarlo
template <class T>
T CacheManager<T>::get(string key){

    T obj;

    if (buscarCache(key)){
        // SI ESTA EN LA CACHE

        // MRU MAYOR
        cache_data[key].second = maxMRU();

        //LO DEVUELVO
        for(const auto elem : cache_data){
            if (elem.first == key){
                obj = elem.second.first;
            }
        }
        // return obj;
        //map<string, pair<T, int>> cache_data; // < Clave , < Obj , Indice de Uso > >
    }
    else{
        // NO
        // BUSCA EN EL ARCHIVO
        if (buscarArchivo(key)){
            // SI ESTA EN EL ARCHIVO
            obj = recuperarDato(key);
            // LO COPIO EN LA CACHE
            cache_data.insert(make_pair(key,make_pair(obj,maxMRU())));
            if (cache_data.size() > capacity){
                string eliminar = minLRU();
                cache_data.erase(eliminar);
            }
            return obj;
        }
        else{
            // EL DATO NO ESTA EN LA CACHE NI EN EL ARCHIVO
            cout << "El dato buscado no se encuentra en memoria, ingreselo por favor..." << endl;
        }

    }
    return obj;
}
//******************************************************************************************
