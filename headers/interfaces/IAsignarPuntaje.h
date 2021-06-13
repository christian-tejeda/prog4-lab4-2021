#ifndef I_ASIGNAR_PUNTAJE_H
#define I_ASIGNAR_PUNTAJE_H

#include "../datatypes/DataVideojuego.h"

class IAsignarPuntaje
{
public:
    virtual set<DataVideojuego *> obtenerVideojuegos() = 0;
    virtual void puntuarVideojuego(string nombre, int puntaje) = 0;

    virtual ~IAsignarPuntaje(){};
};

#endif