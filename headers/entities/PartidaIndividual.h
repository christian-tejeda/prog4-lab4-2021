#ifndef PARTIDA_INDIVIDUAL_H
#define PARTIDA_INDIVIDUAL_H

#include "./Partida.h"
#include "../datatypes/DataPartidaIndividual.h"

class PartidaIndividual : public Partida
{

    PartidaIndividual();

    PartidaIndividual(DataPartidaIndividual dataPartidaIndividual);

    PartidaIndividual(int id, Fecha fechaInicio, Fecha fechaFin, float duracionTotal);

public:
    void finalizar();
    void eliminarPartidasVideojuego(Videojuego videojuego);

    DataPartida getData();

    ~PartidaIndividual();
};

#endif