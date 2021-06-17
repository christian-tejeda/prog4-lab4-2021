#ifndef PARTIDA_MULTIJUGADOR_H
#define PARTIDA_MULTIJUGADOR_H

class Partida; //fwd dec

#include "PartidaIndividual.h"
#include "../datatypes/DataPartidaMultijugador.h"
#include "DuracionParticipante.h"

class DuracionParticipante; //forward declaration
class Jugador;              //forward declaration
class Videojuego;           //forward declaration

class PartidaMultijugador : public Partida
{
private:
    bool transmitidaEnVivo;
    set<DuracionParticipante *> durpart;

public:
    PartidaMultijugador();

    //no cumple req datapartidamultijugador PartidaMultijugador(DataPartidaMultijugador dataPartidaMultijugador);

    PartidaMultijugador(int id, Fecha fechaInicio, Fecha *fechaFin, float duracionTotal, Videojuego *vj, Jugador *host, bool trasmitida, set<DuracionParticipante *> durpart);

    bool getTransmitidaEnVivo();
    set<DuracionParticipante *> getDuracionParticipantes();

    void setTransmitidaEnVivo(bool enVivo);

    void agregarParticipante(Jugador *participante);
    void finalizar(Fecha * fecha);
    void eliminarPartidasVideojuego(Videojuego *videojuego);

    DataPartida *getData();

    ~PartidaMultijugador();
};

#endif