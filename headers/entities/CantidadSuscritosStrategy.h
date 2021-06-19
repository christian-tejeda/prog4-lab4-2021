#ifndef CANTIDAD_SUSCRITOS_STRATEGY_H
#define CANTIDAD_SUSCRITOS_STRATEGY_H

#include "../interfaces/IStrategyEstadistica.h"
#include <utility>

class CantidadSuscritosStrategy : public IStrategyIEstadistica {
private:
  static CantidadSuscritosStrategy *instancia;

  CantidadSuscritosStrategy();

  ~CantidadSuscritosStrategy();

public:
  static CantidadSuscritosStrategy *getInstance();

  float calcularEstadistica(Videojuego *vj);
};

#endif