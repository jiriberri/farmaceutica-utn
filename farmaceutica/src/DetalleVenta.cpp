#include "DetalleVenta.h"
#include <iostream>


DetalleVenta::DetalleVenta(int nFactura, int idProducto, int cantidad, float precio,float subtotal, bool eliminado)
{

    setNumFactura(nFactura);
    setIdProducto(idProducto);
    setCantidad(cantidad);
    setPrecio(precio);
    setSubtotal(subtotal);
    setEliminado(eliminado);

}


int DetalleVenta::getNumFactura(){ return _numFactura; }

int DetalleVenta::getIdProducto(){ return _idProducto; }

int DetalleVenta::getCantidad(){ return _cantidad; }

float DetalleVenta::getPrecio(){ return _precio; }

float DetalleVenta::getSubtotal(){return _subtotal;}

bool DetalleVenta::getEliminado(){ return _eliminado; }

void DetalleVenta::setNumFactura(int numFactura){ _numFactura = numFactura; }
void DetalleVenta::setIdProducto(int idProducto){ _idProducto = idProducto; }
void DetalleVenta::setCantidad(int cantidad){ _cantidad = cantidad; }
void DetalleVenta::setPrecio(float precio){ _precio = precio; }
void DetalleVenta::setSubtotal(float subtotal){ _subtotal=subtotal;}// agregar setSubtotal y todo lo que conlleva
void DetalleVenta::setEliminado(bool eliminado){ _eliminado = eliminado; }
