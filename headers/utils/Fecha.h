

#ifndef DATA_FECHA_H
#define DATA_FECHA_H

#include <iostream>
using namespace std;

class DataFecha
{
private:
    int dia;
    int mes;
    int anio;
    int hora;
    int minuto;

public:
    DataFecha();

    DataFecha(const DataFecha &fecha);

    DataFecha(int dia, int mes, int anio, int hora, int minuto);

    int getDia();
    int getMes();
    int getAnio();
    int getHora();
    int getMinuto();

    ~DataFecha();

    bool operator==(DataFecha opFecha);

    friend std::ostream &operator<<(std::ostream &os, DataFecha f);
};

#endif
