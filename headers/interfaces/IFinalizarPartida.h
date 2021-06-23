#ifndef I_FINALIZAR_PARTIDA_H
#define I_FINALIZAR_PARTIDA_H

#include "../datatypes/DataPartida.h"

class IFinalizarPartida
{
public:
    virtual set<DataPartida> obtenerPartidasSinFinalizarDeJugador() = 0;

    virtual void finalizarPartida(int idPartida, Fecha fecha) = 0;

    virtual ~IFinalizarPartida(){};
};

#endif