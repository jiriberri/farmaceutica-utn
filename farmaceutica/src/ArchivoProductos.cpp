#include "ArchivoProductos.h"
#include <iostream>
using namespace std;

ArchivoProductos::ArchivoProductos(string nombreArchivo)
{
    _nombreArchivo = nombreArchivo;
}

bool ArchivoProductos::guardarPr(Producto reg)
{
    FILE* p = fopen(_nombreArchivo.c_str(), "ab");
    if (p == NULL)
    {
        cout << "Error, archivo no encontrado 1." << endl;
        return 0;
    }

    fwrite(&reg, sizeof(Producto), 1, p);
    fclose(p);

    return true;
}

int ArchivoProductos::cantidadRegistros()
{
    FILE* p= fopen(_nombreArchivo.c_str(),"rb");

    if(p == NULL)
    {
        cout<<"Error, archivo no encontrado 2."<<endl;
    }

    fseek(p,0,SEEK_END);

    int cantidad = ftell(p)/sizeof(Producto);

    return cantidad;
}

Producto ArchivoProductos::leerPr(int pos)
{
    FILE *p = fopen(_nombreArchivo.c_str(),"rb");

    if(p==nullptr)
    {
        return Producto();
    }

    Producto pr;

    fseek(p, sizeof(Producto) * pos, SEEK_SET);
    fread(&pr, sizeof(Producto), 1, p);
    fclose(p);

    return pr;
}

int ArchivoProductos::buscarPorId(int id)
{
    int total = cantidadRegistros();

    for (int i = 0; i < total; i++)
    {
        Producto pr = leerPr(i);
        if(pr.getId() == id)
        {
            return i;
        }
    }
    return -1;
}

bool ArchivoProductos::modificarPr(Producto obj, int pos)
{
    FILE *p =fopen(_nombreArchivo.c_str(),"rb+");

    if(p==nullptr)
    {
        return false;
    }
    fseek(p, pos * sizeof obj, 0);
    bool escribio = fwrite(&obj,sizeof obj,1,p);
    fclose(p);
    return escribio;
}

bool ArchivoProductos::existe() const
{
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");

    if (p == NULL) return false;

    fclose(p);

    return true;
}

bool ArchivoProductos::checkEliminado(int pos) const {
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");

    if (p == nullptr) return false;

    Producto pr;

    fseek(p, sizeof(Producto) * pos, SEEK_SET);
    fread(&pr, sizeof(Producto), 1, p);

    fclose(p);

    return pr.getEliminado();
}

bool ArchivoProductos::reactivarPro(int pos) {
    Producto pr = leerPr(pos);

    pr.setEliminado(false);

    return modificarPr(pr, pos);
}
