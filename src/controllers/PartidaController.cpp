#include <map>
#include <set>

#include "../../headers/controllers/PartidaController.h"
#include "../../headers/controllers/UsuarioController.h"
#include "../../headers/utils/Fecha.h"
#include "../../headers/handlers/VideojuegoHandler.h"
#include "../../headers/entities/Jugador.h"
#include "../../headers/handlers/UsuarioHandler.h"

int PartidaController::idPartida = 0;

PartidaController::PartidaController()
{
    this->jugador = nullptr;
    this->videojuego = nullptr;
    this->partidaAContinuar = nullptr;
}

int PartidaController::generarIdPartida()
{
    ///TODO: ????
    idPartida = idPartida + 1;
    return idPartida - 1;
}

Jugador *PartidaController::getJugador() { return this->jugador; }

Videojuego *PartidaController::getVideojuego() { return this->videojuego; }

PartidaIndividual *PartidaController::getPartidaAContinuar() { return this->partidaAContinuar; }

set<DataPartida> PartidaController::obtenerPartidasSinFinalizarDeJugador()
{
    UsuarioController *usuarioController = UsuarioController::getInstance();

    Jugador *jugador = dynamic_cast<Jugador *>(usuarioController->getSesion());
    this->jugador = jugador;

    set<DataPartida> res = set<DataPartida>();
    if (jugador != nullptr)
    {
        map<int, Partida *> partidasSinFinalizar = jugador->obtenerPartidasSinFinalizar();
        map<int, Partida *>::iterator it;
        for (it = partidasSinFinalizar.begin(); it != partidasSinFinalizar.end(); it++)
        {
            Partida *partida = it->second;
            PartidaMultijugador *partidaMultijugador = dynamic_cast<PartidaMultijugador *>(partida);
            PartidaIndividual *partidaIndividual = dynamic_cast<PartidaIndividual *>(partida);

            if (partidaMultijugador)
            {
                res.insert(partidaMultijugador->getData());
            }
            else
            {
                res.insert(partidaIndividual->getData());
            }
        }
    }

    return res;
}

void PartidaController::finalizarPartida(int idPartida, Fecha fecha)
{
    Jugador *jugador = dynamic_cast<Jugador *>(this->jugador);

    if (jugador != nullptr)
    {
        jugador->finalizarPartida(idPartida, fecha);
    }
}

void PartidaController::seleccionarPartidaAContinuar(int id)
{
    PartidaIndividual *partidaAContinuar = dynamic_cast<Jugador *>(this->jugador)->obtenerPartida(id);

    if (partidaAContinuar == nullptr)
    {
        throw invalid_argument("Error. Id de partida no valido, intente con otro ");
    }

    this->partidaAContinuar = partidaAContinuar;
}

set<DataVideojuego> PartidaController::obtenerVideojuegosDeJugadorConSuscripcionActiva(Fecha fecha)
{
    UsuarioController *usuarioController = UsuarioController::getInstance();

    Jugador *jugador = dynamic_cast<Jugador *>(usuarioController->getSesion());
    map<string, Videojuego *> videojuegos = jugador->obtenerVideojuegosConSuscripcionActiva(fecha);

    set<DataVideojuego> res;
    map<string, Videojuego *>::iterator it;
    for (it = videojuegos.begin(); it != videojuegos.end(); it++)
    {
        Videojuego *videojuego = it->second;
        DataVideojuego dataVideojuego = videojuego->getData();
        res.insert(dataVideojuego);
    }

    return res;
}
set<DataPartidaIndividual> PartidaController::obtenerPartidasFinalizadasDeJugador()
{

    map<int, PartidaIndividual *> partidasFinalizadas = dynamic_cast<Jugador *>(this->jugador)->obtenerPartidasFinalizadas();

    set<DataPartidaIndividual> res;
    map<int, PartidaIndividual *>::iterator it;
    for (it = partidasFinalizadas.begin(); it != partidasFinalizadas.end(); it++)
    {
        PartidaIndividual *partida = it->second;
        DataPartidaIndividual dataPartida = partida->getData();
        res.insert(dataPartida);
    }

    return res;
}

