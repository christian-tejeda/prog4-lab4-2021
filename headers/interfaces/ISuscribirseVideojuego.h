#ifndef I_SUSCRIBIRSE_VIDEOJUEGO_H
#define I_SUSCRIBIRSE_VIDEOJUEGO_H

#include "../datatypes/DataContratoSuscripcion.h"
#include "../datatypes/DataSuscripcionJugador.h"
#include <set>

class ISuscribirseVideojuego
{
public:
  virtual set<DataSuscripcionJugador *> obtenerSuscripciones(Fecha* f) = 0;
  virtual void seleccionarVideojuego(string nombreVideojuego) = 0;
  virtual void cancelarSuscripcion() = 0;
  virtual void contratarSuscripcion(TipoPeriodoValidez validezSuscripcion,
                                    TipoMetodoPago metodoPago) = 0;
  virtual void confirmarSuscripcion(bool confirmar, Fecha *f) = 0;

  virtual ~ISuscribirseVideojuego(){};
};

#endif