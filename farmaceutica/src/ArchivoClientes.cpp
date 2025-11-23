#include "ArchivoClientes.h"
#include <iostream>
using namespace std;

ArchivoClientes::ArchivoClientes(std::string nombreArchivo)
{
    _nombreArchivo=nombreArchivo;
}

bool ArchivoClientes::guardarCliente(Cliente reg)
{
    FILE* p = fopen(_nombreArchivo.c_str(), "ab");
    if (p == NULL)
    {

        cout<<"Error, archivo no encontrado"<<endl;
        return 0;
    }

    fwrite(&reg, sizeof(Cliente), 1, p);
    fclose(p);

    return true;
}

int ArchivoClientes::cantidadRegistros()
{
    FILE* p= fopen(_nombreArchivo.c_str(),"rb");

    if(p == NULL)
    {
        cout << "Error, archivo no encontrado" << endl;
        return 0;
    }

    fseek(p,0,SEEK_END);

    int cantidad= ftell(p)/sizeof(Cliente);

    fclose(p);

    return cantidad;
}

Cliente ArchivoClientes::leerClientes(int pos)
{

    FILE *p = fopen(_nombreArchivo.c_str(),"rb");

    if(p==nullptr)
    {
        return Cliente();
    }

    Cliente c;

    fseek(p, sizeof(Cliente) * pos, SEEK_SET);
    fread(&c, sizeof(Cliente), 1, p);
    fclose(p);


    return c;
}

bool ArchivoClientes::modificarCliente(Cliente obj, int pos)
{

    FILE *p =fopen(_nombreArchivo.c_str(),"rb+");

    if(p==nullptr)
    {
        return false;
    }
    fseek(p, pos * sizeof obj, 0);
    bool escribio=fwrite(&obj,sizeof obj,1,p);
    fclose(p);
    return escribio;
}

int ArchivoClientes::buscarPorCUIL(long long cuilBuscado)
{
    int total = cantidadRegistros();

    for (int i = 0; i < total; i++)
    {
        Cliente c = leerClientes(i);
        if (c.getCuil() == cuilBuscado)
        {
            return i;
        }
    }

    return -1;
}

bool ArchivoClientes::existe() const {
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");

    if (p == NULL) return false;

    fclose(p);

    return true;
}

bool ArchivoClientes::checkEliminado(int pos) const {
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");

    if (p == nullptr) return false;

    Cliente c;

    fseek(p, sizeof(Cliente) * pos, SEEK_SET);
    fread(&c, sizeof(Cliente), 1, p);

    fclose(p);

    return c.getEliminado();
}

bool ArchivoClientes::reactivarCliente(int pos) {
    Cliente c = leerClientes(pos);

    c.setEliminado(false);

    return modificarCliente(c, pos);
}

