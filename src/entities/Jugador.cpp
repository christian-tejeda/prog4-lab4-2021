#include "../../headers/entities/Jugador.h"

Jugador::Jugador() : Usuario(){};

Jugador::Jugador(std::string email, std::string password, std::string nickname,
                 std::string descripcion)
    : Usuario(email, password) {
  this->nickname = nickname;
  this->descripcion = descripcion;
}

std::string Jugador::getNickname() { return this->nickname; }
std::string Jugador::getDescripcion() { return this->descripcion; }

void Jugador::setNickname(std::string nick) { this->nickname = nick; }

void Jugador::setDescripcion(std::string descripcion) {
  this->descripcion = descripcion;
}

void Jugador::cancelarSuscripcionActiva(Videojuego *vj) {
  std::set<ContratoSuscripcion *> contratos = this->contratos;
  std::set<ContratoSuscripcion *>::iterator it;

  bool cancelado = false;
  for (it = contratos.begin(); it != contratos.end() && !cancelado; it++) {
    ContratoSuscripcion *contrato = (*it);
    if (contrato->perteneceAVideojuego(vj)) {
      if (contrato->esActivo()) {
        contrato->cancelar();
        cancelado = true;
      }
    }
  }
}

void Jugador::contratarSuscripcion(Videojuego *vj, TipoPeriodoValidez validez,
                                   TipoMetodoPago metodoPago) {
  this->contratos.insert(
      new ContratoSuscripcion(this, vj, metodoPago, validez));
}

map<int, Partida *> Jugador::obtenerPartidasSinFinalizar() {
  return map<int, Partida *>();
}

void Jugador::finalizarPartida(int idPartida) {}

map<string, Videojuego *> Jugador::obtenerVideojuegos() {
  return map<string, Videojuego *>();
}

void Jugador::eliminarContratosDeVideojuego(Videojuego *vj) {
  set<ContratoSuscripcion *> cont = this->contratos;
  set<ContratoSuscripcion *>::iterator it;
  for (it = cont.begin(); it != cont.end(); it++) {
    ContratoSuscripcion *contr = *it;
    bool pertenece = contr->perteneceAVideojuego(vj);
    if (pertenece) {
      this->contratos.erase(*it);
      delete contr;
    }
  }
}

void Jugador::eliminarPartidasDeVideojuego(Videojuego *vj) {
  map<int, Partida *> partidas = this->partidasIniciadas;
  map<int, Partida *>::iterator it;
  for (it = partidas.begin(); it != partidas.end(); it++) {
    Partida *par = (it->second);
    Videojuego *video = par->getVideojuego();
    if (vj == video) {
      par->eliminarPartidasVideojuego(vj);
      this->partidasIniciadas.erase(it->first);
      delete par;
    }
  }
}

DataUsuario *Jugador::getData() { return nullptr; }

map<int, PartidaIndividual *> Jugador::obtenerPartidasFinalizadas() {
  return map<int, PartidaIndividual *>();
}

PartidaIndividual *Jugador::obtenerPartida(string id) { return nullptr; }

bool tieneSuscripcionActiva(Videojuego *vj) { return false; }

bool Jugador::tienePartidaSinFinalizar(Videojuego *vj) {
  map<int, Partida *> partidas = this->partidasIniciadas;
  map<int, Partida *>::iterator it;
  it = partidas.begin();
  PartidaIndividual *partida = dynamic_cast<PartidaIndividual *>(it->second);
  bool tiene = (partida->getFechaFin() == nullptr);
  while (it != partidas.end() && !tiene) {
    it++;
    PartidaIndividual *partida = dynamic_cast<PartidaIndividual *>(it->second);
    tiene = (partida->getFechaFin() == nullptr);
  }
  return tiene;
}

int Jugador::obtenerDuracionPartida(Videojuego *vj) {
  map<int, Partida *> partidas = this->partidasIniciadas;
  map<int, Partida *>::iterator it;
  int res = 0;
  for (it = partidas.begin(); it != partidas.end(); it++) {
    Partida *partida = it->second;
    // PartidaIndividual*partida=dynamic_cast<PartidaIndividual *>(it->second);
    Videojuego *video = partida->getVideojuego();
    if (vj == video) {
      int sumar = partida->getDuracionTotal();
      res += sumar;
    }
  }
  return res;
}

std::set<ContratoSuscripcion *> Jugador::obtenerContratosActivos() {
  std::set<ContratoSuscripcion *> activos = std::set<ContratoSuscripcion *>();

  std::set<ContratoSuscripcion *>::iterator it;
  for (it = this->contratos.begin(); it != this->contratos.end(); it++) {
    ContratoSuscripcion *contrato = (*it);
    if (contrato->esActivo()) {
      activos.insert(contrato);
    }
  }

  return activos;
}

float Jugador::calcularTotalHorasPartidasIniciadas(Videojuego *videojuego) {
  float res = 0;
  map<int, Partida *> partidasIniciadas = this->partidasIniciadas;

  map<int, Partida *>::iterator it;
  for (it = partidasIniciadas.begin(); it != partidasIniciadas.end(); it++) {
    Partida *partida = (it->second);
    Videojuego *currentVideojuego = partida->getVideojuego();

    if (currentVideojuego == videojuego) {
      res += partida->getDuracionTotal();
    }
  }

  return res;
}

Jugador::~Jugador(){};
