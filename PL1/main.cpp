#include <iostream>
#include <locale.h>
#include <random>
#include "Cola.h"
#include "NodoCola.h"
#include "Reserva.h"
#include "Gestor.h"
#include "Lista.h"
#include "Gestor.h"
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()
using namespace std;

//Se definen las colecciones a usar
Cola colaReservas;
Cola colaReservasPdtes;
Cola colaReservasNoGestionadas;
Lista listaPedidos;
Pila pilaMesas;

//Se inicializan las variables est�ticas
int Gestor::numReservasGestionadas = 0;
bool Gestor::seHaComenzadoLaSimulacion = false;

int main()
{
    //Cambiamos el formato de texto de la consola para que soporte tildes y otros car�cteres castellanos
    setlocale(LC_ALL, "");


    //Comienzo de programa
    //Mostrar por pantalla las opciones disponibles:
    cout << "Bienvenido al simulador de gesti�n de mesas y reservas UltraReserva3000." << endl;
    //Inicializaci�n de variables
    srand(time(nullptr));

    bool programaEnEjecucion = true;
    while(programaEnEjecucion)
    {
        cout << endl<<"---------------------MENU PRINCIPAL--------------------------" << endl;
        cout << "1. Generar una cola de reservas aleatoria realizadas por los clientes" << endl;
        cout << "2. Mostrar los datos de la cola de reservas realizadas por los clientes" << endl;
        cout << "3. Borrar los datos de la cola de reservas" << endl;
        cout << "4. Generar una pila de 20 mesas aleatoria" << endl;
        cout << "5. Mostrar los datos de la pila de mesas" << endl;
        cout << "6. Borrar los datos de la pila de mesas" << endl;
        cout << "7. Simular la gesti�n de la pr�xima reserva de la cola" << endl;
        cout << "8. Simular la gesti�n de toda la ronda de reservas de la pr�xima hora" << endl;
        cout << "9. Simular la gesti�n de todas las reservas de la cola" << endl;

        cout << "11. Mostrar los datos de la cola de reservas realizadas por los clientes" << endl;
        cout << "12. Borrar la cola de reservas realizadas por los clientes" << endl;

        cout << "13. A�adir pedidos a la lista de pedidos" << endl;
        cout << "14. Mostrar los datos de la lista de pedidos" << endl;
        cout << "15. Mostrar los datos de la cola de reservas" << endl;
        cout << "16. Mostrar los datos de la cola de reservas pendientes" << endl;
        cout << "17. A�adir un pedido al �rbol binario de pedidos" << endl;
        cout << "18. Mostrar los datos del �rbol binario de pedidos" << endl;
        cout << "19. Mostrar los clientes que hayan realizado al menos un pedido" << endl; //En orden alfab�tico
        cout << "20. Mostrar los pedidos realizados por un cliente" << endl;
        cout << "21. Mostrar los clientes que han pedido un men� vegano" << endl;
        cout << "0. Salir\n" << endl;

        int eleccion = 0;
        bool eleccionValida = false;
        int maxIntentos = 3;

        //Se pide y valida la eleccion del usuario
        while(!eleccionValida && maxIntentos>0)
        {
            cin >> eleccion;
            if(eleccion >=0 && eleccion < 19)
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

        //Se selecciona y ejecuta la elecci�n elegida
        switch(eleccion)
        {
        case 1:
            cout << "Generando aleatoriamente la cola de reservas..." << endl;
            Gestor::generarColaReservas(colaReservas);
            break;
        case 2:
            cout << "Mostrando la cola de reservas creada..." << endl;
            Gestor::mostrarColaReservas(colaReservas);
            break;
        case 3:
            cout << "Vaciando la cola de reservas..." << endl;
            Gestor::vaciarColaReservas(colaReservas);
            break;
        case 4:
            cout << "Generando aleatoriamente la pila de mesas..." << endl;
            Gestor::generarPilaMesas(pilaMesas);
            break;
        case 5:
            cout << "Mostrando la pila de mesas creada..." << endl;
            Gestor::mostrarPilaMesas(pilaMesas);
            break;
        case 6:
            cout << "Vaciando la pila de mesas..." << endl;
            Gestor::vaciarPilaMesas(pilaMesas);
            break;
        case 7:
            cout << "Simulando la gesti�n de la primera reserva de la cola de reservas..." << endl;
            Gestor::simularGestionProximaReserva(colaReservas, colaReservasPdtes, colaReservasNoGestionadas,pilaMesas,listaPedidos); //Opci�n 7
            Gestor::mostrarDatos(colaReservas,colaReservasPdtes,colaReservasNoGestionadas,pilaMesas,listaPedidos);
            break;
        case 8:
            cout << "Simulando la gesti�n de las reservas y creaci�n de pedidos de todas las reservas para la misma hora..." << endl;
            Gestor::simularGestionReservasProximaHora(colaReservas, colaReservasPdtes, colaReservasNoGestionadas,pilaMesas, listaPedidos); //Opci�n 8
            Gestor::mostrarDatos(colaReservas,colaReservasPdtes,colaReservasNoGestionadas,pilaMesas,listaPedidos);
            break;
        case 9:
            cout << "Simulando la gesti�n de todas las reservas del restaurante..." << endl;
            Gestor::simularGestionReservasTotal(colaReservas, colaReservasPdtes, colaReservasNoGestionadas,pilaMesas, listaPedidos); //Opci�n 9
            Gestor::mostrarDatos(colaReservas,colaReservasPdtes,colaReservasNoGestionadas,pilaMesas,listaPedidos);
            break;
        case 10:
            break;
        case 11:
            break;
        case 12:
            break;
        case 13:
            break;
        case 14:
            break;
        case 15:
            break;
        case 16:
            break;
        case 17:
            break;
        case 18:
            break;
        case 0:
            cout << "Saliendo del programa..." << endl;
            Gestor::Salir();
            programaEnEjecucion = false;
            break;
        }
    }
    return 0;
}



