

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
    partidaAContinuar = dynamic_cast<Jugador*>(this->jg)->obtenerPartida(id);
    if(partidaAContinuar == nullptr){
        throw std::invalid_argument("Error. Id de partida no valido, intente con otro ");
    }
}
set<DataVideojuego *> PartidaController::obtenerVideojuegosDeJugadorConSuscripcionActiva()//pronta, sin compilar
{
    set<DataVideojuego*> res;
    UsuarioController * uc;
    uc = uc->getInstance();
    jg = dynamic_cast<Jugador*>(uc->getSesion());
    map<std::string, Videojuego*> vjs = dynamic_cast<Jugador*>(jg)->obtenerVideojuegosConSuscripcionActiva();
    map<std::string, Videojuego*>::iterator it;
    for(it = vjs.begin();it !=vjs.end(); it++){
        Videojuego* vj= it->second;
        DataVideojuego dvj2 = vj->getData();
        DataVideojuego *dvj = &dvj2;
        res.insert(dvj);
    }
    vjs.clear();
    return res;
}
set<DataPartidaIndividual *> PartidaController::obtenerPartidasFinalizadasDeJugador()//cu iniciar partida, pronta sin compilar
{
    set<DataPartidaIndividual *> res;
    map<int,PartidaIndividual *> parti = dynamic_cast<Jugador *>(this->jg)->obtenerPartidasFinalizadas();
    map<int,PartidaIndividual *>::iterator it;
    for(it = parti.begin();it !=parti.end(); it++){
        PartidaIndividual* pi = it->second;
        DataPartidaIndividual* dpi = dynamic_cast<DataPartidaIndividual*>(pi->getData());
        res.insert(dpi);
    }
    parti.clear();
    return res;
}
void PartidaController::esTransmitidaEnVivo(bool transmitidaEnVivo)//pronta, sin compilar
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
        DataUsuario * dtjg;
        dtjg = jgaux->getData();
        res.insert(dynamic_cast<DataJugador*>(dtjg));
    }
    return res;
}
void PartidaController::seleccionarVideojuego(string nombreVideojuego)
{
    VideojuegoHandler* vjh = vjh->getInstance();
    this->vj = vjh->obtenerVideojuegoPorId(nombreVideojuego);
    if(this->vj == nullptr){
        throw std::invalid_argument("Error no hay videojuego con ese nombre, pruebe con otro ");
    }
}
void PartidaController::seleccionarJugador(string nickname)
{
    UsuarioHandler* uH = uH->getInstance();
    bool hayJugador = uH->existeJugadorConNickname(nickname);
    if(hayJugador){
        this->participantes.insert({nickname,uH->obtenerJugadorPorNickname(nickname)});
    }
}
void PartidaController::confirmarIniciarPartida(bool confirmar)
{
    if(confirmar){
        Fecha  fechaDeIinicio = Fecha(1,1,1,1,1);
        Fecha * fechaFin = nullptr;
        if(this->partidaAContinuar != nullptr){//va a continuar una partida indi
            dynamic_cast<Jugador*>(this->jg)->crearPartidaIndividual(this->partidaAContinuar->getId(),this->partidaAContinuar->getFechaInicio(),this->vj,dynamic_cast<Jugador*>(this->jg),this->partidaAContinuar);
        }
        else if(this->partidaAContinuar == nullptr && participantes.size() == 0) {
            dynamic_cast<Jugador*>(this->jg)->crearPartidaIndividual(this->partidaAContinuar->getId(),fechaDeIinicio,this->vj,dynamic_cast<Jugador*>(this->jg),nullptr);
            }
        else{
            int id =this->generarIdPartida();
            dynamic_cast<Jugador*>(this->jg)->crearPartidaMultijugador(id,fechaDeIinicio,nullptr,this->vj,this->transmitida,dynamic_cast<Jugador*>(this->jg),this->participantes);
        }
    }
    this->jg = nullptr;
    this->partidaAContinuar = nullptr;
    this->participantes.clear();
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


int PartidaController::generarIdPartida(){
    idPartida = idPartida + 1;
    return idPartida - 1;
}

int PartidaController::idPartida = 0;