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
#include "ListaEstudiantes.h"

using namespace std;

/*
 *  ESTE SOLO ES UNA PRUEBA DEL FUNCIONAMIENTO DE LA PILA, NO ES LA VERSION FINAL DEL MAIN
 */

int main() {
	Lista<MEstudiante> list;
	ListaEstudiantes listv;
	MEstudiante mest;
	VGeneral vg;
	Papeleta pap, auxpila;
	Cargo car;
	//datos del cargo
	string c, p;
	int r;
	//datos para lista estudiantes
	string ced, nomb, ape, progra, deca;
	int stre, resp, opc;
	bool band;

	vg.ImprimirEncabezado("==============================", "\n=====SISTEMA DE CENTRO DE VOTACIONES=====");

	resp =
			vg.LeerValidarNro(
					"\nIndique el menu al que desea acceder: 1)Gestion Candidatos  2)Lista Estudiantes: ",
					1, 2);

	if (resp == 1) {
		vg.ImprimirMensaje("==== SELECCIONE A SUS CANDIDATOS ==== ");
		do {
			c = vg.LeerString("\n Cargo a votar: ");
			p = vg.LeerString("\n Nombre del postulado: ");
			car.setCargo(c);
			car.setPostulado(p);
			pap.agregarVoto(car);
			r = vg.LeerValidarNro("\n Desea votar por otro cargo? 1.Si, 2.No",
					1, 2);
		} while (r == 1);

		cout << " GRACIAS POR PARTICIPAR" << endl;

		//	se imprime la papeleta con los cargos seleccionados por el votante
		if(!pap.vacia()) {
			pap.imprimirResultados();
		}


		/*
		 *  MENU PARA GESTION LISTA ESTUDIANTES VERSION DE PRUEBA.
		 */
	}

	else {
		vg.ImprimirMensaje("\n 1.Incluir estudiantes a la lista");
		vg.ImprimirMensaje("\n 2.Remover  el primer estudiante de la lista");
		vg.ImprimirMensaje("\n 3.Consultar estudiante");
		vg.ImprimirMensaje("\n 4.Volver al Menu");
		vg.ImprimirMensaje("\n 5.Salir");
		opc = vg.LeerValidarNro("\nSeleccione una opcion: ", 1, 5);

		switch (opc) {
		case 1:
			ced = vg.LeerString("\nIngrese la cedula del estudiante a incluir");
			nomb = vg.LeerString("\nIndique el nombre del estudiante: ");
			ape = vg.LeerString("\nIndique el apellido del estudiante: ");
			progra = vg.LeerString("\nIndique el programa que cursa: ");
			stre = vg.LeerValidarNro("\nIndique el semestre que cursa 1-10:", 1,
					10);

			mest.setCedula(ced);
			mest.setNombre(nomb);
			mest.setApellido(ape);
			mest.setPrograma(progra);
			mest.setSemestre(stre);

			listv.InsEstudiante(mest); // Esta estructura debe incluir por mesa? programa?

			cout << "\nEstudiante incluido";
			listv.mostrarLista();
			break;

		case 2:
			cout << "\nOpcion para remover el primer estudiante de la lista";
			listv.EliPrimerEstudiante(mest);
			break;

		case 3:

			cout << "\nOpcion para consultar un estudiante de la lista ";
			ced = vg.LeerString("\nIngrese la cedula del estudiante: ");
			band = listv.BuscarEstudiante(ced);
			if (band != true) {
				cout << "\nEl Estudiante no esta en la lista";
			}
			cout << "\n El Estudiante esta en la lista";
			break;

		case 4:
			main();
			system("PAUSE");
			system("cls");
			break;
		}

		opc = vg.LeerValidarNro(
				"\nSeleccione una opcion 1-4 o 5 para salir del menu:", 1, 5);
	}
	while (opc != 5);

	system("pause");
	return 0;
}




