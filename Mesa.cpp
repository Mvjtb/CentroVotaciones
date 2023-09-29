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
}

void Mesa::setNombreEncargado(string ne)
{
	nombreEncargado=ne;
}

string Mesa::getNombreEncargado()
{
	return nombreEncargado;
}


void Mesa::setEstudiante(MEstudiante e)
{
	estudiante=e;
}

MEstudiante Mesa::getEstudiante()
{
	return estudiante;
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

void Mesa::AgregarVoto(Papeleta pap)
{
  papeletas.Insertar(pap);
}

bool Mesa::RetirarVoto(Papeleta& pap)
{
	return papeletas.Remover(pap);
}

bool Mesa::Vacia()
{
	return papeletas.Vacia();
}

nodo<Papeleta>* Mesa::obtPrimerVotante()
{
	return papeletas.obtPrimero();
}
