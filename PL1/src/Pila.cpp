#include "Pila.h"
#include <iostream>
#include "NodoPila.h"
using namespace std;


Pila::Pila()
{
    //ctor
    cima=NULL;
}

Pila::~Pila()
{
    //dtor
    while(cima)
    {
        desapilar();
    }
}
bool Pila::esVacia()
{
    return cima == NULL;
}

void Pila::apilar(Mesa& mesa)
{
    NodoPila* nuevo = new NodoPila(mesa,cima);
    cima = nuevo;
}

void Pila::vaciarPila()
{
    while(cima!=NULL)
    {
        desapilar();
    }
}

void Pila::desapilar()
{
    if(cima)
    {
        NodoPila* nodo= cima;
        cima = nodo->siguiente;
        delete nodo;
    }
}
void Pila::mostrarCima()
{
    if(esVacia())
    {
        cout << "Pila vacia"<<endl;
    }
    else
    {
        cout << "N�mero de mesa de cima: " << cima->pmesa ->numMesa << endl;
    }
}


void Pila::mostrarPilaMesas()
{
    NodoPila* aux = cima;
        if(esVacia()){
            cout << "Pila vacia" << endl;
        }
        else{
            cout << "Datos de la pila:" << endl << endl;
            while(aux){
                cout << "Numero de mesa: " << aux->pmesa->getNumMesa() << endl;
                cout << "  -Capacidad: " << aux->pmesa->getCapacidad() << endl;
                cout << "  -Situaci�n de preferencia: " << aux->pmesa->getSituacionMesa() <<  endl;
                aux = aux->siguiente;
            }
            cout << "Fin de los datos de la cola de reservas." << endl;
        }
}
