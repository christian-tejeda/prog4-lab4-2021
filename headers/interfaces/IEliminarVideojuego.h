#ifndef I_ELIMINAR_VIDEOJUEGO_H
#define I_ELIMINAR_VIDEOJUEGO_H

#include "../datatypes/DataVideojuego.h"

class IEliminarVideojuego
{
public:
    virtual set<DataVideojuego> obtenerVideojuegosPublicadosPorDesarrolladorConPartidasFinalizadas() = 0;

    virtual void seleccionarVideojuego(string nombreVideojuego) = 0;

    virtual void confirmarEliminarVideojuego() = 0;

    virtual ~IEliminarVideojuego(){};
};

#endif