#ifndef DATA_CONTRATO_SUSCRIPCION_H
#define DATA_CONTRATO_SUSCRIPCION_H

#include "../utils/enums.h"
#include <string>

using namespace std;

class DataContratoSuscripcion
{
private:
    bool activa;
    string nombreVideojuego;
    float precio;
    TipoPeriodoValidez periodoValidez;
    bool cancelada;
    Fecha fechaSuscripcion;
    TipoMetodoPago metodoPago;
    string nombreJugador;

public:
    DataContratoSuscripcion();
    DataContratoSuscripcion(bool activa, string nombreVideojuego,string nombreJugador, float precio, TipoPeriodoValidez periodoValidez, bool cancelada, Fecha fecha, TipoMetodoPago metodoPago);

    //Getters
    bool getActiva() const;
    string getNombreVideojuego() const;
    float getPrecio() const;
    TipoPeriodoValidez getPeriodoValidez() const;
    bool getCancelada() const;
    Fecha getFechaSuscripcion() const;
    TipoMetodoPago getMetodoPago() const;
    string getNombreJugador() const;

    ~DataContratoSuscripcion();
};

#endif