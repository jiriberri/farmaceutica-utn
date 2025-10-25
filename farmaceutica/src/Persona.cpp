#include "Persona.h"
#include <cstring>

Persona::Persona(const char* n, const char* a, const char* d, const char* m, const char* t)
{
    setNombre(n);
    setApellido(a);
    setDomicilio(d);
    setMail(m);
    setTelefono(t);
}

const char* Persona::getNombre() const { return _nombre; }
const char* Persona::getApellido() const { return _apellido; }
const char* Persona::getDomicilio() const { return _domicilio; }
const char* Persona::getMail() const { return _mail; }
const char* Persona::getTelefono() const { return _telefono; }

void Persona::setNombre(const char* n){
    std::strncpy(_nombre, n ? n : "", sizeof(_nombre)-1);
    _nombre[sizeof(_nombre)-1] = '\0';
}
void Persona::setApellido(const char* a){
    std::strncpy(_apellido, a ? a : "", sizeof(_apellido)-1);
    _apellido[sizeof(_apellido)-1] = '\0';
}

void Persona::setDomicilio(const char* d){
    std::strncpy(_domicilio, d ? d : "", sizeof(_domicilio)-1);
    _domicilio[sizeof(_domicilio)-1] = '\0';
}

void Persona::setMail(const char* m){
    std::strncpy(_mail, m ? m : "", sizeof(_mail)-1);
    _mail[sizeof(_mail)-1] = '\0';
}
void Persona::setTelefono(const char* t){
    std::strncpy(_telefono, t ? t : "", sizeof(_telefono)-1);
    _telefono[sizeof(_telefono)-1] = '\0';
}
