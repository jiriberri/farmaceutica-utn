#ifndef ARCHIVOOBRASSOCIALES_H
#define ARCHIVOOBRASSOCIALES_H
#pragma once
#include <string>
#include "ObraSocial.h"


class ArchivoObrasSociales
{
    private:
        std::string _nombreArchivo;

    public:
        ArchivoObrasSociales(std::string nombreArchivo);

        bool guardarOS(ObraSocial reg);

        int cantidadRegistros();

        ObraSocial leerOS(int pos);

        int buscarPorId(int id);

        bool existe() const;
};

#endif // ARCHIVOOBRASSOCIALES_H
