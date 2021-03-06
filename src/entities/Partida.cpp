
#include <string>
#include <map>
#include <set>
#include <utility>

#include "../../headers/entities/Partida.h"

Partida::Partida() {}

Partida::Partida(int id, Fecha fechaInicio, Fecha *fechaFin, float duracionTotal, Videojuego *vj, Jugador *host)
{
    this->id = id;
    this->fechaFin = fechaFin;
    this->fechaInicio = fechaInicio;
    this->duracionTotal = duracionTotal;
    this->videojuego = vj;
    this->host = host;
}

int Partida::getId()
{
    return this->id;
}
Fecha Partida::getFechaInicio()
{
    return this->fechaInicio;
}
Fecha *Partida::getFechaFin()
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
Jugador *Partida::getHost()
{
    return this->host;
}

void Partida::setId(int id)
{
    this->id = id;
}
void Partida::setFechaInicio(Fecha fechaInicio)
{
    this->fechaInicio = fechaInicio;
}
void Partida::setFechaFin(Fecha *fechaFin)
{
    this->fechaFin = fechaFin;
}

//Acumula las horas de los jugadores que van abandonando.
void Partida::setDuracionTotal(float duracionTotal)
{
    this->duracionTotal += duracionTotal;
}
void Partida::setHost(Jugador *host)
{
    this->host = host;
}

bool Partida::esFinalizada()
{
    return (this->fechaFin != nullptr);
}
bool Partida::perteneceAVideojuego(Videojuego *videojuego)
{
    return false;
}

Partida::~Partida() {}
