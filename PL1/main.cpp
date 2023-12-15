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

//Se inicializan las variables globales
Gestor gestor;

// Cabeceras de las funciones
int validarEntero(string mensaje,string mensajeError, int minimoIncluido, int maximoExcluido,int maxIntentos);
Pedido* cogerDatosPedido();

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
        cout << "0.  Generar una cola de reservas aleatoria realizadas por los clientes" << endl;
        cout << "1.  Mostrar los datos de la cola de reservas realizadas por los clientes" << endl;
        cout << "2.  Borrar los datos de la cola de reservas" << endl;
        cout << "3.  Generar una pila de 20 mesas aleatoria" << endl;
        cout << "4.  Mostrar los datos de la pila de mesas" << endl;
        cout << "5.  Borrar los datos de la pila de mesas" << endl;
        cout << "6.  Simular la gesti�n de la pr�xima reserva de la cola" << endl;
        cout << "7.  Simular la gesti�n de toda la ronda de reservas de la pr�xima hora" << endl;
        cout << "8.  Simular la gesti�n de todas las reservas de la cola" << endl;
        cout << "9.  A�adir pedidos a la lista de pedidos" << endl;
        cout << "10. Mostrar los datos de la lista de pedidos" << endl;
        cout << "11. Mostrar los datos de la cola de reservas" << endl;
        cout << "12. Mostrar los datos de la cola de reservas pendientes" << endl;
        cout << "13. A�adir un pedido al �rbol binario de pedidos" << endl;
        cout << "14. Mostrar los datos del �rbol binario de pedidos" << endl;
        cout << "15. Mostrar los clientes que hayan realizado al menos un pedido" << endl; //En orden alfab�tico
        cout << "16. Mostrar los pedidos realizados por un cliente" << endl;
        cout << "17. Mostrar el n�mero de pedidos realizados por categor�a " << endl;
        cout << "18. Mostrar los clientes que han pedido men� vegano " << endl;
        cout << "19. Salir\n" << endl;

        int maxIntentos = 3;

        //Se pide y valida la eleccion del usuario
        int eleccion = validarEntero("Elige una opci�n: ","La elecci�n escogida no es correcta. Escoge una v�lida.\n",0,20,3);
        //Si se supera el m�ximo n�mero de intentos el programa finaliza.
        if(eleccion == -1)
        {
            cout << "Superaste el n�mero de intentos de elecci�n. Finalizando programa." << endl;
            return 0;
        }

        //Se selecciona y ejecuta la elecci�n elegida
        switch(eleccion)
        {
        case 0:
            cout << "Generando aleatoriamente la cola de reservas..." << endl;
            gestor.generarColaReservas();
            break;
        case 1:
            cout << "Mostrando la cola de reservas creada..." << endl;
            gestor.mostrarColaReservas();
            break;
        case 2:
            cout << "Vaciando la cola de reservas..." << endl;
            gestor.vaciarColaReservas();
            break;
        case 3:
            cout << "Generando aleatoriamente la pila de mesas..." << endl;
            gestor.generarPilaMesas();
            break;
        case 4:
            cout << "Mostrando la pila de mesas creada..." << endl;
            gestor.mostrarPilaMesas();
            break;
        case 5:
            cout << "Vaciando la pila de mesas..." << endl;
            gestor.vaciarPilaMesas();
            break;
        case 6:
            cout << "Simulando la gesti�n de la primera reserva de la cola de reservas..." << endl;
            gestor.simularGestionProximaReserva(); //Opci�n 6
            gestor.mostrarDatos();
            break;
        case 7:
            cout << "Simulando la gesti�n de las reservas y creaci�n de pedidos de todas las reservas para la misma hora..." << endl;
            gestor.simularGestionReservasProximaHora(); //Opci�n 7
            gestor.mostrarDatos();
            break;
        case 8:
            cout << "Simulando la gesti�n de todas las reservas del restaurante..." << endl;
            gestor.simularGestionReservasTotal(); //Opci�n 8
            gestor.mostrarDatos();
            gestor.mostrarAbbPedidos();
            break;
        case 9:{
            int numPedidos = validarEntero("�Cu�ntos pedidos quieres a�adir? (Max: 10) ('c' para cancelar): ","Introduce un n�mero de pedidos entre 1 y 10",1,11,100);
            if (numPedidos == -1){
                cout << "Volviendo al men� principal." << endl;
                break;
            }

            Pedido** pedidos = new Pedido*[numPedidos];
            bool error = false;
            for(int i = 0; i<numPedidos;i++){
                cout << "Introduce los datos del pedido " << (i+1) << ":" << endl;
                Pedido* pedido = cogerDatosPedido();
                if (pedido == nullptr){
                    cout << "Error cogiendo los datos de los pedidos. No se a�adieron los pedidos a la lista de pedidos." << endl;
                    error = true;
                    break;
                }else{
                    pedidos[i] = pedido;
                }
            }
            if (!error){
                gestor.insertarPedidosEnLista(pedidos,numPedidos);
                cout << "Insertados los " << numPedidos << " pedidos en la lista de pedidos." << endl;
            }
            break;
            }

        case 10:
            cout << "Mostrando los datos de la lista de pedidos..." << endl;
            gestor.mostrarListaPedidos();
            break;
        case 11:
            cout << "Mostrando los datos de la cola de reservas..." << endl;
            gestor.mostrarColaReservas();
            break;
        case 12:
            cout << "Mostrando los datos de la cola de reservas pendientes..." << endl;
            gestor.mostrarColaReservasPendientes();
            break;
        case 13:{
            cout << "Introduce los datos del pedido:" << endl;
            Pedido* pedido = cogerDatosPedido();
            if (pedido == nullptr){
                cout << "Error cogiendo los datos del pedido. No se a�adi� el pedido al ABB de pedidos." << endl;
                break;
            }
            gestor.insertarPedidoEnABB(pedido);
            cout << "Pedido a�adido al �rbol binario de b�squeda de pedidos." << endl;
            break;}
        case 14:
            cout << "Mostrando los datos del �rbol binario de b�squeda de pedidos..." << endl;
            gestor.mostrarAbbPedidos();
        case 15:
            cout << "Mostrando los nombres de todos los clientes que han hecho un pedido en orden alfab�tico:" << endl;
            gestor.mostrarNombresClientesAlfabeticamente();
            break;
        case 16:{
            string nombre;
            cout << "�De que cliente quieres ver los pedidos realizados? : ";
            cin >> nombre;
            cout << endl;
            gestor.mostrarPedidosDeCliente(nombre);
            break;
        }
        case 17:
            cout << "Mostrando los n�meros de pedidos gestionados por categor�a:" << endl;
            gestor.mostrarCantidadPedidoPorCategoria();
            break;
        case 18:
            cout << "Mostrando los datos de los clientes que han pedido men� vegano:" << endl;
            gestor.mostrarClientesConMenuVegano();
            break;
        case 19:
            cout << "Saliendo del programa..." << endl;
            gestor.Salir();
            programaEnEjecucion = false;
            break;
        }
    }
    return 0;
}

