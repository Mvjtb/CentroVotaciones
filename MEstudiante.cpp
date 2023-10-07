/*
 * MEstudiante.cpp
 *
 *  Created on: Sep 25, 2023
 *      Author: reyes
 */

#include "MEstudiante.h"

MEstudiante::MEstudiante() {
	// TODO Auto-generated constructor stub

}

void MEstudiante::setCedula(string ced){
	cedula=ced;
}

void MEstudiante::setNombre(string nomb){
	nombre=nomb;
}
void MEstudiante::setApellido(string ape){
	apellido=ape;
}
void MEstudiante::setDecanato(string deca){
	decanato=deca;
}

void MEstudiante::setPrograma(string prog){
	programa=prog;
}

void MEstudiante::setSemestre(int stre){
	semestre=stre;
}
string MEstudiante::getCedula(){
	return cedula;
}
string MEstudiante::getNombre(){
	return nombre;
}

string MEstudiante::getApellido(){
	return apellido;
}
string MEstudiante::getDecanato(){
	return decanato;
}

string MEstudiante::getPrograma(){
	return programa;
}
int MEstudiante::getSemestre(){
	return semestre;
}

/*
void MEstudiante::setPapeleta(Papeleta p)
{
	pap=p;
}

Papeleta MEstudiante::getPapeleta()
{
	return pap;
}

*/
