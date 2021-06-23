#include "../../headers/controllers/UsuarioController.h"
#include "../../headers/handlers/UsuarioHandler.h"
#include "../../headers/handlers/VideojuegoHandler.h"

UsuarioController *UsuarioController::instancia = nullptr;

UsuarioController::UsuarioController()
{
  this->sesion = nullptr;
  this->videojuego = nullptr;
}

UsuarioController *UsuarioController::getInstance()
{
  if (instancia == nullptr)
    instancia = new UsuarioController();

  return instancia;
}

Usuario *UsuarioController::getSesion() { return this->sesion; }

DataDesarrollador UsuarioController::getDataDesarrollador() { return this->dataDesarrollador; }

DataJugador UsuarioController::getDataJugador() { return this->dataJugador; }

Videojuego *UsuarioController::getVideojuego() { return this->videojuego; }

TipoMetodoPago UsuarioController::getMetodoPago() { return this->metodoPago; }

set<DataEstadistica> UsuarioController::obtenerEstadisticas()
{
  set<DataEstadistica> res;

  for (int tipoEstadistica = horasJugadas; tipoEstadistica != Last; tipoEstadistica++)
  {
    TipoEstadistica tipo = static_cast<TipoEstadistica>(tipoEstadistica);
    DataEstadistica dataEstadistica = DataEstadistica(tipo, 3.14);
    res.insert(dataEstadistica);
  }

  return res;
}

void UsuarioController::seleccionarEstadisticas(set<TipoEstadistica> estadisticas)
{
  set<TipoEstadistica>::iterator it;

  for (it = estadisticas.begin(); it != estadisticas.end(); it++)
  {
    TipoEstadistica tipoEstadistica = *it;
    Desarrollador *dev = dynamic_cast<Desarrollador *>(this->sesion);
    dev->agregarEstadisticaDeInteres(tipoEstadistica);
  }
}

void UsuarioController::ingresarDatosJugador(DataJugador dataJugador)
{

  UsuarioHandler *usuarioHandler = UsuarioHandler::getInstance();
  bool existeNick = usuarioHandler->existeJugadorConNickname(dataJugador.getNickname());

  if (!existeNick)
  {
    this->dataJugador = dataJugador;
    return;
  }

  throw invalid_argument("Error: Ya existe un jugador con ese nickname.");
}

void UsuarioController::ingresarDatosDesarrollador(DataDesarrollador dataDesarrollador) { this->dataDesarrollador = dataDesarrollador; }

void UsuarioController::confirmarAltaUsuario()
{
  UsuarioHandler *usuarioHandler = UsuarioHandler::getInstance();

  DataUsuario dataUsuario;
  if (this->dataJugador != DataJugador())
  {
    dataUsuario = this->dataJugador;
  }
  else
  {
    dataUsuario = this->dataDesarrollador;
  }

  usuarioHandler->agregarUsuario(dataUsuario);
}

set<DataSuscripcionJugador> UsuarioController::obtenerSuscripciones()
{

  UsuarioController *usuarioController = UsuarioController::getInstance();
  Jugador *jugador = dynamic_cast<Jugador *>(usuarioController->getSesion());

  set<ContratoSuscripcion *> contratosActivos = jugador->obtenerContratosActivos();

  set<DataSuscripcionJugador> res = set<DataSuscripcionJugador>();
  set<ContratoSuscripcion *>::iterator it;
  for (it = contratosActivos.begin(); it != contratosActivos.end(); it++)
  {
    ContratoSuscripcion *contrato = (*it);
    TipoPeriodoValidez validez = contrato->getValidez();
    Videojuego *videojuego = contrato->getVideojuego();
    float precio = videojuego->getSuscripciones()[contrato->getValidez()];
    res.insert(DataSuscripcionJugador(videojuego->getNombre(), precio, validez, true));

    map<TipoPeriodoValidez, float> suscripciones = videojuego->getSuscripciones();
    map<TipoPeriodoValidez, float>::iterator itSusc;

    for (itSusc = suscripciones.begin(); itSusc != suscripciones.end(); itSusc++)
    {
      if (validez != (*itSusc).first)
      {
        res.insert(DataSuscripcionJugador(videojuego->getNombre(), precio, validez, false));
      }
    }
  }

  VideojuegoHandler *videojuegoHandler = VideojuegoHandler::getInstance();

  map<string, Videojuego *> videojuegos = videojuegoHandler->obtenerVideojuegos();

  set<DataSuscripcionJugador>::iterator itRes;
  map<string, Videojuego *>::iterator itVj;

  for (itVj = videojuegos.begin(); itVj != videojuegos.end(); itVj++)
  {
    Videojuego *videojuego = (*itVj).second;

    bool agregado = false;
    for (itRes = res.begin(); itRes != res.end() && !agregado; itRes++)
    {
      DataSuscripcionJugador dataSuscJugador = *itRes;
      string nombreVideojuegoActual = dataSuscJugador.getNombreVideojuego();

      if (videojuego->getNombre() == nombreVideojuegoActual)
      {
        agregado = true;
      }
    }

    if (!agregado)
    {
      map<TipoPeriodoValidez, float>::iterator itSuscVj;
      map<TipoPeriodoValidez, float> suscripcionesVjActual = videojuego->getSuscripciones();

      for (itSuscVj = suscripcionesVjActual.begin(); itSuscVj != suscripcionesVjActual.end(); itSuscVj++)
      {
        res.insert(DataSuscripcionJugador(videojuego->getNombre(), (*itSuscVj).second, (*itSuscVj).first, false));
      }
    }
  }

  return res;
}

