#include <string>
#include <map>
#include <set>
#include <utility>

#include "../headers/FactoryController.h"

using namespace std;

FactoryController *FactoryController::instancia = nullptr;

FactoryController::FactoryController() {}

FactoryController *FactoryController::getInstance()
{
    if (instancia == nullptr)
        instancia = new FactoryController();
    return instancia;
}

//Usuario Controller
ISeleccionarEstadisticas *FactoryController::getISeleccionarEstadisticas() { return UsuarioController::getInstance(); }
IConsultarEstadisticas *FactoryController::getIConsultarEstadisticas() { return UsuarioController::getInstance(); }
ISuscribirseVideojuego *FactoryController::getISuscribirseVideojuego() { return UsuarioController::getInstance(); }
IIniciarSesion *FactoryController::getIIniciarSesion() { return UsuarioController::getInstance(); }
IAltaUsuario *FactoryController::getIAltaUsuario() { return UsuarioController::getInstance(); }

//Partida Controller
IIniciarPartida *FactoryController::getIIniciarPartida() { return new PartidaController(); }
IAbandonarPartida *FactoryController::getIAbandonarPartida() { return new PartidaController(); }
IFinalizarPartida *FactoryController::getIFinalizarPartida() { return new PartidaController(); }

//Videojuego Controller
IAgregarCategoria *FactoryController::getIAgregarCategoria() { return new VideojuegoController(); }
IVerInfoVideojuego *FactoryController::getIVerInfoVideojuego() { return new VideojuegoController(); }
IAsignarPuntaje *FactoryController::getIAsignarPuntaje() { return new VideojuegoController(); }
IEliminarVideojuego *FactoryController::getIEliminarVideojuego() { return new VideojuegoController(); }
IPublicarVideojuego *FactoryController::getIPublicarVideojuego() { return new VideojuegoController(); }

FactoryController::~FactoryController() {}
