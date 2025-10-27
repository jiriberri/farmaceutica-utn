#pragma once
#include <string>
#include "Cliente.h"


class ArchivoClientes {
private:

std::string _nombreArchivo;


public:

ArchivoClientes(std::string nombreArchivo);

bool guardarCliente(Cliente reg);

int cantidadRegistros();

Cliente leerClientes(int pos);

int buscarPorCUIL(int cuilSolicitado);

};








