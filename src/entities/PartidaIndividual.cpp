
#include <string>
#include <map>
#include <set>
#include <utility>

#include "../../headers/datatypes/DataPartidaIndividual.h"
#include "../../headers/entities/PartidaIndividual.h"
#include "../../headers/entities/Videojuego.h"

PartidaIndividual::PartidaIndividual()
{
}

PartidaIndividual::PartidaIndividual(int id, Fecha fechaInicio, Fecha fechaFin, float duracionTotal, Videojuego *videojuego, Jugador *host, PartidaIndividual *continuacion) : Partida(id, fechaInicio, fechaFin, duracionTotal, videojuego, host)
{
    this->continua = continuacion;
}

bool PartidaIndividual::getEsContinuacion() { return (this->continua != nullptr); }

void PartidaIndividual::finalizar(Fecha fecha)
{
    this->setFechaFin(fecha);
    Fecha inicio = this->getFechaInicio();
    Fecha actual = fecha;
    float duracion = abs(actual - inicio);
    this->setDuracionTotal(duracion);
}
void PartidaIndividual::eliminarPartidasVideojuego(Videojuego *videojuego) {}

DataPartidaIndividual PartidaIndividual::getData()
{
    return DataPartidaIndividual(this->getId(), DataVideojuego(this->getVideojuego()->getNombre(), this->getVideojuego()->getDescripcion(), this->getVideojuego()->getPeriodoValidez(), this->getVideojuego()->getNombreCategorias(), this->getVideojuego()->getRating()), this->getFechaInicio(), this->getFechaFin(), this->getDuracionTotal(), this->getEsContinuacion());
}

PartidaIndividual::~PartidaIndividual() {}