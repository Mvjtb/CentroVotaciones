/*
 * Cargo.h
 *
 *  Created on: 26 sept 2023
 *      Author: Miri
 */


#ifndef CARGO_H_
#define CARGO_H_
#include <string>
#include<iostream>
using namespace std;

/*
 * La clase cargo contiene los datos del candidato al cargo (presidente,secretario, vocero, etc)
 *  es donde se guardara la información para llenar las pilas de la papeleta (votos)
 */

class Cargo {
private:								//atributos de la clase
	string cargo, postulado;
public:									//metodos de la clase
	Cargo();
	void setCargo(string c);
	void setPostulado(string p);
	string getCargo();
	string getPostulado();

};

#endif /* CARGO_H_ */
