

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

public:
    Fecha();
    Fecha(const Fecha &fecha);
    Fecha(int dia, int mes, int anio, int hora, int minuto);

    int getDia();
    int getMes();
    int getAnio();
    int getHora();
    int getMinuto();

    ~Fecha();

    bool operator==(Fecha opFecha);

    friend std::ostream &operator<<(std::ostream &os, Fecha f);
};

#endif
