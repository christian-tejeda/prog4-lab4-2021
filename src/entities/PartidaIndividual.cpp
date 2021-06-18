
#include <string>
#include <map>
#include <set>
#include <utility>

//#include "../../headers/entities/Partida.h"
#include "../../headers/entities/PartidaIndividual.h"
#include "../../headers/entities/Videojuego.h"

PartidaIndividual::PartidaIndividual()
{
}

PartidaIndividual::PartidaIndividual(int id, Fecha fechaInicio, Fecha *fechaFin, float duracionTotal, Videojuego *vj, Jugador *host, PartidaIndividual *cont) : Partida(id, fechaInicio, fechaFin, duracionTotal, vj, host)
{
    this->continua = cont;
}

void PartidaIndividual::finalizar(Fecha *fecha)
{
    this->setFechaFin(fecha);
}
void PartidaIndividual::eliminarPartidasVideojuego(Videojuego *videojuego)
{
}
DataPartida *PartidaIndividual::getData()
{
    return new DataPartida(this->getId(),
                           DataVideojuego(this->getVideojuego()->getNombre(), this->getVideojuego()->getDescripcion(), this->getVideojuego()->getPeriodoValidez(), this->getVideojuego()->getNombreCategorias(), this->getVideojuego()->getRating()),
                           this->getFechaInicio(),
                           this->getFechaFin(),
                           this->getDuracionTotal());
}


PartidaIndividual::~PartidaIndividual() {}