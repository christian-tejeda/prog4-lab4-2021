#ifndef PARTIDA_INDIVIDUAL_H
#define PARTIDA_INDIVIDUAL_H

#include "./Partida.h"
#include "../datatypes/DataPartidaIndividual.h"

class PartidaIndividual : public Partida
{
private:
    PartidaIndividual *continua;

public:
    PartidaIndividual();

    //data partida ind no cumple requerimientos PartidaIndividual(DataPartidaIndividual dataPartidaIndividual);

    PartidaIndividual(int id, Fecha fechaInicio, Fecha fechaFin, float duracionTotal, Videojuego *vj, set<Jugador *> jugadores, PartidaIndividual *cont);

    void finalizar(Fecha f);
    void eliminarPartidasVideojuego(Videojuego videojuego);

    DataPartida getData();

    ~PartidaIndividual();
};

#endif