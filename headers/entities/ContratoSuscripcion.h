#ifndef CONTRATO_SUSCRIPCION_H
#define CONTRATO_SUSCRIPCION_H

#include "../utils/Fecha.h"
#include "../entities/Jugador.h"
#include "../entities/Videojuego.h"
#include "../utils/enums.h"

class ContratoSuscripcion{
private:
    Jugador  *contratista;
    TipoMetodoPago metodoDePago;
    TipoPeriodoValidez periodoValidez;
    Videojuego *videojuego;
    Fecha fechaSuscripcion;
    bool activa;
    bool fueCancelada;
public:
    ContratoSuscripcion();
    ContratoSuscripcion(Jugador *jg,Videojuego *vj,TipoMetodoPago metodoDePago,TipoPeriodoValidez validez);
    //getters
    ContratoSuscripcion getContratoSuscripcion();
    Jugador* getJugador();
    Videojuego* getVideojuego();
    bool getFueCancelada();
    Fecha getFecha();
    TipoPeriodoValidez getValidez();
    TipoMetodoPago getMetodoDePago();
    //setters
    void setVideojuego(Videojuego* vj);
    void setJugador(Jugador *jg);
    void setFecha(Fecha &fe);
    void setActivo(bool activo);
    void setFueCancelada(bool fueCancelada);
    void setMetodoDePago(TipoMetodoPago metodoDePago);
    void setPeriodoDeValidez(TipoPeriodoValidez periodoValidez);
    //ops
    void cancelar();
    bool perteneceAVideojuego(Videojuego* vj);
    bool esActivo();
};



#endif