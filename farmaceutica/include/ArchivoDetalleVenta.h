
#pragma once
#include <string>
#include "DetalleVenta.h"


class ArchivoDetalleVenta{

private:

    std::string _nombreArchivo;




public:

    ArchivoDetalleVenta(std::string nombreArchivo);

    bool guardarDetalleVenta(Detalleventas reg);
    int Cantidadregistros();
    DetalleVenta leerDetalleVenta(int pos);
    bool modificarVenta(Venta obj, int pos);

    int buscarPorNumFactura(int numFactura);
    bool existe() const;

};






#endif // ARCHIVODETALLEVENTA_H_INCLUDED
