#ifndef I_SUSCRIBIRSE_VIDEOJUEGO_H
#define I_SUSCRIBIRSE_VIDEOJUEGO_H

#include "../datatypes/DataContratoSuscripcion.h"
#include "../datatypes/DataSuscripcionJugador.h"
#include <set>

class ISuscribirseVideojuego {
public:
  virtual set<DataSuscripcionJugador *> obtenerSuscripciones() = 0;
  virtual void seleccionarVideojuego(string nombreVideojuego) = 0;
  virtual void cancelarSuscripcion(bool cancelada) = 0;
  virtual void contratarSuscripcion(pair<TipoPeriodoValidez, float> suscripcion,
                                    TipoMetodoPago m) = 0;
  virtual void confirmarSuscripcion(bool confirmar) = 0;

  virtual ~ISuscribirseVideojuego(){};
};

#endif