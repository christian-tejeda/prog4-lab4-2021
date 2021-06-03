#ifndef DATA_CONTRATO_SUSCRIPCION_H
#define DATA_CONTRATO_SUSCRIPCION_H

#include "../enums.h"
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
    //FechaHora fechaSuscripcion
    TipoMetodoPago metodoPago;

public:
    DataContratoSuscripcion();
    DataContratoSuscripcion(bool activa, string nombreVideojuego, float precio, TipoPeriodoValidez periodoValidez, bool cancelada /*METER FECHA !!!*/, TipoMetodoPago metodoPago);

    //Getters
    bool getActiva() const;
    string getNombreVideojuego() const;
    float getPrecio() const;
    TipoPeriodoValidez getPeriodoValidez() const;
    bool getCancelada() const;
    //FechaHora getFechaSuscripcion() const;
    TipoMetodoPago getMetodoPago() const;

    ~DataContratoSuscripcion();
};

#endif