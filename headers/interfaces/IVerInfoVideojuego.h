#ifndef I_VER_INFO_VIDEOJUEGO_H
#define I_VER_INFO_VIDEOJUEGO_H

#include "../datatypes/DataVideojuego.h"
#include "../entities/Usuario.h"

class IVerInfoVideojuego
{
public:
    virtual set<DataVideojuego *> obtenerVideojuegos() = 0;
    virtual DataVideojuego *obtenerDataVideojuego(string nombre) = 0;

    virtual ~IVerInfoVideojuego(){};
};

#endif