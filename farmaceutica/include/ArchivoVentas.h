#pragma once
#include <string>
#include "Venta.h"





class ArchivoVentas {

private:
    std::string _nombreArchivo;

public:
    ArchivoVentas(std::string nombreArchivo);

    bool guardarVenta(Venta reg);
    int cantidadRegistros();
    Venta leerVenta(int pos);
    bool modificarVenta(Venta obj, int pos);
    int buscarPorNumFactura(int numFactura);
    bool existe() const;
};
