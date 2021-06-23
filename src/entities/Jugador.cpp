#include "../../headers/entities/Jugador.h"

Jugador::Jugador() : Usuario(){};

Jugador::Jugador(string email, string password, string nickname, string descripcion) : Usuario(email, password)
{
  this->nickname = nickname;
  this->descripcion = descripcion;
}

string Jugador::getNickname() { return this->nickname; }

string Jugador::getDescripcion() { return this->descripcion; }

void Jugador::setNickname(string nickname) { this->nickname = nickname; }

void Jugador::setDescripcion(string descripcion) { this->descripcion = descripcion; }

void Jugador::cancelarSuscripcionActiva(Videojuego *videojuego)
{
  set<ContratoSuscripcion *> contratos = this->contratos;
  set<ContratoSuscripcion *>::iterator it;
  bool cancelado = false;

  for (it = contratos.begin(); it != contratos.end() && !cancelado; it++)
  {
    ContratoSuscripcion *contrato = (*it);
    if (contrato->perteneceAVideojuego(videojuego))
    {
      if (contrato->esActivo())
      {
        contrato->cancelar();
        cancelado = true;
      }
    }
  }
}

void Jugador::contratarSuscripcion(Videojuego *videojuego, TipoPeriodoValidez validez, TipoMetodoPago metodoPago, Fecha fecha)
{
  ///TODO: Para que la fecha?

  ContratoSuscripcion *contrato = new ContratoSuscripcion(this, videojuego, metodoPago, validez);
  this->contratos.insert(contrato);
  videojuego->agregarSuscriptor(contrato);
}

map<int, Partida *> Jugador::obtenerPartidasSinFinalizar()
{
  map<int, Partida *> res;
  map<int, Partida *>::iterator it;
  for (it = this->partidasIniciadas.begin(); it != this->partidasIniciadas.end(); it++)
  {
    if (it->second->getFechaFin() == Fecha())
    {
      res.insert(*it);
    }
  }
  return res;
}

Partida *Jugador::obtenerPartidaPorId(int id) { return this->partidasIniciadas.find(id)->second; }

void Jugador::finalizarPartida(int idPartida, Fecha fecha)
{
  Partida *partida = partidasIniciadas.find(idPartida)->second;
  partida->finalizar(fecha);
}

map<string, Videojuego *> Jugador::obtenerVideojuegos()
{
  /// TODO: Por que vacio?
  return map<string, Videojuego *>();
}

void Jugador::eliminarContratosDeVideojuego(Videojuego *videojuego)
{
  set<ContratoSuscripcion *> cont = this->contratos;
  set<ContratoSuscripcion *>::iterator it;
  it = cont.begin();

  while (it != cont.end())
  {
    ContratoSuscripcion *contrato = *it;
    bool pertenece = contrato->perteneceAVideojuego(videojuego);

    if (pertenece)
    {
      this->contratos.erase(*it);
      delete contrato;
    }

    it++;
  }
}

void Jugador::eliminarPartidasDeVideojuego(Videojuego *videojuego)
{
  map<int, Partida *> partidas = this->partidasIniciadas;
  map<int, Partida *>::iterator it;

  for (it = partidas.begin(); it != partidas.end(); it++)
  {
    Partida *partida = (it->second);
    Videojuego *videojuegoPartida = partida->getVideojuego();

    if (videojuego == videojuegoPartida)
    {
      partida->eliminarPartidasVideojuego(videojuego);
      this->partidasIniciadas.erase(it->first);
      delete partida;
    }
  }
}

DataJugador Jugador::getData() { return DataJugador(this->getEmail(), this->getPassword(), this->getNickname(), this->getDescripcion()); }

bool tieneSuscripcionActiva(Videojuego *vj)
{
  ///TODO: Siempre false?
  return false;
}

bool Jugador::tienePartidaSinFinalizar(Videojuego *videojuego)
{
  map<int, Partida *> partidas = this->partidasIniciadas;
  map<int, Partida *>::iterator it;
  it = partidas.begin();

  bool tiene;

  while (it != partidas.end() && !tiene)
  {
    Partida *partida = it->second;
    tiene = !(partida->esFinalizada());
    it++;
  }

  return tiene;
}