Pedido* cogerDatosPedido(){
    /** Recoge los datos de los clientes*/
    cout << "Introduzca el nombre del cliente: ";
    string nombreCliente;
    cin >> nombreCliente;
    int numPersonas = validarEntero("Introduzca el n�mero de personas ('c' para cancelar): ","\nIntroduce un n�mero v�lido entre 1 y 8",1,9,1000);
    // Si algo falla validando los n�meros se devuelve nullptr
    if (numPersonas == -1){
        return nullptr;
    }
    int numPreferencia = validarEntero("Elija la preferenc�a de men� (Escoja el n�mero)('c' para cancelar):\n1. Vegano\n2. Sin glut�n\n3. Completo\n","Introduce un n�mero v�lido",1,4,100);
    // Si algo falla validando los n�meros se devuelve nullptr
    if (numPreferencia == -1){
        return nullptr;
    }
    int numSituacion = validarEntero("Elija la situaci�n de la mesa (Escoja el n�mero)('c' para cancelar):\n1. Terraza\n2. Interior\n","Introduce un n�mero v�lidO",1,3,100);
    // Si algo falla validando los n�meros se devuelve nullptr
    if (numSituacion == -1){
        return nullptr;
    }

    string menus[] = {"vegano", "sinGluten", "completo"};
    string preferencia = menus[numPreferencia-1];
    string situaciones[] = {"Terraza","Interior"};
    string situacionMesa = situaciones[numSituacion-1];

    //Se crea una nueva reserva con los datos para poder procesarla y que se le encuentren o no mesas
    Reserva* reservaFicticia = new Reserva(nombreCliente,"",situacionMesa,numPersonas,preferencia);
    Pedido* pPedido = gestor.procesarReserva(reservaFicticia,false,false,false);
    return pPedido;
}

int validarEntero(string mensaje,string mensajeError, int minimoIncluido, int maximoExcluido,int maxIntentos){
    bool eleccionValida = false;
    int eleccion = -1;

    //Se pide y valida la eleccion del usuario
    while(!eleccionValida && maxIntentos>0)
    {
        string input;
        cout << mensaje;
        cin >> input;

        if(input == "c"){
            cout << "Operaci�n cancelada. ";
            return -1;
        }

        char* finalDeCadena;
        eleccion = strtol(input.c_str(), &finalDeCadena, 10);
        if(eleccion >=minimoIncluido && eleccion < maximoExcluido && *finalDeCadena == '\0')
        {
            eleccionValida=true;
        }
        else
        {
            cout << mensajeError << endl;
        }
        maxIntentos--;
    }
    if(maxIntentos == 0){
        return -1;
    }else{
        return eleccion;
    }

}


