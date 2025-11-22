#ifndef FECHA_H
#define FECHA_H


class Fecha
{
    private:
        int _dia;
        int _mes;
        int _anio;

    public:
        Fecha(int dia = 0, int mes = 0, int anio = 0);

        void cargar();
        void mostrar() const;

        int getDia() const;
        int getMes() const;
        int getAnio() const;

        void setDia(int dia);
        void setMes(int mes);
        void setAnio(int anio);

        static Fecha fechaActual();

};

#endif // FECHA_H
