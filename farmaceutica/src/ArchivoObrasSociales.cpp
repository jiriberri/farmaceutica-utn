#include "ArchivoObrasSociales.h"
#include <iostream>
using namespace std;

ArchivoObrasSociales::ArchivoObrasSociales(string nombreArchivo)
{
    _nombreArchivo = nombreArchivo;
}

bool ArchivoObrasSociales::guardarOS(ObraSocial reg)
{
    FILE* p = fopen(_nombreArchivo.c_str(), "ab");
    if (p == NULL)
    {
        cout << "Error, archivo no encontrado 1." << endl;
        return 0;
    }

    fwrite(&reg, sizeof(ObraSocial), 1, p);
    fclose(p);

    return true;
}

int ArchivoObrasSociales::cantidadRegistros()
{
    FILE* p= fopen(_nombreArchivo.c_str(),"rb");

    if(p == NULL)
    {
        cout<<"Error, archivo no encontrado 2."<<endl;
    }

    fseek(p,0,SEEK_END);

    int cantidad = ftell(p)/sizeof(ObraSocial);

    return cantidad;
}

ObraSocial ArchivoObrasSociales::leerOS(int pos)
{
    FILE *p = fopen(_nombreArchivo.c_str(),"rb");

    if(p==nullptr)
    {
        return ObraSocial();
    }

    ObraSocial os;

    fseek(p, sizeof(ObraSocial) * pos, SEEK_SET);
    fread(&os, sizeof(ObraSocial), 1, p);
    fclose(p);

    return os;
}

int ArchivoObrasSociales::buscarPorId(int id)
{
    int total = cantidadRegistros();

    for (int i = 0; i < total; i++)
    {
        ObraSocial os = leerOS(i);
        if(os.getId() == id)
        {
            return i;
        }
    }

    return -1;
}

bool ArchivoObrasSociales::modificarObraSocial(ObraSocial obj, int pos)
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

bool ArchivoObrasSociales::existe() const
{
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");

    if (p == NULL) return false;

    fclose(p);

    return true;
}

bool ArchivoObrasSociales::checkEliminado(int pos) const {
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");

    if (p == nullptr) return false;

    ObraSocial os;

    fseek(p, sizeof(ObraSocial) * pos, SEEK_SET);
    fread(&os, sizeof(ObraSocial), 1, p);

    fclose(p);

    return os.getEliminado();
}

bool ArchivoObrasSociales::reactivarOS(int pos) {
    ObraSocial os = leerOS(pos);

    os.setEliminado(false);

    return modificarObraSocial(os, pos);
}

