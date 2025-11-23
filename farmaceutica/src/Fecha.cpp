#include "Fecha.h"
#include <iostream>
#include <ctime>
#include <cstdio>

using namespace std;

Fecha::Fecha(int dia, int mes, int anio) : _dia(dia), _mes(mes), _anio(anio) {}

void Fecha::cargar() {
    bool valido = false;

    while (!valido) {
        cout << "Dia: ";
        cin >> _dia;
        cout << "Mes: ";
        cin >> _mes;
        cout << "Anio: ";
        cin >> _anio;

        // Validacion de rangos
        if (_anio < 1) {
            cout << "Anio invalido.\n";
            continue;
        }
        if (_mes < 1 || _mes > 12) {
            cout << "Mes invalido (1-12).\n";
            continue;
        }

        // Dias maximos por mes
        int diasMes[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

        // Ajuste por anio bisiesto
        bool bisiesto = (_anio % 4 == 0 && (_anio % 100 != 0 || _anio % 400 == 0));
        if (bisiesto && _mes == 2) diasMes[1] = 29;

        if (_dia < 1 || _dia > diasMes[_mes - 1]) {
            cout << "Dia invalido para el mes ingresado.\n";
            continue;
        }
        valido = true;
    }
}

void Fecha::mostrar() const {
    if (_dia == 0 && _mes == 0 && _anio == 0) {
        cout << "Fecha No Establecida";
    } else {
        cout << _dia << "/" << _mes << "/" << _anio;
    }
    cout << endl;
}

int Fecha::getDia() const { return _dia; }
int Fecha::getMes() const { return _mes; }
int Fecha::getAnio() const { return _anio; }

void Fecha::setDia(int dia) { _dia = dia; }
void Fecha::setMes(int mes) { _mes = mes; }
void Fecha::setAnio(int anio) { _anio = anio; }

Fecha Fecha::fechaActual() {
    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);

    Fecha hoy;
    hoy.setDia(timeinfo->tm_mday);
    hoy.setMes(timeinfo->tm_mon + 1);
    hoy.setAnio(timeinfo->tm_year + 1900);
    return hoy;
}

