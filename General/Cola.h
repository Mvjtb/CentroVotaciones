/*
 * Cola.h
 *
 *  Created on: 25 sept 2023
 *      Author: Miri
 */
#include <iostream>
#include <string>
using namespace std;
#ifndef Cola_H
#define Cola_H
using namespace std;

template <class Tipo>
class Cola;

template <class Tipo>
class nodoCola
{
Tipo info;
nodoCola *prox;
friend class Cola<Tipo>;
};

template <class Tipo>
class Cola								//ESTRUCTURA FIFO (PRIMER ELEMENTO EN ENTRAR, PRIMERO QUE SALE)
{
nodoCola<Tipo> *Frente,*Final;				//PUNTEROS REFERENCIADOS AL PRIMER Y ULTIMO ELEMENTO DE LA COLA
public:									//METODOS DE LA COLA
Cola();									//CONSTRUCTOR
bool Vacia();							//PARA SABER SI LA COLA ESTA VACIA
bool Llena();							//PARA SABER SI LA COLA ESTA LLENA (NO PUEDE RECIBIR MAS ELEMENTOS)
bool Insertar(Tipo Valor);				//INSERTAR UN ELEMENTO EN LA COLA
bool Remover(Tipo &Valor);				//QUITAR UN ELEMENTO DE LA COLA
void cargarCola(Cola<Tipo>&cola1);		//CARGAR LOS ELEMENTOS A UNA COLA
void imprimirCola(Cola<Tipo>&cola1);	//IMPRIMIR LOS VALORES DENTRO DE LA COLA
nodoCola<Tipo>* obtPrimero();				//OBTENER EL PRIMER ELEMENTO DE LA COLA
};

//#include "Cola.cpp" CUIDADO:no pongan esto si no quieren que les pete la libreria

#endif /* COLA_H_ */
