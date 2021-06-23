#include "../../headers/entities/TotalHorasJugadasStrategy.h"
#include "../../headers/entities/Jugador.h"

TotalHorasJugadasStrategy *TotalHorasJugadasStrategy::instancia = nullptr;

TotalHorasJugadasStrategy::TotalHorasJugadasStrategy() {}

TotalHorasJugadasStrategy *TotalHorasJugadasStrategy::getInstance()
{
  if (instancia == nullptr)
    instancia = new TotalHorasJugadasStrategy();

  return instancia;
}

float TotalHorasJugadasStrategy::calcularEstadistica(Videojuego *videojuego)
{
  float res = 0;

  set<Jugador *> suscriptores = videojuego->getSuscriptores();
  set<Jugador *>::iterator it;

  for (it = suscriptores.begin(); it != suscriptores.end(); it++)
  {
    Jugador *jugador = (*it);
    res += jugador->calcularTotalHorasPartidasIniciadas(videojuego);
  }

  return res;
}