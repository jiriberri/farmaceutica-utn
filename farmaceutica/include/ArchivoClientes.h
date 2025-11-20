#pragma once
#include <string>
#include "Cliente.h"

class ArchivoClientes
{
private:

    std::string _nombreArchivo;


public:

    ArchivoClientes(std::string nombreArchivo);

    bool guardarCliente(Cliente reg);

    int cantidadRegistros();

    Cliente leerClientes(int pos);

    bool modificarCliente(Cliente, int pos);

    int buscarPorCUIL(long long cuilSolicitado);

    bool existe() const;

    bool checkEliminado(int pos) const;

    bool reactivarCliente(int pos);
};



