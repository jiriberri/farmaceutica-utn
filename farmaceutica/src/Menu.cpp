#include <iostream>
#include "Menu.h"
#include "ClientesManager.h"
#include "ObrasSocialesManager.h"
#include "ProductosManager.h"
#include "VentasManager.h"
#include "VendedorManager.h"
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

cout << "+--------------------------+" << endl;
cout << "|      MENU PRINCIPAL      |" << endl;
cout << "+--------------------------+" << endl;
cout << "| 1. Clientes              |" << endl;
cout << "| 2. Obras Sociales        |" << endl;
cout << "| 3. Vendedores            |" << endl;
cout << "| 4. Productos             |" << endl;
cout << "| 5. Ventas                |" << endl;
cout << "+--------------------------+" << endl;
cout << "| 0. Salir                 |" << endl;
cout << "+--------------------------+" << endl;
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
        case 3:
            menuVendedores();
            break;
        case 4:
            menuProductos();
            break;
        case 5:
            menuVentas();
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
        cout << "+----------------------------+" << endl;
        cout << "|    --- Menu Clientes ---   |" << endl;
        cout << "+----------------------------+" << endl;
        cout << "|[1]. Cargar cliente         |" << endl;
        cout << "|[2]. Listar Clientes        |"<< endl;
        cout << "|[3]. Buscar Cliente por CUIL|"<<endl;
        cout << "|[4]. Modificar Cliente      |"<<endl;
         cout <<"|[5]. Baja Cliente           |"<<endl;
         cout <<"+----------------------------+" << endl;
        cout << "|[0]. Atras                  |" << endl;
         cout <<"+----------------------------+" << endl;

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
            break;
        case 5:
            limpiarPantalla();
            mgr.baja();

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
        cout << "+------------------------------+" << endl;
        cout << "|  --- Menu Obras Sociales --- |" << endl;
        cout << "+------------------------------+" << endl;
        cout << "|1). Cargar Obra Social        |" << endl;
        cout << "|2). Listar Obras Sociales     |" << endl;
        cout << "|3). Modificar Obra Social     |" << endl;
        cout << "|4). Baja Obra Social          |" << endl;
        cout << "+------------------------------+" << endl;
        cout << "|0). Atras                     |" << endl;
        cout << "+------------------------------+" << endl;
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
            break;
        case 4:
            limpiarPantalla();
            mgr.baja();

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

void Menu::menuProductos()
{
    int opcion;

    do
    {
        limpiarPantalla();

        cout << "--- [Menu Productos] ---" << endl;
        cout << "---------------------------" << endl;
        cout << "1). Cargar Producto" << endl;
        cout << "2). Listar Productos"<< endl;
        cout << "3). Modificar Producto" << endl;
        cout << "4). Eliminar Producto" << endl;
        cout << "---------------------------" << endl;
        cout << "0). [Atras]" << endl;
        cout << "---------------------------" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cout << endl;

        ProductosManager mgr;

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
            break;
        case 4:
            limpiarPantalla();
            mgr.baja();
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

void Menu::menuVentas()
{
    int opcion;

    do
    {
        limpiarPantalla();

         cout <<" +--------------------------------+" << endl;
        cout << " |      --- Menu Ventas ---       |" << endl;
          cout<<" +--------------------------------+" << endl;
        cout << " |1. Nueva venta                  |" << endl;
        cout << " |2. Listar ventas                |"<< endl;
        cout << " |3. Buscar por numero de factura |" << endl;
        cout << " |4. Eliminar venta               |" << endl;
        cout << " +--------------------------------+" << endl;
        cout << " |0. Atras                        |" << endl;
        cout << " +--------------------------------+" << endl;

        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cout << endl;

        VentasManager mgr;

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
            mgr.buscarxId();
            break;
        case 4:
            limpiarPantalla();
            mgr.baja();
            break;
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

void Menu::menuVendedores(){

int opcion;

    do
    {
        limpiarPantalla();


cout << "--- [Menú Vendedores] ---" << endl;
 cout << "---------------------------" << endl;
        cout << "1). Cargar Vendedores" << endl;
        cout << "2). Listar Vendedores"<< endl;
        cout << "3). Buscar Vendedor por ID"<<endl;
        cout << "4). Modificar Vendedor"<<endl;
        cout <<"5). Baja Vendedor"<<endl;
        cout << "---------------------------" << endl;
        cout << "0). [Atras]" << endl;
        cout << "---------------------------" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cout << endl;

        VendedorManager mgr;

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
            mgr.mostrarxID();
            break;

        case 4:
            limpiarPantalla();
            mgr.modificar();
            break;
        case 5:
            limpiarPantalla();
            mgr.baja();
            break;
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
