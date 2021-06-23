#ifndef USUARIO_CONTROLLER_H
#define USUARIO_CONTROLLER_H

#include "../../headers/datatypes/DataSuscripcionJugador.h"
#include "../../headers/entities/Desarrollador.h"
#include "../../headers/entities/ContratoSuscripcion.h"
#include "../../headers/entities/Jugador.h"
#include "../../headers/utils/Fecha.h"
#include "../entities/Usuario.h"

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
  DataDesarrollador dataDesarrollador;
  DataJugador dataJugador;
  Videojuego *videojuego;
  TipoPeriodoValidez validezSuscripcion;
  TipoMetodoPago metodoPago;

  UsuarioController();

  ~UsuarioController();

public:
  static UsuarioController *getInstance();

  Usuario *getSesion();

  DataDesarrollador getDataDesarrollador();

  DataJugador getDataJugador();

  Videojuego *getVideojuego();

  TipoMetodoPago getMetodoPago();

  set<DataEstadistica> obtenerEstadisticas();

  void seleccionarEstadisticas(set<TipoEstadistica> estadisticas);

  set<DataVideojuego> obtenerVideojuegosPublicadosPorDesarrollador();

  set<DataEstadistica> calcularEstadisticas(string nombreVideojuego);

  set<DataSuscripcionJugador> obtenerSuscripciones();

  void seleccionarVideojuego(string nombreVideojuego);

  void cancelarSuscripcion();

  void contratarSuscripcion(TipoPeriodoValidez validez, TipoMetodoPago metodoPago);

  void confirmarSuscripcion(Fecha fecha);

  bool iniciarSesion(string email, string password);

  void confirmarInicioSesion(string email, bool &jugador, bool &desarrollador);

  void ingresarDatosJugador(DataJugador dataJugador);

  void ingresarDatosDesarrollador(DataDesarrollador dataDesarrollador);

  void confirmarAltaUsuario();

  static void releaseInstance();
};

#endif