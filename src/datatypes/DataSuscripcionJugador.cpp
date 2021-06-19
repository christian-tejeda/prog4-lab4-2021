#include "../../headers/datatypes/DataSuscripcionJugador.h"

DataSuscripcionJugador::DataSuscripcionJugador() {}

DataSuscripcionJugador::DataSuscripcionJugador(std::string nombreVideojuego,
                                               float precio,
                                               TipoPeriodoValidez validez,
                                               bool activo) {
  this->nombreVideojuego = nombreVideojuego;
  this->precio = precio;
  this->validez = validez;
  this->activo = activo;
}

std::string DataSuscripcionJugador::getNombreVideojuego() {
  return this->nombreVideojuego;
}

float DataSuscripcionJugador::getPrecio() { return this->precio; }

TipoPeriodoValidez DataSuscripcionJugador::getValidez() {
  return this->validez;
}

bool DataSuscripcionJugador::esSuscripcionActiva() { return this->activo; }