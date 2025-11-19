#include "DetalleVenta.h"
#include <iostream>


DetalleVenta::DetalleVenta(int NFactura, int idProducto, int Cantidad, float Precio , bool eliminado){

setNumFactura(Nfactura);
setIdProducto(idProducto);
setCantidad(Cantidad);
setPrecio(Precio);
setEliminado(eliminado);
}


int DetalleVenta::getNumFactura(){

return _NumFactura;
}

int DetalleVenta::getIdProducto(){

return _idProducto;
}

int DetalleVenta::getCantidad(){

return _Cantidad;
}

int DetalleVenta::getPrecio(){

return _Precio;
}

bool DetalleVenta::getEliminado(){

return _Eliminado;
}

    void setNumFactura(int numFactura){

    _NumFactura=numFactura;

    }
    void setIdProducto(int idProducto){

    _idProducto=idProducto;
    }
    void setCantidad(int cantidad){

    _Cantidad=cantidad;

    }
    void setPrecio(float precio){

    _Precio=precio;

    }
    void setEliminado(bool eliminado){
    _Eliminado=eliminado;

    }
