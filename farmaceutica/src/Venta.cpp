#include "Venta.h"
#include <cstring>

Venta::Venta(int numFactura, int idVendedor, long long cuilCliente, int idObraSocial, Fecha fecha, const char* medioPago, float importe, bool eliminado){

setNumFacturas(numFactura);
    setIdVendedor(idVendedor);
    setCuilCliente(cuilCliente);
    setIdObraSocial(idObraSocial);
    setFecha(fecha);
    setMedioDePago(medioPago);
    setImporte(importe);
    setEliminado(eliminado);

}


int Venta::getNumFacturas() const { return _NumFacturas; }
int Venta::getIdVendedor() const { return _idVendedor; }
long long Venta::getCuilCliente() const { return _CuilCliente; }
int Venta::getIdObraSocial() const { return _IdObraSocial; }
Fecha Venta::getFecha() const { return _fecha; }
const char* Venta::getMedioDePago() const { return _MedioDePago; }
float Venta::getImporte() const { return _Importe; }
bool Venta::getEliminado() const { return _Eliminado; }


void Venta::setNumFacturas(int num) { _NumFacturas = num; }
void Venta::setIdVendedor(int id) { _idVendedor = id; }
void Venta::setCuilCliente(long long cuil) { _CuilCliente = cuil; }
void Venta::setIdObraSocial(int id) { _IdObraSocial = id; }
void Venta::setFecha(Fecha f) { _fecha = f; }
void Venta::setMedioDePago(const char* medio)
{
    std::strncpy(_MedioDePago, medio ? medio:"", sizeof(_MedioDePago)-1);
    _MedioDePago[sizeof(_MedioDePago)-1] ='\0';
}

void Venta::setImporte(float imp) { _Importe = imp; }
void Venta::setEliminado(bool e) { _Eliminado = e; }
