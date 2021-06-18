

#include <string>
#include <map>
#include <set>
#include <utility>

#include "../../headers/controllers/PartidaController.h"
#include "../../headers/utils/Fecha.h"

using namespace std;

PartidaController::PartidaController() {}

//op de singleton
//PartidaController *PartidaController::getInstance() {}

//Getters
Jugador *PartidaController::getJugador()
{
    return this->jg;
}
Videojuego *PartidaController::getVideojuego()
{
    return this->vj;
}
PartidaIndividual *PartidaController::getPartidaAContinuar()
{
    return this->partidaAContinuar;
}
Jugador *PartidaController::getParticipantePorNickname(string nick)
{
    return nullptr;
}
//ops de interface
set<DataPartida *> PartidaController::obtenerPartidasSinFinalizarDeJugador()
{
    set<DataPartida *> res;
    res.insert(nullptr);
    return res;
}
void PartidaController::finalizarPartida(int idPartida)
{
}
void PartidaController::seleccionarPartidaAContinuar(int id)
{
}
set<DataVideojuego *> PartidaController::obtenerVideojuegosDeJugadorConSuscripcionActiva()
{
    set<DataVideojuego *> res;
    res.insert(nullptr);
    return res;
}
set<DataPartidaIndividual *> PartidaController::obtenerPartidasFinalizadasDeJugador()
{
    set<DataPartidaIndividual *> res;
    res.insert(nullptr);
    return res;
}
void PartidaController::esTransmitidaEnVivo(bool transmitidaEnVivo)
{
}
set<DataJugador *> PartidaController::obtenerJugadoresConSuscripcionActiva()
{
    set<DataJugador *> res;
    res.insert(nullptr);
    return res;
}
void PartidaController::seleccionarVideojuego(string nombreVideojuego)
{
}
void PartidaController::seleccionarJugador(string nickname)
{
}
void PartidaController::confirmarIniciarPartida(bool confirmar)
{
}
set<DataPartidaMultijugador *> PartidaController::obtenerPartidasMultijugadorActivasDeJugador()
{
    set<DataPartidaMultijugador *> res;
    res.insert(nullptr);
    return res;
}
void PartidaController::abandonarPartida(int idPartida)
{
}
PartidaController::~PartidaController() {}
