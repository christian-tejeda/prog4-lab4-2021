
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
void PartidaMultijugador::finalizar(Fecha *fecha)
{
    set<DuracionParticipante *> dur = this->durpart;
    float d = 0;
    int con = 0;
    //d=fecha-this->fechaInicio();
    set<DuracionParticipante *>::iterator it;
    for (it = dur.begin(); it != dur.end(); it++)
    {
        DuracionParticipante *cuestion = *it;
        //cuestion->setHoraSalida(fecha);
        cuestion->terminarParticipacion(fecha);
        con++;
    }
    this->setFechaFin(fecha);
    this->setDuracionTotal(d * con);
}
void PartidaMultijugador::eliminarPartidasVideojuego(Videojuego *videojuego)
{
    set<DuracionParticipante *> dur = this->durpart;
    set<DuracionParticipante *>::iterator it;
    for (it = dur.begin(); it != dur.end(); it++)
    {
        DuracionParticipante *cuestion = *it;
        dur.erase(*it);
        delete cuestion;
    }
}

DataPartida *PartidaMultijugador::getData()
{
    return new DataPartida(this->getId(),
                           new DataVideojuego(this->getVideojuego()->getNombre(), this->getVideojuego()->getDescripcion(), this->getVideojuego()->getPeriodoValidez(), this->getVideojuego()->getNombreCategorias(), this->getVideojuego()->getRating()),
                           this->getFechaInicio(),
                           this->getFechaFin(),
                           this->getDuracionTotal());
}

bool PartidaMultijugador::existeParticipante(Jugador *jg)
{
    set<DuracionParticipante *>::iterator it;
    for (it = this->durpart.begin(); it != this->durpart.end(); it++)
    {
        if ((*it)->getParticipante() == jg)
            break;
    }
    if (it != this->durpart.end())
        return true;
    else
        return false;
}

void PartidaMultijugador::bajarParticipante(Jugador *jg, Fecha *f)
{
    float dur = -1;
    set<DuracionParticipante *>::iterator it;
    for (it = this->durpart.begin(); it != this->durpart.end(); it++)
    {
        if ((*it)->getParticipante() == jg)
        {
            (*it)->setHoraSalida(f);
            dur = (*it)->calcularDuracion();
            break;
        }
    }

    if (dur >= 0.0F)
    {
        this->setDuracionTotal(abs(dur));
    }
}

PartidaMultijugador::~PartidaMultijugador()
{
}