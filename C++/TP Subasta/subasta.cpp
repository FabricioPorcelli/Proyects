#include "subasta.h"
//#include <conio.h>

using namespace std;

//-------------------------------------
// 		PERSONA

// Constructores
persona::persona (){
	this->nombre = "nn";
}
persona::persona (string nombre){
	this->nombre = nombre;
}

// Getters
string persona::getNombre(){
	return nombre;
}
//-------------------------------------
// 		OFERTA

// Constructores
oferta::oferta (){
	ofertante = persona("no identificado");
	monto = 0;
}
oferta::oferta (persona ofertante, float monto){
	this->ofertante = ofertante;
	this->monto = monto;
}

// Setters
void oferta::setOfertante(persona ofertante){
	this->ofertante = ofertante;
}
void oferta::setMonto(float monto){
	this->monto = monto;
}

// Getters
persona oferta::getOfertante(){
	return ofertante;
}
float oferta::getMonto(){
	return monto;
}
//-------------------------------------
// 		LOTE

// Constructores
lote::lote(){
	mayorOferta = oferta();
	numero = 0;
	nombre = "nn";
}
lote::lote(oferta mayorOferta, int numero, string nombre){
	this->mayorOferta = mayorOferta;
	this->numero = numero;
	this->nombre = nombre;
}

// Setters
void lote::setMayorOferta(oferta mayorOferta){
	this->mayorOferta = mayorOferta;
}
void lote::setNumero(int numero){
	this->numero = numero;
}
void lote::setNombre(string nombre){
	this->nombre = nombre;
}

// Getters
oferta lote::getMayorOferta(){
	return mayorOferta;
}
int lote::getNumero(){
	return numero;
}
string lote::getNombre(){
	return nombre;
}
//-------------------------------------
// 		SUBASTA

// Constructores
subasta::subasta (){
	vector<lote> lotess(0, lote());
	this->lotes = lotess;
}

// Setters
void subasta::setCantidad(int cantidad){
	this->cantidad = cantidad;
}

// Getters
int subasta::getCantidad(){
	return cantidad;
}
lote subasta::getLote(int numeroDeLote){
	return lotes[numeroDeLote];
}
vector<lote> subasta::getLotes(){
	return lotes;
}

//**************************************************************************************************

// ofertar
// Recibe un numeroDeLote, un ofertante, y el monto por el cual se desea ofertar.
void subasta::ofertar (int numeroDeLote, persona ofertante, float monto){
	if (monto > lotes[numeroDeLote].getMayorOferta().getMonto())
	{
		oferta ofertaMayor(ofertante, monto);
		lotes[numeroDeLote].setMayorOferta(ofertaMayor);
		cout << "Su oferta se ha concretado correctamente" << endl;
	}
	else
	{
		cout << "La oferta ingresada no es superadora.." << endl;
		cout << "La mayor oferta sigue siendo de " << lotes[numeroDeLote].getMayorOferta().getOfertante().getNombre() << " por $" << lotes[numeroDeLote].getMayorOferta().getMonto() << endl;
	}
}

// listarLotes
// Imprime una lista de los lotes que se encuentran en la subasta
void subasta::listarLotes (){
	cout << "**********************************" << endl;
	if (lotes.size() > 0)
	{
		cout << "Lista de Lotes : " << endl;
		for (int i = 0; i < lotes.size(); i++)
		{
			cout << "Lote n" << lotes[i].getNumero() << ": \"" << lotes[i].getNombre() << "\" -> $" << lotes[i].getMayorOferta().getMonto() << endl;
		}
	}
	else{
		cout << "No hay lotes ingresados.. " << endl;
	}
	cout << "**********************************" << endl;
	//getch();
}

// nuevoLote
// Recibe un numero de lote y un nombre para el mismo
// en caso de que no haya un lote cargado con el mimo numero, lo carga al vector de lotes
void subasta::nuevoLote (string nombre){
	int deshabilita = 0;
	oferta ofertaNula = oferta();
	lote lote1(ofertaNula, (getLotes().size()), nombre);
	lotes.push_back(lote1);
}

