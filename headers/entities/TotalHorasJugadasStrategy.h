#ifndef TOTAL_HORAS_JUGADAS_STRATEGY
#define TOTAL_HORAS_JUGADAS_STRATEGY

#include "../interfaces/IStrategyEstadistica.h"

class TotalHorasJugadasStrategy : public IStrategyIEstadistica
{
private:
  static TotalHorasJugadasStrategy *instancia;

  TotalHorasJugadasStrategy();

  ~TotalHorasJugadasStrategy();

public:
  static TotalHorasJugadasStrategy *getInstance();

  float calcularEstadistica(Videojuego *videojuego);
};

#endif