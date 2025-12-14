#include <iostream>
#include <limits>
#include "ClientesManager.h"
#include "Cliente.h"
#include "ArchivoClientes.h"
#include "ArchivoObrasSociales.h"

using namespace std;

void imprimirCliente(const Cliente &c);
int checkOS(int id);

void ClientesManager::alta()
{
    long long cuil;
    int ob;
    char nom[20] {}, ape[20] {}, dom[50], mail[30], tel[12];
    ArchivoClientes arch("clientes.dat");

    cout << "Ingrese datos de cliente" << endl;
    cout << "CUIL: ";
    cin >> cuil;

    int pos = arch.buscarPorCUIL(cuil); //posicion al buscar por cuil, si no lo encuentra entonces es -1

    if (arch.existe() && pos != -1)
    {
        cout << endl << "EL CUIL ingresado ya esta agregado" << endl;

        if(arch.checkEliminado(pos))
        {
            char opcion;

            cout << endl << "Este cliente esta eliminado" << endl;
            cout << "Desea reactivarlo? (S/N): ";
            cin >> opcion;
            cout << endl;

            if(opcion == 'S' || opcion == 's')
            {
                if (arch.reactivarCliente(pos))
                {
                    cout << "El cliente fue reactivado exitosamente" << endl;
                }
                else
                {
                    cout << "No se pudo reactivar el cliente" << endl;
                }
            }
        }
        system("pause");
        return;
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
        
        // chequea que la OS exista
        int idOS = checkOS(ob);
        if(idOS == -1) return;

        cout << "Domicilio: ";
        cin.getline(dom, sizeof(dom));

        cout << "Mail: ";
        cin.getline(mail, sizeof(mail));

        cout << "Telefono: ";
        cin.getline(tel, sizeof(tel));
        cout << endl;

        Cliente c(cuil, nom, ape, ob, dom, mail, tel, false);

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

    if (!archi.existe()) {
        cout << "No hay clientes para mostrar." << endl;
        system("pause");
        return;
    }

    int cantReg= archi.cantidadRegistros();

    if (cantReg <= 0) {
        cout << "No hay clientes para mostrar." << endl;
        system("pause");
        return;
    }

    Cliente* clientes = new Cliente[cantReg];

    for (int i = 0; i < cantReg; i++) {
        clientes[i] = archi.leerClientes(i);
    }

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

        if (!c.getEliminado()) {
            imprimirCliente(c);
            cout << "==============================================" << endl;
        }

    }

    delete[] clientes;
    system("pause");
}

void ClientesManager::mostrarxCUIL()
{
    long long cuilBuscado;
    cout << "Ingrese el CUIL del cliente a buscar: ";
    cin >> cuilBuscado;

    ArchivoClientes archi("clientes.dat");
    int pos = archi.buscarPorCUIL(cuilBuscado);

    if (pos < 0)
    {
        cout << "Cliente no encontrado." << endl;
        system("pause");
        return;
    }


    Cliente c = archi.leerClientes(pos);

    if (c.getEliminado()) {
        cout << "\nEl cliente con ese CUIL esta dado de baja." << endl;
        system("pause");
        return;
    }


    cout << "\n--- Cliente encontrado ---\n";
    imprimirCliente(c);
    cout << "==============================================" << endl;

    system("pause");
}

