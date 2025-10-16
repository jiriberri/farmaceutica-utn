#include <iostream>
#include "Menu.h"
#include "ClientesManager.h"

using namespace std;

void limpiarPantalla();
void cargar();

void Menu::menuPrincipal(){
    int opcion;

    do{
        limpiarPantalla();

        cout << "--- Menu Principal ---" << endl;
        cout << "1. Clientes" << endl;

        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cout << endl;

        switch (opcion){
        case 1:
            menuClientes();
            break;
        case 0:
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            cout << "Opcion invalida. Intente de nuevo." << endl << endl;
            system("pause");
            cout << endl;
        }
    } while(opcion != 0);

}

void Menu::menuClientes(){
    int opcion;

    do{
        limpiarPantalla();

        cout << "--- Menu Clientes ---" << endl;

        cout << "1. Cargar cliente" << endl;
        cout << "0. Atras" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cout << endl;

        switch (opcion){
        case 1:
            limpiarPantalla();
            ClientesManager mgr;
            mgr.alta();
            break;
        case 0:
            break;
        default:
            cout << "Opcion invalida. Intente de nuevo." << endl << endl;
            system("pause");
            cout << endl;
        }
    } while(opcion != 0);
}

void limpiarPantalla(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