// buscarLote
// Recibe un numeroDeLote a buscar y lo devuelve, en caso de no encontrar ninguno con el numero
// requerido, devuelve el lote inicial.
lote subasta::buscarLote (int n){
	for (int i = 0; i < lotes.size(); i++)
	{
		if (lotes[i].getNumero() == n)
		{
			return lotes[i];
		}
	}
	return lotes[0];
}

// printLote
// Recibe el numeroDeLote e imprime su numero y su nombre, seguido de
// si se realizo una apuesta para el lote o todavia nadie oferto.
void subasta::printLote(int n){
	cout << "Lote n" << buscarLote(n).getNumero() << ": \"" << buscarLote(n).getNombre() << "\"" << endl;

	if (lotes[n].getMayorOferta().getMonto() != 0)
	{
		cout << "La oferta maxima a cargo de " << lotes[n].getMayorOferta().getOfertante().getNombre() << " por un total de $" << lotes[n].getMayorOferta().getMonto() << endl;
	}
	else{
		cout << "Todavia no se hizo ninguna oferta." << endl;
	}
}

//**************************************************************************************************

void iniciarSubasta(){
	int confirm = 0; char deseaApostar;
	string nombre; float precio;
	int op;
	int numeroDeLote;

	//system("cls");

	subasta subasta1 = subasta();

	//subasta1.nuevoLote("Fiat 600");
	//subasta1.nuevoLote("Volks A");
	//subasta1.nuevoLote("Audi A7");

	do
	{
		//system("cls");
		cout << "Menu Subasta" << endl;
		cout << "1. Buscar Lote / Ofertar" << endl;
		cout << "2. Nuevo Lote" << endl;
		cout << "3. Listar Lotes" << endl;
		cout << "4. Salir \n> ";
		cin >> op;

		switch (op)
		{
		case 1: // buscar lote
			cout << "**********************************" << endl;
			if (subasta1.getLotes().size() != 0)
			{
				cout << "Ingrese el numero de lote a buscar: " ;
				cin >> numeroDeLote;
				subasta1.printLote(numeroDeLote);
				cout << "----------------------------------" << endl;
				cout << "Desea ofertar por el lote? S | N \n> ";
				cin >> deseaApostar;

				if (deseaApostar == 's' || deseaApostar == 'S')
				{
					cout << "Ingrese su nombre: " ;
					cin >> nombre;
					cout << "Ingrese un monto superior a $" << subasta1.getLote(numeroDeLote).getMayorOferta().getMonto() << " : ";
					cin >> precio;
					subasta1.ofertar(numeroDeLote,persona(nombre),precio);
				}
			}
			else if (subasta1.getLotes().size() == 0)
			{
				cout << "No hay lotes ingresados." << endl;
			}

			cout << "**********************************" << endl;
			//getch();
			break;

		case 2: // nuevo lote
			//system("cls");
			cout << "**********************************" << endl;
			cout << "Ingrese nombre del lote: ";
			cin.ignore();
			getline(cin, nombre);
			subasta1.nuevoLote(nombre);
			subasta1.printLote(subasta1.getLotes().size()-1);

			cout << "**********************************" << endl;
			//getch();
			break;

		case 3: // listar lotes
			subasta1.listarLotes();
			break;

		case 4:
			confirm = 1;
			//system("cls");
			cout << "Fin del programa." << endl;
			break;

		default:
			break;
		}

	} while (confirm != 1);
}

//**************************************************************************************************

int main () {
    char salir = 's';
    do
    {
        iniciarSubasta();
        //system("cls");
        do
        {
            if (salir != 's' && salir != 'S' && salir != 'n'  && salir != 'N')
            {
                cout << "Ingreso erroneo. Intente nuevamente." << endl;
            }
            cout << "Quiere realizar otra subasta? S | N \n> ";
            cin >> salir;
        } while (salir != 's' && salir != 'S' && salir != 'n'  && salir != 'N');
		cout << "\n\n***********************************************\n" << endl;
    } while (salir != 'n' && salir != 'N');
	cout << "Fin del programa." << endl;
	return 0;
}