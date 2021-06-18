#ifndef USUARIO_CONTROLLER_H
#define USUARIO_CONTROLLER_H

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
                          public IAltaUsuario { // singleton
private:
  static UsuarioController *instancia;

  Usuario *sesion;
  DataDesarrollador
      *dataDesarrollador;   // se borra la instacnia al terminar el CU
  DataJugador *dataJugador; // se borra la instacnia al terminar el CU
  Videojuego *videojuego;   // se borra la referencia
  TipoPeriodoValidez validezSuscripcion;
  TipoMetodoPago metodoPago;
  UsuarioController();
  ~UsuarioController();

public:
  // op de singleton
  static UsuarioController *getInstance();

  // Getters
  Usuario *getSesion();
  DataDesarrollador *getDataDesarrollador();
  DataJugador *getDataJugador();
  Videojuego *getVideojuego();
  TipoMetodoPago getMetodoPago();

  // ops de ISeleccionarEstadisticas
  std::set<DataEstadistica *> listarEstadisticas();
  void seleccionarEstadisticas(std::set<std::string> nombresEstadisticas);

  // ops de IConsultarEstadisticas
  set<DataVideojuego *> obtenerVideojuegosPublicadosPorDesarrollador();
  set<DataEstadistica *> calcularEstadisticas(string nomVideojuego);

  // ops de ISuscribirseVideojuego
  std::set<DataSuscripcionJugador *> obtenerSuscripciones();
  void seleccionarVideojuego(string nombreVideojuego);
  void cancelarSuscripcion();
  void contratarSuscripcion(TipoPeriodoValidez validez,
                            TipoMetodoPago metodoPago);
  void confirmarSuscripcion(bool confirmar);

  // ops de IIniciarSesion
  bool iniciarSesion(string mail, string password);
  void confirmarInicioSesion(bool confirmar, string mail, bool &jg, bool &dev);

  // ops de IAltaUsuario
  void ingresarDatosJugador(DataJugador *dataJugador);
  void ingresarDatosDesarrollador(DataDesarrollador *dataDesarrollador);
  void confirmarAltaUsuario(bool confirmar);

  static void releaseInstance();
};

#endif