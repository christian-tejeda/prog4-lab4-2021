#include "../../headers/datatypes/DataSuscripcionJugador.h"

DataSuscripcionJugador::DataSuscripcionJugador() {}

DataSuscripcionJugador::DataSuscripcionJugador(const DataSuscripcionJugador &data)
{
  nombreVideojuego = data.nombreVideojuego;
  precio = data.precio;
  validez = data.validez;
  activo = data.activo;
}

DataSuscripcionJugador::DataSuscripcionJugador(string nombreVideojuego, float precio, TipoPeriodoValidez validez, bool activo)
{
  nombreVideojuego = nombreVideojuego;
  precio = precio;
  validez = validez;
  activo = activo;
}

string DataSuscripcionJugador::getNombreVideojuego() const { return nombreVideojuego; }

float DataSuscripcionJugador::getPrecio() const { return precio; }

TipoPeriodoValidez DataSuscripcionJugador::getValidez() const { return validez; }

bool DataSuscripcionJugador::esSuscripcionActiva() const { return activo; }

ostream &operator<<(ostream &os, const DataSuscripcionJugador &dataSuscJugador)
{
  string validez;

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

  string nombreVideojuego = dataSuscJugador.nombreVideojuego;
  string precio = to_string(dataSuscJugador.precio);

  string breakline = "\n";

  os << string("Videojuego: ") << nombreVideojuego << breakline;
  os << string("Periodo Validez: ") << validez << breakline;
  os << string("Precio: ") << precio << breakline;

  return os;
}

bool operator<(const DataSuscripcionJugador &d1, const DataSuscripcionJugador &d2)
{
  return &d1 < &d2;
}

bool operator!=(const DataSuscripcionJugador &d1, const DataSuscripcionJugador &d2)
{
  return d1.getValidez() != d2.getValidez() || d1.getPrecio() != d2.getPrecio() || d1.getNombreVideojuego() != d2.getNombreVideojuego() || d1.esSuscripcionActiva() != d2.esSuscripcionActiva();
}