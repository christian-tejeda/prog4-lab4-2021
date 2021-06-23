#include "../../headers/entities/PromedioRatingStrategy.h"

PromedioRatingStrategy *PromedioRatingStrategy::instancia = nullptr;

PromedioRatingStrategy::PromedioRatingStrategy() {}

PromedioRatingStrategy *PromedioRatingStrategy::getInstance()
{
  if (instancia == nullptr)
    instancia = new PromedioRatingStrategy();
  return instancia;
}

float PromedioRatingStrategy::calcularEstadistica(Videojuego *videojuego)
{
  float votos = videojuego->getRating().first;
  float cantVotos = videojuego->getRating().second;

  return cantVotos > 0 ? (votos / cantVotos) : 0;
}