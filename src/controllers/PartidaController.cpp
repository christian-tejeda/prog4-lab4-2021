

#include <string>
#include <map>
#include <set>
#include <utility>

#include "../../headers/controllers/PartidaController.h"
#include "../../headers/utils/Fecha.h"
#include "../../headers/controllers/UsuarioController.h"
#include "../../headers/handlers/VideojuegoHandler.h"
#include "../../headers/entities/Jugador.h"
#include "../../headers/handlers/UsuarioHandler.h"


using namespace std;


PartidaController::PartidaController() {}

//op de singleton
//PartidaController *PartidaController::getInstance() {}

//Getters
Usuario *PartidaController::getJugador()
{
    return nullptr;
}
Videojuego *PartidaController::getVideojuego()
{
    return nullptr;
}
PartidaIndividual *PartidaController::getPartidaAContinuar()
{
    return nullptr;
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
    partidaAContinuar = dynamic_cast<Jugador*>(jg)->obtenerPartida(id);
}
set<DataVideojuego *> PartidaController::obtenerVideojuegosDeJugadorConSuscripcionActiva()
{
    set<DataVideojuego*> res;
    //res.insert(nullptr);
    //return res;
    UsuarioController * uc;
    uc->getInstance();
    Jugador* jg = dynamic_cast<Jugador*>(uc->getSesion());
    map<std::string, Videojuego*> vjs = jg->obtenerVideojuegosConSuscripcionActiva();
    map<std::string, Videojuego*>::iterator it;
    for(it = vjs.begin();it !=vjs.end(); it++){
        Videojuego* vj= it->second;
        DataVideojuego dvj2 = vj->getData();
        DataVideojuego *dvj = &dvj2;
        res.insert(dvj);
    }
    return res;
}
set<DataPartidaIndividual *> PartidaController::obtenerPartidasFinalizadasDeJugador()
{
    set<DataPartidaIndividual *> res;
    Jugador *jg = dynamic_cast<Jugador *>(jg);
    map<int,PartidaIndividual *> parti = jg->obtenerPartidasFinalizadas();
    map<int,PartidaIndividual *>::iterator it;
    for(it = parti.begin();it !=parti.end(); it++){
        PartidaIndividual* pi = it->second;
        DataPartidaIndividual* dpi = dynamic_cast<DataPartidaIndividual*>(pi->getData());
        res.insert(dpi);
    }
}
void PartidaController::esTransmitidaEnVivo(bool transmitidaEnVivo)
{
    this->transmitida = transmitidaEnVivo;
}
set<DataJugador *> PartidaController::obtenerJugadoresConSuscripcionActiva()
{
    UsuarioHandler * uH = uH->getInstance();
    map<string, Usuario *> jgCS = uH->obtenerJugadoresConSuscripcionActiva(this->vj);
    map<string, Usuario*>::iterator it;
    set<DataJugador*> res;
    for(it = jgCS.begin();it !=jgCS.end(); it++){
        Jugador *jgaux= dynamic_cast<Jugador*>(it->second);
        DataUsuario * dtjg = new DataJugador;
        dtjg = jgaux->getData();
        res.insert(dynamic_cast<DataJugador*>(dtjg));
    }
    return res;
}
void PartidaController::seleccionarVideojuego(string nombreVideojuego)
{
    VideojuegoHandler* vjh = vjh->getInstance();
    vj = vjh->obtenerVideojuegoPorId(nombreVideojuego);
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
