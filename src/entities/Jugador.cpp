
#include <string>
#include <map>
#include <set>
#include <utility>

#include "../../headers/entities/Jugador.h"
#include "../../headers/entities/Usuario.h"
#include "../../headers/utils/enums.h"
#include "../../headers/datatypes/DataVideojuego.h"
#include "../../headers/utils/Fecha.h"

Jugador::Jugador() {}

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

void Jugador::setNickname(std::string nick) {
    this->nickname = nick;
}

void Jugador::setDescripcion(std::string descripcion) {
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

DataUsuario *Jugador::*getData()
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

Jugador::~Jugador(){};
