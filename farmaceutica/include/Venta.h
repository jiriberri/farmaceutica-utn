#ifndef VENTA_H
#define VENTA_H

#include "Fecha.h"

class Venta
{
private:
    int _NumFacturas;
    int _idVendedor;
    long long _CuilCliente;
    int _IdObraSocial;
    Fecha _fecha;
    char _MedioDePago[20];
    float _Importe;
    bool _Eliminado;

public:

    Venta(int numFactura = 0,
          int idVendedor=0;
          long long cuilCliente = 0,
          int IdObraSocial=0.
          Fecha fecha = Fecha(),
          const char* medioPago = "",
          float importe = 0.0f,
          bool eliminado = false);

    // Getters
    int getNumFacturas() const;
    int getIdVendedor() const;
    long long getCuilCliente() const;
    int getIdObraSocial() const;
    Fecha getFecha() const;
    const char* getMedioDePago() const;
    float getImporte() const;
    bool getEliminado() const;

    // Setters
    void setNumFacturas(int num);
    void setIdVendedor(int id);
    void setCuilCliente(long long cuil);
    void setIdObraSocial(int id);
    void setFecha(Fecha f);
    void setMedioDePago(const char* medio);
    void setImporte(float imp);
    void setEliminado(bool e);
};

#endif // VENTA_H
