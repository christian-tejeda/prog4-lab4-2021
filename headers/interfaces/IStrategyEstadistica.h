#ifndef I_STRATEGY_ESTADISTICA_H
#define I_STRATEGY_ESTADISTICA_H

#include "../entities/Videojuego.h"

class Videojuego;

class IStrategyIEstadistica {
public:
  IStrategyIEstadistica();

  virtual float calcularEstadistica(Videojuego *vj) = 0;

  virtual ~IStrategyIEstadistica(){};
};

class CantidadSuscritosStrategy : public IStrategyIEstadistica {
public:
  CantidadSuscritosStrategy();
  float calcularEstadistica(Videojuego *vj);
  ~CantidadSuscritosStrategy();
};

CantidadSuscritosStrategy::CantidadSuscritosStrategy() {}

float CantidadSuscritosStrategy::calcularEstadistica(Videojuego *vj) {
  return vj->getCantidadSuscriptores();
}

class TotalHorasJugadasStrategy : public IStrategyIEstadistica {
public:
  TotalHorasJugadasStrategy();
  float calcularEstadistica(Videojuego *vj);
  ~TotalHorasJugadasStrategy();
};

TotalHorasJugadasStrategy::TotalHorasJugadasStrategy() {}

float TotalHorasJugadasStrategy::calcularEstadistica(Videojuego *vj) {
  std::set<Jugador *> suscriptores = vj->getSuscriptores();

  float res = 0;

  std::set<Jugador *>::iterator it;

  for (it = suscriptores.begin(); it != suscriptores.end(); it++) {
    Jugador *jugador = (*it);
    res += jugador->calcularTotalHorasPartidasIniciadas(vj);
  }
}

class PromedioRatingStrategy : public IStrategyIEstadistica {
public:
  PromedioRatingStrategy();
  float calcularEstadistica(Videojuego *vj);
  ~PromedioRatingStrategy();
};

PromedioRatingStrategy::PromedioRatingStrategy() {}

float PromedioRatingStrategy::calcularEstadistica(Videojuego *vj) {
  return nullptr;
}

#endif
