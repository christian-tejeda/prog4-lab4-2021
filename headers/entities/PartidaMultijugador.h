#ifndef PARTIDA_MULTIJUGADOR_H
#define PARTIDA_MULTIJUGADOR_H

#include "Partida.h"
#include "../datatypes/DataPartidaMultijugador.h"
#include "../entities/DuracionParticipante.h"

class PartidaMultijugador : public Partida
{
private:
    bool transmitidaEnVivo;
    set<DuracionParticipante> durpart;

public:
    PartidaMultijugador();

    //no cumple req datapartidamultijugador PartidaMultijugador(DataPartidaMultijugador dataPartidaMultijugador);

    PartidaMultijugador(int id, Fecha fechaInicio, Fecha fechaFin, float duracionTotal, Videojuego *vj, set<Jugador *> jugadores, bool trasmitida, set<DuracionParticipante> durpart);

    bool getTransmitidaEnVivo();
    set<DuracionParticipante> getDuracionParticipantes();

    void setTransmitidaEnVivo(bool enVivo);

    void agregarParticipante(Jugador participante);
    void finalizar();
    void eliminarPartidasVideojuego(Videojuego videojuego);

    DataPartida getData();

    ~PartidaMultijugador();
};

#endif