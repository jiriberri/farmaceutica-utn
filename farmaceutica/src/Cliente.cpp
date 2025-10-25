#include "Cliente.h"
#include <cstring>

int Cliente::getCuil() const { return _cuil; }
const char* Cliente::getNombre() const { return _nombre; }
const char* Cliente::getApellido() const { return _apellido; }
int Cliente::getIdObraSocial() const { return _idObraSocial; }
const char* Cliente::getDomicilio() const { return _domicilio; }
const char* Cliente::getMail() const { return _mail; }
const char* Cliente::getTelefono() const { return _telefono; }
bool Cliente::getEliminado() const { return _eliminado; }

void Cliente::setCuil(int c){ _cuil = c; }
void Cliente::setNombre(const char* n){
    std::strncpy(_nombre, n ? n : "", sizeof(_nombre)-1);
    _nombre[sizeof(_nombre)-1] = '\0';
}
void Cliente::setApellido(const char* a){
    std::strncpy(_apellido, a ? a : "", sizeof(_apellido)-1);
    _apellido[sizeof(_apellido)-1] = '\0';
}
void Cliente::setIdObraSocial(int o){ _idObraSocial = o; }

void Cliente::setDomicilio(const char* d){
    std::strncpy(_domicilio, d ? d : "", sizeof(_domicilio)-1);
    _domicilio[sizeof(_domicilio)-1] = '\0';
}

void Cliente::setMail(const char* m){
    std::strncpy(_mail, m ? m : "", sizeof(_mail)-1);
    _mail[sizeof(_mail)-1] = '\0';
}
void Cliente::setTelefono(const char* t){
    std::strncpy(_telefono, t ? t : "", sizeof(_telefono)-1);
    _telefono[sizeof(_telefono)-1] = '\0';
}

void Cliente::setEliminado(bool e){ _eliminado = e; }

Cliente::Cliente(int c, const char* n, const char* a, int o, const char* d, char* m, char* t, bool e){
    setCuil(c);
    setNombre(n);
    setApellido(a);
    setIdObraSocial(o);
    setDomicilio(d);
    setMail(m);
    setTelefono(t);
    setEliminado(e);
}
