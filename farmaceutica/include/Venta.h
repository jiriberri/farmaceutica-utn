#ifndef VENTA_H
#define VENTA_H
#include "Fecha.h"

class Venta
{
private:
    int _numFactura;
    long long _cuilCliente;
    int _idObraSocial;
    Fecha _fecha;
    char _medioPago[20];
    float _importe;
    bool _eliminado;

public:

    Venta(int numFactura = 0,
          long long cuilCliente = 0,
          int idObraSocial=0,
          Fecha fecha = Fecha(),
          const char* medioPago = "",
          float importe = 0.0f,
          bool eliminado = false);

    // Getters
    int getNumFacturas() const;
    long long getCuilCliente() const;
    int getIdObraSocial() const;
    Fecha getFecha() const;
    const char* getMedioDePago() const;
    float getImporte() const;
    bool getEliminado() const;

    // Setters
    void setNumFacturas(int num);
    void setCuilCliente(long long cuil);
    void setIdObraSocial(int id);
    void setFecha(const Fecha& f);
    void setMedioDePago(const char* medio);
    void setImporte(float imp);
    void setEliminado(bool e);
};

#endif // VENTA_H
