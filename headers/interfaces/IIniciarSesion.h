#ifndef I_INICIAR_SESION_H
#define I_INICIAR_SESION_H

#include <string>
#include <set>
#include <utility>

#include "../datatypes/DataUsuario.h"

using namespace std;

class IIniciarSesion
{ //interface
public:
    // virtual set<DataPartidaMultijugador *> obtenerPartidasMultijugadorActivasDeJugador() = 0;
    // virtual void seleccionarPartida(int id) = 0;
    // virtual void seleccionarVideojuego(string nombreVideojuego) = 0;
    virtual bool iniciarSesion(DataUsuario *dataUsuario) = 0;
    virtual void confirmarInicioSesion(bool confirmar) = 0;

    virtual ~IIniciarSesion() {}
};

#endif