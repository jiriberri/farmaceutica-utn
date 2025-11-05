#ifndef CLIENTE_H
#define CLIENTE_H

#include "Persona.h"

class Cliente : public Persona
{
private:
    long long _cuil;
    int _idObraSocial;
    bool _eliminado;

public:
    Cliente(long long c = 0, const char* n = "", const char* a = "",
            int o = 0, const char* d = "", const char* m = "",
            const char* t = "", bool e = false);

    // Getters y setters
    long long getCuil() const;
    int getIdObraSocial() const;
    bool getEliminado() const;

    void setCuil(long long c);
    void setIdObraSocial(int o);
    void setEliminado(bool e);
};

#endif // CLIENTE_H