void ClientesManager::modificar()
{
    long long cuilBuscado;
    cout<<"Ingrese el Cuil del cliente que quiera modificar: ";
    cin>> cuilBuscado;

    ArchivoClientes archi("clientes.dat");

    int pos=archi.buscarPorCUIL(cuilBuscado);

    if(pos<0)
    {
        cout << "Cliente no encontrado." << endl;
        system("pause");
        return;
    }

    Cliente c;
    c=archi.leerClientes(pos);

    if (c.getEliminado()) {
        cout << "\nEl cliente esta dado de baja. Para reactivarlo, agreguelo nuevamente." << endl;
        system("pause");
        return;
    }

    int opcion;
    cout << "\n--- Cliente encontrado ---\n";
    cout << "==============================================" << endl;
    imprimirCliente(c);
    cout << "==============================================" << endl;

    cout << "1. Modificar domicilio"<<endl;
    cout << "2. Modificar mail"<<endl;
    cout << "3. Modificar telefono"<<endl;
    cout<<  "4. Modificar ID Obra Social"<<endl;
    cout << "0. Cancelar"<<endl;
    cout << "Seleccione una opcion: ";
    cin >> opcion;
    cout << endl;


    switch(opcion)
    {

    case 1:
    {
        char nuevoDomicilio[50];
        cout<<"Ingrese nuevo domicilio: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.getline(nuevoDomicilio, sizeof(nuevoDomicilio));
        c.setDomicilio(nuevoDomicilio);
        break;
    }

    case 2:
    {
        char nuevoMail[30];
        cout<<"Ingrese nuevo mail: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.getline(nuevoMail, sizeof(nuevoMail));
        c.setMail(nuevoMail);
        break;
    }
    case 3:
    {
        char nuevoTelefono[12];
        cout << "Ingrese nuevo telefono: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.getline(nuevoTelefono, sizeof(nuevoTelefono));
        c.setTelefono(nuevoTelefono);
        break;

    }
    case 4:
    {
        int nuevoIdObra;
        cout << "Ingrese el nuevo ID de la obra social: ";
        cin >> nuevoIdObra;

        int idOS = checkOS(nuevoIdObra);
        if(idOS == -1) return;
        
        c.setIdObraSocial(idOS);
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

    if(archi.modificarCliente(c, pos)){
        cout<<"El Cliente se modifico de manera correcta"<<endl;
    } else{
       cout<<"Error al modificar el cliente.";
    }

    system("pause");
}

void ClientesManager::baja() {
    long long cuilBuscado;
    cout << "Ingrese el CUIL del cliente a buscar: ";
    cin >> cuilBuscado;

    ArchivoClientes arc("clientes.dat");
    int pos = arc.buscarPorCUIL(cuilBuscado);

    if (pos < 0) {
        cout << "No existe el CUIL en el archivo." << endl;
        system("pause");
        return;
    }

    Cliente obj = arc.leerClientes(pos);

    if (obj.getEliminado()) {
        cout << "\nEl cliente ya esta dado de baja." << endl;
        system("pause");
        return;
    }
    cout << "\n--- Cliente encontrado ---\n";
    imprimirCliente(obj);
    cout << "Eliminado: " << (obj.getEliminado() ? "Si" : "No") << endl;
    cout << "==============================================" << endl;

    char opcion;
    cout << "\nEsta seguro que desea dar de baja este cliente? (S/N): ";
    cin >> opcion;

    if (opcion != 'S' && opcion!='s') {
        cout << "Operacion cancelada." << endl;
        system("pause");
        return;
    }


    obj.setEliminado(true);
    arc.modificarCliente(obj, pos);

    cout << "\nCliente dado de baja correctamente." << endl;
    system("pause");
}

void imprimirCliente(const Cliente &c){
    cout << "CUIL: " << c.getCuil() << endl;
    cout << "Nombre: " << c.getNombre() << endl;
    cout << "Apellido: " << c.getApellido() << endl;
    cout << "Obra Social: " << c.getIdObraSocial() << endl;
    cout << "Domicilio: " << c.getDomicilio() << endl;
    cout << "Mail: " << c.getMail() << endl;
    cout << "Telefono: " << c.getTelefono() << endl;
}

int checkOS(int id)
{
    ArchivoObrasSociales archOS("obrassociales.dat");
    int posOS = archOS.buscarPorId(id);

    if(posOS < 0)
    {
        cout << endl;
        cout << "La obra social con ese ID no existe." << endl;
        system("pause");
        return -1;
    }

    return id;
}