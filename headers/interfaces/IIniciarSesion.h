#ifndef I_INICIAR_SESION_H
#define I_INICIAR_SESION_H

#include <string>
#include <set>
#include <utility>

#include "../datatypes/DataUsuario.h"

using namespace std;

class IIniciarSesion
{
public:
    virtual bool iniciarSesion(string email, string password) = 0;

    virtual void confirmarInicioSesion(string email, bool &jugador, bool &dev) = 0;

    virtual ~IIniciarSesion(){};
};

#endif