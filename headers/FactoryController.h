#ifndef FACTORY_CONTROLLER_H
#define FACTORY_CONTROLLER_H

#include "controllers/PartidaController.h"
#include "controllers/UsuarioController.h"
#include "controllers/VideojuegoController.h"

#include <map>
#include <set>
#include <string>
#include <utility>

using namespace std;

class FactoryController {

private:
  static FactoryController *instancia;
  FactoryController();
  ~FactoryController();

public:
  static FactoryController *getInstance();

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

  static void releaseInstance();
};

#endif