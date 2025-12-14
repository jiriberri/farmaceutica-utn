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
#include "ArchivoVendedor.h"
#include "Vendedor.h"
using namespace std;

bool checkCliente(long long);
bool checkVendedor(long long);
bool checkProducto(int);
bool checkStock(int, int);
bool restarStock(int, int);
float obtenerPrecio(int);
float obtenerDescuento(long long, int);
void mostrarDescripcionProducto(int);
void imprimirFactura(const Venta &venta);
void mostrarNombreCliente(int);
void mostrarNombreVendedor(int);


void VentasManager::alta()
{
    long long cuil, idVendedor , cantVenta = 0, idPr, cantxPr;
    char med[20]{};

    ArchivoDetalleVenta archDv("detalleventa.dat");
    ArchivoVentas archVen("venta.dat");
    ArchivoProductos archPr("productos.dat");
    ArchivoClientes archCli("clientes.dat");
    ArchivoVendedor archVendedor("Vendedores.dat");

    cout << "Ingrese datos de la venta" << endl;
    int numFactura= archVen.cantidadRegistros() + 1;
    cout << "Venta #" << numFactura << endl;

    cout << "ID Vendedor: ";
    cin >> idVendedor;
    if (!checkVendedor(idVendedor)) return;

    cout << "Cuil Cliente: ";
    cin >> cuil;
    if (!checkCliente(cuil)) return;

    Fecha fecha;
    Fecha obj = fecha.fechaActual();
    cout << "Fecha: " << obj.getDia() << "/" << obj.getMes() << "/" << obj.getAnio() << endl; //tomar fecha actual
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Medio de pago: ";
    cin.getline(med, sizeof(med));

    cout << endl;

    DetalleVenta* detalles = nullptr;
    float total = 0;
    char opc = 'S';

    while (opc == 'S' || opc == 's')
    {
        cout << "Item #" << cantVenta + 1 << endl;

        cout << "idProducto: ";
        cin >> idPr;
        if (!checkProducto(idPr));
        else
        {
            cout << "Cantidad: ";
            cin >> cantxPr;

            while (cantxPr <= 0){
            cout << "Cantidad invalida. Ingrese un numero mayor a 0: ";
            cin >> cantxPr;
            }

            if (!checkStock(cantxPr, idPr));
            else
            {
                float precio = obtenerPrecio(idPr);
                cout << "Precio individual: $" << precio << endl;

                float desc = obtenerDescuento(cuil, idPr);
                if(desc != 1.0f)
                {
                    cout << "Descuento: " << (1.0f - desc) * 100 << "%" << endl;
                }

                float subtotal = precio * cantxPr * desc;
                cout << "Subtotal: $" << subtotal << endl << endl;

                total += subtotal;


                DetalleVenta dv;
                dv.setNumFactura(numFactura);
                dv.setIdProducto(idPr);
                dv.setCantidad(cantxPr);
                dv.setPrecio(precio);
                dv.setSubtotal(subtotal);
                dv.setEliminado(false);


                DetalleVenta* aux = new DetalleVenta[cantVenta + 1];

                for (int i = 0; i < cantVenta; i++) {
                    aux[i] = detalles[i];
                }

                aux[cantVenta] = dv;

                delete[] detalles;
                detalles = aux;
                cantVenta++;
            }
        }

        cout << "Agregar otro producto? (S/N): ";
        cin >> opc;
        cout << endl;
    }


    if(cantVenta <= 0)
    {
        cout << "No hay productos a cargar. Venta cancelada." << endl;
        delete[] detalles;
        system("pause");
        return;
    }

    cout << "Total a pagar: $"<< total << endl << endl;

    char conf;
    cout << "Confirmar venta? (S/N): ";
    cin >> conf;
    cout << endl;

    if(conf != 'S' && conf != 's')
    {
        cout << "Venta cancelada. No se guardo nada." << endl;
        delete[] detalles;
        system("pause");
        return;
    }

    // Obtener idObraSocial
    int posCli = archCli.buscarPorCUIL(cuil);
    Cliente cli = archCli.leerClientes(posCli);
    int idObraSocial = cli.getIdObraSocial();

    Venta nuevaVenta(numFactura, cuil, idVendedor, idObraSocial, obj, med, total, false);
    archVen.guardarVenta(nuevaVenta);

    // Guardar detalles y restar stock
    for(int i = 0; i < cantVenta; i++){
        archDv.guardarDetalleVenta(detalles[i]);
        restarStock(detalles[i].getCantidad(), detalles[i].getIdProducto());
    }

    cout<<"Venta registrada correctamente."<<endl;

    delete[] detalles;
    system("pause");
}

