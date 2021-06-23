#ifndef DATA_SUSCRIPCION_JUGADOR_H
#define DATA_SUSCRIPCION_JUGADOR_H

#include "../utils/enums.h"

#include <string>

using namespace std;

class DataSuscripcionJugador
{

private:
  string nombreVideojuego;
  float precio;
  TipoPeriodoValidez validez;
  bool activo;

public:
  DataSuscripcionJugador();
  DataSuscripcionJugador(const DataSuscripcionJugador &data);
  DataSuscripcionJugador(string nombreVideojuego, float precio, TipoPeriodoValidez validez, bool activo);

  string getNombreVideojuego() const;
  float getPrecio() const;
  TipoPeriodoValidez getValidez() const;

  bool esSuscripcionActiva() const;

  friend ostream &operator<<(ostream &os, const DataSuscripcionJugador &dt);
  friend bool operator<(const DataSuscripcionJugador &d1, const DataSuscripcionJugador &d2);
  friend bool operator!=(const DataSuscripcionJugador &d1, const DataSuscripcionJugador &d2);
};

#endif