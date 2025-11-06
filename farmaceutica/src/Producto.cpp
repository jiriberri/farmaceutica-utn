#include "Producto.h"
#include <cstring>

Producto::Producto(int id, const char* d, int s, float p, bool e)
{
    setId(id);
    setDescripcion(d);
    setStock(s);
    setPrecioUnitario(p);
    setEliminado(e);
}

int Producto::getId() const { return _id; }
const char* Producto::getDescripcion() const { return _descripcion; }
int Producto::getStock() const { return _stock; }
float Producto::getPrecioUnitario() const { return _precioUnitario; }
bool Producto::getEliminado() const { return _eliminado; }

void Producto::setId(int id)
{
    _id = id;
}
void Producto::setDescripcion(const char* d)
{
    std::strncpy(_descripcion, d ? d : "", sizeof(_descripcion)-1);
    _descripcion[sizeof(_descripcion)-1] = '\0';
}
void Producto::setStock(int s)
{
    _stock = s;
}
void Producto::setPrecioUnitario(float p)
{
    _precioUnitario = p;
}
void Producto::setEliminado(bool e)
{
    _eliminado = e;
}
