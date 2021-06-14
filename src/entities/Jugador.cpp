
#include <string>
#include <map>
#include <set>
#include <utility>

#include "../../headers/entities/Jugador.h"
// #include "../../headers/entities/Usuario.h"
// #include "../../headers/utils/enums.h"
#include "../../headers/datatypes/DataVideojuego.h"
//#include "../../headers/utils/Fecha.h"

Jugador::Jugador() : Usuario(){};

Jugador::Jugador(std::string email, std::string password, std::string nickname, std::string descripcion) : Usuario(email, password)
{
    this->nickname = nickname;
    this->descripcion = descripcion;
}

std::string Jugador::getNickname()
{
    return this->nickname;
}
std::string Jugador::getDescripcion()
{
    return this->descripcion;
}

void Jugador::setNickname(std::string nick)
{
    this->nickname = nick;
}

void Jugador::setDescripcion(std::string descripcion)
{
    this->descripcion = descripcion;
}

//Jugador::set<ContratoSuscripcion> obtenerSuscripciones(EstadoSuscripcion estado);

void Jugador::cancelarSuscripcionActiva(Videojuego *vj)
{
}

//void Jugador::contratarSuscripcion(Videojuego *vj, ContratoSuscripcion susc, TipoMetodoPago m);

map<int, Partida *> Jugador::obtenerPartidasSinFinalizar()
{
    return map<int, Partida *>(); //retorna un map vacío
}

void Jugador::finalizarPartida(int idPartida)
{
}

map<string, Videojuego *> Jugador::obtenerVideojuegos()
{
    return map<string, Videojuego *>();
}

void Jugador::eliminarContratosDeVideojuego(Videojuego *vj)
{
}

void Jugador::eliminarPartidasDeVideojuego(Videojuego *vj)
{
}

DataUsuario *Jugador::getData()
{
    return nullptr;
}

map<int, PartidaIndividual *> Jugador::obtenerPartidasFinalizadas()
{
    return map<int, PartidaIndividual *>();
}

PartidaIndividual *Jugador::obtenerPartida(string id)
{
    return nullptr;
}

bool tieneSuscripcionActiva(Videojuego *vj)
{
    return false;
}

bool Jugador::tienePartidaSinFinalizar(Videojuego *vj){//operacion faltante en obtenerpartidasfinalizadas en elim videojuego
    map<int, Partida *> partidas=this->partidasIniciadas;
    map<int, Partida *>::iterator it;
    it = partidas.begin();
    PartidaIndividual*partida=dynamic_cast<PartidaIndividual *>(it->second);
    bool tiene=(partida->getFechaFin()==nullptr);
    while(it != partidas.end()&&!tiene){
        it++;
        PartidaIndividual*partida=dynamic_cast<PartidaIndividual *>(it->second);
        tiene=(partida->getFechaFin()==nullptr);
    }
    return tiene;
}

Jugador::~Jugador(){};
