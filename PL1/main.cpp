#include <iostream>
#include <locale.h>
using namespace std;



int main()
{
    //Cambiamos el formato de texto de la consola para que soporte tildes y otros car�cteres castellanos
    setlocale(LC_ALL, "");

    //string nombresPosibles[] = {"Alice", "Bob", "Charlie", "David", "Eve", "Frank","Grace", "Hannah", "Ivan", "Jack", "Karen"}

    //Comienzo de programa
    //Mostrar por pantalla las opciones disponibles:
    cout << "Bienvenido al simulador de gesti�n de mesas y reservas UltraReserva3000.\n";
    cout << "Escribe el n�mero de una las siguientes opciones para realizarla:\n";
    cout << "1. Generar una cola de reservas aleatoria\n";
    cout << "2. Mostrar los datos de la cola de reservas\n";
    cout << "3. Borrar los datos de la cola de reservas\n";
    cout << "4. Gerarar una pila de 20 mesas aleatoria\n";
    cout << "5. Mostrar los datos de la pila de mesas\n";
    cout << "6. Borrar los datos de la pila de mesas\n";
    cout << "7. Simular la gesti�n de la pr�xima reserva de la cola\n";
    cout << "8. Simular la gesti�n de toda la ronda de reservas de la pr�xima hora\n";
    cout << "9. Simular la gesti�n de todas las reservas de la cola\n";
    cout << "0. Salir\n\n";

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
            cout << "La elecci�n escogida no es correcta. Escoge una v�lida.\n\n";
        }
        maxIntentos--;
    }
    if(maxIntentos == 0)
    {
        cout << "Superaste el n�mero de intentos de elecci�n. Finalizando programa.";
        return 0;
    }

    switch(eleccion)
    {
        case 1:
            cout << "Opcion 1";
            break;
        case 2:
            cout << "Salir";
            break;
        case 3:
            cout << "Salir";
            break;
        case 4:
            cout << "Salir";
            break;
        case 5:
            cout << "Salir";
            break;
        case 6:
            cout << "Salir";
            break;
        case 7:
            cout << "Salir";
            break;
        case 8:
            cout << "Salir";
            break;
        case 9:
            cout << "Salir";
            break;
        case 0:
            cout << "Salir";
            break;
    }

    cout << "EndOfMain";



}
