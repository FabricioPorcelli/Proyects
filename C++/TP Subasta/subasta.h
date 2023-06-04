// subasta.h
#ifndef SUBASTA_H
#define SUBASTA_H
#endif

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class persona{
private:
	string nombre;
public:
	persona();
	persona(string);

	string getNombre();
};

class oferta{
private:
	persona ofertante;
	float monto;
public:
	oferta();
	oferta(persona, float);

	void setOfertante(persona);
	persona getOfertante();
	void setMonto(float);
	float getMonto();
};

class lote{
private:
	oferta mayorOferta;
	int numero;
	string nombre;
public:
	lote();
	lote(oferta, int, string);

	void setMayorOferta(oferta);
	oferta getMayorOferta();
	void setNumero(int);
	int getNumero();
	void setNombre(string);
	string getNombre();
};

class subasta{
private:
	vector<lote> lotes;
	int cantidad;
public:

	subasta ();
	vector<lote> getLotes();
	lote getLote(int);
	void setCantidad(int);
	int getCantidad();
	void ofertar (int, persona, float);
	void listarLotes ();
	void nuevoLote (string);
	lote buscarLote (int);

	void printLote(int);
};
