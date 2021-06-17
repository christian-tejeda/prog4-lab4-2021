#ifndef PARTIDA_INDIVIDUAL_H
#define PARTIDA_INDIVIDUAL_H

class Partida; //fwd dec

#include "Partida.h"
#include "../datatypes/DataPartidaIndividual.h"

class Videojuego; //fwd dec
class Jugador;    //fwd dec

class PartidaIndividual : public Partida
{
private:
    PartidaIndividual *continua;

public:
    PartidaIndividual();

    //data partida ind no cumple requerimientos PartidaIndividual(DataPartidaIndividual dataPartidaIndividual);

    PartidaIndividual(int id, Fecha fechaInicio, Fecha *fechaFin, float duracionTotal, Videojuego *vj, Jugador *host, PartidaIndividual *cont);

    void finalizar(Fecha* fecha);
    void eliminarPartidasVideojuego(Videojuego *videojuego);

    DataPartida *getData();

    ~PartidaIndividual();
};

#endif