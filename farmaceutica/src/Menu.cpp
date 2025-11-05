#include <iostream>
#include "Menu.h"
#include "ClientesManager.h"
#include "ObrasSocialesManager.h"
#include <iostream>
using namespace std;

void limpiarPantalla();
void cargar();

void Menu::menuPrincipal()
{
    int opcion;

    do
    {
        limpiarPantalla();

        cout << "--- Menu Principal ---" << endl;
        cout << "1. Clientes" << endl;
        cout << "2. Obras Sociales" << endl;

        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cout << endl;

        switch (opcion)
        {
        case 1:
            menuClientes();
            break;
        case 2:
            menuOS();
            break;
        case 0:
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            cout << "Opcion invalida. Intente de nuevo." << endl << endl;
            system("pause");
            cout << endl;
        }
    }
    while(opcion != 0);
}

void Menu::menuClientes()
{
    int opcion;

    do
    {
        limpiarPantalla();

        cout << "--- Menu Clientes ---" << endl;

        cout << "1. Cargar cliente" << endl;
        cout << "2. Listar Clientes"<< endl;
        cout << "3. Buscar Cliente por CUIL"<<endl;
        cout<<"4. Modificar Cliente"<<endl;

        cout << "0. Atras" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cout << endl;

        ClientesManager mgr;

        switch (opcion)
        {
        case 1:
            limpiarPantalla();
            mgr.alta();
            break;
        case 2:
            limpiarPantalla();
            mgr.mostrar();
            break;
        case 3:
            limpiarPantalla();
            mgr.mostrarxCUIL();
            break;

        case 4:
            limpiarPantalla();
            mgr.modificar();


        case 0:
            break;
        default:
            cout << "Opcion invalida. Intente de nuevo." << endl << endl;
            system("pause");
            cout << endl;
        }
    }
    while(opcion != 0);
}

void Menu::menuOS()
{
    int opcion;

    do
    {
        limpiarPantalla();

        cout << "--- Menu Obras Sociales ---" << endl;

        cout << "1. Cargar Obra Social" << endl;
        cout << "2. Listar Obras Sociales"<< endl;
        cout<< "3. Modificar Obra Social"<<endl;

        cout << "0. Atras" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cout << endl;

        ObrasSocialesManager mgr;

        switch (opcion)
        {
        case 1:
            limpiarPantalla();
            mgr.alta();
            break;
        case 2:
            limpiarPantalla();
            mgr.mostrar();
            break;


        case 3:
            limpiarPantalla();
            mgr.modificar();

        case 0:
            break;
        default:
            cout << "Opcion invalida. Intente de nuevo." << endl << endl;
            system("pause");
            cout << endl;
        }
    }
    while(opcion != 0);
}

void limpiarPantalla()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
