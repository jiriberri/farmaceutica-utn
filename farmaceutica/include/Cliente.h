#ifndef CLIENTE_H
#define CLIENTE_H


class Cliente
{
    private:
        int _cuil;
        char _nombre[20];
        char _apellido[20];
        int _idObraSocial;
        char _domicilio[50];
        char _mail[30];
        char _telefono[12];
        bool _eliminado;

    public:
        Cliente(int c = 0, const char* n = "", const char* a = "", int o = 0, const char* d = "", char* m = "", char* t = "", bool e = false);

        int getCuil() const;
        const char* getNombre() const;
        const char* getApellido() const;
        int getIdObraSocial() const;
        const char* getDomicilio() const;
        const char* getMail() const;
        const char* getTelefono() const;
        bool getEliminado() const;

        void setCuil(int c);
        void setNombre(const char* n);
        void setApellido(const char* a);
        void setIdObraSocial(int o);
        void setDomicilio(const char* d);
        void setMail(const char* m);
        void setTelefono(const char* t);
        void setEliminado(bool e);

};

#endif // CLIENTE_H
