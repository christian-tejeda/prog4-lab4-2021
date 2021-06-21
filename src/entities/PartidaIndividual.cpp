
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

bool PartidaIndividual::getEsContinuacion(){
    return (this->continua!=nullptr);
}

void PartidaIndividual::finalizar(Fecha *fecha)
{
    this->setFechaFin(fecha);
    Fecha inicio = this->getFechaInicio();
    Fecha actual = *fecha;
    float f;
    f=abs(actual-inicio);
    this->setDuracionTotal(f);
}
void PartidaIndividual::eliminarPartidasVideojuego(Videojuego *videojuego)
{
}
DataPartida *PartidaIndividual::getData()
{
    return new DataPartidaIndividual(this->getId(),
                           new DataVideojuego(this->getVideojuego()->getNombre(), this->getVideojuego()->getDescripcion(), this->getVideojuego()->getPeriodoValidez(), this->getVideojuego()->getNombreCategorias(), this->getVideojuego()->getRating()),
                           this->getFechaInicio(),
                           this->getFechaFin(),
                           this->getDuracionTotal(),this->getEsContinuacion());
}


PartidaIndividual::~PartidaIndividual() {}