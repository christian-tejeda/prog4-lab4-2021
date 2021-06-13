#ifndef I_ABANDONAR_PARTIDA_H
#define I_ABANDONAR_PARTIDA_H

#include "../datatypes/DataPartidaMultijugador.h"

class IAbandonarPartida
{
public:
    virtual set<DataPartidaMultijugador *> obtenerPartidasMultijugadorActivasDeJugador() = 0;
    virtual void abandonarPartida(int idPartida) = 0;

    virtual ~IAbandonarPartida(){};
};

#endif