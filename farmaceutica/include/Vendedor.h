#ifndef VENDEDOR_H
#define VENDEDOR_H

#include "Persona.h"

class Vendedor : public Persona {
private:
    long long _id;
    int _sueldo;
    bool _eliminado;

public:
    Vendedor(long long id = 0, const char* n = "", const char* a = "",
             int sueldo = 0, const char* d = "", const char* m = "",
             const char* t = "", bool eliminado = false);

    long long getId() const;
    int getSueldo() const;
    bool getEliminado() const;

    void setId(long long id);
    void setSueldo(int sueldo);
    void setEliminado(bool eliminado);
};

#endif
