#include "../../headers/entities/ContratoSuscripcion.h"

ContratoSuscripcion::ContratoSuscripcion() {}

ContratoSuscripcion::ContratoSuscripcion(Jugador *jg, Videojuego *vj,
                                         TipoMetodoPago metodoDePago,
                                         TipoPeriodoValidez validez)
{
  this->jugador = jg;
  this->videojuego = vj;
  this->metodoDePago = metodoDePago;
  this->periodoValidez = validez;
  this->activa = true;
}

Jugador *ContratoSuscripcion::getJugador() { return this->jugador; }

Videojuego *ContratoSuscripcion::getVideojuego() { return this->videojuego; }

bool ContratoSuscripcion::getFueCancelada() { return this->fueCancelada; }

Fecha ContratoSuscripcion::getFecha() { return this->fechaSuscripcion; }

TipoPeriodoValidez ContratoSuscripcion::getValidez() { return this->periodoValidez; }

TipoMetodoPago ContratoSuscripcion::getMetodoDePago() { return this->metodoDePago; }

void ContratoSuscripcion::setVideojuego(Videojuego *videojuego) {}

void ContratoSuscripcion::setJugador(Jugador *jugador) {}

void ContratoSuscripcion::setFecha(Fecha fecha) { this->fechaSuscripcion = fecha; }

void ContratoSuscripcion::setActivo(Fecha fecha)
{
  switch (this->periodoValidez)
  {
  case mensual:
    this->activa = (fecha - this->getFecha()) <= 30 * 24;
    break;
  case trimestral:
    this->activa = (fecha - this->getFecha()) <= 90 * 24;
    break;
  case anual:
    this->activa = (fecha - this->getFecha()) <= 365 * 24;
    break;
  default:
    break;
  }
}

void ContratoSuscripcion::setFueCancelada(bool fueCancelada) {}

void ContratoSuscripcion::setMetodoDePago(TipoMetodoPago metodoDePago) {}

void ContratoSuscripcion::setPeriodoDeValidez(TipoPeriodoValidez periodoValidez) {}

void ContratoSuscripcion::cancelar() { this->fueCancelada = true; }

bool ContratoSuscripcion::perteneceAVideojuego(Videojuego *videojuego) { return this->videojuego == videojuego; }

bool ContratoSuscripcion::esActivo()
{
  if (this->fueCancelada)
    return false;

  bool esActivo;
  //   Fecha difference = fechaActual.difference(this->fechaSuscripcion);
  switch (this->periodoValidez)
  {
  case vitalicia:
    return true;
  //   case anual:
  //     return difference.getAnio() > 1;
  //   case mensual:
  //    return difference.getMes() < 1;
  //   case trimestral:
  //     return difference.getMes() < 3;
  default:
    return this->activa;
  }
}
