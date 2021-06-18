#ifndef FACTORY_STRATEGY_ESTADISTICA_H
#define FACTORY_STRATEGY_ESTADISTICA_H

#include "interfaces/IStrategyEstadistica.h"

class FactoryStrategyEstadistica {
  static FactoryStrategyEstadistica *instancia;
  FactoryStrategyEstadistica();
  ~FactoryStrategyEstadistica();

public:
  static FactoryStrategyEstadistica *getInstance();

  IStrategyIEstadistica *getStrategy(TipoEstadistica tipoEstadistica);
};

#endif