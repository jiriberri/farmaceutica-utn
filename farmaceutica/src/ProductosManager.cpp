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

        cout << "Id: " << prod.getId() << endl;
        cout << "Descripcion: " << prod.getDescripcion() << endl;
        cout << "Stock: " << prod.getStock() << endl;
        cout << "Telefono: " << prod.getPrecioUnitario() << endl;
        cout << "Eliminado: " << (prod.getEliminado() ? "Sí" : "No") << endl;
        cout << "==============================================" << endl;
    }

    delete[] pr;
    system("pause");
}
