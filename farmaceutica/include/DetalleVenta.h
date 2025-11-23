#ifndef DETALLEVENTA_H
#define DETALLEVENTA_H
#pragma once
#include "Producto.h"



class DetalleVenta
{
private:
    int _numFactura;
    int _idProducto;
    int _cantidad;
    float _precio;
     float _subtotal;
    bool _eliminado;


public:
    DetalleVenta(int numFactura = 0,
                 int idProducto = 0,
                 int cantidad = 0,
                 float precio = 0.0f,
                 float subtotal=0.0f,
                 bool eliminado = false);

    ///Getters
    int getNumFactura();
    int getIdProducto();
    int getCantidad();
    float getPrecio();
    float getSubtotal();
    bool getEliminado();

    ///Setters
    void setNumFactura(int numFactura);
    void setIdProducto(int idProducto);
    void setCantidad(int cantidad);
    void setPrecio(float precio);
    void setSubtotal(float subtotal);
    void setEliminado(bool eliminado);
};
#endif
