#ifndef OBRASOCIAL_H
#define OBRASOCIAL_H
#pragma once

class ObraSocial
{
    private:
        int _id;
        char _descripcion[100];
        float _descuento;
        char _telefono[12];
        char _mail[30];
        bool _eliminado;

    public:
        ObraSocial(int id = 0, const char* d = "", float desc = 0,
                   const char* t = "", const char* m = "", bool e = false);

        int getId() const;
        const char* getDescripcion() const;
        float getDescuento() const;
        const char* getTelefono() const;
        const char* getMail() const;
        bool getEliminado() const;

        void setId(int id);
        void setDescripcion(const char* d);
        void setDescuento(float desc);
        void setTelefono(const char* t);
        void setMail(const char* m);
        void setEliminado(bool e);
};

#endif // OBRASOCIAL_H
