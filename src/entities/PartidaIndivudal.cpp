
#include <string>
#include <map>
#include <set>
#include <utility>

#include "../../headers/entities/Partida.h"
#include "../../headers/entities/PartidaIndividual.h"

PartidaIndividual::PartidaIndividual()
{
}

PartidaIndividual::PartidaIndividual(int id, Fecha fechaInicio, Fecha fechaFin, float duracionTotal, Videojuego *vj, set<Jugador *> jugadores, PartidaIndividual *cont) : Partida(id, fechaInicio, fechaFin, duracionTotal, vj, jugadores)
{
    this->continua = cont;
}

void PartidaIndividual::finalizar(Fecha fecha)
{
    this->setFechaFin(fecha);
}
void PartidaIndividual::eliminarPartidasVideojuego(Videojuego videojuego)
{
}
DataPartida PartidaIndividual::getData()
{
    return DataPartida(this->getId(),
                       DataVideojuego(this->getVideojuego()->getNombre(), this->getVideojuego()->getDescripcion(), this->getVideojuego()->getPeriodoValidez(), this->getVideojuego()->getCategorias(), this->getVideojuego()->getRating()),
                       this->getFechaInicio(),
                       this->getFechaFin(),
                       this->getDuracionTotal());
}

PartidaIndividual::~PartidaIndividual() {}