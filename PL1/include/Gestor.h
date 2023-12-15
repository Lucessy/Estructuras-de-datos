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
    void generarColaReservas(); //Opci�n 0
    void mostrarColaReservas(); //Opci�n 1
    void vaciarColaReservas(); //Opci�n 2

    void generarPilaMesas(); //Opci�n 3
    void mostrarPilaMesas(); //Opci�n 4
    void vaciarPilaMesas(); //Opci�n 5

    void simularGestionProximaReserva(); //Opci�n 6
    void simularGestionReservasProximaHora(); //Opci�n 7
    void simularGestionReservasTotal(); //Opci�n 8

    void insertarPedidosEnLista(Pedido** pedidos,int longitudPedidos); //Opci�n 9
    void mostrarListaPedidos(); //Opci�n 10
    void mostrarColaReservasPendientes(); //Opci�n 12
    void insertarPedidoEnABB(Pedido* pedido); //Opci�n 13
    void mostrarAbbPedidos(); //Opci�n 14
    void mostrarNombresClientesAlfabeticamente(); //Opci�n 15
    void mostrarPedidosDeCliente(string nombreCliente); //Opci�n 16
    void mostrarCantidadPedidoPorCategoria(); //Opci�n 17
    void mostrarClientesConMenuVegano(); //Opci�n 18

    void Salir(); //Opci�n 19

    //Funciones p�blicas auxiliares
    void mostrarDatos();
    bool estaEnPilaMesas(Mesa* mesa);
    Pedido* procesarReserva(Reserva* pReserva,bool esReservaPdt, bool esReservaPdtDelFinal,bool reinsertarEnCola);


protected:

private:

    //Colecciones privadas
    ABB abbPedidos;
    Cola colaReservas;
    Cola colaReservasPdtes;
    Cola colaReservasNoGestionadas;
    Lista listaPedidos;
    Pila pilaMesas;

    //M�todos y funciones privadas
    void simularCambioHora();
    Reserva* siguienteReserva(bool esReservaPdte);
    bool comprobarCambioHora(string horaInicial);
    Pedido* crearPedidos(Mesa** mesas, Reserva* pReserva);

    // Variables privadas
    bool seHaComenzadoLaSimulacion;
    int numReservasGestionadas;

};

#endif // GESTOR_H
