#ifndef FACTORY_CONTROLLER_H
#define FACTORY_CONTROLLER_H

#include <string>
#include <utility>
#include "controllers/UsuarioController.h"
#include "controllers/PartidaController.h"
#include "controllers/VideojuegoController.h"

using namespace std;

class FactoryController
{
    //singleton
private:
    static FactoryController *instancia;

public:
    FactoryController();
    //op de singleton
    static FactoryController *getInstance();

    //op de factory
    ISeleccionarEstadisticas *getISeleccionarEstadisticas();
    IConsultarEstadisticas *getIConsultarEstadisticas();
    ISuscribirseVideojuego *getISuscribirseVideojuego();
    IIniciarSesion *getIIniciarSesion();
    IAltaUsuario *getIAltaUsuario();

    IIniciarPartida *getIIniciarPartida();
    IAbandonarPartida *getIAbandonarPartida();
    IFinalizarPartida *getIFinalizarPartida();

    IAgregarCategoria *getIAgregarCategoria();
    IVerInfoVideojuego *getIVerInfoVideojuego();
    IAsignarPuntaje *getIAsignarPuntaje();
    IEliminarVideojuego *getIEliminarVideojuego();
    IPublicarVideojuego *getIPublicarVideojuego();

    ~FactoryController();
};

#endif