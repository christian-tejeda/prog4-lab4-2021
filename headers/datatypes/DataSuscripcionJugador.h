#ifndef DATA_SUSCRIPCION_JUGADOR_H
#define DATA_SUSCRIPCION_JUGADOR_H

#include "../utils/enums.h"
#include <string>

class DataSuscripcionJugador
{

private:
  std::string nombreVideojuego;
  float precio;
  TipoPeriodoValidez validez;
  bool activo;

public:
  DataSuscripcionJugador();
  DataSuscripcionJugador(std::string nombreVideojuego, float precio,
                         TipoPeriodoValidez validez, bool activo);

  std::string getNombreVideojuego();
  float getPrecio();
  TipoPeriodoValidez getValidez();

  bool esSuscripcionActiva();

  friend std::ostream &operator<<(std::ostream &os, const DataSuscripcionJugador &dt);
};

#endif