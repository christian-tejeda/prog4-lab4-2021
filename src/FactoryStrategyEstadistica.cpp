#include "../../headers/FactoryStrategyEstadistica.h"

using namespace std;

FactoryStrategyEstadistica *FactoryStrategyEstadistica::instancia = nullptr;

FactoryStrategyEstadistica::FactoryStrategyEstadistica() {}

FactoryStrategyEstadistica *FactoryStrategyEstadistica::getInstance() {
  if (instancia == nullptr)
    instancia = new FactoryStrategyEstadistica();
  return instancia;
}

IStrategyIEstadistica *
FactoryStrategyEstadistica::getStrategy(TipoEstadistica tipoEstadistica) {
  switch (tipoEstadistica) {
  case horasJugadas:
    return new TotalHorasJugadasStrategy();
  case promedioRating:
    return new PromedioRatingStrategy();
  case cantidadSuscritos:
    return new CantidadSuscritosStrategy();
  default:
    return;
  }
}