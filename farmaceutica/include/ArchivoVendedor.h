#pragma once
#include <string>
#include "Vendedor.h"

class ArchivoVendedor
{
private:

    std::string _nombreArchivo;


public:

    ArchivoVendedor(std::string nombreArchivo);

    bool guardarVendedor(Vendedor reg);

    int cantidadRegistros();

    Vendedor leerVendedor(int pos);

    bool modificarVendedor(Vendedor, int pos);

    int buscarPorID(long long IDSolicitado);

    bool existe() const;

    bool checkEliminado(int pos) const;

    bool reactivarEmpleado(int pos);
};


