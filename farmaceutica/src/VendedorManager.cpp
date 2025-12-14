#include <iostream>
#include <limits>
#include "VendedorManager.h"
#include "Vendedor.h"
#include "ArchivoVendedor.h"

using namespace std;




void imprimirVendedor(const Vendedor &v);


void VendedorManager::alta() {

    long long ID;
    float Sueldo;
    char nom[20]{}, ape[20]{}, dom[50], mail[30], tel[12];

    ArchivoVendedor arch("Vendedores.dat");

    cout << "Ingrese datos del Vendedor" << endl;
    cout << "ID: ";
    cin >> ID;

    int pos = arch.buscarPorID(ID);

    if (arch.existe() && pos != -1)
    {
        cout << endl << "EL ID ingresado ya esta agregado" << endl;

        if (arch.checkEliminado(pos))
        {
            char opcion;
            cout << "Este Vendedor esta eliminado. Reactivar? (S/N): ";
            cin >> opcion;

            if (opcion == 'S' || opcion == 's')
            {
                if (arch.reactivarEmpleado(pos))
                    cout << "Reactivado correctamente." << endl;
                else
                    cout << "Error al reactivar." << endl;
            }
        }
        system("pause");
        return;
    }


    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Nombre: ";
    cin.getline(nom, sizeof(nom));

    cout << "Apellido: ";
    cin.getline(ape, sizeof(ape));

    cout << "Sueldo: $";
    cin >> Sueldo;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Domicilio: ";
    cin.getline(dom, sizeof(dom));

    cout << "Mail: ";
    cin.getline(mail, sizeof(mail));

    cout << "Telefono: ";
    cin.getline(tel, sizeof(tel));

    Vendedor v(ID, nom, ape, Sueldo, dom, mail, tel, false);

    if (arch.guardarVendedor(v))
        cout << "Vendedor guardado exitosamente." << endl;
    else
        cout << "ERROR al guardar vendedor." << endl;

    system("pause");
}

void VendedorManager::mostrar(){
 ArchivoVendedor archi("Vendedores.dat");

    if (!archi.existe()) {
        cout << "No hay Vendedores para mostrar." << endl;
        system("pause");
        return;
    }

    int cantReg= archi.cantidadRegistros();

    if (cantReg <= 0) {
        cout << "No hay Vendedores para mostrar." << endl;
        system("pause");
        return;
    }

    Vendedor* vendedores = new Vendedor[cantReg];

    for (int i = 0; i < cantReg; i++) {
        vendedores[i] = archi.leerVendedor(i);
    }

    for (int i = 0; i < cantReg - 1; i++) {
        for (int j = 0; j < cantReg - i - 1; j++) {
            if (vendedores[j].getId() > vendedores[j + 1].getId()) {
                Vendedor aux = vendedores[j];
                vendedores[j] = vendedores[j + 1];
                vendedores[j + 1] = aux;
            }
        }
    }

    for(int i = 0; i < cantReg; i++)
    {
        Vendedor v = vendedores[i];

        if (!v.getEliminado()) {
            imprimirVendedor(v);
            cout << "==============================================" << endl;
        }

    }

    delete[] vendedores;
    system("pause");


}


void VendedorManager::mostrarxID()
{
    long long idBuscado;
    cout << "Ingrese el id del Vendedor a buscar: ";
    cin >> idBuscado;

    ArchivoVendedor archi("Vendedores.dat");
    int pos = archi.buscarPorID(idBuscado);

    if (pos < 0)
    {
        cout << "Vendedor no encontrado." << endl;
        system("pause");
        return;
    }


    Vendedor v = archi.leerVendedor(pos);

    if (v.getEliminado()) {
        cout << "\nEl Vendedor con ese ID esta dado de baja." << endl;
        system("pause");
        return;
    }


    cout << "\n--- Vendedor encontrado ---\n";
    imprimirVendedor(v);
    cout << "==============================================" << endl;

    system("pause");
}



