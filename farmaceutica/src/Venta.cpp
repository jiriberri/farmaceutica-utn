#include "Venta.h"
#include <cstring>

Venta::Venta(int numFactura, long long cuilCliente, int idObraSocial, const char* medioPago, float importe, bool eliminado){

setNumFacturas(numFactura);
    setCuilCliente(cuilCliente);
    setIdObraSocial(idObraSocial);
    // setFecha(fecha);
    setMedioDePago(medioPago);
    setImporte(importe);
    setEliminado(eliminado);

}


int Venta::getNumFacturas() const { return _numFactura; }
long long Venta::getCuilCliente() const { return _cuilCliente; }
int Venta::getIdObraSocial() const { return _idObraSocial; }
// Fecha Venta::getFecha() const { return _fecha; }
const char* Venta::getMedioDePago() const { return _medioPago; }
float Venta::getImporte() const { return _importe; }
bool Venta::getEliminado() const { return _eliminado; }


void Venta::setNumFacturas(int num) { _numFactura = num; }
void Venta::setCuilCliente(long long cuil) { _cuilCliente = cuil; }
void Venta::setIdObraSocial(int id) { _idObraSocial = id; }
// void Venta::setFecha(Fecha f) { _fecha = f; }
void Venta::setMedioDePago(const char* medio)
{
    std::strncpy(_medioPago, medio ? medio:"", sizeof(_medioPago)-1);
    _medioPago[sizeof(_medioPago)-1] ='\0';
}

void Venta::setImporte(float imp) { _importe = imp; }
void Venta::setEliminado(bool e) { _eliminado = e; }
