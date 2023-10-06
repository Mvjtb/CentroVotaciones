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
#include "ListaEstudiantes.h"
using namespace std;

/*
 * la clase mesa es la que se va a encargar de procesar los votos (papeletas) de cada estudiante(votante) en la cola
 */
class Mesa {
private:													//atributos de la clase
	string categoria;										//criterio categoria de la mesa
	int numMesa,cantVotos,contP,contS,contV1,contV2;		//contadores para poder totalizar luego la cantidad de votos por mesa y por cargos
	Cola<MEstudiante> estudiantes;							//cola de estudiantes
	ListaEstudiantes le;

public:														//metodos de la clase
	Mesa();
	void setCategoria(string c);
	string getCategoria();
	void setNumMesa(int nm);
	int getNumMesa();
	void setCantVotos(int v);
	int getCantVotos();
	void setContP(int cp);
	int getContP();
	void setContS(int cs);
	int getContS();
	void setContV1(int v1);
	int getContV1();
	void setContV2(int v2);
	int getContV2();
	void AgregarVotante(MEstudiante e);				//emplea el metodo de la cola para ingresar un nodo de tipo estudiante a la cola
	bool RetirarVotante(MEstudiante& e);			//emplea el metodo remover para extraer de la cola un nodo de tipo estudiante
	bool Vacia();									//emplea metodo vacia de cola
	nodo<MEstudiante>* obtPrimerVotante();			//emplea el metodo obtener primero de la cola
};

#endif /* MESA_H_ */
