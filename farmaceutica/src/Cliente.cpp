#include "Cliente.h"
#include <cstring>

int Cliente::getCuil() const { return _cuil; }
const char* Cliente::getNombre() const { return _nombre; }
const char* Cliente::getApellido() const { return _apellido; }
int Cliente::getIdObraSocial() const { return _idObraSocial; }
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
void Cliente::setEliminado(bool e){ _eliminado = e; }

Cliente::Cliente(int c, const char* n, const char* a, int o, bool e){
    setCuil(c);
    setNombre(n);
    setApellido(a);
    setIdObraSocial(o);
    setEliminado(e);
}
