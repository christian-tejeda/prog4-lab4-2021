#ifndef CONTRATO_SUSCRIPCION_H
#define CONTRATO_SUSCRIPCION_H

#include "../utils/Fecha.h"
#include "../entities/Jugador.h"
#include "../entities/Videojuego.h"
#include "../utils/enums.h"

class ContratoSuscripcion
{
private:
    Jugador *jugador;
    TipoMetodoPago metodoDePago;
    TipoPeriodoValidez periodoValidez;
    Videojuego *videojuego;
    Fecha fechaSuscripcion;
    bool activa;
    bool fueCancelada;

public:
    ContratoSuscripcion();
    ContratoSuscripcion(Jugador *jugador, Videojuego *videojuego, TipoMetodoPago metodoDePago, TipoPeriodoValidez validez);

    ContratoSuscripcion getContratoSuscripcion();
    Jugador *getJugador();
    Videojuego *getVideojuego();
    bool getFueCancelada();
    Fecha getFecha();
    TipoPeriodoValidez getValidez();
    TipoMetodoPago getMetodoDePago();

    void setVideojuego(Videojuego *videojuego);
    void setJugador(Jugador *jugador);
    void setFecha(Fecha fecha);
    void setActivo(Fecha fecha);
    void setFueCancelada(bool fueCancelada);
    void setMetodoDePago(TipoMetodoPago metodoDePago);
    void setPeriodoDeValidez(TipoPeriodoValidez periodoValidez);

    void cancelar();
    bool perteneceAVideojuego(Videojuego *videojuego);
    bool esActivo();
};

#endif