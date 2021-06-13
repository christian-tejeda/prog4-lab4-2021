#ifndef I_ALTA_USUARIO_H
#define I_ALTA_USUARIO_H

#include "../datatypes/DataJugador.h"
#include "../datatypes/DataDesarrollador.h"

class IAltaUsuario
{
public:
    virtual void ingresarDatosJugador(DataJugador *dataJugador) = 0;
    virtual void ingresarDatosDesarrollador(DataDesarrollador *dataDesarrollador) = 0;
    virtual void confirmarAltaUsuario(bool confirmar) = 0;

    virtual ~IAltaUsuario(){};
};

#endif