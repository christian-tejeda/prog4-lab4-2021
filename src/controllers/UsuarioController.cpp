

#include <map>
#include <set>
#include <string>
#include <utility>

#include "../../headers/controllers/UsuarioController.h"
#include "../../headers/entities/Desarrollador.h"
#include "../../headers/handlers/UsuarioHandler.h"
#include "../../headers/utils/Fecha.h"

using namespace std;

UsuarioController *UsuarioController::instancia = nullptr;

UsuarioController::UsuarioController() {
  this->dataDesarrollador = nullptr;
  this->dataJugador = nullptr;
  this->sesion = nullptr;
  this->videojuego = nullptr;
}

// op de singleton
UsuarioController *UsuarioController::getInstance() {
  if (instancia == nullptr)
    instancia = new UsuarioController();
  return instancia;
}

// Getters
Usuario *UsuarioController::getSesion() { return this->sesion; }
DataDesarrollador *UsuarioController::getDataDesarrollador() {
  return this->dataDesarrollador;
}
DataJugador *UsuarioController::getDataJugador() { return this->dataJugador; }
Videojuego *UsuarioController::getVideojuego() { return this->videojuego; }

pair<TipoPeriodoValidez, float> UsuarioController::getSuscripcion() {
  return this->suscripcion;
}
TipoMetodoPago UsuarioController::getMetodoPago() { return this->metodoP; }

// métodos de ISeleccionarEstadisticas
std::set<DataEstadistica *> UsuarioController::listarEstadisticas() {
  set<DataEstadistica *> res;
  return res;
}
void UsuarioController::seleccionarEstadisticas(
    std::set<std::string> nombresEstadisticas) {}

// métodos de IAltaUsuario
void UsuarioController::ingresarDatosJugador(DataJugador *dataJugador) {

  UsuarioHandler *uh = UsuarioHandler::getInstance();
  bool existeNick = uh->existeJugadorConNickname(dataJugador->getNickname());

  if (existeNick) {
    throw std::invalid_argument("Error: Ya existe un jugador con ese nickname. "
                                "Pruebe con uno distinto.");
  } else {
    this->dataJugador = dataJugador;
  }
}

void UsuarioController::ingresarDatosDesarrollador(
    DataDesarrollador *dataDesarrollador) {
  this->dataDesarrollador = dataDesarrollador;
}

void UsuarioController::confirmarAltaUsuario(bool confirmar) {
  try {
    if (confirmar) {
      UsuarioHandler *uh = UsuarioHandler::getInstance();
      DataUsuario *dtUser = nullptr;
      if (this->dataJugador != nullptr) {
        dtUser = this->dataJugador;
      } else {
        dtUser = this->dataDesarrollador;
      }

      uh->agregarUsuario(dtUser);
      std::cout << "¡Usuario agregado correctamente!\n";
    }
  } catch (const std::invalid_argument &ex) {
    std::cout << ex.what() << '\n';
  }

  if (this->dataJugador != nullptr)
    delete this->dataJugador;
  if (this->dataDesarrollador != nullptr)
    delete this->dataDesarrollador;
}

// métodos de ISuscribirseVideojuego
set<DataContratoSuscripcion *> UsuarioController::obtenerSuscripciones() {
  set<DataContratoSuscripcion *> res;
  res.insert(nullptr);
  return res;
}
void UsuarioController::seleccionarVideojuego(string nombreVideojuego) {}
void UsuarioController::cancelarSuscripcion(bool cancelada) {}
void UsuarioController::contratarSuscripcion(
    pair<TipoPeriodoValidez, float> suscripcion, TipoMetodoPago m) {}
void UsuarioController::confirmarSuscripcion(bool confirmar) {}

// métodos de IConsultarEstadisticas
set<DataVideojuego *>
UsuarioController::obtenerVideojuegosPublicadosPorDesarrollador() {
  std::set<DataVideojuego *> res = std::set<DataVideojuego *>();
  UsuarioController *uc = UsuarioController::getInstance();
  Desarrollador *des = dynamic_cast<Desarrollador *>(uc->getSesion());
  set<Videojuego *> vjs = des->getVideojuegoPublicados();

  set<Videojuego *>::iterator it;

  for (it = vjs.begin(); it != vjs.end(); it++) {
    Videojuego *vj = (*it);
    res.insert(vj->getData());
  }

  return res;
}

set<DataEstadistica *>
UsuarioController::calcularEstadisticas(string nomVideojuego) {
  set<DataEstadistica *> res;
  res.insert(nullptr);
  return res;
}

// set<DataPartidaMultijugador *>
// UsuarioController::obtenerPartidasMultijugadorActivasDeJugador()
// {
//     set<DataPartidaMultijugador *> res;
//     res.insert(nullptr);
//     return res;
// }
// void UsuarioController::seleccionarPartida(int id) {}

// métodos de IIniciarSesion
bool UsuarioController::iniciarSesion(string mail, string password) {
  UsuarioHandler *uh = UsuarioHandler::getInstance();
  Usuario *user = uh->obtenerUsuarioPorId(mail);
  if (user != nullptr && user->getPassword() == password)
    return true;
  else
    return false;
}

void UsuarioController::confirmarInicioSesion(bool confirmar, string mail,
                                              bool &jg, bool &dev) {
  if (confirmar) {
    UsuarioHandler *uh = UsuarioHandler::getInstance();
    this->sesion = uh->obtenerUsuarioPorId(mail);

    Jugador *sesionJg = dynamic_cast<Jugador *>(this->sesion);
    if (sesionJg)
      jg = false;
    else
      dev = false;

    std::cout << "¡Sesión iniciada correctamente!\n\n";
    std::cout << "                Bienvenid@, " << this->sesion->getEmail()
              << "\n\n";
  }
}

UsuarioController::~UsuarioController() { this->sesion = nullptr; }

void UsuarioController::releaseInstance() {
  if (instancia != nullptr) {
    delete instancia;
    instancia = nullptr;
  }
}
