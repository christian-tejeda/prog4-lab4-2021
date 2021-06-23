#ifndef DATA_PARTIDA_H
#define DATA_PARTIDA_H

#include <string>

#include "../datatypes/DataVideojuego.h"
#include "../utils/Fecha.h"

using namespace std;

class DataPartida
{
private:
    int id;
    DataVideojuego dataVideojuego;
    Fecha fechaInicio;
    Fecha fechaFin;
    float duracionTotal;

public:
    DataPartida();
    DataPartida(const DataPartida &data);
    DataPartida(int id, DataVideojuego dataVideojuego, Fecha fechaInicio, Fecha fechaFin, float duracionTotal);

    int getId() const;
    DataVideojuego getDataVideojuego() const;
    Fecha getFechaInicio() const;
    Fecha getFechaFin() const;
    float getDuracionTotal() const;

    friend bool operator<(const DataPartida &d1, const DataPartida &d2);
    friend bool operator!=(const DataPartida &d1, const DataPartida &d2);

    virtual ~DataPartida();
};

#endif