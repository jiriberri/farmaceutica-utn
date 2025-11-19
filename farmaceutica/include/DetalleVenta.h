#ifndef DETALLEVENTA_H
#define DETALLEVENTA_H

#include "Producto.h"



class DetalleVenta {

private:
int _NumFactura;
int _idProducto;
int _Cantidad;
float _Precio;
bool _Eliminado;

public:
    DetalleVenta(int NumFactura=0, int idProducto=0, int Cantidad=0, float Precio 0.0f, bool eliminado= false);



    ///Getters
    int getNumFactura();
    int getIdProducto();
    int getCantidad();
    float getPrecio();
    bool getEliminado();

    ///Setters

    void setNumFactura(int numFactura);
    void setIdProducto(int idProducto);
    void setCantidad(int cantidad);
    void setPrecio(float precio);
    void setEliminado(bool eliminado);

}

#endif
