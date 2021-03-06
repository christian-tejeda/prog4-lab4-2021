

#include <string>
#include <map>
#include <set>
#include <utility>

#include "../../headers/controllers/PartidaController.h"
#include "../../headers/controllers/UsuarioController.h"
#include "../../headers/utils/Fecha.h"
#include "../../headers/handlers/VideojuegoHandler.h"
#include "../../headers/entities/Jugador.h"
#include "../../headers/handlers/UsuarioHandler.h"

using namespace std;

PartidaController::PartidaController()
{
    this->jg = nullptr;
    this->vj = nullptr;
    this->partidaAContinuar = nullptr;
}

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
    UsuarioController *UC;
    UC = UC->getInstance();
    Jugador *jugador = dynamic_cast<Jugador *>(UC->getSesion());
    this->jg = jugador;
    set<DataPartida *> res;
    if (jugador != nullptr)
    {
        map<int, Partida *> oracle = jugador->obtenerPartidasSinFinalizar();
        map<int, Partida *>::iterator it;
        for (it = oracle.begin(); it != oracle.end(); it++)
        {
            DataPartida *actual = it->second->getData();
            //if (actual->getFechaFin()!=nullptr){ no es necesario solo devuelve finalizadas
            res.insert(actual);
            //}
        }
    }
    return res;
}

void PartidaController::finalizarPartida(int idPartida, Fecha *fecha)
{
    //Fecha fecha=getFecha();
    Jugador *jugador = dynamic_cast<Jugador *>(this->jg);
    if (jugador != nullptr)
    {
        jugador->finalizarPartida(idPartida, fecha);
    }
}
void PartidaController::seleccionarPartidaAContinuar(int id)
{
    partidaAContinuar = dynamic_cast<Jugador *>(this->jg)->obtenerPartida(id);
    if (partidaAContinuar == nullptr)
    {
        throw std::invalid_argument("Error. Id de partida no valido, intente con otro ");
    }
}
set<DataVideojuego *> PartidaController::obtenerVideojuegosDeJugadorConSuscripcionActiva(Fecha *f) //pronta, sin compilar
{
    set<DataVideojuego *> res;
    UsuarioController *uc;
    uc = uc->getInstance();
    jg = dynamic_cast<Jugador *>(uc->getSesion());
    map<std::string, Videojuego *> vjs = jg->obtenerVideojuegosConSuscripcionActiva(f);
    map<std::string, Videojuego *>::iterator it;
    for (it = vjs.begin(); it != vjs.end(); it++)
    {
        Videojuego *vj = it->second;
        DataVideojuego *dvj = vj->getData();
        //DataVideojuego *dvj = &dvj2;
        res.insert(dvj);
    }
    vjs.clear();
    return res;
}
set<DataPartidaIndividual *> PartidaController::obtenerPartidasFinalizadasDeJugador() //cu iniciar partida, pronta sin compilar
{
    set<DataPartidaIndividual *> res;
    map<int, PartidaIndividual *> parti = dynamic_cast<Jugador *>(this->jg)->obtenerPartidasFinalizadas();
    map<int, PartidaIndividual *>::iterator it;
    for (it = parti.begin(); it != parti.end(); it++)
    {
        PartidaIndividual *pi = it->second;
        DataPartidaIndividual *dpi = dynamic_cast<DataPartidaIndividual *>(pi->getData());
        res.insert(dpi);
    }
    parti.clear();
    return res;
}
void PartidaController::esTransmitidaEnVivo(bool transmitidaEnVivo) //pronta, sin compilar
{
    this->transmitida = transmitidaEnVivo;
}
set<DataJugador *> PartidaController::obtenerJugadoresConSuscripcionActiva()
{
    UsuarioHandler *uH = uH->getInstance();
    map<string, Usuario *> jgCS = uH->obtenerJugadoresConSuscripcionActiva(this->vj);
    map<string, Usuario *>::iterator it;
    set<DataJugador *> res;
    for (it = jgCS.begin(); it != jgCS.end(); it++)
    {
        Jugador *jgaux = dynamic_cast<Jugador *>(it->second);
        DataUsuario *dtjg;
        dtjg = jgaux->getData();
        res.insert(dynamic_cast<DataJugador *>(dtjg));
        //std::cout << dynamic_cast<DataJugador *>(dtjg)->getNickname(); error en getnickname
        //std::cout << "metio un data jugador pcont"; paso
    }
    return res;
}
void PartidaController::seleccionarVideojuego(string nombreVideojuego)
{
    VideojuegoHandler *vjh = vjh->getInstance();
    this->vj = vjh->obtenerVideojuegoPorId(nombreVideojuego);
    if (this->vj == nullptr)
    {
        throw std::invalid_argument("Error no hay videojuego con ese nombre, pruebe con otro ");
    }
}
void PartidaController::seleccionarJugador(string nickname)
{
    UsuarioHandler *uH = uH->getInstance();
    bool hayJugador = uH->existeJugadorConNickname(nickname);
    if (hayJugador)
    {
        this->participantes.insert(std::pair<string, Jugador *>(nickname, uH->obtenerJugadorPorNickname(nickname)));
    }
}
void PartidaController::confirmarIniciarPartida(bool confirmar, Fecha *fechainicio)
{
    if (confirmar)
    {
        int id = this->generarIdPartida();
        Fecha *fechaFin = nullptr;
        if (this->partidaAContinuar != nullptr)
        { //va a continuar una partida indi
            dynamic_cast<Jugador *>(this->jg)->crearPartidaIndividual(id, this->partidaAContinuar->getFechaInicio(), this->vj, dynamic_cast<Jugador *>(this->jg), this->partidaAContinuar);
        }
        else if (this->partidaAContinuar == nullptr && participantes.size() == 0)
        {

            dynamic_cast<Jugador *>(this->jg)->crearPartidaIndividual(id, *fechainicio, this->vj, dynamic_cast<Jugador *>(this->jg), nullptr);
        }
        else
        {
            dynamic_cast<Jugador *>(this->jg)->crearPartidaMultijugador(id, *fechainicio, nullptr, this->vj, this->transmitida, dynamic_cast<Jugador *>(this->jg), this->participantes);
        }
    }
    this->jg = nullptr;
    this->partidaAContinuar = nullptr;
    this->participantes.clear();
}
set<DataPartidaMultijugador *> PartidaController::obtenerPartidasMultijugadorActivasDeJugador()
{
    UsuarioController *uc = UsuarioController::getInstance();
    this->jg = dynamic_cast<Jugador *>(uc->getSesion());
    UsuarioHandler *uh = UsuarioHandler::getInstance();
    set<DataPartidaMultijugador *> res = uh->obtenerPartidasMultijugadorActivasDeJugador(jg);

    return res;
}

void PartidaController::abandonarPartida(int idPartida, Fecha *f)
{
    UsuarioHandler *uh = UsuarioHandler::getInstance();
    PartidaMultijugador *prt = dynamic_cast<PartidaMultijugador *>(uh->obtenerPartidaPorId(idPartida));
    if (this->jg)
    {
        prt->bajarParticipante(this->jg, f);
    }
    else
        throw std::invalid_argument("Ocurri?? un error obteniendo el jugador.\n");
}

PartidaController::~PartidaController()
{
    this->jg = nullptr;
    this->vj = nullptr;
    this->partidaAContinuar = nullptr;
    this->participantes.clear();
}
//PartidaController::~PartidaController() {}

int PartidaController::generarIdPartida()
{
    idPartida = idPartida + 1;
    return idPartida - 1;
}

int PartidaController::idPartida = 6;
