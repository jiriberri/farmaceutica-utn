#include "ProductosManager.h"
#include "Producto.h"
#include "ArchivoProductos.h"
#include <iostream>
#include <limits>

using namespace std;

void ProductosManager::alta()
{
    int id, s;
    char d[100]{};
    float p;
    ArchivoProductos arch("productos.dat");

    cout << "Ingrese datos del producto" << endl;
    cout << "Id: ";
    cin >> id;

    int pos = arch.buscarPorId(id);

    if (arch.existe() && pos != -1)
    {
        cout << endl << "EL Id ingresado ya esta agregado" << endl;

        if(arch.checkEliminado(pos))
        {
            char opcion;

            cout << endl << "Este producto esta eliminado" << endl;
            cout << "Desea reactivarlo? (S/N): ";
            cin >> opcion;
            cout << endl;

            if(opcion == 'S' || opcion == 's')
            {
                if (arch.reactivarPro(pos))
                {
                    cout << "El producto fue reactivado exitosamente" << endl;
                }
                else
                {
                    cout << "No se pudo reactivar el producto" << endl;
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

        cout << "Stock: ";
        cin >> s;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Precio Unitario: ";
        cin >> p;

        cout << endl;

        Producto pr(id, d, s, p, false);

        ArchivoProductos archi("productos.dat");

        if(archi.guardarPr(pr))
        {
            cout << "Producto guardado exitosamente" << endl;
        }
        else
        {
            cout << "Error al guardar el producto" << endl;
        }
    }

    system("pause");
}

void ProductosManager::mostrar()
{
    ArchivoProductos arch("productos.dat");

    if (!arch.existe()) {
        cout << "No hay productos para mostrar." << endl;
        system("pause");
        return;
    }

    int cantReg = arch.cantidadRegistros();

    if (cantReg <= 0) {
        cout << "No hay productos para mostrar." << endl;
        system("pause");
        return;
    }

    Producto* pr = new Producto[cantReg];

    for (int i = 0; i < cantReg; i++) {
        pr[i] = arch.leerPr(i);
    }

    for (int i = 0; i < cantReg - 1; i++) {
        for (int j = 0; j < cantReg - i - 1; j++) {
            if (pr[j].getId() > pr[j + 1].getId()) {
                Producto aux = pr[j];
                pr[j] = pr[j + 1];
                pr[j + 1] = aux;
            }
        }
    }

    for(int i = 0; i < cantReg; i++)
    {
        Producto prod = pr[i];

        if(!prod.getEliminado()){
            cout << "Id: " << prod.getId() << endl;
            cout << "Descripcion: " << prod.getDescripcion() << endl;
            cout << "Stock: " << prod.getStock() << endl;
            cout << "Telefono: " << prod.getPrecioUnitario() << endl;
            cout << "==============================================" << endl;
        }
    }

    delete[] pr;
    system("pause");
}


void ProductosManager::modificar()
{
    int idBuscado;
    cout<<"Ingrese el id del producto que quiera modificar: ";
    cin>> idBuscado;

    ArchivoProductos archi("productos.dat");

    int pos = archi.buscarPorId(idBuscado);

    if (pos < 0)
    {
        cout << "ID no encontrado." << endl;
        system("pause");
        return;
    }

    Producto prod;
    prod = archi.leerPr(pos);
    int opcion;

    cout << "\n--- Producto encontrado ---\n";
    cout << "-----------------------------------------------" << endl;
    cout << "ID: " << prod.getId() << endl;
    cout << "Descripcion: " << prod.getDescripcion() << endl;
    cout << "Stock: " << prod.getStock() << endl;
    cout << "Precio Unitario: " << prod.getPrecioUnitario() << endl;
    cout << "Eliminado: " << prod.getEliminado() << endl;
    cout << "-----------------------------------------------" << endl;

    cout << "1. Modificar descripcion" << endl;
    cout << "2. Modificar stock" << endl;
    cout << "3. Modificar precio" << endl;
    cout << "0. Cancelar" << endl;
    cout << "Seleccione una opcion: ";
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
        prod.setDescripcion(nuevaDescripcion);
        break;
    }
    case 2:
    {
        int nuevoStock;
        cout << "Ingrese nuevo stock: ";
        cin >> nuevoStock;
        prod.setStock(nuevoStock);
        break;
    }
    case 3:
    {
        float nuevoPrecio;
        cout << "Ingrese nuevo precio unitario: ";
        cin >> nuevoPrecio;
        prod.setPrecioUnitario(nuevoPrecio);
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

    if(archi.modificarPr(prod,pos))
    {
        cout << "El producto se modifico de manera correcta" << endl;
    }
    else
    {
        cout<<"Error al modificar el producto.";
    }
    system("pause");
}

void ProductosManager::baja() {
    int idBuscado;
    cout << "Ingrese el ID del producto a buscar: ";
    cin >> idBuscado;

    ArchivoProductos arc("productos.dat");
    int pos = arc.buscarPorId(idBuscado);

    if (pos < 0) {
        cout << "No existe el ID en el archivo." << endl;
        system("pause");
        return;
    }

    Producto obj = arc.leerPr(pos);

    if (obj.getEliminado()) {
        cout << "El producto ya esta dado de baja." << endl;
        system("pause");
        return;
    }
    cout << "\n--- Producto encontrado ---\n";
    cout << "ID: " << obj.getId() << endl;
    cout << "Descripcion: " << obj.getDescripcion() << endl;
    cout << "Stock: " << obj.getStock() << endl;
    cout << "Precio unitario: " << obj.getPrecioUnitario() << endl;
    cout << "-----------------------------" << endl;
    char opcion;
    cout << "Esta seguro que desea dar de baja el producto? (S/N): ";
    cin >> opcion;

    if (opcion != 'S' && opcion!='s') {
        cout << "Operacion cancelada." << endl;
        system("pause");
        return;
    }


    obj.setEliminado(true);
    arc.modificarPr(obj, pos);

    cout << "El producto fue dado de baja." << endl;
    system("pause");
}
