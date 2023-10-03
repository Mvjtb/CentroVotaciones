/*
 * Papeleta.cpp
 *
 *  Created on: 26 sept 2023
 *      Author: Miri
 */

#include "Papeleta.h"

Papeleta::Papeleta() {

}

void Papeleta::setEstudiante(MEstudiante e)
{
	estudiante=e;
}

MEstudiante Papeleta::getEstudiante()
{
	return estudiante;
}

bool Papeleta::agregarVoto(Cargo car)
{
	cargos.Insertar(car);
}

bool Papeleta::retirarVoto(Cargo& car)
{
	cargos.Remover(car);
}

bool Papeleta::vacia()
{
	cargos.Vacia();
}

int Papeleta::cantVotos()
{
	Pila<Cargo> aux;
	Cargo val;
	int cont;

	while(!cargos.Vacia())
	{
		cargos.Remover(val);
		cont++;
		aux.Insertar(val);
	}
	while(!aux.Vacia())
		{
			aux.Remover(val);
			cargos.Insertar(val);
		}
	return cont;
}


Cargo Papeleta::obtenerInfo(Nodopila<Cargo>* apunt)
{
	cargos.ObtInfo(apunt);
}
void Papeleta::imprimirResultados()
{
	string car,post;
	Pila<Cargo> aux;
	Cargo info;
	while(!cargos.Vacia())
	{
		cargos.Remover(info);
		cout<< "Su eleccion"<<endl;
		car=info.getCargo();
		post=info.getPostulado();
		cout<<"Cargo: "<<car<<endl;
		cout<<"Candidato: "<<post<<" "<<endl;
		obtenerInfo(apunt);
		cout<<"contenido: "<<apunt<<endl;
		aux.Insertar(info);
	};
	while(!aux.Vacia())
	{
		aux.Remover(info);
		cargos.Insertar(info);
	}

}