void UsuarioController::seleccionarVideojuego(string nombreVideojuego)
{
  VideojuegoHandler *videojuegoHandler = VideojuegoHandler::getInstance();

  this->videojuego = videojuegoHandler->obtenerVideojuegoPorId(nombreVideojuego);
}

void UsuarioController::cancelarSuscripcion()
{
  UsuarioController *usuarioController = UsuarioController::getInstance();

  Jugador *jugador = dynamic_cast<Jugador *>(usuarioController->getSesion());
  jugador->cancelarSuscripcionActiva(this->videojuego);
}

void UsuarioController::contratarSuscripcion(TipoPeriodoValidez validezSuscripcion, TipoMetodoPago metodoPago)
{
  this->validezSuscripcion = validezSuscripcion;
  this->metodoPago = metodoPago;
}

void UsuarioController::confirmarSuscripcion(Fecha fecha)
{
  UsuarioController *usuarioController = UsuarioController::getInstance();

  Jugador *jugador = dynamic_cast<Jugador *>(usuarioController->getSesion());
  jugador->contratarSuscripcion(this->videojuego, this->validezSuscripcion, this->metodoPago, fecha);

  this->videojuego = nullptr;
}

set<DataVideojuego> UsuarioController::obtenerVideojuegosPublicadosPorDesarrollador()
{
  UsuarioController *usuarioController = UsuarioController::getInstance();

  Desarrollador *dev = dynamic_cast<Desarrollador *>(usuarioController->getSesion());
  set<Videojuego *> vjs = dev->getVideojuegoPublicados();

  set<DataVideojuego> res = set<DataVideojuego>();
  set<Videojuego *>::iterator it;

  for (it = vjs.begin(); it != vjs.end(); it++)
  {
    Videojuego *vj = (*it);
    res.insert(vj->getData());
  }

  return res;
}

set<DataEstadistica> UsuarioController::calcularEstadisticas(string nombreVideojuego)
{
  UsuarioController *usuarioController = UsuarioController::getInstance();
  VideojuegoHandler *videojuegoHandler = VideojuegoHandler::getInstance();

  Videojuego *videojuego = videojuegoHandler->obtenerVideojuegoPorId(nombreVideojuego);
  Desarrollador *dev = dynamic_cast<Desarrollador *>(usuarioController->getSesion());

  set<TipoEstadistica> estadisticasDeInteres = dev->getEstadisticasDeInteres();

  set<DataEstadistica> res = set<DataEstadistica>();
  set<TipoEstadistica>::iterator it;

  for (it = estadisticasDeInteres.begin(); it != estadisticasDeInteres.end(); it++)
  {
    TipoEstadistica estadistica = (*it);
    float resultado = videojuego->calcularEstadistica(estadistica);

    res.insert(DataEstadistica(estadistica, resultado));
  }

  return res;
}

bool UsuarioController::iniciarSesion(string email, string password)
{
  UsuarioHandler *usuarioHandler = UsuarioHandler::getInstance();

  Usuario *usuario = usuarioHandler->obtenerUsuarioPorId(email);

  return usuario != nullptr && usuario->getPassword() == password ? true : false;
}

void UsuarioController::confirmarInicioSesion(string email, bool &jugador, bool &dev)
{

  UsuarioHandler *usuarioHandler = UsuarioHandler::getInstance();
  this->sesion = usuarioHandler->obtenerUsuarioPorId(email);

  Jugador *sesionJugador = dynamic_cast<Jugador *>(this->sesion);

  if (sesionJugador)
    jugador = false;
  else
    dev = false;
}

UsuarioController::~UsuarioController() { this->sesion = nullptr; }

void UsuarioController::releaseInstance()
{
  if (instancia != nullptr)
  {
    delete instancia;
    instancia = nullptr;
  }
}
