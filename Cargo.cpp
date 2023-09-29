/*
 * Cargo.cpp
 *
 *  Created on: 26 sept 2023
 *      Author: Miri
 */

#include "Cargo.h"

Cargo::Cargo() //inicializamos variables en el constructor
{
	cargo= "";
	postulado= "";
}

//METODOS SET Y GET

void Cargo::setCargo(string c)
{
	cargo=c;
}

string Cargo::getCargo()
{
	return cargo;
}


void Cargo::setPostulado(string p)
{
	postulado=p;
}

string Cargo::getPostulado()
{
	return postulado;
}
