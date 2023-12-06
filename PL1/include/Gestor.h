#ifndef GESTOR_H
#define GESTOR_H
#include "Cola.h"
#include "Pila.h"
#include "Lista.h"
#include <ABB.h>

using namespace std;

class Gestor
{
public:
    Gestor();
    virtual ~Gestor();
    void generarColaReservas(); //Opci�n 1
    void mostrarColaReservas(); //Opci�n 2
    void vaciarColaReservas(); //Opci�n 3

    void generarPilaMesas(); //Opci�n 4
    void mostrarPilaMesas(); //Opci�n 5
    void vaciarPilaMesas(); //Opci�n 6

    void mostrarAbbPedidos(); //Opci�n 18

    void simularGestionProximaReserva(); //Opci�n 7
    void simularGestionReservasProximaHora(); //Opci�n 8
    void simularGestionReservasTotal(); //Opci�n 9

    void mostrarDatos();

    void Salir(); //Opci�n 0


    //Atributos p�blicos
    int numReservasGestionadas;

protected:

private:
    ABB abbPedidos;
    Cola colaReservas;
    Cola colaReservasPdtes;
    Cola colaReservasNoGestionadas;
    Lista listaPedidos;
    Pila pilaMesas;
    void procesarReserva(Reserva* pReserva,bool esReservaPdt, bool esReservaPdtDelFinal);
    void simularCambioHora();
    Reserva* siguienteReserva(bool esReservaPdte);
    bool comprobarCambioHora(string horaInicial);
    void crearPedidos(Mesa** mesas, Reserva* pReserva);

    bool seHaComenzadoLaSimulacion;

};

#endif // GESTOR_H
