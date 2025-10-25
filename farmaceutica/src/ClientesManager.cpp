#include "ClientesManager.h"
#include "Cliente.h"
#include <iostream>
#include <limits>

using namespace std;

void ClientesManager::alta(){
    int cuil, ob;
    char nom[20]{}, ape[20]{}, dom[50], mail[30], tel[12];

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

    cout << "Domicilio: ";
    cin.getline(dom, sizeof(dom));

    cout << "Mail: ";
    cin.getline(mail, sizeof(mail));

    cout << "Telefono: ";
    cin.getline(tel, sizeof(tel));
    cout << endl;

    Cliente c(cuil, nom, ape, ob, dom, mail, tel, false);


    //momentaneo para ver que la carga se haya hecho bien
    cout << c.getCuil() << endl;
    cout << c.getNombre() << endl;
    cout << c.getApellido() << endl;
    cout << c.getIdObraSocial() << endl;
    cout << c.getDomicilio() << endl;
    cout << c.getMail() << endl;
    cout << c.getTelefono() << endl;
    cout << c.getEliminado() << endl;

    system("pause");
}
