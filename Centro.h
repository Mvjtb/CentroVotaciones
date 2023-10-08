/*
 * Centro.h
 *
 *  Created on: 6 oct 2023
 *      Author: Miri
 */

#ifndef CENTRO_H_
#define CENTRO_H_
#include <string>
#include "Mesa.h"
#include "General/Lista.h"
#include "General/VGeneral.h"

class Centro {
private:
	VGeneral vg;
	Lista<Mesa> mesas;
	nodo<Mesa>* pointer;
	int acumVPM;
	bool check;				//esta variable sera de utilidad cuando se carguen los datos de la BD
public:
	Centro();
	nodo<Mesa>* obtPrimero();
	void asigPrimero(nodo<Mesa>* ptr);
	nodo<Mesa>* ObtProx(nodo<Mesa>* p);
	bool insertarC(Mesa mesa);
	bool insertarD(nodo<Mesa>* pt,Mesa &mesa);
	bool removerC(Mesa &mesa);
	bool removerD(nodo<Mesa>* pt, Mesa &mesa);
	void cargarMesas();
	void imprimirListaMesas();
	void llenarVotacionManual();
	Mesa buscarMesa(string cat,nodo<Mesa>*&ap);
	void procesarMesa(string cat);
	void reporteMesa(string cat);
};

#endif /* CENTRO_H_ */
