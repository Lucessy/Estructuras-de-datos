#include "Lista.h"
#include <iostream>
#include <math.h>
using namespace std;

Lista::Lista()
{
    //Se crea lista vacia
    primero = nullptr;
    ultimo = nullptr;
    ultCompleto = nullptr;
    ultSinGluten = nullptr;
    ultVegano = nullptr;

    longitud = 0;
    longCompleto = 0;
    longSinGluten = 0;
    longVegano = 0;
}

Lista::~Lista()
{
    //dtor
    while(primero)
    {
        elemFinal();
    }
}



void Lista::extenderListaPorDerecha(Pedido& elem)
{
    NodoLista* nuevoNodo = new NodoLista(elem,nullptr,ultimo);
    if(esVacia())
    {
        primero = nuevoNodo;
        ultimo = nuevoNodo;
    }
    else
    {
        ultimo->siguiente = nuevoNodo;
        ultimo = nuevoNodo;
    }

    string pref = elem.getPreferenciaMenu();
    if(pref == "completo")
    {
        ultCompleto = nuevoNodo;
        longCompleto++;
    }
    else if(pref == "sinGluten")
    {
        ultSinGluten = nuevoNodo;
        longSinGluten++;
    }
    else
    {
        ultVegano = nuevoNodo;
        longVegano++;
    }

    longitud++;
}

void Lista::extenderListaPorIzquierda(Pedido& elem)
{
    NodoLista* nuevoNodo = new NodoLista(elem,primero,nullptr);
    if(esVacia())
    {
        primero = nuevoNodo;
        ultimo = nuevoNodo;
    }
    else
    {
        primero->anterior = nuevoNodo;
        primero = nuevoNodo;
    }

    string pref = elem.getPreferenciaMenu();
    if(pref == "completo")
    {
        ultCompleto = nuevoNodo;
        longCompleto++;
    }
    else if(pref == "sinGluten")
    {
        ultSinGluten = nuevoNodo;
        longSinGluten++;
    }
    else
    {
        ultVegano = nuevoNodo;
        longVegano++;
    }

    longitud++;
}

/**
* Extiende la lista con el elemento dado, en su posici�n correspondiente por categor�a.
* Las categor�as se distribuyen en este orden: completo, sinGluten,vegano
* La lista est� siempre ordenada, los nuevos elementos se insertan en su posici�n correspondiente al final su categor�a.
*/
void Lista::extenderListaPorCategoria(Pedido& elem)
{
    string categoria = elem.getPreferenciaMenu();
    NodoLista* sig = nullptr;

    // Se guarda una referencia al puntero que se usar� para insertar el elemento dependiendo de su categor�a.
    NodoLista** punteroUtilizado = nullptr;
    bool insertar = false;

    if(categoria=="completo")
    {
        // Si a�n no hay ning�n men� completo la lista simplemente se extiende por la izquierda porque ir� primero as�
        if(ultCompleto==nullptr)
        {
            extenderListaPorIzquierda(elem);
        }
        else
        {
            insertar = true;
            punteroUtilizado = &ultCompleto;
            longCompleto++;
        }
    }
    else if(categoria=="sinGluten")
    {
        // Si no hay ya un pedido sin glut�n, si no hay un pedido completo (el primero de las 3 categor�as) se coloca a la izquierda
        // y si s� lo hay entonces se coloca a su derecha
        if(ultSinGluten==nullptr)
        {
            if(ultCompleto!=nullptr)
            {
                //Lo crea justo despu�s del �ltimo completo
                NodoLista* nuevoNodo = new NodoLista(elem,ultCompleto->siguiente,ultCompleto);
                longitud++;
                longSinGluten++;
                if(ultCompleto->siguiente != nullptr)
                {
                    ultCompleto->siguiente->anterior = nuevoNodo;
                }
                ultCompleto->siguiente = nuevoNodo;
                ultSinGluten = nuevoNodo;
            }
            else
            {
                extenderListaPorIzquierda(elem);
            }
        }
        else
        {
            insertar = true;
            punteroUtilizado = &ultSinGluten;
            longSinGluten++;
        }
    }
    else
    {
        // Si no hay ya un �ltimo pedido vegano se inserta por la derecha y as� ser� la �ltima categor�a como debe ser
        if(ultVegano==nullptr)
        {
            extenderListaPorDerecha(elem);
        }
        else
        {
            insertar = true;
            punteroUtilizado = &ultVegano;
            longVegano++;
        }
    }

    //Si el pedido no era el primero en ning�n caso se inserta en su lugar correspondiente usando el puntero correspondiente a la categor�a
    if(insertar)
    {
        NodoLista* nuevoNodo = new NodoLista(elem, (*punteroUtilizado)->siguiente, (*punteroUtilizado));
        longitud++;
        if( (*punteroUtilizado)->siguiente != nullptr)
        {
            (*punteroUtilizado)->siguiente->anterior = nuevoNodo;
        }
        (*punteroUtilizado)->siguiente = nuevoNodo;
        *punteroUtilizado = nuevoNodo;
    }
}

Pedido& Lista::elemInicial()
{
    return *(primero->pPedido);
}

Pedido& Lista::elemFinal()
{
    return *(ultimo->pPedido);
}

