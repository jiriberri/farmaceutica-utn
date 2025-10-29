#include "Cliente.h"

Cliente::Cliente(int c, const char* n, const char* a,
                 int o, const char* d, const char* m,
                 const char* t, bool e)
    : Persona(n, a, d, m, t)
{
    _cuil = c;
    _idObraSocial = o;
    _eliminado = e;
}

int Cliente::getCuil() const
{
    return _cuil;
}
int Cliente::getIdObraSocial() const
{
    return _idObraSocial;
}
bool Cliente::getEliminado() const
{
    return _eliminado;
}

void Cliente::setCuil(int c)
{
    _cuil = c;
}
void Cliente::setIdObraSocial(int o)
{
    _idObraSocial = o;
}

void Cliente::setEliminado(bool e)
{
    _eliminado = e;
}
