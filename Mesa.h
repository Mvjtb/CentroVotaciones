/*
 * Mesa.h
 *
 *  Created on: 28 sept 2023
 *      Author: Miri
 */

#ifndef MESA_H_
#define MESA_H_
#include <iostream>
#include <string>
#include "General/Cola.cpp"
#include "MEstudiante.h"
#include "Papeleta.h"
using namespace std;

/*
 * la clase mesa es la que se va a encargar de procesar los votos (papeletas) de cada estudiante(votante) en la cola
 */
class Mesa {
private:						//atributos de la clase
	string nombreEncargado;		//encargado o responsable de la mesa
	MEstudiante estudiante;		//NOTA: dudas sobre la existencia de este objeto aqui (pendiente)
	int numMesa,cantVotos;		//cantVotos para poder totalizar luego la cantidad de votos por mesa
	Cola<Papeleta> papeletas;	//cola de votos
public:							//metodos de la clase
	Mesa();
	void setNombreEncargado(string ne);
	string getNombreEncargado();
	void setEstudiante(MEstudiante e);
	MEstudiante getEstudiante();
	void setNumMesa(int nm);
	int getNumMesa();
	void setCantVotos(int v);
	int getCantVotos();
	void AgregarVoto(Papeleta pap);		//emplea el metodo de la cola para ingresar un nodo de tipo papeleta a la cola
	bool RetirarVoto(Papeleta& pap);	//emplea el metodo remover de la cola para extraer un nodo de tipo papeleta de la cola
	bool Vacia();						//emplea metodo vacia de cola
	nodo<Papeleta>* obtPrimerVotante();		//emplea el metodo obtener primero de la cola




};

#endif /* MESA_H_ */
