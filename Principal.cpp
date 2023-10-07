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
 *  ESTE SOLO ES UNA PRUEBA DEL FUNCIONAMIENTO DE LA PILA Y LA LISTA, NO ES LA VERSION FINAL DEL MAIN
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
	int r,vo;
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

		vg.ImprimirMensaje("\n");
		vg.ImprimirEncabezado("============================","====== MENU DE VOTACIONES ========");
		vg.ImprimirMensaje("1.Seleccionar Candidatos");
		vg.ImprimirMensaje("2. Volver al Menu");

		opc=vg.LeerValidarNro("\n Elija su opcion: ",1,2);

		if(opc==1)
		{
				vg.ImprimirMensaje("==== SELECCIONE A SUS CANDIDATOS ======");
				vg.ImprimirMensaje("\n TIENE A SU DISPOSICION 3 CARGOS POR LOS CUALES PUEDE VOTAR: VOCERO, SECRETARIO Y PRESIDENTE");
				vg.ImprimirMensaje("\n Elija Sabiamente");

				vo=vg.LeerValidarNro("Desea votar por el cargo de vocero? \n Presione 1 para SI, 2 para no: ",1,2);
				if(vo==1)
				{
					vg.ImprimirMensaje("============== Candidatos para Vocero ============= ");
					vg.ImprimirMensaje("Maria Lopez");
					vg.ImprimirMensaje("Jose Perez");

					c="vocero";
					p="voto por el cargo";
					car.setCargo(c);
					car.setEstado(p);
					pap.agregarVoto(car);
				}
				else
				{
					c="vocero";
					p="no voto por este cargo";
					car.setCargo(c);
					car.setEstado(p);
					pap.agregarVoto(car);
				}

				//Votar por el secretario
				vo=vg.LeerValidarNro("\n Desea votar por el cargo de Secretario? \n Presione 1 para SI, 2 para no: ",1,2);
				if(vo==1)
				{
					vg.ImprimirMensaje("========== Candidatos para Secretario ============ \n ");
					vg.ImprimirMensaje("Juan Orozco");
					vg.ImprimirMensaje("Pedro Alvarez");

					c="secretario";
					p="voto por el cargo";
					car.setCargo(c);
					car.setEstado(p);
					pap.agregarVoto(car);
				}
				else
				{
					c="secretario";
					p="no voto por este cargo";
					car.setCargo(c);
					car.setEstado(p);
					pap.agregarVoto(car);
				}

				//Votar por el presidente
				vo=vg.LeerValidarNro("Desea votar por el cargo de presidente? Presione 1 para SI, 2 para no: ",1,2);
				if(vo==1)
				{
					vg.ImprimirMensaje("====== Candidatos para Presidente ======== \n ");
					vg.ImprimirMensaje("Magdalena Mendoza");
					vg.ImprimirMensaje("Jesus Juarez");

					c="presidente";
					p="voto por el cargo";
					car.setCargo(c);
					car.setEstado(p);
					pap.agregarVoto(car);
				}
				else
				{
					c="presidente";
					p="no voto por este cargo";
					car.setCargo(c);
					car.setEstado(p);
					pap.agregarVoto(car);
				}

				vg.ImprimirMensaje("=====GRACIAS POR PARTICIPAR======");

				//	se imprime la papeleta con los cargos seleccionados por el votante
				if(!pap.vacia()) {
					pap.imprimirResultados();
				}
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

		//opc2 = vg.LeerValidarNro(
	//			"\nSeleccione una opcion 1-4 o 5 para salir del menu:", 1, 5);
	}
	while (opc != 5);

	system("pause");
	return 0;
}




