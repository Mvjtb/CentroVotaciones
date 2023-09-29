/*
 * Pila.cpp
 *
 *  Created on: 25 sept 2023
 *      Author: Miri
 */
#include "Pila.h"


template <class Tipo>
Pila<Tipo>::Pila()
{
  Tope = NULL;
};

//===========================================================================
template <class Tipo>
bool Pila<Tipo>::Vacia()
{
  return Tope == NULL;
};

//===========================================================================
template <class Tipo>
bool Pila<Tipo>::Llena()
{
  apPila p;
  p = new Nodopila<Tipo>;
  if (p == NULL)
    return true;
  else
  {
    delete p;
    return false;
  }
};

//===========================================================================
template <class Tipo>
bool Pila<Tipo>:: Insertar(Tipo Valor)
{
  apPila nuevo;
  if (!Llena())
  {
    nuevo = new Nodopila<Tipo>;
    nuevo->info = Valor;
    nuevo->ap = Tope;
    Tope = nuevo;
    return true;
  }
  else
    return false;
};

//===========================================================================
template <class Tipo>
bool Pila<Tipo>::Remover(Tipo &Valor)
{
  apPila viejo;
  if (!Vacia())
  {
    viejo = Tope;
    Valor = viejo->info;
    Tope = Tope->ap;
    delete viejo;
    return true;
  }
  else
    return false;
};

//===========================================================================
template <class Tipo>
Nodopila<Tipo>* Pila<Tipo>::ObtTope()
{
  return Tope;
};

//===========================================================================
template <class Tipo>
void Pila<Tipo>::AsigTope(Nodopila<Tipo> *p)
{
  Tope = *p;
};

//===========================================================================
template <class Tipo>
Tipo Pila<Tipo>::ObtInfo(Nodopila<Tipo> *p)
{
  return p->info;
};

//===========================================================================
template <class Tipo>
void Pila<Tipo>::AsigInfo(Nodopila<Tipo> *p,Tipo x)
{
  p->info = x;
};

//===========================================================================
template <class Tipo>
void Pila<Tipo>::CargarPila(Pila<Tipo>&pilaA)
{
	Tipo valor;

	for(int i=0;i<5;i++)
	{
		cout<<"Por favor ingrese un valor: ";
		cin>>valor;
		if(!pilaA.Vacia())
		{
			if(!pilaA.Llena())
			{
				pilaA.Insertar(valor);
			}
			else
				cout<<"LA PILA ESTA LLENA";
		}
	}
}

//===========================================================================
template <class Tipo>
int Pila<Tipo>::ObtTamanno(Pila<Tipo>&pilaA)
{
	int cont;
	Tipo val;
	Pila<Tipo> aux;

	while(!pilaA.Vacia())
	{
		pilaA.Remover(val);
		cont++;
		aux.Insertar(val);
	}

	while(!aux.Vacia())
	{
		aux.Remover(val);
		pilaA.Insertar(val);
	}

	return cont;
}

//===========================================================================  NOTA: ACTUALMENTE DEFECTUOSO ESTE METODO
template <class Tipo>
void Pila<Tipo>::ImprimirPila(Pila<Tipo>&pilaA)
{

		Pila<Tipo> aux;
		Tipo val;
		while(!pilaA.Vacia())
		{
			pilaA.Remover(val);
			cout<<"valor: "<< val <<endl;
			aux.Insertar(val);
		};
		while(!aux.Vacia())
		{
			aux.Remover(val);
			pilaA.Insertar(val);
		}
}


