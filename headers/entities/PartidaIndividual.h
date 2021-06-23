#ifndef PARTIDA_INDIVIDUAL_H
#define PARTIDA_INDIVIDUAL_H

#include "Partida.h"
#include "../datatypes/DataPartidaIndividual.h"

class Videojuego;
class Jugador;

class PartidaIndividual : public Partida
{
private:
    PartidaIndividual *continua;

public:
    PartidaIndividual();

    bool getEsContinuacion();

    PartidaIndividual(int id, Fecha fechaInicio, Fecha fechaFin, float duracionTotal, Videojuego *videojuego, Jugador *host, PartidaIndividual *continuacion);

    void finalizar(Fecha fecha);
    void eliminarPartidasVideojuego(Videojuego *videojuego);

    DataPartidaIndividual getData();

    ~PartidaIndividual();
};

#endif