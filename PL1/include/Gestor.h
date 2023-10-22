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
        static Cola generarColaReservas(); //Opci�n 1
        static void mostrarColaReservas(Cola colaReservas); //Opci�n 2
        static void vaciarColaReservas(Cola& colaReservas); //Opci�n 3

        static Pila generarPilaMesas(Pila pilaMesas); //Opci�n 4
        static void mostrarPilaMesas(); //Opci�n 5
        static void vaciarPilaReservas(Pila&); //Opci�n 6

        static void simularGestionPrimeraReserva(Cola colaReservas, Cola colaReservasPdtes, Lista listaPedidos); //Opci�n 7
        static void simularGestionReservasProximaHora(Cola colaReservas, Cola colaReservasPdtes, Lista listaPedidos); //Opci�n 8
        static void simularGestionReservasTotal(Cola colaReservas, Cola colaReservasPdtes, Lista listaPedidos); //Opci�n 9

        static void Salir(); //Opci�n 0

    protected:

    private:

};

#endif // GESTOR_H
