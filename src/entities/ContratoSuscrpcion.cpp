#include "../../headers/entities/ContratoSuscripcion.h"

#include <string>

ContratoSuscripcion::ContratoSuscripcion(){}
ContratoSuscripcion::ContratoSuscripcion(Jugador *jg,Videojuego *vj,TipoMetodoPago metodoDePago,TipoPeriodoValidez validez){}

ContratoSuscripcion ContratoSuscripcion::getContratoSuscripcion(){}
Jugador* ContratoSuscripcion::getJugador(){}
Videojuego* ContratoSuscripcion::getVideojuego(){}
bool ContratoSuscripcion::getFueCancelada(){}
Fecha ContratoSuscripcion::getFecha(){}
TipoPeriodoValidez ContratoSuscripcion::getValidez(){}
TipoMetodoPago ContratoSuscripcion::getMetodoDePago(){}

void ContratoSuscripcion::setVideojuego(Videojuego* vj){}
void ContratoSuscripcion::setJugador(Jugador *jg){}
void ContratoSuscripcion::setFecha(Fecha &fe){}
void ContratoSuscripcion::setActivo(bool activo){}
void ContratoSuscripcion::setFueCancelada(bool fueCancelada){}
void ContratoSuscripcion::setMetodoDePago(TipoMetodoPago metodoDePago){}
void ContratoSuscripcion::setPeriodoDeValidez(TipoPeriodoValidez periodoValidez){}
void ContratoSuscripcion::cancelar(){}
bool ContratoSuscripcion::perteneceAVideojuego(Videojuego* vj){}
bool ContratoSuscripcion::esActivo(){}
