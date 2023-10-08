/*
 * Centro.cpp
 *
 *  Created on: 6 oct 2023
 *      Author: Miri
 */

#include "Centro.h"

Centro::Centro() {
	check=false;		//esta variable sera de utilidad cuando se carguen los datos de la BD
}

void Centro::llenarVotacionManual()
{
	vg.ImprimirMensaje("========== LLENAR PAPELETA ============");

	string categoria;
	Mesa m;
	Papeleta p;
	MEstudiante e;
	Cargo c;
	int r2;

	do
	{
		vg.Limpiar();

		//datos del estudiante que va a votar
		vg.ImprimirMensaje("========== DATOS DEL ESTUDIANTE ==========");
		string ced= vg.LeerString("Cedula: ");
		string nom= vg.LeerString("Nombre: ");
		string ap= vg.LeerString("Apellido: ");
		string pro= vg.LeerString("Ingrese el nombre de su Programa: \nInformatica \nAnalisis \nProduccion \nFisica \nMatematica \nTelematica ");
		string dec= vg.LeerString("Decanato: ");
		int s= vg.LeerNro("Semestre: ");
		e.setCedula(ced);
		e.setNombre(nom);
		e.setApellido(ap);
		e.setPrograma(pro);
		e.setDecanato(dec);
		e.setSemestre(s);

		vg.ImprimirMensaje("===== CARGOS A VOTAR =======");
		string cargo,est;
		int vop;

					vg.ImprimirMensaje("==== SELECCIONE A SUS CANDIDATOS ======");
					vg.ImprimirMensaje("\n TIENE A SU DISPOSICION 3 CARGOS POR LOS CUALES PUEDE VOTAR: VOCERO, SECRETARIO Y PRESIDENTE");
					vg.ImprimirMensaje("\n Piense Sabiamente su Elección");
					vg.ImprimirMensaje("\n");

					//votar por el vocero
					vop=vg.LeerValidarNro("\n Desea votar por el cargo de vocero? \n Presione 1 para SI, 2 para no: ",1,2);
					if(vop==1)
						{
							vg.ImprimirMensaje("============== Candidatos para Vocero ============= ");
							vg.ImprimirMensaje("Maria Lopez");
							vg.ImprimirMensaje("Jose Perez");

							cargo="vocero";
							est="voto por el cargo";
							c.setCargo(cargo);
							c.setEstado(est);
							p.agregarVoto(c);
						}
					else
						{
							cargo="vocero";
							est="no voto por este cargo";
							c.setCargo(cargo);
							c.setEstado(est);
							p.agregarVoto(c);
						}

				//Votar por el secretario
				vop=vg.LeerValidarNro("\n Desea votar por el cargo de Secretario? \n Presione 1 para SI, 2 para no: ",1,2);
						if(vop==1)
							{
								vg.ImprimirMensaje("========== Candidatos para Secretario ============ \n ");
								vg.ImprimirMensaje("Juan Orozco");
								vg.ImprimirMensaje("Pedro Alvarez");

								cargo="secretario";
								est="voto por el cargo";
								c.setCargo(cargo);
								c.setEstado(est);
								p.agregarVoto(c);
							}
						else
							{
								cargo="secretario";
								est="no voto por este cargo";
								c.setCargo(cargo);
								c.setEstado(est);
								p.agregarVoto(c);
							}

				//Votar por el presidente
				vop=vg.LeerValidarNro("\n Desea votar por el cargo de presidente? Presione 1 para SI, 2 para no: ",1,2);
						if(vop==1)
							{
								vg.ImprimirMensaje("====== Candidatos para Presidente ======== \n ");
								vg.ImprimirMensaje("Magdalena Mendoza");
								vg.ImprimirMensaje("Jesus Juarez");

								cargo="presidente";
								est="voto por el cargo";
								c.setCargo(cargo);
								c.setEstado(est);
								p.agregarVoto(c);
							}
						else
							{
								cargo="presidente";
								est="no voto por este cargo";
								c.setCargo(cargo);
								c.setEstado(est);
								p.agregarVoto(c);
							}

							vg.ImprimirMensaje("=====GRACIAS POR PARTICIPAR======");
			//Se carga la papeleta del estudiante con los datos correspondientes
			e.setPapeleta(p);

			//se selecciona la mesa donde se colocara al estudiante para procesar su eleccion
			string cat= e.getPrograma();
	//otra manera de obtener la categoria NOTA:metodo menos eficiente, puede generar ambiguedad;
			//string cat= vg.LeerString("\n Mesa donde va a votar: \n debe ingresar el nombre de la mesa correspondiente a su programa: \nInformatica \nAnalisis \nProduccion \nFisica \nMatematica \nTelematica ");
			nodo<Mesa>* apun;
			m= buscarMesa(cat,apun);
			m.AgregarVotante(e);
			mesas.AsigInfo(apun,m);
			r2=vg.LeerValidarNro("\n Desea agregar otro votante? 1.Si 2.No: ",1,2);
	}while(r2==1);

}

Mesa Centro::buscarMesa(string cat,nodo<Mesa>*&ap)
{
	Mesa m;								//se declara un objeto mesa
	ap= mesas.ObtPrimero();				//declaramos un ap con el primer elemento de la lista mesas
	for(int i=0; i<6; i++)				//ciclo iterativo que se ejecuta segun la cantidad de mesas, para este caso 6 mesas
	{
		m= mesas.ObtInfo(ap);			//la mesa se va a traer de la lista de mesas la informacion contenida en el nodo al que apunta el apuntador
		if(cat!=m.getCategoria())		//si la categoria es distinta a la categoria de la mesa posicionada en el primer nodo pasa al siguiente nodo
		{
			ap= mesas.ObtProx(ap);		//ahora el apuntador tiene la posicion del siguiente nodo de la lista, para proseguir con la busqueda hasta allar la mesa
		}
	}
	return m;
}

void Centro::procesarMesa(string cat)
{
	if(check==false)
	{
		vg.ImprimirMensaje("\n No estan cargados los datos de las mesas");
		vg.Pausa();
		return;
	}
	nodo<Mesa>* ap;
	Mesa m= buscarMesa(cat,ap);
	if(m.Vacia())
	{
		vg.ImprimirMensaje("\n No hay estudiantes en la cola");
		vg.Pausa();
		return;
	}

	MEstudiante e;
	Papeleta p;
	int r;
	do
	{
		if(!m.RetirarVotante(e))
		{
			vg.ImprimirMensaje("\n ¡NO HAY ESTUDIANTES EN LA MESA!");
			mesas.AsigInfo(ap,m);
			vg.Pausa();
			return;
		}
		m.setCantE();
		m.setCantV();
		vg.ImprimirMensaje(" \n ===== PAPELETA ELECTORAL =====");
		vg.ImprimirString("Estudiante: ",e.getNombre());
		while(!m.Vacia())
		{
			if(!p.vacia())
			p.imprimirResultados();
		}
		r=vg.LeerValidarNro("\n Desea procesar otro votante? 1.SI ,2.NO",1,2);

	}while(r==1);
	mesas.AsigInfo(ap,m);

}

void Centro::reporteMesa(string cat)
{
	nodo<Mesa>* ap;
	Mesa m= buscarMesa(cat,ap);
	vg.ImprimirString("\n Reporte de la Mesa: ",cat);
	vg.ImprimirMensaje("================");
	vg.ImprimirNro("\n Cantidad de estudiantes que votaron: ",m.getCantE());
	vg.ImprimirNro("\n Total de votos en la mesa: ",m.getCantV());
	vg.Pausa();
}
