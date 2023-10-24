#include <iostream>
#include <locale.h>
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
Lista listaPedidos;
Pila pilaMesas;

//Se inicializan las variables est�ticas
int Gestor::numReservasGestionadas = 0;

int main()
{
    //Cambiamos el formato de texto de la consola para que soporte tildes y otros car�cteres castellanos
    setlocale(LC_ALL, "");


    //Comienzo de programa
    //Mostrar por pantalla las opciones disponibles:
    cout << "Bienvenido al simulador de gesti�n de mesas y reservas UltraReserva3000." << endl;

    bool programaEnEjecucion = true;
    while(programaEnEjecucion)
    {
        cout << endl << "Men�: Escribe el n�mero de una las siguientes opciones para realizarla:" << endl;
        cout << "1. Generar una cola de reservas aleatoria" << endl;
        cout << "2. Mostrar los datos de la cola de reservas" << endl;
        cout << "3. Borrar los datos de la cola de reservas" << endl;
        cout << "4. Generar una pila de 20 mesas aleatoria" << endl;
        cout << "5. Mostrar los datos de la pila de mesas" << endl;
        cout << "6. Borrar los datos de la pila de mesas" << endl;
        cout << "7. Simular la gesti�n de la pr�xima reserva de la cola" << endl;
        cout << "8. Simular la gesti�n de toda la ronda de reservas de la pr�xima hora" << endl;
        cout << "9. Simular la gesti�n de todas las reservas de la cola" << endl;
        cout << "0. Salir\n" << endl;

        int eleccion = 0;
        cout << eleccion << endl;
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

        switch(eleccion)
        {
        case 1:
            cout << "Introduce el n�mero de reservas aleatorias a gestionar:" << endl;
            try
            {
                int numero;
                cin >> numero;
                if(numero>=12 && numero<=50)
                {
                    cout << "Generando aleatoriamente la cola de reservas..." << endl;
                    Gestor::generarColaReservas(colaReservas,numero);
                }
                else
                {
                    cout << "N�mero o car�cter incorrecto. Volviendo al men� principal..." <<endl;
                }
            }
            catch(exception& e)
            {
                cout << "N�mero o car�cter incorrecto. Volviendo al men� principal..."<<endl;
            }
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
            Gestor::simularGestionProximaReserva(colaReservas, colaReservasPdtes, pilaMesas,listaPedidos);
            break;
        case 8:
            cout << "Simulando la gesti�n de las reservas y creaci�n de pedidos de todas las reservas para la misma hora..." << endl;
            Gestor::simularGestionReservasProximaHora(colaReservas, colaReservasPdtes,pilaMesas, listaPedidos); //Opci�n 8
            break;
        case 9:
            cout << "Simulando la gesti�n de todas las reservas del restaurante..." << endl;
            Gestor::simularGestionReservasTotal(colaReservas, colaReservasPdtes,pilaMesas, listaPedidos); //Opci�n 9
            break;

        case 0:
            cout << "Saliendo del programa..." << endl;
            Gestor::Salir();
            programaEnEjecucion = false;
            break;
        }
    }
    cout << "EndOfMain";



}



