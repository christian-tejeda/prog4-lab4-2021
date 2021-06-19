#include "../../headers/entities/CantidadSuscritosStrategy.h"

CantidadSuscritosStrategy *CantidadSuscritosStrategy::instancia = nullptr;

CantidadSuscritosStrategy::CantidadSuscritosStrategy() {}

CantidadSuscritosStrategy *CantidadSuscritosStrategy::getInstance() {
  if (instancia == nullptr)
    instancia = new CantidadSuscritosStrategy();
  return instancia;
}

float CantidadSuscritosStrategy::calcularEstadistica(Videojuego *vj) {
  return vj->getCantidadSuscriptores();
}