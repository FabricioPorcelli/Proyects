#include "cachemanager.h"
#include <string.h>

class Student
{
    int id;
    int value;
    const char *data;

public:
    static const string class_name; // Cada clase tiene un
    Student(int _key, int _value, const char *_data) : id(_key), value(_value), data(_data) {}
    Student(){};
    void print()
    {
        cout << "Student Object: " << id << ", " << value << ", " << data
             << endl;
    };
    friend ostream & operator<<(ostream &os, Student ST){
        os << ST.id << " " << ST.value << " " << ST.data;
        return os;
    }
    friend istream & operator>>(istream &is, Student& ST){
        string myString;
        is >> ST.id >> ST.value >> myString; //
        ST.data = myString.c_str();

        //strcpy(ST.data,myString.c_str());
        // char * cstr = new char [myString.length()+1];
        // strcpy (cstr, myString.c_str());

        // // cstr now contains a c-string copy of str

        // char * p = strtok (cstr," ");
        // is << p;
        // p = strtok(NULL," ");

        // delete[] cstr;

        return is;
    }
    Student & operator=(Student obj){
        id = obj.id;
        value = obj.value;
        data = obj.data;
        return *this;
    }
    bool operator!=(Student obj){
        if ((id == obj.id)&&(value = obj.value)&&(data == obj.data)){
            return false;
        }
        return true;
    }
    ~Student(){};
};
const string Student ::class_name = "StudentClass";

int main()
{
    CacheManager<Student> my_cache(3);

    my_cache.insert("0", Student (0,21,"student1"));
    my_cache.insert("1", Student (1,22,"student2"));
    my_cache.insert("2", Student (2,23,"student3"));
    my_cache.insert("3", Student (3,24,"student4"));

    my_cache.show_cache ();

    cout << "---------------------- UPDATE -- -- -- -- -- -- -- -- -- -- -- -" << endl;
    my_cache.insert("2", Student(22, 222, "EZE"));
    my_cache.show_cache();

    cout << " < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < " << endl;
    my_cache.get("2").print(); // not in cache but in filesystem
    cout << " < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < < " << endl;

    my_cache.show_cache();

    my_cache.insert("9", Student(1, 5, "Nine"));
    my_cache.show_cache();

    my_cache.insert("9", Student(1, 5, "Nine"));
    my_cache.insert("9", Student(1, 5, "Nine"));
    my_cache.show_cache();

    return 0;
}

// Dada una clave, el cache manager accede al valor. Si el valor existe en
// la memoria es retornado. En caso que no exista en memoria, entonces
// el cache deber ́a buscar la clave en el archivo y retornar el pair si es
// encontrado.
// El cach ́e tambi ́en debe implementar un tamano lımite de capacidad, lo
// que significa una restriccion sobre cu ́antos elementos pueden existir a la
// vez en la memoria. Una vez que se ha alcanzado el lımite, el menos utili-
// zado recientemente (LRU) debe eliminarse de la memoria para ingresar
// al nuevo.
// En el momento de la insercion, todo nuevo par < key, valor > debe
// guardarse tanto en la memoria como en el archivo.