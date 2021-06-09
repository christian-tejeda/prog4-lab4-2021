
#include <string>
#include <map>
#include <set>
#include <utility>

#include "../../headers/entities/Partida.h"
#include "../../headers/entities/PartidaMultijugador.h"

PartidaMultijugador::PartidaMultijugador()
{
}

//no cumple req datapartidamultijugador PartidaMultijugador(DataPartidaMultijugador dataPartidaMultijugador);

PartidaMultijugador::PartidaMultijugador(int id, Fecha fechaInicio, Fecha fechaFin, float duracionTotal, Videojuego *vj, set<Jugador *> jugadores, bool trasmitida, set<DuracionParticipante> durpart) : Partida(id, fechaInicio, fechaFin, duracionTotal, vj, jugadores)
{
    this->transmitidaEnVivo = trasmitida;
    this->durpart = durpart;
}

bool PartidaMultijugador::getTransmitidaEnVivo()
{
    this->transmitidaEnVivo;
}
set<DuracionParticipante> PartidaMultijugador::getDuracionParticipantes()
{
    this->durpart;
}

void PartidaMultijugador::setTransmitidaEnVivo(bool enVivo)
{
    this->transmitidaEnVivo = enVivo;
}

void PartidaMultijugador::agregarParticipante(Jugador participante)
{
}
void PartidaMultijugador::finalizar()
{
}
void PartidaMultijugador::eliminarPartidasVideojuego(Videojuego videojuego)
{
}

DataPartida PartidaMultijugador::getData()
{
    return DataPartida(this->getId(),
                       DataVideojuego(this->getVideojuego()->getNombre(), this->getVideojuego()->getDescripcion(), this->getVideojuego()->getPeriodoValidez(), this->getVideojuego()->getCategorias(), this->getVideojuego()->getRating()),
                       this->getFechaInicio(),
                       this->getFechaFin(),
                       this->getDuracionTotal());
}

PartidaMultijugador::~PartidaMultijugador() {}