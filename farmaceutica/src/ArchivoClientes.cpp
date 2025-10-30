#include "ArchivoClientes.h"
#include <iostream>
using namespace std;

ArchivoClientes::ArchivoClientes(std::string nombreArchivo)
{
    _nombreArchivo=nombreArchivo;
}

bool ArchivoClientes::guardarCliente(Cliente reg)
{
    FILE* p = fopen(_nombreArchivo.c_str(), "ab"); // abrir en modo append
    if (p == NULL)
    {

        cout<<"Error, archivo no encontrado"<<endl;
        return 0;
    }

    fwrite(&reg, sizeof(Cliente), 1, p); // escribe el cliente
    fclose(p);

    return true;
}


int ArchivoClientes::cantidadRegistros()
{
    FILE* p= fopen(_nombreArchivo.c_str(),"rb");

    if(p == NULL)
    {
        cout<<"Error, archivo no encontrado"<<endl;
    }

    fseek(p,0,SEEK_END); // va al final del archivo

    int cantidad= ftell(p)/sizeof(Cliente); // Posicion actual / tamaño Cliente

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

    fseek(p, sizeof(Cliente) * pos, SEEK_SET);  // mueve puntero a la posición
    fread(&c, sizeof(Cliente), 1, p);           // lee el cliente
    fclose(p);


    return c;
}

int ArchivoClientes::buscarPorCUIL(int cuilBuscado)
{
    int total = cantidadRegistros();  // obtenemos cuántos clientes hay en el archivo

    for (int i = 0; i < total; i++)
    {
        Cliente c = leerClientes(i);   // leemos el cliente en la posición i
        if (c.getCuil() == cuilBuscado)
        {
            return i;                 // devolvemos la posición si coincide
        }
    }

    return -1;  // no se encontró
}

bool ArchivoClientes::existe() const {
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");

    if (p == NULL) return false;

    fclose(p);

    return true;
}

