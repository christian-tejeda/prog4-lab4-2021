#ifndef PARTIDA_CONTROLLER_H
#define PARTIDA_CONTROLLER_H

#include "../interfaces/IIniciarPartida.h"
#include "../interfaces/IAbandonarPartida.h"
#include "../interfaces/IFinalizarPartida.h"
#include "../entities/Usuario.h"
#include "../entities/Videojuego.h"
//#include "../entities/PartidaIndividual.h"

class PartidaController : public IIniciarPartida, public IAbandonarPartida, public IFinalizarPartida
{
private:
    static int idPartida;
    //Usuario *jg; //se borra la ref al final del CU
    Jugador *jg;                          //se borra la ref al final del CU
    Videojuego *vj;                       //se borra la ref al final del CU
    PartidaIndividual *partidaAContinuar; //se borra la ref al final del CU
    bool transmitida;
    map<string, Jugador *> participantes; //se borra la ref al final del CU

public:
    PartidaController();

    //Getters
    Jugador *getJugador();
    Videojuego *getVideojuego();
    PartidaIndividual *getPartidaAContinuar();
    Jugador *getParticipantePorNickname(string nick);

    //ops de IIniciarPartida
    Fecha getFecha();
    int generarIdPartida();
    void seleccionarPartidaAContinuar(int id);
    set<DataVideojuego *> obtenerVideojuegosDeJugadorConSuscripcionActiva();
    set<DataPartidaIndividual *> obtenerPartidasFinalizadasDeJugador();
    void esTransmitidaEnVivo(bool transmitidaEnVivo);
    set<DataJugador *> obtenerJugadoresConSuscripcionActiva();
    void seleccionarVideojuego(string nombreVideojuego);
    void seleccionarJugador(string nickname);
    void confirmarIniciarPartida(bool confirmar, Fecha *fechainicio);

    //ops de IAbandonarPartida
    set<DataPartidaMultijugador *> obtenerPartidasMultijugadorActivasDeJugador();
    void abandonarPartida(int idPartida, Fecha *f);

    //ops de IFinalizarPartida
    set<DataPartida *> obtenerPartidasSinFinalizarDeJugador();
    void finalizarPartida(int idPartida, Fecha *fecha);

    ~PartidaController();
};

#endif