#ifndef ARCHIVOVENTAS_H_INCLUDED
#define ARCHIVOVENTAS_H_INCLUDED


#include "Venta.h"
#include <cstdio>

class ArchivoVentas {
private:
    char _nombre[30];

public:
    ArchivoVentas(const char* nombre = "ventas.dat");

    bool guardarVenta(Venta reg);
    int cantidadRegistros();
    Venta leerVenta(int pos);
    bool modificarVenta(Venta reg, int pos);
    int buscarPorNumFactura(int numFactura);
    bool existe() const;
};


#endif // ARCHIVOVENTAS_H_INCLUDED
