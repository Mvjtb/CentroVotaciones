/*
 * Pila.h
 *
 *  Created on: 25 sept 2023
 *      Author: Miri
 */

#ifndef Pila_H_
#define Pila_H_
#include <iostream>
#include <string>
using namespace std;

template <class Tipo>
class Pila;

#ifndef NODOPILA_H
#define NODOPILA_H
template <class Tipo>
class Nodopila
{
public:
	Tipo info;
	Nodopila<Tipo>* ap;
	friend class Pila<Tipo>;
};
#endif

template <class Tipo>
class Pila											//ESTRUCTURA LIFO (ULTIMO EN ENTRAR PRIMERO EN SALIR)
{
	typedef Nodopila<Tipo>* apPila;
public:												//METODOS DE LA CLASE
	apPila Tope;
	Pila();											//CONSTRUCTOR
	bool Vacia();									//METODO PARA SABER SI LA PILA ESTA VACIA
	bool Llena();									//METODO PARA SABER SI LA PILA "ESTA LLENA" (NO HAY MAS MEMORIA DISPONIBLE PARA ALMACENAR NODOS)
	bool Insertar(Tipo Valor);						//INSERTAR UN NODO A LA PILA
	bool Remover(Tipo &Valor);						//ELIMINAR UN NODO DE LA PILA
	apPila ObtTope();								//OBTENER EL ELEMENTO QUE SE ENCUENTRA EN EL TOPO (ULTIMO ELEMENTO QUE FUE INGRESADO)
	void AsigTope(apPila p);
	Tipo ObtInfo(Nodopila<Tipo>* p);
	void AsigInfo(Nodopila<Tipo>* p, Tipo x);
	int ObtTamanno(Pila<Tipo>&pilaA);				//PARA SABER LA CANTIDAD DE NODOS QUE POSEE LA PILA
	void CargarPila(Pila<Tipo>&pilaA);				//METODO PARA CARGAR NODOS A LA PILA (SE PUEDE EDITAR ADAPTANDO A LAS NECESIDADES)
	void ImprimirPila(Pila<Tipo>&pilaA); 			//IMPRIME LOS ELEMENTOS DE LA PILA (NOTA: ACTUALMENTE DEFECTUOSO)

};

//#include "Pila.cpp"	PRECAUCION: NO INCLUIR SI NO QUIEREN QUE PETE LA LIBRERIA
#endif /* PILA_H_ */

