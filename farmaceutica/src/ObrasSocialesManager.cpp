#include "ObrasSocialesManager.h"
#include "ObraSocial.h"
#include "ArchivoObrasSociales.h"
#include <iostream>
#include <limits>

using namespace std;

void imprimirOS(const ObraSocial &os);

void ObrasSocialesManager::alta()
{
    int id;
    char d[100]{}, t[12]{}, m[30]{};
    float desc;
    ArchivoObrasSociales arch("obrassociales.dat");

    cout << "Ingrese datos de la obra social" << endl;
    cout << "Id: ";
    cin >> id;

    int pos = arch.buscarPorId(id);

    if (arch.existe() && pos != -1)
    {
        cout << endl << "EL Id ingresado ya esta agregado" << endl;

        if(arch.checkEliminado(pos))
        {
            char opcion;

            cout << endl << "Esta obra social esta eliminada" << endl;
            cout << "Desea reactivarla? (S/N): ";
            cin >> opcion;
            cout << endl;

            if(opcion == 'S' || opcion == 's')
            {
                if (arch.reactivarOS(pos))
                {
                    cout << "La obra social fue reactivada exitosamente" << endl;
                }
                else
                {
                    cout << "No se pudo reactivar la obra social" << endl;
                }
            }
        }

        system("pause");
        return;
    }
    else
    {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Descripcion: ";
        cin.getline(d, sizeof(d));

        cout << "Descuento: ";
        cin >> desc;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Telefono: ";
        cin.getline(t, sizeof(t));

        cout << "Mail: ";
        cin.getline(m, sizeof(m));

        cout << endl;

        ObraSocial os(id, d, desc, t, m, false);

        ArchivoObrasSociales archi("obrassociales.dat");

        if(archi.guardarOS(os))
        {
            cout << "Obra Social guardada exitosamente" << endl;
        }
        else
        {
            cout << "Error al guardar la obra social" << endl;
        }
    }

    system("pause");
}

void ObrasSocialesManager::mostrar()
{
    ArchivoObrasSociales arch("obrassociales.dat");

    if (!arch.existe()) {
        cout << "No hay obras sociales para mostrar." << endl;
        system("pause");
        return;
    }

    int cantReg = arch.cantidadRegistros();

    if (cantReg <= 0) {
        cout << "No hay obras sociales para mostrar." << endl;
        system("pause");
        return;
    }

    ObraSocial* os = new ObraSocial[cantReg];

    for (int i = 0; i < cantReg; i++) {
        os[i] = arch.leerOS(i);
    }

    for (int i = 0; i < cantReg - 1; i++) {
        for (int j = 0; j < cantReg - i - 1; j++) {
            if (os[j].getId() > os[j + 1].getId()) {
                ObraSocial aux = os[j];
                os[j] = os[j + 1];
                os[j + 1] = aux;
            }
        }
    }

    for(int i = 0; i < cantReg; i++)
    {
        ObraSocial o = os[i];

        if(!o.getEliminado()){
            imprimirOS(o);
            cout << "==============================================" << endl;
        }
    }

    delete[] os;
    system("pause");
}

void ObrasSocialesManager::modificar()
{
    int idBuscado;
    cout<<"Ingrese el id de la obra social que quiera modificar: ";
    cin>> idBuscado;

    ArchivoObrasSociales archi("obrassociales.dat");

    int pos=archi.buscarPorId(idBuscado);

    if(pos<0)
    {
        cout << "ID no encontrado." << endl;
        system("pause");
        return;
    }

    ObraSocial OS;
    OS = archi.leerOS(pos);

    if(OS.getEliminado())
    {
        cout << "La Obra Social esta dada de baja. Para reactivarla, agreguela nuevamente." << endl;
        system("pause");
        return;
    }

    int opcion;

    cout << "\n--- Obra Social encontrada ---\n";
    cout << "-----------------------------------------------" << endl;

    imprimirOS(OS);
    cout << "==============================================" << endl;

    cout << "1. Modificar descripcion"<<endl;
    cout << "2. Modificar descuento"<<endl;
    cout << "3. Modificar telefono"<<endl;
    cout << "4. Modificar mail"<<endl;
    cout << "0. Cancelar"<<endl;
    cout << "Seleccione una opcion: "<<endl;
    cin >> opcion;
    cout << endl;

    switch(opcion)
    {
    case 1:
    {
        char nuevaDescripcion[100];
        cout << "Ingrese nueva descripcion: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.getline(nuevaDescripcion, sizeof(nuevaDescripcion));
        OS.setDescripcion(nuevaDescripcion);
        break;
    }
    case 2:
    {
        float nuevoDescuento;
        cout<<"Ingrese nuevo valor de Descuento: ";
        cin>>nuevoDescuento;
        OS.setDescuento(nuevoDescuento);
        break;
    }
    case 3:
    {
        char nuevoTelefono[12];
        cout<<"Ingrese nuevo Telefono: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.getline(nuevoTelefono, sizeof(nuevoTelefono));
        OS.setTelefono(nuevoTelefono);
        break;
    }

    case 4:
    {
        char nuevoMail[30];
        cout<<"Ingrese nuevo Mail: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.getline(nuevoMail, sizeof(nuevoMail));
        OS.setMail(nuevoMail);
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

    if(archi.modificarObraSocial(OS,pos))
    {
        cout<<"La Obra Social se modifico de manera correcta"<<endl;
    }
    else
    {
        cout<<"Error al modificar la obra social.";
    }
    system("pause");
}

void ObrasSocialesManager::baja() {
    int idBuscado;
    cout << "Ingrese el ID de la Obra Social a buscar: ";
    cin >> idBuscado;

    ArchivoObrasSociales arc("obrassociales.dat");
    int pos = arc.buscarPorId(idBuscado);

    if (pos < 0) {
        cout << "No existe el ID en el archivo." << endl;
        system("pause");
        return;
    }

    ObraSocial obj = arc.leerOS(pos);

    if (obj.getEliminado()) {
        cout << "La obra social ya esta dado de baja." << endl;
        system("pause");
        return;
    }
    cout << "\n--- Obra Social encontrada ---\n";
    imprimirOS(obj);
    cout << "Eliminado: " << (obj.getEliminado() ? "Si" : "No") << endl;
    cout << "==============================================" << endl;

    char opcion;
    cout << "Esta seguro que desea dar de baja la obra social? (S/N): ";
    cin >> opcion;

    if (opcion != 'S' && opcion!='s') {
        cout << "Operacion cancelada." << endl;
        system("pause");
        return;
    }

    obj.setEliminado(true);
    arc.modificarObraSocial(obj, pos);

    cout << "La Obra Social fue dada de baja." << endl;
    system("pause");
}

void imprimirOS(const ObraSocial& o)
{
    cout << "Id: " << o.getId() << endl;
    cout << "Descripcion: " << o.getDescripcion() << endl;
    cout << "Descuento: " << o.getDescuento() << "%" << endl;
    cout << "Telefono: " << o.getTelefono() << endl;
    cout << "Mail: " << o.getMail() << endl;
}
