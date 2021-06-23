#include "../../headers/datatypes/DataPartidaIndividual.h"

DataPartidaIndividual::DataPartidaIndividual() {}

DataPartidaIndividual::DataPartidaIndividual(const DataPartidaIndividual &data) : DataPartida(data)
{
    esContinuacion = data.esContinuacion;
}

DataPartidaIndividual::DataPartidaIndividual(int id, DataVideojuego dataVideojuego, Fecha fechaInicio, Fecha fechaFin, float DuracionTotal, bool esContinuacion) : DataPartida(id, dataVideojuego, fechaInicio, fechaFin, DuracionTotal)
{
    esContinuacion = esContinuacion;
}

bool DataPartidaIndividual::getContinuacion() const { return esContinuacion; }

bool operator<(const DataPartidaIndividual &d1, const DataPartidaIndividual &d2)
{
    return &d1 < &d2;
}

bool operator!=(const DataPartidaIndividual &d1, const DataPartidaIndividual &d2)
{
    return d1.getId() != d2.getId() || d1.getFechaInicio() != d2.getFechaInicio() || d1.getFechaFin() != d2.getFechaFin() || d1.getDuracionTotal() != d2.getDuracionTotal() || d1.getDataVideojuego() != d2.getDataVideojuego() || d1.getContinuacion() != d2.getContinuacion();
}

DataPartidaIndividual::~DataPartidaIndividual() {}
