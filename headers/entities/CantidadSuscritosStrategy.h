#ifndef CANTIDAD_SUSCRITOS_STRATEGY_H
#define CANTIDAD_SUSCRITOS_STRATEGY_H

#include "../interfaces/IStrategyEstadistica.h"

class CantidadSuscritosStrategy : public IStrategyIEstadistica
{
private:
  static CantidadSuscritosStrategy *instancia;

  CantidadSuscritosStrategy();

  ~CantidadSuscritosStrategy();

public:
  static CantidadSuscritosStrategy *getInstance();

  float calcularEstadistica(Videojuego *videojuego);
};

#endif