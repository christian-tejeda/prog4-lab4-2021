#include "../../headers/controllers/UsuarioController.h"

UsuarioController *UsuarioController::instancia = nullptr;

UsuarioController::UsuarioController()
{
  this->dataDesarrollador = nullptr;
  this->dataJugador = nullptr;
  this->sesion = nullptr;
  this->videojuego = nullptr;
}

// op de singleton
UsuarioController *UsuarioController::getInstance()
{
  if (instancia == nullptr)
    instancia = new UsuarioController();
  return instancia;
}

Usuario *UsuarioController::getSesion() { return this->sesion; }
DataDesarrollador *UsuarioController::getDataDesarrollador()
{
  return this->dataDesarrollador;
}
DataJugador *UsuarioController::getDataJugador() { return this->dataJugador; }
Videojuego *UsuarioController::getVideojuego() { return this->videojuego; }

TipoMetodoPago UsuarioController::getMetodoPago() { return this->metodoPago; }

// métodos de ISeleccionarEstadisticas
std::set<DataEstadistica *> UsuarioController::listarEstadisticas()
{
  set<DataEstadistica *> res;
  for (int eint = horasJugadas; eint != Last; eint++)
  {
    TipoEstadistica tipoest = static_cast<TipoEstadistica>(eint);
    DataEstadistica *est = new DataEstadistica(tipoest, 3.14);
    res.insert(est);
  }
  return res;
}
void UsuarioController::seleccionarEstadisticas(set<TipoEstadistica> estadisticas){
    set<TipoEstadistica>::iterator it;
    for (it = estadisticas.begin(); it != estadisticas.end(); it++) {
      TipoEstadistica estadistica = *it;
      Desarrollador *des = dynamic_cast<Desarrollador *>(this->sesion);
      des->agregarEstadisticaDeInteres(estadistica);
    }
}


// métodos de IAltaUsuario
void UsuarioController::ingresarDatosJugador(DataJugador *dataJugador)
{

  UsuarioHandler *uh = UsuarioHandler::getInstance();
  bool existeNick = uh->existeJugadorConNickname(dataJugador->getNickname());

  if (existeNick)
  {
    throw std::invalid_argument("Error: Ya existe un jugador con ese nickname. "
                                "Pruebe con uno distinto.");
  }
  else
  {
    this->dataJugador = dataJugador;
  }
}

void UsuarioController::ingresarDatosDesarrollador(
    DataDesarrollador *dataDesarrollador)
{
  this->dataDesarrollador = dataDesarrollador;
}

void UsuarioController::confirmarAltaUsuario(bool confirmar)
{
  try
  {
    if (confirmar)
    {
      UsuarioHandler *uh = UsuarioHandler::getInstance();
      DataUsuario *dtUser = nullptr;
      if (this->dataJugador != nullptr)
      {
        dtUser = this->dataJugador;
      }
      else
      {
        dtUser = this->dataDesarrollador;
      }

      uh->agregarUsuario(dtUser);
      std::cout << "¡Usuario agregado correctamente!\n";
    }
  }
  catch (const std::invalid_argument &ex)
  {
    std::cout << ex.what() << '\n';
  }

  if (this->dataJugador != nullptr)
    delete this->dataJugador;
  if (this->dataDesarrollador != nullptr)
    delete this->dataDesarrollador;
  this->dataDesarrollador = nullptr;
  this->dataJugador = nullptr;
}

// ISuscribirseAVideojuego

std::set<DataSuscripcionJugador *> UsuarioController::obtenerSuscripciones(Fecha *fecha)
{
  std::set<DataSuscripcionJugador *> res = std::set<DataSuscripcionJugador *>();

  UsuarioController *uc = UsuarioController::getInstance();
  Jugador *jugador = dynamic_cast<Jugador *>(uc->getSesion());

  std::set<ContratoSuscripcion *> contratosActivos =
      jugador->obtenerContratosActivos(fecha);

  std::set<ContratoSuscripcion *>::iterator it;

  for (it = contratosActivos.begin(); it != contratosActivos.end(); it++)
  {

    ContratoSuscripcion *contrato = (*it);
    TipoPeriodoValidez validez = contrato->getValidez();
    Videojuego *videojuego = contrato->getVideojuego();
    float precio = videojuego->getSuscripciones()[contrato->getValidez()];

    /// Agrego unico contrato (validez) activo asociado a [videojuego]
    res.insert(new DataSuscripcionJugador(videojuego->getNombre(), precio,
                                          validez, true));

    std::map<TipoPeriodoValidez, float> suscripciones =
        videojuego->getSuscripciones();
    std::map<TipoPeriodoValidez, float>::iterator itSusc;

    /// Como hay un unico contrato activo (por lo tanto un unico)
    /// TipoPeriodoValidez activo, se que el resto son inactivos
    /// para un Videojuego dado
    for (itSusc = suscripciones.begin(); itSusc != suscripciones.end();
         itSusc++)
    {
      if (validez != (*itSusc).first)
      {
        res.insert(new DataSuscripcionJugador(videojuego->getNombre(), precio,
                                              validez, false));
      }
    }
  }

  /// El chequeo anterior solo contempla a aquellos Videojuegos
  /// en el cual el Jugador tenga una suscripcion activa, ahora
  /// itero sobre todos los Videojuegos del Sistema y agrego aquellos que falten

  VideojuegoHandler *vH = VideojuegoHandler::getInstance();
  std::map<string, Videojuego *> videojuegos = vH->obtenerVideojuegos();

  std::set<DataSuscripcionJugador *>::iterator itRes;
  std::map<string, Videojuego *>::iterator itVj;

  for (itVj = videojuegos.begin(); itVj != videojuegos.end(); itVj++)
  {
    Videojuego *vj = (*itVj).second;

    bool agregado = false;

    for (itRes = res.begin(); itRes != res.end() && !agregado; itRes++)
    {
      std::string nombreVideojuegoActual = (*itRes)->getNombreVideojuego();

      if (vj->getNombre() == nombreVideojuegoActual)
      {
        agregado = true;
      }
    }

    /// Si no esta en res, lo agrego
    if (!agregado)
    {
      std::map<TipoPeriodoValidez, float>::iterator itSuscVj;
      std::map<TipoPeriodoValidez, float> suscripcionesVjActual =
          vj->getSuscripciones();

      for (itSuscVj = suscripcionesVjActual.begin();
           itSuscVj != suscripcionesVjActual.end(); itSuscVj++)
      {
        res.insert(new DataSuscripcionJugador(
            vj->getNombre(), (*itSuscVj).second, (*itSuscVj).first, false));
      }
    }
  }

  return res;
}

