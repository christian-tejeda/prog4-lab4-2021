#ifndef I_INICIAR_PARTIDA_H
#define I_INICIAR_PARTIDA_H

#include <set>
#include <string>

#include "../datatypes/DataPartidaIndividual.h"
#include "../datatypes/DataJugador.h"

using namespace std;

class IIniciarPartida
{ //interface
public:
    virtual void seleccionarPartidaAContinuar(int id) = 0;
    virtual set<DataVideojuego *> obtenerVideojuegosDeJugadorConSuscripcionActiva(Fecha *f) = 0;
    virtual set<DataPartidaIndividual *> obtenerPartidasFinalizadasDeJugador() = 0;
    virtual void esTransmitidaEnVivo(bool transmitidaEnVivo) = 0;
    virtual set<DataJugador *> obtenerJugadoresConSuscripcionActiva() = 0;
    virtual void seleccionarVideojuego(string nombreVideojuego) = 0;
    virtual void seleccionarJugador(string nickname) = 0;
    virtual void confirmarIniciarPartida(bool confirmar, Fecha *fechainicio) = 0;

    virtual ~IIniciarPartida(){};
};

#endif