#include "Vendedor.h"
#include <cstring>

Vendedor::Vendedor(long long id, const char* n, const char* a,
                   int sueldo, const char* d, const char* m,
                   const char* t, bool eliminado)
    : Persona(n, a, d, m, t)
{
    _id = id;
    _sueldo = sueldo;
    _eliminado = eliminado;
}

// Getters
long long Vendedor::getId() const {
    return _id;
}

int Vendedor::getSueldo() const {
    return _sueldo;
}

bool Vendedor::getEliminado() const {
    return _eliminado;
}

// Setters
void Vendedor::setId(long long id) {
    _id = id;
}

void Vendedor::setSueldo(int sueldo) {
    _sueldo = sueldo;
}

void Vendedor::setEliminado(bool eliminado) {
    _eliminado = eliminado;
}
