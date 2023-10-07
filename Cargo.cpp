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
	estado= "";
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


void Cargo::setEstado(string ec)
{
	estado=ec;
}

string Cargo::getEstado()
{
	return estado;
}
