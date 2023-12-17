#ifndef LISTA_H
#define LISTA_H q
#include <NodoLista.h>
#include "Pila.h"

class Lista
{
    public:
        Lista();
        virtual ~Lista();
        void extenderListaPorDerecha(Pedido& elem);
        void extenderListaPorIzquierda(Pedido& elem);
        Pedido& elemInicial();
        Pedido& elemFinal();
        void eliminarPrimero();
        void eliminarUltimo();
        bool esVacia();
        void mostrarDatosLista(string pref = "");
        Lista sacarSiguientesPedidos(Pila& pilaMesas);
        NodoLista* getPrimero();
        NodoLista* getUltVegano();
        void extenderListaPorCategoria(Pedido& elem);

    protected:

    private:
        NodoLista* ultCompleto;
        NodoLista* ultSinGluten;
        NodoLista* ultVegano;

        NodoLista* primero;
        NodoLista* ultimo;
        int longitud;
        friend class NodoLista;
};

#endif // LISTA_H
