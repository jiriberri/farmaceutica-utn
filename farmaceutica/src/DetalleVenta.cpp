#include "DetalleVenta.h"
#include <iostream>


DetalleVenta::DetalleVenta(int nFactura, int idProducto, int cantidad, float precio, bool eliminado)
{

    setNumFactura(nFactura);
    setIdProducto(idProducto);
    setCantidad(cantidad);
    setPrecio(precio);
    setEliminado(eliminado);
}


int DetalleVenta::getNumFactura(){ return _numFactura; }

int DetalleVenta::getIdProducto(){ return _idProducto; }

int DetalleVenta::getCantidad(){ return _cantidad; }

float DetalleVenta::getPrecio(){ return _precio; }

bool DetalleVenta::getEliminado(){ return _eliminado; }

void DetalleVenta::setNumFactura(int numFactura){ _numFactura = numFactura; }
void DetalleVenta::setIdProducto(int idProducto){ _idProducto = idProducto; }
void DetalleVenta::setCantidad(int cantidad){ _cantidad = cantidad; }
void DetalleVenta::setPrecio(float precio){ _precio = precio; }
// agregar setSubtotal y todo lo que conlleva
void DetalleVenta::setEliminado(bool eliminado){ _eliminado = eliminado; }