void VentasManager::mostrar()
{
    ArchivoVentas archVen("venta.dat");


    if(!archVen.existe()){
        cout<<"No hay ventas cargadas."<<endl;
        system("pause");
        return;
    }

    int totalVentas = archVen.cantidadRegistros();

    if (totalVentas <= 0) {
        cout << "No hay ventas para mostrar." << endl;
        system("pause");
        return;
    }

    for(int i=0; i < totalVentas;i++)
    {
        Venta ven = archVen.leerVenta(i);
        if (!ven.getEliminado())
        {
            imprimirFactura(ven);
            cout << "------------------------------------------------------------" << endl << endl;
        }
    }

    system("pause");
}

void VentasManager::buscarxId()
{
    int idBuscado;
    cout << "Ingrese # de factura a buscar: ";
    cin >> idBuscado;

    ArchivoVentas archVen("venta.dat");

    int posVen = archVen.buscarPorNumFactura(idBuscado);

    if (posVen < 0)
    {
        cout << "\n Factura no encontrada. \n" << endl;
        system("pause");
        return;
    }


    Venta venta = archVen.leerVenta(posVen);

    if (venta.getEliminado()) {
        cout << "\nLa factura ya esta dada de baja. \n" << endl;
        system("pause");
        return;
    }

    cout << "\n--- Factura encontrada ---\n";
    imprimirFactura(venta);
    cout << "------------------------------------------------------------" << endl << endl;

    system("pause");
}

void VentasManager::baja()
{
    int idBuscado;
    cout << "Ingrese # de factura a eliminar: ";
    cin >> idBuscado;

    ArchivoVentas archVen("venta.dat");
    ArchivoDetalleVenta archDv("detalleventa.dat");

    int posVen = archVen.buscarPorNumFactura(idBuscado);

    if (posVen < 0)
    {
        cout << "Factura no encontrada." << endl;
        system("pause");
        return;
    }

    Venta venta = archVen.leerVenta(posVen);

    if (venta.getEliminado()) {
        cout << "La factura ya esta dada de baja." << endl;
        system("pause");
        return;
    }

    cout << "\n--- Factura encontrada ---\n";
    imprimirFactura(venta);
    cout << "Eliminado: " << (venta.getEliminado() ? "Si" : "No") << endl;
    cout << "------------------------------------------------------------" << endl << endl;

    char opcion;
    cout << "Esta seguro que desea dar de baja esta venta? (S/N): ";
    cin >> opcion;

    if (opcion != 'S' && opcion!='s') {
        cout << "\nOperacion cancelada.\n" << endl;
        system("pause");
        return;
    }

    // Marca cabecera como eliminada
    venta.setEliminado(true);
    archVen.modificarVenta(venta, posVen);

    // Marca detalles como eliminados
    int totalDv = archDv.cantidadRegistros();

    for(int i = 0; i < totalDv; i++)
    {
        DetalleVenta det = archDv.leerDetalleVenta(i);

        if(det.getNumFactura() == idBuscado)
        {
            det.setEliminado(true);
            archDv.modificarDetalleVenta(det, i);
        }
    }

    cout << "\nVenta y detalles dados de baja correctamente. \n" << endl;
    system("pause");
}