void UsuarioController::seleccionarVideojuego(string nombreVideojuego)
{
  VideojuegoHandler *vH = VideojuegoHandler::getInstance();

  this->videojuego = vH->obtenerVideojuegoPorId(nombreVideojuego);
}

void UsuarioController::cancelarSuscripcion()
{
  UsuarioController *uc = UsuarioController::getInstance();
  Jugador *jugador = dynamic_cast<Jugador *>(uc->getSesion());

  jugador->cancelarSuscripcionActiva(this->videojuego);
}

void UsuarioController::contratarSuscripcion(TipoPeriodoValidez validezSuscripcion, TipoMetodoPago metodoPago)
{
  this->validezSuscripcion = validezSuscripcion;
  this->metodoPago = metodoPago;
}

void UsuarioController::confirmarSuscripcion(bool confirmar, Fecha *f)
{
  if (confirmar)
  {
    UsuarioController *uc = UsuarioController::getInstance();
    Jugador *jugador = dynamic_cast<Jugador *>(uc->getSesion());

    jugador->contratarSuscripcion(this->videojuego, this->validezSuscripcion, this->metodoPago, f);
    this->videojuego = nullptr;
    std::cout << "Suscripción contratada correctamente!\n";
  }
  this->videojuego = nullptr;
}

// métodos de IConsultarEstadisticas
set<DataVideojuego *>
UsuarioController::obtenerVideojuegosPublicadosPorDesarrollador()
{
  std::set<DataVideojuego *> res = std::set<DataVideojuego *>();
  UsuarioController *uc = UsuarioController::getInstance();
  Desarrollador *des = dynamic_cast<Desarrollador *>(uc->getSesion());
  set<Videojuego *> vjs = des->getVideojuegoPublicados();

  set<Videojuego *>::iterator it;

  for (it = vjs.begin(); it != vjs.end(); it++)
  {
    Videojuego *vj = (*it);
    res.insert(vj->getData());
  }

  return res;
}

set<DataEstadistica *>
UsuarioController::calcularEstadisticas(string nomVideojuego)
{
  std::set<DataEstadistica *> res = std::set<DataEstadistica *>();

  VideojuegoHandler *vH = VideojuegoHandler::getInstance();
  Videojuego *videojuego = vH->obtenerVideojuegoPorId(nomVideojuego);

  UsuarioController *uc = UsuarioController::getInstance();
  Desarrollador *dev = dynamic_cast<Desarrollador *>(uc->getSesion());

  std::set<TipoEstadistica> estadisticasDeInteres =
      dev->getEstadisticasDeInteres();

  std::set<TipoEstadistica>::iterator it;

  for (it = estadisticasDeInteres.begin(); it != estadisticasDeInteres.end();
       it++)
  {
    TipoEstadistica estadistica = (*it);
    float resultado = videojuego->calcularEstadistica(estadistica);

    res.insert(new DataEstadistica(estadistica, resultado));
  }

  return res;
}

// métodos de IIniciarSesion
bool UsuarioController::iniciarSesion(string mail, string password)
{
  UsuarioHandler *uh = UsuarioHandler::getInstance();
  Usuario *user = uh->obtenerUsuarioPorId(mail);
  if (user != nullptr && user->getPassword() == password)
    return true;
  else
    return false;
}

void UsuarioController::confirmarInicioSesion(bool confirmar, string mail,
                                              bool &jg, bool &dev)
{
  if (confirmar)
  {
    UsuarioHandler *uh = UsuarioHandler::getInstance();
    this->sesion = uh->obtenerUsuarioPorId(mail);

    Jugador *sesionJg = dynamic_cast<Jugador *>(this->sesion);
    if (sesionJg)
      jg = false;
    else
      dev = false;
  }
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
