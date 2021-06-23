#ifndef PARTIDA_MULTIJUGADOR_H
#define PARTIDA_MULTIJUGADOR_H

#include "DuracionParticipante.h"
#include "../datatypes/DataPartidaMultijugador.h"

class Jugador;
class Videojuego;
class DuracionParticipante;

class PartidaMultijugador : public Partida
{
private:
    bool transmitidaEnVivo;
    set<DuracionParticipante *> participantes;

public:
    PartidaMultijugador();

    PartidaMultijugador(int id, Fecha fechaInicio, Fecha fechaFin, float duracionTotal, Videojuego *videojuego, Jugador *host, bool trasmitida, set<DuracionParticipante *> participantes);

    bool getTransmitidaEnVivo();

    set<DuracionParticipante *> getDuracionParticipantes();

    void setTransmitidaEnVivo(bool enVivo);

    void agregarParticipante(Jugador *participante);

    void finalizar(Fecha fecha);

    void eliminarPartidasVideojuego(Videojuego *videojuego);

    bool existeParticipante(Jugador *jugador);

    void bajarParticipante(Jugador *jugador, Fecha f);

    DataPartidaMultijugador getData();

    ~PartidaMultijugador();
};

#endif