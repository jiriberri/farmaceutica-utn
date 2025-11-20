#include <iostream>
#include <limits>
#include "VentasManager.h"

using namespace std;

void VentasManager::alta()
{
    int cuil , cantVenta = 0, idPr, cantxPr;
    float precio = 1000, total = 0;
    char med[20]{};

    cout << "Ingrese datos de la venta" << endl;
    cout << "Venta #" << 1 << endl; //cambiar numero por uno autoincremental

    cout << "Cuil Cliente: ";
    cin >> cuil;

    cout << "Fecha: " << "20/11/2025" << endl; //tomar fecha actual
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Medio de pago: ";
    cin.getline(med, sizeof(med));

    cout << "Cantidad de productos diferentes a vender: ";
    cin >> cantVenta;

    cout << endl;

    for(int i = 0; i < cantVenta ; i++) {
        cout << "Item #" << i+1 << endl;

        cout << "idProducto: ";
        cin >> idPr;
        //chequear si el producto existe

        cout << "Cantidad: ";
        cin >> cantxPr;

        cout << "Precio individual: " << precio << endl; //obtener precio del archivo y borrar variable seteada arriba de todo

        cout << "Subtotal: " << precio * cantxPr << endl;

        total += (precio * cantxPr);

        cout << endl;
    }

    if(cantVenta == 0)
    {
        cout << "No hay productos a cargar." << endl;
    } else {
        cout << "Total a pagar: "<< total << endl;
    }


    system("pause");
}
