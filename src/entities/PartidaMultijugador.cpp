
#include <string>
#include <map>
#include <set>
#include <utility>

//#include "../../headers/entities/Partida.h"
#include "../../headers/entities/PartidaMultijugador.h"

PartidaMultijugador::PartidaMultijugador()
{
}

//no cumple req datapartidamultijugador PartidaMultijugador(DataPartidaMultijugador dataPartidaMultijugador);

PartidaMultijugador::PartidaMultijugador(int id, Fecha fechaInicio, Fecha *fechaFin, float duracionTotal, Videojuego *vj, Jugador *host, bool trasmitida, set<DuracionParticipante *> durpart) : Partida(id, fechaInicio, fechaFin, duracionTotal, vj, host)
{
    this->transmitidaEnVivo = trasmitida;
    this->durpart = durpart;
}

bool PartidaMultijugador::getTransmitidaEnVivo()
{
    return this->transmitidaEnVivo;
}
set<DuracionParticipante *> PartidaMultijugador::getDuracionParticipantes()
{
    return this->durpart;
}

void PartidaMultijugador::setTransmitidaEnVivo(bool enVivo)
{
    this->transmitidaEnVivo = enVivo;
}

void PartidaMultijugador::agregarParticipante(Jugador *participante)
{
}
void PartidaMultijugador::finalizar(Fecha * fecha)
{
}
void PartidaMultijugador::eliminarPartidasVideojuego(Videojuego *videojuego)
{
}

DataPartida *PartidaMultijugador::getData()
{
    return new DataPartida(this->getId(),
                           DataVideojuego(this->getVideojuego()->getNombre(), this->getVideojuego()->getDescripcion(), this->getVideojuego()->getPeriodoValidez(), this->getVideojuego()->getNombreCategorias(), this->getVideojuego()->getRating()),
                           this->getFechaInicio(),
                           this->getFechaFin(),
                           this->getDuracionTotal());
}

PartidaMultijugador::~PartidaMultijugador() {}