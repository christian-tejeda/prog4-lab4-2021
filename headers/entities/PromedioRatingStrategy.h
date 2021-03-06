#ifndef PROMEDIO_RATING_STRATEGY
#define PROMEDIO_RATING_STRATEGY

#include "../interfaces/IStrategyEstadistica.h"
#include <utility>

class PromedioRatingStrategy : public IStrategyIEstadistica {

private:
  static PromedioRatingStrategy *instancia;

  PromedioRatingStrategy();

  ~PromedioRatingStrategy();

public:
  static PromedioRatingStrategy *getInstance();

  float calcularEstadistica(Videojuego *vj);
};

#endif