void PartidaController::esTransmitidaEnVivo(bool transmitidaEnVivo) { this->transmitida = transmitidaEnVivo; }

set<DataJugador> PartidaController::obtenerJugadoresConSuscripcionActiva()
{
    UsuarioHandler *usuarioHandler = UsuarioHandler::getInstance();

    map<string, Usuario *> jugadoresConSuscActiva = usuarioHandler->obtenerJugadoresConSuscripcionActiva(this->videojuego);

    set<DataJugador> res;
    map<string, Usuario *>::iterator it;
    for (it = jugadoresConSuscActiva.begin(); it != jugadoresConSuscActiva.end(); it++)
    {
        Jugador *jugador = dynamic_cast<Jugador *>(it->second);
        DataJugador dataJugador = jugador->getData();
        res.insert(dataJugador);
    }

    return res;
}

void PartidaController::seleccionarVideojuego(string nombreVideojuego)
{
    VideojuegoHandler *videojuegoHandler = VideojuegoHandler::getInstance();

    this->videojuego = videojuegoHandler->obtenerVideojuegoPorId(nombreVideojuego);

    if (this->videojuego == nullptr)
    {
        throw invalid_argument("Error no hay videojuego con ese nombre, pruebe con otro ");
    }
}

void PartidaController::seleccionarJugador(string nickname)
{
    UsuarioHandler *usuarioHandler = UsuarioHandler::getInstance();

    bool existe = usuarioHandler->existeJugadorConNickname(nickname);

    if (existe)
    {
        this->participantes.insert(pair<string, Jugador *>(nickname, usuarioHandler->obtenerJugadorPorNickname(nickname)));
    }
}

void PartidaController::confirmarIniciarPartida(Fecha fechaInicio)
{

    int id = this->generarIdPartida();
    Fecha fechaFin;

    if (this->partidaAContinuar != nullptr)
    {
        dynamic_cast<Jugador *>(this->jugador)->crearPartidaIndividual(id, this->partidaAContinuar->getFechaInicio(), this->videojuego, dynamic_cast<Jugador *>(this->jugador), this->partidaAContinuar);
    }
    else if (this->partidaAContinuar == nullptr && participantes.size() == 0)
    {

        dynamic_cast<Jugador *>(this->jugador)->crearPartidaIndividual(id, fechaInicio, this->videojuego, dynamic_cast<Jugador *>(this->jugador), nullptr);
    }
    else
    {
        dynamic_cast<Jugador *>(this->jugador)->crearPartidaMultijugador(id, fechaInicio, fechaFin, this->videojuego, this->transmitida, dynamic_cast<Jugador *>(this->jugador), this->participantes);
    }

    this->jugador = nullptr;
    this->partidaAContinuar = nullptr;
    this->participantes.clear();
}

set<DataPartidaMultijugador> PartidaController::obtenerPartidasMultijugadorActivasDeJugador()
{
    UsuarioController *usuarioController = UsuarioController::getInstance();
    this->jugador = dynamic_cast<Jugador *>(usuarioController->getSesion());
    UsuarioHandler *usuarioHandler = UsuarioHandler::getInstance();
    set<DataPartidaMultijugador> res = usuarioHandler->obtenerPartidasMultijugadorActivasDeJugador(this->jugador);

    return res;
}

void PartidaController::abandonarPartida(int idPartida, Fecha fecha)
{
    UsuarioHandler *usuarioHandler = UsuarioHandler::getInstance();
    PartidaMultijugador *partidaMulti = dynamic_cast<PartidaMultijugador *>(usuarioHandler->obtenerPartidaPorId(idPartida));

    if (this->jugador)
    {
        partidaMulti->bajarParticipante(this->jugador, fecha);
        return;
    }

    throw invalid_argument("Ocurrió un error obteniendo el jugador.\n");
}

PartidaController::~PartidaController()
{
    this->jugador = nullptr;
    this->videojuego = nullptr;
    this->partidaAContinuar = nullptr;
    this->participantes.clear();
}
