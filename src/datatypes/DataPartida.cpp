#include "../../headers/datatypes/DataPartida.h"

DataPartida::DataPartida()
{
    id = -1;
}

DataPartida::DataPartida(const DataPartida &data)
{
    id = data.id;
    dataVideojuego = data.dataVideojuego;
    fechaInicio = data.fechaInicio;
    fechaFin = data.fechaFin;
    duracionTotal = data.duracionTotal;
}

DataPartida::DataPartida(int id, DataVideojuego dataVideojuego, Fecha fechaInicio, Fecha fechaFin, float duracionTotal)
{
    id = id;
    dataVideojuego = dataVideojuego;
    fechaInicio = fechaInicio;
    fechaFin = fechaFin;
    duracionTotal = duracionTotal;
}

int DataPartida::getId() const { return id; }

Fecha DataPartida::getFechaInicio() const { return fechaInicio; }

Fecha DataPartida::getFechaFin() const { return fechaFin; }

DataVideojuego DataPartida::getDataVideojuego() const { return dataVideojuego; }

float DataPartida::getDuracionTotal() const { return duracionTotal; }

bool operator<(const DataPartida &d1, const DataPartida &d2)
{
    return &d1 < &d2;
}

bool operator!=(const DataPartida &d1, const DataPartida &d2)
{
    return d1.getId() != d2.getId() || d1.getFechaInicio() != d2.getFechaInicio() || d1.getFechaFin() != d2.getFechaFin() || d1.getDuracionTotal() != d2.getDuracionTotal() || d1.getDataVideojuego() != d2.getDataVideojuego();
}

DataPartida::~DataPartida()
{
}
