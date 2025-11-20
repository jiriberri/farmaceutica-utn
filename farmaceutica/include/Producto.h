#ifndef PRODUCTO_H
#define PRODUCTO_H


class Producto
{
    private:
        int _id;
        char _descripcion[100];
        int _stock;
        float _precioUnitario;
        bool _aplicaDescuento;
        bool _eliminado;

    public:
        Producto(int id = 0, const char* d = "", int s = 0,
                 float p = 0, bool apDesc = false, bool e = false);

        int getId() const;
        const char* getDescripcion() const;
        int getStock() const;
        float getPrecioUnitario() const;
        bool getAplicaDescuento() const;
        bool getEliminado() const;

        void setId(int id);
        void setDescripcion(const char* d);
        void setStock(int s);
        void setPrecioUnitario(float p);
        void setAplicaDescuento(bool apDesc);
        void setEliminado(bool e);

};

#endif // PRODUCTO_H
