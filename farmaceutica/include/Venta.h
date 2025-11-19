#ifndef VENTA_H
#define VENTA_H

#include "Fecha.h"

class Venta
{
private:
    int _NumFacturas;
    long long _CuilCliente;
    Fecha _fecha;
    char _MedioDePago[20];
    float _Importe;
    bool _Eliminado;

public:

    Venta(int numFactura = 0,
          long long cuilCliente = 0,
          Fecha fecha = Fecha(),
          const char* medioPago = "",
          float importe = 0.0f,
          bool eliminado = false);

    // Getters
    int getNumFacturas() const;
    long long getCuilCliente() const;
    Fecha getFecha() const;
    const char* getMedioDePago() const;
    float getImporte() const;
    bool getEliminado() const;

    // Setters
    void setNumFacturas(int num);
    void setCuilCliente(long long cuil);
    void setFecha(Fecha f);
    void setMedioDePago(const char* medio);
    void setImporte(float imp);
    void setEliminado(bool e);
};

#endif // VENTA_H
