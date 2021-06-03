#ifndef PARTIDA_MULTIJUGADOR_H
#define PARTIDA_MULTIJUGADOR_H

#include "Partida.h"
#include "../datatypes/DataPartidaMultijugador.h"

class PartidaMultijugador : public Partida
{

    PartidaMultijugador();

    PartidaMultijugador(DataPartidaMultijugador dataPartidaMultijugador);

    PartidaMultijugador(int id, Fecha fechaInicio, Fecha fechaFin, float duracionTotal);

private:
    bool transmitidaEnVivo;

public:
    bool getTransmitidaEnVivo();

    void setTransmitidaEnVivo(bool enVivo);

    void agregarParticipante(Jugador participante);
    void finalizar();
    void eliminarPartidasVideojuego(Videojuego videojuego);

    DataPartida getData();

    ~PartidaMultijugador();
};

#endif