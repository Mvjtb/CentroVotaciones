/*
 * ListaVotantes.cpp
 *
 *  Created on: Sep 26, 2023
 *      Author: reyes
 */

#include "ListaEstudiantes.h"

ListaEstudiantes::ListaEstudiantes(){}

bool ListaEstudiantes::InsEstudiante(MEstudiante &estudiante) {

	return estudiantes.InsComienzo(estudiante);
}

bool ListaEstudiantes::EliPrimerEstudiante(MEstudiante &estudiante) {
	return estudiantes.EliComienzo(estudiante);
}

bool ListaEstudiantes::esVacia() {
	return estudiantes.Vacia();
}

bool ListaEstudiantes::llena() {
	return estudiantes.Llena();
}

bool ListaEstudiantes::EliEstudiante(string ced, MEstudiante &estudiante) {

	Lista<MEstudiante> est_aux;
	MEstudiante est_actual;
	bool hallado = false;
	while (!estudiantes.Vacia()) {

		estudiantes.EliComienzo(est_actual);

		if (est_actual.getCedula() == ced) {
			estudiante = est_actual;
			hallado = true;
			break;
		}

		est_aux.InsComienzo(est_actual);
	}

	while (!est_aux.Vacia()) {
		est_aux.EliComienzo(est_actual);
		estudiantes.InsComienzo(est_actual);
	}
	return hallado;
}

bool ListaEstudiantes::BuscarEstudiante(string ced) {
	Lista<MEstudiante> est_aux;
	MEstudiante est_actual;
	bool encontrado = false;

	while (!estudiantes.Vacia()) {
		estudiantes.EliComienzo(est_actual);
		if (est_actual.getCedula() == ced) {
			encontrado = true;
			cout << "\nEstudiante encontrado en la lista";
		}
		est_aux.InsComienzo(est_actual);

	}
	while (!est_aux.Vacia()) {
		est_aux.EliComienzo(est_actual);
		est_aux.InsComienzo(est_actual);
	}
	return encontrado;

}

/*bool ListaVotantes::BuscarEstudiante2(string ced){
 bool band=false;
 nodo<MEstudiante> *aux=NULL;
 typedef nodo<MEstudiante> *Apuntador;
 Apuntador ap;
 if(ap!=NULL){
 aux=ap;
 while(aux !=NULL){
 if (aux->info==ced){
 band=true;
 }
 aux = aux->prox;
 }
 }
 return band;
 } */ //Metodo usando apuntador referencia

void ListaEstudiantes::mostrarLista(){
 Lista<MEstudiante> aux_est;
 MEstudiante mest;
 int tamano=estudiantes.Contar();
 if(tamano>0){
 for(int i=0; i<tamano ;i++){
    estudiantes.EliComienzo(mest);
    aux_est.InsComienzo(mest);
    cout<<"----------"<<i+1<<"----------"<<endl;
    cout<<"Cedula:"<<mest.getCedula()<<endl;
	cout<<"Nombre: "<<mest.getNombre()<<endl;
	cout<<"Apellido: "<<mest.getApellido()<<endl;
	cout<<"Programa: "<<mest.getPrograma()<<endl;
	cout<<"Semestre: "<<mest.getSemestre()<<endl;
 }
 while(!aux_est.Vacia()){
  aux_est.pasarListaAux(aux_est,estudiantes);

 }


 }

}
