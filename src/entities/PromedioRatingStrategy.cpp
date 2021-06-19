#include "../../headers/entities/PromedioRatingStrategy.h"

PromedioRatingStrategy *PromedioRatingStrategy::instancia = nullptr;

PromedioRatingStrategy::PromedioRatingStrategy() {}

PromedioRatingStrategy *PromedioRatingStrategy::getInstance() {
  if (instancia == nullptr)
    instancia = new PromedioRatingStrategy();
  return instancia;
}

float PromedioRatingStrategy::calcularEstadistica(Videojuego *vj) {
  float votos = vj->getRating().first;
  float cantVotos = vj->getRating().second;

  return cantVotos > 0 ? (votos / cantVotos) : 0;
}