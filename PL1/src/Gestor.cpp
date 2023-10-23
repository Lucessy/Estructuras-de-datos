#include "Gestor.h"
#include "Cola.h"
#include "Reserva.h"
#include "Mesa.h"
#include "Pila.h"
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()

using namespace std;

Gestor::Gestor()
{
    //ctor
}

Gestor::~Gestor()
{
    //dtor
}

Cola Gestor::generarColaReservas(Cola& colaReservas)
{
    if(colaReservas.esVacia() == false)
    {
        vaciarColaReservas(colaReservas);
    }
    string horas[] = {"13:30", "14:30", "15:30"};
    string menus[] = {"vegano", "sinGluten", "completo"};
    string situaciones[] = {"Terraza","Interior"};
    string nombresPosibles[] = {
        "Frodo", "Aragorn", "Gandalf", "Legolas", "Gimli",
        "Sam", "Boromir", "Merry", "Pippin", "Sauron",
        "Saruman", "Elrond", "Galadriel", "Faramir", "Denethor",
        "Th�oden", "�owyn", "Gollum", "Bilbo", "Thorin",
        "Dwalin", "Balin", "Kili", "Fili", "Oin",
        "Gloin", "Dori", "Nori", "Ori", "Bombur", //30
        "Gollum", "Bilbo", "Thorin", "Dwalin", "Balin",
        "Kili", "Fili", "Oin", "Gloin", "Dori",
        "Nori", "Ori", "Bombur", "Gollum", "Bilbo", //45
        "Thorin", "Dwalin", "Balin", "Kili", "Fili", //50
        "Oin", "Gloin", "Nori", "Ori", "Bombur", //55
        "Gollum", "Bilbo", "Thorin", "Dwalin", "Balin" //60
    };

    int limite = 12;

    srand(time(0));


    for(int i = 0; i < 20; i++)
    {
        string nombreCliente = nombresPosibles[rand() % 60];
        string menu = menus[rand() % 3];
        string situacion = situaciones [rand() % 2];
        int numeroPersonas = rand() % 8 + 1;

        string hora;
        if(i<limite)
        {
            hora = horas[i / 4];
        }
        else
        {
            hora = horas[rand() % 3];
        }
        Reserva* preserva = new Reserva(nombreCliente, hora, situacion, numeroPersonas, menu);
        colaReservas.encolar(*preserva);
    }
    cout << "Cola de reservas generada." << endl;
    return colaReservas;
}

void Gestor::mostrarColaReservas(Cola& colaReservas)
{
    colaReservas.mostrarCola(); //Se puede implementar de esta manera(?
} //Opci�n 2

void Gestor::vaciarColaReservas(Cola& colaReservas)
{
    if(colaReservas.esVacia()){
        cout << "La cola de reservas ya est� vac�a." << endl;
        return;
    }
    colaReservas.vaciarCola();
    cout << "Cola de reservas vaciada." << endl;
} //Opci�n 3

Pila Gestor::generarPilaMesas(Pila& pilaMesas)
{
    string situaciones[2] = {"Terraza","Interior"};
    int capacidades[2] = {2,4};
    for(int numeroMesa=20; numeroMesa>=1; numeroMesa--)
    {
        //Genera aleatoriamente la capacidad
        int capacidad = capacidades [rand() % 2];
        string situacion = situaciones [rand() % 2];
        Mesa* pmesa = new Mesa(numeroMesa,capacidad,situacion);
        pilaMesas.apilar(*pmesa);
    }
    cout << "Pila de mesas generada." << endl;
    return pilaMesas;
} //Opci�n 4

void Gestor::mostrarPilaMesas(Pila& pilaMesas)
{
    pilaMesas.mostrarPilaMesas();
} //Opci�n 5

void Gestor::vaciarPilaMesas(Pila& pila)
{
    if(pila.esVacia()){
        cout << "La pila de mesas est� vac�a."<<endl;
        return;
    }
    pila.vaciarPila();
    cout << "Pila de mesas vaciada."<<endl;
} //Opci�n 6

void Gestor::simularGestionPrimeraReserva(Cola colaReservas, Cola colaReservasPdtes, Lista listaPedidos)
{

} //Opci�n 7

void Gestor::simularGestionReservasProximaHora(Cola colaReservas, Cola colaReservasPdtes, Lista listaPedidos)
{

}
//Opci�n 8

void Gestor::simularGestionReservasTotal(Cola colaReservas, Cola colaReservasPdtes, Lista listaPedidos)
{

} //Opci�n 9

void Gestor::Salir()
{
    cout << "Gracias por usar UltraReserva3000. Nos vemos pronto." << endl;
    //Otras cosas que realizar antes de salir:


} //Opci�n 0
