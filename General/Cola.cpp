/*
 * Cola.cpp
 *
 *  Created on: 25 sept 2023
 *      Author: Miri
 */

#include "Cola.h"

template <class Tipo>				//constructor de la clase
Cola<Tipo>::Cola() {
     Frente=NULL;
     Final=NULL;
};

//===========================================================================

template <class Tipo>				//metodo para verificar si la cola esta vacia
bool Cola<Tipo>::Vacia(){
     return Frente == NULL;			//el apuntador frente debe apuntar a null cuando la lista este vacia
};
//===========================================================================

template <class Tipo>
bool Cola<Tipo>::Llena(){			//metodo para verificar si la cola "esta llena" es decir, ya no puede almacenar mas elementos
     nodoCola<Tipo> *p;					//puntero de tipo nodo
     p=new nodoCola<Tipo>;				//se crea la variable apuntadora
     if (p==NULL)					//si p es igual a null quiere decir que ya no hay mas espacio disponible en memoria para crear nodos
        return true;				//retorna true ya que no se pueden insertar mas nodos a la cola
     else							//en caso de que quede espacio en memoria para seguir insertando nodos p sera diferente a null
    {   delete p;					//se elimina la variable apuntadora ya que es posible seguir insertando nodos en la cola
        return false;				//retorna false porque aun hay espacio en memoria disponible.
    }
};
//===========================================================================

template <class Tipo>
bool Cola<Tipo>::Insertar(Tipo Valor){		//metodo que permite insertar elementos a la cola, recibe un parametro tipo para facilitar el manejo de datos
     nodoCola<Tipo> *nuevo;						// puntero de tipo nodo
     if (!Llena())							//si la lista no "esta llena" puede insertar el nuevo nodo a la cola
     {
        nuevo=new nodoCola<Tipo>;				//inicializa la variable apuntadora de tipo nodo que estara enlazada al nodo apuntado por final
        nuevo->info=Valor;
        nuevo->prox=NULL;					//el nuevo nodo ahora pasa a ser el final (null es a donde apunta el ultimo elemento de la cola)
        if (Final==NULL)					//si el apuntador al ultimo elemento es igual a null, entonces el nodo es el primero en entrar a la cola
            Frente=nuevo;					//frente ahora apunta al nuevo nodo
        else Final->prox=nuevo;
        Final=nuevo;						//final ahora apunta al nuevo nodo
        return true;
      }
      else return false;
};
//===========================================================================

template <class Tipo>
bool Cola<Tipo>::Remover(Tipo &Valor){		//metodo para remover un elemento de la cola (funciona similar al insertar)
     nodoCola<Tipo> *primero;
     if (!Vacia())						//si la cola no esta vacia, es decir, tiene elementos procede a eliminar el primer nodo de la cola
     {
        primero=Frente;					//nodo primero es igual a frente (primer nodo de la cola)
        Valor=primero->info;			//retorna la informacion del nodo apuntado por frente, sacandolo de la secuencia de nodos
        Frente=primero->prox;			//ahora frente es el proximo nodo
        if (Frente==NULL)				//si frente es NULL, porque era el ultimo elemento, entonces final tambien debe ser igual a NULL
            Final=NULL;
        delete primero;					//elimina la variable puntero que fue creada
        return true;
     }
     else
     return false;
};
//===========================================================================

template <class Tipo>
void Cola<Tipo>::cargarCola(Cola<Tipo>&cola1)
{
	Tipo valor;						//USO DE LA PLANTILLA TIPO PARA FACILITAR EL USO DEL METODO, INDEPENDIENTEMENTE DEL TIPO DE DATO

	for(int i=0;i<5;i++)			//CICLO DE EJECUCION PARA LLENAR LA COLA
	{
		cout<<"Ingrese un valor: ";		//MENSAJE PARA QUE EL USUARIO DIGITE EL VALOR
		cin>>valor;						//SE INGRESA EL VALOR
		if(!cola1.Llena())				//VERIFICAR QUE LA COLA NO ESTA LLENA
			cola1.Insertar(valor);		//SE INSERTA EL VALOR EN LA COLA
		else
			cout<<"La cola esta llena"<<endl;		//EN CASO QUE LA COLA YA NO PUEDA RECIBIR MAS ELEMENTOS (ESTA LLENA), MUESTRA EL MENSAJE
	}
};
//===========================================================================

template <class Tipo>
void Cola<Tipo>::imprimirCola(Cola<Tipo>&cola1)
{
	Tipo valor, marca;								//USO DE LA PLANTILLA TIPO PARA FACILITAR EL USO DEL METODO INDEP. DEL TIPO DE DATO
	bool encontrar;									//UTILIZADO PARA ENCONTRAR LA MARCA DENTRO DE LA COLA
	marca=-1;										// ESTE ELEMENTO PERMITE SABER DONDE TERMINA LA COLA, EVITA BUCLE INFINITO
	if(!cola1.Vacia())					//SI LA COLA NO ESTA VACIA
	{
		cola1.Insertar(marca);			//SE INSERTA LA MARCA EN LA COLA Y EL PARAMETRO ENCONTRAR SE ESTABLECE EN FALSO
		encontrar=false;
		while(!encontrar)				//MIENTRAS EL VALOR DE ENCONTRAR SEA DISTINTO A FALSE SE EJECUTA EL CICLO (NO SE HA ENCONTRADO LA MARCA AUN)
		{
			cola1.Remover(valor);		//REMOVER EL ELEMENTO DE LA COLA PARA PODERLO IMPRIMIR
			if(valor==marca)			//SI EL VALOR COINCIDE CON LA MARCA QUIERE DECIR QUE ENCONTRO LA MARCA
				encontrar=true;			//EL ESTADO DE ENCONTRAR CAMBIA A TRUE, FINALIZA EL CICLO
			else						//SI VALOR NO COINCIDE CON MARCA EL CICLO CONTINUA
				{
				cout<<"Valor: "<<valor<<endl;	//SE IMPRIME EL VALOR DEL ELEMENTO SACADO DE LA COLA
				cola1.Insertar(valor);			//EL ELEMENTO SE INGRESA NUEVAMENTE A LA COLA
				}
		}

	}
}
//===========================================================================

//METODO PARA OBTENER EL PUNTERO FRENTE
template <class Tipo>
nodoCola<Tipo>* Cola<Tipo>::obtPrimero()			//metodo para obtener el primer elemento de la cola
{
	return Frente;							//frente apunta al primer elemento de la cola
}

