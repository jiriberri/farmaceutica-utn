#include "ObrasSocialesManager.h"
#include "ObraSocial.h"
#include "ArchivoObrasSociales.h"
#include <iostream>
#include <limits>

using namespace std;

void ObrasSocialesManager::alta()
{
    int id;
    char d[100]{}, t[12]{}, m[30]{};
    float desc;
    ArchivoObrasSociales arch("obrassociales.dat");

    cout << "Ingrese datos de la obra social" << endl;
    cout << "Id: ";
    cin >> id;


    if (arch.existe() && arch.buscarPorId(id) != -1)
    {
        cout << endl << "EL Id ingresado ya esta agregado" << endl;
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

        cout << "Id: " << o.getId() << endl;
        cout << "Descripcion: " << o.getDescripcion() << endl;
        cout << "Descuento: " << o.getDescuento() << endl;
        cout << "Telefono: " << o.getTelefono() << endl;
        cout << "Mail: " << o.getMail() << endl;
        cout << "Eliminado: " << (o.getEliminado() ? "Sí" : "No") << endl;
        cout << "==============================================" << endl;
    }

    delete[] os;
    system("pause");
}
