#include "../../headers/entities/ContratoSuscripcion.h"

#include <string>

ContratoSuscripcion::ContratoSuscripcion() {}
ContratoSuscripcion::ContratoSuscripcion(Jugador *jg, Videojuego *vj, TipoMetodoPago metodoDePago, TipoPeriodoValidez validez)
{
    this->jugador = jg;
    this->videojuego = vj;
    this->metodoDePago = metodoDePago;
    this->periodoValidez = validez;
}

Jugador *ContratoSuscripcion::getJugador()
{
    return this->jugador;
}
Videojuego *ContratoSuscripcion::getVideojuego()
{
    return this->videojuego;
}
bool ContratoSuscripcion::getFueCancelada()
{
    return this->fueCancelada;
}
Fecha ContratoSuscripcion::getFecha()
{
    return this->fechaSuscripcion;
}
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
void ContratoSuscripcion::setFecha(Fecha &fe) {}
void ContratoSuscripcion::setActivo(bool activo) {}
void ContratoSuscripcion::setFueCancelada(bool fueCancelada) {}
void ContratoSuscripcion::setMetodoDePago(TipoMetodoPago metodoDePago) {}
void ContratoSuscripcion::setPeriodoDeValidez(TipoPeriodoValidez periodoValidez) {}
void ContratoSuscripcion::cancelar() {}
bool ContratoSuscripcion::perteneceAVideojuego(Videojuego *vj)
{
    return false;
}
bool ContratoSuscripcion::esActivo()
{
    return false;
}
