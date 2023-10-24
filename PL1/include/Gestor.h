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
        static void generarColaReservas(Cola& colaReservas); //Opci�n 1
        static void mostrarColaReservas(Cola& colaReservas); //Opci�n 2
        static void vaciarColaReservas(Cola& colaReservas); //Opci�n 3

        static void generarPilaMesas(Pila& pilaMesas); //Opci�n 4
        static void mostrarPilaMesas(Pila& pilaMesas); //Opci�n 5
        static void vaciarPilaMesas(Pila& pila); //Opci�n 6

        static void procesarReserva(Reserva* pReserva, Cola& colaReservasPdtes,Pila& pilaMesas, Lista& listaPedidos,bool insertarEnReservasPdtes);
        static void simularCambioHora(Pila& pilaMesas, Lista& listaPedidos);
        static void simularGestionReservaPendiente(Cola& colaReservas, Cola& colaReservasPdtes,Pila& pilaMesas, Lista& listaPedidos);
        static Reserva* siguienteReserva(bool esReservaPdte, Cola& colaReservas, Cola& colaReservasPdtes);
        static bool comprobarCambioHora(string horaInicial,Cola& colaReservas);

        static void simularGestionProximaReserva(Cola& colaReservas, Cola& colaReservasPdtes, Pila& pilaMesas,Lista& listaPedidos); //Opci�n 7
        static void simularGestionReservasProximaHora(Cola& colaReservas, Cola& colaReservasPdtes,Pila& pilaMesas, Lista& listaPedidos); //Opci�n 8
        static void simularGestionReservasTotal(Cola& colaReservas, Cola& colaReservasPdtes,Pila& pilaMesas, Lista& listaPedidos); //Opci�n 9

        static void Salir(); //Opci�n 0

        //Atributos p�blicos
        static int numReservasGestionadas;

    protected:

    private:
};

#endif // GESTOR_H
