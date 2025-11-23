#include <iostream>
#include <limits>
#include "VentasManager.h"
#include "ArchivoClientes.h"
#include "ArchivoProductos.h"
#include "Producto.h"
#include "ArchivoObrasSociales.h"
#include "ObraSocial.h"
#include "Cliente.h"
#include "Fecha.h"
#include "DetalleVenta.h"
#include "Venta.h"
#include "ArchivoDetalleVenta.h"
#include "ArchivoVentas.h"

using namespace std;

bool checkCliente(long long);
bool checkProducto(int);
bool checkStock(int, int);
bool restarStock(int, int);
float obtenerPrecio(int);
float obtenerDescuento(long long, int);

void VentasManager::alta()
{
    long long cuil , cantVenta = 0, idPr, cantxPr;
    char med[20]{};

    ArchivoDetalleVenta archDv("detalleventa.dat");
    ArchivoVentas archVen("venta.dat");
    ArchivoProductos archPr("productos.dat");
    ArchivoClientes archCli("clientes.dat");

    cout << "Ingrese datos de la venta" << endl;
    int numFactura= archVen.cantidadRegistros()+1; ///Numero de factura autoincrementable
    cout << "Venta #" << numFactura << endl; //cambiar numero por uno autoincremental

    cout << "Cuil Cliente: ";
    cin >> cuil;
    if (!checkCliente(cuil)) return;



    Fecha fecha;
    Fecha obj = fecha.fechaActual();
    cout << "Fecha: " << obj.getDia() << "/" << obj.getMes() << "/" << obj.getAnio() << endl; //tomar fecha actual
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Medio de pago: ";
    cin.getline(med, sizeof(med));

    cout << "Cantidad de productos diferentes a vender: ";
    cin >> cantVenta;

    cout << endl;

    DetalleVenta* detalles = new DetalleVenta[cantVenta];

    float total = 0;

    for(int i = 0; i < cantVenta ; i++) {
        cout << "Item #" << i+1 << endl;

        cout << "idProducto: ";
        cin >> idPr;
        if (!checkProducto(idPr)) {
            delete[] detalles;
            return;
        }



        cout << "Cantidad: ";
        cin >> cantxPr;
        if (!checkStock(cantxPr, idPr)) {
            delete[] detalles;
            return;
        }

        float precio = obtenerPrecio(idPr);
        cout << "Precio individual: " << precio << endl;

        float desc = obtenerDescuento(cuil, idPr);
        if(desc != 1.0f)
        {
            cout << "Descuento: " << (1.0f - desc) * 100 << "%" << endl;
        }

        float subtotal = precio * cantxPr * desc;
        cout << "Subtotal: " << subtotal << endl;

        total += subtotal;

        cout << endl;

        detalles[i].setNumFactura(numFactura);
        detalles[i].setIdProducto(idPr);
        detalles[i].setCantidad(cantxPr);
        detalles[i].setPrecio(precio);
        detalles[i].setSubtotal(subtotal);
        detalles[i].setEliminado(false);
    }


    if(cantVenta <= 0)
    {
        cout << "No hay productos a cargar." << endl;
    } else {
        cout << "Total a pagar: "<< total << endl;
    }


    char conf;
    cout << "Confirmar venta? (S/N): ";
    cin >> conf;

    if(conf != 'S' && conf != 's')
    {
        cout << "Venta cancelada. No se guardo nada." << endl;
        delete[] detalles;
        system("pause");
        return;
    }


    /// OBTENER ID OBRA SOCIAL
    int posCli = archCli.buscarPorCUIL(cuil);
    Cliente cli = archCli.leerClientes(posCli);
    int idObraSocial = cli.getIdObraSocial();



Venta nuevaVenta(numFactura,cuil,idObraSocial,obj,med,total,false);

archVen.guardarVenta(nuevaVenta);


///Gaurdar detalles y restar stock
  for(int i=0;i<cantVenta;i++){
        archDv.guardarDetalleVenta(detalles[i]);

    restarStock(detalles[i].getCantidad(),detalles[i].getIdProducto());
}

cout<<"Venta registrada correctamente."<<endl;

    delete[] detalles;
    system("pause");

}


void VentasManager::mostrar(){

ArchivoVentas archVen("venta.dat");
ArchivoDetalleVenta archDv("detalleventa.dat");
ArchivoClientes archcli("Cliente.dat");

if(!archVen.existe()){

    cout<<"No hay ventas cargadas."<<endl;
    system("pause");
    return;
}

int totalVentas=archVen.cantidadRegistros();

for(int i=0; i<totalVentas;i++){

    Venta Ven=archVen.leerVenta(i);

    cout<<"Factura #"<<Ven.getNumFacturas()<<endl;
    cout<<"CUIL: "<<Ven.getCuilCliente()<<endl;

    Fecha f=Ven.getFecha();

    cout << "Fecha: " << f.getDia() << "/" << f.getMes() << "/" << f.getAnio() << endl;

    cout<<"Medio Pago: "<< Ven.getMedioDePago()<<endl;

    cout <<"Estado: " <<(Ven.getEliminado()?"ANULADA" : "ACTIVA")<<endl;

    int totalDv = archDv.Cantidadregistros();

    for(int a=0; a<totalDv;a++){

        DetalleVenta detV=archDv.leerDetalleVenta(a);

        if(detV.getNumFactura()==Ven.getNumFacturas()){

            cout << "   - Producto " << detV.getIdProducto()
                 << " | Cant: " << detV.getCantidad()
                 << " | Precio: " << detV.getPrecio()
                 << " | Subtotal: " << detV.getSubtotal()
                     << endl;

        }

      }


    cout << "------------------------------------------------------------" << endl;

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
    else return true;

}

bool restarStock(int cantxPr, int id)
{
    ArchivoProductos archPr("productos.dat");
    Producto prod;

    int pos = archPr.buscarPorId(id);

    prod = archPr.leerPr(pos);

    int stock = prod.getStock();

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
