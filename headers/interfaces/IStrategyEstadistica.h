#ifndef I_STRATEGY_ESTADISTICA_H
#define I_STRATEGY_ESTADISTICA_H

#include "../entities/Videojuego.h"

class IStrategyIEstadistica {
public:
  virtual float calcularEstadistica(Videojuego *vj) = 0;
};

#endif
