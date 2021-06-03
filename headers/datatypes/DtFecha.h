

#ifndef DT_FECHA_H
#define DT_FECHA_H

#include <iostream>
using namespace std;

class DtFecha
{
private:
    int dia;
    int mes;
    int anio;
    int hora;
    int minuto;

public:
    DtFecha();

    DtFecha(const DtFecha &fecha);

    DtFecha(int dia, int mes, int anio, int hora, int minuto);

    int getDia();
    int getMes();
    int getAnio();
    int getHora();
    int getMinuto();

    ~DtFecha();

    bool operator==(DtFecha opFecha);

    friend std::ostream &operator<<(std::ostream &os, DtFecha f);
};

#endif
