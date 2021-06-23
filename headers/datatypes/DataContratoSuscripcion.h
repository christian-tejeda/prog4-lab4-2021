#ifndef DATA_CONTRATO_SUSCRIPCION_H
#define DATA_CONTRATO_SUSCRIPCION_H

#include "../utils/enums.h"
#include "../utils/Fecha.h"

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
    DataContratoSuscripcion(const DataContratoSuscripcion &data);
    DataContratoSuscripcion(bool activa, string nombreVideojuego, string nombreJugador, float precio, TipoPeriodoValidez periodoValidez, bool cancelada, Fecha fecha, TipoMetodoPago metodoPago);

    bool getActiva() const;
    string getNombreVideojuego() const;
    string getNombreJugador() const;
    float getPrecio() const;
    TipoPeriodoValidez getPeriodoValidez() const;
    bool getCancelada() const;
    Fecha getFechaSuscripcion() const;
    TipoMetodoPago getMetodoPago() const;

    friend bool operator<(const DataContratoSuscripcion &d1, const DataContratoSuscripcion &d2);
    friend bool operator!=(const DataContratoSuscripcion &d1, const DataContratoSuscripcion &d2);

    ~DataContratoSuscripcion();
};

#endif