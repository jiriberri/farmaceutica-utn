#include <iostream>
#include <limits>
#include "ClientesManager.h"
#include "Cliente.h"
#include "ArchivoClientes.h"
#include "ArchivoObrasSociales.h"

using namespace std;

void ClientesManager::alta()
{
    int cuil, ob;
    char nom[20] {}, ape[20] {}, dom[50], mail[30], tel[12];
    ArchivoClientes arch("clientes.dat");

    cout << "Ingrese datos de cliente" << endl;
    cout << "CUIL: ";
    cin >> cuil;

    if (arch.existe() && arch.buscarPorCUIL(cuil) != -1)
    {
        cout << endl << "EL CUIL ingresado ya esta agregado" << endl;
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

    if (pos < 0)
    {
        cout << "Cliente no encontrado." << endl;
        system("pause");
        return;
    }


    Cliente c = archi.leerClientes(pos);

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

    system("pause");
}

void ClientesManager::modificar(){
int cuilBuscado;
cout<<"Ingrese el Cuil del cliente que quiera modificar: "<<endl;
cin>> cuilBuscado;

ArchivoClientes archi("clientes.dat");

int pos=archi.buscarPorCUIL(cuilBuscado);

if(pos<0){

    cout << "Cliente no encontrado." << endl;
      return;

}
Cliente c;
c=archi.leerClientes(pos);

int opcion;
        cout << "\n--- Cliente encontrado ---\n";
        cout<<"-----------------------------------------------"<<endl;
        cout << "CUIL: " << c.getCuil() << endl;
        cout << "Nombre: " << c.getNombre() << endl;
        cout << "Apellido: " << c.getApellido() << endl;
        cout << "Obra Social: " << c.getIdObraSocial() << endl;
        cout << "Domicilio: " << c.getDomicilio() << endl;
        cout << "Mail: " << c.getMail() << endl;
        cout << "Telefono: " << c.getTelefono() << endl;
        cout << "Eliminado: " << (c.getEliminado() ? "Sí" : "No") << endl;
        cout << "---------------------------------------------" << endl;




    cout << "1. Modificar domicilio"<<endl;
    cout << "2. Modificar mail"<<endl;
    cout << "3. Modificar telefono"<<endl;
    cout<<  "4. Modificar ID Obra Social"<<endl;
    cout << "0. Cancelar"<<endl;
    cout << "Seleccione una opcion: "<<endl;
    cin >> opcion;


switch(opcion){

case 1:{ char nuevoDomicilio[50];
         cout<<"Ingrese nuevo Domicilio"<<endl;
         cin>>nuevoDomicilio;
         c.setDomicilio(nuevoDomicilio);
         break;
}

case 2:{
      char nuevoMail[30];
      cout<<"Ingrese nuevo mail: "<<endl;
      cin>>nuevoMail;
      c.setMail(nuevoMail);
      break;
}
case 3: {
            char nuevoTelefono[12];
            cout << "Ingrese nuevo teléfono: "<<endl;
            cin>>nuevoTelefono;
            c.setTelefono(nuevoTelefono);
            break;

}

 case 4:{
            int nuevoIdObra;
            cout << "Ingrese el nuevo ID de la obra social: ";
            cin >> nuevoIdObra;

            // Validar si existe esa obra social
            ArchivoObrasSociales archOS("obrassociales.dat");
            int posOS = archOS.buscarPorId(nuevoIdObra);

            if(posOS < 0){
                cout << "La obra social con ese ID no existe." << endl;
                system("pause");
                return;
            }

            c.setIdObraSocial(nuevoIdObra);
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

if(archi.modificarCliente(c,pos)){

    cout<<"El Cliente se modifico de manera correcta"<<endl;

} else{

   cout<<"Error al modificar el cliente.";
}

system("pause");

}




void ClientesManager::baja(){
int cuilBuscado;
    cout << "Ingrese el CUIL del cliente a buscar: ";
    cin >> cuilBuscado;


}

