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


void ObrasSocialesManager::modificar(){
int idBuscado;
cout<<"Ingrese el Cuil del cliente que quiera modificar: "<<endl;
cin>> idBuscado;

ArchivoObrasSociales archi("obrassociales.dat");

int pos=archi.buscarPorId(idBuscado);

if(pos<0){

    cout << "ID no encontrado." << endl;
      return;

}
ObraSocial OS;
OS=archi.leerOS(pos);
int opcion;

    cout << "\n--- ID encontrado ---\n";
    cout << "1. Modificar descripcion"<<endl;
    cout << "2. Modificar descuento"<<endl;
    cout << "3. Modificar telefono"<<endl;
    cout << "4. Modificar mail"<<endl;
    cout << "0. Cancelar"<<endl;
    cout << "Seleccione una opcion: "<<endl;
    cin >> opcion;


switch(opcion){

case 1:{ char nuevaDescripcion[100];
         cout<<"Ingrese nuevo Domicilio"<<endl;
         cin>>nuevaDescripcion;
         OS.setDescripcion(nuevaDescripcion);
         break;
}

case 2:{ float nuevoDescuento;
         cout<<"Ingrese nuevo valor de Descuento"<<endl;
         cin>>nuevoDescuento;
         OS.setDescuento(nuevoDescuento);
         break;
}
case 3:{ char nuevoTelefono[12];
         cout<<"Ingrese nuevo Telefono"<<endl;
         cin>>nuevoTelefono;
         OS.setTelefono(nuevoTelefono);
         break;
}

case 4:{ char nuevoMail[30];
         cout<<"Ingrese nuevo Mail"<<endl;
         cin>>nuevoMail;
         OS.setMail(nuevoMail);
         break;

}

case 0:
            cout << "Operación cancelada." << endl;
            system("pause");
            return;
        default:
            cout << "Opción inválida." << endl;
            system("pause");
            return;

}

if(archi.modificarObraSocial(OS,pos)){

    cout<<"La Obra Social se modifico de manera correcta"<<endl;

} else{

   cout<<"Error al modificar el cliente.";
}

system("pause");







}
