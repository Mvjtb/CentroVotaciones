/*
 * MEstudiante.h
 *
 *  Created on: Sep 25, 2023
 *      Author: reyes
 */

#ifndef MESTUDIANTE_H_
#define MESTUDIANTE_H_
#include <string>
#include <iostream>
#include "Papeleta.h"

using namespace std;

class MEstudiante {

private:
	Papeleta pap;
	string cedula, nombre, apellido, programa, decanato;
	int semestre;

public:
	MEstudiante();
	void setCedula(string ced);
	void setNombre(string nomb);
	void setApellido(string ape);
	void setPrograma(string prog);
	void setDecanato(string deca);
	void setSemestre(int stre);
	string getCedula();
	string getNombre();
	string getApellido();
	string getPrograma();
	string getDecanato();
	int getSemestre();
	void setPapeleta(Papeleta p);
	Papeleta getPapeleta();

};

#endif /* MESTUDIANTE_H_ */
