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

    cout << "Ingrese datos de cliente" << endl;
    cout << "CUIL: ";
    cin >> cuil;
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


    ///Esta es la funcion de la clase ArchivoClientes
    ArchivoClientes archi("clientes.dat");

    if(archi.guardarCliente(c))
    {
        cout<<"Cliente guardado exitosamente"<<endl;
    }
    else
    {
        cout<<"Error al guardar el cliente"<<endl;
    }

    system("pause");
}

void ClientesManager::mostrar()
{

    ArchivoClientes archi("clientes.dat");

    int cantreg= archi.cantidadRegistros();

    for(int i =0; i< cantreg; i++)
    {
        Cliente c =archi.leerClientes(i);

        cout << "CUIL: " << c.getCuil() << endl;
        cout << "Nombre: " << c.getNombre() << endl;
        cout << "Apellido: " << c.getApellido() << endl;
        cout << "Obra Social: " << c.getIdObraSocial() << endl;
        cout << "Domicilio: " << c.getDomicilio() << endl;
        cout << "Mail: " << c.getMail() << endl;
        cout << "Telefono: " << c.getTelefono() << endl;
        cout << "Eliminado: " << (c.getEliminado() ? "Sí" : "No") << endl;
        cout<< "=============================================="<<endl;

    }
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
