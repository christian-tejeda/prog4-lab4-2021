#ifndef I_PARTIDA_CONTROLLER_H
#define I_PARTIDA_CONTROLLER_H

#include <set>
#include <string>

//#include "../datatypes/DataPartida.h"
#include "../datatypes/DataPartidaIndividual.h"
#include "../datatypes/DataPartidaMultijugador.h"
#include "../datatypes/DataJugador.h"

using namespace std;

class IPartidaController
{ //interface
public:
    virtual set<DataPartida *> obtenerPartidasSinFinalizarDeJugador() = 0;
    virtual void finalizarPartida(int idPartida) = 0;
    virtual void seleccionarPartidaAContinuar(int id) = 0;
    virtual set<DataVideojuego *> obtenerVideojuegosDeJugadorConSuscripcionActiva() = 0;
    virtual set<DataPartidaIndividual *> obtenerPartidasFinalizadasDeJugador() = 0;
    virtual void esTransmitidaEnVivo(bool transmitidaEnVivo) = 0;
    virtual set<DataJugador *> obtenerJugadoresConSuscripcionActiva() = 0;
    virtual void seleccionarVideojuego(string nombreVideojuego) = 0;
    virtual void seleccionarJugador(string nickname) = 0;
    virtual void confirmarIniciarPartida(bool confirmar) = 0;
    virtual set<DataPartidaMultijugador *> obtenerPartidasMultijugadorActivasDeJugador() = 0;
    virtual void abandonarPartida(int idPartida) = 0;

    virtual ~IPartidaController() {}
};

#endif