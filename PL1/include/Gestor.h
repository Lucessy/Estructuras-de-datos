#ifndef GESTOR_H
#define GESTOR_H
#include "Cola.h"
#include "Pila.h"
#include "Lista.h"


class Gestor
{
    public:
        Gestor();
        virtual ~Gestor();
        Cola generarColaReservas(); //Opci�n 1
        void mostrarColaReservas(Cola colaReservas); //Opci�n 2
        Cola vaciarColaReservas(); //Opci�n 3

        Pila generarPisaMesas(); //Opci�n 4
        void mostrarPilaMesas(); //Opci�n 5
        Pila vaciarPilaReservas(); //Opci�n 6

        void simularGestionPrimeraReserva(Cola colaReservas, Cola colaReservasPdtes, Lista listaPedidos); //Opci�n 7
        void simularGestionReservasProximaHora(Cola colaReservas, Cola colaReservasPdtes, Lista listaPedidos); //Opci�n 8
        void simularGestionReservasTotal(Cola colaReservas, Cola colaReservasPdtes, Lista listaPedidos); //Opci�n 9

        void Salir(); //Opci�n 0

    protected:

    private:

};

#endif // GESTOR_H
