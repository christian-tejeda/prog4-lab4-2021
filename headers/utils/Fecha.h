#ifndef DATA_FECHA_H
#define DATA_FECHA_H

#include <iostream>
using namespace std;

class Fecha
{
private:
    int dia;
    int mes;
    int anio;
    int hora;
    int minuto;
    int contarAniosBisiestos(const Fecha &f);

public:
    Fecha();
    Fecha(const Fecha &fecha);
    Fecha(int dia, int mes, int anio, int hora, int minuto);

    int getDia() const;
    int getMes() const;
    int getAnio() const;
    int getHora() const;
    int getMinuto() const;

    ~Fecha();

    bool operator==(Fecha fecha);
    friend bool operator!=(const Fecha &f1, const Fecha &f2);
    float operator-(const Fecha &fecha);

    friend ostream &operator<<(ostream &os, Fecha fecha);
};

#endif
