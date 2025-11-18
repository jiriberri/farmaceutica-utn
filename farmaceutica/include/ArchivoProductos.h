#ifndef ARCHIVOPRODUCTOS_H
#define ARCHIVOPRODUCTOS_H
#pragma once
#include <string>
#include "Producto.h"

class ArchivoProductos
{
    private:
        std::string _nombreArchivo;

    public:
        ArchivoProductos(std::string nombreArchivo);

        bool guardarPr(Producto reg);

        int cantidadRegistros();

        Producto leerPr(int pos);

        bool modificarPr(Producto, int pos);

        int buscarPorId(int id);

        bool existe() const;

        bool checkEliminado(int pos) const;

        bool reactivarPro(int pos);
};

#endif // ARCHIVOPRODUCTOS_H
