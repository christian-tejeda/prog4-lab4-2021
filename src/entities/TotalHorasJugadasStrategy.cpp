#include "../../headers/entities/TotalHorasJugadasStrategy.h"

TotalHorasJugadasStrategy *TotalHorasJugadasStrategy::instancia = nullptr;

TotalHorasJugadasStrategy::TotalHorasJugadasStrategy() {}

TotalHorasJugadasStrategy *TotalHorasJugadasStrategy::getInstance() {
  if (instancia == nullptr)
    instancia = new TotalHorasJugadasStrategy();
  return instancia;
}

float TotalHorasJugadasStrategy::calcularEstadistica(Videojuego *vj) {
  std::set<Jugador *> suscriptores = vj->getSuscriptores();

  float res = 0;

  std::set<Jugador *>::iterator it;

  for (it = suscriptores.begin(); it != suscriptores.end(); it++) {
    Jugador *jugador = (*it);
    res += jugador->calcularTotalHorasPartidasIniciadas(vj);
  }

  return res;
}