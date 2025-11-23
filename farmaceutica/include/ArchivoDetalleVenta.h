#pragma once
#include <string>
#include "DetalleVenta.h"


class ArchivoDetalleVenta{

private:

    std::string _nombreArchivo;

public:

    ArchivoDetalleVenta(std::string nombreArchivo);

    bool guardarDetalleVenta(DetalleVenta reg);
    int cantidadRegistros();
    DetalleVenta leerDetalleVenta(int pos);
    bool modificarDetalleVenta(DetalleVenta obj, int pos);
    int buscarPorNumFactura(int numFactura);
    bool existe() const;

};
