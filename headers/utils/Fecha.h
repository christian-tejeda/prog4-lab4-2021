

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

    int getDia();
    int getMes();
    int getAnio();
    int getHora();
    int getMinuto();

    ~Fecha();

    bool operator==(Fecha opFecha);
    //Calcula la diferencia entre dos Fechas en horas.
    float operator-(const Fecha &opFecha);

    friend std::ostream &operator<<(std::ostream &os, Fecha f);
};

#endif
