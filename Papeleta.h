/*
 * Papeleta.h
 *
 *  Created on: 26 sept 2023
 *      Author: Miri
 */

#ifndef PAPELETA_H_
#define PAPELETA_H_
#include <iostream>
#include <string>
#include "Cargo.h"
#include "General/Pila.cpp"
using namespace std;

/*
 * la clase papeleta es donde se guarda la informacion(voto) referente a los cargos por los cuales los estudiantes(votantes) van a votar
 */
class Papeleta {
private:							//atributos de la clase
	Pila<Cargo> cargos;				//la papeleta contiene una pila de objetos cargo
	Nodopila<Cargo>* apunt;
public:
	Papeleta();						//metodos de la clase
	bool agregarVoto(Cargo car);		//metodo para agregar/insertar un voto de cargo usuando metodo de pila
	bool retirarVoto(Cargo &car);		//metodo para retirar de la pila un voto de cargo empleando metodo de pila
	bool vacia();						//metodo para saber si la pila "esta vacia" (no tiene elementos)
	int cantVotos();					//para saber cuantos votos a cargos hay por papeleta (se puede votar por todos los cargos o solo por alguno(s))
	Cargo obtenerInfo(Nodopila<Cargo>* apunt);
	void imprimirResultados();			//imprime la informacion contenida en la papeleta (NOTA:METODO DEFECTUOSO ACTUALMENTE)
	bool vaciarPilaVotos();				//metodo para vaciar la pila base, pasa la informacion a una pila auxiliar
};

#endif /* PAPELETA_H_ */
