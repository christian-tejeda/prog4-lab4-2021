#include "../../headers/entities/ContratoSuscripcion.h"

#include <string>

ContratoSuscripcion::ContratoSuscripcion() {}
ContratoSuscripcion::ContratoSuscripcion(Jugador *jg, Videojuego *vj,
                                         TipoMetodoPago metodoDePago,
                                         TipoPeriodoValidez validez)
{

  // TODO: Settear fecha del sistema cuando se crea el contrato
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
TipoPeriodoValidez ContratoSuscripcion::getValidez()
{
  return this->periodoValidez;
}
TipoMetodoPago ContratoSuscripcion::getMetodoDePago()
{
  return this->metodoDePago;
}

void ContratoSuscripcion::setVideojuego(Videojuego *vj) {}
void ContratoSuscripcion::setJugador(Jugador *jg) {}
void ContratoSuscripcion::setFecha(Fecha &fe)
{
  this->fechaSuscripcion = fe;
}
void ContratoSuscripcion::setActivo(Fecha *f)
{
  switch (this->periodoValidez)
  {
  case mensual:
    this->activa = (*f - this->getFecha()) <= 30 * 24;
    break;
  case trimestral:
    this->activa = (*f - this->getFecha()) <= 90 * 24;
    break;
  case anual:
    this->activa = (*f - this->getFecha()) <= 365 * 24;
    break;
  default:
    break;
  }
}
void ContratoSuscripcion::setFueCancelada(bool fueCancelada) {}
void ContratoSuscripcion::setMetodoDePago(TipoMetodoPago metodoDePago) {}
void ContratoSuscripcion::setPeriodoDeValidez(
    TipoPeriodoValidez periodoValidez) {}

void ContratoSuscripcion::cancelar() { this->fueCancelada = true; }

bool ContratoSuscripcion::perteneceAVideojuego(Videojuego *vj)
{
  Videojuego *video = this->videojuego;
  return (video == vj);
}
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
