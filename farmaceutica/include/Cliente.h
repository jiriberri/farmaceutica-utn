#ifndef CLIENTE_H
#define CLIENTE_H


class Cliente
{
    private:
        int _cuil;
        char _nombre[20];
        char _apellido[20];
        int _idObraSocial;
        bool _eliminado;

    public:
        Cliente(int c=0, const char* n="", const char* a="", int o=0, bool e=false);

        int getCuil() const;
        const char* getNombre() const;
        const char* getApellido() const;
        int getIdObraSocial() const;
        bool getEliminado() const;

        void setCuil(int c);
        void setNombre(const char* n);
        void setApellido(const char* a);
        void setIdObraSocial(int o);
        void setEliminado(bool e);

};

#endif // CLIENTE_H
