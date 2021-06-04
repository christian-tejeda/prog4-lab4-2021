#ifndef PARTIDA_CONTROLLER_H
#define PARTIDA_CONTROLLER_H

#include "../interfaces/IPartidaController.h"
#include "../entities/Usuario.h"
#include "../entities/Videojuego.h"
#include "../entities/PartidaIndividual.h"

class PartidaController : public IPartidaController
{ //singleton
private:
    PartidaController *instancia;

    Usuario *jg;                          //se borra la ref al final del CU
    Videojuego *vj;                       //se borra la ref al final del CU
    PartidaIndividual *partidaAContinuar; //se borra la ref al final del CU
    bool transmitida;
    map<string, Jugador *> participantes; //se borra la ref al final del CU

public:
    PartidaController();
    //op de singleton
    static PartidaController *getInstance();
    //Getters
    Usuario *getJugador();
    Videojuego *getVideojuego();
    PartidaIndividual *getPartidaAContinuar();
    Jugador *getParticipantePorNickname(string nick);
    //ops de interface
    set<DataPartida *> obtenerPartidasSinFinalizarDeJugador();
    void finalizarPartida(int idPartida);
    void seleccionarPartidaAContinuar(int id);
    set<DataVideojuego *> obtenerVideojuegosDeJugadorConSuscripcionActiva();
    set<DataPartidaIndividual *> obtenerPartidasFinalizadasDeJugador();
    void esTransmitidaEnVivo(bool transmitidaEnVivo);
    set<DataJugador *> obtenerJugadoresConSuscripcionActiva();
    void seleccionarVideojuego(string nombreVideojuego);
    void seleccionarJugador(string nickname);
    void confirmarIniciarPartida(bool confirmar);
    set<DataPartidaMultijugador *> obtenerPartidasMultijugadorActivasDeJugador();
    void abandonarPartida(int idPartida);

    ~PartidaController();
};

#endif