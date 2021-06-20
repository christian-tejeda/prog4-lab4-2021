#include "../../headers/datatypes/DataSuscripcionJugador.h"

DataSuscripcionJugador::DataSuscripcionJugador() {}

DataSuscripcionJugador::DataSuscripcionJugador(std::string nombreVideojuego,
                                               float precio,
                                               TipoPeriodoValidez validez,
                                               bool activo)
{
  this->nombreVideojuego = nombreVideojuego;
  this->precio = precio;
  this->validez = validez;
  this->activo = activo;
}

std::string DataSuscripcionJugador::getNombreVideojuego()
{
  return this->nombreVideojuego;
}

float DataSuscripcionJugador::getPrecio() { return this->precio; }

TipoPeriodoValidez DataSuscripcionJugador::getValidez()
{
  return this->validez;
}

bool DataSuscripcionJugador::esSuscripcionActiva() { return this->activo; }

std::ostream &operator<<(std::ostream &os, const DataSuscripcionJugador &dataSuscJugador)
{
  std::string validez;

  switch (dataSuscJugador.validez)
  {
  case vitalicia:
    validez = "Vitalicia";
    break;
  case mensual:
    validez = "1 Mes";
    break;
  case trimestral:
    validez = "3 meses";
    break;
  case anual:
    validez = "1 Año";
    break;
  }

  std::string nombreVideojuego = dataSuscJugador.nombreVideojuego;
  std::string precio = std::to_string(dataSuscJugador.precio);

  std::string breakline = "\n";

  os << std::string("Videojuego: ") << nombreVideojuego << breakline;
  os << std::string("Periodo Validez: ") << validez << breakline;
  os << std::string("Precio: ") << precio << breakline;

  return os;
}