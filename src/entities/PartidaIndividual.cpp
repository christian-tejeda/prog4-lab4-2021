
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
    float f=0;
    //f=fecha-inicio;
    /*
    if (fecha->getAnio()>inicio.getAnio()){
        f=1000;
    }
    else{
        if (fecha->getMes()>inicio.getMes()){
            (fecha->getDia()>inicio.getDia()) ? (f=f+fecha->getDia()-inicio.getDia()-1) : (f=30-inicio.getDia()+fecha->getDia());
            f=f*24+fecha->getHora();
            f=f+((fecha->getMinuto())/60);
            f=f+24-inicio.getHora();
            f=f+60-((inicio.getMinuto())/60);
        }
        else{
            if (fecha->getDia()>inicio.getDia()){
                f=fecha->getDia()-inicio.getDia()-1;
                f=f*24+fecha->getHora();
                f=f+((fecha->getMinuto())/60);
                f=f+24-inicio.getHora();
                f=f+60-((inicio.getMinuto())/60);
            }
            else {
                f=fecha->getHora()-inicio.getHora()+((fecha->getMinuto()-inicio.getMinuto())/60);
            }
        }
    }*/
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