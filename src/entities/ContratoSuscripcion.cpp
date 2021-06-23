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
  int contrato=(this->getFecha().getAnio());
  //std::cout << contrato <<" contrato\n";
  contrato=contrato-2020;
  //std::cout << contrato <<" contrato\n";
  contrato=contrato*24*12*30;
  //std::cout << contrato <<" contrato\n";
  //std::cout << contrato <<" contrato\n";
  contrato=contrato+((this->getFecha().getMes())*24*30);
  //std::cout << contrato <<" contrato\n";
  contrato=contrato+((this->getFecha().getDia())*24);
  //std::cout << contrato <<" contrato\n";
  switch (this->periodoValidez)
  {
  case mensual:
    contrato = (contrato+(30*24));
  //std::cout << contrato <<" contrato\n";
    break;
  case trimestral:
    contrato = (contrato+(90*24));
  //std::cout << contrato <<" contrato\n";
    break;
  case anual:
    contrato =(contrato+(360*24));
  //std::cout << contrato <<" contrato\n";
    break;
  default:
    break;
  }int actual=(f->getAnio()-2020)*12*30*24;
  
  //std::cout << actual <<"\n";
  actual=actual+((f->getMes())*24*30);
  //std::cout << actual <<"\n";
  actual=actual+((f->getDia())*24);
  //std::cout << actual <<"\n";
  int dif=actual-contrato;
  this->activa= (contrato>actual);
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
