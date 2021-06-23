#ifndef PARTIDA_CONTROLLER_H
#define PARTIDA_CONTROLLER_H

#include "../interfaces/IIniciarPartida.h"
#include "../interfaces/IAbandonarPartida.h"
#include "../interfaces/IFinalizarPartida.h"
#include "../entities/Videojuego.h"
#include "../entities/PartidaIndividual.h"

class PartidaController : public IIniciarPartida, public IAbandonarPartida, public IFinalizarPartida
{
private:
    static int idPartida;

    Jugador *jugador;
    Videojuego *videojuego;
    PartidaIndividual *partidaAContinuar;
    bool transmitida;
    map<string, Jugador *> participantes;

public:
    PartidaController();

    Jugador *getJugador();

    Videojuego *getVideojuego();

    PartidaIndividual *getPartidaAContinuar();

    Fecha getFecha();

    int generarIdPartida();

    void seleccionarPartidaAContinuar(int idPartida);

    set<DataVideojuego> obtenerVideojuegosDeJugadorConSuscripcionActiva(Fecha fecha);

    set<DataPartidaIndividual> obtenerPartidasFinalizadasDeJugador();

    void esTransmitidaEnVivo(bool transmitidaEnVivo);

    set<DataJugador> obtenerJugadoresConSuscripcionActiva();

    void seleccionarVideojuego(string nombreVideojuego);

    void seleccionarJugador(string nickname);

    void confirmarIniciarPartida(Fecha fechaInicio);

    set<DataPartidaMultijugador> obtenerPartidasMultijugadorActivasDeJugador();

    void abandonarPartida(int idPartida, Fecha fecha);

    set<DataPartida> obtenerPartidasSinFinalizarDeJugador();

    void finalizarPartida(int idPartida, Fecha fecha);

    ~PartidaController();
};

#endif