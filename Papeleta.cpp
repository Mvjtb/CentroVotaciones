/*
 * Papeleta.cpp
 *
 *  Created on: 26 sept 2023
 *      Author: Miri
 */

#include "Papeleta.h"

Papeleta::Papeleta() {

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
	Pila<Cargo> aux;
	Cargo info;
	cout<< " ===================== " <<endl;
	cout<< " ==== SU ELECCION ==== "<<endl;
	cout<< " ===================== " <<endl;
	while(!cargos.Vacia())
	{
			cargos.Remover(info);
			cout<<"***************************************"<<endl;
			cout<<"\nCargo: "<<info.getCargo()<<endl<<"\n Estatus: "<<info.getEstado()<<endl;
			cout<<"***************************************"<<endl;
			aux.Insertar(info);
	};
	while(!aux.Vacia())
	{
		aux.Remover(info);
		cargos.Insertar(info);
	}

}

bool Papeleta::vaciarPilaVotos()
{
	Pila<Cargo> auxiliar;
	Cargo info;

	cout<<" ===== VACIANDO LA PILA ====="<<endl;

	while(!cargos.Vacia())
	{
		cargos.Remover(info);
		auxiliar.Insertar(info);
	}
}
