/*
 * Principal.cpp
 *
 *  Created on: 26 sept 2023
 *      Author: Miri
 */

#include <iostream>
#include <cstdlib>
#include <string>
#include "Papeleta.h"
#include "General/VGeneral.h"
using namespace std;

/*
 *  ESTE SOLO ES UNA PRUEBA DEL FUNCIONAMIENTO DE LA PILA, NO ES LA VERSION FINAL DEL MAIN
 */

int main()
{
	VGeneral vg;
	Papeleta pap,auxpila;
	Cargo car;
	//datos del cargo
	string c,p;
	int r;
	vg.ImprimirMensaje("==== SELECCIONE A SUS CANDIDATOS ==== ");
	do{
		c= vg.LeerString("\n Cargo a votar: ");
		p= vg.LeerString("\n Nombre del postulado: ");
		car.setCargo(c);
		car.setPostulado(p);
		pap.agregarVoto(car);
		r= vg.LeerValidarNro("\n Desea votar por otro cargo? 1.Si, 2.No",1,2);
	}while(r==1);

	cout<<" GRACIAS POR PARTICIPAR"<<endl;

	while(!pap.vacia())
	{
		pap.retirarVoto(car);
		pap.imprimirResultados();
	}
/*		auxpila.agregarVoto(car);
	}
	while(!auxpila.vacia())
	{
		auxpila.retirarVoto(car);
		pap.agregarVoto(car);
	}
*/

	system("pause");
	return 0;
}



