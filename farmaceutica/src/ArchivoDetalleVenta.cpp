#include "ArchivoDetalleVenta.h"
#include <iostream>
using namespace std;

ArchivoDetalleVenta::ArchivoDetalleVenta(string nombreArchivo)
{
    _nombreArchivo = nombreArchivo;
}

bool ArchivoDetalleVenta::guardarDetalleVenta(DetalleVenta reg)
{
    FILE* p = fopen(_nombreArchivo.c_str(), "ab");
    if (p == NULL)
    {
        cout << "Error, archivo no encontrado" << endl;
        return 0;
    }

    fwrite(&reg, sizeof(DetalleVenta), 1, p);
    fclose(p);

    return true;
}

int ArchivoDetalleVenta::Cantidadregistros()
{
    FILE* p= fopen(_nombreArchivo.c_str(),"rb");

    if(p == NULL)
    {
        cout << "Error, archivo no encontrado" << endl;
        return 0;
    }

    fseek(p,0,SEEK_END);

    int cantidad = ftell(p)/sizeof(DetalleVenta);

    fclose(p);

    return cantidad;
}
DetalleVenta ArchivoDetalleVenta::leerDetalleVenta(int pos)
{
    FILE *p = fopen(_nombreArchivo.c_str(),"rb");

    if(p==nullptr)
    {
        return DetalleVenta();
    }

    DetalleVenta Dv;

    fseek(p, sizeof(DetalleVenta) * pos, SEEK_SET);
    fread(&Dv, sizeof(DetalleVenta), 1, p);
    fclose(p);

    return Dv;
}
bool ArchivoDetalleVenta::modificarDetalleVenta(DetalleVenta obj, int pos)
{
    FILE* p = fopen(_nombreArchivo.c_str(), "rb+");
    if (p == NULL)
    {
        cout << "Error al abrir el archivo para modificar DetalleVenta." << endl;
        return false;
    }

    fseek(p, sizeof(DetalleVenta) * pos, SEEK_SET);
    bool escribio = fwrite(&obj, sizeof(DetalleVenta), 1, p);

    fclose(p);

    return escribio;
}

int ArchivoDetalleVenta::buscarPorNumFactura(int numFactura)
{
    int total = Cantidadregistros();

    for (int i = 0; i < total; i++)
    {
        DetalleVenta dv = leerDetalleVenta(i);
        if (dv.getNumFactura() == numFactura)
        {
            return i;
        }
    }

    return -1;
}
bool ArchivoDetalleVenta::existe() const
{
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");
    if (p == NULL) return false;

    fclose(p);
    return true;
}
