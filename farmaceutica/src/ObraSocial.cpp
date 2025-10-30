#include "ObraSocial.h"
#include <cstring>

ObraSocial::ObraSocial(int id, const char* d, float desc, const char* t, const char* m, bool e)
{
    setId(id);
    setDescripcion(d);
    setDescuento(desc);
    setTelefono(t);
    setMail(m);
    setEliminado(e);
}

int ObraSocial::getId() const { return _id; }
const char* ObraSocial::getDescripcion() const { return _descripcion; }
float ObraSocial::getDescuento() const { return _descuento; }
const char* ObraSocial::getTelefono() const { return _telefono; }
const char* ObraSocial::getMail() const { return _mail; }
bool ObraSocial::getEliminado() const { return _eliminado; }

void ObraSocial::setId(int id)
{
    _id = id;
}
void ObraSocial::setDescripcion(const char* d)
{
    std::strncpy(_descripcion, d ? d : "", sizeof(_descripcion)-1);
    _descripcion[sizeof(_descripcion)-1] = '\0';
}
void ObraSocial::setDescuento(float desc)
{
    _descuento = desc;
}
void ObraSocial::setTelefono(const char* t)
{
    std::strncpy(_telefono, t ? t : "", sizeof(_telefono)-1);
    _telefono[sizeof(_telefono)-1] = '\0';
}
void ObraSocial::setMail(const char* m)
{
    std::strncpy(_mail, m ? m : "", sizeof(_mail)-1);
    _mail[sizeof(_mail)-1] = '\0';
}
void ObraSocial::setEliminado(bool e)
{
    _eliminado = e;
}
