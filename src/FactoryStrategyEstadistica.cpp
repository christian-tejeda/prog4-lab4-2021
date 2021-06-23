#include "../headers/FactoryStrategyEstadistica.h"
#include "../headers/entities/CantidadSuscritosStrategy.h"
#include "../headers/entities/PromedioRatingStrategy.h"
#include "../headers/entities/TotalHorasJugadasStrategy.h"

FactoryStrategyEstadistica *FactoryStrategyEstadistica::instancia = nullptr;

FactoryStrategyEstadistica::FactoryStrategyEstadistica() {}

FactoryStrategyEstadistica *FactoryStrategyEstadistica::getInstance()
{
  if (instancia == nullptr)
    instancia = new FactoryStrategyEstadistica();

  return instancia;
}

IStrategyIEstadistica *FactoryStrategyEstadistica::getStrategy(TipoEstadistica tipoEstadistica)
{
  switch (tipoEstadistica)
  {
  case horasJugadas:
    return TotalHorasJugadasStrategy::getInstance();
  case promedioRating:
    return PromedioRatingStrategy::getInstance();
  case cantidadSuscritos:
    return CantidadSuscritosStrategy::getInstance();
  default:
    throw "ERROR: Invalid TipoEstadistica in IStrategyIEstadistica.getStrategy";
  }
}