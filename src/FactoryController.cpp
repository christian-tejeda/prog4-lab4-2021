#include <string>
#include <map>
#include <set>
#include <utility>

#include "../headers/FactoryController.h"

using namespace std;

FactoryController *FactoryController::instancia = nullptr;

FactoryController::FactoryController() {}

ISeleccionarEstadisticas *FactoryController::getISeleccionarEstadisticas() { return nullptr; }
IConsultarEstadisticas *FactoryController::getIConsultarEstadisticas() { return nullptr; }
ISuscribirseVideojuego *FactoryController::getISuscribirseVideojuego() { return nullptr; }
IIniciarSesion *FactoryController::getIIniciarSesion() { return nullptr; }
IAltaUsuario *FactoryController::getIAltaUsuario() { return nullptr; }

IIniciarPartida *FactoryController::getIIniciarPartida() { return nullptr; }
IAbandonarPartida *FactoryController::getIAbandonarPartida() { return nullptr; }
IFinalizarPartida *FactoryController::getIFinalizarPartida() { return nullptr; }

IAgregarCategoria *FactoryController::getIAgregarCategoria() { return nullptr; }
IVerInfoVideojuego *FactoryController::getIVerInfoVideojuego() { return nullptr; }
IAsignarPuntaje *FactoryController::getIAsignarPuntaje() { return nullptr; }
IEliminarVideojuego *FactoryController::getIEliminarVideojuego() { return nullptr; }
IPublicarVideojuego *FactoryController::getIPublicarVideojuego() { return nullptr; }

FactoryController::~FactoryController() {}