bool checkCliente(long long cuil)
{
    ArchivoClientes arch("clientes.dat");

    int pos = arch.buscarPorCUIL(cuil);

    if (pos == -1)
    {
        cout << "Cuil no encontrado" << endl;
        system("pause");
        return false;
    }

    Cliente cli = arch.leerClientes(pos);

    if (cli.getEliminado() == true)
    {
        cout << "El cliente con el CUIL ingresado se encuentra eliminado" << endl;
        system("pause");
        return false;
    }

    return true;
}

bool checkVendedor(long long id)
{
    ArchivoVendedor arch("Vendedores.dat");

    int pos = arch.buscarPorID(id);

    if (pos == -1){

        cout<<"ID de vendedor no encontrado"<<endl;
        system("pause");
        return false;
    }

    Vendedor vend = arch.leerVendedor(pos);

    if (vend.getEliminado() == true)
    {
        cout << "El vendedor con el ID ingresado se encuentra eliminado" << endl;
        system("pause");
        return false;
    }

    return true;
}



bool checkProducto(int id)
{
    ArchivoProductos arch("productos.dat");

    int pos = arch.buscarPorId(id);

    if (pos == -1)
    {
        cout << "Id no encontrado" << endl;
        system("pause");
        cout << endl;
        return false;
    }

    Producto prod = arch.leerPr(pos);

    if (prod.getEliminado() == true)
    {
        cout << "El producto con el ID ingresado se encuentra eliminado\n" << endl;
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
        cout << endl;
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

void mostrarDescripcionProducto(int idProd)
{
    ArchivoProductos arch("productos.dat");
    int pos = arch.buscarPorId(idProd);

    Producto p = arch.leerPr(pos);
    cout << p.getDescripcion();
}

void mostrarNombreVendedor(int idVendedor){
    ArchivoVendedor arch("Vendedores.dat");
    int pos = arch.buscarPorID(idVendedor);

    Vendedor v = arch.leerVendedor(pos);
    cout << v.getNombre() << endl;
}


void mostrarNombreCliente(int cuil){
    ArchivoClientes arch("clientes.dat");
    int pos = arch.buscarPorCUIL(cuil);

    Cliente c = arch.leerClientes(pos);
    cout << c.getNombre() << endl;
}

void imprimirFactura(const Venta &venta)
{
    ArchivoDetalleVenta archDv("detalleventa.dat");

    cout << "Factura #" << venta.getNumFacturas() << endl;
    cout<<"Vendedor: "<<venta.getIdVendedor()<<endl;

    cout<<"Nombre Vendedor: ";mostrarNombreVendedor(venta.getIdVendedor());

    cout << "CUIL: " << venta.getCuilCliente() << endl;

    cout << "Nombre: ";
    mostrarNombreCliente(venta.getCuilCliente());

    Fecha f = venta.getFecha();
    cout << "Fecha: " << f.getDia() << "/" << f.getMes() << "/" << f.getAnio() << endl;

    cout << "Medio Pago: " << venta.getMedioDePago() << endl;
    cout << "Estado: " << (venta.getEliminado() ? "ANULADA" : "ACTIVA") << endl << endl;

    cout << "Detalles:" << endl;

    int totalDv = archDv.cantidadRegistros();

    for (int i = 0; i < totalDv; i++)
    {
        DetalleVenta detV = archDv.leerDetalleVenta(i);

        if (detV.getNumFactura() == venta.getNumFacturas())
        {
            cout << "   - Producto ";
            mostrarDescripcionProducto(detV.getIdProducto());
            cout << " (ID: " << detV.getIdProducto() << ")"
                 << " | Cant: " << detV.getCantidad()
                 << " | Precio: $" << detV.getPrecio()
                 << " | Subtotal: $" << detV.getSubtotal()
                 << endl;
        }
    }

    cout << "Total factura: $" << venta.getImporte() << endl;
}