void VendedorManager::modificar()
{
    long long idBuscado;
    cout << "Ingrese el ID del Vendedor que quiera modificar: ";
    cin >> idBuscado;

    ArchivoVendedor archi("Vendedores.dat");

    int pos = archi.buscarPorID(idBuscado);

    if (pos < 0)
    {
        cout << "Vendedor no encontrado." << endl;
        system("pause");
        return;
    }

    Vendedor v = archi.leerVendedor(pos);

    if (v.getEliminado())
    {
        cout << "\nEl Vendedor esta dado de baja. Para reactivarlo, agreguelo nuevamente." << endl;
        system("pause");
        return;
    }

    int opcion;
    cout << "\n--- Vendedor encontrado ---\n";
    cout << "==============================================" << endl;
    imprimirVendedor(v);
    cout << "==============================================" << endl;

    cout << "1. Modificar domicilio" << endl;
    cout << "2. Modificar mail" << endl;
    cout << "3. Modificar telefono" << endl;
    cout << "4. Modificar Sueldo" << endl;
    cout << "0. Cancelar" << endl;
    cout << "Seleccione una opcion: ";
    cin >> opcion;
    cout << endl;

    switch (opcion)
    {
        case 1:
        {
            char nuevoDomicilio[50];
            cout << "Ingrese nuevo domicilio: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.getline(nuevoDomicilio, sizeof(nuevoDomicilio));
            v.setDomicilio(nuevoDomicilio);
            break;
        }

        case 2:
        {
            char nuevoMail[30];
            cout << "Ingrese nuevo mail: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.getline(nuevoMail, sizeof(nuevoMail));
            v.setMail(nuevoMail);
            break;
        }

        case 3:
        {
            char nuevoTelefono[12];
            cout << "Ingrese nuevo telefono: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.getline(nuevoTelefono, sizeof(nuevoTelefono));
            v.setTelefono(nuevoTelefono);
            break;
        }

        case 4:
        {
            int nuevoSueldo;
            cout << "Ingrese el nuevo sueldo: ";
            cin >> nuevoSueldo;
            v.setSueldo(nuevoSueldo);
            break;
        }

        case 0:
            cout << "Operacion cancelada." << endl;
            system("pause");
            return;

        default:
            cout << "Opcion invalida." << endl;
            system("pause");
            return;
    }


    if (archi.modificarVendedor(v, pos))
    {
        cout << "El Vendedor se modifico de manera correcta" << endl;
    }
    else
    {
        cout << "Error al modificar el Vendedor." << endl;
    }

    system("pause");
}

void VendedorManager::baja() {
    long long idBuscado;
    cout << "Ingrese el ID del Vendedor a buscar: ";
    cin >> idBuscado;

    ArchivoVendedor archi("Vendedores.dat");
    int pos = archi.buscarPorID(idBuscado);

    if (pos < 0) {
        cout << "No existe el ID en el archivo." << endl;
        system("pause");
        return;
    }

    Vendedor obj = archi.leerVendedor(pos);

    if (obj.getEliminado()) {
        cout << "\nEl Vendedor ya esta dado de baja." << endl;
        system("pause");
        return;
    }
    cout << "\n--- Vendedor encontrado ---\n";
    imprimirVendedor(obj);
    cout << "Eliminado: " << (obj.getEliminado() ? "Si" : "No") << endl;
    cout << "==============================================" << endl;

    char opcion;
    cout << "\nEsta seguro que desea dar de baja este Vendedor? (S/N): ";
    cin >> opcion;

    if (opcion != 'S' && opcion!='s') {
        cout << "Operacion cancelada." << endl;
        system("pause");
        return;
    }


    obj.setEliminado(true);
    archi.modificarVendedor(obj, pos);

    cout << "\nVendedor dado de baja correctamente." << endl;
    system("pause");
}










void imprimirVendedor(const Vendedor &v){
    cout << "ID: " << v.getId() << endl;
    cout << "Nombre: " << v.getNombre() << endl;
    cout << "Apellido: " << v.getApellido() << endl;
    cout << "Sueldo: $" << v.getSueldo() << endl;
    cout << "Domicilio: " << v.getDomicilio() << endl;
    cout << "Mail: " << v.getMail() << endl;
    cout << "Telefono: " << v.getTelefono() << endl;
}

