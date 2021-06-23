#ifndef USUARIO_CONTROLLER_H
#define USUARIO_CONTROLLER_H

#include "../../headers/datatypes/DataSuscripcionJugador.h"
#include "../../headers/entities/Desarrollador.h"
#include "../../headers/handlers/UsuarioHandler.h"
#include "../../headers/handlers/VideojuegoHandler.h"
#include "../../headers/utils/Fecha.h"

#include "../entities/Usuario.h"
#include "../entities/Videojuego.h"
#include "../interfaces/IAltaUsuario.h"
#include "../interfaces/IConsultarEstadisticas.h"
#include "../interfaces/IIniciarSesion.h"
#include "../interfaces/ISeleccionarEstadisticas.h"
#include "../interfaces/ISuscribirseVideojuego.h"

class UsuarioController : public ISeleccionarEstadisticas,
                          public IConsultarEstadisticas,
                          public ISuscribirseVideojuego,
                          public IIniciarSesion,
                          public IAltaUsuario
{
private:
  static UsuarioController *instancia;

  Usuario *sesion;
  DataDesarrollador *dataDesarrollador;
  DataJugador *dataJugador;
  Videojuego *videojuego;
  TipoPeriodoValidez validezSuscripcion;
  TipoMetodoPago metodoPago;
  //set<DataEstadistica *> estadisticas;
  UsuarioController();
  ~UsuarioController();

public:
  static UsuarioController *getInstance();

  Usuario *getSesion();
  DataDesarrollador *getDataDesarrollador();
  DataJugador *getDataJugador();
  Videojuego *getVideojuego();
  TipoMetodoPago getMetodoPago();

  /// ISeleccionarEstadisticas
  std::set<DataEstadistica *> listarEstadisticas();
 void seleccionarEstadisticas(set<TipoEstadistica> estadisticas);

  /// IConsultarEstadisticas
  set<DataVideojuego *> obtenerVideojuegosPublicadosPorDesarrollador();
  set<DataEstadistica *> calcularEstadisticas(string nomVideojuego);

  /// ISuscribirseVideojuego
  std::set<DataSuscripcionJugador *> obtenerSuscripciones(Fecha *f);
  void seleccionarVideojuego(string nombreVideojuego);
  void cancelarSuscripcion();
  void contratarSuscripcion(TipoPeriodoValidez validez,
                            TipoMetodoPago metodoPago);
  void confirmarSuscripcion(bool confirmar, Fecha *f);

  /// IIniciarSesion
  bool iniciarSesion(string mail, string password);
  void confirmarInicioSesion(bool confirmar, string mail, bool &jg, bool &dev);

  /// IAltaUsuario
  void ingresarDatosJugador(DataJugador *dataJugador);
  void ingresarDatosDesarrollador(DataDesarrollador *dataDesarrollador);
  void confirmarAltaUsuario(bool confirmar);

  static void releaseInstance();
};

#endif