int Jugador::obtenerDuracionPartida(Videojuego *videojuego)
{
  map<int, Partida *> partidas = this->partidasIniciadas;
  map<int, Partida *>::iterator it;
  int res = 0;
  for (it = partidas.begin(); it != partidas.end(); it++)
  {
    Partida *partida = it->second;
    Videojuego *videojuegoPartida = partida->getVideojuego();

    if (videojuego == videojuegoPartida)
    {
      int sumar = partida->getDuracionTotal();
      res += sumar;
    }
  }

  return res;
}

set<ContratoSuscripcion *> Jugador::obtenerContratosActivos()
{
  set<ContratoSuscripcion *> activos = set<ContratoSuscripcion *>();
  set<ContratoSuscripcion *>::iterator it;

  for (it = this->contratos.begin(); it != this->contratos.end(); it++)
  {
    ContratoSuscripcion *contrato = (*it);
    if (contrato->esActivo())
    {
      activos.insert(contrato);
    }
  }

  return activos;
}

float Jugador::calcularTotalHorasPartidasIniciadas(Videojuego *videojuego)
{
  float res = 0;
  map<int, Partida *> partidasIniciadas = this->partidasIniciadas;

  map<int, Partida *>::iterator it;
  for (it = partidasIniciadas.begin(); it != partidasIniciadas.end(); it++)
  {
    Partida *partida = (it->second);
    Videojuego *currentVideojuego = partida->getVideojuego();

    if (currentVideojuego == videojuego)
    {
      res += partida->getDuracionTotal();
    }
  }

  return res;
}

map<int, PartidaIndividual *> Jugador::obtenerPartidasFinalizadas()
{
  map<int, PartidaIndividual *> res;
  map<int, Partida *>::iterator it;

  for (it = this->partidasIniciadas.begin(); it != this->partidasIniciadas.end(); it++)
  {
    if (it->second->esFinalizada())
    {
      PartidaIndividual *partida = dynamic_cast<PartidaIndividual *>(it->second);
      if (partida != nullptr)
      {
        res.insert(pair<int, PartidaIndividual *>(it->first, dynamic_cast<PartidaIndividual *>(partida)));
      }
    }
  }
  return res;
}

PartidaIndividual *Jugador::obtenerPartida(int id) { return dynamic_cast<PartidaIndividual *>(partidasIniciadas.find(id)->second); }

bool Jugador::tieneSuscripcionActiva(Videojuego *videojuego)
{
  set<ContratoSuscripcion *>::iterator it;
  for (it = this->contratos.begin(); it != this->contratos.end(); it++)
  {
    if ((*it)->esActivo() && (*it)->perteneceAVideojuego(videojuego))
    {
      return true;
    }
  }
  return false;
}

map<string, Videojuego *> Jugador::obtenerVideojuegosConSuscripcionActiva(Fecha fecha)
{
  ///TODO: fecha???

  map<string, Videojuego *> res;
  set<ContratoSuscripcion *>::iterator it;

  for (it = this->contratos.begin(); it != this->contratos.end(); it++)
  {
    if ((*it)->esActivo())
    {
      res.insert(pair<string, Videojuego *>((*it)->getVideojuego()->getNombre(), (*it)->getVideojuego()));
    }
  }

  return res;
}

void Jugador::crearPartidaIndividual(int idPartida, Fecha actual, Videojuego *videojuego, Jugador *host, PartidaIndividual *continuada)
{
  float duracion = 0;
  if (continuada != nullptr)
  {
    duracion = continuada->getDuracionTotal();
    this->partidasIniciadas.erase(idPartida);
  }
  Fecha fechaFin;
  PartidaIndividual *partida = new PartidaIndividual(idPartida, actual, fechaFin, duracion, videojuego, this, continuada);
  this->partidasIniciadas.insert(pair<int, PartidaIndividual *>(idPartida, partida));
}

void Jugador::crearPartidaMultijugador(int idPartida, Fecha actual, Fecha fin, Videojuego *videojuego, bool transmitida, Jugador *host, map<string, Jugador *> participantes)
{
  set<DuracionParticipante *> duracionParticipantess;
  map<string, Jugador *>::iterator it;
  for (it = participantes.begin(); it != participantes.end(); it++)
  {
    DuracionParticipante *durparticipante = new DuracionParticipante(actual, fin, it->second);
    duracionParticipantess.insert(durparticipante);
  }
  PartidaMultijugador *partidaMultijugador = new PartidaMultijugador(idPartida, actual, fin, 0, videojuego, host, transmitida, duracionParticipantess);
  this->partidasIniciadas.insert(pair<int, PartidaMultijugador *>(idPartida, partidaMultijugador));
}

Jugador::~Jugador(){};
