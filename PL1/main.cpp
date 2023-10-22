#include <iostream>
#include <locale.h>
#include "Cola.h"
#include "NodoCola.h"
#include "Reserva.h"
#include "Gestor.h"
#include "Lista.h"
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()
using namespace std;

Cola colaReservasAleatoria();

int main()
{
    //Cambiamos el formato de texto de la consola para que soporte tildes y otros car�cteres castellanos
    setlocale(LC_ALL, "");

    //string nombresPosibles[] = {"Alice", "Bob", "Charlie", "David", "Eve", "Frank","Grace", "Hannah", "Ivan", "Jack", "Karen"}

    //Comienzo de programa
    //Mostrar por pantalla las opciones disponibles:
    cout << "Bienvenido al simulador de gesti�n de mesas y reservas UltraReserva3000." << endl;
    cout << "Escribe el n�mero de una las siguientes opciones para realizarla:" << endl;
    cout << "1. Generar una cola de reservas aleatoria" << endl;
    cout << "2. Mostrar los datos de la cola de reservas" << endl;
    cout << "3. Borrar los datos de la cola de reservas" << endl;
    cout << "4. Gerarar una pila de 20 mesas aleatoria" << endl;
    cout << "5. Mostrar los datos de la pila de mesas" << endl;
    cout << "6. Borrar los datos de la pila de mesas" << endl;
    cout << "7. Simular la gesti�n de la pr�xima reserva de la cola" << endl;
    cout << "8. Simular la gesti�n de toda la ronda de reservas de la pr�xima hora" << endl;
    cout << "9. Simular la gesti�n de todas las reservas de la cola" << endl;
    cout << "0. Salir\n" << endl;

    int eleccion;
    bool eleccionValida = false;
    int maxIntentos = 3;
    while(!eleccionValida && maxIntentos>0)
    {
        cin >> eleccion;
        if(eleccion >=0 && eleccion < 10)
        {
            eleccionValida=true;
        }
        else
        {
            cout << "La elecci�n escogida no es correcta. Escoge una v�lida.\n" << endl;
        }
        maxIntentos--;
    }
    if(maxIntentos == 0)
    {
        cout << "Superaste el n�mero de intentos de elecci�n. Finalizando programa." << endl;
        return 0;
    }

    Gestor gestor;
    Cola colaReservas;
    Cola colaReservasPdtes;
    Lista listaPedidos;

    switch(eleccion)
    {
        case 1:
            cout << "Generando aleatoriamente la cola de reservas...\n";
            //cReservas = gestor.generarColaReservas();
            //cReservas.mostrarCola();
            gestor.generarColaReservas();
            break;
        case 2:
            cout << "Mostrando la cola de reservas creada...\n";
            gestor.mostrarColaReservas(colaReservas);
            break;
        case 3:
            cout << "Vaciando la cola de reservas...\n";
            gestor.vaciarColaReservas();
            break;
        case 4:
            cout << "Generando aleatoriamente la pila de mesas...\n";
            gestor.generarPilaMesas();
            break;
        case 5:
            cout << "Mostrando la pila de mesas creada...\n";
            gestor.mostrarPilaMesas();
            break;
        case 6:
            cout << "Vaciando la pila de mesas...\n";
            gestor.vaciarPilaReservas();
            break;
        case 7:
            cout << "Simulando la gesti�n de la primera reserva de la cola de reservas...\n";
            gestor.simularGestionPrimeraReserva(colaReservas, colaReservasPdtes, listaPedidos);
            break;
        case 8:
            cout << "Simulando la gesti�n de las reservas y creaci�n de pedidos de todas las reservas para la misma hora...\n";
            gestor.simularGestionReservasProximaHora(colaReservas, colaReservasPdtes, listaPedidos); //Opci�n 8
            break;
        case 9:
            cout << "Simulando la gesti�n de todas las reservas del restaurante...\n";
            gestor.simularGestionReservasTotal(colaReservas, colaReservasPdtes, listaPedidos); //Opci�n 9
            break;

        case 0:
            cout << "Saliendo del programa...";
            gestor.Salir();
            break;
    }

    cout << "EndOfMain";



}



