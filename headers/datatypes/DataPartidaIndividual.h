#ifndef DATA_PARTIDA_INDIVIDUAL_H
#define DATA_PARTIDA_INDIVIDUAL_H

#include "../datatypes/DataPartida.h"

using namespace std;

class DataPartidaIndividual : public DataPartida
{
private:
    bool esContinuacion;

public:
    DataPartidaIndividual();
    DataPartidaIndividual(const DataPartidaIndividual &data);
    DataPartidaIndividual(int id, DataVideojuego videojuego, Fecha fechaInicio, Fecha fechaFin, float duracionTotal, bool esContinuacion);

    bool getContinuacion() const;

    friend bool operator<(const DataPartidaIndividual &d1, const DataPartidaIndividual &d2);
    friend bool operator!=(const DataPartidaIndividual &d1, const DataPartidaIndividual &d2);

    ~DataPartidaIndividual();
};

#endif