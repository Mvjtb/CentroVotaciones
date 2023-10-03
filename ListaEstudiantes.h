#ifndef LISTAESTUDIANTES_H_
#define LISTAESTUDIANTES_H_
#include "General/Lista.cpp"
#include "MEstudiante.h"
#include <iostream>
#include <string>



using namespace std;

class ListaEstudiantes
{
private:
	Lista<MEstudiante> estudiantes;
public:
	ListaEstudiantes();
	bool InsEstudiante(MEstudiante &estudiante);
	bool EliEstudiante(string ced,MEstudiante &estudiante);
	bool EliPrimerEstudiante(MEstudiante &estudiante);
	bool BuscarEstudiante(string ced);
	bool BuscarEstudiante2(string ced);
	void mostrarLista();
	bool esVacia();
	bool llena();


};

#endif /* LISTAESTUDIANTES_H_ */
