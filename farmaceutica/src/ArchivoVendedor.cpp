#include "ArchivoVendedor.h"
#include <iostream>

using namespace std;

ArchivoVendedor::ArchivoVendedor(std::string nombreArchivo)
{
    _nombreArchivo = nombreArchivo;
}

bool ArchivoVendedor::guardarVendedor(Vendedor reg)
{
    FILE* p = fopen(_nombreArchivo.c_str(), "ab");
    if (p == NULL)
    {
        cout << "Error, archivo no encontrado" << endl;
        return false;
    }

    fwrite(&reg, sizeof reg, 1, p);
    fclose(p);

    return true;
}

int ArchivoVendedor::cantidadRegistros()
{
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");

    if (p == NULL)
    {
        return 0;
    }

    fseek(p, 0, SEEK_END);
    int cantidad = ftell(p) / sizeof(Vendedor);
    fclose(p);

    return cantidad;
}

Vendedor ArchivoVendedor::leerVendedor(int pos)
{
    FILE *p = fopen(_nombreArchivo.c_str(), "rb");

    if (p == nullptr)
    {
        return Vendedor();
    }

    Vendedor v; // ahora es válido gracias a los valores por defecto

    fseek(p, pos * sizeof v, SEEK_SET);
    fread(&v, sizeof v, 1, p);
    fclose(p);

    return v;
}

bool ArchivoVendedor::modificarVendedor(Vendedor obj, int pos)
{
    FILE *p = fopen(_nombreArchivo.c_str(), "rb+");
    if (p == nullptr) return false;

    fseek(p, pos * sizeof obj, SEEK_SET);

    bool escribio = fwrite(&obj, sizeof obj, 1, p);

    fclose(p);
    return escribio;
}

int ArchivoVendedor::buscarPorID(long long IDBuscado)
{
    int total = cantidadRegistros();

    for (int i = 0; i < total; i++)
    {
        Vendedor v = leerVendedor(i);
        if (v.getId() == IDBuscado)
        {
            return i;
        }
    }

    return -1;
}

bool ArchivoVendedor::existe() const
{
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");

    if (p == NULL) return false;

    fclose(p);
    return true;
}

bool ArchivoVendedor::checkEliminado(int pos) const
{
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");
    if (p == nullptr) return false;

    Vendedor v;

    fseek(p, pos * sizeof v, SEEK_SET);
    fread(&v, sizeof v, 1, p);
    fclose(p);

    return v.getEliminado();
}

bool ArchivoVendedor::reactivarEmpleado(int pos)
{
    Vendedor v = leerVendedor(pos);
    v.setEliminado(false);
    return modificarVendedor(v, pos);
}
