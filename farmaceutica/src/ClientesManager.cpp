#include <iostream>
#include <limits>
#include "ClientesManager.h"
#include "Cliente.h"
#include "ArchivoClientes.h"
using namespace std;

void ClientesManager::alta()
{
    int cuil, ob;
    char nom[20] {}, ape[20] {}, dom[50], mail[30], tel[12];
    ArchivoClientes arch("clientes.dat");

    cout << "Ingrese datos de cliente" << endl;
    cout << "CUIL: ";
    cin >> cuil;

    if (arch.buscarPorCUIL(cuil) != -1)
    {
        cout << endl << "EL CUIL ingresado ya esta agregado" << endl;
    }
    else
    {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Nombre: ";
        cin.getline(nom, sizeof(nom));

        cout << "Apellido: ";
        cin.getline(ape, sizeof(ape));

        cout << "ID de Obra Social: ";
        cin >> ob;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Domicilio: ";
        cin.getline(dom, sizeof(dom));

        cout << "Mail: ";
        cin.getline(mail, sizeof(mail));

        cout << "Telefono: ";
        cin.getline(tel, sizeof(tel));
        cout << endl;

        Cliente c(cuil, nom, ape, ob, dom, mail, tel, false);

        // Esta es la funcion de la clase ArchivoClientes
        ArchivoClientes archi("clientes.dat");

        if(archi.guardarCliente(c))
        {
            cout << "Cliente guardado exitosamente" << endl;
        }
        else
        {
            cout << "Error al guardar el cliente" << endl;
        }
    }
    system("pause");
}

void ClientesManager::mostrar()
{
    ArchivoClientes archi("clientes.dat");

    int cantReg= archi.cantidadRegistros();

    if (cantReg <= 0) {
        cout << "No hay clientes para mostrar." << endl;
        system("pause");
        return;
    }

    // Reservar memoria
    Cliente* clientes = new Cliente[cantReg];

    // Leer todos los clientes
    for (int i = 0; i < cantReg; i++) {
        clientes[i] = archi.leerClientes(i);
    }

    // Ordenar por CUIL
    for (int i = 0; i < cantReg - 1; i++) {
        for (int j = 0; j < cantReg - i - 1; j++) {
            if (clientes[j].getCuil() > clientes[j + 1].getCuil()) {
                Cliente aux = clientes[j];
                clientes[j] = clientes[j + 1];
                clientes[j + 1] = aux;
            }
        }
    }

    for(int i = 0; i < cantReg; i++)
    {
        Cliente c = clientes[i];

        cout << "CUIL: " << c.getCuil() << endl;
        cout << "Nombre: " << c.getNombre() << endl;
        cout << "Apellido: " << c.getApellido() << endl;
        cout << "Obra Social: " << c.getIdObraSocial() << endl;
        cout << "Domicilio: " << c.getDomicilio() << endl;
        cout << "Mail: " << c.getMail() << endl;
        cout << "Telefono: " << c.getTelefono() << endl;
        cout << "Eliminado: " << (c.getEliminado() ? "Sí" : "No") << endl;
        cout << "==============================================" << endl;

    }

    delete[] clientes;
    system("pause");
}

void ClientesManager::mostrarxCUIL()
{
    int cuilBuscado;
    cout << "Ingrese el CUIL del cliente a buscar: ";
    cin >> cuilBuscado;

    ArchivoClientes archi("clientes.dat");
    int pos = archi.buscarPorCUIL(cuilBuscado);

    if (pos != -1)
    {
        Cliente c = archi.leerClientes(pos);  // leer cliente encontrado

        cout << "\n--- Cliente encontrado ---\n";
        cout << "CUIL: " << c.getCuil() << endl;
        cout << "Nombre: " << c.getNombre() << endl;
        cout << "Apellido: " << c.getApellido() << endl;
        cout << "Obra Social: " << c.getIdObraSocial() << endl;
        cout << "Domicilio: " << c.getDomicilio() << endl;
        cout << "Mail: " << c.getMail() << endl;
        cout << "Telefono: " << c.getTelefono() << endl;
        cout << "Eliminado: " << (c.getEliminado() ? "Sí" : "No") << endl;
        cout << "==============================" << endl;
    }
    else
    {
        cout << "Cliente no encontrado." << endl;
    }

    system("pause");  // pausa para que el usuario vea el resultado
}
