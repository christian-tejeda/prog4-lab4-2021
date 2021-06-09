
#include <string>
#include <map>
#include <set>
#include <utility>

#include "../../headers/entities/Partida.h"

Partida::Partida() {}

Partida::Partida(int id, Fecha fechaInicio, Fecha fechaFin, float duracionTotal, Videojuego *vj, set<Jugador *> jugadores)
{
    this->id = id;
    this->fechaFin = fechaFin;
    this->fechaInicio = fechaInicio;
    this->duracionTotal = duracionTotal;
    this->videojuego = vj;
    this->jugadores = jugadores;
}

int Partida::getId()
{
    return this->id;
}
Fecha Partida::getFechaInicio()
{
    return this->fechaInicio;
}
Fecha Partida::getFechaFin()
{
    return this->fechaFin;
}
float Partida::getDuracionTotal()
{
    return this->duracionTotal;
}
Videojuego *Partida::getVideojuego()
{
    return this->videojuego;
}
void Partida::setId(int id)
{
    this->id = id;
}
void Partida::setFechaInicio(Fecha fechaInicio)
{
    this->fechaInicio = fechaInicio;
}
void Partida::setFechaFin(Fecha fechaFin)
{
    this->fechaFin = fechaFin;
}
void Partida::setDuracionTotal(float duracionTotal)
{
    this->duracionTotal;
}
bool Partida::esFinalizada()
{
    return (this->fechaFin.getAnio() == NULL);
}
bool Partida::perteneceAVideojuego(Videojuego videojuego)
{
    return false;
}

Partida::~Partida() {}