void Lista::eliminarPrimero()
{
    if(!esVacia())
    {
        NodoLista *aux = primero;

        string pref = primero->pPedido->getPreferenciaMenu();
        if(pref == "completo")
        {
            longCompleto--;
            if(longCompleto==0)
            {
                ultCompleto=nullptr;
            }
        }
        else if(pref == "sinGluten")
        {
            longSinGluten--;
            if(longSinGluten==0)
            {
                ultSinGluten=nullptr;
            }
        }
        else
        {
            longVegano--;
            if(longVegano==0)
            {
                ultVegano=nullptr;
            }
        }

        if((primero==ultimo)&&(primero->siguiente == NULL))
        {
            primero=NULL;
            ultimo=NULL;
        }
        else
        {
            primero = primero->siguiente;
        }
        aux->siguiente=NULL;
        aux->anterior = NULL;
        delete(aux);
        longitud--;
    }
}

void Lista::eliminarUltimo()
{
    if(!esVacia())
    {
        NodoLista *aux = ultimo;

        string pref = primero->pPedido->getPreferenciaMenu();
        if(pref == "completo")
        {
            longCompleto--;
            if(longCompleto==0)
            {
                ultCompleto=nullptr;
            }
        }
        else if(pref == "sinGluten")
        {
            longSinGluten--;
            if(longSinGluten==0)
            {
                ultSinGluten=nullptr;
            }
        }
        else
        {
            longVegano--;
            if(longVegano==0)
            {
                ultVegano=nullptr;
            }
        }

        if((primero==ultimo)&&(ultimo->siguiente == NULL))
        {
            primero=NULL;
            ultimo=NULL;
        }
        else
        {
            ultimo->anterior->siguiente = NULL;
            ultimo = ultimo->anterior;
        }
        aux->siguiente=NULL;
        aux->anterior = NULL;
        delete(aux);
        longitud--;
    }
}


bool Lista::esVacia()
{
    return longitud == 0;
}


void Lista::mostrarDatosLista()
{
    if(esVacia())
    {
        cout << "La lista est� vac�a" << endl;
        return;
    }
    NodoLista* aux = primero;
    for(int i = 0; i<longitud; i++)
    {
        aux->pPedido->mostrarPedido();
        aux = aux->siguiente;
    }
}


NodoLista* Lista::getPrimero()
{
    return primero;
}


/*
* Saca de la lista los pedidos finalizados [la mitad de los pedidos de cada preferencia de men�] y devuelve una lista de pedidos con ellos
*/
Lista Lista::sacarSiguientesPedidos(Pila& pilaMesas)
{
    Lista auxLista;
    NodoLista* aux;
    NodoLista* primCategoria;

    if(ultCompleto != nullptr)
    {
        cout << "Sacando ultCOmpleto" << endl;
        primCategoria = primero;
        aux = primCategoria;
        for(int i = 0; i < ceil(longCompleto/2) ; i++)
        {
            auxLista.extenderListaPorDerecha(*(aux->pPedido));
            aux = aux->siguiente;
        }
        if(longCompleto==1)
        {
            ultCompleto = nullptr;
        }
        longCompleto = longCompleto - ceil(longCompleto/2);

        if(aux != nullptr)
        {
            aux->anterior = primCategoria->anterior;
        }
    }

    if(ultSinGluten != nullptr)
    {
        cout << "Sacando ultSinGluten" << endl;
        if(ultCompleto != nullptr)
        {
            primCategoria = ultCompleto->siguiente;
        }
        else
        {
            primCategoria = primero;
        }
        aux = primCategoria;
        for(int i = 0; i < ceil(longSinGluten/2); i++)
        {
            auxLista.extenderListaPorDerecha(*(aux->pPedido));
            aux = aux->siguiente;
        }

        if(longSinGluten==1)
        {
            ultSinGluten = nullptr;
        }
        longSinGluten = longSinGluten - ceil(longSinGluten/2);

        if(aux != nullptr)
        {
            aux->anterior = primCategoria->anterior;
        }
        if(primCategoria->anterior != nullptr)
        {
            primCategoria->anterior->siguiente = aux;
        }
    }

    if(ultVegano != nullptr)
    {
        cout << "Sacando ultVegano" << endl;
        if(ultSinGluten != nullptr)
        {
            primCategoria = ultSinGluten->siguiente;
        }
        else if(ultCompleto != nullptr)
        {
            primCategoria = ultCompleto->siguiente;
        }
        else
        {
            primCategoria = primero;
        }

        cout << "For de ultVegano" << endl;
        for(int i = 0; i < ceil(longVegano/2); i++)
        {
            auxLista.extenderListaPorDerecha(*(aux->pPedido));
            aux = aux->siguiente;
        }

        if(longVegano==1)
        {
            ultVegano = nullptr;
        }
        longVegano = longVegano - ceil(longVegano/2);

        cout << "Sacando el nodoPedido de la lista" << endl;
        if(aux != nullptr)
        {
            aux->anterior = primCategoria->anterior;
        }
        if(primCategoria->anterior != nullptr)
        {
            primCategoria->anterior->siguiente = aux;
        }
    }

    aux = auxLista.getPrimero();
    for(int j = 0; j < auxLista.getLongitud(); j++)
    {
        if(aux->pPedido->getMesaAsignada1() != nullptr)
        {
            pilaMesas.apilar(*(aux->pPedido->getMesaAsignada1()));
        }
        if(aux->pPedido->getMesaAsignada2() != nullptr)
        {
            pilaMesas.apilar(*(aux->pPedido->getMesaAsignada2()));
        }
        aux = aux->siguiente;
    }

    cout << "Lista terminada" << endl;
    return auxLista;
}


int Lista::getLongitud()
{
    return longitud;
}
