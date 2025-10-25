#ifndef PERSONA_H
#define PERSONA_H
#pragma once


class Persona
{
    private:
        char _nombre[20];
        char _apellido[20];
        char _domicilio[50];
        char _mail[30];
        char _telefono[12];
    public:
        Persona(const char* n = "", const char* a = "", const char* d = "", const char* m = "", const char* t = "");

        const char* getNombre() const;
        const char* getApellido() const;
        const char* getDomicilio() const;
        const char* getMail() const;
        const char* getTelefono() const;

        void setNombre(const char* n);
        void setApellido(const char* a);
        void setDomicilio(const char* d);
        void setMail(const char* m);
        void setTelefono(const char* t);
        void setEliminado(bool e);
};

#endif // PERSONA_H
