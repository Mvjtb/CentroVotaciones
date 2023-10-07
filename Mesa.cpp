/*
 * Mesa.cpp
 *
 *  Created on: 28 sept 2023
 *      Author: Miri
 */

#include "Mesa.h"

Mesa::Mesa() {
	numMesa=0;
	cantVotos=0;
	contP=0;
	contS=0;
	contV1=0;
	contV2=0;
}

void Mesa::setCategoria(string c)
{
	categoria=c;
}

string Mesa::getCategoria()
{
	return categoria;
}

void Mesa::setNumMesa(int nm)
{
	numMesa=nm;
}

int Mesa::getNumMesa()
{
	return numMesa;
}

void Mesa::setCantVotos(int v)
{
	cantVotos=v;
}

int Mesa::getCantVotos()
{
	return cantVotos;
}


void Mesa::AgregarVotante(MEstudiante e)
{
  estudiantes.Insertar(e);
}

bool Mesa::RetirarVotante(MEstudiante& e)
{
	return estudiantes.Remover(e);
}

bool Mesa::Vacia()
{
	return estudiantes.Vacia();
}

nodo<MEstudiante>* Mesa::obtPrimerVotante()
{
	return estudiantes.obtPrimero();
}


void Mesa::ImprimirCola()
{
	MEstudiante valor,marca;
	Cola<MEstudiante> colaux;
	while(!estudiantes.Vacia())
	{
			estudiantes.Remover(valor);
			cout<<"estudiante: "<<valor.getNombre()<<endl;
			colaux.Insertar(valor);
	}
	while(!colaux.Vacia())
	{
		colaux.Remover(valor);
		estudiantes.Insertar(valor);
	}
}

