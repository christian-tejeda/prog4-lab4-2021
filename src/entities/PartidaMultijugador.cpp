
#include <string>
#include <map>
#include <set>
#include <utility>

#include "../../headers/entities/PartidaMultijugador.h"

PartidaMultijugador::PartidaMultijugador()
{
}

PartidaMultijugador::PartidaMultijugador(int id, Fecha fechaInicio, Fecha fechaFin, float duracionTotal, Videojuego *videojuego, Jugador *host, bool trasmitida, set<DuracionParticipante *> participantes) : Partida(id, fechaInicio, fechaFin, duracionTotal, videojuego, host)
{
    this->transmitidaEnVivo = trasmitida;
    this->participantes = participantes;
}

bool PartidaMultijugador::getTransmitidaEnVivo() { return this->transmitidaEnVivo; }

set<DuracionParticipante *> PartidaMultijugador::getDuracionParticipantes() { return this->participantes; }

void PartidaMultijugador::setTransmitidaEnVivo(bool enVivo) { this->transmitidaEnVivo = enVivo; }

void PartidaMultijugador::agregarParticipante(Jugador *participante)
{
    ///TODO: vacio???
}

void PartidaMultijugador::finalizar(Fecha fecha)
{
    float duracionTotal = 0;

    set<DuracionParticipante *> participantes = this->participantes;
    set<DuracionParticipante *>::iterator it;
    for (it = participantes.begin(); it != participantes.end(); it++)
    {
        DuracionParticipante *duracionParticipante = *it;
        duracionParticipante->terminarParticipacion(fecha);
        duracionTotal += duracionParticipante->calcularDuracion();
    }
    this->setFechaFin(fecha);
    this->setDuracionTotal(duracionTotal * participantes.size());
}

void PartidaMultijugador::eliminarPartidasVideojuego(Videojuego *videojuego)
{
    set<DuracionParticipante *> dur = this->participantes;
    set<DuracionParticipante *>::iterator it;
    for (it = dur.begin(); it != dur.end(); ++it)
    {
        DuracionParticipante *cuestion = *it;
        delete cuestion; //o sino hacer cuestion->~DuracionParticipante();
    }
    dur.clear();
    this->participantes.clear();
}

DataPartidaMultijugador PartidaMultijugador::getData()
{
    set<DataJugador> participantes = set<DataJugador>();
    set<DuracionParticipante *>::iterator it;

    for (it = this->participantes.begin(); it != this->participantes.end(); it++)
    {
        DuracionParticipante *duracionParticipante = *it;
        participantes.insert(duracionParticipante->getParticipante()->getData());
    }

    DataVideojuego dataVideojuego = DataVideojuego(this->getVideojuego()->getNombre(), this->getVideojuego()->getDescripcion(), this->getVideojuego()->getPeriodoValidez(), this->getVideojuego()->getNombreCategorias(), this->getVideojuego()->getRating());

    return DataPartidaMultijugador(this->getId(), dataVideojuego, this->getFechaInicio(), this->getFechaFin(), this->getDuracionTotal(), this->getTransmitidaEnVivo(), this->getHost()->getData(), participantes);
}

bool PartidaMultijugador::existeParticipante(Jugador *jugador)
{
    set<DuracionParticipante *> participantes = this->participantes;
    set<DuracionParticipante *>::iterator it;
    for (it = participantes.begin(); it != participantes.end(); it++)
    {
        DuracionParticipante *duracionParticipante = *it;
        if (duracionParticipante->getParticipante() == jugador)
            return true;
    }

    return false;
}

void PartidaMultijugador::bajarParticipante(Jugador *jugador, Fecha fecha)
{
    set<DuracionParticipante *> participantes = this->participantes;
    float duracion = -1;
    set<DuracionParticipante *>::iterator it;
    for (it = participantes.begin(); it != participantes.end(); it++)
    {
        DuracionParticipante *duracionParticipante = *it;
        if (duracionParticipante->getParticipante() == jugador)
        {
            duracionParticipante->setHoraSalida(fecha);
            duracion = duracionParticipante->calcularDuracion();
            break;
        }
    }

    if (duracion >= 0.0F)
    {
        this->setDuracionTotal(abs(duracion));
    }
}

PartidaMultijugador::~PartidaMultijugador() {}