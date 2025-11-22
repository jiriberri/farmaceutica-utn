#include <iostream>
#include <limits>
#include "VentasManager.h"
#include "ArchivoClientes.h"
#include "ArchivoProductos.h"
#include "Producto.h"
#include "ArchivoObrasSociales.h"
#include "ObraSocial.h"
#include "Cliente.h"

using namespace std;

bool checkCliente(long long);
bool checkProducto(int);
bool checkStock(int, int);
float obtenerPrecio(int);
float obtenerDescuento(long long, int);

void VentasManager::alta()
{
    long long cuil , cantVenta = 0, idPr, cantxPr;
    float precio = 0, total = 0;
    char med[20]{};

    ArchivoProductos archPr("productos.dat");

    cout << "Ingrese datos de la venta" << endl;
    cout << "Venta #" << 1 << endl; //cambiar numero por uno autoincremental

    cout << "Cuil Cliente: ";
    cin >> cuil;
    if (!checkCliente(cuil)) return;

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
        if (!checkProducto(idPr)) return;

        cout << "Cantidad: ";
        cin >> cantxPr;

        if (!checkStock(cantxPr, idPr)) return;

        precio = obtenerPrecio(idPr);
        cout << "Precio individual: " << precio << endl;

        float desc = obtenerDescuento(cuil, idPr);
        if(desc != 1.0f)
        {
            cout << "Descuento: " << (1.0f - desc) * 100 << "%" << endl;
        }

        cout << "Subtotal: " << (precio * cantxPr * desc) << endl;

        total += (precio * cantxPr * desc);

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

bool checkCliente(long long cuil)
{
    ArchivoClientes arch("clientes.dat");

    if (arch.buscarPorCUIL(cuil) == -1)
    {
        cout << "Cuil no encontrado" << endl;
        system("pause");
        return false;
    }
    return true;
}

bool checkProducto(int id)
{
    ArchivoProductos arch("productos.dat");

    if (arch.buscarPorId(id) == -1)
    {
        cout << "Id no encontrado" << endl;
        system("pause");
        return false;
    }
    return true;
}

bool checkStock(int cantxPr, int id)
{
    ArchivoProductos archPr("productos.dat");
    Producto prod;

    int pos = archPr.buscarPorId(id);

    prod = archPr.leerPr(pos);

    int stock = prod.getStock();

    if((stock - cantxPr) < 0)
    {
        cout << endl;
        cout << "La cantidad a vender supera el stock actual" << endl;
        cout << "Stock actual: " << stock << endl;
        system("pause");
        return false;
    }
    else
    {
        prod.setStock(stock - cantxPr);
        bool resModif = archPr.modificarPr(prod, pos);

        if(resModif) return true;
        else
        {
            cout << "Error al actualizar el stock" << endl;
            system("pause");
            return false;
        }
    }
}

float obtenerPrecio(int id)
{
    Producto prod;
    ArchivoProductos arch("productos.dat");

    int pos = arch.buscarPorId(id);

    prod = arch.leerPr(pos);

    return prod.getPrecioUnitario();
}

float obtenerDescuento(long long cuil, int id)
{
    Producto prod;
    ArchivoProductos archPr("productos.dat");

    int posPr = archPr.buscarPorId(id);

    prod = archPr.leerPr(posPr);

    if (!prod.getAplicaDescuento()) {
        return 1.0f;
    }

    Cliente cli;
    ObraSocial obSoc;
    ArchivoClientes archCli("clientes.dat");
    ArchivoObrasSociales archOb("obrassociales.dat");

    int posCli = archCli.buscarPorCUIL(cuil);
    cli = archCli.leerClientes(posCli);

    int posOb = archOb.buscarPorId(cli.getIdObraSocial());
    obSoc = archOb.leerOS(posOb);

    int porc = obSoc.getDescuento(); // ej: 10
    float porcFinal = 1.0f - (porc / 100.0f); // 1 - 0.10 = 0.9

    return porcFinal;
}
